%% template file for generating NeuralNetworks.h.
%% see README.md.
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

/**
 * @addtogroup NeuralNetworks
 * @{
 */

/**
 * @file NeuralNetworks.h
 */

#ifndef ANDROID_FRAMEWORKS_ML_NN_RUNTIME_NEURAL_NETWORKS_H
#define ANDROID_FRAMEWORKS_ML_NN_RUNTIME_NEURAL_NETWORKS_H

/******************************************************************
 *
 * IMPORTANT NOTICE:
 *
 *   This file is part of Android's set of stable system headers
 *   exposed by the Android NDK (Native Development Kit).
 *
 *   Third-party source AND binary code relies on the definitions
 *   here to be FROZEN ON ALL UPCOMING PLATFORM RELEASES.
 *
 *   - DO NOT MODIFY ENUMS (EXCEPT IF YOU ADD NEW 32-BIT VALUES)
 *   - DO NOT MODIFY CONSTANTS OR FUNCTIONAL MACROS
 *   - DO NOT CHANGE THE SIGNATURE OF FUNCTIONS IN ANY WAY
 *   - DO NOT CHANGE THE LAYOUT OR SIZE OF STRUCTURES
 */

#include <android/hardware_buffer.h>
#include <stddef.h>
#include <stdint.h>
#include <sys/cdefs.h>

__BEGIN_DECLS

%insert Operand_1.0_Comment
typedef enum {
%insert Operand_1.0
#if __ANDROID_API__ >= __ANDROID_API_Q__
%insert Operand_1.2
#endif  // __ANDROID_API__ >= __ANDROID_API_Q__
} OperandCode;

%insert Operation_1.0_Comment
typedef enum {
    // Operations below are available since API level 27.

%insert Operation_1.0

    // Operations below are available since API level 28.

%insert Operation_1.1

    // Operations below are available since API level 29.

%insert Operation_1.2
} OperationCode;

/**
 * Fused activation function types.
 *
 *
 * Available since API level 27.
 */
typedef enum {
    /** NO fused activation function. */
    ANEURALNETWORKS_FUSED_NONE = 0,
    /** Fused ReLU activation function. */
    ANEURALNETWORKS_FUSED_RELU = 1,
    /** Fused ReLU1 activation function. */
    ANEURALNETWORKS_FUSED_RELU1 = 2,
    /** Fused ReLU6 activation function. */
    ANEURALNETWORKS_FUSED_RELU6 = 3,
} FuseCode;

/**
 * Implicit padding algorithms.
 *
 *
 * Available since API level 27.
 */
typedef enum {
    /**
     * SAME padding.
     * Padding on both ends are the "same":
     *     padding_to_beginning =  total_padding / 2
     *     padding_to_end       = (total_padding + 1)/2.
     * i.e., for even number of padding, padding to both ends are exactly
     * the same; for odd number of padding, padding to the ending is bigger
     * than the padding to the beginning by 1.
     *
     * total_padding is a function of input, stride, dilation and filter size.
     * It could be computed as follows:
     *    out_size = (input + stride - 1) / stride
     *    effective_filter_size = (filter_size - 1) * dilation + 1
     *    needed_input = (out_size - 1) * stride + effective_filter_size
     *    total_padding = max(0, needed_input - input_size)
     *  The computation is the same for the horizontal and vertical directions.
     */
    ANEURALNETWORKS_PADDING_SAME = 1,

    /**
     * VALID padding.
     * No padding. When the input size is not evenly divisible by
     * the filter size, the input at the end that could not fill
     * the whole filter tile will simply be ignored.
     */
    ANEURALNETWORKS_PADDING_VALID = 2,
} PaddingCode;

/**
 * Execution preferences.
 *
 * Available since API level 27.
 */
typedef enum {
    /**
     * Prefer executing in a way that minimizes battery drain.
     * This is desirable for compilations that will be executed often.
     */
    ANEURALNETWORKS_PREFER_LOW_POWER = 0,
    /**
     * Prefer returning a single answer as fast as possible, even if this causes
     * more power consumption.
     */
    ANEURALNETWORKS_PREFER_FAST_SINGLE_ANSWER = 1,
    /**
     * Prefer maximizing the throughput of successive frames, for example when
     * processing successive frames coming from the camera.
     */
    ANEURALNETWORKS_PREFER_SUSTAINED_SPEED = 2,
} PreferenceCode;

/**
 * Device types.
 *
 * The type of NNAPI device.
 */
typedef enum {
    /** The device type cannot be provided. */
    ANEURALNETWORKS_DEVICE_UNKNOWN = 0,
    /** The device does not fall into any category below. */
    ANEURALNETWORKS_DEVICE_OTHER = 1,
    /** The device runs NNAPI models on single or multi-core CPU. */
    ANEURALNETWORKS_DEVICE_CPU = 2,
    /** The device can run NNAPI models and also accelerate graphics APIs such
     * as OpenGL ES and Vulkan. */
    ANEURALNETWORKS_DEVICE_GPU = 3,
    /** Dedicated accelerator for Machine Learning workloads. */
    ANEURALNETWORKS_DEVICE_ACCELERATOR = 4,
} DeviceTypeCode;

/**
 * Result codes.
 *
 * <p>Any NNAPI function can return any result code, including result codes not
 * currently documented. Any value other than {@link ANEURALNETWORKS_NO_ERROR}
 * indicates a failure of some kind.</p>
 *
 * <p>Additional information about the nature of a failure can be obtained from
 * the device log after enabling NNAPI debugging by setting the debug.nn.vlog
 * property to 1, e.g., by calling "adb shell setprop debug.nn.vlog 1".</p>
 *
 * Available since API level 27.
 */
typedef enum {
    /**
     * Operation was succesful.
     */
    ANEURALNETWORKS_NO_ERROR = 0,

    /**
     * Failure caused by not enough available memory.
     */
    ANEURALNETWORKS_OUT_OF_MEMORY = 1,

    ANEURALNETWORKS_INCOMPLETE = 2,

    /**
     * Failure caused by unexpected null argument.
     */
    ANEURALNETWORKS_UNEXPECTED_NULL = 3,

    /**
     * Failure caused by invalid function arguments, invalid model definition,
     * invalid execution definition or invalid data at execution time.
     */
    ANEURALNETWORKS_BAD_DATA = 4,

    /**
     * Failure caused by failed model execution.
     */
    ANEURALNETWORKS_OP_FAILED = 5,

    /**
     * Failure caused by object being in the wrong state.
     */
    ANEURALNETWORKS_BAD_STATE = 6,

    /**
     * Failure caused by not being able to map a file into memory.
     * This may be caused by a file descriptor not being mappable, or an AHardwareBuffer
     * not supported by the device.
     * Mitigate by reading its content into memory.
     */
    ANEURALNETWORKS_UNMAPPABLE = 7,

    /**
     * Failure caused by insufficient buffer size provided to a model output.
     */
    ANEURALNETWORKS_OUTPUT_INSUFFICIENT_SIZE = 8,

    /**
     * Failure caused by a device not being available.
     */
    ANEURALNETWORKS_UNAVAILABLE_DEVICE = 9,
} ResultCode;

/**
 * For {@link ANeuralNetworksModel_setOperandValue}, values with a
 * length smaller or equal to this will be immediately copied into
 * the model. The size is in bytes.
 *
 * Available since API level 27.
 */
enum { ANEURALNETWORKS_MAX_SIZE_OF_IMMEDIATELY_COPIED_VALUES = 128 };

/**
 * For {@link ANeuralNetworksCompilation_setCaching}, specify the size
 * of the cache token required from the application. The size is in bytes.
 *
 * Available since API level 29.
 */
enum { ANEURALNETWORKS_BYTE_SIZE_OF_CACHE_TOKEN = 32 };

/**
 * ANeuralNetworksMemory is an opaque type that represents memory.
 *
 * This type is used to represent shared memory, memory mapped files,
 * and similar memories.
 *
 * By using shared memory, a program can efficiently communicate to the
 * runtime and drivers the tensors that define a model. See
 * {@link ANeuralNetworksModel_setOperandValueFromMemory}. An application
 * should typically create one shared memory object that contains every constant tensor
 * needed to define a model. {@link ANeuralNetworksMemory_createFromFd} can be used to
 * create shared memory from a file handle.
 * {@link ANeuralNetworksMemory_createFromAHardwareBuffer} can be used to
 * create shared memory from an AHardwareBuffer handle.
 *
 * Memory objects can also be used to specify the input and output arguments of
 * an execution. See {@link ANeuralNetworksExecution_setInputFromMemory}
 * and {@link ANeuralNetworksExecution_setOutputFromMemory}.
 *
 * When calling {@link ANeuralNetworksModel_setOperandValueFromMemory},
 * {@link ANeuralNetworksExecution_setInputFromMemory} and
 * {@link ANeuralNetworksExecution_setOutputFromMemory}, each operand in the shared
 * memory object must be aligned on a boundary of a byte size that is a multiple
 * of the element type byte size, e.g., a tensor with
 * {@link ANEURALNETWORKS_TENSOR_FLOAT32} type must be aligned on 4-byte boundary.
 *
 * It is the application's responsibility to ensure that there are no uses of
 * the memory after calling {@link ANeuralNetworksMemory_free}. This includes
 * any model which references this memory because of a call to
 * {@link ANeuralNetworksModel_setOperandValueFromMemory}, any compilation
 * created using such a model, any execution object or burst object created
 * using such a compilation, or any execution which references this memory
 * because of a call to {@link ANeuralNetworksExecution_setInputFromMemory} or
 * {@link ANeuralNetworksExecution_setOutputFromMemory}.
 *
 * Available since API level 27.
 */
