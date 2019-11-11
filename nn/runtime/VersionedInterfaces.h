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

#ifndef ANDROID_FRAMEWORKS_ML_NN_RUNTIME_VERSIONED_INTERFACES_H
#define ANDROID_FRAMEWORKS_ML_NN_RUNTIME_VERSIONED_INTERFACES_H

#include <android-base/macros.h>

#include <cstddef>
#include <functional>
#include <memory>
#include <optional>
#include <shared_mutex>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

#include "Callbacks.h"
#include "HalInterfaces.h"

namespace android {
namespace nn {

// forward declarations
class ExecutionBurstController;
class IDeviceDeathHandler;
class IPreparedModelDeathHandler;
class MetaModel;
class VersionedIPreparedModel;

/**
 * Each class (VersionedIDevice, VersionedIPreparedModel) wraps a HIDL interface
 * of any version to abstract away version differences. It allows the remainder
 * of the runtime to always use the most up-to-date version of all HIDL types.
 * As such, any reference to a HIDL type in the rest of the runtime
 * will--by default--be the latest HIDL version.
 *
 * Each class will attempt to call the latest version of each interface method
 * if possible. If the latest method is unavailable, the versioned class
 * will attempt to upcast the type (e.g., V1_1::Model to V1_0::Model), and
 * invoke the latest interface method possible. If the versioned class
 * fails to find a matching applicable function, it will return an error.
 */

/** This class wraps an IDevice object of any version. */
class VersionedIDevice {
    DISALLOW_IMPLICIT_CONSTRUCTORS(VersionedIDevice);

    // forward declaration of nested class
    class Core;

   public:
    /**
     * Create a VersionedIDevice object.
     *
     * Prefer using this function over the constructor, as it adds more
     * protections.
     *
     * @param serviceName The name of the service that provides "device".
     * @param device A device object that is at least version 1.0 of the IDevice
     *               interface.
     * @return A valid VersionedIDevice object, otherwise nullptr.
     */
    static std::shared_ptr<VersionedIDevice> create(std::string serviceName,
                                                    sp<hal::V1_0::IDevice> device);

    /**
     * Constructor for the VersionedIDevice object.
     *
     * VersionedIDevice will default to using the latest version of all IDevice
     * interface methods automatically.
     *
     * @param serviceName The name of the service that provides core.getDevice<V1_0::IDevice>().
     * @param core An object that encapsulates a V1_0::IDevice, any appropriate downcasts to
     *             newer interfaces, and a hidl_death_recipient that will proactively handle
     *             the case when the service containing the IDevice object crashes.
     */
    VersionedIDevice(std::string serviceName, Core core);

    /**
     * Gets the capabilities of a driver.
     *
     * @return capabilities Capabilities of the driver.
     */
    const hal::Capabilities& getCapabilities() const;

    /**
     * Gets information about extensions supported by the driver implementation.
     *
     * Extensions of category ExtensionCategory::BASE must not appear
     * in the list.
     *
     * All extension operations and operands must be fully supported for the
     * extension to appear in the list of supported extensions.
     *
     * @return extensions A list of supported extensions.
     */
    const std::vector<hal::Extension>& getSupportedExtensions() const;

    /**
     * Gets the supported operations in a MetaModel.
     *
     * getSupportedOperations indicates which operations of
     * MetaModel::getModel() are fully supported by the vendor driver. If an
     * operation may not be supported for any reason, getSupportedOperations
     * must return false for that operation.
     *
     * @param metaModel A MetaModel whose operations--and their corresponding
     *                  operands--are to be verified by the driver.  When
     *                  metaModel.getModel() is not compliant with the HAL
     *                  version of the vendor driver, the MetaModel's slicing
     *                  functionality (MetaModel::getSlice*()) is employed
     *                  to query the vendor driver about which of the subset of
     *                  compliant operations are supported.  See the MetaModel
     *                  class in MetaModel.h for more details.
     * @return status Error status of the call, must be:
     *                - NONE if successful
     *                - DEVICE_UNAVAILABLE if driver is offline or busy
     *                - GENERAL_FAILURE if there is an unspecified error
     *                - INVALID_ARGUMENT if provided model is invalid
     * @return supportedOperations A list of supported operations, where true
     *                             indicates the operation is supported and
     *                             false indicates the operation is not
     *                             supported. The index of "supported"
     *                             corresponds with the index of the operation
     *                             it is describing.
     */
    std::pair<hal::ErrorStatus, hal::hidl_vec<bool>> getSupportedOperations(
            const MetaModel& metaModel) const;

