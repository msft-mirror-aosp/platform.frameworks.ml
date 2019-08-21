// Generated from fully_connected_float_large.mod.py
// DO NOT EDIT
// clang-format off
#include "GeneratedTests.h"

namespace generated_tests::fully_connected_float_large {

std::vector<::test_helper::MixedTypedExample>& get_examples();

} // namespace generated_tests::fully_connected_float_large

namespace android::hardware::neuralnetworks::V1_2::generated_tests::fully_connected_float_large {

Model createTestModel();
bool is_ignored(int);

TEST_F(NeuralnetworksHidlTest, fully_connected_float_large) {
  Execute(device,
          createTestModel,
          is_ignored,
          ::generated_tests::fully_connected_float_large::get_examples());
}

TEST_F(ValidationTest, fully_connected_float_large) {
  const Model model = createTestModel();
  const std::vector<Request> requests = createRequests(::generated_tests::fully_connected_float_large::get_examples());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::fully_connected_float_large

namespace generated_tests::fully_connected_float_large {

std::vector<::test_helper::MixedTypedExample>& get_examples_dynamic_output_shape();

} // namespace generated_tests::fully_connected_float_large

namespace android::hardware::neuralnetworks::V1_2::generated_tests::fully_connected_float_large {

Model createTestModel_dynamic_output_shape();
bool is_ignored_dynamic_output_shape(int);

TEST_F(DynamicOutputShapeTest, fully_connected_float_large_dynamic_output_shape) {
  Execute(device,
          createTestModel_dynamic_output_shape,
          is_ignored_dynamic_output_shape,
          ::generated_tests::fully_connected_float_large::get_examples_dynamic_output_shape(), true);
}

TEST_F(ValidationTest, fully_connected_float_large_dynamic_output_shape) {
  const Model model = createTestModel_dynamic_output_shape();
  const std::vector<Request> requests = createRequests(::generated_tests::fully_connected_float_large::get_examples_dynamic_output_shape());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::fully_connected_float_large
