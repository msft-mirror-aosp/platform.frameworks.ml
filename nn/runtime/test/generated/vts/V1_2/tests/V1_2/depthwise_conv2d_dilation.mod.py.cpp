// Generated from depthwise_conv2d_dilation.mod.py
// DO NOT EDIT
// clang-format off
#include "GeneratedTests.h"

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_nhwc();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_nhwc();
bool is_ignored_nhwc(int);

TEST_F(NeuralnetworksHidlTest, depthwise_conv2d_dilation_nhwc) {
  Execute(device,
          createTestModel_nhwc,
          is_ignored_nhwc,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_nhwc());
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_nhwc) {
  const Model model = createTestModel_nhwc();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_nhwc());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_nhwc_relaxed();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_nhwc_relaxed();
bool is_ignored_nhwc_relaxed(int);

TEST_F(NeuralnetworksHidlTest, depthwise_conv2d_dilation_nhwc_relaxed) {
  Execute(device,
          createTestModel_nhwc_relaxed,
          is_ignored_nhwc_relaxed,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_nhwc_relaxed());
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_nhwc_relaxed) {
  const Model model = createTestModel_nhwc_relaxed();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_nhwc_relaxed());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_nhwc_float16();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_nhwc_float16();
bool is_ignored_nhwc_float16(int);

TEST_F(NeuralnetworksHidlTest, depthwise_conv2d_dilation_nhwc_float16) {
  Execute(device,
          createTestModel_nhwc_float16,
          is_ignored_nhwc_float16,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_nhwc_float16());
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_nhwc_float16) {
  const Model model = createTestModel_nhwc_float16();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_nhwc_float16());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_nhwc_quant8();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_nhwc_quant8();
bool is_ignored_nhwc_quant8(int);

TEST_F(NeuralnetworksHidlTest, depthwise_conv2d_dilation_nhwc_quant8) {
  Execute(device,
          createTestModel_nhwc_quant8,
          is_ignored_nhwc_quant8,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_nhwc_quant8());
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_nhwc_quant8) {
  const Model model = createTestModel_nhwc_quant8();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_nhwc_quant8());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_nhwc_weight_as_input();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_nhwc_weight_as_input();
bool is_ignored_nhwc_weight_as_input(int);

TEST_F(NeuralnetworksHidlTest, depthwise_conv2d_dilation_nhwc_weight_as_input) {
  Execute(device,
          createTestModel_nhwc_weight_as_input,
          is_ignored_nhwc_weight_as_input,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_nhwc_weight_as_input());
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_nhwc_weight_as_input) {
  const Model model = createTestModel_nhwc_weight_as_input();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_nhwc_weight_as_input());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_nhwc_weight_as_input_relaxed();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_nhwc_weight_as_input_relaxed();
bool is_ignored_nhwc_weight_as_input_relaxed(int);

TEST_F(NeuralnetworksHidlTest, depthwise_conv2d_dilation_nhwc_weight_as_input_relaxed) {
  Execute(device,
          createTestModel_nhwc_weight_as_input_relaxed,
          is_ignored_nhwc_weight_as_input_relaxed,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_nhwc_weight_as_input_relaxed());
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_nhwc_weight_as_input_relaxed) {
  const Model model = createTestModel_nhwc_weight_as_input_relaxed();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_nhwc_weight_as_input_relaxed());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_nhwc_weight_as_input_float16();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_nhwc_weight_as_input_float16();
bool is_ignored_nhwc_weight_as_input_float16(int);

TEST_F(NeuralnetworksHidlTest, depthwise_conv2d_dilation_nhwc_weight_as_input_float16) {
  Execute(device,
          createTestModel_nhwc_weight_as_input_float16,
          is_ignored_nhwc_weight_as_input_float16,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_nhwc_weight_as_input_float16());
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_nhwc_weight_as_input_float16) {
  const Model model = createTestModel_nhwc_weight_as_input_float16();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_nhwc_weight_as_input_float16());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_nhwc_weight_as_input_quant8();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_nhwc_weight_as_input_quant8();
bool is_ignored_nhwc_weight_as_input_quant8(int);

TEST_F(NeuralnetworksHidlTest, depthwise_conv2d_dilation_nhwc_weight_as_input_quant8) {
  Execute(device,
          createTestModel_nhwc_weight_as_input_quant8,
          is_ignored_nhwc_weight_as_input_quant8,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_nhwc_weight_as_input_quant8());
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_nhwc_weight_as_input_quant8) {
  const Model model = createTestModel_nhwc_weight_as_input_quant8();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_nhwc_weight_as_input_quant8());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_nchw();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_nchw();
bool is_ignored_nchw(int);

TEST_F(NeuralnetworksHidlTest, depthwise_conv2d_dilation_nchw) {
  Execute(device,
          createTestModel_nchw,
          is_ignored_nchw,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_nchw());
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_nchw) {
  const Model model = createTestModel_nchw();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_nchw());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_nchw_relaxed();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_nchw_relaxed();
bool is_ignored_nchw_relaxed(int);

TEST_F(NeuralnetworksHidlTest, depthwise_conv2d_dilation_nchw_relaxed) {
  Execute(device,
          createTestModel_nchw_relaxed,
          is_ignored_nchw_relaxed,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_nchw_relaxed());
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_nchw_relaxed) {
  const Model model = createTestModel_nchw_relaxed();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_nchw_relaxed());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_nchw_float16();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_nchw_float16();
bool is_ignored_nchw_float16(int);

TEST_F(NeuralnetworksHidlTest, depthwise_conv2d_dilation_nchw_float16) {
  Execute(device,
          createTestModel_nchw_float16,
          is_ignored_nchw_float16,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_nchw_float16());
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_nchw_float16) {
  const Model model = createTestModel_nchw_float16();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_nchw_float16());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_nchw_quant8();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_nchw_quant8();
bool is_ignored_nchw_quant8(int);

TEST_F(NeuralnetworksHidlTest, depthwise_conv2d_dilation_nchw_quant8) {
  Execute(device,
          createTestModel_nchw_quant8,
          is_ignored_nchw_quant8,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_nchw_quant8());
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_nchw_quant8) {
  const Model model = createTestModel_nchw_quant8();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_nchw_quant8());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_nchw_weight_as_input();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_nchw_weight_as_input();
bool is_ignored_nchw_weight_as_input(int);

TEST_F(NeuralnetworksHidlTest, depthwise_conv2d_dilation_nchw_weight_as_input) {
  Execute(device,
          createTestModel_nchw_weight_as_input,
          is_ignored_nchw_weight_as_input,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_nchw_weight_as_input());
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_nchw_weight_as_input) {
  const Model model = createTestModel_nchw_weight_as_input();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_nchw_weight_as_input());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_nchw_weight_as_input_relaxed();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_nchw_weight_as_input_relaxed();
bool is_ignored_nchw_weight_as_input_relaxed(int);

TEST_F(NeuralnetworksHidlTest, depthwise_conv2d_dilation_nchw_weight_as_input_relaxed) {
  Execute(device,
          createTestModel_nchw_weight_as_input_relaxed,
          is_ignored_nchw_weight_as_input_relaxed,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_nchw_weight_as_input_relaxed());
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_nchw_weight_as_input_relaxed) {
  const Model model = createTestModel_nchw_weight_as_input_relaxed();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_nchw_weight_as_input_relaxed());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_nchw_weight_as_input_float16();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_nchw_weight_as_input_float16();
bool is_ignored_nchw_weight_as_input_float16(int);

TEST_F(NeuralnetworksHidlTest, depthwise_conv2d_dilation_nchw_weight_as_input_float16) {
  Execute(device,
          createTestModel_nchw_weight_as_input_float16,
          is_ignored_nchw_weight_as_input_float16,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_nchw_weight_as_input_float16());
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_nchw_weight_as_input_float16) {
  const Model model = createTestModel_nchw_weight_as_input_float16();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_nchw_weight_as_input_float16());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_nchw_weight_as_input_quant8();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_nchw_weight_as_input_quant8();
bool is_ignored_nchw_weight_as_input_quant8(int);

TEST_F(NeuralnetworksHidlTest, depthwise_conv2d_dilation_nchw_weight_as_input_quant8) {
  Execute(device,
          createTestModel_nchw_weight_as_input_quant8,
          is_ignored_nchw_weight_as_input_quant8,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_nchw_weight_as_input_quant8());
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_nchw_weight_as_input_quant8) {
  const Model model = createTestModel_nchw_weight_as_input_quant8();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_nchw_weight_as_input_quant8());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_dynamic_output_shape_nhwc();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_dynamic_output_shape_nhwc();
bool is_ignored_dynamic_output_shape_nhwc(int);

TEST_F(DynamicOutputShapeTest, depthwise_conv2d_dilation_dynamic_output_shape_nhwc) {
  Execute(device,
          createTestModel_dynamic_output_shape_nhwc,
          is_ignored_dynamic_output_shape_nhwc,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_dynamic_output_shape_nhwc(), true);
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_dynamic_output_shape_nhwc) {
  const Model model = createTestModel_dynamic_output_shape_nhwc();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_dynamic_output_shape_nhwc());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_dynamic_output_shape_nhwc_relaxed();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_dynamic_output_shape_nhwc_relaxed();
bool is_ignored_dynamic_output_shape_nhwc_relaxed(int);

TEST_F(DynamicOutputShapeTest, depthwise_conv2d_dilation_dynamic_output_shape_nhwc_relaxed) {
  Execute(device,
          createTestModel_dynamic_output_shape_nhwc_relaxed,
          is_ignored_dynamic_output_shape_nhwc_relaxed,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_dynamic_output_shape_nhwc_relaxed(), true);
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_dynamic_output_shape_nhwc_relaxed) {
  const Model model = createTestModel_dynamic_output_shape_nhwc_relaxed();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_dynamic_output_shape_nhwc_relaxed());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_dynamic_output_shape_nhwc_float16();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_dynamic_output_shape_nhwc_float16();
