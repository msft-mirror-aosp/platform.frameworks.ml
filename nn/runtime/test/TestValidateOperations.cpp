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

#include "NeuralNetworksOEM.h"
#include "NeuralNetworksWrapper.h"

#include <gtest/gtest.h>
#include <optional>
#include <set>

using namespace android::nn::wrapper;

namespace {

static const int32_t kAvailableOperandCodes[] = {ANEURALNETWORKS_FLOAT32,
                                                 ANEURALNETWORKS_INT32,
                                                 ANEURALNETWORKS_UINT32,
                                                 ANEURALNETWORKS_TENSOR_FLOAT32,
                                                 ANEURALNETWORKS_TENSOR_INT32,
                                                 ANEURALNETWORKS_TENSOR_QUANT8_ASYMM,
                                                 ANEURALNETWORKS_BOOL,
                                                 ANEURALNETWORKS_TENSOR_QUANT16_SYMM,
                                                 ANEURALNETWORKS_TENSOR_FLOAT16,
                                                 ANEURALNETWORKS_TENSOR_BOOL8,
                                                 ANEURALNETWORKS_FLOAT16,
                                                 ANEURALNETWORKS_TENSOR_QUANT8_SYMM_PER_CHANNEL,
                                                 ANEURALNETWORKS_TENSOR_QUANT16_ASYMM,
                                                 ANEURALNETWORKS_TENSOR_OEM_BYTE};

ANeuralNetworksOperandType getOpType(int32_t opcode, uint32_t dimCount = 0, uint32_t* dim = nullptr,
                                     float scale = 0.0f, int32_t zeroPoint = 0) {
    return {.type = opcode,
            .dimensionCount = dimCount,
            .dimensions = dim,
            .scale = scale,
            .zeroPoint = zeroPoint};
}

struct OperandTypeWithExtraParams {
    OperandTypeWithExtraParams(const ANeuralNetworksOperandType& operandType)
        : operandType(operandType), channelQuant(std::nullopt) {}

    ANeuralNetworksOperandType operandType;
    std::optional<ANeuralNetworksSymmPerChannelQuantParams> channelQuant;
};

class OperationTestBase {
   public:
    OperationTestBase(ANeuralNetworksOperationType opCode,
                      std::vector<ANeuralNetworksOperandType> validInputs,
                      std::vector<ANeuralNetworksOperandType> validOutputs)
        : mOpCode(opCode) {
        for (ANeuralNetworksOperandType input : validInputs) {
            mValidInputs.push_back(input);
        }
        for (ANeuralNetworksOperandType output : validOutputs) {
            mValidOutputs.push_back(output);
        }
    }

    void setInputSymmPerChannelQuantParams(
            int32_t index, const ANeuralNetworksSymmPerChannelQuantParams& channelQuant) {
        mValidInputs[index].channelQuant = channelQuant;
    }

    void setOutputSymmPerChannelQuantParams(
            int32_t index, const ANeuralNetworksSymmPerChannelQuantParams& channelQuant) {
        mValidOutputs[index].channelQuant = channelQuant;
    }

    // Add each operand separately and add the operation using these operands.
    // This function does not cover the cases that an operand is used mutiple times.
    int32_t addOperation(const std::vector<OperandTypeWithExtraParams>& inputs,
                         const std::vector<OperandTypeWithExtraParams>& outputs) {
        ANeuralNetworksModel* model = nullptr;
        ANeuralNetworksModel_create(&model);

        uint32_t opIdx = 0;
        std::vector<uint32_t> inputIds;
        std::vector<uint32_t> outputIds;
        for (uint32_t i = 0; i < inputs.size(); i++) {
            ANeuralNetworksModel_addOperand(model, &inputs[i].operandType);
            if (inputs[i].channelQuant) {
                ANeuralNetworksModel_setOperandSymmPerChannelQuantParams(
                        model, opIdx, &inputs[i].channelQuant.value());
            }
            inputIds.push_back(opIdx++);
        }
        for (uint32_t i = 0; i < outputs.size(); i++) {
            ANeuralNetworksModel_addOperand(model, &outputs[i].operandType);
            if (outputs[i].channelQuant) {
                ANeuralNetworksModel_setOperandSymmPerChannelQuantParams(
                        model, opIdx, &outputs[i].channelQuant.value());
            }
            outputIds.push_back(opIdx++);
        }

        int32_t result = ANeuralNetworksModel_addOperation(
                model, mOpCode, static_cast<uint32_t>(inputIds.size()), inputIds.data(),
                static_cast<uint32_t>(outputIds.size()), outputIds.data());
        ANeuralNetworksModel_free(model);
        return result;
    }

    bool testMutatingInputOperandCode() {
        for (uint32_t i = 0; i < mValidInputs.size(); i++) {
            // LSH_PROJECTION's second argument is allowed to have any type.
            // This is the only operation that currently has a type that can be
            // anything independent from any other type. Changing the operand
            // type to any other type will result in a valid model for
            // LSH_PROJECTION. If this is the case, skip the test.
            if (mOpCode == ANEURALNETWORKS_LSH_PROJECTION && i == 1) {
                continue;
            }
            OperandTypeWithExtraParams newType = mValidInputs[i];
            int32_t originalOperandCode = mValidInputs[i].operandType.type;
            std::set<int32_t> operandTypesToSkip;
            // Transposed conv can have either fully quantized or per-channel
            // quantized filter for the quantized version of the op.
            if (mOpCode == ANEURALNETWORKS_TRANSPOSE_CONV_2D && i == 1) {
                if (originalOperandCode == ANEURALNETWORKS_TENSOR_QUANT8_ASYMM) {
                    operandTypesToSkip.insert(ANEURALNETWORKS_TENSOR_QUANT8_SYMM_PER_CHANNEL);
                } else if (originalOperandCode == ANEURALNETWORKS_TENSOR_QUANT8_SYMM_PER_CHANNEL) {
                    operandTypesToSkip.insert(ANEURALNETWORKS_TENSOR_QUANT8_ASYMM);
                }
            }
            for (int32_t newOperandCode : kAvailableOperandCodes) {
                if (newOperandCode == originalOperandCode ||
                    operandTypesToSkip.find(newOperandCode) != operandTypesToSkip.end()) {
                    continue;
                }
                // Switch input 7 from bool to int for 10-input CONV_2d
                // switch between valid "implicit padding with layout param"
                // and valid "explicit padding without layout param"
                if (mOpCode == ANEURALNETWORKS_CONV_2D && i == 7 && mValidInputs.size() == 10) {
                    if ((newOperandCode == ANEURALNETWORKS_INT32 &&
                         originalOperandCode == ANEURALNETWORKS_BOOL) ||
                        (newOperandCode == ANEURALNETWORKS_BOOL &&
                         originalOperandCode == ANEURALNETWORKS_INT32)) {
                        continue;
                    }
                }
                // QUANTIZE supports both types below and its output type does
                // not depend on the input type.
                if (mOpCode == ANEURALNETWORKS_QUANTIZE && i == 0 &&
                    (newOperandCode == ANEURALNETWORKS_TENSOR_FLOAT16 ||
                     newOperandCode == ANEURALNETWORKS_TENSOR_FLOAT32)) {
                    continue;
                }
                // ARGMIN/MAX supports four input types and has a fixed output type.
                if ((mOpCode == ANEURALNETWORKS_ARGMIN || mOpCode == ANEURALNETWORKS_ARGMAX) &&
                    i == 0 &&
                    (newOperandCode == ANEURALNETWORKS_TENSOR_FLOAT16 ||
                     newOperandCode == ANEURALNETWORKS_TENSOR_FLOAT32 ||
                     newOperandCode == ANEURALNETWORKS_TENSOR_INT32 ||
                     newOperandCode == ANEURALNETWORKS_TENSOR_QUANT8_ASYMM)) {
                    continue;
                }

                // Switch input 8 from bool to int for 11-input DEPTHWISE_CONV_2D
                // switch between valid "implicit padding with layout param"
                // and valid "explicit padding without layout param"
                if (mOpCode == ANEURALNETWORKS_DEPTHWISE_CONV_2D && i == 8 &&
                    mValidInputs.size() == 11) {
                    if ((newOperandCode == ANEURALNETWORKS_INT32 &&
                         originalOperandCode == ANEURALNETWORKS_BOOL) ||
                        (newOperandCode == ANEURALNETWORKS_BOOL &&
                         originalOperandCode == ANEURALNETWORKS_INT32)) {
                        continue;
                    }
                }

                newType.operandType.type = newOperandCode;
                std::vector<OperandTypeWithExtraParams> inputs = mValidInputs;
                inputs[i] = newType;
                int32_t result = addOperation(inputs, mValidOutputs);
                if (ANEURALNETWORKS_NO_ERROR == result) {
                    return false;
                }
            }
        }
        return true;
    }

    bool testMutatingOutputOperandCode() {
        for (uint32_t i = 0; i < mValidOutputs.size(); i++) {
            // LSH_PROJECTION's second argument is allowed to have any type.
            // This is the only operation that currently has a type that can be
            // anything independent from any other type. Changing the operand
            // type to any other type will result in a valid model for
            // LSH_PROJECTION. If this is the case, skip the test.
            if (mOpCode == ANEURALNETWORKS_LSH_PROJECTION && i == 1) {
                continue;
            }
            OperandTypeWithExtraParams newType = mValidOutputs[i].operandType;
            int32_t originalOperandCode = mValidOutputs[i].operandType.type;
            for (int32_t newOperandCode : kAvailableOperandCodes) {
                if (newOperandCode == originalOperandCode) {
                    continue;
                }
                // DEQUANTIZE's output can be either TENSOR_FLOAT16 or TENSOR_FLOAT32.
                if (mOpCode == ANEURALNETWORKS_DEQUANTIZE &&
                    (newOperandCode == ANEURALNETWORKS_TENSOR_FLOAT16 ||
                     newOperandCode == ANEURALNETWORKS_TENSOR_FLOAT32)) {
                    continue;
                }
                newType.operandType.type = newOperandCode;
                std::vector<OperandTypeWithExtraParams> outputs = mValidOutputs;
                outputs[i] = newType;
                int32_t result = addOperation(mValidInputs, outputs);
                if (ANEURALNETWORKS_NO_ERROR == result) {
                    return false;
                }
            }
        }
        return true;
    }

    bool testMutatingInputOperandCounts(uint32_t numToAdd = 5) {
        std::vector<OperandTypeWithExtraParams> inputs = mValidInputs;
        for (uint32_t i = 0; i < numToAdd; i++) {
            inputs.push_back(inputs[0]);
            if (ANEURALNETWORKS_NO_ERROR == addOperation(inputs, mValidOutputs)) {
                return false;
            }
        }
        return true;
    }

    bool testMutatingOutputOperandCounts() {
        std::vector<OperandTypeWithExtraParams> outputs = mValidOutputs;
        for (int i = 0; i < 5; i++) {
            outputs.push_back(outputs[0]);
            if (ANEURALNETWORKS_NO_ERROR == addOperation(mValidInputs, outputs)) {
                return false;
            }
        }
        return true;
    }