    /**
     * Synchronously creates a prepared model for execution and optionally saves it
     * into cache files.
     *
     * prepareModel is used to make any necessary transformations or alternative
     * representations to a model for execution, possibly including
     * transformations on the constant data, optimization on the model's graph,
     * or compilation into the device's native binary format. The model itself
     * is not changed.
     *
     * Optionally, caching information may be provided for the driver to save
     * the prepared model to cache files for faster model compilation time
     * when the same model preparation is requested in the future. There are
     * two types of cache file handles provided to the driver: model cache
     * and data cache. For more information on the two types of cache handles,
     * refer to getNumberOfCacheFilesNeeded.
     *
     * The file descriptors must be opened with read and write permission. A file may
     * have any size, and the corresponding file descriptor may have any offset. The
     * driver must truncate a file to zero size before writing to that file. The file
     * descriptors may be closed by the client once the asynchronous preparation has
     * finished. The driver must dup a file descriptor if it wants to get access to
     * the cache file later.
     *
     * The model is prepared synchronously with respect to the caller. The
     * prepareModel function must verify the inputs to the preparedModel
     * function related to preparing the model (as opposed to saving the
     * prepared model to cache) are correct. If there is an error, prepareModel
     * must immediately return the appropriate ErrorStatus value and nullptr for
     * the VersionedIPreparedModel. If the inputs to the prepareModel function
     * that are related to preparing the model are valid and there is no error,
     * prepareModel must prepare the model.
     *
     * If the model was prepared successfully, prepareModel must return
     * ErrorStatus::NONE and the produced VersionedIPreparedModel object. If an
     * error occurred preparing the model, prepareModel must return the
     * appropriate ErrorStatus value and nullptr for the
     * VersionedIPreparedModel.
     *
     * Optionally, the driver may save the prepared model to cache during
     * preparation. Any error that occurs when saving to cache must not affect
     * the status of preparing the model. Even if the input arguments related to
     * the cache may be invalid, or the driver may fail to save to cache, the
     * prepareModel function must finish preparing the model. The driver may
     * choose not to save to cache even if the caching information is provided
     * and valid.
     *
     * The only information that may be unknown to the model at this stage is
     * the shape of the tensors, which may only be known at execution time. As
     * such, some driver services may return partially prepared models, where
     * the prepared model may only be finished when it is paired with a set of
     * inputs to the model. Note that the same prepared model object may be
     * used with different shapes of inputs on different (possibly concurrent)
     * executions.
     *
     * Multiple threads may call prepareModel on the same model concurrently.
     *
     * @param model The model to be prepared for execution.
     * @param preference Indicates the intended execution behavior of a prepared
     *     model.
     * @param modelCache A vector of handles with each entry holding exactly one
     *     cache file descriptor for the security-sensitive cache. The length of
     *     the vector must either be 0 indicating that caching information is not provided,
     *     or match the numModelCache returned from getNumberOfCacheFilesNeeded. The cache
     *     handles will be provided in the same order when retrieving the
     *     preparedModel from cache files with prepareModelFromCache.
     * @param dataCache A vector of handles with each entry holding exactly one
     *     cache file descriptor for the constants' cache. The length of
     *     the vector must either be 0 indicating that caching information is not provided,
     *     or match the numDataCache returned from getNumberOfCacheFilesNeeded. The cache
     *     handles will be provided in the same order when retrieving the
     *     preparedModel from cache files with prepareModelFromCache.
     * @param token A caching token of length Constant::BYTE_SIZE_OF_CACHE_TOKEN
     *     identifying the prepared model. The same token will be provided when retrieving
     *     the prepared model from the cache files with prepareModelFromCache.
     *     Tokens should be chosen to have a low rate of collision for a particular
     *     application. The driver cannot detect a collision; a collision will result
     *     in a failed execution or in a successful execution that produces incorrect
     *     output values. If both modelCache and dataCache are empty indicating that
     *     caching information is not provided, this token must be ignored.
     * @return A pair of:
     *     - status Error status of preparing the model; must be:
     *         - NONE if preparation succeeded
     *         - DEVICE_UNAVAILABLE if driver is offline or busy
     *         - GENERAL_FAILURE if there is an unspecified error
     *         - INVALID_ARGUMENT if one of the input arguments related to
     *             preparing the model is invalid
     *     - preparedModel A VersionedIPreparedModel object representing a model
     *         that has been prepared for execution, else nullptr.
     */
    std::pair<hal::ErrorStatus, std::shared_ptr<VersionedIPreparedModel>> prepareModel(
            const hal::Model& model, hal::ExecutionPreference preference,
            const hal::hidl_vec<hal::hidl_handle>& modelCache,
            const hal::hidl_vec<hal::hidl_handle>& dataCache, const hal::CacheToken& token) const;