bool is_ignored_dynamic_output_shape_nhwc_float16(int);

TEST_F(DynamicOutputShapeTest, depthwise_conv2d_dilation_dynamic_output_shape_nhwc_float16) {
  Execute(device,
          createTestModel_dynamic_output_shape_nhwc_float16,
          is_ignored_dynamic_output_shape_nhwc_float16,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_dynamic_output_shape_nhwc_float16(), true);
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_dynamic_output_shape_nhwc_float16) {
  const Model model = createTestModel_dynamic_output_shape_nhwc_float16();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_dynamic_output_shape_nhwc_float16());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_dynamic_output_shape_nhwc_quant8();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_dynamic_output_shape_nhwc_quant8();
bool is_ignored_dynamic_output_shape_nhwc_quant8(int);

TEST_F(DynamicOutputShapeTest, depthwise_conv2d_dilation_dynamic_output_shape_nhwc_quant8) {
  Execute(device,
          createTestModel_dynamic_output_shape_nhwc_quant8,
          is_ignored_dynamic_output_shape_nhwc_quant8,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_dynamic_output_shape_nhwc_quant8(), true);
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_dynamic_output_shape_nhwc_quant8) {
  const Model model = createTestModel_dynamic_output_shape_nhwc_quant8();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_dynamic_output_shape_nhwc_quant8());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_dynamic_output_shape_nhwc_weight_as_input();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_dynamic_output_shape_nhwc_weight_as_input();
bool is_ignored_dynamic_output_shape_nhwc_weight_as_input(int);

TEST_F(DynamicOutputShapeTest, depthwise_conv2d_dilation_dynamic_output_shape_nhwc_weight_as_input) {
  Execute(device,
          createTestModel_dynamic_output_shape_nhwc_weight_as_input,
          is_ignored_dynamic_output_shape_nhwc_weight_as_input,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_dynamic_output_shape_nhwc_weight_as_input(), true);
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_dynamic_output_shape_nhwc_weight_as_input) {
  const Model model = createTestModel_dynamic_output_shape_nhwc_weight_as_input();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_dynamic_output_shape_nhwc_weight_as_input());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_dynamic_output_shape_nhwc_weight_as_input_relaxed();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_dynamic_output_shape_nhwc_weight_as_input_relaxed();
bool is_ignored_dynamic_output_shape_nhwc_weight_as_input_relaxed(int);

TEST_F(DynamicOutputShapeTest, depthwise_conv2d_dilation_dynamic_output_shape_nhwc_weight_as_input_relaxed) {
  Execute(device,
          createTestModel_dynamic_output_shape_nhwc_weight_as_input_relaxed,
          is_ignored_dynamic_output_shape_nhwc_weight_as_input_relaxed,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_dynamic_output_shape_nhwc_weight_as_input_relaxed(), true);
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_dynamic_output_shape_nhwc_weight_as_input_relaxed) {
  const Model model = createTestModel_dynamic_output_shape_nhwc_weight_as_input_relaxed();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_dynamic_output_shape_nhwc_weight_as_input_relaxed());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_dynamic_output_shape_nhwc_weight_as_input_float16();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_dynamic_output_shape_nhwc_weight_as_input_float16();
bool is_ignored_dynamic_output_shape_nhwc_weight_as_input_float16(int);

TEST_F(DynamicOutputShapeTest, depthwise_conv2d_dilation_dynamic_output_shape_nhwc_weight_as_input_float16) {
  Execute(device,
          createTestModel_dynamic_output_shape_nhwc_weight_as_input_float16,
          is_ignored_dynamic_output_shape_nhwc_weight_as_input_float16,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_dynamic_output_shape_nhwc_weight_as_input_float16(), true);
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_dynamic_output_shape_nhwc_weight_as_input_float16) {
  const Model model = createTestModel_dynamic_output_shape_nhwc_weight_as_input_float16();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_dynamic_output_shape_nhwc_weight_as_input_float16());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_dynamic_output_shape_nhwc_weight_as_input_quant8();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_dynamic_output_shape_nhwc_weight_as_input_quant8();
bool is_ignored_dynamic_output_shape_nhwc_weight_as_input_quant8(int);

TEST_F(DynamicOutputShapeTest, depthwise_conv2d_dilation_dynamic_output_shape_nhwc_weight_as_input_quant8) {
  Execute(device,
          createTestModel_dynamic_output_shape_nhwc_weight_as_input_quant8,
          is_ignored_dynamic_output_shape_nhwc_weight_as_input_quant8,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_dynamic_output_shape_nhwc_weight_as_input_quant8(), true);
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_dynamic_output_shape_nhwc_weight_as_input_quant8) {
  const Model model = createTestModel_dynamic_output_shape_nhwc_weight_as_input_quant8();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_dynamic_output_shape_nhwc_weight_as_input_quant8());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_dynamic_output_shape_nchw();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_dynamic_output_shape_nchw();
bool is_ignored_dynamic_output_shape_nchw(int);

TEST_F(DynamicOutputShapeTest, depthwise_conv2d_dilation_dynamic_output_shape_nchw) {
  Execute(device,
          createTestModel_dynamic_output_shape_nchw,
          is_ignored_dynamic_output_shape_nchw,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_dynamic_output_shape_nchw(), true);
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_dynamic_output_shape_nchw) {
  const Model model = createTestModel_dynamic_output_shape_nchw();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_dynamic_output_shape_nchw());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_dynamic_output_shape_nchw_relaxed();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_dynamic_output_shape_nchw_relaxed();
bool is_ignored_dynamic_output_shape_nchw_relaxed(int);

TEST_F(DynamicOutputShapeTest, depthwise_conv2d_dilation_dynamic_output_shape_nchw_relaxed) {
  Execute(device,
          createTestModel_dynamic_output_shape_nchw_relaxed,
          is_ignored_dynamic_output_shape_nchw_relaxed,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_dynamic_output_shape_nchw_relaxed(), true);
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_dynamic_output_shape_nchw_relaxed) {
  const Model model = createTestModel_dynamic_output_shape_nchw_relaxed();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_dynamic_output_shape_nchw_relaxed());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_dynamic_output_shape_nchw_float16();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_dynamic_output_shape_nchw_float16();
bool is_ignored_dynamic_output_shape_nchw_float16(int);

TEST_F(DynamicOutputShapeTest, depthwise_conv2d_dilation_dynamic_output_shape_nchw_float16) {
  Execute(device,
          createTestModel_dynamic_output_shape_nchw_float16,
          is_ignored_dynamic_output_shape_nchw_float16,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_dynamic_output_shape_nchw_float16(), true);
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_dynamic_output_shape_nchw_float16) {
  const Model model = createTestModel_dynamic_output_shape_nchw_float16();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_dynamic_output_shape_nchw_float16());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_dynamic_output_shape_nchw_quant8();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_dynamic_output_shape_nchw_quant8();
bool is_ignored_dynamic_output_shape_nchw_quant8(int);

TEST_F(DynamicOutputShapeTest, depthwise_conv2d_dilation_dynamic_output_shape_nchw_quant8) {
  Execute(device,
          createTestModel_dynamic_output_shape_nchw_quant8,
          is_ignored_dynamic_output_shape_nchw_quant8,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_dynamic_output_shape_nchw_quant8(), true);
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_dynamic_output_shape_nchw_quant8) {
  const Model model = createTestModel_dynamic_output_shape_nchw_quant8();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_dynamic_output_shape_nchw_quant8());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_dynamic_output_shape_nchw_weight_as_input();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_dynamic_output_shape_nchw_weight_as_input();
bool is_ignored_dynamic_output_shape_nchw_weight_as_input(int);

TEST_F(DynamicOutputShapeTest, depthwise_conv2d_dilation_dynamic_output_shape_nchw_weight_as_input) {
  Execute(device,
          createTestModel_dynamic_output_shape_nchw_weight_as_input,
          is_ignored_dynamic_output_shape_nchw_weight_as_input,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_dynamic_output_shape_nchw_weight_as_input(), true);
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_dynamic_output_shape_nchw_weight_as_input) {
  const Model model = createTestModel_dynamic_output_shape_nchw_weight_as_input();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_dynamic_output_shape_nchw_weight_as_input());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_dynamic_output_shape_nchw_weight_as_input_relaxed();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_dynamic_output_shape_nchw_weight_as_input_relaxed();
bool is_ignored_dynamic_output_shape_nchw_weight_as_input_relaxed(int);

TEST_F(DynamicOutputShapeTest, depthwise_conv2d_dilation_dynamic_output_shape_nchw_weight_as_input_relaxed) {
  Execute(device,
          createTestModel_dynamic_output_shape_nchw_weight_as_input_relaxed,
          is_ignored_dynamic_output_shape_nchw_weight_as_input_relaxed,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_dynamic_output_shape_nchw_weight_as_input_relaxed(), true);
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_dynamic_output_shape_nchw_weight_as_input_relaxed) {
  const Model model = createTestModel_dynamic_output_shape_nchw_weight_as_input_relaxed();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_dynamic_output_shape_nchw_weight_as_input_relaxed());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_dynamic_output_shape_nchw_weight_as_input_float16();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_dynamic_output_shape_nchw_weight_as_input_float16();
bool is_ignored_dynamic_output_shape_nchw_weight_as_input_float16(int);

TEST_F(DynamicOutputShapeTest, depthwise_conv2d_dilation_dynamic_output_shape_nchw_weight_as_input_float16) {
  Execute(device,
          createTestModel_dynamic_output_shape_nchw_weight_as_input_float16,
          is_ignored_dynamic_output_shape_nchw_weight_as_input_float16,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_dynamic_output_shape_nchw_weight_as_input_float16(), true);
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_dynamic_output_shape_nchw_weight_as_input_float16) {
  const Model model = createTestModel_dynamic_output_shape_nchw_weight_as_input_float16();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_dynamic_output_shape_nchw_weight_as_input_float16());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_dynamic_output_shape_nchw_weight_as_input_quant8();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_dynamic_output_shape_nchw_weight_as_input_quant8();
