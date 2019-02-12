/*
 * Copyright (C) 2017 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define LOG_TAG "Manager"

#include "Manager.h"
#include "Callbacks.h"
#include "HalInterfaces.h"
#include "Tracing.h"
#include "Utils.h"

#include <android/hidl/manager/1.0/IServiceManager.h>
#include <build/version.h>
#include <hidl/HidlTransportSupport.h>
#include <hidl/ServiceManagement.h>

#include <algorithm>
#include <functional>

using ::android::hardware::neuralnetworks::V1_2::implementation::ExecutionCallback;
using ::android::hardware::neuralnetworks::V1_2::implementation::PreparedModelCallback;

namespace android {
namespace nn {

uint32_t Device::getSizeOfData(const Operand& operand,
                               const std::map<std::string, uint16_t>& extensionNameToPrefix) const {
    if (!isExtensionOperandType(operand.type)) {
        return sizeOfData(operand);
    }

    // A slow naive implementation.
    // TODO(b/123178734): Speed it up.
    uint32_t operandType = static_cast<uint32_t>(operand.type);
    uint8_t kLowBitsType = static_cast<uint8_t>(Model::ExtensionTypeEncoding::LOW_BITS_TYPE);
    uint16_t prefix = operandType >> kLowBitsType;
    uint16_t typeWithinExtension = operandType & ((1 << kLowBitsType) - 1);
    for (const Extension& extension : getSupportedExtensions()) {
        if (extensionNameToPrefix.at(extension.name) != prefix) {
            continue;
        }
        for (auto& extensionOperandType : extension.operandTypes) {
            if (extensionOperandType.type == typeWithinExtension) {
                uint32_t numElements = 1;
                if (extensionOperandType.isTensor) {
                    for (auto dimension : operand.dimensions) {
                        numElements *= dimension;
                    }
                }
                return numElements * extensionOperandType.byteSize;
            }
        }
    }

    CHECK(false) << "Cannot determine the size of extension operand type "
                 << toString(operand.type);
    return 0;
}

// A Device with actual underlying driver
class DriverDevice : public Device {
    DISALLOW_IMPLICIT_CONSTRUCTORS(DriverDevice);

   public:
    DriverDevice(std::string name, const sp<V1_0::IDevice>& device);

    // Returns true if succesfully initialized.
    bool initialize();

    const char* getName() const override { return mName.c_str(); }
    const char* getVersionString() const override { return mVersionString.c_str(); }
    VersionedIDevice* getInterface() override { return &mInterface; }
    int64_t getFeatureLevel() override { return mInterface.getFeatureLevel(); }
    int32_t getType() const override { return mInterface.getType(); }
    hidl_vec<Extension> getSupportedExtensions() const override;
    void getSupportedOperations(const Model& hidlModel,
                                hidl_vec<bool>* supportedOperations) override;
    PerformanceInfo getFloat32Performance() const override { return mFloat32Performance; }
    PerformanceInfo getQuantized8Performance() const override { return mQuantized8Performance; }
    PerformanceInfo getRelaxedFloat32toFloat16Performance() const override {
        return mRelaxedFloat32toFloat16Performance;
    }

    int prepareModel(const Model& hidlModel, ExecutionPreference executionPreference,
                     std::shared_ptr<VersionedIPreparedModel>* preparedModel) override;

   private:
    std::string mName;
    std::string mVersionString;
    VersionedIDevice mInterface;
    PerformanceInfo mFloat32Performance;
    PerformanceInfo mQuantized8Performance;
    PerformanceInfo mRelaxedFloat32toFloat16Performance;
    hidl_vec<Extension> mSupportedExtensions;

#ifdef NN_DEBUGGABLE
    // For debugging: behavior of IDevice::getSupportedOperations for SampleDriver.
    // 0 - all operations reported by IDevice::getSupportedOperations() supported
    // 1 - some operations reported by IDevice::getSupportedOperations() supported
    uint32_t mSupported = 0;
#endif  // NN_DEBUGGABLE
};

DriverDevice::DriverDevice(std::string name, const sp<V1_0::IDevice>& device)
    : mName(std::move(name)), mInterface(device) {}

// TODO: handle errors from initialize correctly
bool DriverDevice::initialize() {
#ifdef NN_DEBUGGABLE
    static const char samplePrefix[] = "sample";

    mSupported = (mName.substr(0, sizeof(samplePrefix) - 1) == samplePrefix)
                         ? getProp("debug.nn.sample.supported")
                         : 0;
#endif  // NN_DEBUGGABLE

    bool success = true;
    ErrorStatus status = ErrorStatus::GENERAL_FAILURE;

    Capabilities capabilities;
    std::tie(status, capabilities) = mInterface.getCapabilities();
    if (status != ErrorStatus::NONE) {
        LOG(ERROR) << "IDevice::getCapabilities returned the error " << toString(status);
        success = false;
    } else {
        VLOG(MANAGER) << "Capab " << capabilities.float32Performance.execTime;
        VLOG(MANAGER) << "Capab " << capabilities.quantized8Performance.execTime;
        VLOG(MANAGER) << "Capab " << capabilities.relaxedFloat32toFloat16Performance.execTime;
        mFloat32Performance = capabilities.float32Performance;
        mQuantized8Performance = capabilities.quantized8Performance;
        mRelaxedFloat32toFloat16Performance = capabilities.relaxedFloat32toFloat16Performance;
    }

    std::tie(status, mVersionString) = mInterface.getVersionString();
    // TODO(miaowang): add a validation test case for in case of error.
    if (status != ErrorStatus::NONE) {
        LOG(ERROR) << "IDevice::getVersionString returned the error " << toString(status);
        success = false;
    }

    std::tie(status, mSupportedExtensions) = mInterface.getSupportedExtensions();
    if (status != ErrorStatus::NONE) {
        LOG(ERROR) << "IDevice::getSupportedExtensions returned the error " << toString(status);
        success = false;
    }

    return success;
}

hidl_vec<Extension> DriverDevice::getSupportedExtensions() const {
    return mSupportedExtensions;
}

void DriverDevice::getSupportedOperations(const Model& hidlModel,
                                          hidl_vec<bool>* outSupportedOperations) {
    // Query the driver for what it can do.
    ErrorStatus status = ErrorStatus::GENERAL_FAILURE;
    hidl_vec<bool> supportedOperations;
    std::tie(status, supportedOperations) = mInterface.getSupportedOperations(hidlModel);

    if (status != ErrorStatus::NONE) {
        LOG(ERROR) << "IDevice::getSupportedOperations returned the error " << toString(status);
        // Set the supported operation vectors to all false, so we won't use this driver.
        outSupportedOperations->resize(hidlModel.operations.size());
        std::fill(outSupportedOperations->begin(), outSupportedOperations->end(), false);
        return;
    }
    if (supportedOperations.size() != hidlModel.operations.size()) {
        LOG(ERROR) << "IDevice::getSupportedOperations returned a vector of length "
                   << supportedOperations.size() << " when expecting "
                   << hidlModel.operations.size();
        // Set the supported operation vectors to all false, so we won't use this driver.
        outSupportedOperations->resize(hidlModel.operations.size());
        std::fill(outSupportedOperations->begin(), outSupportedOperations->end(), false);
        return;
    }

    *outSupportedOperations = std::move(supportedOperations);

#ifdef NN_DEBUGGABLE
    if (mSupported != 1) {
        return;
    }

    const uint32_t baseAccumulator = std::hash<std::string>{}(mName);
    for (size_t operationIndex = 0; operationIndex < outSupportedOperations->size();
         operationIndex++) {
        if (!(*outSupportedOperations)[operationIndex]) {
            continue;
        }

        uint32_t accumulator = baseAccumulator;
        const Operation &operation = hidlModel.operations[operationIndex];
        accumulator ^= static_cast<uint32_t>(operation.type);
        auto accumulateOperands = [&hidlModel, &accumulator](const hidl_vec<uint32_t>& operands) {
            for (uint32_t operandIndex : operands) {
                const Operand& operand = hidlModel.operands[operandIndex];
                accumulator ^= static_cast<uint32_t>(operand.type);
                accumulator ^= operand.dimensions.size();
                for (uint32_t dimension : operand.dimensions) {
                    accumulator ^= dimension;
                    if (operand.lifetime == OperandLifeTime::CONSTANT_COPY ||
                        operand.lifetime == OperandLifeTime::CONSTANT_REFERENCE) {
                        accumulator ^= 1;
                    }
                }
            }
        };
        accumulateOperands(operation.inputs);
        accumulateOperands(operation.outputs);
        if (accumulator & 1) {
            (*outSupportedOperations)[operationIndex] = false;
        }
    }
#endif  // NN_DEBUGGABLE
}

// Compilation logic copied from StepExecutor::startComputeOnDevice().
int DriverDevice::prepareModel(const Model& hidlModel, ExecutionPreference executionPreference,
                               std::shared_ptr<VersionedIPreparedModel>* preparedModel) {
    *preparedModel = nullptr;
    sp<PreparedModelCallback> preparedModelCallback = new PreparedModelCallback();

    // Note that some work within VersionedIDevice will be subtracted from the
    // IPC layer
    NNTRACE_FULL(NNTRACE_LAYER_IPC, NNTRACE_PHASE_COMPILATION, "prepareModel");
    Return<ErrorStatus> prepareLaunchStatus =
            mInterface.prepareModel(hidlModel, executionPreference, preparedModelCallback);
    if (!prepareLaunchStatus.isOk()) {
        LOG(ERROR) << "ExecutionStep::finishSubModel compilation failed due to transport error: "
                   << prepareLaunchStatus.description();
        return ANEURALNETWORKS_OP_FAILED;
    }
    if (prepareLaunchStatus != ErrorStatus::NONE) {
        LOG(ERROR) << "ExecutionStep::finishSubModel compilation failed with error: "
                   << toString(static_cast<ErrorStatus>(prepareLaunchStatus));
        return ANEURALNETWORKS_OP_FAILED;
    }

    preparedModelCallback->wait();
    ErrorStatus prepareReturnStatus = preparedModelCallback->getStatus();
    if (auto returnedPreparedModel = preparedModelCallback->getPreparedModel()) {
        *preparedModel = std::make_shared<VersionedIPreparedModel>(returnedPreparedModel);
    }
    if (prepareReturnStatus != ErrorStatus::NONE || *preparedModel == nullptr) {
        LOG(ERROR) << "ExecutionPlan compilation on " << getName() << " failed:"
                   << " prepareReturnStatus=" << toString(prepareReturnStatus)
                   << ", preparedModel=" << preparedModel->get();
        return ANEURALNETWORKS_OP_FAILED;
    }
    return ANEURALNETWORKS_NO_ERROR;
}

// A special abstracted device for the CPU. Only one instance of this class will exist.
// Use get() to retrieve it.
class CpuDevice : public Device {
    DISALLOW_COPY_AND_ASSIGN(CpuDevice);

   public:
    // Returns the singleton CPU fallback device.
    static std::shared_ptr<CpuDevice> get() {
        static std::shared_ptr<CpuDevice> instance(new CpuDevice);
        return instance;
    }

    const char* getName() const override { return kName.c_str(); }
    const char* getVersionString() const override { return kVersionString.c_str(); }
    VersionedIDevice* getInterface() override { return nullptr; }
    int64_t getFeatureLevel() override { return kFeatureLevel; }
    int32_t getType() const override { return ANEURALNETWORKS_DEVICE_CPU; }
    hidl_vec<Extension> getSupportedExtensions() const override { return {/* No extensions. */}; }
    void getSupportedOperations(const Model& hidlModel,
                                hidl_vec<bool>* supportedOperations) override;
    PerformanceInfo getFloat32Performance() const override { return kPerformance; }
    PerformanceInfo getQuantized8Performance() const override { return kPerformance; }
    PerformanceInfo getRelaxedFloat32toFloat16Performance() const override { return kPerformance; }

    int prepareModel(const Model& hidlModel, ExecutionPreference executionPreference,
                     std::shared_ptr<VersionedIPreparedModel>* preparedModel) override;

   private:
    CpuDevice() = default;
    const int64_t kFeatureLevel = __ANDROID_API__;
    const std::string kName = "google-cpu";
    const std::string kVersionString = build::GetBuildNumber();
    // Since the performance is a ratio compared to the CPU performance,
    // by definition the performance of the CPU is 1.0.
    const PerformanceInfo kPerformance = {.execTime = 1.0f, .powerUsage = 1.0f};
};