    /**
     * Creates a prepared model from cache files for execution.
     *
     * prepareModelFromCache is used to retrieve a prepared model directly from
     * cache files to avoid slow model compilation time. There are
     * two types of cache file handles provided to the driver: model cache
     * and data cache. For more information on the two types of cache handles,
     * refer to getNumberOfCacheFilesNeeded.
     *
     * The file descriptors must be opened with read and write permission. A file may
     * have any size, and the corresponding file descriptor may have any offset. The
     * driver must truncate a file to zero size before writing to that file. The file
     * descriptors may be closed by the client once the asynchronous preparation has
     * finished. The driver must dup a file descriptor if it wants to get access to
     * the cache file later.
     *
     * The model is prepared synchronously with respect to the caller. The
     * prepareModelFromCache function must verify the inputs to the
     * prepareModelFromCache function are correct, and that the
     * security-sensitive cache has not been modified since it was last written
     * by the driver. If there is an error, or if compilation caching is not
     * supported, or if the security-sensitive cache has been modified,
     * prepareModelFromCache must return the appropriate ErrorStatus value and
     * nullptr for the VersionedIPreparedModel. If the inputs to the
     * prepareModelFromCache function are valid, the security-sensitive cache is
     * not modified, and there is no error, prepareModelFromCache must prepare
     * the model.
     *
     * If the model was prepared successfully, prepareModelFromCache must return
     * ErrorStatus::NONE and the produced VersionedIPreparedModel object. If an
     * error occurred preparing the model, prepareModelFromCache must return the
     * appropriate ErrorStatus value and nullptr for the
     * VersionedIPreparedModel.
     *
     * The only information that may be unknown to the model at this stage is
     * the shape of the tensors, which may only be known at execution time. As
     * such, some driver services may return partially prepared models, where
     * the prepared model may only be finished when it is paired with a set of
     * inputs to the model. Note that the same prepared model object may be
     * used with different shapes of inputs on different (possibly concurrent)
     * executions.
     *
     * @param modelCache A vector of handles with each entry holding exactly one
     *     cache file descriptor for the security-sensitive cache. The length of
     *     the vector must match the numModelCache returned from getNumberOfCacheFilesNeeded.
     *     The cache handles will be provided in the same order as with prepareModel_1_2.
     * @param dataCache A vector of handles with each entry holding exactly one
     *     cache file descriptor for the constants' cache. The length of the vector
     *     must match the numDataCache returned from getNumberOfCacheFilesNeeded.
     *     The cache handles will be provided in the same order as with prepareModel_1_2.
     * @param token A caching token of length Constant::BYTE_SIZE_OF_CACHE_TOKEN
     *     identifying the prepared model. It is the same token provided when saving
     *     the cache files with prepareModel_1_2. Tokens should be chosen
     *     to have a low rate of collision for a particular application. The driver
     *     cannot detect a collision; a collision will result in a failed execution
     *     or in a successful execution that produces incorrect output values.
     * @return A pair of:
     *     - status Error status of preparing the model; must be:
     *         - NONE if preparation succeeded
     *         - DEVICE_UNAVAILABLE if driver is offline or busy
     *         - GENERAL_FAILURE if caching is not supported or if there is an
     *             unspecified error
     *         - INVALID_ARGUMENT if one of the input arguments is invalid
     *     - preparedModel A VersionedIPreparedModel object representing a model
     *        that has been prepared for execution, else nullptr.
     */
    std::pair<hal::ErrorStatus, std::shared_ptr<VersionedIPreparedModel>> prepareModelFromCache(
            const hal::hidl_vec<hal::hidl_handle>& modelCache,
            const hal::hidl_vec<hal::hidl_handle>& dataCache, const hal::CacheToken& token) const;