bool is_ignored_dynamic_output_shape_nchw_weight_as_input_quant8(int);

TEST_F(DynamicOutputShapeTest, depthwise_conv2d_dilation_dynamic_output_shape_nchw_weight_as_input_quant8) {
  Execute(device,
          createTestModel_dynamic_output_shape_nchw_weight_as_input_quant8,
          is_ignored_dynamic_output_shape_nchw_weight_as_input_quant8,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_dynamic_output_shape_nchw_weight_as_input_quant8(), true);
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_dynamic_output_shape_nchw_weight_as_input_quant8) {
  const Model model = createTestModel_dynamic_output_shape_nchw_weight_as_input_quant8();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_dynamic_output_shape_nchw_weight_as_input_quant8());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_nhwc_2();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_nhwc_2();
bool is_ignored_nhwc_2(int);

TEST_F(NeuralnetworksHidlTest, depthwise_conv2d_dilation_nhwc_2) {
  Execute(device,
          createTestModel_nhwc_2,
          is_ignored_nhwc_2,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_nhwc_2());
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_nhwc_2) {
  const Model model = createTestModel_nhwc_2();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_nhwc_2());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_nhwc_weight_as_input_2();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_nhwc_weight_as_input_2();
bool is_ignored_nhwc_weight_as_input_2(int);

TEST_F(NeuralnetworksHidlTest, depthwise_conv2d_dilation_nhwc_weight_as_input_2) {
  Execute(device,
          createTestModel_nhwc_weight_as_input_2,
          is_ignored_nhwc_weight_as_input_2,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_nhwc_weight_as_input_2());
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_nhwc_weight_as_input_2) {
  const Model model = createTestModel_nhwc_weight_as_input_2();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_nhwc_weight_as_input_2());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_nchw_2();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_nchw_2();
bool is_ignored_nchw_2(int);

TEST_F(NeuralnetworksHidlTest, depthwise_conv2d_dilation_nchw_2) {
  Execute(device,
          createTestModel_nchw_2,
          is_ignored_nchw_2,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_nchw_2());
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_nchw_2) {
  const Model model = createTestModel_nchw_2();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_nchw_2());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_nchw_weight_as_input_2();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_nchw_weight_as_input_2();
bool is_ignored_nchw_weight_as_input_2(int);

TEST_F(NeuralnetworksHidlTest, depthwise_conv2d_dilation_nchw_weight_as_input_2) {
  Execute(device,
          createTestModel_nchw_weight_as_input_2,
          is_ignored_nchw_weight_as_input_2,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_nchw_weight_as_input_2());
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_nchw_weight_as_input_2) {
  const Model model = createTestModel_nchw_weight_as_input_2();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_nchw_weight_as_input_2());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_dynamic_output_shape_nhwc_2();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_dynamic_output_shape_nhwc_2();
bool is_ignored_dynamic_output_shape_nhwc_2(int);

TEST_F(DynamicOutputShapeTest, depthwise_conv2d_dilation_dynamic_output_shape_nhwc_2) {
  Execute(device,
          createTestModel_dynamic_output_shape_nhwc_2,
          is_ignored_dynamic_output_shape_nhwc_2,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_dynamic_output_shape_nhwc_2(), true);
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_dynamic_output_shape_nhwc_2) {
  const Model model = createTestModel_dynamic_output_shape_nhwc_2();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_dynamic_output_shape_nhwc_2());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_dynamic_output_shape_nhwc_weight_as_input_2();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_dynamic_output_shape_nhwc_weight_as_input_2();
bool is_ignored_dynamic_output_shape_nhwc_weight_as_input_2(int);

TEST_F(DynamicOutputShapeTest, depthwise_conv2d_dilation_dynamic_output_shape_nhwc_weight_as_input_2) {
  Execute(device,
          createTestModel_dynamic_output_shape_nhwc_weight_as_input_2,
          is_ignored_dynamic_output_shape_nhwc_weight_as_input_2,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_dynamic_output_shape_nhwc_weight_as_input_2(), true);
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_dynamic_output_shape_nhwc_weight_as_input_2) {
  const Model model = createTestModel_dynamic_output_shape_nhwc_weight_as_input_2();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_dynamic_output_shape_nhwc_weight_as_input_2());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_dynamic_output_shape_nchw_2();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_dynamic_output_shape_nchw_2();
bool is_ignored_dynamic_output_shape_nchw_2(int);

TEST_F(DynamicOutputShapeTest, depthwise_conv2d_dilation_dynamic_output_shape_nchw_2) {
  Execute(device,
          createTestModel_dynamic_output_shape_nchw_2,
          is_ignored_dynamic_output_shape_nchw_2,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_dynamic_output_shape_nchw_2(), true);
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_dynamic_output_shape_nchw_2) {
  const Model model = createTestModel_dynamic_output_shape_nchw_2();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_dynamic_output_shape_nchw_2());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_dynamic_output_shape_nchw_weight_as_input_2();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_dynamic_output_shape_nchw_weight_as_input_2();
bool is_ignored_dynamic_output_shape_nchw_weight_as_input_2(int);

TEST_F(DynamicOutputShapeTest, depthwise_conv2d_dilation_dynamic_output_shape_nchw_weight_as_input_2) {
  Execute(device,
          createTestModel_dynamic_output_shape_nchw_weight_as_input_2,
          is_ignored_dynamic_output_shape_nchw_weight_as_input_2,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_dynamic_output_shape_nchw_weight_as_input_2(), true);
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_dynamic_output_shape_nchw_weight_as_input_2) {
  const Model model = createTestModel_dynamic_output_shape_nchw_weight_as_input_2();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_dynamic_output_shape_nchw_weight_as_input_2());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_valid_padding_nhwc();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_nhwc_3();
bool is_ignored_nhwc_3(int);

TEST_F(NeuralnetworksHidlTest, depthwise_conv2d_dilation_valid_padding_nhwc) {
  Execute(device,
          createTestModel_nhwc_3,
          is_ignored_nhwc_3,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_nhwc());
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_valid_padding_nhwc) {
  const Model model = createTestModel_nhwc_3();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_nhwc());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_valid_padding_nhwc_relaxed();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_nhwc_relaxed_2();
bool is_ignored_nhwc_relaxed_2(int);

TEST_F(NeuralnetworksHidlTest, depthwise_conv2d_dilation_valid_padding_nhwc_relaxed) {
  Execute(device,
          createTestModel_nhwc_relaxed_2,
          is_ignored_nhwc_relaxed_2,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_nhwc_relaxed());
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_valid_padding_nhwc_relaxed) {
  const Model model = createTestModel_nhwc_relaxed_2();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_nhwc_relaxed());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_valid_padding_nhwc_float16();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_nhwc_float16_2();
bool is_ignored_nhwc_float16_2(int);

TEST_F(NeuralnetworksHidlTest, depthwise_conv2d_dilation_valid_padding_nhwc_float16) {
  Execute(device,
          createTestModel_nhwc_float16_2,
          is_ignored_nhwc_float16_2,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_nhwc_float16());
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_valid_padding_nhwc_float16) {
  const Model model = createTestModel_nhwc_float16_2();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_nhwc_float16());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_valid_padding_nhwc_quant8();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_nhwc_quant8_2();
bool is_ignored_nhwc_quant8_2(int);

TEST_F(NeuralnetworksHidlTest, depthwise_conv2d_dilation_valid_padding_nhwc_quant8) {
  Execute(device,
          createTestModel_nhwc_quant8_2,
          is_ignored_nhwc_quant8_2,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_nhwc_quant8());
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_valid_padding_nhwc_quant8) {
  const Model model = createTestModel_nhwc_quant8_2();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_nhwc_quant8());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_valid_padding_nhwc_weight_as_input();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_nhwc_weight_as_input_3();
bool is_ignored_nhwc_weight_as_input_3(int);

TEST_F(NeuralnetworksHidlTest, depthwise_conv2d_dilation_valid_padding_nhwc_weight_as_input) {
  Execute(device,
          createTestModel_nhwc_weight_as_input_3,
          is_ignored_nhwc_weight_as_input_3,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_nhwc_weight_as_input());
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_valid_padding_nhwc_weight_as_input) {
  const Model model = createTestModel_nhwc_weight_as_input_3();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_nhwc_weight_as_input());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_valid_padding_nhwc_weight_as_input_relaxed();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_nhwc_weight_as_input_relaxed_2();
bool is_ignored_nhwc_weight_as_input_relaxed_2(int);

TEST_F(NeuralnetworksHidlTest, depthwise_conv2d_dilation_valid_padding_nhwc_weight_as_input_relaxed) {
  Execute(device,
          createTestModel_nhwc_weight_as_input_relaxed_2,
          is_ignored_nhwc_weight_as_input_relaxed_2,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_nhwc_weight_as_input_relaxed());
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_valid_padding_nhwc_weight_as_input_relaxed) {
  const Model model = createTestModel_nhwc_weight_as_input_relaxed_2();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_nhwc_weight_as_input_relaxed());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_valid_padding_nhwc_weight_as_input_float16();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_nhwc_weight_as_input_float16_2();
bool is_ignored_nhwc_weight_as_input_float16_2(int);

TEST_F(NeuralnetworksHidlTest, depthwise_conv2d_dilation_valid_padding_nhwc_weight_as_input_float16) {
  Execute(device,
          createTestModel_nhwc_weight_as_input_float16_2,
          is_ignored_nhwc_weight_as_input_float16_2,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_nhwc_weight_as_input_float16());
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_valid_padding_nhwc_weight_as_input_float16) {
  const Model model = createTestModel_nhwc_weight_as_input_float16_2();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_nhwc_weight_as_input_float16());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_valid_padding_nhwc_weight_as_input_quant8();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_nhwc_weight_as_input_quant8_2();
