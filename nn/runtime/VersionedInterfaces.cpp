/*
 * Copyright (C) 2018 The Android Open Source Project
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

#include "VersionedInterfaces.h"

#include "Callbacks.h"
#include "ExecutionBurstController.h"
#include "Tracing.h"
#include "Utils.h"

#include <android-base/logging.h>

using ::android::hardware::neuralnetworks::V1_2::implementation::ExecutionCallback;

namespace android {
namespace nn {

const Timing kBadTiming = {.timeOnDevice = UINT64_MAX, .timeInDriver = UINT64_MAX};

ErrorStatus VersionedIPreparedModel::execute(const Request& request, MeasureTiming measure,
                                             const sp<IExecutionCallback>& callback) {
    if (mPreparedModelV1_2 != nullptr) {
        Return<ErrorStatus> ret = mPreparedModelV1_2->execute_1_2(request, measure, callback);
        if (!ret.isOk()) {
            LOG(ERROR) << "execute_1_2 failure: " << ret.description();
            return ErrorStatus::GENERAL_FAILURE;
        }
        return static_cast<ErrorStatus>(ret);
    } else if (mPreparedModelV1_0 != nullptr) {
        Return<ErrorStatus> ret = mPreparedModelV1_0->execute(request, callback);
        if (!ret.isOk()) {
            LOG(ERROR) << "execute failure: " << ret.description();
            return ErrorStatus::GENERAL_FAILURE;
        }
        return static_cast<ErrorStatus>(ret);
    } else {
        LOG(ERROR) << "execute called with no preparedModel";
        return ErrorStatus::GENERAL_FAILURE;
    }
}

std::tuple<ErrorStatus, hidl_vec<OutputShape>, Timing>
VersionedIPreparedModel::executeSynchronously(const Request& request, MeasureTiming measure) {
    if (mPreparedModelV1_2 != nullptr) {
        std::tuple<ErrorStatus, hidl_vec<OutputShape>, Timing> result;
        Return<void> ret = mPreparedModelV1_2->executeSynchronously(
                request, measure,
                [&result](ErrorStatus error, const hidl_vec<OutputShape>& outputShapes,
                          const Timing& timing) {
                    result = std::make_tuple(error, outputShapes, timing);
                });
        if (!ret.isOk()) {
            LOG(ERROR) << "executeSynchronously failure: " << ret.description();
            return {ErrorStatus::GENERAL_FAILURE, {}, kBadTiming};
        }
        return result;
    } else {
        // Simulate synchronous execution.
        sp<ExecutionCallback> callback = new ExecutionCallback();
        ErrorStatus ret = execute(request, measure, callback);
        if (ret != ErrorStatus::NONE) {
            return {ret, {}, kBadTiming};
        }
        callback->wait();
        // callback->getOutputShapes() will always return an empty hidl vector.
        // callback->getTiming() will always return values indicating no measurement.
        return {callback->getStatus(), callback->getOutputShapes(), callback->getTiming()};
    }
}

std::unique_ptr<ExecutionBurstController> VersionedIPreparedModel::configureExecutionBurst(
        bool blocking) const {
    if (mPreparedModelV1_2 != nullptr) {
        return createExecutionBurstController(mPreparedModelV1_2, blocking);
    } else {
        return nullptr;
    }
}

bool VersionedIPreparedModel::operator==(nullptr_t) const {
    return mPreparedModelV1_0 == nullptr;
}

bool VersionedIPreparedModel::operator!=(nullptr_t) const {
    return mPreparedModelV1_0 != nullptr;
}

// HIDL guarantees all V1_1 interfaces inherit from their corresponding V1_0 interfaces.
VersionedIDevice::VersionedIDevice(sp<V1_0::IDevice> device)
    : mDeviceV1_0(device),
      mDeviceV1_1(V1_1::IDevice::castFrom(mDeviceV1_0).withDefault(nullptr)),
      mDeviceV1_2(V1_2::IDevice::castFrom(mDeviceV1_0).withDefault(nullptr)) {}

std::pair<ErrorStatus, Capabilities> VersionedIDevice::getCapabilities() {
    std::pair<ErrorStatus, Capabilities> result;

    if (mDeviceV1_1 != nullptr) {
        NNTRACE_FULL(NNTRACE_LAYER_IPC, NNTRACE_PHASE_INITIALIZATION, "getCapabilities_1_1");
        Return<void> ret = mDeviceV1_1->getCapabilities_1_1(
                [&result](ErrorStatus error, const Capabilities& capabilities) {
                    result = std::make_pair(error, capabilities);
                });
        if (!ret.isOk()) {
            LOG(ERROR) << "getCapabilities_1_1 failure: " << ret.description();
            return {ErrorStatus::GENERAL_FAILURE, {}};
        }
    } else if (mDeviceV1_0 != nullptr) {
        NNTRACE_FULL(NNTRACE_LAYER_IPC, NNTRACE_PHASE_INITIALIZATION, "getCapabilities");
        Return<void> ret = mDeviceV1_0->getCapabilities(
                [&result](ErrorStatus error, const V1_0::Capabilities& capabilities) {
                    // Time taken to convert capabilities is trivial
                    result = std::make_pair(error, convertToV1_1(capabilities));
                });
        if (!ret.isOk()) {
            LOG(ERROR) << "getCapabilities failure: " << ret.description();
            return {ErrorStatus::GENERAL_FAILURE, {}};
        }
    } else {
        LOG(ERROR) << "Device not available!";
        return {ErrorStatus::DEVICE_UNAVAILABLE, {}};
    }

    return result;
}

std::pair<ErrorStatus, hidl_vec<Extension>> VersionedIDevice::getSupportedExtensions() {
    NNTRACE_FULL(NNTRACE_LAYER_IPC, NNTRACE_PHASE_COMPILATION, "getSupportedExtensions");
    if (mDeviceV1_2 != nullptr) {
        std::pair<ErrorStatus, hidl_vec<Extension>> result;
        Return<void> ret = mDeviceV1_2->getSupportedExtensions(
                [&result](ErrorStatus error, const hidl_vec<Extension>& extensions) {
                    result = std::make_pair(error, extensions);
                });
        if (!ret.isOk()) {
            LOG(ERROR) << "getSupportedExtensions failure: " << ret.description();
            return {ErrorStatus::GENERAL_FAILURE, {}};
        }
        return result;
    } else if (mDeviceV1_0 != nullptr) {
        return {ErrorStatus::NONE, {/* No extensions. */}};
    } else {
        LOG(ERROR) << "Device not available!";
        return {ErrorStatus::DEVICE_UNAVAILABLE, {}};
    }
}