typedef struct ANeuralNetworksMemory ANeuralNetworksMemory;

/**
 * ANeuralNetworksModel is an opaque type that contains a description of the
 * mathematical operations that constitute the model.
 *
 * <p>Build the model by calling<ul>
 * <li>{@link ANeuralNetworksModel_create}</li>
 * <li>{@link ANeuralNetworksModel_addOperation}</li>
 * <li>{@link ANeuralNetworksModel_addOperand}</li>
 * </ul>
 *
 * This forms a graph in which each operation and operand is a node, a
 * directed edge from an operand to an operation indicates that the
 * operand is an input to the operation, and a directed edge from an
 * operation to an operand indicates that the operand is an output
 * from the operation. This graph must be acyclic.
 *
 * A model is completed by calling {@link ANeuralNetworksModel_finish}.
 * A model is destroyed by calling {@link ANeuralNetworksModel_free}.
 *
 * <p>A model cannot be modified once {@link ANeuralNetworksModel_finish}
 * has been called on it.</p>
 *
 * <p>It is the application's responsibility to make sure that only one thread
 * modifies a model at a given time. It is however safe for more than one
 * thread to use the model once {@link ANeuralNetworksModel_finish} has returned.</p>
 *
 * <p>It is also the application's responsibility to ensure that there are no
 * other uses of the model after calling {@link ANeuralNetworksModel_free}.
 * This includes any compilation, execution object or burst object created using
 * the model.</p>
 *
 * Available since API level 27.
 */
typedef struct ANeuralNetworksModel ANeuralNetworksModel;

/**
 * ANeuralNetworksCompilation is an opaque type that can be used to compile
 * a machine learning model.
 *
 * <p>To use:<ul>
 *    <li>Create a new compilation instance by calling the
 *        {@link ANeuralNetworksCompilation_create} function or
 *        {@link ANeuralNetworksCompilation_createForDevices}.</li>
 *    <li>Set any desired properties on the compilation (for example,
 *        {@link ANeuralNetworksCompilation_setPreference}).</li>
 *    <li>Optionally, set the caching signature and the cache directory on the
 *        compilation by calling {@link ANeuralNetworksCompilation_setCaching}.</li>
 *    <li>Complete the compilation with {@link ANeuralNetworksCompilation_finish}.</li>
 *    <li>Use the compilation as many times as needed
 *        with {@link ANeuralNetworksExecution_create} and
 *        {@link ANeuralNetworksBurst_create}.</li>
 *    <li>Destroy the compilation with {@link ANeuralNetworksCompilation_free}
 *        once all executions using the compilation have completed.</li></ul></p>
 *
 * A compilation is completed by calling {@link ANeuralNetworksCompilation_finish}.
 * A compilation is destroyed by calling {@link ANeuralNetworksCompilation_free}.
 *
 * <p>A compilation cannot be modified once {@link ANeuralNetworksCompilation_finish}
 * has been called on it.</p>
 *
 * <p>It is the application's responsibility to make sure that only
 * one thread modifies a compilation at a given time. It is however
 * safe for more than one thread to use the compilation once
 * {@link ANeuralNetworksCompilation_finish} has returned.</p>
 *
 * <p>It is also the application's responsibility to ensure that there are no other
 * uses of the compilation after calling {@link ANeuralNetworksCompilation_free}.
 * This includes any execution object or burst object created using the compilation.</p>
 *
 * Available since API level 27.
 */
typedef struct ANeuralNetworksCompilation ANeuralNetworksCompilation;

/**
 * ANeuralNetworksExecution is an opaque type that can be used to apply a machine
 * learning model to a set of inputs.
 *
 * <p>To use:<ul>
 *    <li>Create a new execution instance by calling the
 *        {@link ANeuralNetworksExecution_create} function.</li>
 *    <li>Associate input buffers or memory regions to the model inputs with
 *        {@link ANeuralNetworksExecution_setInput} or
 *        {@link ANeuralNetworksExecution_setInputFromMemory}.</li>
 *    <li>Associate output buffers or memory regions to the model outputs with
 *        {@link ANeuralNetworksExecution_setOutput} or
 *        {@link ANeuralNetworksExecution_setOutputFromMemory}.</li>
 *    <li>Apply the model with one of the following:</li><ul>
 *        <li>Asynchronously with {@link ANeuralNetworksExecution_startCompute},
 *            waiting for the execution to complete with
 *            {@link ANeuralNetworksEvent_wait}.</li>
 *        <li>Synchronously with {@link ANeuralNetworksExecution_compute}.</li>
 *        <li>Synchronously as part of an execution burst with
 *            {@link ANeuralNetworksExecution_burstCompute}.</li></ul>
 *    <li>Destroy the execution with
 *        {@link ANeuralNetworksExecution_free}.</li></ul></p>
 *
 * <p>An output buffer or memory region must not overlap with any
 * other output buffer or memory region, with an input buffer or
 * memory region, or with an operand value in a memory object
 * ({@link ANeuralNetworksModel_setOperandValueFromMemory}).</p>
 *
 * <p>An execution cannot be modified once
 * {@link ANeuralNetworksExecution_burstCompute},
 * {@link ANeuralNetworksExecution_compute} or
 * {@link ANeuralNetworksExecution_startCompute} has been called on it.</p>
 *
 * <p>An execution can be applied to a model with
 * {@link ANeuralNetworksExecution_burstCompute},
 * {@link ANeuralNetworksExecution_compute} or
 * {@link ANeuralNetworksExecution_startCompute} only once. Create new
 * executions to do new evaluations of the model.</p>
 *
 * <p>It is the application's responsibility to make sure that only one thread
 * modifies an execution at a given time. It is however safe for more than one
 * thread to use {@link ANeuralNetworksEvent_wait} at the same time.</p>
 *
 * <p>It is also the application's responsibility to ensure that the execution
 * either has never been scheduled or has completed (i.e., that
 * {@link ANeuralNetworksExecution_burstCompute},
 * {@link ANeuralNetworksExecution_compute}, or
 * {@link ANeuralNetworksEvent_wait} has returned) before calling
 * {@link ANeuralNetworksExecution_free}.</p>.
 *
 * <p>It is also the application's responsibility to ensure that there are no other
 * uses of the execution after calling {@link ANeuralNetworksExecution_free}.</p>
 *
 * <p>Multiple executions can be scheduled and evaluated concurrently, either by
 * means of {@link ANeuralNetworksExecution_compute} or
 * {@link ANeuralNetworksExecution_burstCompute} (which are synchronous) in
 * different threads, or by means of
 * {@link ANeuralNetworksExecution_startCompute} (which is asynchronous).
 * (Concurrent uses of {@link ANeuralNetworksExecution_burstCompute} must be on
 * different burst objects.) The runtime makes no guarantee on the ordering of
 * completion of executions. If it's important to the application, the
 * application should enforce the ordering by ensuring that one execution
 * completes before the next is scheduled (for example, by scheduling all
 * executions synchronously within a single thread, or by scheduling all
 * executions asynchronously and using {@link ANeuralNetworksEvent_wait} between
 * calls to {@link ANeuralNetworksExecution_startCompute}).</p>
 *
 * Available since API level 27.
 */
typedef struct ANeuralNetworksExecution ANeuralNetworksExecution;

#if __ANDROID_API__ >= __ANDROID_API_Q__
/**
 * Parameters for ANEURALNETWORKS_TENSOR_QUANT8_SYMM_PER_CHANNEL operand.
 */
typedef struct ANeuralNetworksSymmPerChannelQuantParams {
    /* The index of the channel dimension. */
    uint32_t channelDim;
    /** The size of the scale array. Should be equal to dimension[channelDim] of the Operand. */
    uint32_t scaleCount;
    /** The array of scaling values for each channel. Each value must be greater than zero. */
    const float* scales;
} ANeuralNetworksSymmPerChannelQuantParams;