bool is_ignored_nhwc_weight_as_input_quant8_2(int);

TEST_F(NeuralnetworksHidlTest, depthwise_conv2d_dilation_valid_padding_nhwc_weight_as_input_quant8) {
  Execute(device,
          createTestModel_nhwc_weight_as_input_quant8_2,
          is_ignored_nhwc_weight_as_input_quant8_2,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_nhwc_weight_as_input_quant8());
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_valid_padding_nhwc_weight_as_input_quant8) {
  const Model model = createTestModel_nhwc_weight_as_input_quant8_2();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_nhwc_weight_as_input_quant8());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_valid_padding_nchw();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_nchw_3();
bool is_ignored_nchw_3(int);

TEST_F(NeuralnetworksHidlTest, depthwise_conv2d_dilation_valid_padding_nchw) {
  Execute(device,
          createTestModel_nchw_3,
          is_ignored_nchw_3,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_nchw());
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_valid_padding_nchw) {
  const Model model = createTestModel_nchw_3();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_nchw());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_valid_padding_nchw_relaxed();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_nchw_relaxed_2();
bool is_ignored_nchw_relaxed_2(int);

TEST_F(NeuralnetworksHidlTest, depthwise_conv2d_dilation_valid_padding_nchw_relaxed) {
  Execute(device,
          createTestModel_nchw_relaxed_2,
          is_ignored_nchw_relaxed_2,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_nchw_relaxed());
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_valid_padding_nchw_relaxed) {
  const Model model = createTestModel_nchw_relaxed_2();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_nchw_relaxed());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_valid_padding_nchw_float16();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_nchw_float16_2();
bool is_ignored_nchw_float16_2(int);

TEST_F(NeuralnetworksHidlTest, depthwise_conv2d_dilation_valid_padding_nchw_float16) {
  Execute(device,
          createTestModel_nchw_float16_2,
          is_ignored_nchw_float16_2,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_nchw_float16());
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_valid_padding_nchw_float16) {
  const Model model = createTestModel_nchw_float16_2();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_nchw_float16());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_valid_padding_nchw_quant8();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_nchw_quant8_2();
bool is_ignored_nchw_quant8_2(int);

TEST_F(NeuralnetworksHidlTest, depthwise_conv2d_dilation_valid_padding_nchw_quant8) {
  Execute(device,
          createTestModel_nchw_quant8_2,
          is_ignored_nchw_quant8_2,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_nchw_quant8());
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_valid_padding_nchw_quant8) {
  const Model model = createTestModel_nchw_quant8_2();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_nchw_quant8());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_valid_padding_nchw_weight_as_input();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_nchw_weight_as_input_3();
bool is_ignored_nchw_weight_as_input_3(int);

TEST_F(NeuralnetworksHidlTest, depthwise_conv2d_dilation_valid_padding_nchw_weight_as_input) {
  Execute(device,
          createTestModel_nchw_weight_as_input_3,
          is_ignored_nchw_weight_as_input_3,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_nchw_weight_as_input());
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_valid_padding_nchw_weight_as_input) {
  const Model model = createTestModel_nchw_weight_as_input_3();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_nchw_weight_as_input());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_valid_padding_nchw_weight_as_input_relaxed();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_nchw_weight_as_input_relaxed_2();
bool is_ignored_nchw_weight_as_input_relaxed_2(int);

TEST_F(NeuralnetworksHidlTest, depthwise_conv2d_dilation_valid_padding_nchw_weight_as_input_relaxed) {
  Execute(device,
          createTestModel_nchw_weight_as_input_relaxed_2,
          is_ignored_nchw_weight_as_input_relaxed_2,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_nchw_weight_as_input_relaxed());
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_valid_padding_nchw_weight_as_input_relaxed) {
  const Model model = createTestModel_nchw_weight_as_input_relaxed_2();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_nchw_weight_as_input_relaxed());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_valid_padding_nchw_weight_as_input_float16();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_nchw_weight_as_input_float16_2();
bool is_ignored_nchw_weight_as_input_float16_2(int);

TEST_F(NeuralnetworksHidlTest, depthwise_conv2d_dilation_valid_padding_nchw_weight_as_input_float16) {
  Execute(device,
          createTestModel_nchw_weight_as_input_float16_2,
          is_ignored_nchw_weight_as_input_float16_2,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_nchw_weight_as_input_float16());
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_valid_padding_nchw_weight_as_input_float16) {
  const Model model = createTestModel_nchw_weight_as_input_float16_2();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_nchw_weight_as_input_float16());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_valid_padding_nchw_weight_as_input_quant8();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_nchw_weight_as_input_quant8_2();
bool is_ignored_nchw_weight_as_input_quant8_2(int);

TEST_F(NeuralnetworksHidlTest, depthwise_conv2d_dilation_valid_padding_nchw_weight_as_input_quant8) {
  Execute(device,
          createTestModel_nchw_weight_as_input_quant8_2,
          is_ignored_nchw_weight_as_input_quant8_2,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_nchw_weight_as_input_quant8());
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_valid_padding_nchw_weight_as_input_quant8) {
  const Model model = createTestModel_nchw_weight_as_input_quant8_2();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_nchw_weight_as_input_quant8());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_valid_padding_dynamic_output_shape_nhwc();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_dynamic_output_shape_nhwc_3();
bool is_ignored_dynamic_output_shape_nhwc_3(int);

TEST_F(DynamicOutputShapeTest, depthwise_conv2d_dilation_valid_padding_dynamic_output_shape_nhwc) {
  Execute(device,
          createTestModel_dynamic_output_shape_nhwc_3,
          is_ignored_dynamic_output_shape_nhwc_3,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_dynamic_output_shape_nhwc(), true);
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_valid_padding_dynamic_output_shape_nhwc) {
  const Model model = createTestModel_dynamic_output_shape_nhwc_3();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_dynamic_output_shape_nhwc());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_valid_padding_dynamic_output_shape_nhwc_relaxed();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_dynamic_output_shape_nhwc_relaxed_2();
bool is_ignored_dynamic_output_shape_nhwc_relaxed_2(int);

TEST_F(DynamicOutputShapeTest, depthwise_conv2d_dilation_valid_padding_dynamic_output_shape_nhwc_relaxed) {
  Execute(device,
          createTestModel_dynamic_output_shape_nhwc_relaxed_2,
          is_ignored_dynamic_output_shape_nhwc_relaxed_2,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_dynamic_output_shape_nhwc_relaxed(), true);
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_valid_padding_dynamic_output_shape_nhwc_relaxed) {
  const Model model = createTestModel_dynamic_output_shape_nhwc_relaxed_2();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_dynamic_output_shape_nhwc_relaxed());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_valid_padding_dynamic_output_shape_nhwc_float16();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_dynamic_output_shape_nhwc_float16_2();
bool is_ignored_dynamic_output_shape_nhwc_float16_2(int);

TEST_F(DynamicOutputShapeTest, depthwise_conv2d_dilation_valid_padding_dynamic_output_shape_nhwc_float16) {
  Execute(device,
          createTestModel_dynamic_output_shape_nhwc_float16_2,
          is_ignored_dynamic_output_shape_nhwc_float16_2,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_dynamic_output_shape_nhwc_float16(), true);
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_valid_padding_dynamic_output_shape_nhwc_float16) {
  const Model model = createTestModel_dynamic_output_shape_nhwc_float16_2();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_dynamic_output_shape_nhwc_float16());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_valid_padding_dynamic_output_shape_nhwc_quant8();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_dynamic_output_shape_nhwc_quant8_2();
bool is_ignored_dynamic_output_shape_nhwc_quant8_2(int);

TEST_F(DynamicOutputShapeTest, depthwise_conv2d_dilation_valid_padding_dynamic_output_shape_nhwc_quant8) {
  Execute(device,
          createTestModel_dynamic_output_shape_nhwc_quant8_2,
          is_ignored_dynamic_output_shape_nhwc_quant8_2,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_dynamic_output_shape_nhwc_quant8(), true);
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_valid_padding_dynamic_output_shape_nhwc_quant8) {
  const Model model = createTestModel_dynamic_output_shape_nhwc_quant8_2();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_dynamic_output_shape_nhwc_quant8());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_valid_padding_dynamic_output_shape_nhwc_weight_as_input();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_dynamic_output_shape_nhwc_weight_as_input_3();
bool is_ignored_dynamic_output_shape_nhwc_weight_as_input_3(int);

TEST_F(DynamicOutputShapeTest, depthwise_conv2d_dilation_valid_padding_dynamic_output_shape_nhwc_weight_as_input) {
  Execute(device,
          createTestModel_dynamic_output_shape_nhwc_weight_as_input_3,
          is_ignored_dynamic_output_shape_nhwc_weight_as_input_3,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_dynamic_output_shape_nhwc_weight_as_input(), true);
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_valid_padding_dynamic_output_shape_nhwc_weight_as_input) {
  const Model model = createTestModel_dynamic_output_shape_nhwc_weight_as_input_3();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_dynamic_output_shape_nhwc_weight_as_input());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_valid_padding_dynamic_output_shape_nhwc_weight_as_input_relaxed();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_dynamic_output_shape_nhwc_weight_as_input_relaxed_2();
bool is_ignored_dynamic_output_shape_nhwc_weight_as_input_relaxed_2(int);

TEST_F(DynamicOutputShapeTest, depthwise_conv2d_dilation_valid_padding_dynamic_output_shape_nhwc_weight_as_input_relaxed) {
  Execute(device,
          createTestModel_dynamic_output_shape_nhwc_weight_as_input_relaxed_2,
          is_ignored_dynamic_output_shape_nhwc_weight_as_input_relaxed_2,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_dynamic_output_shape_nhwc_weight_as_input_relaxed(), true);
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_valid_padding_dynamic_output_shape_nhwc_weight_as_input_relaxed) {
  const Model model = createTestModel_dynamic_output_shape_nhwc_weight_as_input_relaxed_2();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_dynamic_output_shape_nhwc_weight_as_input_relaxed());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_valid_padding_dynamic_output_shape_nhwc_weight_as_input_float16();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_dynamic_output_shape_nhwc_weight_as_input_float16_2();