std::pair<ErrorStatus, hidl_vec<bool>> VersionedIDevice::getSupportedOperations(
        const Model& model) {
    std::pair<ErrorStatus, hidl_vec<bool>> result;

    if (mDeviceV1_2 != nullptr) {
        NNTRACE_FULL(NNTRACE_LAYER_IPC, NNTRACE_PHASE_COMPILATION, "getSupportedOperations_1_2");
        Return<void> ret = mDeviceV1_2->getSupportedOperations_1_2(
                model, [&result](ErrorStatus error, const hidl_vec<bool>& supported) {
                    result = std::make_pair(error, supported);
                });
        if (!ret.isOk()) {
            LOG(ERROR) << "getSupportedOperations_1_2 failure: " << ret.description();
            return {ErrorStatus::GENERAL_FAILURE, {}};
        }
    } else if (mDeviceV1_1 != nullptr && compliantWithV1_1(model)) {
        V1_1::Model model11 = convertToV1_1(model);
        NNTRACE_FULL(NNTRACE_LAYER_IPC, NNTRACE_PHASE_COMPILATION, "getSupportedOperations_1_1");
        Return<void> ret = mDeviceV1_1->getSupportedOperations_1_1(
                model11, [&result](ErrorStatus error, const hidl_vec<bool>& supported) {
                    result = std::make_pair(error, supported);
                });
        if (!ret.isOk()) {
            LOG(ERROR) << "getSupportedOperations_1_1 failure: " << ret.description();
            return {ErrorStatus::GENERAL_FAILURE, {}};
        }
    } else if (mDeviceV1_0 != nullptr && compliantWithV1_0(model)) {
        V1_0::Model model10 = convertToV1_0(model);
        NNTRACE_FULL(NNTRACE_LAYER_IPC, NNTRACE_PHASE_COMPILATION, "getSupportedOperations_1_0");
        Return<void> ret = mDeviceV1_0->getSupportedOperations(
                model10, [&result](ErrorStatus error, const hidl_vec<bool>& supported) {
                    result = std::make_pair(error, supported);
                });
        if (!ret.isOk()) {
            LOG(ERROR) << "getSupportedOperations failure: " << ret.description();
            return {ErrorStatus::GENERAL_FAILURE, {}};
        }
    } else {
        // TODO: partition the model such that v1.1 ops are not passed to v1.0
        // device
        LOG(ERROR) << "Could not handle getSupportedOperations!";
        return {ErrorStatus::GENERAL_FAILURE, {}};
    }

    return result;
}