void CpuDevice::getSupportedOperations(const Model& hidlModel,
                                       hidl_vec<bool>* supportedOperations) {
    const size_t count = hidlModel.operations.size();
    hidl_vec<bool> result(count);
    for (size_t i = 0; i < count; i++) {
        // TODO(b/119870033): Decide whether and how post-P operations would be supported on CPU.
        OperationType operationType = hidlModel.operations[i].type;
        result[i] = !isExtensionOperationType(operationType) &&
                    operationType != OperationType::OEM_OPERATION;
    }
    *supportedOperations = std::move(result);
}

int CpuDevice::prepareModel(const Model& hidlModel, ExecutionPreference executionPreference,
                            std::shared_ptr<VersionedIPreparedModel>* preparedModel) {
    *preparedModel = nullptr;
    if (!validateModel(hidlModel) || !validateExecutionPreference(executionPreference)) {
        return ANEURALNETWORKS_OP_FAILED;
    }
    return ANEURALNETWORKS_NO_ERROR;
}

DeviceManager* DeviceManager::get() {
    static DeviceManager manager;
    return &manager;
}

std::shared_ptr<Device> DeviceManager::getCpuDevice() {
    return CpuDevice::get();
}

std::shared_ptr<Device> DeviceManager::forTest_makeDriverDevice(const std::string& name,
                                                                const sp<V1_0::IDevice>& device) {
    auto driverDevice = std::make_shared<DriverDevice>(name, device);
    CHECK(driverDevice->initialize());
    return driverDevice;
}