bool is_ignored_dynamic_output_shape_nhwc_weight_as_input_float16_2(int);

TEST_F(DynamicOutputShapeTest, depthwise_conv2d_dilation_valid_padding_dynamic_output_shape_nhwc_weight_as_input_float16) {
  Execute(device,
          createTestModel_dynamic_output_shape_nhwc_weight_as_input_float16_2,
          is_ignored_dynamic_output_shape_nhwc_weight_as_input_float16_2,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_dynamic_output_shape_nhwc_weight_as_input_float16(), true);
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_valid_padding_dynamic_output_shape_nhwc_weight_as_input_float16) {
  const Model model = createTestModel_dynamic_output_shape_nhwc_weight_as_input_float16_2();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_dynamic_output_shape_nhwc_weight_as_input_float16());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_valid_padding_dynamic_output_shape_nhwc_weight_as_input_quant8();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_dynamic_output_shape_nhwc_weight_as_input_quant8_2();
bool is_ignored_dynamic_output_shape_nhwc_weight_as_input_quant8_2(int);

TEST_F(DynamicOutputShapeTest, depthwise_conv2d_dilation_valid_padding_dynamic_output_shape_nhwc_weight_as_input_quant8) {
  Execute(device,
          createTestModel_dynamic_output_shape_nhwc_weight_as_input_quant8_2,
          is_ignored_dynamic_output_shape_nhwc_weight_as_input_quant8_2,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_dynamic_output_shape_nhwc_weight_as_input_quant8(), true);
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_valid_padding_dynamic_output_shape_nhwc_weight_as_input_quant8) {
  const Model model = createTestModel_dynamic_output_shape_nhwc_weight_as_input_quant8_2();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_dynamic_output_shape_nhwc_weight_as_input_quant8());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_valid_padding_dynamic_output_shape_nchw();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_dynamic_output_shape_nchw_3();
bool is_ignored_dynamic_output_shape_nchw_3(int);

TEST_F(DynamicOutputShapeTest, depthwise_conv2d_dilation_valid_padding_dynamic_output_shape_nchw) {
  Execute(device,
          createTestModel_dynamic_output_shape_nchw_3,
          is_ignored_dynamic_output_shape_nchw_3,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_dynamic_output_shape_nchw(), true);
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_valid_padding_dynamic_output_shape_nchw) {
  const Model model = createTestModel_dynamic_output_shape_nchw_3();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_dynamic_output_shape_nchw());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_valid_padding_dynamic_output_shape_nchw_relaxed();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_dynamic_output_shape_nchw_relaxed_2();
bool is_ignored_dynamic_output_shape_nchw_relaxed_2(int);

TEST_F(DynamicOutputShapeTest, depthwise_conv2d_dilation_valid_padding_dynamic_output_shape_nchw_relaxed) {
  Execute(device,
          createTestModel_dynamic_output_shape_nchw_relaxed_2,
          is_ignored_dynamic_output_shape_nchw_relaxed_2,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_dynamic_output_shape_nchw_relaxed(), true);
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_valid_padding_dynamic_output_shape_nchw_relaxed) {
  const Model model = createTestModel_dynamic_output_shape_nchw_relaxed_2();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_dynamic_output_shape_nchw_relaxed());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_valid_padding_dynamic_output_shape_nchw_float16();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_dynamic_output_shape_nchw_float16_2();
bool is_ignored_dynamic_output_shape_nchw_float16_2(int);

TEST_F(DynamicOutputShapeTest, depthwise_conv2d_dilation_valid_padding_dynamic_output_shape_nchw_float16) {
  Execute(device,
          createTestModel_dynamic_output_shape_nchw_float16_2,
          is_ignored_dynamic_output_shape_nchw_float16_2,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_dynamic_output_shape_nchw_float16(), true);
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_valid_padding_dynamic_output_shape_nchw_float16) {
  const Model model = createTestModel_dynamic_output_shape_nchw_float16_2();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_dynamic_output_shape_nchw_float16());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_valid_padding_dynamic_output_shape_nchw_quant8();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_dynamic_output_shape_nchw_quant8_2();
bool is_ignored_dynamic_output_shape_nchw_quant8_2(int);

TEST_F(DynamicOutputShapeTest, depthwise_conv2d_dilation_valid_padding_dynamic_output_shape_nchw_quant8) {
  Execute(device,
          createTestModel_dynamic_output_shape_nchw_quant8_2,
          is_ignored_dynamic_output_shape_nchw_quant8_2,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_dynamic_output_shape_nchw_quant8(), true);
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_valid_padding_dynamic_output_shape_nchw_quant8) {
  const Model model = createTestModel_dynamic_output_shape_nchw_quant8_2();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_dynamic_output_shape_nchw_quant8());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_valid_padding_dynamic_output_shape_nchw_weight_as_input();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_dynamic_output_shape_nchw_weight_as_input_3();
bool is_ignored_dynamic_output_shape_nchw_weight_as_input_3(int);

TEST_F(DynamicOutputShapeTest, depthwise_conv2d_dilation_valid_padding_dynamic_output_shape_nchw_weight_as_input) {
  Execute(device,
          createTestModel_dynamic_output_shape_nchw_weight_as_input_3,
          is_ignored_dynamic_output_shape_nchw_weight_as_input_3,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_dynamic_output_shape_nchw_weight_as_input(), true);
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_valid_padding_dynamic_output_shape_nchw_weight_as_input) {
  const Model model = createTestModel_dynamic_output_shape_nchw_weight_as_input_3();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_dynamic_output_shape_nchw_weight_as_input());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_valid_padding_dynamic_output_shape_nchw_weight_as_input_relaxed();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_dynamic_output_shape_nchw_weight_as_input_relaxed_2();
bool is_ignored_dynamic_output_shape_nchw_weight_as_input_relaxed_2(int);

TEST_F(DynamicOutputShapeTest, depthwise_conv2d_dilation_valid_padding_dynamic_output_shape_nchw_weight_as_input_relaxed) {
  Execute(device,
          createTestModel_dynamic_output_shape_nchw_weight_as_input_relaxed_2,
          is_ignored_dynamic_output_shape_nchw_weight_as_input_relaxed_2,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_dynamic_output_shape_nchw_weight_as_input_relaxed(), true);
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_valid_padding_dynamic_output_shape_nchw_weight_as_input_relaxed) {
  const Model model = createTestModel_dynamic_output_shape_nchw_weight_as_input_relaxed_2();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_dynamic_output_shape_nchw_weight_as_input_relaxed());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_valid_padding_dynamic_output_shape_nchw_weight_as_input_float16();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_dynamic_output_shape_nchw_weight_as_input_float16_2();
bool is_ignored_dynamic_output_shape_nchw_weight_as_input_float16_2(int);

TEST_F(DynamicOutputShapeTest, depthwise_conv2d_dilation_valid_padding_dynamic_output_shape_nchw_weight_as_input_float16) {
  Execute(device,
          createTestModel_dynamic_output_shape_nchw_weight_as_input_float16_2,
          is_ignored_dynamic_output_shape_nchw_weight_as_input_float16_2,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_dynamic_output_shape_nchw_weight_as_input_float16(), true);
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_valid_padding_dynamic_output_shape_nchw_weight_as_input_float16) {
  const Model model = createTestModel_dynamic_output_shape_nchw_weight_as_input_float16_2();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_dynamic_output_shape_nchw_weight_as_input_float16());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_valid_padding_dynamic_output_shape_nchw_weight_as_input_quant8();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_dynamic_output_shape_nchw_weight_as_input_quant8_2();
bool is_ignored_dynamic_output_shape_nchw_weight_as_input_quant8_2(int);

TEST_F(DynamicOutputShapeTest, depthwise_conv2d_dilation_valid_padding_dynamic_output_shape_nchw_weight_as_input_quant8) {
  Execute(device,
          createTestModel_dynamic_output_shape_nchw_weight_as_input_quant8_2,
          is_ignored_dynamic_output_shape_nchw_weight_as_input_quant8_2,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_dynamic_output_shape_nchw_weight_as_input_quant8(), true);
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_valid_padding_dynamic_output_shape_nchw_weight_as_input_quant8) {
  const Model model = createTestModel_dynamic_output_shape_nchw_weight_as_input_quant8_2();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_dynamic_output_shape_nchw_weight_as_input_quant8());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_valid_padding_nhwc_2();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_nhwc_4();
bool is_ignored_nhwc_4(int);

TEST_F(NeuralnetworksHidlTest, depthwise_conv2d_dilation_valid_padding_nhwc_2) {
  Execute(device,
          createTestModel_nhwc_4,
          is_ignored_nhwc_4,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_nhwc_2());
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_valid_padding_nhwc_2) {
  const Model model = createTestModel_nhwc_4();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_nhwc_2());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_valid_padding_nhwc_weight_as_input_2();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_nhwc_weight_as_input_4();
bool is_ignored_nhwc_weight_as_input_4(int);

TEST_F(NeuralnetworksHidlTest, depthwise_conv2d_dilation_valid_padding_nhwc_weight_as_input_2) {
  Execute(device,
          createTestModel_nhwc_weight_as_input_4,
          is_ignored_nhwc_weight_as_input_4,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_nhwc_weight_as_input_2());
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_valid_padding_nhwc_weight_as_input_2) {
  const Model model = createTestModel_nhwc_weight_as_input_4();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_nhwc_weight_as_input_2());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_valid_padding_nchw_2();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_nchw_4();
bool is_ignored_nchw_4(int);