    /**
     * Returns the current status of a driver.
     *
     * @return status Status of the driver, one of:
     *                - DeviceStatus::AVAILABLE
     *                - DeviceStatus::BUSY
     *                - DeviceStatus::OFFLINE
     *                - DeviceStatus::UNKNOWN
     */
    hal::DeviceStatus getStatus() const;

    /**
     * Returns the feature level of a driver.
     *
     * @return featureLevel The API level of the most advanced feature this driver implements.
     *                      For example, if the driver implements the features introduced in
     *                      Android P, the value would be 28.
     *                      Return -1 if the driver is offline or busy, or the query resulted in
     *                      an unspecified error.
     */
    int64_t getFeatureLevel() const;

    /**
     * Returns the device type of a driver.
     *
     * @return deviceType The type of a given device, which can help application
     *     developers to distribute Machine Learning workloads and other
     *     workloads such as graphical rendering. E.g., for an app which renders
     *     AR scenes based on real time object detection results, the developer
     *     could choose an ACCELERATOR type device for ML workloads, and reserve
     *     GPU for graphical rendering.
     */
    int32_t getType() const;

    /**
     * Get the version string of the driver implementation.
     *
     * The version string must be a unique token among the set of version strings of
     * drivers of a specific device. The token identifies the device driver's
     * implementation. The token must not be confused with the feature level which is solely
     * defined by the interface version. This API is opaque to the Android framework, but the
     * Android framework may use the information for debugging or to pass on to NNAPI applications.
     *
     * Application developers sometimes have specific requirements to ensure good user experiences,
     * and they need more information to make intelligent decisions when the Android framework
     * cannot. For example, combined with the device name and other information, the token can help
     * NNAPI applications filter devices based on their needs:
     *     - An application demands a certain level of performance, but a specific version of
     *       the driver cannot meet that requirement because of a performance regression.
     *       The application can blacklist the driver based on the version provided.
     *     - An application has a minimum precision requirement, but certain versions of
     *       the driver cannot meet that requirement because of bugs or certain optimizations.
     *       The application can filter out versions of these drivers.
     *
     * @return version The version string of the device implementation.
     */
    const std::string& getVersionString() const;