/**
 * ANeuralNetworksBurst is an opaque type that can be used to reduce the latency
 * of a rapid sequence of executions. It will likely cause overhead if only used
 * for a single execution.
 *
 * ANeuralNetworksBurst serves as a context object for any number of inferences
 * using {@link ANeuralNetworksExecution} objects. An ANeuralNetworksBurst
 * object and the {@link ANeuralNetworksExecution} objects used with it must all
 * have been created from the same {@link ANeuralNetworksCompilation} object.
 *
 * This object is also used as a hint to drivers, providing insight to the
 * lifetime of a rapid sequence of executions. For example, a driver may choose
 * to increase the clock frequency of its accelerator for the lifetime of a
 * burst object.
 *
 * <p>To use:<ul>
 *    <li>Create a new burst object by calling the
 *        {@link ANeuralNetworksBurst_create} function.</li>
 *    <li>For each execution:</li><ul>
 *        <li>Create {@link ANeuralNetworksExecution} and configure its
 *            properties (see {@link ANeuralNetworksExecution} for details).</li>
 *        <li>Apply the model synchronously with
 *            {@link ANeuralNetworksExecution_burstCompute}, reusing the same
 *            {@link ANeuralNetworksBurst} with the new
 *            {@link ANeuralNetworksExecution}.</li>
 *        <li>Use and free the {@link ANeuralNetworksExecution}.</li></ul>
 *    <li>Destroy the burst with
 *        {@link ANeuralNetworksBurst_free}.</li></ul></p>
 *
 * Available since API level 29.
 */
typedef struct ANeuralNetworksBurst ANeuralNetworksBurst;
#endif  //  __ANDROID_API__ >= __ANDROID_API_Q__

/**
 * ANeuralNetworksOperandType describes the type of an operand.
 *
 * This structure is used to describe both scalars and tensors.
 *
 * A tensor operand type with all dimensions specified is "fully
 * specified".  Whenever possible (i.e., whenever the dimensions are
 * known at model construction time), a tensor operand type should be
 * (but is not required to be) fully specified, in order to enable the
 * best possible performance.
 *
 * If a tensor operand's type is not fully specified, the dimensions
 * of the operand are deduced from the operand types and values of the
 * operation for which that operand is an output.
 *
 * <p>In the following situations, a tensor operand type must be fully
 * specified:<ul>
 *     <li>The operand has a constant value, set by
 *         {@link ANeuralNetworksModel_setOperandValue} (with a
 *         non-nullptr buffer) or
 *         {@link ANeuralNetworksModel_setOperandValueFromMemory}.</li>
 *     <li>The operand is a model input (see
 *         {@link ANeuralNetworksModel_identifyInputsAndOutputs}).  A
 *         fully specified tensor operand type must either be provided
 *         to {@link ANeuralNetworksModel_addOperand}; or it must be
 *         provided to the corresponding
 *         {@link ANeuralNetworksExecution_setInput}, or
 *         {@link ANeuralNetworksExecution_setInputFromMemory}.
 *         EXCEPTION: If the input is optional and omitted
 *         (by passing nullptr for buffer to
 *         {@link ANeuralNetworksExecution_setInput}) then it need
 *         not have a fully specified tensor operand type.</li></ul>
 *
 * A tensor operand type of specified rank but some number of
 * unspecified dimensions is represented by setting dimensionCount to
 * the rank and each unspecified dimension to 0.
 *
 * Available since API level 27.
 *
 * Starting at API level 29, a tensor operand type of unspecified rank is
 * represented by setting dimensionCount to 0 and dimensions to NULL (just as if
 * it were a scalar operand type).
 */
typedef struct ANeuralNetworksOperandType {
    /**
     * The data type, e.g ANEURALNETWORKS_FLOAT32.
     */
    int32_t type;

    /**
     * The number of dimensions (rank).
     *
     * Must be 0 for scalars.
     */
    uint32_t dimensionCount;

    /**
     * The dimensions of the tensor.
     *
     * Must be nullptr for scalars.
     */
    const uint32_t* dimensions;

    /**
     * These two fields are only used for quantized tensors.
     * They must be zero for all other types.
     * The dequantized value of each entry is (value - zeroPoint) * scale.
     */
    float scale;
    int32_t zeroPoint;
} ANeuralNetworksOperandType;

typedef int32_t ANeuralNetworksOperationType;

/**
 * ANeuralNetworksEvent is an opaque type that represents an event
 * that will be signaled once an execution completes.
 *
 * Available since API level 27.
 */
typedef struct ANeuralNetworksEvent ANeuralNetworksEvent;

#if __ANDROID_API__ >= __ANDROID_API_Q__

/**
 * ANeuralNetworksDevice is an opaque type that represents a device.
 *
 * This type is used to query basic properties and supported operations of the corresponding
 * device, and control which device(s) a model is to be run on.
 *
 * Available since API level 29.
 */
typedef struct ANeuralNetworksDevice ANeuralNetworksDevice;

/**
 * Get the number of available devices.
 *
 * @param numDevices Used to return the number of devices.
 *
 * @return ANEURALNETWORKS_NO_ERROR if successful.
 *
 * Available since API level 29.
 */
int ANeuralNetworks_getDeviceCount(uint32_t* numDevices) __INTRODUCED_IN(29);

/**
 * Get the representation of the specified device.
 *
 * @param devIndex The index of the specified device. Must be less than the
                   number of available devices.
 * @param device The representation of the specified device.
 *               The same representation will always be returned for the specified
 *               device.
 *
 * @return ANEURALNETWORKS_NO_ERROR if successful.
 *
 * Available since API level 29.
 */
int ANeuralNetworks_getDevice(uint32_t devIndex, ANeuralNetworksDevice** device)
        __INTRODUCED_IN(29);

/**
 * Get the name of the specified device.
 *
 * @param device The representation of the specified device.
 * @param name   The returned name of the specified device. The name will be in UTF-8
 *               and will be null-terminated. It will be recognizable as a known device name
 *               rather than a cryptic string. For devices with feature level 29 and above, the
 *               format of the name is {VENDOR}-{DEVICE}. For devices with feature level 28
 *               or lower, the format of the name is undefined.
 *               The name will remain valid for the duration of the application.
 *
 * @return ANEURALNETWORKS_NO_ERROR if successful.
 *
 * Available since API level 29.
 */
int ANeuralNetworksDevice_getName(const ANeuralNetworksDevice* device, const char** name)
        __INTRODUCED_IN(29);

/**
 * Get the type of a given device.
 *
 * The device type can be used to help application developers to distribute Machine Learning
 * workloads and other workloads such as graphical rendering.
 * E.g., for an app which renders AR scenes based on real time object detection results,
 * the developer could choose an ACCELERATOR type device for ML workloads, and reserve GPU
 * for graphical rendering.
 *
 * @param device The representation of the specified device.
 * @param type The returned {@link DeviceTypeCode} of the specified device.
 *
 * @return ANEURALNETWORKS_NO_ERROR if successful.
 *
 * Available since API level 29.
 */
int ANeuralNetworksDevice_getType(const ANeuralNetworksDevice* device, int32_t* type)
        __INTRODUCED_IN(29);

/**
 * Get the version of the driver implementation of the specified device.
 *
 * It’s the responsibility of the driver implementor to insure that this version string
 * uniquely distinguishes this implementation from all previous implementations.
 *
 * This version string must not be confused with the feature level which is solely defined
 * by {@link ANeuralNetworksDevice_getFeatureLevel}. There is no implicit ordering of the versions.
 * For example, it is not possible to filter all drivers older than a certain version.
 *
 * Application developers may use this version string to avoid or prefer specific driver
 * implementations. For example, an application may want to do so because:
 *     - A specific version of the driver does not provide the required performance,
 *       perhaps because of a performance regression.
 *     - A specific version of the driver has a bug or returns results that don’t match
 *       the minimum precision requirement for the application.
 *
 * @param device The representation of the specified device.
 * @param version The returned version string of the driver for the specified device. The
 *                string will be in UTF-8 and will be null-terminated. For devices with feature
 *                level 28 or lower, "UNKNOWN" will be returned. The version string will remain
 *                valid for the duration of the application.
 *
 * @return ANEURALNETWORKS_NO_ERROR if successful.
 *
 * Available since API level 29.
 */
int ANeuralNetworksDevice_getVersion(const ANeuralNetworksDevice* device, const char** version)
        __INTRODUCED_IN(29);

/**
 * Get the supported NNAPI version of the specified device.
 *
 * Each device has a supported feature level, which is the most advanced feature this driver
 * implements. For example, if the driver implements the features introduced in Android P,
 * but does not implement the features introduced after Android P, the value would be 28.
 * Developers could decide whether or not the specified device should be used for a Model that
 * has certain feature requirements.
 *
 * @param device The representation of the specified device.
 * @param featureLevel The API level of the most advanced feature this driver implements.
 *
 * @return ANEURALNETWORKS_NO_ERROR if successful.
 *
 * Available since API level 29.
 */