TEST_F(NeuralnetworksHidlTest, depthwise_conv2d_dilation_valid_padding_nchw_2) {
  Execute(device,
          createTestModel_nchw_4,
          is_ignored_nchw_4,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_nchw_2());
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_valid_padding_nchw_2) {
  const Model model = createTestModel_nchw_4();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_nchw_2());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_valid_padding_nchw_weight_as_input_2();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_nchw_weight_as_input_4();
bool is_ignored_nchw_weight_as_input_4(int);

TEST_F(NeuralnetworksHidlTest, depthwise_conv2d_dilation_valid_padding_nchw_weight_as_input_2) {
  Execute(device,
          createTestModel_nchw_weight_as_input_4,
          is_ignored_nchw_weight_as_input_4,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_nchw_weight_as_input_2());
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_valid_padding_nchw_weight_as_input_2) {
  const Model model = createTestModel_nchw_weight_as_input_4();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_nchw_weight_as_input_2());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_valid_padding_dynamic_output_shape_nhwc_2();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_dynamic_output_shape_nhwc_4();
bool is_ignored_dynamic_output_shape_nhwc_4(int);

TEST_F(DynamicOutputShapeTest, depthwise_conv2d_dilation_valid_padding_dynamic_output_shape_nhwc_2) {
  Execute(device,
          createTestModel_dynamic_output_shape_nhwc_4,
          is_ignored_dynamic_output_shape_nhwc_4,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_dynamic_output_shape_nhwc_2(), true);
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_valid_padding_dynamic_output_shape_nhwc_2) {
  const Model model = createTestModel_dynamic_output_shape_nhwc_4();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_dynamic_output_shape_nhwc_2());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_valid_padding_dynamic_output_shape_nhwc_weight_as_input_2();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_dynamic_output_shape_nhwc_weight_as_input_4();
bool is_ignored_dynamic_output_shape_nhwc_weight_as_input_4(int);

TEST_F(DynamicOutputShapeTest, depthwise_conv2d_dilation_valid_padding_dynamic_output_shape_nhwc_weight_as_input_2) {
  Execute(device,
          createTestModel_dynamic_output_shape_nhwc_weight_as_input_4,
          is_ignored_dynamic_output_shape_nhwc_weight_as_input_4,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_dynamic_output_shape_nhwc_weight_as_input_2(), true);
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_valid_padding_dynamic_output_shape_nhwc_weight_as_input_2) {
  const Model model = createTestModel_dynamic_output_shape_nhwc_weight_as_input_4();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_dynamic_output_shape_nhwc_weight_as_input_2());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_valid_padding_dynamic_output_shape_nchw_2();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_dynamic_output_shape_nchw_4();
bool is_ignored_dynamic_output_shape_nchw_4(int);

TEST_F(DynamicOutputShapeTest, depthwise_conv2d_dilation_valid_padding_dynamic_output_shape_nchw_2) {
  Execute(device,
          createTestModel_dynamic_output_shape_nchw_4,
          is_ignored_dynamic_output_shape_nchw_4,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_dynamic_output_shape_nchw_2(), true);
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_valid_padding_dynamic_output_shape_nchw_2) {
  const Model model = createTestModel_dynamic_output_shape_nchw_4();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_dynamic_output_shape_nchw_2());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_valid_padding_dynamic_output_shape_nchw_weight_as_input_2();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_dynamic_output_shape_nchw_weight_as_input_4();
bool is_ignored_dynamic_output_shape_nchw_weight_as_input_4(int);

TEST_F(DynamicOutputShapeTest, depthwise_conv2d_dilation_valid_padding_dynamic_output_shape_nchw_weight_as_input_2) {
  Execute(device,
          createTestModel_dynamic_output_shape_nchw_weight_as_input_4,
          is_ignored_dynamic_output_shape_nchw_weight_as_input_4,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_dynamic_output_shape_nchw_weight_as_input_2(), true);
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_valid_padding_dynamic_output_shape_nchw_weight_as_input_2) {
  const Model model = createTestModel_dynamic_output_shape_nchw_weight_as_input_4();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_valid_padding_dynamic_output_shape_nchw_weight_as_input_2());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_same_padding_stride_2_nhwc();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_nhwc_5();
bool is_ignored_nhwc_5(int);

TEST_F(NeuralnetworksHidlTest, depthwise_conv2d_dilation_same_padding_stride_2_nhwc) {
  Execute(device,
          createTestModel_nhwc_5,
          is_ignored_nhwc_5,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_same_padding_stride_2_nhwc());
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_same_padding_stride_2_nhwc) {
  const Model model = createTestModel_nhwc_5();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_same_padding_stride_2_nhwc());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_same_padding_stride_2_nhwc_relaxed();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_nhwc_relaxed_3();
bool is_ignored_nhwc_relaxed_3(int);

TEST_F(NeuralnetworksHidlTest, depthwise_conv2d_dilation_same_padding_stride_2_nhwc_relaxed) {
  Execute(device,
          createTestModel_nhwc_relaxed_3,
          is_ignored_nhwc_relaxed_3,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_same_padding_stride_2_nhwc_relaxed());
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_same_padding_stride_2_nhwc_relaxed) {
  const Model model = createTestModel_nhwc_relaxed_3();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_same_padding_stride_2_nhwc_relaxed());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_same_padding_stride_2_nhwc_quant8();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_nhwc_quant8_3();
bool is_ignored_nhwc_quant8_3(int);

TEST_F(NeuralnetworksHidlTest, depthwise_conv2d_dilation_same_padding_stride_2_nhwc_quant8) {
  Execute(device,
          createTestModel_nhwc_quant8_3,
          is_ignored_nhwc_quant8_3,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_same_padding_stride_2_nhwc_quant8());
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_same_padding_stride_2_nhwc_quant8) {
  const Model model = createTestModel_nhwc_quant8_3();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_same_padding_stride_2_nhwc_quant8());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_same_padding_stride_2_nhwc_float16();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_nhwc_float16_3();
bool is_ignored_nhwc_float16_3(int);

TEST_F(NeuralnetworksHidlTest, depthwise_conv2d_dilation_same_padding_stride_2_nhwc_float16) {
  Execute(device,
          createTestModel_nhwc_float16_3,
          is_ignored_nhwc_float16_3,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_same_padding_stride_2_nhwc_float16());
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_same_padding_stride_2_nhwc_float16) {
  const Model model = createTestModel_nhwc_float16_3();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_same_padding_stride_2_nhwc_float16());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_same_padding_stride_2_nhwc_weight_as_input();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_nhwc_weight_as_input_5();
bool is_ignored_nhwc_weight_as_input_5(int);

TEST_F(NeuralnetworksHidlTest, depthwise_conv2d_dilation_same_padding_stride_2_nhwc_weight_as_input) {
  Execute(device,
          createTestModel_nhwc_weight_as_input_5,
          is_ignored_nhwc_weight_as_input_5,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_same_padding_stride_2_nhwc_weight_as_input());
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_same_padding_stride_2_nhwc_weight_as_input) {
  const Model model = createTestModel_nhwc_weight_as_input_5();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_same_padding_stride_2_nhwc_weight_as_input());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_same_padding_stride_2_nhwc_weight_as_input_relaxed();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_nhwc_weight_as_input_relaxed_3();
bool is_ignored_nhwc_weight_as_input_relaxed_3(int);

TEST_F(NeuralnetworksHidlTest, depthwise_conv2d_dilation_same_padding_stride_2_nhwc_weight_as_input_relaxed) {
  Execute(device,
          createTestModel_nhwc_weight_as_input_relaxed_3,
          is_ignored_nhwc_weight_as_input_relaxed_3,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_same_padding_stride_2_nhwc_weight_as_input_relaxed());
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_same_padding_stride_2_nhwc_weight_as_input_relaxed) {
  const Model model = createTestModel_nhwc_weight_as_input_relaxed_3();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_same_padding_stride_2_nhwc_weight_as_input_relaxed());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_same_padding_stride_2_nhwc_weight_as_input_quant8();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_nhwc_weight_as_input_quant8_3();
bool is_ignored_nhwc_weight_as_input_quant8_3(int);

TEST_F(NeuralnetworksHidlTest, depthwise_conv2d_dilation_same_padding_stride_2_nhwc_weight_as_input_quant8) {
  Execute(device,
          createTestModel_nhwc_weight_as_input_quant8_3,
          is_ignored_nhwc_weight_as_input_quant8_3,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_same_padding_stride_2_nhwc_weight_as_input_quant8());
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_same_padding_stride_2_nhwc_weight_as_input_quant8) {
  const Model model = createTestModel_nhwc_weight_as_input_quant8_3();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_same_padding_stride_2_nhwc_weight_as_input_quant8());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_same_padding_stride_2_nhwc_weight_as_input_float16();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_nhwc_weight_as_input_float16_3();
bool is_ignored_nhwc_weight_as_input_float16_3(int);

TEST_F(NeuralnetworksHidlTest, depthwise_conv2d_dilation_same_padding_stride_2_nhwc_weight_as_input_float16) {
  Execute(device,
          createTestModel_nhwc_weight_as_input_float16_3,
          is_ignored_nhwc_weight_as_input_float16_3,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_same_padding_stride_2_nhwc_weight_as_input_float16());
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_same_padding_stride_2_nhwc_weight_as_input_float16) {
  const Model model = createTestModel_nhwc_weight_as_input_float16_3();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_same_padding_stride_2_nhwc_weight_as_input_float16());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_same_padding_stride_2_nchw();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_nchw_5();
bool is_ignored_nchw_5(int);

TEST_F(NeuralnetworksHidlTest, depthwise_conv2d_dilation_same_padding_stride_2_nchw) {
  Execute(device,
          createTestModel_nchw_5,
          is_ignored_nchw_5,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_same_padding_stride_2_nchw());
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_same_padding_stride_2_nchw) {
  const Model model = createTestModel_nchw_5();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_same_padding_stride_2_nchw());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_same_padding_stride_2_nchw_relaxed();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_nchw_relaxed_3();