    /**
     * Gets the caching requirements of the driver implementation.
     *
     * There are two types of cache file descriptors provided to the driver: model cache
     * and data cache.
     *
     * The data cache is for caching constant data, possibly including preprocessed
     * and transformed tensor buffers. Any modification to the data cache should
     * have no worse effect than generating bad output values at execution time.
     *
     * The model cache is for caching security-sensitive data such as compiled
     * executable machine code in the device's native binary format. A modification
     * to the model cache may affect the driver's execution behavior, and a malicious
     * client could make use of this to execute beyond the granted permission. Thus,
     * the driver must always check whether the model cache is corrupted before
     * preparing the model from cache.
     *
     * getNumberOfCacheFilesNeeded returns how many of each type of cache files the driver
     * implementation needs to cache a single prepared model. Returning 0 for both types
     * indicates compilation caching is not supported by this driver. The driver may
     * still choose not to cache certain compiled models even if it reports that caching
     * is supported.
     *
     * If the device reports that caching is not supported, the user may avoid calling
     * IDevice::prepareModelFromCache or providing cache file descriptors to
     * IDevice::prepareModel_1_2.
     *
     * @return numModelCache An unsigned integer indicating how many files for model cache
     *                       the driver needs to cache a single prepared model. It must
     *                       be less than or equal to Constant::MAX_NUMBER_OF_CACHE_FILES.
     * @return numDataCache An unsigned integer indicating how many files for data cache
     *                      the driver needs to cache a single prepared model. It must
     *                      be less than or equal to Constant::MAX_NUMBER_OF_CACHE_FILES.
     */
    std::pair<uint32_t, uint32_t> getNumberOfCacheFilesNeeded() const;

    /**
     * Returns the name of the service.
     *
     * @return Name of the service.
     */
    const std::string& getName() const;

   private:
    // initializeInternal is called once during VersionedIDevice creation.
    // 'true' indicates successful initialization.
    bool initializeInternal();

    // internal helper methods
    std::pair<hal::ErrorStatus, hal::Capabilities> getCapabilitiesInternal() const;
    std::pair<hal::ErrorStatus, hal::hidl_vec<hal::Extension>> getSupportedExtensionsInternal()
            const;
    int32_t getTypeInternal() const;
    std::pair<hal::ErrorStatus, hal::hidl_string> getVersionStringInternal() const;
    std::tuple<hal::ErrorStatus, uint32_t, uint32_t> getNumberOfCacheFilesNeededInternal() const;

    // internal members for the cached results of the internal methods above
    hal::Capabilities mCapabilities;
    std::vector<hal::Extension> mSupportedExtensions;
    int32_t mType;
    std::string mVersionString;
    std::pair<uint32_t, uint32_t> mNumberOfCacheFilesNeeded;

    /**
     * This is a utility class for VersionedIDevice that encapsulates a
     * V1_0::IDevice, any appropriate downcasts to newer interfaces, and a
     * hidl_death_recipient that will proactively handle the case when the
     * service containing the IDevice object crashes.
     *
     * This is a convenience class to help VersionedIDevice recover from an
     * IDevice object crash: It bundles together all the data that needs to
     * change when recovering from a crash, and simplifies the process of
     * instantiating that data (at VersionedIDevice creation time) and
     * re-instantiating that data (at crash recovery time).
     */
    class Core {
       public:
        /**
         * Constructor for the Core object.
         *
         * Core is constructed with a V1_0::IDevice object, which represents a
         * device that is at least v1.0 of the interface. The constructor
         * downcasts to the latest version of the IDevice interface, allowing
         * VersionedIDevice to default to using the latest version of all
         * IDevice interface methods automatically.
         *
         * @param device A device object that is at least version 1.0 of the IDevice
         *               interface.
         * @param deathHandler A hidl_death_recipient that will proactively handle
         *                     the case when the service containing the IDevice
         *                     object crashes.
         */
        Core(sp<hal::V1_0::IDevice> device, sp<IDeviceDeathHandler> deathHandler);

        /**
         * Destructor for the Core object.
         *
         * This destructor unlinksToDeath this object's hidl_death_recipient as it
         * no longer needs to handle the case where the IDevice's service crashes.
         */
        ~Core();

        // Support move but not copy
        Core(Core&&) noexcept;
        Core& operator=(Core&&) noexcept;
        Core(const Core&) = delete;
        Core& operator=(const Core&) = delete;

