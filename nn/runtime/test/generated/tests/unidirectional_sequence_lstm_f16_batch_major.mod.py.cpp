// Generated from unidirectional_sequence_lstm_f16_batch_major.mod.py
// DO NOT EDIT
// clang-format off
#include "TestGenerated.h"

namespace generated_tests::unidirectional_sequence_lstm_f16_batch_major {

void CreateModel(Model *model);
bool is_ignored(int);
std::vector<::test_helper::MixedTypedExample>& get_examples();

TEST_F(GeneratedTests, unidirectional_sequence_lstm_f16_batch_major) {
    execute(CreateModel,
            is_ignored,
            get_examples());
}

} // namespace generated_tests::unidirectional_sequence_lstm_f16_batch_major
TEST_AVAILABLE_SINCE(V1_2, unidirectional_sequence_lstm_f16_batch_major, generated_tests::unidirectional_sequence_lstm_f16_batch_major::CreateModel)

namespace generated_tests::unidirectional_sequence_lstm_f16_batch_major {

void CreateModel_dynamic_output_shape(Model *model);
bool is_ignored_dynamic_output_shape(int);
std::vector<::test_helper::MixedTypedExample>& get_examples_dynamic_output_shape();

TEST_F(DynamicOutputShapeTest, unidirectional_sequence_lstm_f16_batch_major_dynamic_output_shape) {
    execute(CreateModel_dynamic_output_shape,
            is_ignored_dynamic_output_shape,
            get_examples_dynamic_output_shape());
}

} // namespace generated_tests::unidirectional_sequence_lstm_f16_batch_major