int ANeuralNetworksDevice_getFeatureLevel(const ANeuralNetworksDevice* device,
                                          int64_t* featureLevel) __INTRODUCED_IN(29);

/**
 * Get the supported operations for a specified set of devices. If multiple devices
 * are selected, the supported operation list is a union of supported operations of all
 * selected devices.
 *
 * @param model The model to be queried.
 * @param devices The set of devices. Must not contain duplicates.
 * @param numDevices The number of devices in the set.
 * @param supportedOps The boolean array to be filled. True means supported. The size of the
 *                     boolean array must be at least as large as the number of operations
 *                     in the model. The order of elements in the supportedOps array matches
 *                     the order in which the corresponding operations were added to the model.
 *
 * @return ANEURALNETWORKS_NO_ERROR if successful.
 *
 * Available since API level 29.
 */
int ANeuralNetworksModel_getSupportedOperationsForDevices(
        const ANeuralNetworksModel* model, const ANeuralNetworksDevice* const* devices,
        uint32_t numDevices, bool* supportedOps) __INTRODUCED_IN(29);

/**
 * Create a {@link ANeuralNetworksCompilation} to compile the given model for a specified set
 * of devices. If more than one device is specified, the compilation will
 * distribute the workload automatically across the devices. The model must be fully
 * supported by the specified set of devices. This means that
 * ANeuralNetworksModel_getSupportedOperationsForDevices() must have returned true for every
 * operation for that model/devices pair.
 *
 * The user must handle all compilation and execution failures from the
 * specified set of devices. This is in contrast to a use of {@link
 * ANeuralNetworksCompilation_create}, where the runtime will attempt to recover
 * from such failures.
 *
 * @param model The {@link ANeuralNetworksModel} to be compiled.
 * @param devices The set of devices. Must not contain duplicates.
 * @param numDevices The number of devices in the set.
 * @param compilation The newly created object or NULL if unsuccessful.
 *
 * @return ANEURALNETWORKS_NO_ERROR if successful, ANEURALNETWORKS_BAD_DATA
 *         if the model is invalid.
 *
 * Available since API level 29.
 */
int ANeuralNetworksCompilation_createForDevices(ANeuralNetworksModel* model,
                                                const ANeuralNetworksDevice* const* devices,
                                                uint32_t numDevices,
                                                ANeuralNetworksCompilation** compilation)
        __INTRODUCED_IN(29);

/**
 * Sets the compilation caching signature and the cache directory.
 *
 * Provides optional caching information to the runtime for faster repeated
 * compilation.
 *
 * See {@link ANeuralNetworksCompilation} for information on multithreaded usage.
 *
 * @param compilation The compilation to be modified.
 * @param cacheDir The cache directory for the runtime to store and retrieve caching
 *                 data. It is recommended to use the code cache directory provided
 *                 by the Android runtime. If not using the code cache directory, the
 *                 user should choose a directory local to the application, and is
 *                 responsible for managing the cache entries.
 * @param token The token provided by the user to specify a model must be of length
 *              ANEURALNETWORKS_BYTE_SIZE_OF_CACHE_TOKEN. The user should ensure that
 *              the token is unique to a model within the application. The NNAPI
 *              runtime cannot detect token collisions; a collision will result in a
 *              failed execution or in a successful execution that produces incorrect
 *              output values.
 *
 * @return ANEURALNETWORKS_NO_ERROR if successful.
 *
 * Available since API level 29.
 */
int ANeuralNetworksCompilation_setCaching(ANeuralNetworksCompilation* compilation,
                                          const char* cacheDir, const uint8_t* token)
        __INTRODUCED_IN(29);

/**
 * Schedule synchronous evaluation of the execution.
 *
 * <p>Schedules synchronous evaluation of the execution. Returns once the
 * execution has completed and the outputs are ready to be consumed.
 * </p>
 *
 * See {@link ANeuralNetworksExecution} for information on multithreaded usage.
 *
 * See {@link ANeuralNetworksExecution_startCompute} for asynchronous execution.
 * Synchronous execution incurs lower overhead than asynchronous execution.
 *
 * Available since API level 29.
 *
 * @param execution The execution to be scheduled and executed.
 *
 * @return ANEURALNETWORKS_NO_ERROR if the execution completed normally.
 *         ANEURALNETWORKS_UNMAPPABLE if the execution input or output memory cannot
 *         be properly mapped.
 */
int ANeuralNetworksExecution_compute(ANeuralNetworksExecution* execution) __INTRODUCED_IN(29);

/**
 * Get the dimensional information of the specified output operand of the model of the
 * {@link ANeuralNetworksExecution}.
 *
 * On asynchronous execution initiated by {@link ANeuralNetworksExecution_startCompute},
 * {@link ANeuralNetworksEvent_wait} must be called prior to this function to recuperate
 * the resources used by the execution.
 *
 * @param execution The execution to be queried.
 * @param index The index of the output argument we are querying. It is
 *              an index into the lists passed to
 *              {@link ANeuralNetworksModel_identifyInputsAndOutputs}. It is not
 *              the index associated with {@link ANeuralNetworksModel_addOperand}.
 * @param rank The rank of the output operand.
 *
 * @return ANEURALNETWORKS_NO_ERROR if successful, ANEURALNETWORKS_OUTPUT_INSUFFICIENT_SIZE
 *         if the target output is provided an insufficient buffer at execution time,
 *         ANEURALNETWORKS_BAD_DATA if the index is invalid.
 *
 * Available since API level 29.
 */
int ANeuralNetworksExecution_getOutputOperandRank(ANeuralNetworksExecution* execution,
                                                  int32_t index, uint32_t* rank)
        __INTRODUCED_IN(29);

/**
 * Get the dimensional information of the specified output operand of the model of the
 * {@link ANeuralNetworksExecution}. The target output operand cannot be a scalar.
 *
 * On asynchronous execution initiated by {@link ANeuralNetworksExecution_startCompute},
 * {@link ANeuralNetworksEvent_wait} must be called prior to this function to recuperate
 * the resources used by the execution.
 *
 * @param execution The execution to be queried.
 * @param index The index of the output argument we are querying. It is an index into the lists
 *              passed to {@link ANeuralNetworksModel_identifyInputsAndOutputs}. It is not
 *              the index associated with {@link ANeuralNetworksModel_addOperand}.
 * @param dimensions The dimension array to be filled. The size of the array must be exactly as
 *                   large as the rank of the output operand to be queried in the model.
 *
 * @return ANEURALNETWORKS_NO_ERROR if successful, ANEURALNETWORKS_OUTPUT_INSUFFICIENT_SIZE
 *         if the target output is provided an insufficient buffer at execution time,
 *         ANEURALNETWORKS_BAD_DATA if the index is invalid or if the target is a scalar.
 *
 * Available since API level 29.
 */
int ANeuralNetworksExecution_getOutputOperandDimensions(ANeuralNetworksExecution* execution,
                                                        int32_t index, uint32_t* dimensions)
        __INTRODUCED_IN(29);

/**
 * Create a {@link ANeuralNetworksBurst} to apply the given compilation.
 * This only creates the burst object. Computation is only performed once
 * {@link ANeuralNetworksExecution_burstCompute} is invoked with a valid
 * {@link ANeuralNetworksExecution} and {@link ANeuralNetworksBurst}.
 *
 * <p>The provided compilation must outlive the burst object.</p>
 *
 * Available since API level 29.
 *
 * @param compilation The {@link ANeuralNetworksCompilation} to be evaluated.
 * @param burst The newly created object or NULL if unsuccessful.
 *
 * @return ANEURALNETWORKS_NO_ERROR if successful, ANEURALNETWORKS_BAD_DATA
 *         if the compilation is invalid.
 */
int ANeuralNetworksBurst_create(ANeuralNetworksCompilation* compilation,
                                ANeuralNetworksBurst** burst) __INTRODUCED_IN(29);

/**
 * Destroys the burst object.
 *
 * Available since API level 29.
 *
 * @param burst The burst object to be destroyed. Passing NULL is acceptable and
 *              results in no operation.
 */
void ANeuralNetworksBurst_free(ANeuralNetworksBurst* burst) __INTRODUCED_IN(29);

/**
 * Schedule synchronous evaluation of the execution on a burst object.
 *
 * <p>Schedules synchronous evaluation of the execution. Returns once the
 * execution has completed and the outputs are ready to be consumed.</p>
 *
 * <p>There must be at most one {@link ANeuralNetworksExecution} processing at
 * any given time for any given burst object. Any
 * {@link ANeuralNetworksExecution} launched before the previous has finished
 * will result in ANEURALNETWORKS_BAD_STATE.</p>
 *
 * Available since API level 29.
 *
 * @param burst The burst object to execute on.
 * @param execution The execution to be scheduled and executed. The execution
 *                  must be created from the same {@link
 *                  ANeuralNetworksCompilation} as the burst object.
 *
 * @return ANEURALNETWORKS_NO_ERROR if the execution completed normally.
 */
