// Generated from relu1_float_1_relaxed.mod.py
// DO NOT EDIT
// clang-format off
#include "TestHarness.h"

using namespace test_helper;

namespace generated_tests::relu1_float_1_relaxed {

const TestModel& get_test_model() {
    static TestModel model = {
        .expectedMultinomialDistributionTolerance = 0,
        .inputIndexes = {0},
        .isRelaxed = true,
        .operands = {{
                .channelQuant = {},
                .data = TestBuffer::createFromVector<float>({-10.0f, -0.5f, 0.5f, 10.0f}),
                .dimensions = {1, 2, 2, 1},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_INPUT,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_FLOAT32,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<float>({-1.0f, -0.5f, 0.5f, 1.0f}),
                .dimensions = {1, 2, 2, 1},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_OUTPUT,
                .numberOfConsumers = 0,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_FLOAT32,
                .zeroPoint = 0
            }},
        .operations = {{
                .inputs = {0},
                .outputs = {1},
                .type = TestOperationType::RELU1
            }},
        .outputIndexes = {1}
    };
    return model;
}

}  // namespace generated_tests::relu1_float_1_relaxed

namespace generated_tests::relu1_float_1_relaxed {

const TestModel& get_test_model_all_inputs_as_internal() {
    static TestModel model = {
        .expectedMultinomialDistributionTolerance = 0,
        .inputIndexes = {2},
        .isRelaxed = true,
        .operands = {{
                .channelQuant = {},
                .data = TestBuffer::createFromVector<float>({}),
                .dimensions = {1, 2, 2, 1},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::TEMPORARY_VARIABLE,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_FLOAT32,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<float>({-1.0f, -0.5f, 0.5f, 1.0f}),
                .dimensions = {1, 2, 2, 1},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_OUTPUT,
                .numberOfConsumers = 0,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_FLOAT32,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<float>({-10.0f, -0.5f, 0.5f, 10.0f}),
                .dimensions = {1, 2, 2, 1},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_INPUT,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_FLOAT32,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<float>({0.0f}),
                .dimensions = {1},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::CONSTANT_COPY,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_FLOAT32,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<int32_t>({0}),
                .dimensions = {},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::CONSTANT_COPY,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::INT32,
                .zeroPoint = 0
            }},
        .operations = {{
                .inputs = {2, 3, 4},
                .outputs = {0},
                .type = TestOperationType::ADD
            }, {
                .inputs = {0},
                .outputs = {1},
                .type = TestOperationType::RELU1
            }},
        .outputIndexes = {1}
    };
    return model;
}

}  // namespace generated_tests::relu1_float_1_relaxed