        /**
         * Create a Core object.
         *
         * Prefer using this function over the constructor, as it adds more
         * protections.
         *
         * This call linksToDeath a hidl_death_recipient that can
         * proactively handle the case when the service containing the IDevice
         * object crashes.
         *
         * @param device A device object that is at least version 1.0 of the IDevice
         *               interface.
         * @return A valid Core object, otherwise nullopt.
         */
        static std::optional<Core> create(sp<hal::V1_0::IDevice> device);

        /**
         * Returns sp<*::IDevice> that is a downcast of the sp<V1_0::IDevice>
         * passed to the constructor.  This will be nullptr if that IDevice is
         * not actually of the specified downcast type.
         */
        template <typename T_IDevice>
        sp<T_IDevice> getDevice() const;
        template <>
        sp<hal::V1_0::IDevice> getDevice() const {
            return mDeviceV1_0;
        }
        template <>
        sp<hal::V1_1::IDevice> getDevice() const {
            return mDeviceV1_1;
        }
        template <>
        sp<hal::V1_2::IDevice> getDevice() const {
            return mDeviceV1_2;
        }
        template <>
        sp<hal::V1_3::IDevice> getDevice() const {
            return mDeviceV1_3;
        }

        /**
         * Returns sp<*::IDevice> (as per getDevice()) and the
         * hidl_death_recipient that will proactively handle the case when the
         * service containing the IDevice object crashes.
         */
        template <typename T_IDevice>
        std::pair<sp<T_IDevice>, sp<IDeviceDeathHandler>> getDeviceAndDeathHandler() const;

       private:
        /**
         * All versions of IDevice are necessary because the driver could be v1.0,
         * v1.1, or a later version. All these pointers logically represent the same
         * object.
         *
         * The general strategy is: HIDL returns a V1_0 device object, which
         * (if not nullptr) could be v1.0, v1.1, or a greater version. The V1_0
         * object is then "dynamically cast" to a V1_1 object. If successful,
         * mDeviceV1_1 will point to the same object as mDeviceV1_0; otherwise,
         * mDeviceV1_1 will be nullptr.
         *
         * In general:
         * * If the device is truly v1.0, mDeviceV1_0 will point to a valid object
         *   and mDeviceV1_1 will be nullptr.
         * * If the device is truly v1.1 or later, both mDeviceV1_0 and mDeviceV1_1
         *   will point to the same valid object.
         *
         * Idiomatic usage: if mDeviceV1_1 is non-null, do V1_1 dispatch; otherwise,
         * do V1_0 dispatch.
         */
        sp<hal::V1_0::IDevice> mDeviceV1_0;
        sp<hal::V1_1::IDevice> mDeviceV1_1;
        sp<hal::V1_2::IDevice> mDeviceV1_2;
        sp<hal::V1_3::IDevice> mDeviceV1_3;

        /**
         * HIDL callback to be invoked if the service for mDeviceV1_0 crashes.
         *
         * nullptr if this Core instance is a move victim and hence has no
         * callback to be unlinked.
         */
        sp<IDeviceDeathHandler> mDeathHandler;
    };

    // This method retrieves the appropriate mCore.mDevice* field, under a read lock.
    template <typename T_IDevice>
    sp<T_IDevice> getDevice() const EXCLUDES(mMutex) {
        std::shared_lock lock(mMutex);
        return mCore.getDevice<T_IDevice>();
    }

    // This method retrieves the appropriate mCore.mDevice* fields, under a read lock.
    template <typename T_IDevice>
    auto getDeviceAndDeathHandler() const EXCLUDES(mMutex) {
        std::shared_lock lock(mMutex);
        return mCore.getDeviceAndDeathHandler<T_IDevice>();
    }