int ANeuralNetworksExecution_burstCompute(ANeuralNetworksExecution* execution,
                                          ANeuralNetworksBurst* burst) __INTRODUCED_IN(29);

/**
 * Creates a shared memory object from an AHardwareBuffer handle.
 *
 * If the shared memory is backed by an AHardwareBuffer of AHARDWAREBUFFER_FORMAT_BLOB
 * format, it can be used the same way as shared memory created from a file handle. See
 * {@link ANeuralNetworksMemory} for a description on how to use this shared memory.
 *
 * If the shared memory is backed by an AHardwareBuffer of a format other than
 * AHARDWAREBUFFER_FORMAT_BLOB, it can only be used for Model inputs and outputs.
 * When calling {@link ANeuralNetworksExecution_setInputFromMemory} or
 * {@link ANeuralNetworksExecution_setOutputFromMemory} with the shared memory, both
 * offset and length must be set to zero and the entire memory region will be
 * associated with the specified input or output operand. There is no guarantee
 * that an arbitrary AHardwareBuffer_Format and AHardwareBuffer_UsageFlags combination
 * can be used by arbitrary devices. The execution will fail if the selected set of
 * devices cannot consume the buffer.
 *
 * Calling {@link ANeuralNetworksModel_setOperandValueFromMemory} with shared memory
 * backed by an AHardwareBuffer of a format other than AHARDWAREBUFFER_FORMAT_BLOB is
 * disallowed.
 *
 * The provided AHardwareBuffer must outlive the ANeuralNetworksMemory object.
 *
 * Available since API level 29.
 *
 * @param ahwb The AHardwareBuffer handle.
 * @param memory The memory object to be created.
 *               Set to NULL if unsuccessful.
 *
 * @return ANEURALNETWORKS_NO_ERROR if the request completed normally.
 *
 * @see AHardwareBuffer
 */
int ANeuralNetworksMemory_createFromAHardwareBuffer(const AHardwareBuffer* ahwb,
                                                    ANeuralNetworksMemory** memory)
        __INTRODUCED_IN(29);

/**

 * Specifies whether duration of the {@link ANeuralNetworksExecution} is to be
 * measured. Evaluation of the execution must not have been scheduled.
 *
 * By default, duration is not measured.
 *
 * The {@link ANeuralNetworksExecution} must have been created with
 * {@link ANeuralNetworksCompilation_createForDevices} with numDevices = 1.
 *
 * See {@link ANeuralNetworksExecution} for information on multithreaded usage.
 *
 * Available since API level 29.
 *
 * @param execution The execution to be modified.
 * @param measure 'true' if duration is to be measured, 'false' if not.
 *
 * @return ANEURALNETWORKS_NO_ERROR if successful.
 */
int ANeuralNetworksExecution_setMeasureTiming(ANeuralNetworksExecution* execution, bool measure)
        __INTRODUCED_IN(29);

/**
 * Different duration measurements.
 *
 * Durations are measured in nanoseconds.
 *
 * Available since API level 29.
 */
typedef enum {
    // Execution time on hardware (not driver, which runs on host processor).
    ANEURALNETWORKS_DURATION_ON_HARDWARE = 0,
    // Execution time in driver (including time on hardware).  Excludes overhead
    // such as that of the runtime itself and the IPC needed for the runtime to
    // communicate with the driver.
    ANEURALNETWORKS_DURATION_IN_DRIVER = 1,
} DurationCode;

/**
 * Get the time spent in the specified {@link ANeuralNetworksExecution}, in nanoseconds.
 * The execution must have completed.
 *
 * Available since API level 29.
 *
 * @param execution The execution to be queried.
 * @param durationCode The measurement to be queried, specified by {@link DurationCode}.
 * @param duration The returned duration. If no measurement was requested by
 *                 {@link ANeuralNetworksExecution_setMeasureTiming}, or for some other
 *                 reason the duration is not available, UINT64_MAX will be returned.
 *                 A particular device need not support any given measurement.
 *
 * @return ANEURALNETWORKS_NO_ERROR if successful.
 */
int ANeuralNetworksExecution_getDuration(const ANeuralNetworksExecution* execution,
                                         int32_t durationCode, uint64_t* duration)
        __INTRODUCED_IN(29);

#endif  // __ANDROID_API__ >= __ANDROID_API_Q__

#if __ANDROID_API__ >= 27

/**
 * Creates a shared memory object from a file descriptor.
 *
 * The shared memory is backed by a file descriptor via mmap.
 * See {@link ANeuralNetworksMemory} for a description on how to use
 * this shared memory.
 *
 * Available since API level 27.
 *
 * @param size The requested size in bytes.
 *             Must not be larger than the file size.
 * @param prot The desired memory protection for the mapping.
 *             It is either PROT_NONE or the bitwise OR of one or
 *             more of the following flags: PROT_READ, PROT_WRITE.
 * @param fd The requested file descriptor.
 *           The file descriptor has to be mmap-able. The file
 *           descriptor will be duplicated.
 * @param offset The offset to the beginning of the file of the area to map.
 *               The offset has to be aligned to a page size.
 * @param memory The memory object to be created.
 *               Set to NULL if unsuccessful.
 *
 * @return ANEURALNETWORKS_NO_ERROR if the request completed normally.
 */
int ANeuralNetworksMemory_createFromFd(size_t size, int protect, int fd, size_t offset,
                                       ANeuralNetworksMemory** memory) __INTRODUCED_IN(27);

/**
 * Delete a memory object.
 *
 * Destroys the object used by the run time to keep track of the memory.
 * This will free the underlying actual memory if no other code has open
 * handles to this memory.
 *
 * Available since API level 27.
 *
 * @param memory The memory object to be freed. Passing NULL is acceptable and
 *               results in no operation.
 */
void ANeuralNetworksMemory_free(ANeuralNetworksMemory* memory) __INTRODUCED_IN(27);

/**
 * Create an empty {@link ANeuralNetworksModel}.
 *
 * <p>This only creates the object. Computation is performed once
 * {@link ANeuralNetworksExecution_compute} or
 * {@link ANeuralNetworksExecution_startCompute} is invoked.
 *
 * The model should be constructed with calls to
 * {@link ANeuralNetworksModel_addOperation} and
 * {@link ANeuralNetworksModel_addOperand}
 *
 * <p>{@link ANeuralNetworksModel_finish} should be called once the model
 * has been fully constructed.</p>
 *
 * <p>{@link ANeuralNetworksModel_free} should be called once the model
 * is no longer needed.</p>
 *
 * Available since API level 27.
 *
 * @param model The {@link ANeuralNetworksModel} to be created.
 *              Set to NULL if unsuccessful.
 *
 * @return ANEURALNETWORKS_NO_ERROR if successful.
 */
int ANeuralNetworksModel_create(ANeuralNetworksModel** model) __INTRODUCED_IN(27);

/**
 * Destroy a model.
 *
 * The model need not have been finished by a call to
 * {@link ANeuralNetworksModel_finish}.
 *
 * See {@link ANeuralNetworksModel} for information on multithreaded usage.
 *
 * Available since API level 27.
 *
 * @param model The model to be destroyed. Passing NULL is acceptable and
 *              results in no operation.
 */
void ANeuralNetworksModel_free(ANeuralNetworksModel* model) __INTRODUCED_IN(27);

/**
 * Indicate that we have finished modifying a model. Required before
 * calling {@link ANeuralNetworksCompilation_create} and
 * {@link ANeuralNetworksCompilation_createForDevices}.
 *
 * An application must ensure that no other thread uses the model at the same
 * time.
 *
 * This function must only be called once for a given model.
 *
 * See {@link ANeuralNetworksModel} for information on multithreaded usage.
 *
 * Available since API level 27.
 *
 * @param model The model to be finished.
 *
 * @return ANEURALNETWORKS_NO_ERROR if successful.
 */
int ANeuralNetworksModel_finish(ANeuralNetworksModel* model) __INTRODUCED_IN(27);

