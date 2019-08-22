// Generated from argmax_1.mod.py
// DO NOT EDIT
// clang-format off
#include "GeneratedTests.h"


namespace generated_tests::argmax_1 {

const ::test_helper::TestModel& get_test_model();

} // namespace generated_tests::argmax_1

namespace android::hardware::neuralnetworks::V1_2::generated_tests::argmax_1 {

TEST_F(GeneratedTest, argmax_1) {
    Execute(device, ::generated_tests::argmax_1::get_test_model());
}

TEST_F(DynamicOutputShapeTest, argmax_1) {
    Execute(device, ::generated_tests::argmax_1::get_test_model(), true);
}

TEST_F(ValidationTest, argmax_1) {
    const Model model = createModel(::generated_tests::argmax_1::get_test_model());
    const Request request = createRequest(::generated_tests::argmax_1::get_test_model());
    validateEverything(model, request);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::argmax_1


namespace generated_tests::argmax_1 {

const ::test_helper::TestModel& get_test_model_all_inputs_as_internal();

} // namespace generated_tests::argmax_1

namespace android::hardware::neuralnetworks::V1_2::generated_tests::argmax_1 {

TEST_F(GeneratedTest, argmax_1_all_inputs_as_internal) {
    Execute(device, ::generated_tests::argmax_1::get_test_model_all_inputs_as_internal());
}

TEST_F(DynamicOutputShapeTest, argmax_1_all_inputs_as_internal) {
    Execute(device, ::generated_tests::argmax_1::get_test_model_all_inputs_as_internal(), true);
}

TEST_F(ValidationTest, argmax_1_all_inputs_as_internal) {
    const Model model = createModel(::generated_tests::argmax_1::get_test_model_all_inputs_as_internal());
    const Request request = createRequest(::generated_tests::argmax_1::get_test_model_all_inputs_as_internal());
    validateEverything(model, request);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::argmax_1


namespace generated_tests::argmax_1 {

const ::test_helper::TestModel& get_test_model_relaxed();

} // namespace generated_tests::argmax_1

namespace android::hardware::neuralnetworks::V1_2::generated_tests::argmax_1 {

TEST_F(GeneratedTest, argmax_1_relaxed) {
    Execute(device, ::generated_tests::argmax_1::get_test_model_relaxed());
}

TEST_F(DynamicOutputShapeTest, argmax_1_relaxed) {
    Execute(device, ::generated_tests::argmax_1::get_test_model_relaxed(), true);
}

TEST_F(ValidationTest, argmax_1_relaxed) {
    const Model model = createModel(::generated_tests::argmax_1::get_test_model_relaxed());
    const Request request = createRequest(::generated_tests::argmax_1::get_test_model_relaxed());
    validateEverything(model, request);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::argmax_1


namespace generated_tests::argmax_1 {

const ::test_helper::TestModel& get_test_model_relaxed_all_inputs_as_internal();

} // namespace generated_tests::argmax_1

namespace android::hardware::neuralnetworks::V1_2::generated_tests::argmax_1 {

TEST_F(GeneratedTest, argmax_1_relaxed_all_inputs_as_internal) {
    Execute(device, ::generated_tests::argmax_1::get_test_model_relaxed_all_inputs_as_internal());
}

TEST_F(DynamicOutputShapeTest, argmax_1_relaxed_all_inputs_as_internal) {
    Execute(device, ::generated_tests::argmax_1::get_test_model_relaxed_all_inputs_as_internal(), true);
}

TEST_F(ValidationTest, argmax_1_relaxed_all_inputs_as_internal) {
    const Model model = createModel(::generated_tests::argmax_1::get_test_model_relaxed_all_inputs_as_internal());
    const Request request = createRequest(::generated_tests::argmax_1::get_test_model_relaxed_all_inputs_as_internal());
    validateEverything(model, request);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::argmax_1


namespace generated_tests::argmax_1 {

const ::test_helper::TestModel& get_test_model_float16();

} // namespace generated_tests::argmax_1

namespace android::hardware::neuralnetworks::V1_2::generated_tests::argmax_1 {

TEST_F(GeneratedTest, argmax_1_float16) {
    Execute(device, ::generated_tests::argmax_1::get_test_model_float16());
}

TEST_F(DynamicOutputShapeTest, argmax_1_float16) {
    Execute(device, ::generated_tests::argmax_1::get_test_model_float16(), true);
}

TEST_F(ValidationTest, argmax_1_float16) {
    const Model model = createModel(::generated_tests::argmax_1::get_test_model_float16());
    const Request request = createRequest(::generated_tests::argmax_1::get_test_model_float16());
    validateEverything(model, request);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::argmax_1


namespace generated_tests::argmax_1 {

const ::test_helper::TestModel& get_test_model_float16_all_inputs_as_internal();

} // namespace generated_tests::argmax_1

namespace android::hardware::neuralnetworks::V1_2::generated_tests::argmax_1 {

TEST_F(GeneratedTest, argmax_1_float16_all_inputs_as_internal) {
    Execute(device, ::generated_tests::argmax_1::get_test_model_float16_all_inputs_as_internal());
}

TEST_F(DynamicOutputShapeTest, argmax_1_float16_all_inputs_as_internal) {
    Execute(device, ::generated_tests::argmax_1::get_test_model_float16_all_inputs_as_internal(), true);
}

TEST_F(ValidationTest, argmax_1_float16_all_inputs_as_internal) {
    const Model model = createModel(::generated_tests::argmax_1::get_test_model_float16_all_inputs_as_internal());
    const Request request = createRequest(::generated_tests::argmax_1::get_test_model_float16_all_inputs_as_internal());
    validateEverything(model, request);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::argmax_1


namespace generated_tests::argmax_1 {

const ::test_helper::TestModel& get_test_model_int32();

} // namespace generated_tests::argmax_1

namespace android::hardware::neuralnetworks::V1_2::generated_tests::argmax_1 {

TEST_F(GeneratedTest, argmax_1_int32) {
    Execute(device, ::generated_tests::argmax_1::get_test_model_int32());
}

TEST_F(DynamicOutputShapeTest, argmax_1_int32) {
    Execute(device, ::generated_tests::argmax_1::get_test_model_int32(), true);
}

TEST_F(ValidationTest, argmax_1_int32) {
    const Model model = createModel(::generated_tests::argmax_1::get_test_model_int32());
    const Request request = createRequest(::generated_tests::argmax_1::get_test_model_int32());
    validateEverything(model, request);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::argmax_1


namespace generated_tests::argmax_1 {

const ::test_helper::TestModel& get_test_model_quant8();

} // namespace generated_tests::argmax_1

namespace android::hardware::neuralnetworks::V1_2::generated_tests::argmax_1 {

TEST_F(GeneratedTest, argmax_1_quant8) {
    Execute(device, ::generated_tests::argmax_1::get_test_model_quant8());
}

TEST_F(DynamicOutputShapeTest, argmax_1_quant8) {
    Execute(device, ::generated_tests::argmax_1::get_test_model_quant8(), true);
}

TEST_F(ValidationTest, argmax_1_quant8) {
    const Model model = createModel(::generated_tests::argmax_1::get_test_model_quant8());
    const Request request = createRequest(::generated_tests::argmax_1::get_test_model_quant8());
    validateEverything(model, request);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::argmax_1


namespace generated_tests::argmax_1 {

const ::test_helper::TestModel& get_test_model_quant8_all_inputs_as_internal();

} // namespace generated_tests::argmax_1

namespace android::hardware::neuralnetworks::V1_2::generated_tests::argmax_1 {

TEST_F(GeneratedTest, argmax_1_quant8_all_inputs_as_internal) {
    Execute(device, ::generated_tests::argmax_1::get_test_model_quant8_all_inputs_as_internal());
}

TEST_F(DynamicOutputShapeTest, argmax_1_quant8_all_inputs_as_internal) {
    Execute(device, ::generated_tests::argmax_1::get_test_model_quant8_all_inputs_as_internal(), true);
}

TEST_F(ValidationTest, argmax_1_quant8_all_inputs_as_internal) {
    const Model model = createModel(::generated_tests::argmax_1::get_test_model_quant8_all_inputs_as_internal());
    const Request request = createRequest(::generated_tests::argmax_1::get_test_model_quant8_all_inputs_as_internal());
    validateEverything(model, request);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::argmax_1
