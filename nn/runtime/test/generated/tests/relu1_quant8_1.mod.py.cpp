// Generated from relu1_quant8_1.mod.py
// DO NOT EDIT
// clang-format off
#include "TestGenerated.h"

namespace generated_tests::relu1_quant8_1 {

void CreateModel(Model *model);
bool is_ignored(int);
std::vector<::test_helper::MixedTypedExample>& get_examples();

TEST_F(GeneratedTests, relu1_quant8_1) {
    execute(CreateModel,
            is_ignored,
            get_examples());
}

} // namespace generated_tests::relu1_quant8_1
TEST_AVAILABLE_SINCE(V1_0, relu1_quant8_1, generated_tests::relu1_quant8_1::CreateModel)

namespace generated_tests::relu1_quant8_1 {

void CreateModel_dynamic_output_shape(Model *model);
bool is_ignored_dynamic_output_shape(int);
std::vector<::test_helper::MixedTypedExample>& get_examples_dynamic_output_shape();

TEST_F(DynamicOutputShapeTest, relu1_quant8_1_dynamic_output_shape) {
    execute(CreateModel_dynamic_output_shape,
            is_ignored_dynamic_output_shape,
            get_examples_dynamic_output_shape());
}

} // namespace generated_tests::relu1_quant8_1

namespace generated_tests::relu1_quant8_1 {

void CreateModel_2(Model *model);
bool is_ignored_2(int);
std::vector<::test_helper::MixedTypedExample>& get_examples_2();

TEST_F(GeneratedTests, relu1_quant8_1_2) {
    execute(CreateModel_2,
            is_ignored_2,
            get_examples_2());
}

} // namespace generated_tests::relu1_quant8_1
TEST_AVAILABLE_SINCE(V1_0, relu1_quant8_1_2, generated_tests::relu1_quant8_1::CreateModel_2)

namespace generated_tests::relu1_quant8_1 {

void CreateModel_dynamic_output_shape_2(Model *model);
bool is_ignored_dynamic_output_shape_2(int);
std::vector<::test_helper::MixedTypedExample>& get_examples_dynamic_output_shape_2();

TEST_F(DynamicOutputShapeTest, relu1_quant8_1_dynamic_output_shape_2) {
    execute(CreateModel_dynamic_output_shape_2,
            is_ignored_dynamic_output_shape_2,
            get_examples_dynamic_output_shape_2());
}

} // namespace generated_tests::relu1_quant8_1