/**
 * Add an operand to a model.
 *
 * The order in which the operands are added is important. The first one added
 * to a model will have the index value 0, the second 1, etc. These indexes are
 * used as operand identifiers in
 * {@link ANeuralNetworksModel_addOperation},
 * {@link ANeuralNetworksModel_identifyInputsAndOutputs},
 * {@link ANeuralNetworksModel_setOperandValue},
 * {@link ANeuralNetworksModel_setOperandValueFromMemory},
 * {@link ANeuralNetworksExecution_setInput},
 * {@link ANeuralNetworksExecution_setInputFromMemory},
 * {@link ANeuralNetworksExecution_setOutput},
 * {@link ANeuralNetworksExecution_setOutputFromMemory} and
 * {@link ANeuralNetworksExecution_setOperandValue}.
 *
 * <p>Every operand must be referenced in exactly one of the following
 * ways:<ul>
 *    <li>It is identified as a model input with
 *        {@link ANeuralNetworksModel_identifyInputsAndOutputs}.</li>
 *    <li>It is identified as a constant with
 *        {@link ANeuralNetworksModel_setOperandValue} or
 *        {@link ANeuralNetworksModel_setOperandValueFromMemory}.</li>
 *    <li>It is identified as an output of exactly one operation with
 *        {@link ANeuralNetworksModel_addOperation}.</li></p>
 * <p>An operand that is identified as a model input or as a constant
 * must not also be identified as a model output with
 * {@link ANeuralNetworksModel_identifyInputsAndOutputs}.</p>
 *
 * To build a model that can accommodate inputs of various sizes, as
 * you may want to do for a CNN, leave unspecified the dimensions that
 * will vary at run time.  If you do so, fully specify dimensions
 * when calling {@link ANeuralNetworksExecution_setInput} or
 * {@link ANeuralNetworksExecution_setInputFromMemory}.
 *
 * Attempting to modify a model once {@link ANeuralNetworksModel_finish} has been
 * called will return an error.
 *
 * See {@link ANeuralNetworksModel} for information on multithreaded usage.
 *
 * Available since API level 27.
 *
 * @param model The model to be modified.
 * @param type The {@link ANeuralNetworksOperandType} that describes the shape
 *             of the operand.  Neither the {@link ANeuralNetworksOperandType}
 *             nor the dimensions it points to need to outlive the call to
 *             {@link ANeuralNetworksModel_addOperand}.
 *
 * @return ANEURALNETWORKS_NO_ERROR if successful.
 */
int ANeuralNetworksModel_addOperand(ANeuralNetworksModel* model,
                                    const ANeuralNetworksOperandType* type) __INTRODUCED_IN(27);

/**
 * Sets an operand to a constant value.
 *
 * Values of length smaller or equal to
 * {@link ANEURALNETWORKS_MAX_SIZE_OF_IMMEDIATELY_COPIED_VALUES}
 * are immediately copied into the model.
 *
 * For values of length greater than
 * {@link ANEURALNETWORKS_MAX_SIZE_OF_IMMEDIATELY_COPIED_VALUES}, a pointer to
 * the buffer is stored within the model. The application must not change the
 * content of this region until all executions using this model have
 * completed. As the data may be copied during processing, modifying the data
 * after this call yields undefined results. The provided buffer must outlive
 * this model.
 *
 * For large tensors, using {@link ANeuralNetworksModel_setOperandValueFromMemory}
 * is likely to be more efficient.
 *
 * To indicate that an optional operand should be considered missing,
 * pass nullptr for buffer and 0 for length.
 *
 * Attempting to modify a model once {@link ANeuralNetworksModel_finish} has been
 * called will return an error.
 *
 * See {@link ANeuralNetworksModel} for information on multithreaded usage.
 *
 * Available since API level 27.
 *
 * @param model The model to be modified.
 * @param index The index of the model operand we're setting.
 * @param buffer A pointer to the data to use.
 * @param length The size in bytes of the data value.
 *
 * @return ANEURALNETWORKS_NO_ERROR if successful.
 */
int ANeuralNetworksModel_setOperandValue(ANeuralNetworksModel* model, int32_t index,
                                         const void* buffer, size_t length) __INTRODUCED_IN(27);

#if __ANDROID_API__ >= __ANDROID_API_Q__

/**
 * Sets an operand's per channel quantization parameters.
 *
 * Sets parameters required by a tensor of type
 * {@link ANEURALNETWORKS_TENSOR_QUANT8_SYMM_PER_CHANNEL}.
 * This function must be called for every tensor of type
 * {@link ANEURALNETWORKS_TENSOR_QUANT8_SYMM_PER_CHANNEL} before
 * calling {@link ANeuralNetworksModel_finish}.
 *
 * Available since API level 29.
 *
 * @param model The model to be modified.
 * @param index The index of the model operand we're setting.
 * @param channelQuant The per channel quantization parameters for the operand.
 *                    No memory in this struct needs to outlive the call to
 *                    this function.
 *
 * @return ANEURALNETWORKS_NO_ERROR if successful.
 */
int ANeuralNetworksModel_setOperandSymmPerChannelQuantParams(
        ANeuralNetworksModel* model, int32_t index,
        const ANeuralNetworksSymmPerChannelQuantParams* channelQuant) __INTRODUCED_IN(29);

#endif  // __ANDROID_API__ >= __ANDROID_API_Q__

/**
 * Sets an operand to a value stored in a memory object.
 *
 * The content of the memory is not copied. A reference to that memory is stored
 * inside the model. The application must not change the content of the memory
 * region until all executions using this model have completed.  As the data may
 * be copied during processing, modifying the data after this call yields
 * undefined results.
 *
 * <p>The provided memory must outlive this model.</p>
 *
 * To indicate that an optional operand should be considered missing,
 * use {@link ANeuralNetworksModel_setOperandValue} instead, passing nullptr for buffer.
 *
 * Is disallowed to set an operand value with shared memory backed by an AHardwareBuffer
 * of a format other than AHARDWAREBUFFER_FORMAT_BLOB.
 *
 * Attempting to modify a model once {@link ANeuralNetworksModel_finish} has been
 * called will return an error.
 *
 * See {@link ANeuralNetworksModel} for information on multithreaded usage.
 * See {@link ANeuralNetworksMemory_createFromAHardwareBuffer} for information on
 * AHardwareBuffer usage.
 *
 * Available since API level 27.
 *
 * @param model The model to be modified.
 * @param index The index of the model operand we're setting.
 * @param buffer A pointer to the data to use.
 * @param memory The memory containing the data.
 * @param offset This specifies the location of the data within the memory.
 *               The offset is in bytes from the start of memory.
 * @param length The size in bytes of the data value.
 *
 * @return ANEURALNETWORKS_NO_ERROR if successful.
 */
int ANeuralNetworksModel_setOperandValueFromMemory(ANeuralNetworksModel* model, int32_t index,
                                                   const ANeuralNetworksMemory* memory,
                                                   size_t offset, size_t length)
        __INTRODUCED_IN(27);

/**
 * Add an operation to a model.
 *
 * @param model The model to be modified.
 * @param type The {@link ANeuralNetworksOperationType} of the operation.
 * @param inputCount The number of entries in the inputs array.
 * @param inputs An array of indexes identifying each operand.
 * @param outputCount The number of entries in the outputs array.
 * @param outputs An array of indexes identifying each operand.
 *
 * The operands specified by inputs and outputs must have been
 * previously added by calls to {@link ANeuralNetworksModel_addOperand}.
 *
 * Attempting to modify a model once {@link ANeuralNetworksModel_finish} has been
 * called will return an error.
 *
 * See {@link ANeuralNetworksModel} for information on multithreaded usage.
 *
 * Available since API level 27.
 *
 * @return ANEURALNETWORKS_NO_ERROR if successful.
 */
int ANeuralNetworksModel_addOperation(ANeuralNetworksModel* model,
                                      ANeuralNetworksOperationType type, uint32_t inputCount,
                                      const uint32_t* inputs, uint32_t outputCount,
                                      const uint32_t* outputs) __INTRODUCED_IN(27);

/**
 * Specifies which operands will be the model's inputs and
 * outputs. Every model must have at least one input and one output.
 *
 * An operand cannot be used for both input and output. Doing so will
 * return an error.
 *
 * @param model The model to be modified.
 * @param inputCount The number of entries in the inputs array.
 * @param inputs An array of indexes identifying the input operands.
 * @param outputCount The number of entries in the outputs array.
 * @param outputs An array of indexes identifying the output operands.
 *
 * The operands specified by inputs and outputs must have been
 * previously added by calls to {@link ANeuralNetworksModel_addOperand}.
 *
 * Attempting to modify a model once {@link ANeuralNetworksModel_finish} has been
 * called will return an error.
 *
 * See {@link ANeuralNetworksModel} for information on multithreaded usage.
 *
 * Available since API level 27.
 *
 */
int ANeuralNetworksModel_identifyInputsAndOutputs(ANeuralNetworksModel* model, uint32_t inputCount,
                                                  const uint32_t* inputs, uint32_t outputCount,
                                                  const uint32_t* outputs) __INTRODUCED_IN(27);

#if __ANDROID_API__ >= 28