   private:
    ANeuralNetworksOperationType mOpCode;
    // The dimensions in the ANeuralNetworksOperandType must outlive the test object.
    std::vector<OperandTypeWithExtraParams> mValidInputs;
    std::vector<OperandTypeWithExtraParams> mValidOutputs;
};

void argMinMaxTest(ANeuralNetworksOperationType operationCode, int32_t inputOperandType) {
    SCOPED_TRACE(inputOperandType);
    uint32_t inputDimensions[4] = {2, 2, 2, 2};
    ANeuralNetworksOperandType input0 = {
            .type = inputOperandType,
            .dimensionCount = 4,
            .dimensions = inputDimensions,
    };
    ANeuralNetworksOperandType axis = {
            .type = ANEURALNETWORKS_INT32,
            .dimensionCount = 0,
            .dimensions = nullptr,
    };
    uint32_t outputDimensions[3] = {2, 2, 2};
    ANeuralNetworksOperandType output = {
            .type = ANEURALNETWORKS_TENSOR_INT32,
            .dimensionCount = 3,
            .dimensions = outputDimensions,
    };
    OperationTestBase test(operationCode, {input0, axis}, {output});

    EXPECT_TRUE(test.testMutatingInputOperandCode());
    EXPECT_TRUE(test.testMutatingInputOperandCounts());
    EXPECT_TRUE(test.testMutatingOutputOperandCode());
    EXPECT_TRUE(test.testMutatingOutputOperandCounts());
}

TEST(OperationValidationTest, ARGMIN) {
    argMinMaxTest(ANEURALNETWORKS_ARGMIN, ANEURALNETWORKS_TENSOR_FLOAT16);
    argMinMaxTest(ANEURALNETWORKS_ARGMIN, ANEURALNETWORKS_TENSOR_FLOAT32);
    argMinMaxTest(ANEURALNETWORKS_ARGMIN, ANEURALNETWORKS_TENSOR_INT32);
    argMinMaxTest(ANEURALNETWORKS_ARGMIN, ANEURALNETWORKS_TENSOR_QUANT8_ASYMM);
}

TEST(OperationValidationTest, ARGMAX) {
    argMinMaxTest(ANEURALNETWORKS_ARGMAX, ANEURALNETWORKS_TENSOR_FLOAT16);
    argMinMaxTest(ANEURALNETWORKS_ARGMAX, ANEURALNETWORKS_TENSOR_FLOAT32);
    argMinMaxTest(ANEURALNETWORKS_ARGMAX, ANEURALNETWORKS_TENSOR_INT32);
    argMinMaxTest(ANEURALNETWORKS_ARGMAX, ANEURALNETWORKS_TENSOR_QUANT8_ASYMM);
}

TEST(OperationValidationTest, DEQUANTIZE_float16) {
    uint32_t inputDimensions[4] = {2, 2, 2, 2};
    ANeuralNetworksOperandType input = {.type = ANEURALNETWORKS_TENSOR_QUANT8_ASYMM,
                                        .dimensionCount = 4,
                                        .dimensions = inputDimensions,
                                        .scale = 1.0f,
                                        .zeroPoint = 0};
    ANeuralNetworksOperandType output = {.type = ANEURALNETWORKS_TENSOR_FLOAT16,
                                         .dimensionCount = 4,
                                         .dimensions = inputDimensions,
                                         .scale = 0.0f,
                                         .zeroPoint = 0};
    OperationTestBase dequantizeTest(ANEURALNETWORKS_DEQUANTIZE, {input}, {output});

    EXPECT_TRUE(dequantizeTest.testMutatingInputOperandCode());
    EXPECT_TRUE(dequantizeTest.testMutatingInputOperandCounts());
    EXPECT_TRUE(dequantizeTest.testMutatingOutputOperandCode());
    EXPECT_TRUE(dequantizeTest.testMutatingOutputOperandCounts());
}

TEST(OperationValidationTest, DEQUANTIZE_float32) {
    uint32_t inputDimensions[4] = {2, 2, 2, 2};
    ANeuralNetworksOperandType input = {.type = ANEURALNETWORKS_TENSOR_QUANT8_ASYMM,
                                        .dimensionCount = 4,
                                        .dimensions = inputDimensions,
                                        .scale = 1.0f,
                                        .zeroPoint = 0};
    ANeuralNetworksOperandType output = {.type = ANEURALNETWORKS_TENSOR_FLOAT32,
                                         .dimensionCount = 4,
                                         .dimensions = inputDimensions,
                                         .scale = 0.0f,
                                         .zeroPoint = 0};
    OperationTestBase dequantizeTest(ANEURALNETWORKS_DEQUANTIZE, {input}, {output});

    EXPECT_TRUE(dequantizeTest.testMutatingInputOperandCode());
    EXPECT_TRUE(dequantizeTest.testMutatingInputOperandCounts());
    EXPECT_TRUE(dequantizeTest.testMutatingOutputOperandCode());
    EXPECT_TRUE(dequantizeTest.testMutatingOutputOperandCounts());
}

void expandDimsTest(int32_t inputOperandType) {
    SCOPED_TRACE(inputOperandType);
    uint32_t inputDimensions[4] = {2, 2, 2, 2};
    ANeuralNetworksOperandType input0 = {
            .type = inputOperandType,
            .dimensionCount = 4,
            .dimensions = inputDimensions,
    };
    ANeuralNetworksOperandType axis = {
            .type = ANEURALNETWORKS_INT32,
            .dimensionCount = 0,
            .dimensions = nullptr,
    };
    uint32_t outputDimensions[5] = {2, 2, 2, 2, 2};
    ANeuralNetworksOperandType output = {
            .type = inputOperandType,
            .dimensionCount = 5,
            .dimensions = outputDimensions,
    };
    OperationTestBase test(ANEURALNETWORKS_EXPAND_DIMS, {input0, axis}, {output});

    EXPECT_TRUE(test.testMutatingInputOperandCode());
    EXPECT_TRUE(test.testMutatingInputOperandCounts());
    EXPECT_TRUE(test.testMutatingOutputOperandCode());
    EXPECT_TRUE(test.testMutatingOutputOperandCounts());
}

TEST(OperationValidationTest, EXPAND_DIMS) {
    expandDimsTest(ANEURALNETWORKS_TENSOR_FLOAT16);
    expandDimsTest(ANEURALNETWORKS_TENSOR_FLOAT32);
    expandDimsTest(ANEURALNETWORKS_TENSOR_INT32);
    expandDimsTest(ANEURALNETWORKS_TENSOR_QUANT8_ASYMM);
}

void gatherTest(int32_t inputOperandType) {
    SCOPED_TRACE(inputOperandType);
    uint32_t inputDimensions[4] = {2, 2, 2, 2};
    ANeuralNetworksOperandType input0 = {
            .type = inputOperandType,
            .dimensionCount = 4,
            .dimensions = inputDimensions,
    };
    ANeuralNetworksOperandType axis = {
            .type = ANEURALNETWORKS_INT32,
            .dimensionCount = 0,
            .dimensions = nullptr,
    };
    ANeuralNetworksOperandType input2 = {
            .type = ANEURALNETWORKS_TENSOR_INT32,
            .dimensionCount = 4,
            .dimensions = inputDimensions,
    };
    uint32_t outputDimensions[7] = {2, 2, 2, 2, 2, 2, 2};
    ANeuralNetworksOperandType output = {
            .type = inputOperandType,
            .dimensionCount = 7,
            .dimensions = outputDimensions,
    };
    OperationTestBase test(ANEURALNETWORKS_GATHER, {input0, axis, input2}, {output});

    EXPECT_TRUE(test.testMutatingInputOperandCode());
    EXPECT_TRUE(test.testMutatingInputOperandCounts());
    EXPECT_TRUE(test.testMutatingOutputOperandCode());
    EXPECT_TRUE(test.testMutatingOutputOperandCounts());
}

TEST(OperationValidationTest, GATHER) {
    gatherTest(ANEURALNETWORKS_TENSOR_FLOAT16);
    gatherTest(ANEURALNETWORKS_TENSOR_FLOAT32);
    gatherTest(ANEURALNETWORKS_TENSOR_INT32);
    gatherTest(ANEURALNETWORKS_TENSOR_QUANT8_ASYMM);
}

void quantizeOpTest(int32_t operandCode) {
    uint32_t inputDimensions[4] = {2, 2, 2, 2};
    ANeuralNetworksOperandType input = {
            .type = operandCode, .dimensionCount = 4, .dimensions = inputDimensions};
    ANeuralNetworksOperandType output = {.type = ANEURALNETWORKS_TENSOR_QUANT8_ASYMM,
                                         .dimensionCount = 4,
                                         .dimensions = inputDimensions,
                                         .scale = 1.0f,
                                         .zeroPoint = 0};
    OperationTestBase test(ANEURALNETWORKS_QUANTIZE, {input}, {output});

    EXPECT_TRUE(test.testMutatingInputOperandCode());
    EXPECT_TRUE(test.testMutatingInputOperandCounts());
    EXPECT_TRUE(test.testMutatingOutputOperandCode());
    EXPECT_TRUE(test.testMutatingOutputOperandCounts());
}

TEST(OperationValidationTest, QUANTIZED_16BIT_LSTM) {
    uint32_t oneDimensional[1] = {5};
    uint32_t twoDimensional[2] = {5, 5};

    ANeuralNetworksOperandType int32Tensor1D = {
            .type = ANEURALNETWORKS_TENSOR_QUANT8_ASYMM,
            .dimensionCount = 1,
            .dimensions = oneDimensional,
            .scale = 0.0f,
            .zeroPoint = 0,
    };
    ANeuralNetworksOperandType quant8Tensor2D = {
            .type = ANEURALNETWORKS_TENSOR_QUANT8_ASYMM,
            .dimensionCount = 2,
            .dimensions = twoDimensional,
            .scale = 0.0f,
            .zeroPoint = 0,
    };
    ANeuralNetworksOperandType quant16Tensor2D = {
            .type = ANEURALNETWORKS_TENSOR_QUANT16_SYMM,
            .dimensionCount = 2,
            .dimensions = twoDimensional,
            .scale = 0.0f,
            .zeroPoint = 0,
    };

    ANeuralNetworksOperandType input0 = quant8Tensor2D;
    ANeuralNetworksOperandType input1 = quant8Tensor2D;
    ANeuralNetworksOperandType input2 = quant8Tensor2D;
    ANeuralNetworksOperandType input3 = quant8Tensor2D;
    ANeuralNetworksOperandType input4 = quant8Tensor2D;
    ANeuralNetworksOperandType input5 = quant8Tensor2D;
    ANeuralNetworksOperandType input6 = quant8Tensor2D;
    ANeuralNetworksOperandType input7 = quant8Tensor2D;
    ANeuralNetworksOperandType input8 = quant8Tensor2D;
    ANeuralNetworksOperandType input9 = int32Tensor1D;
    ANeuralNetworksOperandType input10 = int32Tensor1D;
    ANeuralNetworksOperandType input11 = int32Tensor1D;
    ANeuralNetworksOperandType input12 = int32Tensor1D;
    ANeuralNetworksOperandType input13 = quant16Tensor2D;
    ANeuralNetworksOperandType input14 = int32Tensor1D;

    ANeuralNetworksOperandType output0 = quant16Tensor2D;
    ANeuralNetworksOperandType output1 = quant8Tensor2D;

    OperationTestBase test(ANEURALNETWORKS_QUANTIZED_16BIT_LSTM,
                           {input0, input1, input2, input3, input4, input5, input6, input7, input8,
                            input9, input10, input11, input12, input13, input14},
                           {output0, output1});

    EXPECT_TRUE(test.testMutatingInputOperandCode());
    EXPECT_TRUE(test.testMutatingInputOperandCounts());
    EXPECT_TRUE(test.testMutatingOutputOperandCode());
    EXPECT_TRUE(test.testMutatingOutputOperandCounts());
}

TEST(OperationValidationTest, QUANTIZE_float16) {
    quantizeOpTest(ANEURALNETWORKS_TENSOR_FLOAT16);
}

TEST(OperationValidationTest, QUANTIZE_float32) {
    quantizeOpTest(ANEURALNETWORKS_TENSOR_FLOAT32);
}

void splitTest(int32_t inputOperandType) {
    SCOPED_TRACE(inputOperandType);
    uint32_t inputDimensions[4] = {2, 2, 2, 2};
    ANeuralNetworksOperandType input0 = {
            .type = inputOperandType,
            .dimensionCount = 4,
            .dimensions = inputDimensions,
    };
    ANeuralNetworksOperandType axis = {
            .type = ANEURALNETWORKS_INT32,
            .dimensionCount = 0,
            .dimensions = nullptr,
    };
    ANeuralNetworksOperandType count = {
            .type = ANEURALNETWORKS_INT32,
            .dimensionCount = 0,
            .dimensions = nullptr,
    };
    uint32_t outputDimensions[2] = {2, 2};
    ANeuralNetworksOperandType output0 = {
            .type = inputOperandType,
            .dimensionCount = 2,
            .dimensions = outputDimensions,
    };
    ANeuralNetworksOperandType output1 = {
            .type = inputOperandType,
            .dimensionCount = 2,
            .dimensions = outputDimensions,
    };
    OperationTestBase test(ANEURALNETWORKS_SPLIT, {input0, axis, count}, {output0, output1});

    EXPECT_TRUE(test.testMutatingInputOperandCode());
    EXPECT_TRUE(test.testMutatingInputOperandCounts());
    EXPECT_TRUE(test.testMutatingOutputOperandCode());
    // SPLIT output operand count depends on the value of the count parameter,
    // so is not tested here.
}

TEST(OperationValidationTest, SPLIT) {
    splitTest(ANEURALNETWORKS_TENSOR_FLOAT16);
    splitTest(ANEURALNETWORKS_TENSOR_FLOAT32);
    splitTest(ANEURALNETWORKS_TENSOR_INT32);
    splitTest(ANEURALNETWORKS_TENSOR_QUANT8_ASYMM);
}

void tileTest(int32_t inputOperandType) {
    SCOPED_TRACE(inputOperandType);
    uint32_t inputDimensions[4] = {2, 2, 2, 2};
    ANeuralNetworksOperandType input0 = {
            .type = inputOperandType,
            .dimensionCount = 4,
            .dimensions = inputDimensions,
    };
    uint32_t multiplesDimensions[1] = {4};
    ANeuralNetworksOperandType multiples = {
            .type = ANEURALNETWORKS_TENSOR_INT32,
            .dimensionCount = 1,
            .dimensions = multiplesDimensions,
    };
    uint32_t outputDimensions[8] = {2, 2, 2, 2, 2, 2, 2, 2};
    ANeuralNetworksOperandType output0 = {
            .type = inputOperandType,
            .dimensionCount = 8,
            .dimensions = outputDimensions,
    };
    OperationTestBase test(ANEURALNETWORKS_TILE, {input0, multiples}, {output0});

    EXPECT_TRUE(test.testMutatingInputOperandCode());
    EXPECT_TRUE(test.testMutatingInputOperandCounts());
    EXPECT_TRUE(test.testMutatingOutputOperandCode());
    EXPECT_TRUE(test.testMutatingOutputOperandCounts());
}

TEST(OperationValidationTest, TILE) {
    tileTest(ANEURALNETWORKS_TENSOR_FLOAT16);
    tileTest(ANEURALNETWORKS_TENSOR_FLOAT32);
    tileTest(ANEURALNETWORKS_TENSOR_INT32);
    tileTest(ANEURALNETWORKS_TENSOR_QUANT8_ASYMM);
}

void simpleMathOpTest(ANeuralNetworksOperationType operationCode, int32_t operandCode) {
    uint32_t inputDimensions[4] = {2, 2, 2, 2};
    ANeuralNetworksOperandType input1 = {.type = operandCode,
                                         .dimensionCount = 4,
                                         .dimensions = inputDimensions,
                                         .scale = 0.0f,
                                         .zeroPoint = 0};
    if (operandCode == ANEURALNETWORKS_TENSOR_QUANT8_ASYMM) {
        input1.scale = 0.5f;
    }

    ANeuralNetworksOperandType input2 = input1;
    ANeuralNetworksOperandType output = input1;
    ANeuralNetworksOperandType activation = {.type = ANEURALNETWORKS_INT32,
                                             .dimensionCount = 0,
                                             .dimensions = nullptr,
                                             .scale = 0.0f,
                                             .zeroPoint = 0};

    OperationTestBase simpleMathTest(operationCode, {input1, input2, activation}, {output});

    EXPECT_TRUE(simpleMathTest.testMutatingInputOperandCode());
    EXPECT_TRUE(simpleMathTest.testMutatingInputOperandCounts());
    EXPECT_TRUE(simpleMathTest.testMutatingOutputOperandCode());
    EXPECT_TRUE(simpleMathTest.testMutatingOutputOperandCounts());
}

TEST(OperationValidationTest, ADD_float16) {
    simpleMathOpTest(ANEURALNETWORKS_ADD, ANEURALNETWORKS_TENSOR_FLOAT16);
}

TEST(OperationValidationTest, ADD_float32) {
    simpleMathOpTest(ANEURALNETWORKS_ADD, ANEURALNETWORKS_TENSOR_FLOAT32);
}

TEST(OperationValidationTest, MUL_float32) {
    simpleMathOpTest(ANEURALNETWORKS_MUL, ANEURALNETWORKS_TENSOR_FLOAT32);
}

TEST(OperationValidationTest, SUB_float32) {
    simpleMathOpTest(ANEURALNETWORKS_SUB, ANEURALNETWORKS_TENSOR_FLOAT32);
}

TEST(OperationValidationTest, DIV_float32) {
    simpleMathOpTest(ANEURALNETWORKS_DIV, ANEURALNETWORKS_TENSOR_FLOAT32);
}

TEST(OperationValidationTest, ADD_quant8) {
    simpleMathOpTest(ANEURALNETWORKS_ADD, ANEURALNETWORKS_TENSOR_QUANT8_ASYMM);
}

TEST(OperationValidationTest, MUL_quant8) {
    simpleMathOpTest(ANEURALNETWORKS_MUL, ANEURALNETWORKS_TENSOR_QUANT8_ASYMM);
}

void binaryOpTest(ANeuralNetworksOperationType operationCode, int32_t operandCode) {
    uint32_t inputDimensions[] = {2, 2, 2, 2, 2};
    ANeuralNetworksOperandType input1 = {.type = operandCode,
                                         .dimensionCount = 5,
                                         .dimensions = inputDimensions,
                                         .scale = 0.0f,
                                         .zeroPoint = 0};
    if (operandCode == ANEURALNETWORKS_TENSOR_QUANT8_ASYMM) {
        input1.scale = 0.5f;
    }

    ANeuralNetworksOperandType input2 = input1;
    ANeuralNetworksOperandType output = input1;

    OperationTestBase test(operationCode, {input1, input2}, {output});

    EXPECT_TRUE(test.testMutatingInputOperandCode());
    EXPECT_TRUE(test.testMutatingInputOperandCounts());
    EXPECT_TRUE(test.testMutatingOutputOperandCode());
    EXPECT_TRUE(test.testMutatingOutputOperandCounts());
}

TEST(OperationValidationTest, MAXIMUM_float16) {
    binaryOpTest(ANEURALNETWORKS_MAXIMUM, ANEURALNETWORKS_TENSOR_FLOAT16);
}

TEST(OperationValidationTest, MAXIMUM_float32) {
    binaryOpTest(ANEURALNETWORKS_MAXIMUM, ANEURALNETWORKS_TENSOR_FLOAT32);
}

TEST(OperationValidationTest, MAXIMUM_int32) {
    binaryOpTest(ANEURALNETWORKS_MAXIMUM, ANEURALNETWORKS_TENSOR_INT32);
}

TEST(OperationValidationTest, MAXIMUM_quant8) {
    binaryOpTest(ANEURALNETWORKS_MAXIMUM, ANEURALNETWORKS_TENSOR_QUANT8_ASYMM);
}

TEST(OperationValidationTest, MINIMUM_float16) {
    binaryOpTest(ANEURALNETWORKS_MINIMUM, ANEURALNETWORKS_TENSOR_FLOAT16);
}

TEST(OperationValidationTest, MINIMUM_float32) {
    binaryOpTest(ANEURALNETWORKS_MINIMUM, ANEURALNETWORKS_TENSOR_FLOAT32);
}

TEST(OperationValidationTest, MINIMUM_int32) {
    binaryOpTest(ANEURALNETWORKS_MINIMUM, ANEURALNETWORKS_TENSOR_INT32);
}

TEST(OperationValidationTest, MINIMUM_quant8) {
    binaryOpTest(ANEURALNETWORKS_MINIMUM, ANEURALNETWORKS_TENSOR_QUANT8_ASYMM);
}

void activationOpTest(ANeuralNetworksOperationType operationCode, int32_t operandCode) {
    uint32_t inputDimensions[4] = {2, 2, 2, 2};
    ANeuralNetworksOperandType input = {.type = operandCode,
                                        .dimensionCount = 4,
                                        .dimensions = inputDimensions,
                                        .scale = 0.0f,
                                        .zeroPoint = 0};
    if (operandCode == ANEURALNETWORKS_TENSOR_QUANT8_ASYMM) {
        input.scale = 1.f / 256;
    }

    ANeuralNetworksOperandType output = input;
    OperationTestBase test(operationCode, {input}, {output});

    EXPECT_TRUE(test.testMutatingInputOperandCode());
    EXPECT_TRUE(test.testMutatingInputOperandCounts());
    EXPECT_TRUE(test.testMutatingOutputOperandCode());
    EXPECT_TRUE(test.testMutatingOutputOperandCounts());
}

TEST(OperationValidationTest, ABS_float16) {
    activationOpTest(ANEURALNETWORKS_ABS, ANEURALNETWORKS_TENSOR_FLOAT16);
}

TEST(OperationValidationTest, ABS_float32) {
    activationOpTest(ANEURALNETWORKS_ABS, ANEURALNETWORKS_TENSOR_FLOAT32);
}

TEST(OperationValidationTest, EXP_float16) {
    activationOpTest(ANEURALNETWORKS_EXP, ANEURALNETWORKS_TENSOR_FLOAT16);
}

TEST(OperationValidationTest, EXP_float32) {
    activationOpTest(ANEURALNETWORKS_EXP, ANEURALNETWORKS_TENSOR_FLOAT32);
}

TEST(OperationValidationTest, LOG_float16) {
    activationOpTest(ANEURALNETWORKS_LOG, ANEURALNETWORKS_TENSOR_FLOAT16);
}

TEST(OperationValidationTest, LOG_float32) {
    activationOpTest(ANEURALNETWORKS_LOG, ANEURALNETWORKS_TENSOR_FLOAT32);
}

TEST(OperationValidationTest, RSQRT_float16) {
    activationOpTest(ANEURALNETWORKS_RSQRT, ANEURALNETWORKS_TENSOR_FLOAT16);
}

TEST(OperationValidationTest, RSQRT_float32) {
    activationOpTest(ANEURALNETWORKS_RSQRT, ANEURALNETWORKS_TENSOR_FLOAT32);
}

TEST(OperationValidationTest, SIN_float16) {
    activationOpTest(ANEURALNETWORKS_SIN, ANEURALNETWORKS_TENSOR_FLOAT16);
}

TEST(OperationValidationTest, SIN_float32) {
    activationOpTest(ANEURALNETWORKS_SIN, ANEURALNETWORKS_TENSOR_FLOAT32);
}

TEST(OperationValidationTest, SQRT_float16) {
    activationOpTest(ANEURALNETWORKS_SQRT, ANEURALNETWORKS_TENSOR_FLOAT16);
}

TEST(OperationValidationTest, SQRT_float32) {
    activationOpTest(ANEURALNETWORKS_SQRT, ANEURALNETWORKS_TENSOR_FLOAT32);
}

TEST(OperationValidationTest, NEG_float16) {
    activationOpTest(ANEURALNETWORKS_NEG, ANEURALNETWORKS_TENSOR_FLOAT16);
}

TEST(OperationValidationTest, NEG_float32) {
    activationOpTest(ANEURALNETWORKS_NEG, ANEURALNETWORKS_TENSOR_FLOAT32);
}

TEST(OperationValidationTest, NEG_int32) {
    activationOpTest(ANEURALNETWORKS_NEG, ANEURALNETWORKS_TENSOR_INT32);
}

TEST(OperationValidationTest, FLOOR_float16) {
    activationOpTest(ANEURALNETWORKS_FLOOR, ANEURALNETWORKS_TENSOR_FLOAT16);
}

TEST(OperationValidationTest, FLOOR_float32) {
    activationOpTest(ANEURALNETWORKS_FLOOR, ANEURALNETWORKS_TENSOR_FLOAT32);
}

TEST(OperationValidationTest, LOGICAL_NOT_bool) {
    activationOpTest(ANEURALNETWORKS_LOGICAL_NOT, ANEURALNETWORKS_TENSOR_BOOL8);
}

TEST(OperationValidationTest, MEAN_float16) {
    activationOpTest(ANEURALNETWORKS_MEAN, ANEURALNETWORKS_TENSOR_FLOAT16);
}

TEST(OperationValidationTest, MEAN_float32) {
    activationOpTest(ANEURALNETWORKS_MEAN, ANEURALNETWORKS_TENSOR_FLOAT32);
}

TEST(OperationValidationTest, TANH_float32) {
    activationOpTest(ANEURALNETWORKS_TANH, ANEURALNETWORKS_TENSOR_FLOAT32);
}

TEST(OperationValidationTest, RELU_float32) {
    activationOpTest(ANEURALNETWORKS_RELU, ANEURALNETWORKS_TENSOR_FLOAT32);
}

TEST(OperationValidationTest, RELU1_float32) {
    activationOpTest(ANEURALNETWORKS_RELU, ANEURALNETWORKS_TENSOR_FLOAT32);
}

TEST(OperationValidationTest, RELU6_float32) {
    activationOpTest(ANEURALNETWORKS_RELU, ANEURALNETWORKS_TENSOR_FLOAT32);
}

TEST(OperationValidationTest, LOG_SOFTMAX_float16) {
    activationOpTest(ANEURALNETWORKS_LOG_SOFTMAX, ANEURALNETWORKS_TENSOR_FLOAT16);
}

TEST(OperationValidationTest, LOG_SOFTMAX_float32) {
    activationOpTest(ANEURALNETWORKS_LOG_SOFTMAX, ANEURALNETWORKS_TENSOR_FLOAT32);
}

TEST(OperationValidationTest, LOGISTIC_float32) {
    activationOpTest(ANEURALNETWORKS_LOGISTIC, ANEURALNETWORKS_TENSOR_FLOAT32);
}

TEST(OperationValidationTest, RELU_quant8) {
    activationOpTest(ANEURALNETWORKS_RELU, ANEURALNETWORKS_TENSOR_QUANT8_ASYMM);
}

TEST(OperationValidationTest, RELU1_quant8) {
    activationOpTest(ANEURALNETWORKS_RELU, ANEURALNETWORKS_TENSOR_QUANT8_ASYMM);
}

TEST(OperationValidationTest, RELU6_quant8) {
    activationOpTest(ANEURALNETWORKS_RELU, ANEURALNETWORKS_TENSOR_QUANT8_ASYMM);
}

TEST(OperationValidationTest, LOGISTIC_quant8) {
    activationOpTest(ANEURALNETWORKS_LOGISTIC, ANEURALNETWORKS_TENSOR_QUANT8_ASYMM);
}

void softmaxOpTest(int32_t operandCode) {
    uint32_t inputDimensions[4] = {2, 2, 2, 2};
    ANeuralNetworksOperandType input = {.type = operandCode,
                                        .dimensionCount = 4,
                                        .dimensions = inputDimensions,
                                        .scale = 0.0f,
                                        .zeroPoint = 0};
    if (operandCode == ANEURALNETWORKS_TENSOR_QUANT8_ASYMM) {
        input.scale = 1.f / 256;
    }

    ANeuralNetworksOperandType output = input;
    ANeuralNetworksOperandType beta = {.type = ANEURALNETWORKS_FLOAT32,
                                       .dimensionCount = 0,
                                       .dimensions = nullptr,
                                       .scale = 0.0f,
                                       .zeroPoint = 0};

    OperationTestBase softmaxTest(ANEURALNETWORKS_SOFTMAX, {input, beta}, {output});
    EXPECT_TRUE(softmaxTest.testMutatingInputOperandCode());
    EXPECT_TRUE(softmaxTest.testMutatingInputOperandCounts());
    EXPECT_TRUE(softmaxTest.testMutatingOutputOperandCode());
    EXPECT_TRUE(softmaxTest.testMutatingOutputOperandCounts());

    ANeuralNetworksOperandType axis = {.type = ANEURALNETWORKS_INT32,
                                       .dimensionCount = 0,
                                       .dimensions = nullptr,
                                       .scale = 0.0f,
                                       .zeroPoint = 0};
    OperationTestBase softmaxAxisTest(ANEURALNETWORKS_SOFTMAX, {input, beta, axis}, {output});
    EXPECT_TRUE(softmaxAxisTest.testMutatingInputOperandCode());
    EXPECT_TRUE(softmaxAxisTest.testMutatingInputOperandCounts());
    EXPECT_TRUE(softmaxAxisTest.testMutatingOutputOperandCode());
    EXPECT_TRUE(softmaxAxisTest.testMutatingOutputOperandCounts());
}

TEST(OperationValidationTest, SOFTMAX_float32) {
    softmaxOpTest(ANEURALNETWORKS_TENSOR_FLOAT32);
}

TEST(OperationValidationTest, SOFTMAX_quant8) {
    softmaxOpTest(ANEURALNETWORKS_TENSOR_QUANT8_ASYMM);
}

void poolingOpTest(ANeuralNetworksOperationType operationCode, int32_t operandCode) {
    uint32_t inputDimensions[4] = {2, 4, 4, 2};
    ANeuralNetworksOperandType input = {.type = operandCode,
                                        .dimensionCount = 4,
                                        .dimensions = inputDimensions,
                                        .scale = 0.0f,
                                        .zeroPoint = 0};
    if (operandCode == ANEURALNETWORKS_TENSOR_QUANT8_ASYMM) {
        input.scale = 1.f / 256;
    }
    ANeuralNetworksOperandType output = input;

    ANeuralNetworksOperandType scalar = {.type = ANEURALNETWORKS_INT32,
                                         .dimensionCount = 0,
                                         .dimensions = nullptr,
                                         .scale = 0.0f,
                                         .zeroPoint = 0};
    ANeuralNetworksOperandType padLeft = scalar;
    ANeuralNetworksOperandType padRight = scalar;
    ANeuralNetworksOperandType padTop = scalar;
    ANeuralNetworksOperandType padBottom = scalar;
    ANeuralNetworksOperandType strideWidth = scalar;
    ANeuralNetworksOperandType strideHeight = scalar;
    ANeuralNetworksOperandType filterWidth = scalar;
    ANeuralNetworksOperandType filterHeight = scalar;
    ANeuralNetworksOperandType activation = scalar;

    OperationTestBase explicitPoolingTest(operationCode,
                                          {input, padLeft, padRight, padTop, padBottom, strideWidth,
                                           strideHeight, filterWidth, filterHeight, activation},
                                          {output});

    EXPECT_TRUE(explicitPoolingTest.testMutatingInputOperandCode());
    EXPECT_TRUE(explicitPoolingTest.testMutatingInputOperandCounts());
    EXPECT_TRUE(explicitPoolingTest.testMutatingOutputOperandCode());
    EXPECT_TRUE(explicitPoolingTest.testMutatingOutputOperandCounts());

    ANeuralNetworksOperandType padImplicit = scalar;
    OperationTestBase implicitPoolingTest(
            operationCode,
            {input, padImplicit, strideWidth, strideHeight, filterWidth, filterHeight, activation},
            {output});

    EXPECT_TRUE(implicitPoolingTest.testMutatingInputOperandCode());
    EXPECT_TRUE(implicitPoolingTest.testMutatingInputOperandCounts());
    EXPECT_TRUE(implicitPoolingTest.testMutatingOutputOperandCode());
    EXPECT_TRUE(implicitPoolingTest.testMutatingOutputOperandCounts());

    ANeuralNetworksOperandType layout = {.type = ANEURALNETWORKS_BOOL,
                                         .dimensionCount = 0,
                                         .dimensions = nullptr,
                                         .scale = 0.0f,
                                         .zeroPoint = 0};

    OperationTestBase explicitNchwPoolingTest(
            operationCode,
            {input, padLeft, padRight, padTop, padBottom, strideWidth, strideHeight, filterWidth,
             filterHeight, activation, layout},
            {output});

    EXPECT_TRUE(explicitNchwPoolingTest.testMutatingInputOperandCode());
    EXPECT_TRUE(explicitNchwPoolingTest.testMutatingInputOperandCounts());
    EXPECT_TRUE(explicitNchwPoolingTest.testMutatingOutputOperandCode());
    EXPECT_TRUE(explicitNchwPoolingTest.testMutatingOutputOperandCounts());

    OperationTestBase implicitNchwPoolingTest(operationCode,
                                              {input, padImplicit, strideWidth, strideHeight,
                                               filterWidth, filterHeight, activation, layout},
                                              {output});

    EXPECT_TRUE(implicitNchwPoolingTest.testMutatingInputOperandCode());
    EXPECT_TRUE(implicitNchwPoolingTest.testMutatingInputOperandCounts());
    EXPECT_TRUE(implicitNchwPoolingTest.testMutatingOutputOperandCode());
    EXPECT_TRUE(implicitNchwPoolingTest.testMutatingOutputOperandCounts());
}

TEST(OperationValidationTest, AVERAGE_POOL_2D_float16) {
    poolingOpTest(ANEURALNETWORKS_AVERAGE_POOL_2D, ANEURALNETWORKS_TENSOR_FLOAT16);
}

TEST(OperationValidationTest, AVERAGE_POOL_2D_float32) {
    poolingOpTest(ANEURALNETWORKS_AVERAGE_POOL_2D, ANEURALNETWORKS_TENSOR_FLOAT32);
}

TEST(OperationValidationTest, MAX_POOL_2D_float32) {
    poolingOpTest(ANEURALNETWORKS_MAX_POOL_2D, ANEURALNETWORKS_TENSOR_FLOAT32);
}

TEST(OperationValidationTest, MAX_POOL_2D_float16) {
    poolingOpTest(ANEURALNETWORKS_MAX_POOL_2D, ANEURALNETWORKS_TENSOR_FLOAT16);
}

TEST(OperationValidationTest, L2_POOL_2D_float16) {
    poolingOpTest(ANEURALNETWORKS_L2_POOL_2D, ANEURALNETWORKS_TENSOR_FLOAT16);
}

TEST(OperationValidationTest, L2_POOL_2D_float32) {
    poolingOpTest(ANEURALNETWORKS_L2_POOL_2D, ANEURALNETWORKS_TENSOR_FLOAT32);
}

TEST(OperationValidationTest, AVERAGE_POOL_2D_quant8) {
    poolingOpTest(ANEURALNETWORKS_AVERAGE_POOL_2D, ANEURALNETWORKS_TENSOR_QUANT8_ASYMM);
}

TEST(OperationValidationTest, MAX_POOL_2D_quant8) {
    poolingOpTest(ANEURALNETWORKS_MAX_POOL_2D, ANEURALNETWORKS_TENSOR_QUANT8_ASYMM);
}

void spaceDepthOpTest(ANeuralNetworksOperationType operationCode, int32_t operandCode) {
    uint32_t inputDimensions[4] = {2, 2, 2, 2};
    ANeuralNetworksOperandType input = {.type = operandCode,
                                        .dimensionCount = 4,
                                        .dimensions = inputDimensions,
                                        .scale = 0.0f,
                                        .zeroPoint = 0};
    if (operandCode == ANEURALNETWORKS_TENSOR_QUANT8_ASYMM) {
        input.scale = 1.f / 256;
    }

    ANeuralNetworksOperandType block_size = {.type = ANEURALNETWORKS_INT32,
                                             .dimensionCount = 0,
                                             .dimensions = nullptr,
                                             .scale = 0.0f,
                                             .zeroPoint = 0};
    ANeuralNetworksOperandType output = input;

    OperationTestBase spaceDepthTest(operationCode, {input, block_size}, {output});
    EXPECT_TRUE(spaceDepthTest.testMutatingInputOperandCode());
    EXPECT_TRUE(spaceDepthTest.testMutatingInputOperandCounts());
    EXPECT_TRUE(spaceDepthTest.testMutatingOutputOperandCode());
    EXPECT_TRUE(spaceDepthTest.testMutatingOutputOperandCounts());

    ANeuralNetworksOperandType layout = {.type = ANEURALNETWORKS_BOOL,
                                         .dimensionCount = 0,
                                         .dimensions = nullptr,
                                         .scale = 0.0f,
                                         .zeroPoint = 0};
    OperationTestBase spaceDepthNchwTest(operationCode, {input, block_size, layout}, {output});
    EXPECT_TRUE(spaceDepthNchwTest.testMutatingInputOperandCode());
    EXPECT_TRUE(spaceDepthNchwTest.testMutatingInputOperandCounts());
    EXPECT_TRUE(spaceDepthNchwTest.testMutatingOutputOperandCode());
    EXPECT_TRUE(spaceDepthNchwTest.testMutatingOutputOperandCounts());
}

TEST(OperationValidationTest, SPACE_TO_DEPTH_float32) {
    spaceDepthOpTest(ANEURALNETWORKS_SPACE_TO_DEPTH, ANEURALNETWORKS_TENSOR_FLOAT32);
}

TEST(OperationValidationTest, DEPTH_TO_SPACE_float32) {
    spaceDepthOpTest(ANEURALNETWORKS_DEPTH_TO_SPACE, ANEURALNETWORKS_TENSOR_FLOAT32);
}

TEST(OperationValidationTest, SPACE_TO_DEPTH_quant8) {
    spaceDepthOpTest(ANEURALNETWORKS_SPACE_TO_DEPTH, ANEURALNETWORKS_TENSOR_QUANT8_ASYMM);
}

TEST(OperationValidationTest, DEPTH_TO_SPACE_quant8) {
    spaceDepthOpTest(ANEURALNETWORKS_DEPTH_TO_SPACE, ANEURALNETWORKS_TENSOR_QUANT8_ASYMM);
}

void spaceBatchOpTest(ANeuralNetworksOperationType operationCode, int32_t operandCode) {
    uint32_t inputDimensions[4] = {2, 2, 2, 2};
    ANeuralNetworksOperandType input = {.type = operandCode,
                                        .dimensionCount = 4,
                                        .dimensions = inputDimensions,
                                        .scale = 0.0f,
                                        .zeroPoint = 0};
    if (operandCode == ANEURALNETWORKS_TENSOR_QUANT8_ASYMM) {
        input.scale = 1.f / 256;
    }

    uint32_t blockDimensions[1] = {2};
    ANeuralNetworksOperandType blockShape = {.type = ANEURALNETWORKS_TENSOR_INT32,
                                             .dimensionCount = 1,
                                             .dimensions = blockDimensions,
                                             .scale = 0.0f,
                                             .zeroPoint = 0};
    ANeuralNetworksOperandType layout = {.type = ANEURALNETWORKS_BOOL,
                                         .dimensionCount = 0,
                                         .dimensions = nullptr,
                                         .scale = 0.0f,
                                         .zeroPoint = 0};

    ANeuralNetworksOperandType padding = blockShape;
    ANeuralNetworksOperandType output = input;
    if (operationCode == ANEURALNETWORKS_SPACE_TO_BATCH_ND) {
        OperationTestBase spaceBatchTest(operationCode, {input, blockShape, padding}, {output});
        EXPECT_TRUE(spaceBatchTest.testMutatingInputOperandCode());
        EXPECT_TRUE(spaceBatchTest.testMutatingInputOperandCounts());
        EXPECT_TRUE(spaceBatchTest.testMutatingOutputOperandCode());
        EXPECT_TRUE(spaceBatchTest.testMutatingOutputOperandCounts());

        OperationTestBase spaceBatchNchwTest(operationCode, {input, blockShape, padding, layout},
                                             {output});
        EXPECT_TRUE(spaceBatchNchwTest.testMutatingInputOperandCode());
        EXPECT_TRUE(spaceBatchNchwTest.testMutatingInputOperandCounts());
        EXPECT_TRUE(spaceBatchNchwTest.testMutatingOutputOperandCode());
        EXPECT_TRUE(spaceBatchNchwTest.testMutatingOutputOperandCounts());
    } else {
        OperationTestBase spaceBatchTest(operationCode, {input, blockShape}, {output});
        EXPECT_TRUE(spaceBatchTest.testMutatingInputOperandCode());
        EXPECT_TRUE(spaceBatchTest.testMutatingInputOperandCounts());
        EXPECT_TRUE(spaceBatchTest.testMutatingOutputOperandCode());
        EXPECT_TRUE(spaceBatchTest.testMutatingOutputOperandCounts());

        OperationTestBase spaceBatchNchwTest(operationCode, {input, blockShape, layout}, {output});
        EXPECT_TRUE(spaceBatchNchwTest.testMutatingInputOperandCode());
        EXPECT_TRUE(spaceBatchNchwTest.testMutatingInputOperandCounts());
        EXPECT_TRUE(spaceBatchNchwTest.testMutatingOutputOperandCode());
        EXPECT_TRUE(spaceBatchNchwTest.testMutatingOutputOperandCounts());
    }
}

TEST(OperationValidationTest, SPACE_TO_BATCH_ND_float32) {
    spaceBatchOpTest(ANEURALNETWORKS_SPACE_TO_BATCH_ND, ANEURALNETWORKS_TENSOR_FLOAT32);
}

TEST(OperationValidationTest, BATCH_TO_SPACE_ND_float32) {
    spaceBatchOpTest(ANEURALNETWORKS_BATCH_TO_SPACE_ND, ANEURALNETWORKS_TENSOR_FLOAT32);
}

TEST(OperationValidationTest, SPACE_TO_BATCH_ND_quant8) {
    spaceBatchOpTest(ANEURALNETWORKS_SPACE_TO_BATCH_ND, ANEURALNETWORKS_TENSOR_QUANT8_ASYMM);
}

TEST(OperationValidationTest, BATCH_TO_SPACE_ND_quant8) {
    spaceBatchOpTest(ANEURALNETWORKS_BATCH_TO_SPACE_ND, ANEURALNETWORKS_TENSOR_QUANT8_ASYMM);
}

void transposeAndSqueezeOpTest(ANeuralNetworksOperationType operationCode, int32_t operandCode) {
    uint32_t inputDimensions[4] = {2, 2, 2, 2};
    ANeuralNetworksOperandType input = {.type = operandCode,
                                        .dimensionCount = 4,
                                        .dimensions = inputDimensions,
                                        .scale = 0.0f,
                                        .zeroPoint = 0};
    if (operandCode == ANEURALNETWORKS_TENSOR_QUANT8_ASYMM) {
        input.scale = 1.f / 256;
    }

    uint32_t blockDimensions[1] = {4};
    ANeuralNetworksOperandType dims = {.type = ANEURALNETWORKS_TENSOR_INT32,
                                       .dimensionCount = 1,
                                       .dimensions = blockDimensions,
                                       .scale = 0.0f,
                                       .zeroPoint = 0};

    ANeuralNetworksOperandType output = input;
    OperationTestBase transposeAndSqueezeTest(operationCode, {input, dims}, {output});

    EXPECT_TRUE(transposeAndSqueezeTest.testMutatingInputOperandCode());
    EXPECT_TRUE(transposeAndSqueezeTest.testMutatingInputOperandCounts());
    EXPECT_TRUE(transposeAndSqueezeTest.testMutatingOutputOperandCode());
    EXPECT_TRUE(transposeAndSqueezeTest.testMutatingOutputOperandCounts());
}

TEST(OperationValidationTest, TRANSPOSE_float32) {
    transposeAndSqueezeOpTest(ANEURALNETWORKS_TRANSPOSE, ANEURALNETWORKS_TENSOR_FLOAT32);
}

TEST(OperationValidationTest, SQUEEZE_float32) {
    transposeAndSqueezeOpTest(ANEURALNETWORKS_SQUEEZE, ANEURALNETWORKS_TENSOR_FLOAT32);
}

TEST(OperationValidationTest, TRANSPOSE_quant8) {
    transposeAndSqueezeOpTest(ANEURALNETWORKS_TRANSPOSE, ANEURALNETWORKS_TENSOR_QUANT8_ASYMM);
}

TEST(OperationValidationTest, SQUEEZE_quant8) {
    transposeAndSqueezeOpTest(ANEURALNETWORKS_SQUEEZE, ANEURALNETWORKS_TENSOR_QUANT8_ASYMM);
}

void convOpTest(int32_t inputOperandCode, int32_t filterOperandCode) {
    uint32_t inputDimensions[4] = {2, 4, 4, 2};
    ANeuralNetworksOperandType input = {.type = inputOperandCode,
                                        .dimensionCount = 4,
                                        .dimensions = inputDimensions,
                                        .scale = 0.0f,
                                        .zeroPoint = 0};
    if (inputOperandCode == ANEURALNETWORKS_TENSOR_QUANT8_ASYMM) {
        input.scale = 0.5f;
    }
    ANeuralNetworksOperandType output = input;

    float filterScales[2] = {0.5f, 1.0f};
    ANeuralNetworksOperandType filter = {.type = filterOperandCode,
                                         .dimensionCount = 4,
                                         .dimensions = inputDimensions,
                                         .scale = 0.0f,
                                         .zeroPoint = 0};
    if (filterOperandCode == ANEURALNETWORKS_TENSOR_QUANT8_ASYMM) {
        filter.scale = 0.5f;
    }
    ANeuralNetworksSymmPerChannelQuantParams filterChannelQuantParams = {
            .channelDim = 0,
            .scaleCount = 2,
            .scales = filterScales,
    };

    uint32_t biasDimensions[1] = {2};
    ANeuralNetworksOperandType bias = {.type = inputOperandCode,
                                       .dimensionCount = 1,
                                       .dimensions = biasDimensions,
                                       .scale = 0.0f,
                                       .zeroPoint = 0};
    if (filterOperandCode == ANEURALNETWORKS_TENSOR_QUANT8_ASYMM) {
        bias.type = ANEURALNETWORKS_TENSOR_INT32;
        bias.scale = 0.25f;
    }
    if (filterOperandCode == ANEURALNETWORKS_TENSOR_QUANT8_SYMM_PER_CHANNEL) {
        bias.type = ANEURALNETWORKS_TENSOR_INT32;
        bias.scale = 0.0f;
    }

    ANeuralNetworksOperandType scalar = {.type = ANEURALNETWORKS_INT32,
                                         .dimensionCount = 0,
                                         .dimensions = nullptr,
                                         .scale = 0.0f,
                                         .zeroPoint = 0};
    ANeuralNetworksOperandType padLeft = scalar;
    ANeuralNetworksOperandType padRight = scalar;
    ANeuralNetworksOperandType padTop = scalar;
    ANeuralNetworksOperandType padBottom = scalar;
    ANeuralNetworksOperandType strideWidth = scalar;
    ANeuralNetworksOperandType strideHeight = scalar;
    ANeuralNetworksOperandType dilationHeightFactor = scalar;
    ANeuralNetworksOperandType dilationWidthFactor = scalar;
    ANeuralNetworksOperandType activation = scalar;

    OperationTestBase explicitConvTest(ANEURALNETWORKS_CONV_2D,
                                       {input, filter, bias, padLeft, padRight, padTop, padBottom,
                                        strideWidth, strideHeight, activation},
                                       {output});
    if (filterOperandCode == ANEURALNETWORKS_TENSOR_QUANT8_SYMM_PER_CHANNEL) {
        explicitConvTest.setInputSymmPerChannelQuantParams(1, filterChannelQuantParams);
    }

    EXPECT_TRUE(explicitConvTest.testMutatingInputOperandCode());
    EXPECT_TRUE(explicitConvTest.testMutatingInputOperandCounts());
    EXPECT_TRUE(explicitConvTest.testMutatingOutputOperandCode());
    EXPECT_TRUE(explicitConvTest.testMutatingOutputOperandCounts());

    ANeuralNetworksOperandType padImplicit = scalar;
    OperationTestBase implicitConvTest(
            ANEURALNETWORKS_CONV_2D,
            {input, filter, bias, padImplicit, strideWidth, strideHeight, activation}, {output});
    if (filterOperandCode == ANEURALNETWORKS_TENSOR_QUANT8_SYMM_PER_CHANNEL) {
        implicitConvTest.setInputSymmPerChannelQuantParams(1, filterChannelQuantParams);
    }

    EXPECT_TRUE(implicitConvTest.testMutatingInputOperandCode());
    EXPECT_TRUE(implicitConvTest.testMutatingInputOperandCounts());
    EXPECT_TRUE(implicitConvTest.testMutatingOutputOperandCode());
    EXPECT_TRUE(implicitConvTest.testMutatingOutputOperandCounts());

    ANeuralNetworksOperandType layout = {.type = ANEURALNETWORKS_BOOL,
                                         .dimensionCount = 0,
                                         .dimensions = nullptr,
                                         .scale = 0.0f,
                                         .zeroPoint = 0};

    OperationTestBase explicitNchwConvTest(
            ANEURALNETWORKS_CONV_2D,
            {input, filter, bias, padLeft, padRight, padTop, padBottom, strideWidth, strideHeight,
             activation, layout},
            {output});
    if (filterOperandCode == ANEURALNETWORKS_TENSOR_QUANT8_SYMM_PER_CHANNEL) {
        explicitNchwConvTest.setInputSymmPerChannelQuantParams(1, filterChannelQuantParams);
    }

    EXPECT_TRUE(explicitNchwConvTest.testMutatingInputOperandCode());
    EXPECT_TRUE(explicitNchwConvTest.testMutatingInputOperandCounts());
    EXPECT_TRUE(explicitNchwConvTest.testMutatingOutputOperandCode());
    EXPECT_TRUE(explicitNchwConvTest.testMutatingOutputOperandCounts());

    OperationTestBase implicitNchwConvTest(
            ANEURALNETWORKS_CONV_2D,
            {input, filter, bias, padImplicit, strideWidth, strideHeight, activation, layout},
            {output});
    if (filterOperandCode == ANEURALNETWORKS_TENSOR_QUANT8_SYMM_PER_CHANNEL) {
        implicitNchwConvTest.setInputSymmPerChannelQuantParams(1, filterChannelQuantParams);
    }

    EXPECT_TRUE(implicitNchwConvTest.testMutatingInputOperandCode());
    EXPECT_TRUE(implicitNchwConvTest.testMutatingInputOperandCounts());
    EXPECT_TRUE(implicitNchwConvTest.testMutatingOutputOperandCode());
    EXPECT_TRUE(implicitNchwConvTest.testMutatingOutputOperandCounts());

    OperationTestBase explicitDilateConvTest(
            ANEURALNETWORKS_CONV_2D,
            {input, filter, bias, padLeft, padRight, padTop, padBottom, strideWidth, strideHeight,
             activation, layout, dilationWidthFactor, dilationHeightFactor},
            {output});
    if (filterOperandCode == ANEURALNETWORKS_TENSOR_QUANT8_SYMM_PER_CHANNEL) {
        explicitDilateConvTest.setInputSymmPerChannelQuantParams(1, filterChannelQuantParams);
    }

    EXPECT_TRUE(explicitDilateConvTest.testMutatingInputOperandCode());
    EXPECT_TRUE(explicitDilateConvTest.testMutatingInputOperandCounts());
    EXPECT_TRUE(explicitDilateConvTest.testMutatingOutputOperandCode());
    EXPECT_TRUE(explicitDilateConvTest.testMutatingOutputOperandCounts());

    OperationTestBase implicitDilateConvTest(
            ANEURALNETWORKS_CONV_2D,
            {input, filter, bias, padImplicit, strideWidth, strideHeight, activation, layout,
             dilationWidthFactor, dilationHeightFactor},
            {output});
    if (filterOperandCode == ANEURALNETWORKS_TENSOR_QUANT8_SYMM_PER_CHANNEL) {
        implicitDilateConvTest.setInputSymmPerChannelQuantParams(1, filterChannelQuantParams);
    }

    EXPECT_TRUE(implicitDilateConvTest.testMutatingInputOperandCode());
    EXPECT_TRUE(implicitDilateConvTest.testMutatingInputOperandCounts());
    EXPECT_TRUE(implicitDilateConvTest.testMutatingOutputOperandCode());
    EXPECT_TRUE(implicitDilateConvTest.testMutatingOutputOperandCounts());
}

TEST(OperationValidationTest, CONV_2D_float32) {
    convOpTest(ANEURALNETWORKS_TENSOR_FLOAT32, ANEURALNETWORKS_TENSOR_FLOAT32);
}

TEST(OperationValidationTest, CONV_2D_quant8) {
    convOpTest(ANEURALNETWORKS_TENSOR_QUANT8_ASYMM, ANEURALNETWORKS_TENSOR_QUANT8_ASYMM);
}

TEST(OperationValidationTest, CONV_2D_quant8_per_channel) {
    convOpTest(ANEURALNETWORKS_TENSOR_QUANT8_ASYMM, ANEURALNETWORKS_TENSOR_QUANT8_SYMM_PER_CHANNEL);
}

void depthwiseConvOpTest(int32_t inputOperandCode, int32_t filterOperandCode) {
    uint32_t inputDimensions[4] = {1, 2, 2, 2};
    ANeuralNetworksOperandType input = {.type = inputOperandCode,
                                        .dimensionCount = 4,
                                        .dimensions = inputDimensions,
                                        .scale = 0.0f,
                                        .zeroPoint = 0};
    if (inputOperandCode == ANEURALNETWORKS_TENSOR_QUANT8_ASYMM) {
        input.scale = 0.5f;
    }
    ANeuralNetworksOperandType output = input;

    float filterScales[2] = {0.5f, 1.0f};
    ANeuralNetworksOperandType filter = {.type = filterOperandCode,
                                         .dimensionCount = 4,
                                         .dimensions = inputDimensions,
                                         .scale = 0.0f,
                                         .zeroPoint = 0};
    if (filterOperandCode == ANEURALNETWORKS_TENSOR_QUANT8_ASYMM) {
        filter.scale = 0.5f;
    }
    ANeuralNetworksSymmPerChannelQuantParams filterChannelQuantParams = {
            .channelDim = 3,
            .scaleCount = 2,
            .scales = filterScales,
    };

    uint32_t biasDimensions[1] = {2};
    ANeuralNetworksOperandType bias = {.type = inputOperandCode,
                                       .dimensionCount = 1,
                                       .dimensions = biasDimensions,
                                       .scale = 0.0f,
                                       .zeroPoint = 0};
    if (filterOperandCode == ANEURALNETWORKS_TENSOR_QUANT8_ASYMM) {
        bias.type = ANEURALNETWORKS_TENSOR_INT32;
        bias.scale = 0.25f;
    }
    if (filterOperandCode == ANEURALNETWORKS_TENSOR_QUANT8_SYMM_PER_CHANNEL) {
        bias.type = ANEURALNETWORKS_TENSOR_INT32;
        bias.scale = 0.0f;
    }

    ANeuralNetworksOperandType scalar = {.type = ANEURALNETWORKS_INT32,
                                         .dimensionCount = 0,
                                         .dimensions = nullptr,
                                         .scale = 0.0f,
                                         .zeroPoint = 0};
    ANeuralNetworksOperandType padLeft = scalar;
    ANeuralNetworksOperandType padRight = scalar;
    ANeuralNetworksOperandType padTop = scalar;
    ANeuralNetworksOperandType padBottom = scalar;
    ANeuralNetworksOperandType strideWidth = scalar;
    ANeuralNetworksOperandType strideHeight = scalar;
    ANeuralNetworksOperandType multiplier = scalar;
    ANeuralNetworksOperandType activation = scalar;

    OperationTestBase explicitDepthwiseConvTest(
            ANEURALNETWORKS_DEPTHWISE_CONV_2D,
            {input, filter, bias, padLeft, padRight, padTop, padBottom, strideWidth, strideHeight,
             multiplier, activation},
            {output});
    if (filterOperandCode == ANEURALNETWORKS_TENSOR_QUANT8_SYMM_PER_CHANNEL) {
        explicitDepthwiseConvTest.setInputSymmPerChannelQuantParams(1, filterChannelQuantParams);
    }

    EXPECT_TRUE(explicitDepthwiseConvTest.testMutatingInputOperandCode());
    EXPECT_TRUE(explicitDepthwiseConvTest.testMutatingInputOperandCounts());
    EXPECT_TRUE(explicitDepthwiseConvTest.testMutatingOutputOperandCode());
    EXPECT_TRUE(explicitDepthwiseConvTest.testMutatingOutputOperandCounts());

    ANeuralNetworksOperandType padImplicit = scalar;
    OperationTestBase implicitDepthwiseConvTest(
            ANEURALNETWORKS_DEPTHWISE_CONV_2D,
            {input, filter, bias, padImplicit, strideWidth, strideHeight, multiplier, activation},
            {output});
    if (filterOperandCode == ANEURALNETWORKS_TENSOR_QUANT8_SYMM_PER_CHANNEL) {
        implicitDepthwiseConvTest.setInputSymmPerChannelQuantParams(1, filterChannelQuantParams);
    }

    EXPECT_TRUE(implicitDepthwiseConvTest.testMutatingInputOperandCode());
    EXPECT_TRUE(implicitDepthwiseConvTest.testMutatingInputOperandCounts());
    EXPECT_TRUE(implicitDepthwiseConvTest.testMutatingOutputOperandCode());
    EXPECT_TRUE(implicitDepthwiseConvTest.testMutatingOutputOperandCounts());

    ANeuralNetworksOperandType layout = {.type = ANEURALNETWORKS_BOOL,
                                         .dimensionCount = 0,
                                         .dimensions = nullptr,
                                         .scale = 0.0f,
                                         .zeroPoint = 0};

    OperationTestBase explicitNchwDepthwiseConvTest(
            ANEURALNETWORKS_DEPTHWISE_CONV_2D,
            {input, filter, bias, padLeft, padRight, padTop, padBottom, strideWidth, strideHeight,
             multiplier, activation, layout},
            {output});
    if (filterOperandCode == ANEURALNETWORKS_TENSOR_QUANT8_SYMM_PER_CHANNEL) {
        explicitNchwDepthwiseConvTest.setInputSymmPerChannelQuantParams(1,
                                                                        filterChannelQuantParams);
    }

    EXPECT_TRUE(explicitNchwDepthwiseConvTest.testMutatingInputOperandCode());
    EXPECT_TRUE(explicitNchwDepthwiseConvTest.testMutatingInputOperandCounts());
    EXPECT_TRUE(explicitNchwDepthwiseConvTest.testMutatingOutputOperandCode());
    EXPECT_TRUE(explicitNchwDepthwiseConvTest.testMutatingOutputOperandCounts());

    OperationTestBase implicitNchwDepthwiseConvTest(ANEURALNETWORKS_DEPTHWISE_CONV_2D,
                                                    {input, filter, bias, padImplicit, strideWidth,
                                                     strideHeight, multiplier, activation, layout},
                                                    {output});
    if (filterOperandCode == ANEURALNETWORKS_TENSOR_QUANT8_SYMM_PER_CHANNEL) {
        implicitNchwDepthwiseConvTest.setInputSymmPerChannelQuantParams(1,
                                                                        filterChannelQuantParams);
    }

    EXPECT_TRUE(implicitNchwDepthwiseConvTest.testMutatingInputOperandCode());
    EXPECT_TRUE(implicitNchwDepthwiseConvTest.testMutatingInputOperandCounts());
    EXPECT_TRUE(implicitNchwDepthwiseConvTest.testMutatingOutputOperandCode());
    EXPECT_TRUE(implicitNchwDepthwiseConvTest.testMutatingOutputOperandCounts());

    ANeuralNetworksOperandType dilationHeightFactor = scalar;
    ANeuralNetworksOperandType dilationWidthFactor = scalar;

    OperationTestBase explicitDilationDepthwiseConvTest(
            ANEURALNETWORKS_DEPTHWISE_CONV_2D,
            {input, filter, bias, padLeft, padRight, padTop, padBottom, strideWidth, strideHeight,
             multiplier, activation, layout, dilationWidthFactor, dilationHeightFactor},
            {output});

    EXPECT_TRUE(explicitDilationDepthwiseConvTest.testMutatingInputOperandCode());
    EXPECT_TRUE(explicitDilationDepthwiseConvTest.testMutatingInputOperandCounts());
    EXPECT_TRUE(explicitDilationDepthwiseConvTest.testMutatingOutputOperandCode());
    EXPECT_TRUE(explicitDilationDepthwiseConvTest.testMutatingOutputOperandCounts());

    OperationTestBase implicitDilationDepthwiseConvTest(
            ANEURALNETWORKS_DEPTHWISE_CONV_2D,
            {input, filter, bias, padImplicit, strideWidth, strideHeight, multiplier, activation,
             layout, dilationWidthFactor, dilationHeightFactor},
            {output});

    EXPECT_TRUE(implicitDilationDepthwiseConvTest.testMutatingInputOperandCode());
    EXPECT_TRUE(implicitDilationDepthwiseConvTest.testMutatingInputOperandCounts());
    EXPECT_TRUE(implicitDilationDepthwiseConvTest.testMutatingOutputOperandCode());
    EXPECT_TRUE(implicitDilationDepthwiseConvTest.testMutatingOutputOperandCounts());
}

TEST(OperationValidationTest, DEPTHWISE_CONV_2D_float32) {
    depthwiseConvOpTest(ANEURALNETWORKS_TENSOR_FLOAT32, ANEURALNETWORKS_TENSOR_FLOAT32);
}

TEST(OperationValidationTest, DEPTHWISE_CONV_2D_float16) {
    depthwiseConvOpTest(ANEURALNETWORKS_TENSOR_FLOAT16, ANEURALNETWORKS_TENSOR_FLOAT16);
}

TEST(OperationValidationTest, DEPTHWISE_CONV_2D_quant8) {
    depthwiseConvOpTest(ANEURALNETWORKS_TENSOR_QUANT8_ASYMM, ANEURALNETWORKS_TENSOR_QUANT8_ASYMM);
}

TEST(OperationValidationTest, DEPTHWISE_CONV_2D_quant8_per_channel) {
    depthwiseConvOpTest(ANEURALNETWORKS_TENSOR_QUANT8_ASYMM,
                        ANEURALNETWORKS_TENSOR_QUANT8_SYMM_PER_CHANNEL);
}

void fullyConnectedOpTest(int32_t operandCode) {
    uint32_t inputDimensions[2] = {5, 5};
    ANeuralNetworksOperandType input = {.type = operandCode,
                                        .dimensionCount = 2,
                                        .dimensions = inputDimensions,
                                        .scale = 0.0f,
                                        .zeroPoint = 0};
    if (operandCode == ANEURALNETWORKS_TENSOR_QUANT8_ASYMM) {
        input.scale = 0.5f;
    }

    ANeuralNetworksOperandType weights = input;
    ANeuralNetworksOperandType output = input;

    uint32_t biasDimensions[1] = {5};
    ANeuralNetworksOperandType bias = {.type = operandCode,
                                       .dimensionCount = 1,
                                       .dimensions = biasDimensions,
                                       .scale = 0.0f,
                                       .zeroPoint = 0};
    if (operandCode == ANEURALNETWORKS_TENSOR_QUANT8_ASYMM) {
        bias.type = ANEURALNETWORKS_TENSOR_INT32;
        bias.scale = 0.25f;
    }

    ANeuralNetworksOperandType activation = {.type = ANEURALNETWORKS_INT32,
                                             .dimensionCount = 0,
                                             .dimensions = nullptr,
                                             .scale = 0.0f,
                                             .zeroPoint = 0};

    OperationTestBase fullyConnectedTest(ANEURALNETWORKS_FULLY_CONNECTED,
                                         {input, weights, bias, activation}, {output});

    EXPECT_TRUE(fullyConnectedTest.testMutatingInputOperandCode());
    EXPECT_TRUE(fullyConnectedTest.testMutatingInputOperandCounts());
    EXPECT_TRUE(fullyConnectedTest.testMutatingOutputOperandCode());
    EXPECT_TRUE(fullyConnectedTest.testMutatingOutputOperandCounts());
}

TEST(OperationValidationTest, FULLY_CONNECTED_float16) {
    fullyConnectedOpTest(ANEURALNETWORKS_TENSOR_FLOAT16);
}

TEST(OperationValidationTest, FULLY_CONNECTED_float32) {
    fullyConnectedOpTest(ANEURALNETWORKS_TENSOR_FLOAT32);
}

TEST(OperationValidationTest, FULLY_CONNECTED_quant8) {
    fullyConnectedOpTest(ANEURALNETWORKS_TENSOR_QUANT8_ASYMM);
}

void concatenationTest(int32_t operandCode) {
    uint32_t inputDimensions[2] = {5, 5};
    ANeuralNetworksOperandType input1 = {.type = operandCode,
                                         .dimensionCount = 2,
                                         .dimensions = inputDimensions,
                                         .scale = 0.0f,
                                         .zeroPoint = 0};
    if (operandCode == ANEURALNETWORKS_TENSOR_QUANT8_ASYMM) {
        input1.scale = 0.5f;
    }
    ANeuralNetworksOperandType input2 = input1;
    ANeuralNetworksOperandType output = input1;

    ANeuralNetworksOperandType activation = {.type = ANEURALNETWORKS_INT32,
                                             .dimensionCount = 0,
                                             .dimensions = nullptr,
                                             .scale = 0.0f,
                                             .zeroPoint = 0};

    OperationTestBase concat2Test(ANEURALNETWORKS_CONCATENATION, {input1, input2, activation},
                                  {output});

    EXPECT_TRUE(concat2Test.testMutatingInputOperandCode());
    EXPECT_TRUE(concat2Test.testMutatingOutputOperandCode());
    EXPECT_TRUE(concat2Test.testMutatingOutputOperandCounts());

    OperationTestBase concat1Test(ANEURALNETWORKS_CONCATENATION, {input1, activation}, {output});

    EXPECT_TRUE(concat1Test.testMutatingInputOperandCode());
    EXPECT_TRUE(concat1Test.testMutatingOutputOperandCode());
    EXPECT_TRUE(concat1Test.testMutatingOutputOperandCounts());
}

TEST(OperationValidationTest, CONCATENATION_float32) {
    concatenationTest(ANEURALNETWORKS_TENSOR_FLOAT32);
}

TEST(OperationValidationTest, CONCATENATION_quant8) {
    concatenationTest(ANEURALNETWORKS_TENSOR_QUANT8_ASYMM);
}

TEST(OperationValidationTest, RESIZE_BILINEAR_float32) {
    uint32_t inputDimensions[4] = {2, 2, 2, 2};
    ANeuralNetworksOperandType input = {.type = ANEURALNETWORKS_TENSOR_FLOAT32,
                                        .dimensionCount = 4,
                                        .dimensions = inputDimensions,
                                        .scale = 0.0f,
                                        .zeroPoint = 0};
    ANeuralNetworksOperandType height = {.type = ANEURALNETWORKS_INT32,
                                         .dimensionCount = 0,
                                         .dimensions = nullptr,
                                         .scale = 0.0f,
                                         .zeroPoint = 0};
    ANeuralNetworksOperandType width = height;
    ANeuralNetworksOperandType output = input;

    OperationTestBase resizeTest(ANEURALNETWORKS_RESIZE_BILINEAR, {input, height, width}, {output});
    EXPECT_TRUE(resizeTest.testMutatingInputOperandCode());
    EXPECT_TRUE(resizeTest.testMutatingInputOperandCounts());
    EXPECT_TRUE(resizeTest.testMutatingOutputOperandCode());
    EXPECT_TRUE(resizeTest.testMutatingOutputOperandCounts());

    ANeuralNetworksOperandType layout = {.type = ANEURALNETWORKS_BOOL,
                                         .dimensionCount = 0,
                                         .dimensions = nullptr,
                                         .scale = 0.0f,
                                         .zeroPoint = 0};
    OperationTestBase resizeNchwTest(ANEURALNETWORKS_RESIZE_BILINEAR,
                                     {input, height, width, layout}, {output});
    EXPECT_TRUE(resizeNchwTest.testMutatingInputOperandCode());
    EXPECT_TRUE(resizeNchwTest.testMutatingInputOperandCounts());
    EXPECT_TRUE(resizeNchwTest.testMutatingOutputOperandCode());
    EXPECT_TRUE(resizeNchwTest.testMutatingOutputOperandCounts());
}

void embeddingLookupTest(int32_t operandCode) {
    uint32_t lookupDimensions[1] = {5};
    ANeuralNetworksOperandType lookup = {.type = ANEURALNETWORKS_TENSOR_INT32,
                                         .dimensionCount = 1,
                                         .dimensions = lookupDimensions,
                                         .scale = 0.0f,
                                         .zeroPoint = 0};

    uint32_t inputDimensions[2] = {5, 5};
    ANeuralNetworksOperandType input = {.type = operandCode,
                                        .dimensionCount = 2,
                                        .dimensions = inputDimensions,
                                        .scale = 0.0f,
                                        .zeroPoint = 0};
    if (operandCode == ANEURALNETWORKS_TENSOR_QUANT8_ASYMM) {
        input.scale = 0.5f;
    }
    ANeuralNetworksOperandType output = input;

    OperationTestBase embedLookupTest(ANEURALNETWORKS_EMBEDDING_LOOKUP, {lookup, input}, {output});

    EXPECT_TRUE(embedLookupTest.testMutatingInputOperandCode());
    EXPECT_TRUE(embedLookupTest.testMutatingInputOperandCounts());
    EXPECT_TRUE(embedLookupTest.testMutatingOutputOperandCode());
    EXPECT_TRUE(embedLookupTest.testMutatingOutputOperandCounts());
}

TEST(OperationValidationTest, EMBEDDING_LOOKUP_float32) {
    embeddingLookupTest(ANEURALNETWORKS_TENSOR_FLOAT32);
}

TEST(OperationValidationTest, EMBEDDING_LOOKUP_quant8) {
    embeddingLookupTest(ANEURALNETWORKS_TENSOR_QUANT8_ASYMM);
}

void hashtableLookupTest(int32_t operandCode) {
    uint32_t lookupDimensions[1] = {5};
    ANeuralNetworksOperandType lookup = {.type = ANEURALNETWORKS_TENSOR_INT32,
                                         .dimensionCount = 1,
                                         .dimensions = lookupDimensions,
                                         .scale = 0.0f,
                                         .zeroPoint = 0};
    ANeuralNetworksOperandType keys = lookup;

    uint32_t valuesDimensions[2] = {5, 5};
    ANeuralNetworksOperandType values = {.type = operandCode,
                                         .dimensionCount = 2,
                                         .dimensions = valuesDimensions,
                                         .scale = 0.0f,
                                         .zeroPoint = 0};
    if (operandCode == ANEURALNETWORKS_TENSOR_QUANT8_ASYMM) {
        values.scale = 0.5f;
    }
    ANeuralNetworksOperandType output = values;

    ANeuralNetworksOperandType hits = lookup;
    hits.type = ANEURALNETWORKS_TENSOR_QUANT8_ASYMM;
    hits.scale = 1.0f;

    OperationTestBase hashLookupTest(ANEURALNETWORKS_HASHTABLE_LOOKUP, {lookup, keys, values},
                                     {output, hits});

    EXPECT_TRUE(hashLookupTest.testMutatingInputOperandCode());
    EXPECT_TRUE(hashLookupTest.testMutatingInputOperandCounts());
    EXPECT_TRUE(hashLookupTest.testMutatingOutputOperandCode());
    EXPECT_TRUE(hashLookupTest.testMutatingOutputOperandCounts());
}

TEST(OperationValidationTest, HASHTABLE_LOOKUP_float32) {
    hashtableLookupTest(ANEURALNETWORKS_TENSOR_FLOAT32);
}

TEST(OperationValidationTest, HASHTABLE_LOOKUP_quant8) {
    hashtableLookupTest(ANEURALNETWORKS_TENSOR_QUANT8_ASYMM);
}

void lshProjectionTest(int32_t operandCode, int32_t hashAndWeightOperandCode) {
    uint32_t inputDimensions[2] = {5, 5};
    ANeuralNetworksOperandType hash = {.type = hashAndWeightOperandCode,
                                       .dimensionCount = 2,
                                       .dimensions = inputDimensions,
                                       .scale = 0.0f,
                                       .zeroPoint = 0};

    ANeuralNetworksOperandType input = hash;
    input.type = operandCode;
    if (operandCode == ANEURALNETWORKS_TENSOR_QUANT8_ASYMM) {
        input.scale = 0.5f;
    }

    uint32_t weightDimensions[1] = {5};
    ANeuralNetworksOperandType weight = {.type = hashAndWeightOperandCode,
                                         .dimensionCount = 1,
                                         .dimensions = weightDimensions,
                                         .scale = 0.0f,
                                         .zeroPoint = 0};

    ANeuralNetworksOperandType type = {.type = ANEURALNETWORKS_INT32,
                                       .dimensionCount = 0,
                                       .dimensions = nullptr,
                                       .scale = 0.0f,
                                       .zeroPoint = 0};

    ANeuralNetworksOperandType output = weight;
    output.type = ANEURALNETWORKS_TENSOR_INT32;

    OperationTestBase lshProjTest(ANEURALNETWORKS_LSH_PROJECTION, {hash, input, weight, type},
                                  {output});

    EXPECT_TRUE(lshProjTest.testMutatingInputOperandCode());
    EXPECT_TRUE(lshProjTest.testMutatingInputOperandCounts());
    EXPECT_TRUE(lshProjTest.testMutatingOutputOperandCode());
    EXPECT_TRUE(lshProjTest.testMutatingOutputOperandCounts());
}

TEST(OperationValidationTest, LSH_PROJECTION_float16) {
    lshProjectionTest(ANEURALNETWORKS_TENSOR_FLOAT16, ANEURALNETWORKS_TENSOR_FLOAT32);
    lshProjectionTest(ANEURALNETWORKS_TENSOR_FLOAT16, ANEURALNETWORKS_TENSOR_FLOAT16);
}
TEST(OperationValidationTest, LSH_PROJECTION_float32) {
    lshProjectionTest(ANEURALNETWORKS_TENSOR_FLOAT32, ANEURALNETWORKS_TENSOR_FLOAT32);
    lshProjectionTest(ANEURALNETWORKS_TENSOR_FLOAT32, ANEURALNETWORKS_TENSOR_FLOAT16);
}

TEST(OperationValidationTest, LSH_PROJECTION_quant8) {
    lshProjectionTest(ANEURALNETWORKS_TENSOR_QUANT8_ASYMM, ANEURALNETWORKS_TENSOR_FLOAT32);
    lshProjectionTest(ANEURALNETWORKS_TENSOR_QUANT8_ASYMM, ANEURALNETWORKS_TENSOR_FLOAT16);
}

TEST(OperationValidationTest, LSTM_float32) {
    uint32_t oneDimensional[1] = {5};
    uint32_t twoDimensional[2] = {5, 5};
    ANeuralNetworksOperandType floatTensor1D = {.type = ANEURALNETWORKS_TENSOR_FLOAT32,
                                                .dimensionCount = 1,
                                                .dimensions = oneDimensional,
                                                .scale = 0.0f,
                                                .zeroPoint = 0};
    ANeuralNetworksOperandType floatTensor2D = {.type = ANEURALNETWORKS_TENSOR_FLOAT32,
                                                .dimensionCount = 2,
                                                .dimensions = twoDimensional,
                                                .scale = 0.0f,
                                                .zeroPoint = 0};
    ANeuralNetworksOperandType intScalar = {.type = ANEURALNETWORKS_INT32,
                                            .dimensionCount = 0,
                                            .dimensions = nullptr,
                                            .scale = 0.0f,
                                            .zeroPoint = 0};
    ANeuralNetworksOperandType floatScalar = {.type = ANEURALNETWORKS_FLOAT32,
                                              .dimensionCount = 0,
                                              .dimensions = nullptr,
                                              .scale = 0.0f,
                                              .zeroPoint = 0};

    ANeuralNetworksOperandType input = floatTensor2D;
    ANeuralNetworksOperandType inputToInput = floatTensor2D;
    ANeuralNetworksOperandType inputToForget = floatTensor2D;
    ANeuralNetworksOperandType inputToCell = floatTensor2D;
    ANeuralNetworksOperandType inputToOutput = floatTensor2D;
    ANeuralNetworksOperandType recurrentToInput = floatTensor2D;
    ANeuralNetworksOperandType recurrentToForget = floatTensor2D;
    ANeuralNetworksOperandType recurrentToCell = floatTensor2D;
    ANeuralNetworksOperandType recurrentToOutput = floatTensor2D;
    ANeuralNetworksOperandType cellToInput = floatTensor1D;
    ANeuralNetworksOperandType cellToForget = floatTensor1D;
    ANeuralNetworksOperandType cellToOutput = floatTensor1D;
    ANeuralNetworksOperandType inputGateBias = floatTensor1D;
    ANeuralNetworksOperandType forgetGateBias = floatTensor1D;
    ANeuralNetworksOperandType cellBias = floatTensor1D;
    ANeuralNetworksOperandType outputGateBias = floatTensor1D;
    ANeuralNetworksOperandType projWeights = floatTensor2D;
    ANeuralNetworksOperandType projBias = floatTensor1D;
    ANeuralNetworksOperandType outputStateIn = floatTensor2D;
    ANeuralNetworksOperandType cellStateIn = floatTensor2D;
    ANeuralNetworksOperandType activation = intScalar;
    ANeuralNetworksOperandType clipCellState = floatScalar;
    ANeuralNetworksOperandType clipProjLayer = floatScalar;

    ANeuralNetworksOperandType scratch = floatTensor2D;
    ANeuralNetworksOperandType outputStateOut = floatTensor2D;
    ANeuralNetworksOperandType cellStateOut = floatTensor2D;
    ANeuralNetworksOperandType output = floatTensor2D;

    OperationTestBase lstmTest(ANEURALNETWORKS_LSTM,
                               {input,
                                inputToInput,
                                inputToForget,
                                inputToCell,
                                inputToOutput,
                                recurrentToInput,
                                recurrentToForget,
                                recurrentToCell,
                                recurrentToOutput,
                                cellToInput,
                                cellToForget,
                                cellToOutput,
                                inputGateBias,
                                forgetGateBias,
                                cellBias,
                                outputGateBias,
                                projWeights,
                                projBias,
                                outputStateIn,
                                cellStateIn,
                                activation,
                                clipCellState,
                                clipProjLayer},
                               {scratch, outputStateOut, cellStateOut, output});

    EXPECT_TRUE(lstmTest.testMutatingInputOperandCode());
    EXPECT_TRUE(lstmTest.testMutatingInputOperandCounts(3));
    EXPECT_TRUE(lstmTest.testMutatingOutputOperandCode());
    EXPECT_TRUE(lstmTest.testMutatingOutputOperandCounts());
}

void lstmTestV1_2(int32_t operandCode) {
    uint32_t oneDimensional[1] = {5};
    uint32_t twoDimensional[2] = {5, 5};
    ANeuralNetworksOperandType floatTensor1D = {.type = operandCode,
                                                .dimensionCount = 1,
                                                .dimensions = oneDimensional,
                                                .scale = 0.0f,
                                                .zeroPoint = 0};
    ANeuralNetworksOperandType floatTensor2D = {.type = operandCode,
                                                .dimensionCount = 2,
                                                .dimensions = twoDimensional,
                                                .scale = 0.0f,
                                                .zeroPoint = 0};
    ANeuralNetworksOperandType intScalar = {.type = ANEURALNETWORKS_INT32,
                                            .dimensionCount = 0,
                                            .dimensions = nullptr,
                                            .scale = 0.0f,
                                            .zeroPoint = 0};
    ANeuralNetworksOperandType floatScalar = {.type = ANEURALNETWORKS_FLOAT32,
                                              .dimensionCount = 0,
                                              .dimensions = nullptr,
                                              .scale = 0.0f,
                                              .zeroPoint = 0};

    ANeuralNetworksOperandType input = floatTensor2D;
    ANeuralNetworksOperandType inputToInput = floatTensor2D;
    ANeuralNetworksOperandType inputToForget = floatTensor2D;
    ANeuralNetworksOperandType inputToCell = floatTensor2D;
    ANeuralNetworksOperandType inputToOutput = floatTensor2D;
    ANeuralNetworksOperandType recurrentToInput = floatTensor2D;
    ANeuralNetworksOperandType recurrentToForget = floatTensor2D;
    ANeuralNetworksOperandType recurrentToCell = floatTensor2D;
    ANeuralNetworksOperandType recurrentToOutput = floatTensor2D;
    ANeuralNetworksOperandType cellToInput = floatTensor1D;
    ANeuralNetworksOperandType cellToForget = floatTensor1D;
    ANeuralNetworksOperandType cellToOutput = floatTensor1D;
    ANeuralNetworksOperandType inputGateBias = floatTensor1D;
    ANeuralNetworksOperandType forgetGateBias = floatTensor1D;
    ANeuralNetworksOperandType cellBias = floatTensor1D;
    ANeuralNetworksOperandType outputGateBias = floatTensor1D;
    ANeuralNetworksOperandType projWeights = floatTensor2D;
    ANeuralNetworksOperandType projBias = floatTensor1D;
    ANeuralNetworksOperandType outputStateIn = floatTensor2D;
    ANeuralNetworksOperandType cellStateIn = floatTensor2D;
    ANeuralNetworksOperandType activation = intScalar;
    ANeuralNetworksOperandType clipCellState = floatScalar;
    ANeuralNetworksOperandType clipProjLayer = floatScalar;
    ANeuralNetworksOperandType inputLayerNormWeights = floatTensor1D;
    ANeuralNetworksOperandType forgetLayerNormWeights = floatTensor1D;
    ANeuralNetworksOperandType cellLayerNormWeights = floatTensor1D;
    ANeuralNetworksOperandType outputLayerNormWeights = floatTensor1D;

    ANeuralNetworksOperandType scratch = floatTensor2D;
    ANeuralNetworksOperandType outputStateOut = floatTensor2D;
    ANeuralNetworksOperandType cellStateOut = floatTensor2D;
    ANeuralNetworksOperandType output = floatTensor2D;

    OperationTestBase lstmTest(ANEURALNETWORKS_LSTM,
                               {input,
                                inputToInput,
                                inputToForget,
                                inputToCell,
                                inputToOutput,
                                recurrentToInput,
                                recurrentToForget,
                                recurrentToCell,
                                recurrentToOutput,
                                cellToInput,
                                cellToForget,
                                cellToOutput,
                                inputGateBias,
                                forgetGateBias,
                                cellBias,
                                outputGateBias,
                                projWeights,
                                projBias,
                                outputStateIn,
                                cellStateIn,
                                activation,
                                clipCellState,
                                clipProjLayer,
                                inputLayerNormWeights,
                                forgetLayerNormWeights,
                                cellLayerNormWeights,
                                outputLayerNormWeights},
                               {scratch, outputStateOut, cellStateOut, output});

    EXPECT_TRUE(lstmTest.testMutatingInputOperandCode());
    EXPECT_TRUE(lstmTest.testMutatingInputOperandCounts());
    EXPECT_TRUE(lstmTest.testMutatingOutputOperandCode());
    EXPECT_TRUE(lstmTest.testMutatingOutputOperandCounts());
}

TEST(OperationValidationTest, LSTM_V1_2) {
    lstmTestV1_2(ANEURALNETWORKS_TENSOR_FLOAT32);
    lstmTestV1_2(ANEURALNETWORKS_TENSOR_FLOAT16);
}

void lstmBidirectionalSequence(int32_t operandCode) {
    uint32_t oneDimensional[1] = {5};
    uint32_t twoDimensional[2] = {5, 5};
    uint32_t threeDimensional[3] = {5, 5, 5};
    ANeuralNetworksOperandType floatTensor1D = {
            .type = operandCode,
            .dimensionCount = 1,
            .dimensions = oneDimensional,
            .scale = 0.0f,
            .zeroPoint = 0,
    };
    ANeuralNetworksOperandType floatTensor2D = {
            .type = operandCode,
            .dimensionCount = 2,
            .dimensions = twoDimensional,
            .scale = 0.0f,
            .zeroPoint = 0,
    };
    ANeuralNetworksOperandType floatTensor3D = {
            .type = operandCode,
            .dimensionCount = 3,
            .dimensions = threeDimensional,
            .scale = 0.0f,
            .zeroPoint = 0,
    };
    ANeuralNetworksOperandType intScalar = {
            .type = ANEURALNETWORKS_INT32,
            .dimensionCount = 0,
            .dimensions = nullptr,
            .scale = 0.0f,
            .zeroPoint = 0,
    };
    ANeuralNetworksOperandType floatScalar = {
            .type = operandCode == ANEURALNETWORKS_TENSOR_FLOAT32 ? ANEURALNETWORKS_FLOAT32
                                                                  : ANEURALNETWORKS_FLOAT16,
            .dimensionCount = 0,
            .dimensions = nullptr,
            .scale = 0.0f,
            .zeroPoint = 0,
    };

    ANeuralNetworksOperandType input = floatTensor3D;
    ANeuralNetworksOperandType inputToInputFw = floatTensor2D;
    ANeuralNetworksOperandType inputToForgetFw = floatTensor2D;
    ANeuralNetworksOperandType inputToCellFw = floatTensor2D;
    ANeuralNetworksOperandType inputToOutputFw = floatTensor2D;
    ANeuralNetworksOperandType recurrentToInputFw = floatTensor2D;
    ANeuralNetworksOperandType recurrentToForgetFw = floatTensor2D;
    ANeuralNetworksOperandType recurrentToCellFw = floatTensor2D;
    ANeuralNetworksOperandType recurrentToOutputFw = floatTensor2D;
    ANeuralNetworksOperandType cellToInputFw = floatTensor1D;
    ANeuralNetworksOperandType cellToForgetFw = floatTensor1D;
    ANeuralNetworksOperandType cellToOutputFw = floatTensor1D;
    ANeuralNetworksOperandType inputGateBiasFw = floatTensor1D;
    ANeuralNetworksOperandType forgetGateBiasFw = floatTensor1D;
    ANeuralNetworksOperandType cellBiasFw = floatTensor1D;
    ANeuralNetworksOperandType outputGateBiasFw = floatTensor1D;
    ANeuralNetworksOperandType projWeightsFw = floatTensor2D;
    ANeuralNetworksOperandType projBiasFw = floatTensor1D;
    ANeuralNetworksOperandType outputStateInFw = floatTensor2D;
    ANeuralNetworksOperandType cellStateInFw = floatTensor2D;
    ANeuralNetworksOperandType inputToInputBw = floatTensor2D;
    ANeuralNetworksOperandType inputToForgetBw = floatTensor2D;
    ANeuralNetworksOperandType inputToCellBw = floatTensor2D;
    ANeuralNetworksOperandType inputToOutputBw = floatTensor2D;
    ANeuralNetworksOperandType recurrentToInputBw = floatTensor2D;
    ANeuralNetworksOperandType recurrentToForgetBw = floatTensor2D;
    ANeuralNetworksOperandType recurrentToCellBw = floatTensor2D;
    ANeuralNetworksOperandType recurrentToOutputBw = floatTensor2D;
    ANeuralNetworksOperandType cellToInputBw = floatTensor1D;
    ANeuralNetworksOperandType cellToForgetBw = floatTensor1D;
    ANeuralNetworksOperandType cellToOutputBw = floatTensor1D;
    ANeuralNetworksOperandType inputGateBiasBw = floatTensor1D;
    ANeuralNetworksOperandType forgetGateBiasBw = floatTensor1D;
    ANeuralNetworksOperandType cellBiasBw = floatTensor1D;
    ANeuralNetworksOperandType outputGateBiasBw = floatTensor1D;
    ANeuralNetworksOperandType projWeightsBw = floatTensor2D;
    ANeuralNetworksOperandType projBiasBw = floatTensor1D;
    ANeuralNetworksOperandType outputStateInBw = floatTensor2D;
    ANeuralNetworksOperandType cellStateInBw = floatTensor2D;
    ANeuralNetworksOperandType auxInput = floatTensor3D;
    ANeuralNetworksOperandType auxInputToInputFw = floatTensor2D;
    ANeuralNetworksOperandType auxInputToForgetFw = floatTensor2D;
    ANeuralNetworksOperandType auxInputToCellFw = floatTensor2D;
    ANeuralNetworksOperandType auxInputToOutputFw = floatTensor2D;
    ANeuralNetworksOperandType auxInputToInputBw = floatTensor2D;
    ANeuralNetworksOperandType auxInputToForgetBw = floatTensor2D;
    ANeuralNetworksOperandType auxInputToCellBw = floatTensor2D;
    ANeuralNetworksOperandType auxInputToOutputBw = floatTensor2D;
    ANeuralNetworksOperandType activation = intScalar;
    ANeuralNetworksOperandType clipCellState = floatScalar;
    ANeuralNetworksOperandType clipProjLayer = floatScalar;

    ANeuralNetworksOperandType outputFw = floatTensor2D;
    ANeuralNetworksOperandType outputBw = floatTensor2D;

    OperationTestBase lstmTest(ANEURALNETWORKS_BIDIRECTIONAL_SEQUENCE_LSTM,
                               {
                                       input,
                                       inputToInputFw,
                                       inputToForgetFw,
                                       inputToCellFw,
                                       inputToOutputFw,
                                       recurrentToInputFw,
                                       recurrentToForgetFw,
                                       recurrentToCellFw,
                                       recurrentToOutputFw,
                                       cellToInputFw,
                                       cellToForgetFw,
                                       cellToOutputFw,
                                       inputGateBiasFw,
                                       forgetGateBiasFw,
                                       cellBiasFw,
                                       outputGateBiasFw,
                                       projWeightsFw,
                                       projBiasFw,
                                       outputStateInFw,
                                       cellStateInFw,
                                       inputToInputBw,
                                       inputToForgetBw,
                                       inputToCellBw,
                                       inputToOutputBw,
                                       recurrentToInputBw,
                                       recurrentToForgetBw,
                                       recurrentToCellBw,
                                       recurrentToOutputBw,
                                       cellToInputBw,
                                       cellToForgetBw,
                                       cellToOutputBw,
                                       inputGateBiasBw,
                                       forgetGateBiasBw,
                                       cellBiasBw,
                                       outputGateBiasBw,
                                       projWeightsBw,
                                       projBiasBw,
                                       outputStateInBw,
                                       cellStateInBw,
                                       auxInput,
                                       auxInputToInputFw,
                                       auxInputToForgetFw,
                                       auxInputToCellFw,
                                       auxInputToOutputFw,
                                       auxInputToInputBw,
                                       auxInputToForgetBw,
                                       auxInputToCellBw,
                                       auxInputToOutputBw,
                                       activation,
                                       clipCellState,
                                       clipProjLayer,
                               },
                               {
                                       outputFw,
                                       outputBw,
                               });

    EXPECT_TRUE(lstmTest.testMutatingInputOperandCode());
    EXPECT_TRUE(lstmTest.testMutatingInputOperandCounts());
    EXPECT_TRUE(lstmTest.testMutatingOutputOperandCode());
    EXPECT_TRUE(lstmTest.testMutatingOutputOperandCounts());
}

TEST(OperationValidationTest, LSTM_BIDIRECTIONAL_SEQUENCE) {
    lstmBidirectionalSequence(ANEURALNETWORKS_TENSOR_FLOAT32);
    lstmBidirectionalSequence(ANEURALNETWORKS_TENSOR_FLOAT16);
}

TEST(OperationValidationTest, RANDOM_MULTINOMIAL_float16) {
    uint32_t twoDimensional[2] = {5, 5};
    ANeuralNetworksOperandType floatTensor2D = {.type = ANEURALNETWORKS_TENSOR_FLOAT16,
                                                .dimensionCount = 2,
                                                .dimensions = twoDimensional,
                                                .scale = 0.0f,
                                                .zeroPoint = 0};
    ANeuralNetworksOperandType intScalar = {.type = ANEURALNETWORKS_INT32,
                                            .dimensionCount = 0,
                                            .dimensions = nullptr,
                                            .scale = 0.0f,
                                            .zeroPoint = 0};

    ANeuralNetworksOperandType input = floatTensor2D;
    ANeuralNetworksOperandType sample_count = intScalar;
    ANeuralNetworksOperandType output = floatTensor2D;

    OperationTestBase multinomialTest(ANEURALNETWORKS_RANDOM_MULTINOMIAL, {input, sample_count},
                                      {output});

    EXPECT_TRUE(multinomialTest.testMutatingInputOperandCode());
    EXPECT_TRUE(multinomialTest.testMutatingInputOperandCounts());
    EXPECT_TRUE(multinomialTest.testMutatingOutputOperandCode());
    EXPECT_TRUE(multinomialTest.testMutatingOutputOperandCounts());
}

TEST(OperationValidationTest, RANDOM_MULTINOMIAL_float32) {
    uint32_t twoDimensional[2] = {5, 5};
    ANeuralNetworksOperandType floatTensor2D = {.type = ANEURALNETWORKS_TENSOR_FLOAT32,
                                                .dimensionCount = 2,
                                                .dimensions = twoDimensional,
                                                .scale = 0.0f,
                                                .zeroPoint = 0};
    ANeuralNetworksOperandType intScalar = {.type = ANEURALNETWORKS_INT32,
                                            .dimensionCount = 0,
                                            .dimensions = nullptr,
                                            .scale = 0.0f,
                                            .zeroPoint = 0};

    ANeuralNetworksOperandType input = floatTensor2D;
    ANeuralNetworksOperandType sample_count = intScalar;
    ANeuralNetworksOperandType output = floatTensor2D;

    OperationTestBase multinomialTest(ANEURALNETWORKS_RANDOM_MULTINOMIAL, {input, sample_count},
                                      {output});

    EXPECT_TRUE(multinomialTest.testMutatingInputOperandCode());
    EXPECT_TRUE(multinomialTest.testMutatingInputOperandCounts());
    EXPECT_TRUE(multinomialTest.testMutatingOutputOperandCode());
    EXPECT_TRUE(multinomialTest.testMutatingOutputOperandCounts());
}

TEST(OperationValidationTest, RNN_float16) {
    uint32_t oneDimensional[1] = {5};
    uint32_t twoDimensional[2] = {5, 5};
    ANeuralNetworksOperandType floatTensor1D = {.type = ANEURALNETWORKS_TENSOR_FLOAT16,
                                                .dimensionCount = 1,
                                                .dimensions = oneDimensional,
                                                .scale = 0.0f,
                                                .zeroPoint = 0};
    ANeuralNetworksOperandType floatTensor2D = {.type = ANEURALNETWORKS_TENSOR_FLOAT16,
                                                .dimensionCount = 2,
                                                .dimensions = twoDimensional,
                                                .scale = 0.0f,
                                                .zeroPoint = 0};
    ANeuralNetworksOperandType intScalar = {.type = ANEURALNETWORKS_INT32,
                                            .dimensionCount = 0,
                                            .dimensions = nullptr,
                                            .scale = 0.0f,
                                            .zeroPoint = 0};

    ANeuralNetworksOperandType input = floatTensor2D;
    ANeuralNetworksOperandType weights = floatTensor2D;
    ANeuralNetworksOperandType recurrentWeights = floatTensor2D;
    ANeuralNetworksOperandType bias = floatTensor1D;
    ANeuralNetworksOperandType hiddenStateIn = floatTensor2D;
    ANeuralNetworksOperandType activation = intScalar;

    ANeuralNetworksOperandType hiddenStateOut = floatTensor2D;
    ANeuralNetworksOperandType output = floatTensor2D;

    OperationTestBase rnnTest(ANEURALNETWORKS_RNN,
                              {input, weights, recurrentWeights, bias, hiddenStateIn, activation},
                              {hiddenStateOut, output});

    EXPECT_TRUE(rnnTest.testMutatingInputOperandCode());
    EXPECT_TRUE(rnnTest.testMutatingInputOperandCounts());
    EXPECT_TRUE(rnnTest.testMutatingOutputOperandCode());
    EXPECT_TRUE(rnnTest.testMutatingOutputOperandCounts());
}

TEST(OperationValidationTest, RNN_float32) {
    uint32_t oneDimensional[1] = {5};
    uint32_t twoDimensional[2] = {5, 5};
    ANeuralNetworksOperandType floatTensor1D = {.type = ANEURALNETWORKS_TENSOR_FLOAT32,
                                                .dimensionCount = 1,
                                                .dimensions = oneDimensional,
                                                .scale = 0.0f,
                                                .zeroPoint = 0};
    ANeuralNetworksOperandType floatTensor2D = {.type = ANEURALNETWORKS_TENSOR_FLOAT32,
                                                .dimensionCount = 2,
                                                .dimensions = twoDimensional,
                                                .scale = 0.0f,
                                                .zeroPoint = 0};
    ANeuralNetworksOperandType intScalar = {.type = ANEURALNETWORKS_INT32,
                                            .dimensionCount = 0,
                                            .dimensions = nullptr,
                                            .scale = 0.0f,
                                            .zeroPoint = 0};

    ANeuralNetworksOperandType input = floatTensor2D;
    ANeuralNetworksOperandType weights = floatTensor2D;
    ANeuralNetworksOperandType recurrentWeights = floatTensor2D;
    ANeuralNetworksOperandType bias = floatTensor1D;
    ANeuralNetworksOperandType hiddenStateIn = floatTensor2D;
    ANeuralNetworksOperandType activation = intScalar;

    ANeuralNetworksOperandType hiddenStateOut = floatTensor2D;
    ANeuralNetworksOperandType output = floatTensor2D;

    OperationTestBase rnnTest(ANEURALNETWORKS_RNN,
                              {input, weights, recurrentWeights, bias, hiddenStateIn, activation},
                              {hiddenStateOut, output});

    EXPECT_TRUE(rnnTest.testMutatingInputOperandCode());
    EXPECT_TRUE(rnnTest.testMutatingInputOperandCounts());
    EXPECT_TRUE(rnnTest.testMutatingOutputOperandCode());
    EXPECT_TRUE(rnnTest.testMutatingOutputOperandCounts());
}

TEST(OperationValidationTest, SVDF_float32) {
    uint32_t oneDimensional[1] = {5};
    uint32_t twoDimensional[2] = {5, 5};
    ANeuralNetworksOperandType floatTensor1D = {.type = ANEURALNETWORKS_TENSOR_FLOAT32,
                                                .dimensionCount = 1,
                                                .dimensions = oneDimensional,
                                                .scale = 0.0f,
                                                .zeroPoint = 0};
    ANeuralNetworksOperandType floatTensor2D = {.type = ANEURALNETWORKS_TENSOR_FLOAT32,
                                                .dimensionCount = 2,
                                                .dimensions = twoDimensional,
                                                .scale = 0.0f,
                                                .zeroPoint = 0};
    ANeuralNetworksOperandType intScalar = {.type = ANEURALNETWORKS_INT32,
                                            .dimensionCount = 0,
                                            .dimensions = nullptr,
                                            .scale = 0.0f,
                                            .zeroPoint = 0};

    ANeuralNetworksOperandType input = floatTensor2D;
    ANeuralNetworksOperandType weightsFeature = floatTensor2D;
    ANeuralNetworksOperandType weightsTime = floatTensor2D;
    ANeuralNetworksOperandType bias = floatTensor1D;
    ANeuralNetworksOperandType stateIn = floatTensor2D;
    ANeuralNetworksOperandType rank = intScalar;
    ANeuralNetworksOperandType activation = intScalar;

    ANeuralNetworksOperandType stateOut = floatTensor2D;
    ANeuralNetworksOperandType output = floatTensor2D;

    OperationTestBase svdfTest(
            ANEURALNETWORKS_SVDF,
            {input, weightsFeature, weightsTime, bias, stateIn, rank, activation},
            {stateOut, output});

    EXPECT_TRUE(svdfTest.testMutatingInputOperandCode());
    EXPECT_TRUE(svdfTest.testMutatingInputOperandCounts());
    EXPECT_TRUE(svdfTest.testMutatingOutputOperandCode());
    EXPECT_TRUE(svdfTest.testMutatingOutputOperandCounts());
}

TEST(OperationValidationTest, SVDF_float16) {
    uint32_t oneDimensional[1] = {5};
    uint32_t twoDimensional[2] = {5, 5};
    ANeuralNetworksOperandType floatTensor1D = {.type = ANEURALNETWORKS_TENSOR_FLOAT16,
                                                .dimensionCount = 1,
                                                .dimensions = oneDimensional,
                                                .scale = 0.0f,
                                                .zeroPoint = 0};
    ANeuralNetworksOperandType floatTensor2D = {.type = ANEURALNETWORKS_TENSOR_FLOAT16,
                                                .dimensionCount = 2,
                                                .dimensions = twoDimensional,
                                                .scale = 0.0f,
                                                .zeroPoint = 0};
    ANeuralNetworksOperandType intScalar = {.type = ANEURALNETWORKS_INT32,
                                            .dimensionCount = 0,
                                            .dimensions = nullptr,
                                            .scale = 0.0f,
                                            .zeroPoint = 0};

    ANeuralNetworksOperandType input = floatTensor2D;
    ANeuralNetworksOperandType weightsFeature = floatTensor2D;
    ANeuralNetworksOperandType weightsTime = floatTensor2D;
    ANeuralNetworksOperandType bias = floatTensor1D;
    ANeuralNetworksOperandType stateIn = floatTensor2D;
    ANeuralNetworksOperandType rank = intScalar;
    ANeuralNetworksOperandType activation = intScalar;

    ANeuralNetworksOperandType stateOut = floatTensor2D;
    ANeuralNetworksOperandType output = floatTensor2D;

    OperationTestBase svdfTest(
            ANEURALNETWORKS_SVDF,
            {input, weightsFeature, weightsTime, bias, stateIn, rank, activation},
            {stateOut, output});

    EXPECT_TRUE(svdfTest.testMutatingInputOperandCode());
    EXPECT_TRUE(svdfTest.testMutatingInputOperandCounts());
    EXPECT_TRUE(svdfTest.testMutatingOutputOperandCode());
    EXPECT_TRUE(svdfTest.testMutatingOutputOperandCounts());
}

void stridedSliceOpTest(int32_t operandCode) {
    uint32_t inputDimensions[2] = {5, 5};
    ANeuralNetworksOperandType input = {.type = operandCode,
                                        .dimensionCount = 2,
                                        .dimensions = inputDimensions,
                                        .scale = 0.0f,
                                        .zeroPoint = 0};
    if (operandCode == ANEURALNETWORKS_TENSOR_QUANT8_ASYMM) {
        input.scale = 0.5f;
    }
    ANeuralNetworksOperandType output = input;

    uint32_t beginsDimensions[1] = {2};
    ANeuralNetworksOperandType begins = {.type = ANEURALNETWORKS_TENSOR_INT32,
                                         .dimensionCount = 1,
                                         .dimensions = beginsDimensions,
                                         .scale = 0.0f,
                                         .zeroPoint = 0};

    ANeuralNetworksOperandType ends = begins;
    ANeuralNetworksOperandType strides = begins;

    ANeuralNetworksOperandType beginMask = {.type = ANEURALNETWORKS_INT32,
                                            .dimensionCount = 0,
                                            .dimensions = nullptr,
                                            .scale = 0.0f,
                                            .zeroPoint = 0};
    ANeuralNetworksOperandType endMask = beginMask;
    ANeuralNetworksOperandType shrinkAxisMask = beginMask;

    OperationTestBase stridedSliceTest(
            ANEURALNETWORKS_STRIDED_SLICE,
            {input, begins, ends, strides, beginMask, endMask, shrinkAxisMask}, {output});

    EXPECT_TRUE(stridedSliceTest.testMutatingInputOperandCode());
    EXPECT_TRUE(stridedSliceTest.testMutatingInputOperandCounts());
    EXPECT_TRUE(stridedSliceTest.testMutatingOutputOperandCode());
    EXPECT_TRUE(stridedSliceTest.testMutatingOutputOperandCounts());
}

TEST(OperationValidationTest, STRIDED_SLICE_float32) {
    stridedSliceOpTest(ANEURALNETWORKS_TENSOR_FLOAT32);
}

TEST(OperationValidationTest, STRIDED_SLICE_float16) {
    stridedSliceOpTest(ANEURALNETWORKS_TENSOR_FLOAT16);
}

TEST(OperationValidationTest, STRIDED_SLICE_quant8) {
    stridedSliceOpTest(ANEURALNETWORKS_TENSOR_QUANT8_ASYMM);
}

void roiAlignOpTest(int32_t inputOperandCode, int32_t roiOperandCode, int32_t scalarOperandCode) {
    uint32_t inDim[] = {1, 4, 4, 1}, roiDim[] = {4, 4}, batchSplitDim[] = {1};
    uint32_t outDim[] = {4, 2, 2, 1};
    OperationTestBase roiAlignTest(
            ANEURALNETWORKS_ROI_ALIGN,
            {getOpType(inputOperandCode, 4, inDim), getOpType(roiOperandCode, 2, roiDim),
             getOpType(ANEURALNETWORKS_TENSOR_INT32, 1, batchSplitDim),
             getOpType(ANEURALNETWORKS_INT32), getOpType(ANEURALNETWORKS_INT32),
             getOpType(scalarOperandCode), getOpType(scalarOperandCode),
             getOpType(ANEURALNETWORKS_INT32), getOpType(ANEURALNETWORKS_INT32),
             getOpType(ANEURALNETWORKS_BOOL)},
            {getOpType(inputOperandCode, 4, outDim)});

    EXPECT_TRUE(roiAlignTest.testMutatingInputOperandCode());
    EXPECT_TRUE(roiAlignTest.testMutatingInputOperandCounts());
    EXPECT_TRUE(roiAlignTest.testMutatingOutputOperandCode());
    EXPECT_TRUE(roiAlignTest.testMutatingOutputOperandCounts());
}

TEST(OperationValidationTest, ROI_ALIGN_float16) {
    roiAlignOpTest(ANEURALNETWORKS_TENSOR_FLOAT16, ANEURALNETWORKS_TENSOR_FLOAT16,
                   ANEURALNETWORKS_FLOAT16);
}

TEST(OperationValidationTest, ROI_ALIGN_float32) {
    roiAlignOpTest(ANEURALNETWORKS_TENSOR_FLOAT32, ANEURALNETWORKS_TENSOR_FLOAT32,
                   ANEURALNETWORKS_FLOAT32);
}

TEST(OperationValidationTest, ROI_ALIGN_quant8) {
    roiAlignOpTest(ANEURALNETWORKS_TENSOR_QUANT8_ASYMM, ANEURALNETWORKS_TENSOR_QUANT16_ASYMM,
                   ANEURALNETWORKS_FLOAT32);
}

void roiPoolingOpTest(int32_t inputOperandCode, int32_t roiOperandCode, int32_t scalarOperandCode) {
    uint32_t inDim[] = {1, 4, 4, 1}, roiDim[] = {4, 4}, batchSplitDim[] = {1};
    uint32_t outDim[] = {4, 2, 2, 1};
    OperationTestBase roiPoolingTest(
            ANEURALNETWORKS_ROI_POOLING,
            {getOpType(inputOperandCode, 4, inDim), getOpType(roiOperandCode, 2, roiDim),
             getOpType(ANEURALNETWORKS_TENSOR_INT32, 1, batchSplitDim),
             getOpType(ANEURALNETWORKS_INT32), getOpType(ANEURALNETWORKS_INT32),
             getOpType(scalarOperandCode), getOpType(scalarOperandCode),
             getOpType(ANEURALNETWORKS_BOOL)},
            {getOpType(inputOperandCode, 4, outDim)});

    EXPECT_TRUE(roiPoolingTest.testMutatingInputOperandCode());
    EXPECT_TRUE(roiPoolingTest.testMutatingInputOperandCounts());
    EXPECT_TRUE(roiPoolingTest.testMutatingOutputOperandCode());
    EXPECT_TRUE(roiPoolingTest.testMutatingOutputOperandCounts());
}

TEST(OperationValidationTest, ROI_POOLING_float16) {
    roiPoolingOpTest(ANEURALNETWORKS_TENSOR_FLOAT16, ANEURALNETWORKS_TENSOR_FLOAT16,
                     ANEURALNETWORKS_FLOAT16);
}

TEST(OperationValidationTest, ROI_POOLING_float32) {
    roiPoolingOpTest(ANEURALNETWORKS_TENSOR_FLOAT32, ANEURALNETWORKS_TENSOR_FLOAT32,
                     ANEURALNETWORKS_FLOAT32);
}

TEST(OperationValidationTest, ROI_POOLING_quant8) {
    roiPoolingOpTest(ANEURALNETWORKS_TENSOR_QUANT8_ASYMM, ANEURALNETWORKS_TENSOR_QUANT16_ASYMM,
                     ANEURALNETWORKS_FLOAT32);
}

void heatmapMaxKeypointOpTest(int32_t heatmapOperandCode, int32_t roiOperandCode) {
    uint32_t heatmapDim[] = {6, 4, 4, 1}, boxDim[] = {6, 4}, outScoreDim[] = {6, 1},
             outKeypointDim[] = {6, 1, 2};
    OperationTestBase heatmapMaxKeypointTest(
            ANEURALNETWORKS_HEATMAP_MAX_KEYPOINT,
            {getOpType(heatmapOperandCode, 4, heatmapDim), getOpType(roiOperandCode, 2, boxDim),
             getOpType(ANEURALNETWORKS_BOOL)},
            {getOpType(heatmapOperandCode, 2, outScoreDim),
             getOpType(roiOperandCode, 3, outKeypointDim)});

    EXPECT_TRUE(heatmapMaxKeypointTest.testMutatingInputOperandCode());
    EXPECT_TRUE(heatmapMaxKeypointTest.testMutatingInputOperandCounts());
    EXPECT_TRUE(heatmapMaxKeypointTest.testMutatingOutputOperandCode());
    EXPECT_TRUE(heatmapMaxKeypointTest.testMutatingOutputOperandCounts());
}

TEST(OperationValidationTest, HEATMAP_MAX_KEYPOINT_float16) {
    heatmapMaxKeypointOpTest(ANEURALNETWORKS_TENSOR_FLOAT16, ANEURALNETWORKS_TENSOR_FLOAT16);
}

TEST(OperationValidationTest, HEATMAP_MAX_KEYPOINT_float32) {
    heatmapMaxKeypointOpTest(ANEURALNETWORKS_TENSOR_FLOAT32, ANEURALNETWORKS_TENSOR_FLOAT32);
}

TEST(OperationValidationTest, HEATMAP_MAX_KEYPOINT_quant) {
    heatmapMaxKeypointOpTest(ANEURALNETWORKS_TENSOR_QUANT8_ASYMM,
                             ANEURALNETWORKS_TENSOR_QUANT16_ASYMM);
}

void groupedConvOpTest(int32_t inputOperandCode, int32_t filterOperandCode) {
    uint32_t inDim[] = {1, 3, 3, 2}, filterDim[] = {2, 2, 2, 1}, biasDim[] = {2};
    uint32_t outDim[] = {1, 2, 2, 2};
    ANeuralNetworksOperandType input = getOpType(inputOperandCode, 4, inDim);
    if (inputOperandCode == ANEURALNETWORKS_TENSOR_QUANT8_ASYMM) {
        input.scale = 0.5f;
    }

    float filterScales[2] = {0.5f, 1.0f};
    ANeuralNetworksOperandType filter = getOpType(filterOperandCode, 4, filterDim);
    if (filterOperandCode == ANEURALNETWORKS_TENSOR_QUANT8_ASYMM) {
        filter.scale = 0.5f;
    }

    ANeuralNetworksSymmPerChannelQuantParams filterChannelQuantParams = {
            .channelDim = 0,
            .scaleCount = 2,
            .scales = filterScales,
    };

    ANeuralNetworksOperandType bias = getOpType(inputOperandCode, 1, biasDim);
    if (filterOperandCode == ANEURALNETWORKS_TENSOR_QUANT8_ASYMM) {
        bias.type = ANEURALNETWORKS_TENSOR_INT32;
        bias.scale = 0.25f;
    }
    if (filterOperandCode == ANEURALNETWORKS_TENSOR_QUANT8_SYMM_PER_CHANNEL) {
        bias.type = ANEURALNETWORKS_TENSOR_INT32;
        bias.scale = 0.0f;
    }

    ANeuralNetworksOperandType scalar = getOpType(ANEURALNETWORKS_INT32);
    ANeuralNetworksOperandType layout = getOpType(ANEURALNETWORKS_BOOL);

    ANeuralNetworksOperandType output = getOpType(inputOperandCode, 4, outDim);
    if (inputOperandCode == ANEURALNETWORKS_TENSOR_QUANT8_ASYMM) {
        output.scale = 0.5f;
    }

    OperationTestBase explicitGroupedConvTest(ANEURALNETWORKS_GROUPED_CONV_2D,
                                              {input, filter, bias, scalar, scalar, scalar, scalar,
                                               scalar, scalar, scalar, scalar, layout},
                                              {output});
    if (filterOperandCode == ANEURALNETWORKS_TENSOR_QUANT8_SYMM_PER_CHANNEL) {
        explicitGroupedConvTest.setInputSymmPerChannelQuantParams(1, filterChannelQuantParams);
    }

    EXPECT_TRUE(explicitGroupedConvTest.testMutatingInputOperandCode());
    EXPECT_TRUE(explicitGroupedConvTest.testMutatingInputOperandCounts());
    EXPECT_TRUE(explicitGroupedConvTest.testMutatingOutputOperandCode());
    EXPECT_TRUE(explicitGroupedConvTest.testMutatingOutputOperandCounts());

    OperationTestBase implicitGroupedConvTest(
            ANEURALNETWORKS_GROUPED_CONV_2D,
            {input, filter, bias, scalar, scalar, scalar, scalar, scalar, layout}, {output});
    if (filterOperandCode == ANEURALNETWORKS_TENSOR_QUANT8_SYMM_PER_CHANNEL) {
        implicitGroupedConvTest.setInputSymmPerChannelQuantParams(1, filterChannelQuantParams);
    }

    EXPECT_TRUE(implicitGroupedConvTest.testMutatingInputOperandCode());
    EXPECT_TRUE(implicitGroupedConvTest.testMutatingInputOperandCounts());
    EXPECT_TRUE(implicitGroupedConvTest.testMutatingOutputOperandCode());
    EXPECT_TRUE(implicitGroupedConvTest.testMutatingOutputOperandCounts());
}

TEST(OperationValidationTest, GROUPED_CONV_2D_float32) {
    groupedConvOpTest(ANEURALNETWORKS_TENSOR_FLOAT32, ANEURALNETWORKS_TENSOR_FLOAT32);
}

TEST(OperationValidationTest, GROUPED_CONV_2D_quant8) {
    groupedConvOpTest(ANEURALNETWORKS_TENSOR_QUANT8_ASYMM, ANEURALNETWORKS_TENSOR_QUANT8_ASYMM);
}

TEST(OperationValidationTest, GROUPED_CONV_2D_quant8_per_channel) {
    groupedConvOpTest(ANEURALNETWORKS_TENSOR_QUANT8_ASYMM,
                      ANEURALNETWORKS_TENSOR_QUANT8_SYMM_PER_CHANNEL);
}

void transposeConvOpTest(int32_t inputOperandCode, int32_t filterOperandCode) {
    uint32_t inDim[] = {1, 2, 2, 2}, filterDim[] = {2, 3, 3, 1}, biasDim[] = {2};
    uint32_t outDim[] = {1, 5, 5, 2}, outShapeDim[] = {4};
    ANeuralNetworksOperandType input = getOpType(inputOperandCode, 4, inDim);
    if (inputOperandCode == ANEURALNETWORKS_TENSOR_QUANT8_ASYMM) {
        input.scale = 0.5f;
    }
    ANeuralNetworksOperandType filter = getOpType(filterOperandCode, 4, filterDim);
    if (filterOperandCode == ANEURALNETWORKS_TENSOR_QUANT8_ASYMM) {
        filter.scale = 0.5f;
    }

    float filterScales[2] = {0.5f, 1.0f};
    ANeuralNetworksSymmPerChannelQuantParams filterChannelQuantParams = {
            .channelDim = 0,
            .scaleCount = 2,
            .scales = filterScales,
    };

    ANeuralNetworksOperandType bias = getOpType(inputOperandCode, 1, biasDim);
    if (filterOperandCode == ANEURALNETWORKS_TENSOR_QUANT8_ASYMM) {
        bias.type = ANEURALNETWORKS_TENSOR_INT32;
        bias.scale = 0.25f;
    }
    if (filterOperandCode == ANEURALNETWORKS_TENSOR_QUANT8_SYMM_PER_CHANNEL) {
        bias.type = ANEURALNETWORKS_TENSOR_INT32;
        bias.scale = 0.0f;
    }

    ANeuralNetworksOperandType scalar = getOpType(ANEURALNETWORKS_INT32);
    ANeuralNetworksOperandType layout = getOpType(ANEURALNETWORKS_BOOL);
    ANeuralNetworksOperandType output = getOpType(inputOperandCode, 4, outDim);
    if (inputOperandCode == ANEURALNETWORKS_TENSOR_QUANT8_ASYMM) {
        output.scale = 0.5f;
    }

    OperationTestBase explicitTransposeConvTest(
            ANEURALNETWORKS_TRANSPOSE_CONV_2D,
            {input, filter, bias, scalar, scalar, scalar, scalar, scalar, scalar, scalar, layout},
            {output});
    if (filterOperandCode == ANEURALNETWORKS_TENSOR_QUANT8_SYMM_PER_CHANNEL) {
        explicitTransposeConvTest.setInputSymmPerChannelQuantParams(1, filterChannelQuantParams);
    }

    EXPECT_TRUE(explicitTransposeConvTest.testMutatingInputOperandCode());
    EXPECT_TRUE(explicitTransposeConvTest.testMutatingInputOperandCounts());
    EXPECT_TRUE(explicitTransposeConvTest.testMutatingOutputOperandCode());
    EXPECT_TRUE(explicitTransposeConvTest.testMutatingOutputOperandCounts());

    OperationTestBase implicitTransposeConvTest(
            ANEURALNETWORKS_TRANSPOSE_CONV_2D,
            {input, filter, bias, getOpType(ANEURALNETWORKS_TENSOR_INT32, 1, outShapeDim), scalar,
             scalar, scalar, scalar, layout},
            {output});
    if (filterOperandCode == ANEURALNETWORKS_TENSOR_QUANT8_SYMM_PER_CHANNEL) {
        implicitTransposeConvTest.setInputSymmPerChannelQuantParams(1, filterChannelQuantParams);
    }

    EXPECT_TRUE(implicitTransposeConvTest.testMutatingInputOperandCode());
    EXPECT_TRUE(implicitTransposeConvTest.testMutatingInputOperandCounts());
    EXPECT_TRUE(implicitTransposeConvTest.testMutatingOutputOperandCode());
    EXPECT_TRUE(implicitTransposeConvTest.testMutatingOutputOperandCounts());
}

TEST(OperationValidationTest, TRANSPOSE_CONV_2D_float32) {
    transposeConvOpTest(ANEURALNETWORKS_TENSOR_FLOAT32, ANEURALNETWORKS_TENSOR_FLOAT32);
}

TEST(OperationValidationTest, TRANSPOSE_CONV_2D_quant8) {
    transposeConvOpTest(ANEURALNETWORKS_TENSOR_QUANT8_ASYMM, ANEURALNETWORKS_TENSOR_QUANT8_ASYMM);
}

TEST(OperationValidationTest, TRANSPOSE_CONV_2D_quant8_per_channel) {
    transposeConvOpTest(ANEURALNETWORKS_TENSOR_QUANT8_ASYMM,
                        ANEURALNETWORKS_TENSOR_QUANT8_SYMM_PER_CHANNEL);
}

void channelShuffleOpTest(int32_t operandCode) {
    uint32_t inoutDim[] = {2, 2, 3, 12};
    OperationTestBase channelShuffleTest(
            ANEURALNETWORKS_CHANNEL_SHUFFLE,
            {getOpType(operandCode, 2, inoutDim), getOpType(ANEURALNETWORKS_INT32),
             getOpType(ANEURALNETWORKS_INT32)},
            {getOpType(operandCode, 2, inoutDim)});

    EXPECT_TRUE(channelShuffleTest.testMutatingInputOperandCode());
    EXPECT_TRUE(channelShuffleTest.testMutatingInputOperandCounts());
    EXPECT_TRUE(channelShuffleTest.testMutatingOutputOperandCode());
    EXPECT_TRUE(channelShuffleTest.testMutatingOutputOperandCounts());
}

TEST(OperationValidationTest, CHANNEL_SHUFFLE_float32) {
    channelShuffleOpTest(ANEURALNETWORKS_TENSOR_FLOAT32);
}

TEST(OperationValidationTest, CHANNEL_SHUFFLE_quant8) {
    channelShuffleOpTest(ANEURALNETWORKS_TENSOR_QUANT8_ASYMM);
}

void preluOpTest(int32_t operandCode) {
    uint32_t inoutDim[] = {1, 2, 2, 3}, alphaDim[] = {1, 1, 3};
    OperationTestBase preluTest(
            ANEURALNETWORKS_PRELU,
            {getOpType(operandCode, 4, inoutDim), getOpType(operandCode, 3, alphaDim)},
            {getOpType(operandCode, 4, inoutDim)});

    EXPECT_TRUE(preluTest.testMutatingInputOperandCode());
    EXPECT_TRUE(preluTest.testMutatingInputOperandCounts());
    EXPECT_TRUE(preluTest.testMutatingOutputOperandCode());
    EXPECT_TRUE(preluTest.testMutatingOutputOperandCounts());
}

TEST(OperationValidationTest, PRELU_float16) {
    preluOpTest(ANEURALNETWORKS_TENSOR_FLOAT16);
}

TEST(OperationValidationTest, PRELU_float32) {
    preluOpTest(ANEURALNETWORKS_TENSOR_FLOAT32);
}

TEST(OperationValidationTest, PRELU_quant8) {
    preluOpTest(ANEURALNETWORKS_TENSOR_QUANT8_ASYMM);
}

void normalizationOpTest(ANeuralNetworksOperationType operationCode, int32_t operandCode) {
    uint32_t inputDim[] = {2, 2, 2, 2};
    OperationTestBase normalizationTest(operationCode, {getOpType(operandCode, 4, inputDim)},
                                        {getOpType(operandCode, 4, inputDim)});
    EXPECT_TRUE(normalizationTest.testMutatingInputOperandCode());
    EXPECT_TRUE(normalizationTest.testMutatingInputOperandCounts());
    EXPECT_TRUE(normalizationTest.testMutatingOutputOperandCode());
    EXPECT_TRUE(normalizationTest.testMutatingOutputOperandCounts());

    OperationTestBase normalizationAxisTest(
            operationCode, {getOpType(operandCode, 4, inputDim), getOpType(ANEURALNETWORKS_INT32)},
            {getOpType(operandCode, 4, inputDim)});
    EXPECT_TRUE(normalizationAxisTest.testMutatingInputOperandCode());
    EXPECT_TRUE(normalizationAxisTest.testMutatingInputOperandCounts());
    EXPECT_TRUE(normalizationAxisTest.testMutatingOutputOperandCode());
    EXPECT_TRUE(normalizationAxisTest.testMutatingOutputOperandCounts());
}

TEST(OperationValidationTest, L2_NORMALIZATION_float16) {
    normalizationOpTest(ANEURALNETWORKS_L2_NORMALIZATION, ANEURALNETWORKS_TENSOR_FLOAT16);
}

TEST(OperationValidationTest, L2_NORMALIZATION_float32) {
    normalizationOpTest(ANEURALNETWORKS_L2_NORMALIZATION, ANEURALNETWORKS_TENSOR_FLOAT32);
}

void localResponseNormOpTest(int32_t operandCode) {
    uint32_t inputDim[] = {2, 2, 2, 6};
    OperationTestBase lrnTest(
            ANEURALNETWORKS_LOCAL_RESPONSE_NORMALIZATION,
            {getOpType(operandCode, 4, inputDim), getOpType(ANEURALNETWORKS_INT32),
             getOpType(ANEURALNETWORKS_FLOAT32), getOpType(ANEURALNETWORKS_FLOAT32),
             getOpType(ANEURALNETWORKS_FLOAT32)},
            {getOpType(operandCode, 4, inputDim)});
    EXPECT_TRUE(lrnTest.testMutatingInputOperandCode());
    EXPECT_TRUE(lrnTest.testMutatingInputOperandCounts());
    EXPECT_TRUE(lrnTest.testMutatingOutputOperandCode());
    EXPECT_TRUE(lrnTest.testMutatingOutputOperandCounts());

    OperationTestBase lrnAxisTest(
            ANEURALNETWORKS_LOCAL_RESPONSE_NORMALIZATION,
            {getOpType(operandCode, 4, inputDim), getOpType(ANEURALNETWORKS_INT32),
             getOpType(ANEURALNETWORKS_FLOAT32), getOpType(ANEURALNETWORKS_FLOAT32),
             getOpType(ANEURALNETWORKS_FLOAT32), getOpType(ANEURALNETWORKS_INT32)},
            {getOpType(operandCode, 4, inputDim)});
    EXPECT_TRUE(lrnAxisTest.testMutatingInputOperandCode());
    EXPECT_TRUE(lrnAxisTest.testMutatingInputOperandCounts());
    EXPECT_TRUE(lrnAxisTest.testMutatingOutputOperandCode());
    EXPECT_TRUE(lrnAxisTest.testMutatingOutputOperandCounts());
}

TEST(OperationValidationTest, LOCAL_RESPONSE_NORMALIZATION_float16) {
    localResponseNormOpTest(ANEURALNETWORKS_TENSOR_FLOAT16);
}

TEST(OperationValidationTest, LOCAL_RESPONSE_NORMALIZATION_float32) {
    localResponseNormOpTest(ANEURALNETWORKS_TENSOR_FLOAT32);
}

void axisAlignedBBoxTransformOpTest(int32_t roiOperandCode, int32_t deltaOperandCode) {
    uint32_t roiDim[] = {5, 4}, deltaDim[] = {5, 8}, bsDim[] = {5}, imageDim[] = {5, 2};
    uint32_t outDim[] = {5, 8};
    OperationTestBase axisAlignedBBoxTransformTest(
            ANEURALNETWORKS_AXIS_ALIGNED_BBOX_TRANSFORM,
            {getOpType(roiOperandCode, 2, roiDim), getOpType(deltaOperandCode, 2, deltaDim),
             getOpType(ANEURALNETWORKS_TENSOR_INT32, 1, bsDim),
             getOpType(roiOperandCode, 2, imageDim)},
            {getOpType(roiOperandCode, 2, outDim)});

    EXPECT_TRUE(axisAlignedBBoxTransformTest.testMutatingInputOperandCode());
    EXPECT_TRUE(axisAlignedBBoxTransformTest.testMutatingInputOperandCounts());
    EXPECT_TRUE(axisAlignedBBoxTransformTest.testMutatingOutputOperandCode());
    EXPECT_TRUE(axisAlignedBBoxTransformTest.testMutatingOutputOperandCounts());
}

TEST(OperationValidationTest, AXIS_ALIGNED_BBOX_TRANSFORM_float16) {
    axisAlignedBBoxTransformOpTest(ANEURALNETWORKS_TENSOR_FLOAT16, ANEURALNETWORKS_TENSOR_FLOAT16);
}

TEST(OperationValidationTest, AXIS_ALIGNED_BBOX_TRANSFORM_float32) {
    axisAlignedBBoxTransformOpTest(ANEURALNETWORKS_TENSOR_FLOAT32, ANEURALNETWORKS_TENSOR_FLOAT32);
}

TEST(OperationValidationTest, AXIS_ALIGNED_BBOX_TRANSFORM_quant) {
    axisAlignedBBoxTransformOpTest(ANEURALNETWORKS_TENSOR_QUANT16_ASYMM,
                                   ANEURALNETWORKS_TENSOR_QUANT8_ASYMM);
}

void sliceTest(int32_t operandCode) {
    uint32_t inputDim[] = {3, 3, 3};
    uint32_t startDim[] = {3};
    uint32_t sizeDim[] = {3};
    uint32_t outputDim[] = {1, 2, 3};

    OperationTestBase sliceTest(ANEURALNETWORKS_SLICE,
                                {getOpType(operandCode, 3, inputDim),
                                 getOpType(ANEURALNETWORKS_TENSOR_INT32, 1, startDim),
                                 getOpType(ANEURALNETWORKS_TENSOR_INT32, 1, sizeDim)},
                                {getOpType(operandCode, 3, outputDim)});

    EXPECT_TRUE(sliceTest.testMutatingInputOperandCode());
    EXPECT_TRUE(sliceTest.testMutatingInputOperandCounts());
    EXPECT_TRUE(sliceTest.testMutatingOutputOperandCode());
    EXPECT_TRUE(sliceTest.testMutatingOutputOperandCounts());
}

TEST(OperationValidationTest, SLICE_float32) {
    sliceTest(ANEURALNETWORKS_TENSOR_FLOAT32);
}
TEST(OperationValidationTest, SLICE_int32) {
    sliceTest(ANEURALNETWORKS_TENSOR_INT32);
}
TEST(OperationValidationTest, SLICE_uint8) {
    sliceTest(ANEURALNETWORKS_TENSOR_QUANT8_ASYMM);
}
TEST(OperationValidationTest, SLICE_float16) {
    sliceTest(ANEURALNETWORKS_TENSOR_FLOAT16);
}

void logicalTest(ANeuralNetworksOperationType operationCode) {
    uint32_t inputDimensions[4] = {2, 2, 2, 2};
    ANeuralNetworksOperandType input1 = {.type = ANEURALNETWORKS_TENSOR_BOOL8,
                                         .dimensionCount = 4,
                                         .dimensions = inputDimensions,
                                         .scale = 0.0f,
                                         .zeroPoint = 0};
    ANeuralNetworksOperandType input2 = input1;
    ANeuralNetworksOperandType output = input1;

    OperationTestBase test(operationCode, {input1, input2}, {output});

    EXPECT_TRUE(test.testMutatingInputOperandCode());
    EXPECT_TRUE(test.testMutatingInputOperandCounts());
    EXPECT_TRUE(test.testMutatingOutputOperandCode());
    EXPECT_TRUE(test.testMutatingOutputOperandCounts());
}

TEST(OperationValidationTest, LOGICAL_AND) {
    logicalTest(ANEURALNETWORKS_LOGICAL_AND);
}

TEST(OperationValidationTest, LOGICAL_OR) {
    logicalTest(ANEURALNETWORKS_LOGICAL_OR);
}

void comparisonTest(ANeuralNetworksOperationType operationCode, int32_t inputOperandType) {
    uint32_t inputDimensions[4] = {2, 2, 2, 2};
    ANeuralNetworksOperandType input1 = {.type = inputOperandType,
                                         .dimensionCount = 4,
                                         .dimensions = inputDimensions,
                                         .scale = 0.0f,
                                         .zeroPoint = 0};
    if (inputOperandType == ANEURALNETWORKS_TENSOR_QUANT8_ASYMM) {
        input1.scale = 1.f / 256;
    }
    ANeuralNetworksOperandType input2 = input1;
    ANeuralNetworksOperandType output = {.type = ANEURALNETWORKS_TENSOR_BOOL8,
                                         .dimensionCount = 4,
                                         .dimensions = inputDimensions,
                                         .scale = 0.0f,
                                         .zeroPoint = 0};
    OperationTestBase test(operationCode, {input1, input2}, {output});

    EXPECT_TRUE(test.testMutatingInputOperandCode());
    EXPECT_TRUE(test.testMutatingInputOperandCounts());
    EXPECT_TRUE(test.testMutatingOutputOperandCode());
    EXPECT_TRUE(test.testMutatingOutputOperandCounts());
}

TEST(OperationValidationTest, LESS) {
    comparisonTest(ANEURALNETWORKS_LESS, ANEURALNETWORKS_TENSOR_BOOL8);
    comparisonTest(ANEURALNETWORKS_LESS, ANEURALNETWORKS_TENSOR_FLOAT16);
    comparisonTest(ANEURALNETWORKS_LESS, ANEURALNETWORKS_TENSOR_FLOAT32);
    comparisonTest(ANEURALNETWORKS_LESS, ANEURALNETWORKS_TENSOR_INT32);
    comparisonTest(ANEURALNETWORKS_LESS, ANEURALNETWORKS_TENSOR_QUANT8_ASYMM);
}

TEST(OperationValidationTest, LESS_EQUAL) {
    comparisonTest(ANEURALNETWORKS_LESS_EQUAL, ANEURALNETWORKS_TENSOR_BOOL8);
    comparisonTest(ANEURALNETWORKS_LESS_EQUAL, ANEURALNETWORKS_TENSOR_FLOAT16);
    comparisonTest(ANEURALNETWORKS_LESS_EQUAL, ANEURALNETWORKS_TENSOR_FLOAT32);
    comparisonTest(ANEURALNETWORKS_LESS_EQUAL, ANEURALNETWORKS_TENSOR_INT32);
    comparisonTest(ANEURALNETWORKS_LESS_EQUAL, ANEURALNETWORKS_TENSOR_QUANT8_ASYMM);
}

TEST(OperationValidationTest, EQUAL) {
    comparisonTest(ANEURALNETWORKS_EQUAL, ANEURALNETWORKS_TENSOR_BOOL8);
    comparisonTest(ANEURALNETWORKS_EQUAL, ANEURALNETWORKS_TENSOR_FLOAT16);
    comparisonTest(ANEURALNETWORKS_EQUAL, ANEURALNETWORKS_TENSOR_FLOAT32);
    comparisonTest(ANEURALNETWORKS_EQUAL, ANEURALNETWORKS_TENSOR_INT32);
    comparisonTest(ANEURALNETWORKS_EQUAL, ANEURALNETWORKS_TENSOR_QUANT8_ASYMM);
}

TEST(OperationValidationTest, NOT_EQUAL) {
    comparisonTest(ANEURALNETWORKS_NOT_EQUAL, ANEURALNETWORKS_TENSOR_BOOL8);
    comparisonTest(ANEURALNETWORKS_NOT_EQUAL, ANEURALNETWORKS_TENSOR_FLOAT16);
    comparisonTest(ANEURALNETWORKS_NOT_EQUAL, ANEURALNETWORKS_TENSOR_FLOAT32);
    comparisonTest(ANEURALNETWORKS_NOT_EQUAL, ANEURALNETWORKS_TENSOR_INT32);
    comparisonTest(ANEURALNETWORKS_NOT_EQUAL, ANEURALNETWORKS_TENSOR_QUANT8_ASYMM);
}

TEST(OperationValidationTest, GREATER) {
    comparisonTest(ANEURALNETWORKS_GREATER, ANEURALNETWORKS_TENSOR_BOOL8);
    comparisonTest(ANEURALNETWORKS_GREATER, ANEURALNETWORKS_TENSOR_FLOAT16);
    comparisonTest(ANEURALNETWORKS_GREATER, ANEURALNETWORKS_TENSOR_FLOAT32);
    comparisonTest(ANEURALNETWORKS_GREATER, ANEURALNETWORKS_TENSOR_INT32);
    comparisonTest(ANEURALNETWORKS_GREATER, ANEURALNETWORKS_TENSOR_QUANT8_ASYMM);
}

TEST(OperationValidationTest, GREATER_EQUAL) {
    comparisonTest(ANEURALNETWORKS_GREATER_EQUAL, ANEURALNETWORKS_TENSOR_BOOL8);
    comparisonTest(ANEURALNETWORKS_GREATER_EQUAL, ANEURALNETWORKS_TENSOR_FLOAT16);
    comparisonTest(ANEURALNETWORKS_GREATER_EQUAL, ANEURALNETWORKS_TENSOR_FLOAT32);
    comparisonTest(ANEURALNETWORKS_GREATER_EQUAL, ANEURALNETWORKS_TENSOR_INT32);
    comparisonTest(ANEURALNETWORKS_GREATER_EQUAL, ANEURALNETWORKS_TENSOR_QUANT8_ASYMM);
}

void reduceOpTest(ANeuralNetworksOperationType operationCode, int32_t inputOperandType) {
    bool isQuant = inputOperandType == ANEURALNETWORKS_TENSOR_QUANT8_ASYMM;
    float scale = isQuant ? 1.f / 256 : 0.0f;
    uint32_t inputDimensions[4] = {2, 2, 2, 2};
    ANeuralNetworksOperandType input1 = {
            .type = inputOperandType,
            .dimensionCount = 4,
            .dimensions = inputDimensions,
            .scale = scale,
            .zeroPoint = 0,
    };
    uint32_t axesDimensions[1] = {2};
    ANeuralNetworksOperandType input2 = {
            .type = ANEURALNETWORKS_TENSOR_INT32,
            .dimensionCount = 1,
            .dimensions = axesDimensions,
    };
    ANeuralNetworksOperandType input3 = {
            .type = ANEURALNETWORKS_BOOL,
            .dimensions = {},
    };
    ANeuralNetworksOperandType output = {
            .type = inputOperandType,
            .dimensionCount = 4,
            .dimensions = inputDimensions,
            .scale = scale,
    };
    OperationTestBase test(operationCode, {input1, input2, input3}, {output});

    EXPECT_TRUE(test.testMutatingInputOperandCode());
    EXPECT_TRUE(test.testMutatingInputOperandCounts());
    EXPECT_TRUE(test.testMutatingOutputOperandCode());
    EXPECT_TRUE(test.testMutatingOutputOperandCounts());
}

TEST(OperationValidationTest, REDUCE_PROD) {
    reduceOpTest(ANEURALNETWORKS_REDUCE_PROD, ANEURALNETWORKS_TENSOR_FLOAT16);
    reduceOpTest(ANEURALNETWORKS_REDUCE_PROD, ANEURALNETWORKS_TENSOR_FLOAT32);
}

TEST(OperationValidationTest, REDUCE_SUM) {
    reduceOpTest(ANEURALNETWORKS_REDUCE_SUM, ANEURALNETWORKS_TENSOR_FLOAT16);
    reduceOpTest(ANEURALNETWORKS_REDUCE_SUM, ANEURALNETWORKS_TENSOR_FLOAT32);
}

TEST(OperationValidationTest, REDUCE_MAX) {
    reduceOpTest(ANEURALNETWORKS_REDUCE_MAX, ANEURALNETWORKS_TENSOR_FLOAT16);
    reduceOpTest(ANEURALNETWORKS_REDUCE_MAX, ANEURALNETWORKS_TENSOR_FLOAT32);
    reduceOpTest(ANEURALNETWORKS_REDUCE_MAX, ANEURALNETWORKS_TENSOR_QUANT8_ASYMM);
}

TEST(OperationValidationTest, REDUCE_MIN) {
    reduceOpTest(ANEURALNETWORKS_REDUCE_MIN, ANEURALNETWORKS_TENSOR_FLOAT16);
    reduceOpTest(ANEURALNETWORKS_REDUCE_MIN, ANEURALNETWORKS_TENSOR_FLOAT32);
    reduceOpTest(ANEURALNETWORKS_REDUCE_MIN, ANEURALNETWORKS_TENSOR_QUANT8_ASYMM);
}

TEST(OperationValidationTest, REDUCE_ANY) {
    reduceOpTest(ANEURALNETWORKS_REDUCE_ANY, ANEURALNETWORKS_TENSOR_BOOL8);
}

TEST(OperationValidationTest, REDUCE_ALL) {
    reduceOpTest(ANEURALNETWORKS_REDUCE_ALL, ANEURALNETWORKS_TENSOR_BOOL8);
}

void selectTest(ANeuralNetworksOperationType operationCode, int32_t inputOperandType) {
    uint32_t inputDimensions[4] = {2, 2, 2, 2};
    ANeuralNetworksOperandType input0 = {.type = ANEURALNETWORKS_TENSOR_BOOL8,
                                         .dimensionCount = 4,
                                         .dimensions = inputDimensions,
                                         .scale = 0.0f,
                                         .zeroPoint = 0};
    ANeuralNetworksOperandType input1 = {.type = inputOperandType,
                                         .dimensionCount = 4,
                                         .dimensions = inputDimensions,
                                         .scale = 0.0f,
                                         .zeroPoint = 0};
    if (inputOperandType == ANEURALNETWORKS_TENSOR_QUANT8_ASYMM) {
        input1.scale = 1.f / 256;
    }
    ANeuralNetworksOperandType input2 = input1;
    ANeuralNetworksOperandType output = input1;

    OperationTestBase test(operationCode, {input0, input1, input2}, {output});

    EXPECT_TRUE(test.testMutatingInputOperandCode());
    EXPECT_TRUE(test.testMutatingInputOperandCounts());
    EXPECT_TRUE(test.testMutatingOutputOperandCode());
    EXPECT_TRUE(test.testMutatingOutputOperandCounts());
}

TEST(OperationValidationTest, SELECT) {
    selectTest(ANEURALNETWORKS_SELECT, ANEURALNETWORKS_TENSOR_FLOAT16);
    selectTest(ANEURALNETWORKS_SELECT, ANEURALNETWORKS_TENSOR_FLOAT32);
    selectTest(ANEURALNETWORKS_SELECT, ANEURALNETWORKS_TENSOR_INT32);
    selectTest(ANEURALNETWORKS_SELECT, ANEURALNETWORKS_TENSOR_QUANT8_ASYMM);
}

void powTest(int32_t inputOperandType) {
    const uint32_t inputDimensions[] = {3, 3};
    ANeuralNetworksOperandType inputType = {.type = inputOperandType,
                                            .dimensionCount = 2,
                                            .dimensions = inputDimensions,
                                            .scale = 0.0f,
                                            .zeroPoint = 0};

    OperationTestBase test(ANEURALNETWORKS_POW, {inputType, inputType}, {inputType});

    EXPECT_TRUE(test.testMutatingInputOperandCode());
    EXPECT_TRUE(test.testMutatingInputOperandCounts());
    EXPECT_TRUE(test.testMutatingOutputOperandCode());
    EXPECT_TRUE(test.testMutatingOutputOperandCounts());
}

TEST(OperationValidationTest, POW) {
    powTest(ANEURALNETWORKS_TENSOR_FLOAT16);
    powTest(ANEURALNETWORKS_TENSOR_FLOAT32);
}

void boxWithNmsLimitOpTest(int32_t scoreOperandCode, int32_t roiOperandCode,
                           int32_t scalarOperandCode) {
    uint32_t scoreDim[] = {19, 3}, roiDim[] = {19, 12}, splitDim[] = {2};
    uint32_t outScoreDim[] = {12}, outRoiDim[] = {12, 4}, outClassDim[] = {12}, outSplitDim[] = {2};
    OperationTestBase boxWithNmsLimitTest(
            ANEURALNETWORKS_BOX_WITH_NMS_LIMIT,
            {getOpType(scoreOperandCode, 2, scoreDim), getOpType(roiOperandCode, 2, roiDim),
             getOpType(ANEURALNETWORKS_TENSOR_INT32, 1, splitDim), getOpType(scalarOperandCode),
             getOpType(scalarOperandCode), getOpType(ANEURALNETWORKS_INT32)},
            {getOpType(scoreOperandCode, 1, outScoreDim), getOpType(roiOperandCode, 2, outRoiDim),
             getOpType(ANEURALNETWORKS_TENSOR_INT32, 1, outClassDim),
             getOpType(ANEURALNETWORKS_TENSOR_INT32, 1, outSplitDim)});

    EXPECT_TRUE(boxWithNmsLimitTest.testMutatingInputOperandCode());
    EXPECT_TRUE(boxWithNmsLimitTest.testMutatingInputOperandCounts());
    EXPECT_TRUE(boxWithNmsLimitTest.testMutatingOutputOperandCode());
    EXPECT_TRUE(boxWithNmsLimitTest.testMutatingOutputOperandCounts());
}

TEST(OperationValidationTest, BOX_WITH_NMS_LIMIT_float16) {
    boxWithNmsLimitOpTest(ANEURALNETWORKS_TENSOR_FLOAT16, ANEURALNETWORKS_TENSOR_FLOAT16,
                          ANEURALNETWORKS_FLOAT16);
}

TEST(OperationValidationTest, BOX_WITH_NMS_LIMIT_float32) {
    boxWithNmsLimitOpTest(ANEURALNETWORKS_TENSOR_FLOAT32, ANEURALNETWORKS_TENSOR_FLOAT32,
                          ANEURALNETWORKS_FLOAT32);
}

TEST(OperationValidationTest, BOX_WITH_NMS_LIMIT_quant) {
    boxWithNmsLimitOpTest(ANEURALNETWORKS_TENSOR_QUANT8_ASYMM, ANEURALNETWORKS_TENSOR_QUANT16_ASYMM,
                          ANEURALNETWORKS_FLOAT32);
}

void bidirectionlSequenceRNNTest(int32_t inputOperandCode) {
    const uint32_t batchSize = 2;
    const uint32_t maxTime = 3;
    const uint32_t inputSize = 4;
    const uint32_t numUnits = 5;

    uint32_t inputDims[3] = {maxTime, batchSize, inputSize};
    uint32_t weightsDims[2] = {inputSize, numUnits};
    uint32_t recurrentWeightsDims[2] = {numUnits, numUnits};
    uint32_t biasDims[1] = {numUnits};
    uint32_t hiddenStateDims[2] = {batchSize, numUnits};
    uint32_t outputDims[2] = {batchSize, numUnits};

    ANeuralNetworksOperandType input = {.type = inputOperandCode,
                                        .dimensionCount = 3,
                                        .dimensions = inputDims,
                                        .scale = 0.0f,
                                        .zeroPoint = 0};
    ANeuralNetworksOperandType fwWeights = {.type = inputOperandCode,
                                            .dimensionCount = 2,
                                            .dimensions = weightsDims,
                                            .scale = 0.0f,
                                            .zeroPoint = 0};
    ANeuralNetworksOperandType bwWeights = fwWeights;
    ANeuralNetworksOperandType fwRecurrentWeights = {.type = inputOperandCode,
                                                     .dimensionCount = 2,
                                                     .dimensions = recurrentWeightsDims,
                                                     .scale = 0.0f,
                                                     .zeroPoint = 0};
    ANeuralNetworksOperandType bwRecurrentWeights = fwRecurrentWeights;
    ANeuralNetworksOperandType fwBias = {.type = inputOperandCode,
                                         .dimensionCount = 1,
                                         .dimensions = biasDims,
                                         .scale = 0.0f,
                                         .zeroPoint = 0};
    ANeuralNetworksOperandType bwBias = fwBias;
    ANeuralNetworksOperandType fwHiddenState = {.type = inputOperandCode,
                                                .dimensionCount = 2,
                                                .dimensions = hiddenStateDims,
                                                .scale = 0.0f,
                                                .zeroPoint = 0};
    ANeuralNetworksOperandType bwHiddenState = fwHiddenState;
    ANeuralNetworksOperandType output = {.type = inputOperandCode,
                                         .dimensionCount = 2,
                                         .dimensions = outputDims,
                                         .scale = 0.0f,
                                         .zeroPoint = 0};
    ANeuralNetworksOperandType activation = {.type = ANEURALNETWORKS_INT32,
                                             .dimensionCount = 0,
                                             .dimensions = nullptr,
                                             .scale = 0.0f,
                                             .zeroPoint = 0};
    ANeuralNetworksOperandType boolScalar = {.type = ANEURALNETWORKS_BOOL,
                                             .dimensionCount = 0,
                                             .dimensions = nullptr,
                                             .scale = 0.0f,
                                             .zeroPoint = 0};
    ANeuralNetworksOperandType timeMajor = boolScalar;
    ANeuralNetworksOperandType mergeOutputs = boolScalar;

    OperationTestBase rnnTest(ANEURALNETWORKS_BIDIRECTIONAL_SEQUENCE_RNN,
                              {input, fwWeights, fwRecurrentWeights, fwBias, fwHiddenState,
                               bwWeights, bwRecurrentWeights, bwBias, bwHiddenState, input,
                               fwWeights, bwWeights, activation, timeMajor, mergeOutputs},
                              {output, output});

    EXPECT_TRUE(rnnTest.testMutatingInputOperandCode());
    EXPECT_TRUE(rnnTest.testMutatingInputOperandCounts());
    EXPECT_TRUE(rnnTest.testMutatingOutputOperandCode());
    EXPECT_TRUE(rnnTest.testMutatingOutputOperandCounts());
}

TEST(OperationValidationTest, BIDIRECTIONAL_SEQUENCE_RNN_float32) {
    bidirectionlSequenceRNNTest(ANEURALNETWORKS_TENSOR_FLOAT32);
}

TEST(OperationValidationTest, BIDIRECTIONAL_SEQUENCE_RNN_float16) {
    bidirectionlSequenceRNNTest(ANEURALNETWORKS_TENSOR_FLOAT16);
}

void unidirectionlSequenceRNNTest(int32_t inputOperandCode) {
    const uint32_t batchSize = 2;
    const uint32_t maxTime = 3;
    const uint32_t inputSize = 4;
    const uint32_t numUnits = 5;

    uint32_t inputDims[3] = {maxTime, batchSize, inputSize};
    uint32_t weightsDims[2] = {inputSize, numUnits};
    uint32_t recurrentWeightsDims[2] = {numUnits, numUnits};
    uint32_t biasDims[1] = {numUnits};
    uint32_t hiddenStateDims[2] = {batchSize, numUnits};
    uint32_t outputDims[2] = {batchSize, numUnits};

    ANeuralNetworksOperandType input = {.type = inputOperandCode,
                                        .dimensionCount = 3,
                                        .dimensions = inputDims,
                                        .scale = 0.0f,
                                        .zeroPoint = 0};
    ANeuralNetworksOperandType weights = {.type = inputOperandCode,
                                          .dimensionCount = 2,
                                          .dimensions = weightsDims,
                                          .scale = 0.0f,
                                          .zeroPoint = 0};
    ANeuralNetworksOperandType recurrentWeights = {.type = inputOperandCode,
                                                   .dimensionCount = 2,
                                                   .dimensions = recurrentWeightsDims,
                                                   .scale = 0.0f,
                                                   .zeroPoint = 0};
    ANeuralNetworksOperandType bias = {.type = inputOperandCode,
                                       .dimensionCount = 1,
                                       .dimensions = biasDims,
                                       .scale = 0.0f,
                                       .zeroPoint = 0};
    ANeuralNetworksOperandType hiddenState = {.type = inputOperandCode,
                                              .dimensionCount = 2,
                                              .dimensions = hiddenStateDims,
                                              .scale = 0.0f,
                                              .zeroPoint = 0};
    ANeuralNetworksOperandType output = {.type = inputOperandCode,
                                         .dimensionCount = 2,
                                         .dimensions = outputDims,
                                         .scale = 0.0f,
                                         .zeroPoint = 0};
    ANeuralNetworksOperandType intScalar = {.type = ANEURALNETWORKS_INT32,
                                            .dimensionCount = 0,
                                            .dimensions = nullptr,
                                            .scale = 0.0f,
                                            .zeroPoint = 0};
    ANeuralNetworksOperandType activation = intScalar;
    ANeuralNetworksOperandType timeMajor = intScalar;

    OperationTestBase rnnTest(
            ANEURALNETWORKS_UNIDIRECTIONAL_SEQUENCE_RNN,
            {input, weights, recurrentWeights, bias, hiddenState, activation, timeMajor}, {output});

    EXPECT_TRUE(rnnTest.testMutatingInputOperandCode());
    EXPECT_TRUE(rnnTest.testMutatingInputOperandCounts());
    EXPECT_TRUE(rnnTest.testMutatingOutputOperandCode());
    EXPECT_TRUE(rnnTest.testMutatingOutputOperandCounts());
}

TEST(OperationValidationTest, UNIDIRECTIONAL_SEQUENCE_RNN_float32) {
    unidirectionlSequenceRNNTest(ANEURALNETWORKS_TENSOR_FLOAT32);
}

TEST(OperationValidationTest, UNIDIRECTIONAL_SEQUENCE_RNN_float16) {
    unidirectionlSequenceRNNTest(ANEURALNETWORKS_TENSOR_FLOAT16);
}

void generateProposalsOpTest(int32_t scoreOperandCode, int32_t deltaOperandCode,
                             int32_t anchorOperandCode, int32_t roiOperandCode,
                             int32_t scalarOperandCode) {
    uint32_t scoreDim[] = {1, 2, 2, 2}, deltaDim[] = {1, 2, 2, 8}, anchorDim[] = {2, 4},
             imageInfoDim[] = {1, 2};
    uint32_t outScoreDim[] = {4}, outRoiDim[] = {4, 4}, outSplitDim[] = {1};
    OperationTestBase generateProposalsTest(
            ANEURALNETWORKS_GENERATE_PROPOSALS,
            {getOpType(scoreOperandCode, 4, scoreDim), getOpType(deltaOperandCode, 4, deltaDim),
             getOpType(anchorOperandCode, 2, anchorDim), getOpType(roiOperandCode, 2, imageInfoDim),
             getOpType(scalarOperandCode), getOpType(scalarOperandCode),
             getOpType(ANEURALNETWORKS_INT32), getOpType(ANEURALNETWORKS_INT32),
             getOpType(scalarOperandCode), getOpType(scalarOperandCode)},
            {getOpType(scoreOperandCode, 1, outScoreDim), getOpType(roiOperandCode, 2, outRoiDim),
             getOpType(ANEURALNETWORKS_TENSOR_INT32, 1, outSplitDim)});

    EXPECT_TRUE(generateProposalsTest.testMutatingInputOperandCode());
    EXPECT_TRUE(generateProposalsTest.testMutatingInputOperandCounts());
    EXPECT_TRUE(generateProposalsTest.testMutatingOutputOperandCode());
    EXPECT_TRUE(generateProposalsTest.testMutatingOutputOperandCounts());
}

TEST(OperationValidationTest, GENERATE_PROPOSALS_float16) {
    generateProposalsOpTest(ANEURALNETWORKS_TENSOR_FLOAT16, ANEURALNETWORKS_TENSOR_FLOAT16,
                            ANEURALNETWORKS_TENSOR_FLOAT16, ANEURALNETWORKS_TENSOR_FLOAT16,
                            ANEURALNETWORKS_FLOAT16);
}

TEST(OperationValidationTest, GENERATE_PROPOSALS_float32) {
    generateProposalsOpTest(ANEURALNETWORKS_TENSOR_FLOAT32, ANEURALNETWORKS_TENSOR_FLOAT32,
                            ANEURALNETWORKS_TENSOR_FLOAT32, ANEURALNETWORKS_TENSOR_FLOAT32,
                            ANEURALNETWORKS_FLOAT32);
}

TEST(OperationValidationTest, GENERATE_PROPOSALS_quant) {
    generateProposalsOpTest(ANEURALNETWORKS_TENSOR_QUANT8_ASYMM,
                            ANEURALNETWORKS_TENSOR_QUANT8_ASYMM,
                            ANEURALNETWORKS_TENSOR_QUANT16_SYMM,
                            ANEURALNETWORKS_TENSOR_QUANT16_ASYMM, ANEURALNETWORKS_FLOAT32);
}

}  // end namespace