bool is_ignored_nchw_relaxed_3(int);

TEST_F(NeuralnetworksHidlTest, depthwise_conv2d_dilation_same_padding_stride_2_nchw_relaxed) {
  Execute(device,
          createTestModel_nchw_relaxed_3,
          is_ignored_nchw_relaxed_3,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_same_padding_stride_2_nchw_relaxed());
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_same_padding_stride_2_nchw_relaxed) {
  const Model model = createTestModel_nchw_relaxed_3();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_same_padding_stride_2_nchw_relaxed());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_same_padding_stride_2_nchw_quant8();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_nchw_quant8_3();
bool is_ignored_nchw_quant8_3(int);

TEST_F(NeuralnetworksHidlTest, depthwise_conv2d_dilation_same_padding_stride_2_nchw_quant8) {
  Execute(device,
          createTestModel_nchw_quant8_3,
          is_ignored_nchw_quant8_3,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_same_padding_stride_2_nchw_quant8());
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_same_padding_stride_2_nchw_quant8) {
  const Model model = createTestModel_nchw_quant8_3();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_same_padding_stride_2_nchw_quant8());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_same_padding_stride_2_nchw_float16();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_nchw_float16_3();
bool is_ignored_nchw_float16_3(int);

TEST_F(NeuralnetworksHidlTest, depthwise_conv2d_dilation_same_padding_stride_2_nchw_float16) {
  Execute(device,
          createTestModel_nchw_float16_3,
          is_ignored_nchw_float16_3,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_same_padding_stride_2_nchw_float16());
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_same_padding_stride_2_nchw_float16) {
  const Model model = createTestModel_nchw_float16_3();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_same_padding_stride_2_nchw_float16());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_same_padding_stride_2_nchw_weight_as_input();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_nchw_weight_as_input_5();
bool is_ignored_nchw_weight_as_input_5(int);

TEST_F(NeuralnetworksHidlTest, depthwise_conv2d_dilation_same_padding_stride_2_nchw_weight_as_input) {
  Execute(device,
          createTestModel_nchw_weight_as_input_5,
          is_ignored_nchw_weight_as_input_5,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_same_padding_stride_2_nchw_weight_as_input());
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_same_padding_stride_2_nchw_weight_as_input) {
  const Model model = createTestModel_nchw_weight_as_input_5();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_same_padding_stride_2_nchw_weight_as_input());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_same_padding_stride_2_nchw_weight_as_input_relaxed();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_nchw_weight_as_input_relaxed_3();
bool is_ignored_nchw_weight_as_input_relaxed_3(int);

TEST_F(NeuralnetworksHidlTest, depthwise_conv2d_dilation_same_padding_stride_2_nchw_weight_as_input_relaxed) {
  Execute(device,
          createTestModel_nchw_weight_as_input_relaxed_3,
          is_ignored_nchw_weight_as_input_relaxed_3,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_same_padding_stride_2_nchw_weight_as_input_relaxed());
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_same_padding_stride_2_nchw_weight_as_input_relaxed) {
  const Model model = createTestModel_nchw_weight_as_input_relaxed_3();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_same_padding_stride_2_nchw_weight_as_input_relaxed());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_same_padding_stride_2_nchw_weight_as_input_quant8();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_nchw_weight_as_input_quant8_3();
bool is_ignored_nchw_weight_as_input_quant8_3(int);

TEST_F(NeuralnetworksHidlTest, depthwise_conv2d_dilation_same_padding_stride_2_nchw_weight_as_input_quant8) {
  Execute(device,
          createTestModel_nchw_weight_as_input_quant8_3,
          is_ignored_nchw_weight_as_input_quant8_3,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_same_padding_stride_2_nchw_weight_as_input_quant8());
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_same_padding_stride_2_nchw_weight_as_input_quant8) {
  const Model model = createTestModel_nchw_weight_as_input_quant8_3();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_same_padding_stride_2_nchw_weight_as_input_quant8());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_same_padding_stride_2_nchw_weight_as_input_float16();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_nchw_weight_as_input_float16_3();
bool is_ignored_nchw_weight_as_input_float16_3(int);

TEST_F(NeuralnetworksHidlTest, depthwise_conv2d_dilation_same_padding_stride_2_nchw_weight_as_input_float16) {
  Execute(device,
          createTestModel_nchw_weight_as_input_float16_3,
          is_ignored_nchw_weight_as_input_float16_3,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_same_padding_stride_2_nchw_weight_as_input_float16());
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_same_padding_stride_2_nchw_weight_as_input_float16) {
  const Model model = createTestModel_nchw_weight_as_input_float16_3();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_same_padding_stride_2_nchw_weight_as_input_float16());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_same_padding_stride_2_dynamic_output_shape_nhwc();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_dynamic_output_shape_nhwc_5();
bool is_ignored_dynamic_output_shape_nhwc_5(int);

TEST_F(DynamicOutputShapeTest, depthwise_conv2d_dilation_same_padding_stride_2_dynamic_output_shape_nhwc) {
  Execute(device,
          createTestModel_dynamic_output_shape_nhwc_5,
          is_ignored_dynamic_output_shape_nhwc_5,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_same_padding_stride_2_dynamic_output_shape_nhwc(), true);
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_same_padding_stride_2_dynamic_output_shape_nhwc) {
  const Model model = createTestModel_dynamic_output_shape_nhwc_5();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_same_padding_stride_2_dynamic_output_shape_nhwc());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_same_padding_stride_2_dynamic_output_shape_nhwc_relaxed();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_dynamic_output_shape_nhwc_relaxed_3();
bool is_ignored_dynamic_output_shape_nhwc_relaxed_3(int);

TEST_F(DynamicOutputShapeTest, depthwise_conv2d_dilation_same_padding_stride_2_dynamic_output_shape_nhwc_relaxed) {
  Execute(device,
          createTestModel_dynamic_output_shape_nhwc_relaxed_3,
          is_ignored_dynamic_output_shape_nhwc_relaxed_3,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_same_padding_stride_2_dynamic_output_shape_nhwc_relaxed(), true);
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_same_padding_stride_2_dynamic_output_shape_nhwc_relaxed) {
  const Model model = createTestModel_dynamic_output_shape_nhwc_relaxed_3();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_same_padding_stride_2_dynamic_output_shape_nhwc_relaxed());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_same_padding_stride_2_dynamic_output_shape_nhwc_quant8();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_dynamic_output_shape_nhwc_quant8_3();
bool is_ignored_dynamic_output_shape_nhwc_quant8_3(int);

TEST_F(DynamicOutputShapeTest, depthwise_conv2d_dilation_same_padding_stride_2_dynamic_output_shape_nhwc_quant8) {
  Execute(device,
          createTestModel_dynamic_output_shape_nhwc_quant8_3,
          is_ignored_dynamic_output_shape_nhwc_quant8_3,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_same_padding_stride_2_dynamic_output_shape_nhwc_quant8(), true);
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_same_padding_stride_2_dynamic_output_shape_nhwc_quant8) {
  const Model model = createTestModel_dynamic_output_shape_nhwc_quant8_3();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_same_padding_stride_2_dynamic_output_shape_nhwc_quant8());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_same_padding_stride_2_dynamic_output_shape_nhwc_float16();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_dynamic_output_shape_nhwc_float16_3();
bool is_ignored_dynamic_output_shape_nhwc_float16_3(int);

TEST_F(DynamicOutputShapeTest, depthwise_conv2d_dilation_same_padding_stride_2_dynamic_output_shape_nhwc_float16) {
  Execute(device,
          createTestModel_dynamic_output_shape_nhwc_float16_3,
          is_ignored_dynamic_output_shape_nhwc_float16_3,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_same_padding_stride_2_dynamic_output_shape_nhwc_float16(), true);
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_same_padding_stride_2_dynamic_output_shape_nhwc_float16) {
  const Model model = createTestModel_dynamic_output_shape_nhwc_float16_3();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_same_padding_stride_2_dynamic_output_shape_nhwc_float16());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_same_padding_stride_2_dynamic_output_shape_nhwc_weight_as_input();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_dynamic_output_shape_nhwc_weight_as_input_5();
bool is_ignored_dynamic_output_shape_nhwc_weight_as_input_5(int);

TEST_F(DynamicOutputShapeTest, depthwise_conv2d_dilation_same_padding_stride_2_dynamic_output_shape_nhwc_weight_as_input) {
  Execute(device,
          createTestModel_dynamic_output_shape_nhwc_weight_as_input_5,
          is_ignored_dynamic_output_shape_nhwc_weight_as_input_5,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_same_padding_stride_2_dynamic_output_shape_nhwc_weight_as_input(), true);
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_same_padding_stride_2_dynamic_output_shape_nhwc_weight_as_input) {
  const Model model = createTestModel_dynamic_output_shape_nhwc_weight_as_input_5();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_same_padding_stride_2_dynamic_output_shape_nhwc_weight_as_input());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_same_padding_stride_2_dynamic_output_shape_nhwc_weight_as_input_relaxed();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_dynamic_output_shape_nhwc_weight_as_input_relaxed_3();
bool is_ignored_dynamic_output_shape_nhwc_weight_as_input_relaxed_3(int);

TEST_F(DynamicOutputShapeTest, depthwise_conv2d_dilation_same_padding_stride_2_dynamic_output_shape_nhwc_weight_as_input_relaxed) {
  Execute(device,
          createTestModel_dynamic_output_shape_nhwc_weight_as_input_relaxed_3,
          is_ignored_dynamic_output_shape_nhwc_weight_as_input_relaxed_3,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_same_padding_stride_2_dynamic_output_shape_nhwc_weight_as_input_relaxed(), true);
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_same_padding_stride_2_dynamic_output_shape_nhwc_weight_as_input_relaxed) {
  const Model model = createTestModel_dynamic_output_shape_nhwc_weight_as_input_relaxed_3();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_same_padding_stride_2_dynamic_output_shape_nhwc_weight_as_input_relaxed());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_same_padding_stride_2_dynamic_output_shape_nhwc_weight_as_input_quant8();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_dynamic_output_shape_nhwc_weight_as_input_quant8_3();