/**
 * Specifies whether {@link ANEURALNETWORKS_TENSOR_FLOAT32} is allowed to be
 * calculated with range and/or precision as low as that of the IEEE 754 16-bit
 * floating-point format. By default, {@link ANEURALNETWORKS_TENSOR_FLOAT32}
 * must be calculated using at least the range and precision of the IEEE 754
 * 32-bit floating-point format.
 *
 * @param model The model to be modified.
 * @param allow 'true' indicates {@link ANEURALNETWORKS_TENSOR_FLOAT32} may be
 *              calculated with range and/or precision as low as that of the
 *              IEEE 754 16-bit floating point format. 'false' indicates
 *              {@link ANEURALNETWORKS_TENSOR_FLOAT32} must be calculated using
 *              at least the range and precision of the IEEE 754 32-bit floating
 *              point format.
 *
 * Attempting to modify a model once {@link ANeuralNetworksModel_finish} has been
 * called will return an error.
 *
 * Available since API level 28.
 *
 * See {@link ANeuralNetworksModel} for information on multithreaded usage.
 */
int ANeuralNetworksModel_relaxComputationFloat32toFloat16(ANeuralNetworksModel* model, bool allow)
        __INTRODUCED_IN(28);

#endif  // __ANDROID_API__ >= 28

/**
 * Create a {@link ANeuralNetworksCompilation} to compile the given model.
 *
 * <p>This only creates the object. Compilation is only performed once
 * {@link ANeuralNetworksCompilation_finish} is invoked.</p>
 *
 * <p>{@link ANeuralNetworksCompilation_finish} should be called once
 * all desired properties have been set on the compilation.</p>
 *
 * <p>{@link ANeuralNetworksModel_free} should be called once the compilation
 * is no longer needed.</p>
 *
 * <p>The provided model must outlive the compilation.</p>
 *
 * The model must already have been finished by a call to
 * {@link ANeuralNetworksModel_finish}.
 *
 * See {@link ANeuralNetworksCompilation} for information on multithreaded usage.
 *
 * Available since API level 27.
 *
 * @param model The {@link ANeuralNetworksModel} to be compiled.
 * @param compilation The newly created object or NULL if unsuccessful.
 *
 * @return ANEURALNETWORKS_NO_ERROR if successful, ANEURALNETWORKS_BAD_DATA
 *         if the model is invalid.
 */
int ANeuralNetworksCompilation_create(ANeuralNetworksModel* model,
                                      ANeuralNetworksCompilation** compilation) __INTRODUCED_IN(27);

/**
 * Destroy a compilation.
 *
 * The compilation need not have been finished by a call to
 * {@link ANeuralNetworksCompilation_finish}.
 *
 * See {@link ANeuralNetworksCompilation} for information on multithreaded usage.
 *
 * Available since API level 27.
 *
 * @param compilation The compilation to be destroyed. Passing NULL is acceptable and
 *                    results in no operation.
 */
void ANeuralNetworksCompilation_free(ANeuralNetworksCompilation* compilation) __INTRODUCED_IN(27);

/**
 * Sets the execution preference.
 *
 * <p>Provides guidance to the runtime when trade-offs are possible. By default the runtime
 * uses PREFER_SINGLE_FAST_ANSWER</p>
 *
 * See {@link ANeuralNetworksCompilation} for information on multithreaded usage.
 *
 * Available since API level 27.
 *
 * @param compilation The compilation to be modified.
 * @param preference Either {@link PREFER_LOW_POWER},
 *                  {@link PREFER_SINGLE_FAST_ANSWER}, or
 *                  {@link PREFER_SUSTAINED_SPEED}.
 *
 * @return ANEURALNETWORKS_NO_ERROR if successful.
 */
int ANeuralNetworksCompilation_setPreference(ANeuralNetworksCompilation* compilation,
                                             int32_t preference) __INTRODUCED_IN(27);

/**
 * Indicate that we have finished modifying a compilation. Required before
 * calling {@link ANeuralNetworksExecution_create}.
 *
 * An application must ensure that no other thread uses the compilation at the
 * same time.
 *
 * This function must only be called once for a given compilation.
 *
 * See {@link ANeuralNetworksCompilation} for information on multithreaded usage.
 *
 * Available since API level 27.
 *
 * @param compilation The compilation to be finished.
 *
 * @return ANEURALNETWORKS_NO_ERROR if successful.
 */
int ANeuralNetworksCompilation_finish(ANeuralNetworksCompilation* compilation) __INTRODUCED_IN(27);

/**
 * Create a {@link ANeuralNetworksExecution} to apply the given compilation.
 * This only creates the object. Computation is only performed once
 * {@link ANeuralNetworksExecution_compute} or
 * {@link ANeuralNetworksExecution_startCompute} is invoked.
 *
 * <p>The provided compilation must outlive the execution.</p>
 *
 * See {@link ANeuralNetworksExecution} for information on multithreaded usage.
 *
 * Available since API level 27.
 *
 * @param compilation The {@link ANeuralNetworksCompilation} to be evaluated.
 * @param execution The newly created object or NULL if unsuccessful.
 *
 * @return ANEURALNETWORKS_NO_ERROR if successful, ANEURALNETWORKS_BAD_DATA
 *         if the compilation is invalid.
 */
int ANeuralNetworksExecution_create(ANeuralNetworksCompilation* compilation,
                                    ANeuralNetworksExecution** execution) __INTRODUCED_IN(27);

/**
 * Destroy an execution.
 *
 * <p>The execution need not have been scheduled by a call to
 * {@link ANeuralNetworksExecution_burstCompute},
 * {@link ANeuralNetworksExecution_compute}, or
 * {@link ANeuralNetworksExecution_startCompute}; but if it has been scheduled,
 * then the application must not call {@link ANeuralNetworksExecution_free}
 * until the execution has completed (i.e.,
 * {@link ANeuralNetworksExecution_burstCompute},
 * {@link ANeuralNetworksExecution_compute}, or
 * {@link ANeuralNetworksEvent_wait} has returned).
 *
 * See {@link ANeuralNetworksExecution} for information on multithreaded usage.
 *
 * Available since API level 27.
 *
 * @param execution The execution to be destroyed. Passing NULL is acceptable and
 *                  results in no operation.
 */
void ANeuralNetworksExecution_free(ANeuralNetworksExecution* execution) __INTRODUCED_IN(27);

/**
 * Associate a user buffer with an input of the model of the
 * {@link ANeuralNetworksExecution}. Evaluation of the execution must not have
 * been scheduled. Once evaluation of the execution has been scheduled, the
 * application must not change the content of the buffer until the execution has
 * completed. Evaluation of the execution will not change the content of the
 * buffer.
 *
 * <p>The provided buffer must outlive the execution.</p>
 *
 * If the input is optional, you can indicate that it is omitted by
 * passing nullptr for buffer and 0 for length.
 *
 * See {@link ANeuralNetworksExecution} for information on multithreaded usage.
 *
 * Available since API level 27.
 *
 * @param execution The execution to be modified.
 * @param index The index of the input argument we are setting. It is
 *              an index into the lists passed to
 *              {@link ANeuralNetworksModel_identifyInputsAndOutputs}. It is not
 *              the index associated with
 *              {@link ANeuralNetworksModel_addOperand}.
 * @param type The {@link ANeuralNetworksOperandType} of the
 *             operand. Unless the input is omitted, this should be
 *             used to specify the dimensions that were left
 *             unspecified when the operand was added to the
 *             model. All other properties of the type must be the
 *             same as specified in the model. If the type is the same
 *             as specified when the model was built, NULL can be
 *             passed. Neither the {@link ANeuralNetworksOperandType}
 *             nor the dimensions it points to need to outlive the call
 *             to {@link ANeuralNetworksExecution_setInput}.
 * @param buffer The buffer containing the data.
 * @param length The length in bytes of the buffer.
 *
 * @return ANEURALNETWORKS_NO_ERROR if successful, ANEURALNETWORKS_BAD_DATA if the
 *         name is not recognized or the buffer is too small for the input.
 */
int ANeuralNetworksExecution_setInput(ANeuralNetworksExecution* execution, int32_t index,
                                      const ANeuralNetworksOperandType* type, const void* buffer,
                                      size_t length) __INTRODUCED_IN(27);

