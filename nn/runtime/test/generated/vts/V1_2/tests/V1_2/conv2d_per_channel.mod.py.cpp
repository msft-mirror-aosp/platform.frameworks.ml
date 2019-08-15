// Generated from conv2d_per_channel.mod.py
// DO NOT EDIT
// clang-format off
#include "GeneratedTests.h"

namespace generated_tests::conv2d_per_channel {

std::vector<::test_helper::MixedTypedExample>& get_examples();

} // namespace generated_tests::conv2d_per_channel

namespace android::hardware::neuralnetworks::V1_2::generated_tests::conv2d_per_channel {

Model createTestModel();
bool is_ignored(int);

TEST_F(NeuralnetworksHidlTest, conv2d_per_channel) {
  Execute(device,
          createTestModel,
          is_ignored,
          ::generated_tests::conv2d_per_channel::get_examples());
}

TEST_F(ValidationTest, conv2d_per_channel) {
  const Model model = createTestModel();
  const std::vector<Request> requests = createRequests(::generated_tests::conv2d_per_channel::get_examples());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::conv2d_per_channel

namespace generated_tests::conv2d_per_channel {

std::vector<::test_helper::MixedTypedExample>& get_examples_weight_as_input();

} // namespace generated_tests::conv2d_per_channel

namespace android::hardware::neuralnetworks::V1_2::generated_tests::conv2d_per_channel {

Model createTestModel_weight_as_input();
bool is_ignored_weight_as_input(int);

TEST_F(NeuralnetworksHidlTest, conv2d_per_channel_weight_as_input) {
  Execute(device,
          createTestModel_weight_as_input,
          is_ignored_weight_as_input,
          ::generated_tests::conv2d_per_channel::get_examples_weight_as_input());
}

TEST_F(ValidationTest, conv2d_per_channel_weight_as_input) {
  const Model model = createTestModel_weight_as_input();
  const std::vector<Request> requests = createRequests(::generated_tests::conv2d_per_channel::get_examples_weight_as_input());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::conv2d_per_channel

namespace generated_tests::conv2d_per_channel {

std::vector<::test_helper::MixedTypedExample>& get_examples_dynamic_output_shape();

} // namespace generated_tests::conv2d_per_channel

namespace android::hardware::neuralnetworks::V1_2::generated_tests::conv2d_per_channel {

Model createTestModel_dynamic_output_shape();
bool is_ignored_dynamic_output_shape(int);

TEST_F(DynamicOutputShapeTest, conv2d_per_channel_dynamic_output_shape) {
  Execute(device,
          createTestModel_dynamic_output_shape,
          is_ignored_dynamic_output_shape,
          ::generated_tests::conv2d_per_channel::get_examples_dynamic_output_shape(), true);
}

TEST_F(ValidationTest, conv2d_per_channel_dynamic_output_shape) {
  const Model model = createTestModel_dynamic_output_shape();
  const std::vector<Request> requests = createRequests(::generated_tests::conv2d_per_channel::get_examples_dynamic_output_shape());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::conv2d_per_channel

namespace generated_tests::conv2d_per_channel {

std::vector<::test_helper::MixedTypedExample>& get_examples_dynamic_output_shape_weight_as_input();

} // namespace generated_tests::conv2d_per_channel

namespace android::hardware::neuralnetworks::V1_2::generated_tests::conv2d_per_channel {

Model createTestModel_dynamic_output_shape_weight_as_input();
bool is_ignored_dynamic_output_shape_weight_as_input(int);

TEST_F(DynamicOutputShapeTest, conv2d_per_channel_dynamic_output_shape_weight_as_input) {
  Execute(device,
          createTestModel_dynamic_output_shape_weight_as_input,
          is_ignored_dynamic_output_shape_weight_as_input,
          ::generated_tests::conv2d_per_channel::get_examples_dynamic_output_shape_weight_as_input(), true);
}

TEST_F(ValidationTest, conv2d_per_channel_dynamic_output_shape_weight_as_input) {
  const Model model = createTestModel_dynamic_output_shape_weight_as_input();
  const std::vector<Request> requests = createRequests(::generated_tests::conv2d_per_channel::get_examples_dynamic_output_shape_weight_as_input());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::conv2d_per_channel

namespace generated_tests::conv2d_per_channel {

std::vector<::test_helper::MixedTypedExample>& get_examples_layouts_nhwc();

} // namespace generated_tests::conv2d_per_channel

namespace android::hardware::neuralnetworks::V1_2::generated_tests::conv2d_per_channel {

Model createTestModel_layouts_nhwc();
bool is_ignored_layouts_nhwc(int);

TEST_F(NeuralnetworksHidlTest, conv2d_per_channel_layouts_nhwc) {
  Execute(device,
          createTestModel_layouts_nhwc,
          is_ignored_layouts_nhwc,
          ::generated_tests::conv2d_per_channel::get_examples_layouts_nhwc());
}

TEST_F(ValidationTest, conv2d_per_channel_layouts_nhwc) {
  const Model model = createTestModel_layouts_nhwc();
  const std::vector<Request> requests = createRequests(::generated_tests::conv2d_per_channel::get_examples_layouts_nhwc());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::conv2d_per_channel

namespace generated_tests::conv2d_per_channel {

std::vector<::test_helper::MixedTypedExample>& get_examples_layouts_nhwc_weight_as_input();

} // namespace generated_tests::conv2d_per_channel

namespace android::hardware::neuralnetworks::V1_2::generated_tests::conv2d_per_channel {

Model createTestModel_layouts_nhwc_weight_as_input();
bool is_ignored_layouts_nhwc_weight_as_input(int);

TEST_F(NeuralnetworksHidlTest, conv2d_per_channel_layouts_nhwc_weight_as_input) {
  Execute(device,
          createTestModel_layouts_nhwc_weight_as_input,
          is_ignored_layouts_nhwc_weight_as_input,
          ::generated_tests::conv2d_per_channel::get_examples_layouts_nhwc_weight_as_input());
}

TEST_F(ValidationTest, conv2d_per_channel_layouts_nhwc_weight_as_input) {
  const Model model = createTestModel_layouts_nhwc_weight_as_input();
  const std::vector<Request> requests = createRequests(::generated_tests::conv2d_per_channel::get_examples_layouts_nhwc_weight_as_input());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::conv2d_per_channel

namespace generated_tests::conv2d_per_channel {

std::vector<::test_helper::MixedTypedExample>& get_examples_layouts_nchw();

} // namespace generated_tests::conv2d_per_channel

namespace android::hardware::neuralnetworks::V1_2::generated_tests::conv2d_per_channel {

Model createTestModel_layouts_nchw();
bool is_ignored_layouts_nchw(int);

TEST_F(NeuralnetworksHidlTest, conv2d_per_channel_layouts_nchw) {
  Execute(device,
          createTestModel_layouts_nchw,
          is_ignored_layouts_nchw,
          ::generated_tests::conv2d_per_channel::get_examples_layouts_nchw());
}

TEST_F(ValidationTest, conv2d_per_channel_layouts_nchw) {
  const Model model = createTestModel_layouts_nchw();
  const std::vector<Request> requests = createRequests(::generated_tests::conv2d_per_channel::get_examples_layouts_nchw());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::conv2d_per_channel

namespace generated_tests::conv2d_per_channel {

std::vector<::test_helper::MixedTypedExample>& get_examples_layouts_nchw_weight_as_input();

} // namespace generated_tests::conv2d_per_channel

namespace android::hardware::neuralnetworks::V1_2::generated_tests::conv2d_per_channel {

Model createTestModel_layouts_nchw_weight_as_input();
bool is_ignored_layouts_nchw_weight_as_input(int);

TEST_F(NeuralnetworksHidlTest, conv2d_per_channel_layouts_nchw_weight_as_input) {
  Execute(device,
          createTestModel_layouts_nchw_weight_as_input,
          is_ignored_layouts_nchw_weight_as_input,
          ::generated_tests::conv2d_per_channel::get_examples_layouts_nchw_weight_as_input());
}

TEST_F(ValidationTest, conv2d_per_channel_layouts_nchw_weight_as_input) {
  const Model model = createTestModel_layouts_nchw_weight_as_input();
  const std::vector<Request> requests = createRequests(::generated_tests::conv2d_per_channel::get_examples_layouts_nchw_weight_as_input());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::conv2d_per_channel

namespace generated_tests::conv2d_per_channel {

std::vector<::test_helper::MixedTypedExample>& get_examples_layouts_dynamic_output_shape_nhwc();

} // namespace generated_tests::conv2d_per_channel

namespace android::hardware::neuralnetworks::V1_2::generated_tests::conv2d_per_channel {

Model createTestModel_layouts_dynamic_output_shape_nhwc();
bool is_ignored_layouts_dynamic_output_shape_nhwc(int);

TEST_F(DynamicOutputShapeTest, conv2d_per_channel_layouts_dynamic_output_shape_nhwc) {
  Execute(device,
          createTestModel_layouts_dynamic_output_shape_nhwc,
          is_ignored_layouts_dynamic_output_shape_nhwc,
          ::generated_tests::conv2d_per_channel::get_examples_layouts_dynamic_output_shape_nhwc(), true);
}

TEST_F(ValidationTest, conv2d_per_channel_layouts_dynamic_output_shape_nhwc) {
  const Model model = createTestModel_layouts_dynamic_output_shape_nhwc();
  const std::vector<Request> requests = createRequests(::generated_tests::conv2d_per_channel::get_examples_layouts_dynamic_output_shape_nhwc());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::conv2d_per_channel

namespace generated_tests::conv2d_per_channel {

std::vector<::test_helper::MixedTypedExample>& get_examples_layouts_dynamic_output_shape_nhwc_weight_as_input();

} // namespace generated_tests::conv2d_per_channel

namespace android::hardware::neuralnetworks::V1_2::generated_tests::conv2d_per_channel {

Model createTestModel_layouts_dynamic_output_shape_nhwc_weight_as_input();
bool is_ignored_layouts_dynamic_output_shape_nhwc_weight_as_input(int);

TEST_F(DynamicOutputShapeTest, conv2d_per_channel_layouts_dynamic_output_shape_nhwc_weight_as_input) {
  Execute(device,
          createTestModel_layouts_dynamic_output_shape_nhwc_weight_as_input,
          is_ignored_layouts_dynamic_output_shape_nhwc_weight_as_input,
          ::generated_tests::conv2d_per_channel::get_examples_layouts_dynamic_output_shape_nhwc_weight_as_input(), true);
}

TEST_F(ValidationTest, conv2d_per_channel_layouts_dynamic_output_shape_nhwc_weight_as_input) {
  const Model model = createTestModel_layouts_dynamic_output_shape_nhwc_weight_as_input();
  const std::vector<Request> requests = createRequests(::generated_tests::conv2d_per_channel::get_examples_layouts_dynamic_output_shape_nhwc_weight_as_input());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::conv2d_per_channel

namespace generated_tests::conv2d_per_channel {

std::vector<::test_helper::MixedTypedExample>& get_examples_layouts_dynamic_output_shape_nchw();

} // namespace generated_tests::conv2d_per_channel

namespace android::hardware::neuralnetworks::V1_2::generated_tests::conv2d_per_channel {

Model createTestModel_layouts_dynamic_output_shape_nchw();
bool is_ignored_layouts_dynamic_output_shape_nchw(int);

TEST_F(DynamicOutputShapeTest, conv2d_per_channel_layouts_dynamic_output_shape_nchw) {
  Execute(device,
          createTestModel_layouts_dynamic_output_shape_nchw,
          is_ignored_layouts_dynamic_output_shape_nchw,
          ::generated_tests::conv2d_per_channel::get_examples_layouts_dynamic_output_shape_nchw(), true);
}

TEST_F(ValidationTest, conv2d_per_channel_layouts_dynamic_output_shape_nchw) {
  const Model model = createTestModel_layouts_dynamic_output_shape_nchw();
  const std::vector<Request> requests = createRequests(::generated_tests::conv2d_per_channel::get_examples_layouts_dynamic_output_shape_nchw());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::conv2d_per_channel

namespace generated_tests::conv2d_per_channel {

std::vector<::test_helper::MixedTypedExample>& get_examples_layouts_dynamic_output_shape_nchw_weight_as_input();

} // namespace generated_tests::conv2d_per_channel

namespace android::hardware::neuralnetworks::V1_2::generated_tests::conv2d_per_channel {

Model createTestModel_layouts_dynamic_output_shape_nchw_weight_as_input();
bool is_ignored_layouts_dynamic_output_shape_nchw_weight_as_input(int);

TEST_F(DynamicOutputShapeTest, conv2d_per_channel_layouts_dynamic_output_shape_nchw_weight_as_input) {
  Execute(device,
          createTestModel_layouts_dynamic_output_shape_nchw_weight_as_input,
          is_ignored_layouts_dynamic_output_shape_nchw_weight_as_input,
          ::generated_tests::conv2d_per_channel::get_examples_layouts_dynamic_output_shape_nchw_weight_as_input(), true);
}

TEST_F(ValidationTest, conv2d_per_channel_layouts_dynamic_output_shape_nchw_weight_as_input) {
  const Model model = createTestModel_layouts_dynamic_output_shape_nchw_weight_as_input();
  const std::vector<Request> requests = createRequests(::generated_tests::conv2d_per_channel::get_examples_layouts_dynamic_output_shape_nchw_weight_as_input());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::conv2d_per_channel

namespace generated_tests::conv2d_per_channel {

std::vector<::test_helper::MixedTypedExample>& get_examples_zero_sized_nhwc();

} // namespace generated_tests::conv2d_per_channel

namespace android::hardware::neuralnetworks::V1_2::generated_tests::conv2d_per_channel {

Model createTestModel_zero_sized_nhwc();
bool is_ignored_zero_sized_nhwc(int);

TEST_F(NeuralnetworksHidlTest, conv2d_per_channel_zero_sized_nhwc) {
  Execute(device,
          createTestModel_zero_sized_nhwc,
          is_ignored_zero_sized_nhwc,
          ::generated_tests::conv2d_per_channel::get_examples_zero_sized_nhwc());
}

TEST_F(ValidationTest, conv2d_per_channel_zero_sized_nhwc) {
  const Model model = createTestModel_zero_sized_nhwc();
  const std::vector<Request> requests = createRequests(::generated_tests::conv2d_per_channel::get_examples_zero_sized_nhwc());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::conv2d_per_channel

namespace generated_tests::conv2d_per_channel {

std::vector<::test_helper::MixedTypedExample>& get_examples_zero_sized_nchw();

} // namespace generated_tests::conv2d_per_channel

namespace android::hardware::neuralnetworks::V1_2::generated_tests::conv2d_per_channel {

Model createTestModel_zero_sized_nchw();
bool is_ignored_zero_sized_nchw(int);

TEST_F(NeuralnetworksHidlTest, conv2d_per_channel_zero_sized_nchw) {
  Execute(device,
          createTestModel_zero_sized_nchw,
          is_ignored_zero_sized_nchw,
          ::generated_tests::conv2d_per_channel::get_examples_zero_sized_nchw());
}

TEST_F(ValidationTest, conv2d_per_channel_zero_sized_nchw) {
  const Model model = createTestModel_zero_sized_nchw();
  const std::vector<Request> requests = createRequests(::generated_tests::conv2d_per_channel::get_examples_zero_sized_nchw());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::conv2d_per_channel

namespace generated_tests::conv2d_per_channel {

std::vector<::test_helper::MixedTypedExample>& get_examples_zero_sized_dynamic_output_shape_nhwc();

} // namespace generated_tests::conv2d_per_channel

namespace android::hardware::neuralnetworks::V1_2::generated_tests::conv2d_per_channel {

Model createTestModel_zero_sized_dynamic_output_shape_nhwc();
bool is_ignored_zero_sized_dynamic_output_shape_nhwc(int);

TEST_F(DynamicOutputShapeTest, conv2d_per_channel_zero_sized_dynamic_output_shape_nhwc) {
  Execute(device,
          createTestModel_zero_sized_dynamic_output_shape_nhwc,
          is_ignored_zero_sized_dynamic_output_shape_nhwc,
          ::generated_tests::conv2d_per_channel::get_examples_zero_sized_dynamic_output_shape_nhwc(), true);
}

TEST_F(ValidationTest, conv2d_per_channel_zero_sized_dynamic_output_shape_nhwc) {
  const Model model = createTestModel_zero_sized_dynamic_output_shape_nhwc();
  const std::vector<Request> requests = createRequests(::generated_tests::conv2d_per_channel::get_examples_zero_sized_dynamic_output_shape_nhwc());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::conv2d_per_channel

namespace generated_tests::conv2d_per_channel {

std::vector<::test_helper::MixedTypedExample>& get_examples_zero_sized_dynamic_output_shape_nchw();

} // namespace generated_tests::conv2d_per_channel

namespace android::hardware::neuralnetworks::V1_2::generated_tests::conv2d_per_channel {

Model createTestModel_zero_sized_dynamic_output_shape_nchw();
bool is_ignored_zero_sized_dynamic_output_shape_nchw(int);

TEST_F(DynamicOutputShapeTest, conv2d_per_channel_zero_sized_dynamic_output_shape_nchw) {
  Execute(device,
          createTestModel_zero_sized_dynamic_output_shape_nchw,
          is_ignored_zero_sized_dynamic_output_shape_nchw,
          ::generated_tests::conv2d_per_channel::get_examples_zero_sized_dynamic_output_shape_nchw(), true);
}

TEST_F(ValidationTest, conv2d_per_channel_zero_sized_dynamic_output_shape_nchw) {
  const Model model = createTestModel_zero_sized_dynamic_output_shape_nchw();
  const std::vector<Request> requests = createRequests(::generated_tests::conv2d_per_channel::get_examples_zero_sized_dynamic_output_shape_nchw());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::conv2d_per_channel