ErrorStatus VersionedIDevice::prepareModel(const Model& model, ExecutionPreference preference,
                                           const sp<IPreparedModelCallback>& callback) {
    if (mDeviceV1_2 != nullptr) {
        Return<ErrorStatus> ret = mDeviceV1_2->prepareModel_1_2(model, preference, callback);
        if (!ret.isOk()) {
            LOG(ERROR) << "prepareModel_1_2 failure: " << ret.description();
            return ErrorStatus::GENERAL_FAILURE;
        }
        return static_cast<ErrorStatus>(ret);
    } else if (mDeviceV1_1 != nullptr) {
        bool compliant = false;
        V1_1::Model model11;
        {
            // Attribute time spent in model inspection and conversion to
            // Runtime, as the time may be substantial (0.03ms for mobilenet,
            // but could be larger for other models).
            NNTRACE_FULL_SUBTRACT(NNTRACE_LAYER_RUNTIME, NNTRACE_PHASE_COMPILATION,
                                  "VersionedIDevice::prepareModel_1_1");
            compliant = compliantWithV1_1(model);
            if (compliant) {
                model11 = convertToV1_1(model);  // copy is elided
            }
        }
        if (compliant) {
            Return<ErrorStatus> ret = mDeviceV1_1->prepareModel_1_1(model11, preference, callback);
            if (!ret.isOk()) {
                LOG(ERROR) << "prepareModel_1_1 failure: " << ret.description();
                return ErrorStatus::GENERAL_FAILURE;
            }
            return static_cast<ErrorStatus>(ret);
        } else {
            // TODO: partition the model such that v1.2 ops are not passed to v1.1
            // device
            LOG(ERROR) << "Could not handle prepareModel_1_1!";
            return ErrorStatus::GENERAL_FAILURE;
        }
    } else if (mDeviceV1_0 != nullptr) {
        bool compliant = false;
        V1_0::Model model10;
        {
            // Attribute time spent in model inspection and conversion to
            // Runtime, as the time may be substantial (0.03ms for mobilenet,
            // but could be larger for other models).
            NNTRACE_FULL_SUBTRACT(NNTRACE_LAYER_RUNTIME, NNTRACE_PHASE_COMPILATION,
                                  "VersionedIDevice::prepareModel");
            compliant = compliantWithV1_0(model);
            if (compliant) {
                model10 = convertToV1_0(model);  // copy is elided
            }
        }
        if (compliant) {
            Return<ErrorStatus> ret = mDeviceV1_0->prepareModel(model10, callback);
            if (!ret.isOk()) {
                LOG(ERROR) << "prepareModel failure: " << ret.description();
                return ErrorStatus::GENERAL_FAILURE;
            }
            return static_cast<ErrorStatus>(ret);
        } else {
            // TODO: partition the model such that v1.1 ops are not passed to v1.0
            // device
            LOG(ERROR) << "Could not handle prepareModel!";
            return ErrorStatus::GENERAL_FAILURE;
        }
    } else {
        LOG(ERROR) << "prepareModel called with no device";
        return ErrorStatus::GENERAL_FAILURE;
    }
}

DeviceStatus VersionedIDevice::getStatus() {
    if (mDeviceV1_0 == nullptr) {
        LOG(ERROR) << "Device not available!";
        return DeviceStatus::UNKNOWN;
    }

    Return<DeviceStatus> ret = mDeviceV1_0->getStatus();

    if (!ret.isOk()) {
        LOG(ERROR) << "getStatus failure: " << ret.description();
        return DeviceStatus::UNKNOWN;
    }
    return static_cast<DeviceStatus>(ret);
}

int64_t VersionedIDevice::getFeatureLevel() {
    if (mDeviceV1_2 != nullptr) {
        return __ANDROID_API_Q__;
    } else if (mDeviceV1_1 != nullptr) {
        return __ANDROID_API_P__;
    } else if (mDeviceV1_0 != nullptr) {
        return __ANDROID_API_O_MR1__;
    } else {
        LOG(ERROR) << "Device not available!";
        return -1;
    }
}

int32_t VersionedIDevice::getType() const {
    std::pair<ErrorStatus, DeviceType> result;
    if (mDeviceV1_2 != nullptr) {
        Return<void> ret =
                mDeviceV1_2->getType([&result](ErrorStatus error, DeviceType deviceType) {
                    result = std::make_pair(error, deviceType);
                });
        if (!ret.isOk()) {
            LOG(ERROR) << "getType failure: " << ret.description();
            return -1;
        }
        return static_cast<int32_t>(result.second);
    } else {
        LOG(INFO) << "Unkown NNAPI device type.";
        return ANEURALNETWORKS_DEVICE_UNKNOWN;
    }
}

std::pair<ErrorStatus, hidl_string> VersionedIDevice::getVersionString() {
    std::pair<ErrorStatus, hidl_string> result;

    if (mDeviceV1_2 != nullptr) {
        Return<void> ret = mDeviceV1_2->getVersionString(
                [&result](ErrorStatus error, const hidl_string& version) {
                    result = std::make_pair(error, version);
                });
        if (!ret.isOk()) {
            LOG(ERROR) << "getVersion failure: " << ret.description();
            return {ErrorStatus::GENERAL_FAILURE, ""};
        }
        return result;
    } else if (mDeviceV1_1 != nullptr || mDeviceV1_0 != nullptr) {
        return {ErrorStatus::NONE, "UNKNOWN"};
    } else {
        LOG(ERROR) << "Could not handle getVersionString";
        return {ErrorStatus::GENERAL_FAILURE, ""};
    }
}

bool VersionedIDevice::operator==(nullptr_t) const {
    return mDeviceV1_0 == nullptr;
}

bool VersionedIDevice::operator!=(nullptr_t) const {
    return mDeviceV1_0 != nullptr;
}

}  // namespace nn
}  // namespace android