/**
 * Associate a region of a memory object with an input of the model of the
 * {@link ANeuralNetworksExecution}. Evaluation of the execution must not have
 * been scheduled. Once evaluation of the execution has been scheduled, the
 * application must not change the content of the region until the execution has
 * completed. Evaluation of the execution will not change the content of the
 * region.
 *
 * <p>The provided memory must outlive the execution.</p>
 *
 * If the input is optional, you can indicate that it is omitted by
 * using {@link ANeuralNetworksExecution_setInput} instead, passing nullptr for
 * buffer and 0 for length.
 *
 * See {@link ANeuralNetworksExecution} for information on multithreaded usage.
 * See {@link ANeuralNetworksMemory_createFromAHardwareBuffer} for information on
 * AHardwareBuffer usage.
 *
 * Available since API level 27.
 *
 * @param execution The execution to be modified.
 * @param index The index of the input argument we are setting. It is
 *              an index into the lists passed to
 *              {@link ANeuralNetworksModel_identifyInputsAndOutputs}. It is not
 *              the index associated with {@link ANeuralNetworksModel_addOperand}.
 * @param type The {@link ANeuralNetworksOperandType} of the
 *             operand. This should be used to specify the dimensions
 *             that were left unspecified when the operand was added
 *             to the model. All other properties of the type must be
 *             the same as specified in the model. If the type is the
 *             same as specified when the model was built, NULL can be
 *             passed. Neither the {@link ANeuralNetworksOperandType}
 *             nor the dimensions it points to need to outlive the call
 *             to {@link ANeuralNetworksExecution_setInputFromMemory}.
 * @param memory The memory containing the data.
 * @param offset This specifies the location of the data within the memory.
 *               The offset is in bytes from the start of memory.
 * @param length The size in bytes of the data value.
 *
 * @return ANEURALNETWORKS_NO_ERROR if successful, ANEURALNETWORKS_BAD_DATA if the
 *         name is not recognized or the buffer is too small for the input.
 */
int ANeuralNetworksExecution_setInputFromMemory(ANeuralNetworksExecution* execution, int32_t index,
                                                const ANeuralNetworksOperandType* type,
                                                const ANeuralNetworksMemory* memory, size_t offset,
                                                size_t length) __INTRODUCED_IN(27);

/**
 * Associate a user buffer with an output of the model of the
 * {@link ANeuralNetworksExecution}. Evaluation of the execution must not have
 * been scheduled. Once evaluation of the execution has been scheduled, the
 * application must not change the content of the buffer until the execution has
 * completed.
 *
 * If the output is optional, you can indicate that it is omitted by
 * passing nullptr for buffer and 0 for length.
 *
 * <p>The provided buffer must outlive the execution.</p>
 *
 * See {@link ANeuralNetworksExecution} for information on multithreaded usage.
 *
 * Available since API level 27.
 *
 * @param execution The execution to be modified.
 * @param index The index of the output argument we are setting. It is
 *              an index into the lists passed to
 *              {@link ANeuralNetworksModel_identifyInputsAndOutputs}. It is not
 *              the index associated with {@link ANeuralNetworksModel_addOperand}.
 * @param type The {@link ANeuralNetworksOperandType} of the
 *             operand. Unless the output is omitted, this should be
 *             used to specify the dimensions that were left
 *             unspecified when the operand was added to the
 *             model. All other properties of the type must be the
 *             same as specified in the model. If the type is the same
 *             as specified when the model was built, NULL can be
 *             passed. Neither the {@link ANeuralNetworksOperandType}
 *             nor the dimensions it points to need to outlive the call
 *             to {@link ANeuralNetworksExecution_setOutput}.
 *             Since API level 29, the output operand can have unspecified
 *             dimensions or rank to be deduced dynamically during the execution.
 *             However, the user must provide a large enough buffer. The user
 *             can retrieve the output dimensional information after the execution
 *             by {@link ANeuralNetworksExecution_getOutputOperandRank} and
 *             {@link ANeuralNetworksExecution_getOutputOperandDimensions}.
 * @param buffer The buffer where the data is to be written.
 * @param length The length in bytes of the buffer.
 *
 * @return ANEURALNETWORKS_NO_ERROR if successful, ANEURALNETWORKS_BAD_DATA if the
 *         name is not recognized or the buffer is too small for the output.
 */
int ANeuralNetworksExecution_setOutput(ANeuralNetworksExecution* execution, int32_t index,
                                       const ANeuralNetworksOperandType* type, void* buffer,
                                       size_t length) __INTRODUCED_IN(27);

/**
 * Associate a region of a memory object with an output of the model of the
 * {@link ANeuralNetworksExecution}. Evaluation of the execution must not have
 * been scheduled. Once evaluation of the execution has been scheduled, the
 * application must not change the content of the region until the execution has
 * completed.
 *
 * If the output is optional, you can indicate that it is omitted by
 * using {@link ANeuralNetworksExecution_setOutput} instead, passing nullptr for
 * buffer and 0 for length.
 *
 * <p>The provided memory must outlive the execution.</p>
 *
 * See {@link ANeuralNetworksExecution} for information on multithreaded usage.
 * See {@link ANeuralNetworksMemory_createFromAHardwareBuffer} for information on
 * AHardwareBuffer usage.
 *
 * Available since API level 27.
 *
 * @param execution The execution to be modified.
 * @param index The index of the output argument we are setting. It is
 *              an index into the lists passed to
 *              {@link ANeuralNetworksModel_identifyInputsAndOutputs}. It is not
 *              the index associated with {@link ANeuralNetworksModel_addOperand}.
 * @param type The {@link ANeuralNetworksOperandType} of the operand. This should be
 *             used to specify the dimensions that were left
 *             unspecified when the operand was added to the
 *             model. All other properties of the type must be the
 *             same as specified in the model. If the type is the same
 *             as specified when the model was built, NULL can be
 *             passed. Neither the {@link ANeuralNetworksOperandType}
 *             nor the dimensions it points to need to outlive the call
 *             to {@link ANeuralNetworksExecution_setOutputFromMemory}.
 *             Since API level 29, the output operand can have unspecified
 *             dimensions or rank to be deduced dynamically during the execution.
 *             However, the user must provide a large enough memory. The user
 *             can retrieve the output dimensional information after the execution
 *             by {@link ANeuralNetworksExecution_getOutputOperandRank} and
 *             {@link ANeuralNetworksExecution_getOutputOperandDimensions}.
 * @param memory The memory where the data is to be stored.
 * @param offset This specifies the location of the data within the memory.
 *               The offset is in bytes from the start of memory.
 * @param length The length in bytes of the data value.
 *
 * @return ANEURALNETWORKS_NO_ERROR if successful, ANEURALNETWORKS_BAD_DATA if the
 *         name is not recognized or the buffer is too small for the output.
 */
int ANeuralNetworksExecution_setOutputFromMemory(ANeuralNetworksExecution* execution, int32_t index,
                                                 const ANeuralNetworksOperandType* type,
                                                 const ANeuralNetworksMemory* memory, size_t offset,
                                                 size_t length) __INTRODUCED_IN(27);

/**
 * Schedule asynchronous evaluation of the execution.
 *
 * <p>Schedules asynchronous evaluation of the execution. Once the model has
 * been applied and the outputs are ready to be consumed, the returned event
 * will be signaled. Use {@link ANeuralNetworksEvent_wait} to wait for that
 * event.
 * </p>
 *
 * ANeuralNetworksEvent_wait must be called to recuperate the resources used
 * by the execution.
 *
 * See {@link ANeuralNetworksExecution} for information on multithreaded usage.
 *
 * See {@link ANeuralNetworksExecution_compute} for synchronous execution.
 * Synchronous execution incurs lower overhead than asynchronous execution.
 *
 * Available since API level 27.
 *
 * @param execution The execution to be scheduled and executed.
 * @param event The event that will be signaled on completion. event is set to
 *              NULL if there's an error.
 *
 * @return ANEURALNETWORKS_NO_ERROR if successful.
 */
int ANeuralNetworksExecution_startCompute(ANeuralNetworksExecution* execution,
                                          ANeuralNetworksEvent** event) __INTRODUCED_IN(27);

/**
 * Waits until the execution completes.
 *
 * More than one thread can wait on an event. When the execution completes,
 * all threads will be released.
 *
 * See {@link ANeuralNetworksExecution} for information on multithreaded usage.
 *
 * Available since API level 27.
 *
 * @return ANEURALNETWORKS_NO_ERROR if the execution completed normally.
 *         ANEURALNETWORKS_UNMAPPABLE if the execution input or output memory cannot
 *         be properly mapped.
 */
int ANeuralNetworksEvent_wait(ANeuralNetworksEvent* event) __INTRODUCED_IN(27);

/**
 * Destroys the event.
 *
 * See {@link ANeuralNetworksExecution} for information on multithreaded usage.
 *
 * Available since API level 27.
 *
 * @param event The event object to be destroyed. Passing NULL is acceptable and
 *              results in no operation.
 */
void ANeuralNetworksEvent_free(ANeuralNetworksEvent* event) __INTRODUCED_IN(27);

#endif  // __ANDROID_API__ >= 27

__END_DECLS

#endif  // ANDROID_FRAMEWORKS_ML_NN_RUNTIME_NEURAL_NETWORKS_H

/** @} */