    // This method calls the function fn in a manner that supports recovering
    // from a driver crash: If the driver implementation is dead because the
    // driver crashed either before the call to fn or during the call to fn, we
    // will attempt to obtain a new instance of the same driver and call fn
    // again.
    //
    // If a callback is provided, this method protects it against driver death
    // and waits for it (callback->wait()).
    template <typename T_Return, typename T_IDevice, typename T_Callback = std::nullptr_t>
    hal::Return<T_Return> recoverable(
            const char* context,
            const std::function<hal::Return<T_Return>(const sp<T_IDevice>&)>& fn,
            const T_Callback& callback = nullptr) const EXCLUDES(mMutex);

    // The name of the service that implements the driver.
    const std::string mServiceName;

    // Guards access to mCore.
    mutable std::shared_mutex mMutex;

    // Data that can be rewritten during driver recovery.  Guarded againt
    // synchronous access by a mutex: Any number of concurrent read accesses is
    // permitted, but a write access excludes all other accesses.
    mutable Core mCore GUARDED_BY(mMutex);
};

/** This class wraps an IPreparedModel object of any version. */
class VersionedIPreparedModel {
    DISALLOW_IMPLICIT_CONSTRUCTORS(VersionedIPreparedModel);

   public:
    /**
     * Constructor for the VersionedIPreparedModel object.
     *
     * This constructor should not be used directly. Instead,
     * VersionedIPreparedModel should be created via
     * VersionedIDevice::prepareModel*.
     *
     * VersionedIPreparedModel is constructed with the V1_0::IPreparedModel object, which
     * represents a device that is at least v1.0 of the interface. The constructor downcasts
     * to the latest version of the IPreparedModel interface, and will default to using the
     * latest version of all IPreparedModel interface methods automatically.
     *
     * @param preparedModel A prepared model object that is least version 1.0 of the
     *                      IPreparedModel interface.
     * @param deathHandler A hidl_death_recipient that will proactively handle
     *                     the case when the service containing the IDevice
     *                     object crashes.
     */
    VersionedIPreparedModel(sp<hal::V1_0::IPreparedModel> preparedModel,
                            sp<IPreparedModelDeathHandler> deathHandler);

    /**
     * Destructor for the VersionedIPreparedModel object.
     *
     * This destructor unlinksToDeath this object's hidl_death_recipient as it
     * no longer needs to handle the case where the IPreparedModel's service
     * crashes.
     */
    ~VersionedIPreparedModel();

    /**
     * Performs a synchronous execution on a prepared model.
     *
     * The execution is performed synchronously with respect to the caller.
     * VersionedIPreparedModel::execute must verify the inputs to the function
     * are correct. If there is an error, VersionedIPreparedModel::execute must
     * immediately return with the appropriate result code. If the inputs to the
     * function are valid and there is no error,
     * VersionedIPreparedModel::execute must perform the execution, and must not
     * return until the execution is complete.
     *
     * If the prepared model was prepared from a model wherein all tensor
     * operands have fully specified dimensions, and the inputs to the function
     * are valid, and at execution time every operation's input operands have
     * legal values, then the execution should complete successfully
     * (ANEURALNETWORKS_NO_ERROR): There must be no failure unless the device
     * itself is in a bad state.
     *
     * Any number of calls to the VersionedIPreparedModel::execute function, in
     * any combination, may be made concurrently, even on the same
     * VersionedIPreparedModel object.
     *
     * @param request The input and output information on which the prepared
     *     model is to be executed.
     * @param measure Specifies whether or not to measure duration of the
     *     execution.
     * @param preferSynchronous 'true' to perform synchronous HAL execution when
     *     possible, 'false' to force asynchronous HAL execution.
     * @return A tuple consisting of:
     *     - Result code of the execution, must be:
     *         - ANEURALNETWORKS_NO_ERROR if execution is performed successfully
     *         - ANEURALNETWORKS_UNAVAILABLE_DEVICE if driver is offline or busy
     *         - ANEURALNETWORKS_OP_FAILED if there is an unspecified error
     *         - ANEURALNETWORKS_OUTPUT_INSUFFICIENT_SIZE if at least one output
     *             operand buffer is not large enough to store the corresponding
     *             output
     *         - ANEURALNETWORKS_BAD_DATA if one of the input arguments is
     *             invalid
     *     - A list of shape information of model output operands.
     *         The index into "outputShapes" corresponds to the index of the
     *         output operand in the Request outputs vector. outputShapes must
     *         be empty unless the result code is either
     *         ANEURALNETWORKS_NO_ERROR or
     *         ANEURALNETWORKS_OUTPUT_INSUFFICIENT_SIZE. outputShapes may be
     *         empty if the result code is ANEURALNETWORKS_NO_ERROR and all
     *         model output operands are fully-specified at execution time.
     *         outputShapes must have the same number of elements as the number
     *         of model output operands if the result code is
     *         ANEURALNETWORKS_OUTPUT_INSUFFICIENT_SIZE, or if the result code
     *         is ANEURALNETWORKS_NO_ERROR and the model has at least one output
     *         operand that is not fully-specified.
     *     - Duration of execution. Unless measure is YES and result code is
     *         ANEURALNETWORKS_NO_ERROR, all times must be reported as
     *         UINT64_MAX. A driver may choose to report any time as UINT64_MAX,
     *         indicating that measurement is not available.
     */
    std::tuple<int, std::vector<hal::OutputShape>, hal::Timing> execute(
            const hal::Request& request, hal::MeasureTiming measure, bool preferSynchronous) const;