void DeviceManager::findAvailableDevices() {
    using ::android::hidl::manager::V1_0::IServiceManager;
    VLOG(MANAGER) << "findAvailableDevices";

    sp<IServiceManager> manager = hardware::defaultServiceManager();
    if (manager == nullptr) {
        LOG(ERROR) << "Unable to open defaultServiceManager";
        return;
    }

    manager->listByInterface(V1_0::IDevice::descriptor, [this](const hidl_vec<hidl_string>& names) {
        for (const auto& name : names) {
            VLOG(MANAGER) << "Found interface " << name.c_str();
            sp<V1_0::IDevice> device = V1_0::IDevice::getService(name);
            if (device == nullptr) {
                LOG(ERROR) << "Got a null IDEVICE for " << name.c_str();
                continue;
            }
            registerDevice(name.c_str(), device);
        }
    });

    // register CPU fallback device
    mDevices.push_back(CpuDevice::get());
    mDevicesCpuOnly.push_back(CpuDevice::get());
}

void DeviceManager::registerDevice(const char* name, const sp<V1_0::IDevice>& device) {
    auto d = std::make_shared<DriverDevice>(name, device);
    if (d->initialize()) {
        mDevices.push_back(d);
    }
}

DeviceManager::DeviceManager() {
    VLOG(MANAGER) << "DeviceManager::DeviceManager";
    findAvailableDevices();
#ifdef NN_DEBUGGABLE
    mPartitioning = getProp("debug.nn.partition", kPartitioningDefault);
    mDebugNNCpuOnly = (getProp("debug.nn.cpuonly") != 0);
    mSyncExecCpu = (getProp("debug.nn.syncexec-cpu") != 0);
    if (!mSyncExecHalSetter) {
        mSyncExecHal = (getProp("debug.nn.syncexec-hal", 1) != 0);
    }
    mSyncExecRuntime = (getProp("debug.nn.syncexec-runtime") != 0);
#endif  // NN_DEBUGGABLE
}

}  // namespace nn
}  // namespace android
