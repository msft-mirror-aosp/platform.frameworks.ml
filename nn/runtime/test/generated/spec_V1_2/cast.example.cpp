// Generated from cast.mod.py
// DO NOT EDIT
// clang-format off
#include "TestHarness.h"

using namespace test_helper;

namespace generated_tests::cast {

const TestModel& get_test_model_float16_to_float16() {
    static TestModel model = {
        .expectedMultinomialDistributionTolerance = 0,
        .inputIndexes = {0},
        .isRelaxed = false,
        .operands = {{
                .channelQuant = {},
                .data = TestBuffer::createFromVector<_Float16>({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_INPUT,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_FLOAT16,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<_Float16>({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_OUTPUT,
                .numberOfConsumers = 0,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_FLOAT16,
                .zeroPoint = 0
            }},
        .operations = {{
                .inputs = {0},
                .outputs = {1},
                .type = TestOperationType::CAST
            }},
        .outputIndexes = {1}
    };
    return model;
}

}  // namespace generated_tests::cast

namespace generated_tests::cast {

const TestModel& get_test_model_float16_to_float16_all_inputs_as_internal() {
    static TestModel model = {
        .expectedMultinomialDistributionTolerance = 0,
        .inputIndexes = {2},
        .isRelaxed = false,
        .operands = {{
                .channelQuant = {},
                .data = TestBuffer::createFromVector<_Float16>({}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::TEMPORARY_VARIABLE,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_FLOAT16,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<_Float16>({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_OUTPUT,
                .numberOfConsumers = 0,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_FLOAT16,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<_Float16>({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_INPUT,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_FLOAT16,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<_Float16>({0.0f}),
                .dimensions = {1},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::CONSTANT_COPY,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_FLOAT16,
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
                .type = TestOperationType::CAST
            }},
        .outputIndexes = {1}
    };
    return model;
}

}  // namespace generated_tests::cast

namespace generated_tests::cast {

const TestModel& get_test_model_float16_to_float32() {
    static TestModel model = {
        .expectedMultinomialDistributionTolerance = 0,
        .inputIndexes = {0},
        .isRelaxed = false,
        .operands = {{
                .channelQuant = {},
                .data = TestBuffer::createFromVector<_Float16>({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_INPUT,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_FLOAT16,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<float>({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f}),
                .dimensions = {2, 3},
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
                .type = TestOperationType::CAST
            }},
        .outputIndexes = {1}
    };
    return model;
}

}  // namespace generated_tests::cast

namespace generated_tests::cast {

const TestModel& get_test_model_float16_to_float32_all_inputs_as_internal() {
    static TestModel model = {
        .expectedMultinomialDistributionTolerance = 0,
        .inputIndexes = {2},
        .isRelaxed = false,
        .operands = {{
                .channelQuant = {},
                .data = TestBuffer::createFromVector<_Float16>({}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::TEMPORARY_VARIABLE,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_FLOAT16,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<float>({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_OUTPUT,
                .numberOfConsumers = 0,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_FLOAT32,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<_Float16>({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_INPUT,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_FLOAT16,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<_Float16>({0.0f}),
                .dimensions = {1},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::CONSTANT_COPY,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_FLOAT16,
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
                .type = TestOperationType::CAST
            }},
        .outputIndexes = {1}
    };
    return model;
}

}  // namespace generated_tests::cast

namespace generated_tests::cast {

const TestModel& get_test_model_float16_to_float32_relaxed() {
    static TestModel model = {
        .expectedMultinomialDistributionTolerance = 0,
        .inputIndexes = {0},
        .isRelaxed = true,
        .operands = {{
                .channelQuant = {},
                .data = TestBuffer::createFromVector<_Float16>({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_INPUT,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_FLOAT16,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<float>({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f}),
                .dimensions = {2, 3},
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
                .type = TestOperationType::CAST
            }},
        .outputIndexes = {1}
    };
    return model;
}

}  // namespace generated_tests::cast

namespace generated_tests::cast {

const TestModel& get_test_model_float16_to_float32_relaxed_all_inputs_as_internal() {
    static TestModel model = {
        .expectedMultinomialDistributionTolerance = 0,
        .inputIndexes = {2},
        .isRelaxed = true,
        .operands = {{
                .channelQuant = {},
                .data = TestBuffer::createFromVector<_Float16>({}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::TEMPORARY_VARIABLE,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_FLOAT16,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<float>({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_OUTPUT,
                .numberOfConsumers = 0,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_FLOAT32,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<_Float16>({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_INPUT,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_FLOAT16,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<_Float16>({0.0f}),
                .dimensions = {1},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::CONSTANT_COPY,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_FLOAT16,
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
                .type = TestOperationType::CAST
            }},
        .outputIndexes = {1}
    };
    return model;
}

}  // namespace generated_tests::cast

namespace generated_tests::cast {

const TestModel& get_test_model_float16_to_int32() {
    static TestModel model = {
        .expectedMultinomialDistributionTolerance = 0,
        .inputIndexes = {0},
        .isRelaxed = false,
        .operands = {{
                .channelQuant = {},
                .data = TestBuffer::createFromVector<_Float16>({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_INPUT,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_FLOAT16,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<int32_t>({1, 2, 3, 4, 5, 6}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_OUTPUT,
                .numberOfConsumers = 0,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_INT32,
                .zeroPoint = 0
            }},
        .operations = {{
                .inputs = {0},
                .outputs = {1},
                .type = TestOperationType::CAST
            }},
        .outputIndexes = {1}
    };
    return model;
}

}  // namespace generated_tests::cast

namespace generated_tests::cast {

const TestModel& get_test_model_float16_to_int32_all_inputs_as_internal() {
    static TestModel model = {
        .expectedMultinomialDistributionTolerance = 0,
        .inputIndexes = {2},
        .isRelaxed = false,
        .operands = {{
                .channelQuant = {},
                .data = TestBuffer::createFromVector<_Float16>({}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::TEMPORARY_VARIABLE,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_FLOAT16,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<int32_t>({1, 2, 3, 4, 5, 6}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_OUTPUT,
                .numberOfConsumers = 0,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_INT32,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<_Float16>({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_INPUT,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_FLOAT16,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<_Float16>({0.0f}),
                .dimensions = {1},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::CONSTANT_COPY,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_FLOAT16,
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
                .type = TestOperationType::CAST
            }},
        .outputIndexes = {1}
    };
    return model;
}

}  // namespace generated_tests::cast

namespace generated_tests::cast {

const TestModel& get_test_model_float16_to_quant8() {
    static TestModel model = {
        .expectedMultinomialDistributionTolerance = 0,
        .inputIndexes = {0},
        .isRelaxed = false,
        .operands = {{
                .channelQuant = {},
                .data = TestBuffer::createFromVector<_Float16>({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_INPUT,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_FLOAT16,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<uint8_t>({1, 2, 3, 4, 5, 6}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_OUTPUT,
                .numberOfConsumers = 0,
                .scale = 4.0f,
                .type = TestOperandType::TENSOR_QUANT8_ASYMM,
                .zeroPoint = 100
            }},
        .operations = {{
                .inputs = {0},
                .outputs = {1},
                .type = TestOperationType::CAST
            }},
        .outputIndexes = {1}
    };
    return model;
}

}  // namespace generated_tests::cast

namespace generated_tests::cast {

const TestModel& get_test_model_float16_to_quant8_all_inputs_as_internal() {
    static TestModel model = {
        .expectedMultinomialDistributionTolerance = 0,
        .inputIndexes = {2},
        .isRelaxed = false,
        .operands = {{
                .channelQuant = {},
                .data = TestBuffer::createFromVector<_Float16>({}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::TEMPORARY_VARIABLE,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_FLOAT16,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<uint8_t>({1, 2, 3, 4, 5, 6}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_OUTPUT,
                .numberOfConsumers = 0,
                .scale = 4.0f,
                .type = TestOperandType::TENSOR_QUANT8_ASYMM,
                .zeroPoint = 100
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<_Float16>({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_INPUT,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_FLOAT16,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<_Float16>({0.0f}),
                .dimensions = {1},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::CONSTANT_COPY,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_FLOAT16,
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
                .type = TestOperationType::CAST
            }},
        .outputIndexes = {1}
    };
    return model;
}

}  // namespace generated_tests::cast

namespace generated_tests::cast {

const TestModel& get_test_model_float32_to_float16() {
    static TestModel model = {
        .expectedMultinomialDistributionTolerance = 0,
        .inputIndexes = {0},
        .isRelaxed = false,
        .operands = {{
                .channelQuant = {},
                .data = TestBuffer::createFromVector<float>({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_INPUT,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_FLOAT32,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<_Float16>({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_OUTPUT,
                .numberOfConsumers = 0,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_FLOAT16,
                .zeroPoint = 0
            }},
        .operations = {{
                .inputs = {0},
                .outputs = {1},
                .type = TestOperationType::CAST
            }},
        .outputIndexes = {1}
    };
    return model;
}

}  // namespace generated_tests::cast

namespace generated_tests::cast {

const TestModel& get_test_model_float32_to_float16_all_inputs_as_internal() {
    static TestModel model = {
        .expectedMultinomialDistributionTolerance = 0,
        .inputIndexes = {2},
        .isRelaxed = false,
        .operands = {{
                .channelQuant = {},
                .data = TestBuffer::createFromVector<float>({}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::TEMPORARY_VARIABLE,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_FLOAT32,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<_Float16>({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_OUTPUT,
                .numberOfConsumers = 0,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_FLOAT16,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<float>({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f}),
                .dimensions = {2, 3},
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
                .type = TestOperationType::CAST
            }},
        .outputIndexes = {1}
    };
    return model;
}

}  // namespace generated_tests::cast

namespace generated_tests::cast {

const TestModel& get_test_model_float32_to_float16_relaxed() {
    static TestModel model = {
        .expectedMultinomialDistributionTolerance = 0,
        .inputIndexes = {0},
        .isRelaxed = true,
        .operands = {{
                .channelQuant = {},
                .data = TestBuffer::createFromVector<float>({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_INPUT,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_FLOAT32,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<_Float16>({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_OUTPUT,
                .numberOfConsumers = 0,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_FLOAT16,
                .zeroPoint = 0
            }},
        .operations = {{
                .inputs = {0},
                .outputs = {1},
                .type = TestOperationType::CAST
            }},
        .outputIndexes = {1}
    };
    return model;
}

}  // namespace generated_tests::cast

namespace generated_tests::cast {

const TestModel& get_test_model_float32_to_float16_relaxed_all_inputs_as_internal() {
    static TestModel model = {
        .expectedMultinomialDistributionTolerance = 0,
        .inputIndexes = {2},
        .isRelaxed = true,
        .operands = {{
                .channelQuant = {},
                .data = TestBuffer::createFromVector<float>({}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::TEMPORARY_VARIABLE,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_FLOAT32,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<_Float16>({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_OUTPUT,
                .numberOfConsumers = 0,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_FLOAT16,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<float>({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f}),
                .dimensions = {2, 3},
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
                .type = TestOperationType::CAST
            }},
        .outputIndexes = {1}
    };
    return model;
}

}  // namespace generated_tests::cast

namespace generated_tests::cast {

const TestModel& get_test_model_float32_to_float32() {
    static TestModel model = {
        .expectedMultinomialDistributionTolerance = 0,
        .inputIndexes = {0},
        .isRelaxed = false,
        .operands = {{
                .channelQuant = {},
                .data = TestBuffer::createFromVector<float>({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_INPUT,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_FLOAT32,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<float>({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f}),
                .dimensions = {2, 3},
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
                .type = TestOperationType::CAST
            }},
        .outputIndexes = {1}
    };
    return model;
}

}  // namespace generated_tests::cast

namespace generated_tests::cast {

const TestModel& get_test_model_float32_to_float32_all_inputs_as_internal() {
    static TestModel model = {
        .expectedMultinomialDistributionTolerance = 0,
        .inputIndexes = {2},
        .isRelaxed = false,
        .operands = {{
                .channelQuant = {},
                .data = TestBuffer::createFromVector<float>({}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::TEMPORARY_VARIABLE,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_FLOAT32,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<float>({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_OUTPUT,
                .numberOfConsumers = 0,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_FLOAT32,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<float>({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f}),
                .dimensions = {2, 3},
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
                .type = TestOperationType::CAST
            }},
        .outputIndexes = {1}
    };
    return model;
}

}  // namespace generated_tests::cast

namespace generated_tests::cast {

const TestModel& get_test_model_float32_to_float32_relaxed() {
    static TestModel model = {
        .expectedMultinomialDistributionTolerance = 0,
        .inputIndexes = {0},
        .isRelaxed = true,
        .operands = {{
                .channelQuant = {},
                .data = TestBuffer::createFromVector<float>({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_INPUT,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_FLOAT32,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<float>({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f}),
                .dimensions = {2, 3},
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
                .type = TestOperationType::CAST
            }},
        .outputIndexes = {1}
    };
    return model;
}

}  // namespace generated_tests::cast

namespace generated_tests::cast {

const TestModel& get_test_model_float32_to_float32_relaxed_all_inputs_as_internal() {
    static TestModel model = {
        .expectedMultinomialDistributionTolerance = 0,
        .inputIndexes = {2},
        .isRelaxed = true,
        .operands = {{
                .channelQuant = {},
                .data = TestBuffer::createFromVector<float>({}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::TEMPORARY_VARIABLE,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_FLOAT32,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<float>({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_OUTPUT,
                .numberOfConsumers = 0,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_FLOAT32,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<float>({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f}),
                .dimensions = {2, 3},
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
                .type = TestOperationType::CAST
            }},
        .outputIndexes = {1}
    };
    return model;
}

}  // namespace generated_tests::cast

namespace generated_tests::cast {

const TestModel& get_test_model_float32_to_int32() {
    static TestModel model = {
        .expectedMultinomialDistributionTolerance = 0,
        .inputIndexes = {0},
        .isRelaxed = false,
        .operands = {{
                .channelQuant = {},
                .data = TestBuffer::createFromVector<float>({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_INPUT,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_FLOAT32,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<int32_t>({1, 2, 3, 4, 5, 6}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_OUTPUT,
                .numberOfConsumers = 0,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_INT32,
                .zeroPoint = 0
            }},
        .operations = {{
                .inputs = {0},
                .outputs = {1},
                .type = TestOperationType::CAST
            }},
        .outputIndexes = {1}
    };
    return model;
}

}  // namespace generated_tests::cast

namespace generated_tests::cast {

const TestModel& get_test_model_float32_to_int32_all_inputs_as_internal() {
    static TestModel model = {
        .expectedMultinomialDistributionTolerance = 0,
        .inputIndexes = {2},
        .isRelaxed = false,
        .operands = {{
                .channelQuant = {},
                .data = TestBuffer::createFromVector<float>({}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::TEMPORARY_VARIABLE,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_FLOAT32,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<int32_t>({1, 2, 3, 4, 5, 6}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_OUTPUT,
                .numberOfConsumers = 0,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_INT32,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<float>({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f}),
                .dimensions = {2, 3},
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
                .type = TestOperationType::CAST
            }},
        .outputIndexes = {1}
    };
    return model;
}

}  // namespace generated_tests::cast

namespace generated_tests::cast {

const TestModel& get_test_model_float32_to_int32_relaxed() {
    static TestModel model = {
        .expectedMultinomialDistributionTolerance = 0,
        .inputIndexes = {0},
        .isRelaxed = true,
        .operands = {{
                .channelQuant = {},
                .data = TestBuffer::createFromVector<float>({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_INPUT,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_FLOAT32,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<int32_t>({1, 2, 3, 4, 5, 6}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_OUTPUT,
                .numberOfConsumers = 0,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_INT32,
                .zeroPoint = 0
            }},
        .operations = {{
                .inputs = {0},
                .outputs = {1},
                .type = TestOperationType::CAST
            }},
        .outputIndexes = {1}
    };
    return model;
}

}  // namespace generated_tests::cast

namespace generated_tests::cast {

const TestModel& get_test_model_float32_to_int32_relaxed_all_inputs_as_internal() {
    static TestModel model = {
        .expectedMultinomialDistributionTolerance = 0,
        .inputIndexes = {2},
        .isRelaxed = true,
        .operands = {{
                .channelQuant = {},
                .data = TestBuffer::createFromVector<float>({}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::TEMPORARY_VARIABLE,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_FLOAT32,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<int32_t>({1, 2, 3, 4, 5, 6}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_OUTPUT,
                .numberOfConsumers = 0,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_INT32,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<float>({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f}),
                .dimensions = {2, 3},
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
                .type = TestOperationType::CAST
            }},
        .outputIndexes = {1}
    };
    return model;
}

}  // namespace generated_tests::cast

namespace generated_tests::cast {

const TestModel& get_test_model_float32_to_quant8() {
    static TestModel model = {
        .expectedMultinomialDistributionTolerance = 0,
        .inputIndexes = {0},
        .isRelaxed = false,
        .operands = {{
                .channelQuant = {},
                .data = TestBuffer::createFromVector<float>({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_INPUT,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_FLOAT32,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<uint8_t>({1, 2, 3, 4, 5, 6}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_OUTPUT,
                .numberOfConsumers = 0,
                .scale = 4.0f,
                .type = TestOperandType::TENSOR_QUANT8_ASYMM,
                .zeroPoint = 100
            }},
        .operations = {{
                .inputs = {0},
                .outputs = {1},
                .type = TestOperationType::CAST
            }},
        .outputIndexes = {1}
    };
    return model;
}

}  // namespace generated_tests::cast

namespace generated_tests::cast {

const TestModel& get_test_model_float32_to_quant8_all_inputs_as_internal() {
    static TestModel model = {
        .expectedMultinomialDistributionTolerance = 0,
        .inputIndexes = {2},
        .isRelaxed = false,
        .operands = {{
                .channelQuant = {},
                .data = TestBuffer::createFromVector<float>({}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::TEMPORARY_VARIABLE,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_FLOAT32,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<uint8_t>({1, 2, 3, 4, 5, 6}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_OUTPUT,
                .numberOfConsumers = 0,
                .scale = 4.0f,
                .type = TestOperandType::TENSOR_QUANT8_ASYMM,
                .zeroPoint = 100
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<float>({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f}),
                .dimensions = {2, 3},
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
                .type = TestOperationType::CAST
            }},
        .outputIndexes = {1}
    };
    return model;
}

}  // namespace generated_tests::cast

namespace generated_tests::cast {

const TestModel& get_test_model_float32_to_quant8_relaxed() {
    static TestModel model = {
        .expectedMultinomialDistributionTolerance = 0,
        .inputIndexes = {0},
        .isRelaxed = true,
        .operands = {{
                .channelQuant = {},
                .data = TestBuffer::createFromVector<float>({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_INPUT,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_FLOAT32,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<uint8_t>({1, 2, 3, 4, 5, 6}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_OUTPUT,
                .numberOfConsumers = 0,
                .scale = 4.0f,
                .type = TestOperandType::TENSOR_QUANT8_ASYMM,
                .zeroPoint = 100
            }},
        .operations = {{
                .inputs = {0},
                .outputs = {1},
                .type = TestOperationType::CAST
            }},
        .outputIndexes = {1}
    };
    return model;
}

}  // namespace generated_tests::cast

namespace generated_tests::cast {

const TestModel& get_test_model_float32_to_quant8_relaxed_all_inputs_as_internal() {
    static TestModel model = {
        .expectedMultinomialDistributionTolerance = 0,
        .inputIndexes = {2},
        .isRelaxed = true,
        .operands = {{
                .channelQuant = {},
                .data = TestBuffer::createFromVector<float>({}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::TEMPORARY_VARIABLE,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_FLOAT32,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<uint8_t>({1, 2, 3, 4, 5, 6}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_OUTPUT,
                .numberOfConsumers = 0,
                .scale = 4.0f,
                .type = TestOperandType::TENSOR_QUANT8_ASYMM,
                .zeroPoint = 100
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<float>({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f}),
                .dimensions = {2, 3},
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
                .type = TestOperationType::CAST
            }},
        .outputIndexes = {1}
    };
    return model;
}

}  // namespace generated_tests::cast

namespace generated_tests::cast {

const TestModel& get_test_model_int32_to_float16() {
    static TestModel model = {
        .expectedMultinomialDistributionTolerance = 0,
        .inputIndexes = {0},
        .isRelaxed = false,
        .operands = {{
                .channelQuant = {},
                .data = TestBuffer::createFromVector<int32_t>({1, 2, 3, 4, 5, 6}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_INPUT,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_INT32,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<_Float16>({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_OUTPUT,
                .numberOfConsumers = 0,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_FLOAT16,
                .zeroPoint = 0
            }},
        .operations = {{
                .inputs = {0},
                .outputs = {1},
                .type = TestOperationType::CAST
            }},
        .outputIndexes = {1}
    };
    return model;
}

}  // namespace generated_tests::cast

namespace generated_tests::cast {

const TestModel& get_test_model_int32_to_float32() {
    static TestModel model = {
        .expectedMultinomialDistributionTolerance = 0,
        .inputIndexes = {0},
        .isRelaxed = false,
        .operands = {{
                .channelQuant = {},
                .data = TestBuffer::createFromVector<int32_t>({1, 2, 3, 4, 5, 6}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_INPUT,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_INT32,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<float>({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f}),
                .dimensions = {2, 3},
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
                .type = TestOperationType::CAST
            }},
        .outputIndexes = {1}
    };
    return model;
}

}  // namespace generated_tests::cast

namespace generated_tests::cast {

const TestModel& get_test_model_int32_to_float32_relaxed() {
    static TestModel model = {
        .expectedMultinomialDistributionTolerance = 0,
        .inputIndexes = {0},
        .isRelaxed = true,
        .operands = {{
                .channelQuant = {},
                .data = TestBuffer::createFromVector<int32_t>({1, 2, 3, 4, 5, 6}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_INPUT,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_INT32,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<float>({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f}),
                .dimensions = {2, 3},
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
                .type = TestOperationType::CAST
            }},
        .outputIndexes = {1}
    };
    return model;
}

}  // namespace generated_tests::cast

namespace generated_tests::cast {

const TestModel& get_test_model_int32_to_int32() {
    static TestModel model = {
        .expectedMultinomialDistributionTolerance = 0,
        .inputIndexes = {0},
        .isRelaxed = false,
        .operands = {{
                .channelQuant = {},
                .data = TestBuffer::createFromVector<int32_t>({1, 2, 3, 4, 5, 6}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_INPUT,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_INT32,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<int32_t>({1, 2, 3, 4, 5, 6}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_OUTPUT,
                .numberOfConsumers = 0,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_INT32,
                .zeroPoint = 0
            }},
        .operations = {{
                .inputs = {0},
                .outputs = {1},
                .type = TestOperationType::CAST
            }},
        .outputIndexes = {1}
    };
    return model;
}

}  // namespace generated_tests::cast

namespace generated_tests::cast {

const TestModel& get_test_model_int32_to_quant8() {
    static TestModel model = {
        .expectedMultinomialDistributionTolerance = 0,
        .inputIndexes = {0},
        .isRelaxed = false,
        .operands = {{
                .channelQuant = {},
                .data = TestBuffer::createFromVector<int32_t>({1, 2, 3, 4, 5, 6}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_INPUT,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_INT32,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<uint8_t>({1, 2, 3, 4, 5, 6}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_OUTPUT,
                .numberOfConsumers = 0,
                .scale = 4.0f,
                .type = TestOperandType::TENSOR_QUANT8_ASYMM,
                .zeroPoint = 100
            }},
        .operations = {{
                .inputs = {0},
                .outputs = {1},
                .type = TestOperationType::CAST
            }},
        .outputIndexes = {1}
    };
    return model;
}

}  // namespace generated_tests::cast

namespace generated_tests::cast {

const TestModel& get_test_model_quant8_to_float16() {
    static TestModel model = {
        .expectedMultinomialDistributionTolerance = 0,
        .inputIndexes = {0},
        .isRelaxed = false,
        .operands = {{
                .channelQuant = {},
                .data = TestBuffer::createFromVector<uint8_t>({1, 2, 3, 4, 5, 6}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_INPUT,
                .numberOfConsumers = 1,
                .scale = 4.0f,
                .type = TestOperandType::TENSOR_QUANT8_ASYMM,
                .zeroPoint = 100
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<_Float16>({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_OUTPUT,
                .numberOfConsumers = 0,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_FLOAT16,
                .zeroPoint = 0
            }},
        .operations = {{
                .inputs = {0},
                .outputs = {1},
                .type = TestOperationType::CAST
            }},
        .outputIndexes = {1}
    };
    return model;
}

}  // namespace generated_tests::cast

namespace generated_tests::cast {

const TestModel& get_test_model_quant8_to_float16_all_inputs_as_internal() {
    static TestModel model = {
        .expectedMultinomialDistributionTolerance = 0,
        .inputIndexes = {2},
        .isRelaxed = false,
        .operands = {{
                .channelQuant = {},
                .data = TestBuffer::createFromVector<uint8_t>({}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::TEMPORARY_VARIABLE,
                .numberOfConsumers = 1,
                .scale = 4.0f,
                .type = TestOperandType::TENSOR_QUANT8_ASYMM,
                .zeroPoint = 100
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<_Float16>({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_OUTPUT,
                .numberOfConsumers = 0,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_FLOAT16,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<uint8_t>({1, 2, 3, 4, 5, 6}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_INPUT,
                .numberOfConsumers = 1,
                .scale = 4.0f,
                .type = TestOperandType::TENSOR_QUANT8_ASYMM,
                .zeroPoint = 100
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<uint8_t>({100}),
                .dimensions = {1},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::CONSTANT_COPY,
                .numberOfConsumers = 1,
                .scale = 4.0f,
                .type = TestOperandType::TENSOR_QUANT8_ASYMM,
                .zeroPoint = 100
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
                .type = TestOperationType::CAST
            }},
        .outputIndexes = {1}
    };
    return model;
}

}  // namespace generated_tests::cast

namespace generated_tests::cast {

const TestModel& get_test_model_quant8_to_float32() {
    static TestModel model = {
        .expectedMultinomialDistributionTolerance = 0,
        .inputIndexes = {0},
        .isRelaxed = false,
        .operands = {{
                .channelQuant = {},
                .data = TestBuffer::createFromVector<uint8_t>({1, 2, 3, 4, 5, 6}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_INPUT,
                .numberOfConsumers = 1,
                .scale = 4.0f,
                .type = TestOperandType::TENSOR_QUANT8_ASYMM,
                .zeroPoint = 100
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<float>({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f}),
                .dimensions = {2, 3},
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
                .type = TestOperationType::CAST
            }},
        .outputIndexes = {1}
    };
    return model;
}

}  // namespace generated_tests::cast

namespace generated_tests::cast {

const TestModel& get_test_model_quant8_to_float32_all_inputs_as_internal() {
    static TestModel model = {
        .expectedMultinomialDistributionTolerance = 0,
        .inputIndexes = {2},
        .isRelaxed = false,
        .operands = {{
                .channelQuant = {},
                .data = TestBuffer::createFromVector<uint8_t>({}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::TEMPORARY_VARIABLE,
                .numberOfConsumers = 1,
                .scale = 4.0f,
                .type = TestOperandType::TENSOR_QUANT8_ASYMM,
                .zeroPoint = 100
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<float>({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_OUTPUT,
                .numberOfConsumers = 0,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_FLOAT32,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<uint8_t>({1, 2, 3, 4, 5, 6}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_INPUT,
                .numberOfConsumers = 1,
                .scale = 4.0f,
                .type = TestOperandType::TENSOR_QUANT8_ASYMM,
                .zeroPoint = 100
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<uint8_t>({100}),
                .dimensions = {1},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::CONSTANT_COPY,
                .numberOfConsumers = 1,
                .scale = 4.0f,
                .type = TestOperandType::TENSOR_QUANT8_ASYMM,
                .zeroPoint = 100
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
                .type = TestOperationType::CAST
            }},
        .outputIndexes = {1}
    };
    return model;
}

}  // namespace generated_tests::cast

namespace generated_tests::cast {

const TestModel& get_test_model_quant8_to_float32_relaxed() {
    static TestModel model = {
        .expectedMultinomialDistributionTolerance = 0,
        .inputIndexes = {0},
        .isRelaxed = true,
        .operands = {{
                .channelQuant = {},
                .data = TestBuffer::createFromVector<uint8_t>({1, 2, 3, 4, 5, 6}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_INPUT,
                .numberOfConsumers = 1,
                .scale = 4.0f,
                .type = TestOperandType::TENSOR_QUANT8_ASYMM,
                .zeroPoint = 100
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<float>({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f}),
                .dimensions = {2, 3},
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
                .type = TestOperationType::CAST
            }},
        .outputIndexes = {1}
    };
    return model;
}

}  // namespace generated_tests::cast

namespace generated_tests::cast {

const TestModel& get_test_model_quant8_to_float32_relaxed_all_inputs_as_internal() {
    static TestModel model = {
        .expectedMultinomialDistributionTolerance = 0,
        .inputIndexes = {2},
        .isRelaxed = true,
        .operands = {{
                .channelQuant = {},
                .data = TestBuffer::createFromVector<uint8_t>({}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::TEMPORARY_VARIABLE,
                .numberOfConsumers = 1,
                .scale = 4.0f,
                .type = TestOperandType::TENSOR_QUANT8_ASYMM,
                .zeroPoint = 100
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<float>({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_OUTPUT,
                .numberOfConsumers = 0,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_FLOAT32,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<uint8_t>({1, 2, 3, 4, 5, 6}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_INPUT,
                .numberOfConsumers = 1,
                .scale = 4.0f,
                .type = TestOperandType::TENSOR_QUANT8_ASYMM,
                .zeroPoint = 100
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<uint8_t>({100}),
                .dimensions = {1},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::CONSTANT_COPY,
                .numberOfConsumers = 1,
                .scale = 4.0f,
                .type = TestOperandType::TENSOR_QUANT8_ASYMM,
                .zeroPoint = 100
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
                .type = TestOperationType::CAST
            }},
        .outputIndexes = {1}
    };
    return model;
}

}  // namespace generated_tests::cast

namespace generated_tests::cast {

const TestModel& get_test_model_quant8_to_int32() {
    static TestModel model = {
        .expectedMultinomialDistributionTolerance = 0,
        .inputIndexes = {0},
        .isRelaxed = false,
        .operands = {{
                .channelQuant = {},
                .data = TestBuffer::createFromVector<uint8_t>({1, 2, 3, 4, 5, 6}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_INPUT,
                .numberOfConsumers = 1,
                .scale = 4.0f,
                .type = TestOperandType::TENSOR_QUANT8_ASYMM,
                .zeroPoint = 100
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<int32_t>({1, 2, 3, 4, 5, 6}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_OUTPUT,
                .numberOfConsumers = 0,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_INT32,
                .zeroPoint = 0
            }},
        .operations = {{
                .inputs = {0},
                .outputs = {1},
                .type = TestOperationType::CAST
            }},
        .outputIndexes = {1}
    };
    return model;
}

}  // namespace generated_tests::cast

namespace generated_tests::cast {

const TestModel& get_test_model_quant8_to_int32_all_inputs_as_internal() {
    static TestModel model = {
        .expectedMultinomialDistributionTolerance = 0,
        .inputIndexes = {2},
        .isRelaxed = false,
        .operands = {{
                .channelQuant = {},
                .data = TestBuffer::createFromVector<uint8_t>({}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::TEMPORARY_VARIABLE,
                .numberOfConsumers = 1,
                .scale = 4.0f,
                .type = TestOperandType::TENSOR_QUANT8_ASYMM,
                .zeroPoint = 100
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<int32_t>({1, 2, 3, 4, 5, 6}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_OUTPUT,
                .numberOfConsumers = 0,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_INT32,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<uint8_t>({1, 2, 3, 4, 5, 6}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_INPUT,
                .numberOfConsumers = 1,
                .scale = 4.0f,
                .type = TestOperandType::TENSOR_QUANT8_ASYMM,
                .zeroPoint = 100
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<uint8_t>({100}),
                .dimensions = {1},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::CONSTANT_COPY,
                .numberOfConsumers = 1,
                .scale = 4.0f,
                .type = TestOperandType::TENSOR_QUANT8_ASYMM,
                .zeroPoint = 100
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
                .type = TestOperationType::CAST
            }},
        .outputIndexes = {1}
    };
    return model;
}

}  // namespace generated_tests::cast

namespace generated_tests::cast {

const TestModel& get_test_model_quant8_to_quant8() {
    static TestModel model = {
        .expectedMultinomialDistributionTolerance = 0,
        .inputIndexes = {0},
        .isRelaxed = false,
        .operands = {{
                .channelQuant = {},
                .data = TestBuffer::createFromVector<uint8_t>({1, 2, 3, 4, 5, 6}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_INPUT,
                .numberOfConsumers = 1,
                .scale = 4.0f,
                .type = TestOperandType::TENSOR_QUANT8_ASYMM,
                .zeroPoint = 100
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<uint8_t>({1, 2, 3, 4, 5, 6}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_OUTPUT,
                .numberOfConsumers = 0,
                .scale = 4.0f,
                .type = TestOperandType::TENSOR_QUANT8_ASYMM,
                .zeroPoint = 100
            }},
        .operations = {{
                .inputs = {0},
                .outputs = {1},
                .type = TestOperationType::CAST
            }},
        .outputIndexes = {1}
    };
    return model;
}

}  // namespace generated_tests::cast

namespace generated_tests::cast {

const TestModel& get_test_model_quant8_to_quant8_all_inputs_as_internal() {
    static TestModel model = {
        .expectedMultinomialDistributionTolerance = 0,
        .inputIndexes = {2},
        .isRelaxed = false,
        .operands = {{
                .channelQuant = {},
                .data = TestBuffer::createFromVector<uint8_t>({}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::TEMPORARY_VARIABLE,
                .numberOfConsumers = 1,
                .scale = 4.0f,
                .type = TestOperandType::TENSOR_QUANT8_ASYMM,
                .zeroPoint = 100
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<uint8_t>({1, 2, 3, 4, 5, 6}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_OUTPUT,
                .numberOfConsumers = 0,
                .scale = 4.0f,
                .type = TestOperandType::TENSOR_QUANT8_ASYMM,
                .zeroPoint = 100
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<uint8_t>({1, 2, 3, 4, 5, 6}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_INPUT,
                .numberOfConsumers = 1,
                .scale = 4.0f,
                .type = TestOperandType::TENSOR_QUANT8_ASYMM,
                .zeroPoint = 100
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<uint8_t>({100}),
                .dimensions = {1},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::CONSTANT_COPY,
                .numberOfConsumers = 1,
                .scale = 4.0f,
                .type = TestOperandType::TENSOR_QUANT8_ASYMM,
                .zeroPoint = 100
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
                .type = TestOperationType::CAST
            }},
        .outputIndexes = {1}
    };
    return model;
}

}  // namespace generated_tests::cast

namespace generated_tests::cast {

const TestModel& get_test_model_float16_to_quant8_overflow() {
    static TestModel model = {
        .expectedMultinomialDistributionTolerance = 0,
        .inputIndexes = {0},
        .isRelaxed = false,
        .operands = {{
                .channelQuant = {},
                .data = TestBuffer::createFromVector<_Float16>({-1.0f, 256.0f}),
                .dimensions = {2},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_INPUT,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_FLOAT16,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<uint8_t>({0, 255}),
                .dimensions = {2},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_OUTPUT,
                .numberOfConsumers = 0,
                .scale = 4.0f,
                .type = TestOperandType::TENSOR_QUANT8_ASYMM,
                .zeroPoint = 100
            }},
        .operations = {{
                .inputs = {0},
                .outputs = {1},
                .type = TestOperationType::CAST
            }},
        .outputIndexes = {1}
    };
    return model;
}

}  // namespace generated_tests::cast

namespace generated_tests::cast {

const TestModel& get_test_model_float16_to_quant8_overflow_all_inputs_as_internal() {
    static TestModel model = {
        .expectedMultinomialDistributionTolerance = 0,
        .inputIndexes = {2},
        .isRelaxed = false,
        .operands = {{
                .channelQuant = {},
                .data = TestBuffer::createFromVector<_Float16>({}),
                .dimensions = {2},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::TEMPORARY_VARIABLE,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_FLOAT16,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<uint8_t>({0, 255}),
                .dimensions = {2},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_OUTPUT,
                .numberOfConsumers = 0,
                .scale = 4.0f,
                .type = TestOperandType::TENSOR_QUANT8_ASYMM,
                .zeroPoint = 100
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<_Float16>({-1.0f, 256.0f}),
                .dimensions = {2},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_INPUT,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_FLOAT16,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<_Float16>({0.0f}),
                .dimensions = {1},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::CONSTANT_COPY,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_FLOAT16,
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
                .type = TestOperationType::CAST
            }},
        .outputIndexes = {1}
    };
    return model;
}

}  // namespace generated_tests::cast

namespace generated_tests::cast {

const TestModel& get_test_model_float32_to_quant8_overflow() {
    static TestModel model = {
        .expectedMultinomialDistributionTolerance = 0,
        .inputIndexes = {0},
        .isRelaxed = false,
        .operands = {{
                .channelQuant = {},
                .data = TestBuffer::createFromVector<float>({-1.0f, 256.0f}),
                .dimensions = {2},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_INPUT,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_FLOAT32,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<uint8_t>({0, 255}),
                .dimensions = {2},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_OUTPUT,
                .numberOfConsumers = 0,
                .scale = 4.0f,
                .type = TestOperandType::TENSOR_QUANT8_ASYMM,
                .zeroPoint = 100
            }},
        .operations = {{
                .inputs = {0},
                .outputs = {1},
                .type = TestOperationType::CAST
            }},
        .outputIndexes = {1}
    };
    return model;
}

}  // namespace generated_tests::cast

namespace generated_tests::cast {

const TestModel& get_test_model_float32_to_quant8_overflow_all_inputs_as_internal() {
    static TestModel model = {
        .expectedMultinomialDistributionTolerance = 0,
        .inputIndexes = {2},
        .isRelaxed = false,
        .operands = {{
                .channelQuant = {},
                .data = TestBuffer::createFromVector<float>({}),
                .dimensions = {2},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::TEMPORARY_VARIABLE,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_FLOAT32,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<uint8_t>({0, 255}),
                .dimensions = {2},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_OUTPUT,
                .numberOfConsumers = 0,
                .scale = 4.0f,
                .type = TestOperandType::TENSOR_QUANT8_ASYMM,
                .zeroPoint = 100
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<float>({-1.0f, 256.0f}),
                .dimensions = {2},
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
                .type = TestOperationType::CAST
            }},
        .outputIndexes = {1}
    };
    return model;
}

}  // namespace generated_tests::cast

namespace generated_tests::cast {

const TestModel& get_test_model_float32_to_quant8_overflow_relaxed() {
    static TestModel model = {
        .expectedMultinomialDistributionTolerance = 0,
        .inputIndexes = {0},
        .isRelaxed = true,
        .operands = {{
                .channelQuant = {},
                .data = TestBuffer::createFromVector<float>({-1.0f, 256.0f}),
                .dimensions = {2},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_INPUT,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_FLOAT32,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<uint8_t>({0, 255}),
                .dimensions = {2},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_OUTPUT,
                .numberOfConsumers = 0,
                .scale = 4.0f,
                .type = TestOperandType::TENSOR_QUANT8_ASYMM,
                .zeroPoint = 100
            }},
        .operations = {{
                .inputs = {0},
                .outputs = {1},
                .type = TestOperationType::CAST
            }},
        .outputIndexes = {1}
    };
    return model;
}

}  // namespace generated_tests::cast

namespace generated_tests::cast {

const TestModel& get_test_model_float32_to_quant8_overflow_relaxed_all_inputs_as_internal() {
    static TestModel model = {
        .expectedMultinomialDistributionTolerance = 0,
        .inputIndexes = {2},
        .isRelaxed = true,
        .operands = {{
                .channelQuant = {},
                .data = TestBuffer::createFromVector<float>({}),
                .dimensions = {2},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::TEMPORARY_VARIABLE,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_FLOAT32,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<uint8_t>({0, 255}),
                .dimensions = {2},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_OUTPUT,
                .numberOfConsumers = 0,
                .scale = 4.0f,
                .type = TestOperandType::TENSOR_QUANT8_ASYMM,
                .zeroPoint = 100
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<float>({-1.0f, 256.0f}),
                .dimensions = {2},
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
                .type = TestOperationType::CAST
            }},
        .outputIndexes = {1}
    };
    return model;
}

}  // namespace generated_tests::cast

namespace generated_tests::cast {

const TestModel& get_test_model_int32_to_quant8_overflow() {
    static TestModel model = {
        .expectedMultinomialDistributionTolerance = 0,
        .inputIndexes = {0},
        .isRelaxed = false,
        .operands = {{
                .channelQuant = {},
                .data = TestBuffer::createFromVector<int32_t>({-1, 256}),
                .dimensions = {2},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_INPUT,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_INT32,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<uint8_t>({0, 255}),
                .dimensions = {2},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_OUTPUT,
                .numberOfConsumers = 0,
                .scale = 4.0f,
                .type = TestOperandType::TENSOR_QUANT8_ASYMM,
                .zeroPoint = 100
            }},
        .operations = {{
                .inputs = {0},
                .outputs = {1},
                .type = TestOperationType::CAST
            }},
        .outputIndexes = {1}
    };
    return model;
}

}  // namespace generated_tests::cast