    /**
     * Creates a burst controller on a prepared model.
     *
     * @param preferPowerOverLatency 'true' if the Burst object should run in a
     *                               more power efficient mode, 'false' if more
     *                               power can be used to possibly reduce
     *                               burst compute latency.
     * @return ExecutionBurstController Execution burst controller object.
     *                                  nullptr is returned if the burst cannot
     *                                  be configured for any reason.
     */
    std::shared_ptr<ExecutionBurstController> configureExecutionBurst(
            bool preferPowerOverLatency) const;

   private:
    std::tuple<int, std::vector<hal::OutputShape>, hal::Timing> executeAsynchronously(
            const hal::Request& request, hal::MeasureTiming timing) const;
    std::tuple<int, std::vector<hal::OutputShape>, hal::Timing> executeSynchronously(
            const hal::Request& request, hal::MeasureTiming measure) const;

    /**
     * All versions of IPreparedModel are necessary because the preparedModel could be v1.0,
     * v1.2, or a later version. All these pointers logically represent the same object.
     *
     * The general strategy is: HIDL returns a V1_0 prepared model object, which
     * (if not nullptr) could be v1.0, v1.2, or a greater version. The V1_0
     * object is then "dynamically cast" to a V1_2 object. If successful,
     * mPreparedModelV1_2 will point to the same object as mPreparedModelV1_0; otherwise,
     * mPreparedModelV1_2 will be nullptr.
     *
     * In general:
     * * If the prepared model is truly v1.0, mPreparedModelV1_0 will point to a valid object
     *   and mPreparedModelV1_2 will be nullptr.
     * * If the prepared model is truly v1.2 or later, both mPreparedModelV1_0 and
     *   mPreparedModelV1_2 will point to the same valid object.
     *
     * Idiomatic usage: if mPreparedModelV1_2 is non-null, do V1_2 dispatch; otherwise,
     * do V1_0 dispatch.
     */
    sp<hal::V1_0::IPreparedModel> mPreparedModelV1_0;
    sp<hal::V1_2::IPreparedModel> mPreparedModelV1_2;

    /**
     * HIDL callback to be invoked if the service for mPreparedModelV1_0 crashes.
     */
    const sp<IPreparedModelDeathHandler> mDeathHandler;
};

}  // namespace nn
}  // namespace android

#endif  // ANDROID_FRAMEWORKS_ML_NN_RUNTIME_VERSIONED_INTERFACES_H
