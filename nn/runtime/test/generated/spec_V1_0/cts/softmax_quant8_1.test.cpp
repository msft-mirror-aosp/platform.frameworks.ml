// Generated from softmax_quant8_1.mod.py
// DO NOT EDIT
// clang-format off
#include "TestGenerated.h"


namespace generated_tests::softmax_quant8_1 {

const ::test_helper::TestModel& get_test_model();

TEST_F(GeneratedTests, softmax_quant8_1) { execute(get_test_model()); }

TEST_F(DynamicOutputShapeTest, softmax_quant8_1) { execute(get_test_model()); }

} // namespace generated_tests::softmax_quant8_1

TEST_AVAILABLE_SINCE(V1_0, softmax_quant8_1, generated_tests::softmax_quant8_1::get_test_model());


namespace generated_tests::softmax_quant8_1 {

const ::test_helper::TestModel& get_test_model_all_inputs_as_internal();

TEST_F(GeneratedTests, softmax_quant8_1_all_inputs_as_internal) { execute(get_test_model_all_inputs_as_internal()); }

TEST_F(DynamicOutputShapeTest, softmax_quant8_1_all_inputs_as_internal) { execute(get_test_model_all_inputs_as_internal()); }

} // namespace generated_tests::softmax_quant8_1

TEST_AVAILABLE_SINCE(V1_0, softmax_quant8_1_all_inputs_as_internal, generated_tests::softmax_quant8_1::get_test_model_all_inputs_as_internal());