bool is_ignored_dynamic_output_shape_nhwc_weight_as_input_quant8_3(int);

TEST_F(DynamicOutputShapeTest, depthwise_conv2d_dilation_same_padding_stride_2_dynamic_output_shape_nhwc_weight_as_input_quant8) {
  Execute(device,
          createTestModel_dynamic_output_shape_nhwc_weight_as_input_quant8_3,
          is_ignored_dynamic_output_shape_nhwc_weight_as_input_quant8_3,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_same_padding_stride_2_dynamic_output_shape_nhwc_weight_as_input_quant8(), true);
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_same_padding_stride_2_dynamic_output_shape_nhwc_weight_as_input_quant8) {
  const Model model = createTestModel_dynamic_output_shape_nhwc_weight_as_input_quant8_3();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_same_padding_stride_2_dynamic_output_shape_nhwc_weight_as_input_quant8());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_same_padding_stride_2_dynamic_output_shape_nhwc_weight_as_input_float16();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_dynamic_output_shape_nhwc_weight_as_input_float16_3();
bool is_ignored_dynamic_output_shape_nhwc_weight_as_input_float16_3(int);

TEST_F(DynamicOutputShapeTest, depthwise_conv2d_dilation_same_padding_stride_2_dynamic_output_shape_nhwc_weight_as_input_float16) {
  Execute(device,
          createTestModel_dynamic_output_shape_nhwc_weight_as_input_float16_3,
          is_ignored_dynamic_output_shape_nhwc_weight_as_input_float16_3,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_same_padding_stride_2_dynamic_output_shape_nhwc_weight_as_input_float16(), true);
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_same_padding_stride_2_dynamic_output_shape_nhwc_weight_as_input_float16) {
  const Model model = createTestModel_dynamic_output_shape_nhwc_weight_as_input_float16_3();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_same_padding_stride_2_dynamic_output_shape_nhwc_weight_as_input_float16());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_same_padding_stride_2_dynamic_output_shape_nchw();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_dynamic_output_shape_nchw_5();
bool is_ignored_dynamic_output_shape_nchw_5(int);

TEST_F(DynamicOutputShapeTest, depthwise_conv2d_dilation_same_padding_stride_2_dynamic_output_shape_nchw) {
  Execute(device,
          createTestModel_dynamic_output_shape_nchw_5,
          is_ignored_dynamic_output_shape_nchw_5,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_same_padding_stride_2_dynamic_output_shape_nchw(), true);
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_same_padding_stride_2_dynamic_output_shape_nchw) {
  const Model model = createTestModel_dynamic_output_shape_nchw_5();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_same_padding_stride_2_dynamic_output_shape_nchw());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_same_padding_stride_2_dynamic_output_shape_nchw_relaxed();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_dynamic_output_shape_nchw_relaxed_3();
bool is_ignored_dynamic_output_shape_nchw_relaxed_3(int);

TEST_F(DynamicOutputShapeTest, depthwise_conv2d_dilation_same_padding_stride_2_dynamic_output_shape_nchw_relaxed) {
  Execute(device,
          createTestModel_dynamic_output_shape_nchw_relaxed_3,
          is_ignored_dynamic_output_shape_nchw_relaxed_3,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_same_padding_stride_2_dynamic_output_shape_nchw_relaxed(), true);
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_same_padding_stride_2_dynamic_output_shape_nchw_relaxed) {
  const Model model = createTestModel_dynamic_output_shape_nchw_relaxed_3();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_same_padding_stride_2_dynamic_output_shape_nchw_relaxed());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_same_padding_stride_2_dynamic_output_shape_nchw_quant8();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_dynamic_output_shape_nchw_quant8_3();
bool is_ignored_dynamic_output_shape_nchw_quant8_3(int);

TEST_F(DynamicOutputShapeTest, depthwise_conv2d_dilation_same_padding_stride_2_dynamic_output_shape_nchw_quant8) {
  Execute(device,
          createTestModel_dynamic_output_shape_nchw_quant8_3,
          is_ignored_dynamic_output_shape_nchw_quant8_3,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_same_padding_stride_2_dynamic_output_shape_nchw_quant8(), true);
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_same_padding_stride_2_dynamic_output_shape_nchw_quant8) {
  const Model model = createTestModel_dynamic_output_shape_nchw_quant8_3();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_same_padding_stride_2_dynamic_output_shape_nchw_quant8());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_same_padding_stride_2_dynamic_output_shape_nchw_float16();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_dynamic_output_shape_nchw_float16_3();
bool is_ignored_dynamic_output_shape_nchw_float16_3(int);

TEST_F(DynamicOutputShapeTest, depthwise_conv2d_dilation_same_padding_stride_2_dynamic_output_shape_nchw_float16) {
  Execute(device,
          createTestModel_dynamic_output_shape_nchw_float16_3,
          is_ignored_dynamic_output_shape_nchw_float16_3,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_same_padding_stride_2_dynamic_output_shape_nchw_float16(), true);
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_same_padding_stride_2_dynamic_output_shape_nchw_float16) {
  const Model model = createTestModel_dynamic_output_shape_nchw_float16_3();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_same_padding_stride_2_dynamic_output_shape_nchw_float16());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_same_padding_stride_2_dynamic_output_shape_nchw_weight_as_input();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_dynamic_output_shape_nchw_weight_as_input_5();
bool is_ignored_dynamic_output_shape_nchw_weight_as_input_5(int);

TEST_F(DynamicOutputShapeTest, depthwise_conv2d_dilation_same_padding_stride_2_dynamic_output_shape_nchw_weight_as_input) {
  Execute(device,
          createTestModel_dynamic_output_shape_nchw_weight_as_input_5,
          is_ignored_dynamic_output_shape_nchw_weight_as_input_5,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_same_padding_stride_2_dynamic_output_shape_nchw_weight_as_input(), true);
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_same_padding_stride_2_dynamic_output_shape_nchw_weight_as_input) {
  const Model model = createTestModel_dynamic_output_shape_nchw_weight_as_input_5();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_same_padding_stride_2_dynamic_output_shape_nchw_weight_as_input());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_same_padding_stride_2_dynamic_output_shape_nchw_weight_as_input_relaxed();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_dynamic_output_shape_nchw_weight_as_input_relaxed_3();
bool is_ignored_dynamic_output_shape_nchw_weight_as_input_relaxed_3(int);

TEST_F(DynamicOutputShapeTest, depthwise_conv2d_dilation_same_padding_stride_2_dynamic_output_shape_nchw_weight_as_input_relaxed) {
  Execute(device,
          createTestModel_dynamic_output_shape_nchw_weight_as_input_relaxed_3,
          is_ignored_dynamic_output_shape_nchw_weight_as_input_relaxed_3,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_same_padding_stride_2_dynamic_output_shape_nchw_weight_as_input_relaxed(), true);
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_same_padding_stride_2_dynamic_output_shape_nchw_weight_as_input_relaxed) {
  const Model model = createTestModel_dynamic_output_shape_nchw_weight_as_input_relaxed_3();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_same_padding_stride_2_dynamic_output_shape_nchw_weight_as_input_relaxed());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_same_padding_stride_2_dynamic_output_shape_nchw_weight_as_input_quant8();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_dynamic_output_shape_nchw_weight_as_input_quant8_3();
bool is_ignored_dynamic_output_shape_nchw_weight_as_input_quant8_3(int);

TEST_F(DynamicOutputShapeTest, depthwise_conv2d_dilation_same_padding_stride_2_dynamic_output_shape_nchw_weight_as_input_quant8) {
  Execute(device,
          createTestModel_dynamic_output_shape_nchw_weight_as_input_quant8_3,
          is_ignored_dynamic_output_shape_nchw_weight_as_input_quant8_3,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_same_padding_stride_2_dynamic_output_shape_nchw_weight_as_input_quant8(), true);
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_same_padding_stride_2_dynamic_output_shape_nchw_weight_as_input_quant8) {
  const Model model = createTestModel_dynamic_output_shape_nchw_weight_as_input_quant8_3();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_same_padding_stride_2_dynamic_output_shape_nchw_weight_as_input_quant8());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

namespace generated_tests::depthwise_conv2d_dilation {

std::vector<::test_helper::MixedTypedExample>& get_examples_same_padding_stride_2_dynamic_output_shape_nchw_weight_as_input_float16();

} // namespace generated_tests::depthwise_conv2d_dilation

namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation {

Model createTestModel_dynamic_output_shape_nchw_weight_as_input_float16_3();
bool is_ignored_dynamic_output_shape_nchw_weight_as_input_float16_3(int);

TEST_F(DynamicOutputShapeTest, depthwise_conv2d_dilation_same_padding_stride_2_dynamic_output_shape_nchw_weight_as_input_float16) {
  Execute(device,
          createTestModel_dynamic_output_shape_nchw_weight_as_input_float16_3,
          is_ignored_dynamic_output_shape_nchw_weight_as_input_float16_3,
          ::generated_tests::depthwise_conv2d_dilation::get_examples_same_padding_stride_2_dynamic_output_shape_nchw_weight_as_input_float16(), true);
}

TEST_F(ValidationTest, depthwise_conv2d_dilation_same_padding_stride_2_dynamic_output_shape_nchw_weight_as_input_float16) {
  const Model model = createTestModel_dynamic_output_shape_nchw_weight_as_input_float16_3();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_dilation::get_examples_same_padding_stride_2_dynamic_output_shape_nchw_weight_as_input_float16());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::depthwise_conv2d_dilation

