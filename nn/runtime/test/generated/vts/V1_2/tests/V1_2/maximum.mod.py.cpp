// Generated from maximum.mod.py
// DO NOT EDIT
// clang-format off
#include "GeneratedTests.h"

namespace generated_tests::maximum {

std::vector<::test_helper::MixedTypedExample>& get_examples_simple();

} // namespace generated_tests::maximum

namespace android::hardware::neuralnetworks::V1_2::generated_tests::maximum {

Model createTestModel();
bool is_ignored(int);

TEST_F(NeuralnetworksHidlTest, maximum_simple) {
  Execute(device,
          createTestModel,
          is_ignored,
          ::generated_tests::maximum::get_examples_simple());
}

TEST_F(ValidationTest, maximum_simple) {
  const Model model = createTestModel();
  const std::vector<Request> requests = createRequests(::generated_tests::maximum::get_examples_simple());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::maximum

namespace generated_tests::maximum {

std::vector<::test_helper::MixedTypedExample>& get_examples_simple_relaxed();

} // namespace generated_tests::maximum

namespace android::hardware::neuralnetworks::V1_2::generated_tests::maximum {

Model createTestModel_relaxed();
bool is_ignored_relaxed(int);

TEST_F(NeuralnetworksHidlTest, maximum_simple_relaxed) {
  Execute(device,
          createTestModel_relaxed,
          is_ignored_relaxed,
          ::generated_tests::maximum::get_examples_simple_relaxed());
}

TEST_F(ValidationTest, maximum_simple_relaxed) {
  const Model model = createTestModel_relaxed();
  const std::vector<Request> requests = createRequests(::generated_tests::maximum::get_examples_simple_relaxed());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::maximum

namespace generated_tests::maximum {

std::vector<::test_helper::MixedTypedExample>& get_examples_simple_float16();

} // namespace generated_tests::maximum

namespace android::hardware::neuralnetworks::V1_2::generated_tests::maximum {

Model createTestModel_float16();
bool is_ignored_float16(int);

TEST_F(NeuralnetworksHidlTest, maximum_simple_float16) {
  Execute(device,
          createTestModel_float16,
          is_ignored_float16,
          ::generated_tests::maximum::get_examples_simple_float16());
}

TEST_F(ValidationTest, maximum_simple_float16) {
  const Model model = createTestModel_float16();
  const std::vector<Request> requests = createRequests(::generated_tests::maximum::get_examples_simple_float16());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::maximum

namespace generated_tests::maximum {

std::vector<::test_helper::MixedTypedExample>& get_examples_simple_int32();

} // namespace generated_tests::maximum

namespace android::hardware::neuralnetworks::V1_2::generated_tests::maximum {

Model createTestModel_int32();
bool is_ignored_int32(int);

TEST_F(NeuralnetworksHidlTest, maximum_simple_int32) {
  Execute(device,
          createTestModel_int32,
          is_ignored_int32,
          ::generated_tests::maximum::get_examples_simple_int32());
}

TEST_F(ValidationTest, maximum_simple_int32) {
  const Model model = createTestModel_int32();
  const std::vector<Request> requests = createRequests(::generated_tests::maximum::get_examples_simple_int32());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::maximum

namespace generated_tests::maximum {

std::vector<::test_helper::MixedTypedExample>& get_examples_simple_quant8();

} // namespace generated_tests::maximum

namespace android::hardware::neuralnetworks::V1_2::generated_tests::maximum {

Model createTestModel_quant8();
bool is_ignored_quant8(int);

TEST_F(NeuralnetworksHidlTest, maximum_simple_quant8) {
  Execute(device,
          createTestModel_quant8,
          is_ignored_quant8,
          ::generated_tests::maximum::get_examples_simple_quant8());
}

TEST_F(ValidationTest, maximum_simple_quant8) {
  const Model model = createTestModel_quant8();
  const std::vector<Request> requests = createRequests(::generated_tests::maximum::get_examples_simple_quant8());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::maximum

namespace generated_tests::maximum {

std::vector<::test_helper::MixedTypedExample>& get_examples_simple_dynamic_output_shape();

} // namespace generated_tests::maximum

namespace android::hardware::neuralnetworks::V1_2::generated_tests::maximum {

Model createTestModel_dynamic_output_shape();
bool is_ignored_dynamic_output_shape(int);

TEST_F(DynamicOutputShapeTest, maximum_simple_dynamic_output_shape) {
  Execute(device,
          createTestModel_dynamic_output_shape,
          is_ignored_dynamic_output_shape,
          ::generated_tests::maximum::get_examples_simple_dynamic_output_shape(), true);
}

TEST_F(ValidationTest, maximum_simple_dynamic_output_shape) {
  const Model model = createTestModel_dynamic_output_shape();
  const std::vector<Request> requests = createRequests(::generated_tests::maximum::get_examples_simple_dynamic_output_shape());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::maximum

namespace generated_tests::maximum {

std::vector<::test_helper::MixedTypedExample>& get_examples_simple_dynamic_output_shape_relaxed();

} // namespace generated_tests::maximum

namespace android::hardware::neuralnetworks::V1_2::generated_tests::maximum {

Model createTestModel_dynamic_output_shape_relaxed();
bool is_ignored_dynamic_output_shape_relaxed(int);

TEST_F(DynamicOutputShapeTest, maximum_simple_dynamic_output_shape_relaxed) {
  Execute(device,
          createTestModel_dynamic_output_shape_relaxed,
          is_ignored_dynamic_output_shape_relaxed,
          ::generated_tests::maximum::get_examples_simple_dynamic_output_shape_relaxed(), true);
}

TEST_F(ValidationTest, maximum_simple_dynamic_output_shape_relaxed) {
  const Model model = createTestModel_dynamic_output_shape_relaxed();
  const std::vector<Request> requests = createRequests(::generated_tests::maximum::get_examples_simple_dynamic_output_shape_relaxed());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::maximum

namespace generated_tests::maximum {

std::vector<::test_helper::MixedTypedExample>& get_examples_simple_dynamic_output_shape_float16();

} // namespace generated_tests::maximum

namespace android::hardware::neuralnetworks::V1_2::generated_tests::maximum {

Model createTestModel_dynamic_output_shape_float16();
bool is_ignored_dynamic_output_shape_float16(int);

TEST_F(DynamicOutputShapeTest, maximum_simple_dynamic_output_shape_float16) {
  Execute(device,
          createTestModel_dynamic_output_shape_float16,
          is_ignored_dynamic_output_shape_float16,
          ::generated_tests::maximum::get_examples_simple_dynamic_output_shape_float16(), true);
}

TEST_F(ValidationTest, maximum_simple_dynamic_output_shape_float16) {
  const Model model = createTestModel_dynamic_output_shape_float16();
  const std::vector<Request> requests = createRequests(::generated_tests::maximum::get_examples_simple_dynamic_output_shape_float16());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::maximum

namespace generated_tests::maximum {

std::vector<::test_helper::MixedTypedExample>& get_examples_simple_dynamic_output_shape_int32();

} // namespace generated_tests::maximum

namespace android::hardware::neuralnetworks::V1_2::generated_tests::maximum {

Model createTestModel_dynamic_output_shape_int32();
bool is_ignored_dynamic_output_shape_int32(int);

TEST_F(DynamicOutputShapeTest, maximum_simple_dynamic_output_shape_int32) {
  Execute(device,
          createTestModel_dynamic_output_shape_int32,
          is_ignored_dynamic_output_shape_int32,
          ::generated_tests::maximum::get_examples_simple_dynamic_output_shape_int32(), true);
}

TEST_F(ValidationTest, maximum_simple_dynamic_output_shape_int32) {
  const Model model = createTestModel_dynamic_output_shape_int32();
  const std::vector<Request> requests = createRequests(::generated_tests::maximum::get_examples_simple_dynamic_output_shape_int32());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::maximum

namespace generated_tests::maximum {

std::vector<::test_helper::MixedTypedExample>& get_examples_simple_dynamic_output_shape_quant8();

} // namespace generated_tests::maximum

namespace android::hardware::neuralnetworks::V1_2::generated_tests::maximum {

Model createTestModel_dynamic_output_shape_quant8();
bool is_ignored_dynamic_output_shape_quant8(int);

TEST_F(DynamicOutputShapeTest, maximum_simple_dynamic_output_shape_quant8) {
  Execute(device,
          createTestModel_dynamic_output_shape_quant8,
          is_ignored_dynamic_output_shape_quant8,
          ::generated_tests::maximum::get_examples_simple_dynamic_output_shape_quant8(), true);
}

TEST_F(ValidationTest, maximum_simple_dynamic_output_shape_quant8) {
  const Model model = createTestModel_dynamic_output_shape_quant8();
  const std::vector<Request> requests = createRequests(::generated_tests::maximum::get_examples_simple_dynamic_output_shape_quant8());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::maximum

namespace generated_tests::maximum {

std::vector<::test_helper::MixedTypedExample>& get_examples_broadcast();

} // namespace generated_tests::maximum

namespace android::hardware::neuralnetworks::V1_2::generated_tests::maximum {

Model createTestModel_2();
bool is_ignored_2(int);

TEST_F(NeuralnetworksHidlTest, maximum_broadcast) {
  Execute(device,
          createTestModel_2,
          is_ignored_2,
          ::generated_tests::maximum::get_examples_broadcast());
}

TEST_F(ValidationTest, maximum_broadcast) {
  const Model model = createTestModel_2();
  const std::vector<Request> requests = createRequests(::generated_tests::maximum::get_examples_broadcast());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::maximum

namespace generated_tests::maximum {

std::vector<::test_helper::MixedTypedExample>& get_examples_broadcast_relaxed();

} // namespace generated_tests::maximum

namespace android::hardware::neuralnetworks::V1_2::generated_tests::maximum {

Model createTestModel_relaxed_2();
bool is_ignored_relaxed_2(int);

TEST_F(NeuralnetworksHidlTest, maximum_broadcast_relaxed) {
  Execute(device,
          createTestModel_relaxed_2,
          is_ignored_relaxed_2,
          ::generated_tests::maximum::get_examples_broadcast_relaxed());
}

TEST_F(ValidationTest, maximum_broadcast_relaxed) {
  const Model model = createTestModel_relaxed_2();
  const std::vector<Request> requests = createRequests(::generated_tests::maximum::get_examples_broadcast_relaxed());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::maximum

namespace generated_tests::maximum {

std::vector<::test_helper::MixedTypedExample>& get_examples_broadcast_float16();

} // namespace generated_tests::maximum

namespace android::hardware::neuralnetworks::V1_2::generated_tests::maximum {

Model createTestModel_float16_2();
bool is_ignored_float16_2(int);

TEST_F(NeuralnetworksHidlTest, maximum_broadcast_float16) {
  Execute(device,
          createTestModel_float16_2,
          is_ignored_float16_2,
          ::generated_tests::maximum::get_examples_broadcast_float16());
}

TEST_F(ValidationTest, maximum_broadcast_float16) {
  const Model model = createTestModel_float16_2();
  const std::vector<Request> requests = createRequests(::generated_tests::maximum::get_examples_broadcast_float16());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::maximum

namespace generated_tests::maximum {

std::vector<::test_helper::MixedTypedExample>& get_examples_broadcast_int32();

} // namespace generated_tests::maximum

namespace android::hardware::neuralnetworks::V1_2::generated_tests::maximum {

Model createTestModel_int32_2();
bool is_ignored_int32_2(int);

TEST_F(NeuralnetworksHidlTest, maximum_broadcast_int32) {
  Execute(device,
          createTestModel_int32_2,
          is_ignored_int32_2,
          ::generated_tests::maximum::get_examples_broadcast_int32());
}

TEST_F(ValidationTest, maximum_broadcast_int32) {
  const Model model = createTestModel_int32_2();
  const std::vector<Request> requests = createRequests(::generated_tests::maximum::get_examples_broadcast_int32());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::maximum

namespace generated_tests::maximum {

std::vector<::test_helper::MixedTypedExample>& get_examples_broadcast_quant8();

} // namespace generated_tests::maximum

namespace android::hardware::neuralnetworks::V1_2::generated_tests::maximum {

Model createTestModel_quant8_2();
bool is_ignored_quant8_2(int);

TEST_F(NeuralnetworksHidlTest, maximum_broadcast_quant8) {
  Execute(device,
          createTestModel_quant8_2,
          is_ignored_quant8_2,
          ::generated_tests::maximum::get_examples_broadcast_quant8());
}

TEST_F(ValidationTest, maximum_broadcast_quant8) {
  const Model model = createTestModel_quant8_2();
  const std::vector<Request> requests = createRequests(::generated_tests::maximum::get_examples_broadcast_quant8());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::maximum

namespace generated_tests::maximum {

std::vector<::test_helper::MixedTypedExample>& get_examples_broadcast_dynamic_output_shape();

} // namespace generated_tests::maximum

namespace android::hardware::neuralnetworks::V1_2::generated_tests::maximum {

Model createTestModel_dynamic_output_shape_2();
bool is_ignored_dynamic_output_shape_2(int);

TEST_F(DynamicOutputShapeTest, maximum_broadcast_dynamic_output_shape) {
  Execute(device,
          createTestModel_dynamic_output_shape_2,
          is_ignored_dynamic_output_shape_2,
          ::generated_tests::maximum::get_examples_broadcast_dynamic_output_shape(), true);
}

TEST_F(ValidationTest, maximum_broadcast_dynamic_output_shape) {
  const Model model = createTestModel_dynamic_output_shape_2();
  const std::vector<Request> requests = createRequests(::generated_tests::maximum::get_examples_broadcast_dynamic_output_shape());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::maximum

namespace generated_tests::maximum {

std::vector<::test_helper::MixedTypedExample>& get_examples_broadcast_dynamic_output_shape_relaxed();

} // namespace generated_tests::maximum

namespace android::hardware::neuralnetworks::V1_2::generated_tests::maximum {

Model createTestModel_dynamic_output_shape_relaxed_2();
bool is_ignored_dynamic_output_shape_relaxed_2(int);

TEST_F(DynamicOutputShapeTest, maximum_broadcast_dynamic_output_shape_relaxed) {
  Execute(device,
          createTestModel_dynamic_output_shape_relaxed_2,
          is_ignored_dynamic_output_shape_relaxed_2,
          ::generated_tests::maximum::get_examples_broadcast_dynamic_output_shape_relaxed(), true);
}

TEST_F(ValidationTest, maximum_broadcast_dynamic_output_shape_relaxed) {
  const Model model = createTestModel_dynamic_output_shape_relaxed_2();
  const std::vector<Request> requests = createRequests(::generated_tests::maximum::get_examples_broadcast_dynamic_output_shape_relaxed());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::maximum

namespace generated_tests::maximum {

std::vector<::test_helper::MixedTypedExample>& get_examples_broadcast_dynamic_output_shape_float16();

} // namespace generated_tests::maximum

namespace android::hardware::neuralnetworks::V1_2::generated_tests::maximum {

Model createTestModel_dynamic_output_shape_float16_2();
bool is_ignored_dynamic_output_shape_float16_2(int);

TEST_F(DynamicOutputShapeTest, maximum_broadcast_dynamic_output_shape_float16) {
  Execute(device,
          createTestModel_dynamic_output_shape_float16_2,
          is_ignored_dynamic_output_shape_float16_2,
          ::generated_tests::maximum::get_examples_broadcast_dynamic_output_shape_float16(), true);
}

TEST_F(ValidationTest, maximum_broadcast_dynamic_output_shape_float16) {
  const Model model = createTestModel_dynamic_output_shape_float16_2();
  const std::vector<Request> requests = createRequests(::generated_tests::maximum::get_examples_broadcast_dynamic_output_shape_float16());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::maximum

namespace generated_tests::maximum {

std::vector<::test_helper::MixedTypedExample>& get_examples_broadcast_dynamic_output_shape_int32();

} // namespace generated_tests::maximum

namespace android::hardware::neuralnetworks::V1_2::generated_tests::maximum {

Model createTestModel_dynamic_output_shape_int32_2();
bool is_ignored_dynamic_output_shape_int32_2(int);

TEST_F(DynamicOutputShapeTest, maximum_broadcast_dynamic_output_shape_int32) {
  Execute(device,
          createTestModel_dynamic_output_shape_int32_2,
          is_ignored_dynamic_output_shape_int32_2,
          ::generated_tests::maximum::get_examples_broadcast_dynamic_output_shape_int32(), true);
}

TEST_F(ValidationTest, maximum_broadcast_dynamic_output_shape_int32) {
  const Model model = createTestModel_dynamic_output_shape_int32_2();
  const std::vector<Request> requests = createRequests(::generated_tests::maximum::get_examples_broadcast_dynamic_output_shape_int32());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::maximum

namespace generated_tests::maximum {

std::vector<::test_helper::MixedTypedExample>& get_examples_broadcast_dynamic_output_shape_quant8();

} // namespace generated_tests::maximum

namespace android::hardware::neuralnetworks::V1_2::generated_tests::maximum {

Model createTestModel_dynamic_output_shape_quant8_2();
bool is_ignored_dynamic_output_shape_quant8_2(int);

TEST_F(DynamicOutputShapeTest, maximum_broadcast_dynamic_output_shape_quant8) {
  Execute(device,
          createTestModel_dynamic_output_shape_quant8_2,
          is_ignored_dynamic_output_shape_quant8_2,
          ::generated_tests::maximum::get_examples_broadcast_dynamic_output_shape_quant8(), true);
}

TEST_F(ValidationTest, maximum_broadcast_dynamic_output_shape_quant8) {
  const Model model = createTestModel_dynamic_output_shape_quant8_2();
  const std::vector<Request> requests = createRequests(::generated_tests::maximum::get_examples_broadcast_dynamic_output_shape_quant8());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::maximum

namespace generated_tests::maximum {

std::vector<::test_helper::MixedTypedExample>& get_examples_overflow();

} // namespace generated_tests::maximum

namespace android::hardware::neuralnetworks::V1_2::generated_tests::maximum {

Model createTestModel_3();
bool is_ignored_3(int);

TEST_F(NeuralnetworksHidlTest, maximum_overflow) {
  Execute(device,
          createTestModel_3,
          is_ignored_3,
          ::generated_tests::maximum::get_examples_overflow());
}

TEST_F(ValidationTest, maximum_overflow) {
  const Model model = createTestModel_3();
  const std::vector<Request> requests = createRequests(::generated_tests::maximum::get_examples_overflow());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::maximum

namespace generated_tests::maximum {

std::vector<::test_helper::MixedTypedExample>& get_examples_overflow_dynamic_output_shape();

} // namespace generated_tests::maximum

namespace android::hardware::neuralnetworks::V1_2::generated_tests::maximum {

Model createTestModel_dynamic_output_shape_3();
bool is_ignored_dynamic_output_shape_3(int);

TEST_F(DynamicOutputShapeTest, maximum_overflow_dynamic_output_shape) {
  Execute(device,
          createTestModel_dynamic_output_shape_3,
          is_ignored_dynamic_output_shape_3,
          ::generated_tests::maximum::get_examples_overflow_dynamic_output_shape(), true);
}

TEST_F(ValidationTest, maximum_overflow_dynamic_output_shape) {
  const Model model = createTestModel_dynamic_output_shape_3();
  const std::vector<Request> requests = createRequests(::generated_tests::maximum::get_examples_overflow_dynamic_output_shape());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::maximum

