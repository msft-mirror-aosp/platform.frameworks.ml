// Generated from strided_slice_qaunt8_11.mod.py
// DO NOT EDIT
// clang-format off
#include "GeneratedTests.h"


namespace generated_tests::strided_slice_qaunt8_11 {

const ::test_helper::TestModel& get_test_model();

} // namespace generated_tests::strided_slice_qaunt8_11

namespace android::hardware::neuralnetworks::V1_1::generated_tests::strided_slice_qaunt8_11 {

TEST_F(GeneratedTest, strided_slice_qaunt8_11) {
    Execute(device, ::generated_tests::strided_slice_qaunt8_11::get_test_model());
}

TEST_F(ValidationTest, strided_slice_qaunt8_11) {
    const Model model = createModel(::generated_tests::strided_slice_qaunt8_11::get_test_model());
    const Request request = createRequest(::generated_tests::strided_slice_qaunt8_11::get_test_model());
    validateEverything(model, request);
}

} // namespace android::hardware::neuralnetworks::V1_1::generated_tests::strided_slice_qaunt8_11


namespace generated_tests::strided_slice_qaunt8_11 {

const ::test_helper::TestModel& get_test_model_all_inputs_as_internal();

} // namespace generated_tests::strided_slice_qaunt8_11

namespace android::hardware::neuralnetworks::V1_1::generated_tests::strided_slice_qaunt8_11 {

TEST_F(GeneratedTest, strided_slice_qaunt8_11_all_inputs_as_internal) {
    Execute(device, ::generated_tests::strided_slice_qaunt8_11::get_test_model_all_inputs_as_internal());
}

TEST_F(ValidationTest, strided_slice_qaunt8_11_all_inputs_as_internal) {
    const Model model = createModel(::generated_tests::strided_slice_qaunt8_11::get_test_model_all_inputs_as_internal());
    const Request request = createRequest(::generated_tests::strided_slice_qaunt8_11::get_test_model_all_inputs_as_internal());
    validateEverything(model, request);
}

} // namespace android::hardware::neuralnetworks::V1_1::generated_tests::strided_slice_qaunt8_11


namespace generated_tests::strided_slice_qaunt8_11 {

const ::test_helper::TestModel& get_test_model_all_tensors_as_inputs();

} // namespace generated_tests::strided_slice_qaunt8_11

namespace android::hardware::neuralnetworks::V1_1::generated_tests::strided_slice_qaunt8_11 {

TEST_F(GeneratedTest, strided_slice_qaunt8_11_all_tensors_as_inputs) {
    Execute(device, ::generated_tests::strided_slice_qaunt8_11::get_test_model_all_tensors_as_inputs());
}

TEST_F(ValidationTest, strided_slice_qaunt8_11_all_tensors_as_inputs) {
    const Model model = createModel(::generated_tests::strided_slice_qaunt8_11::get_test_model_all_tensors_as_inputs());
    const Request request = createRequest(::generated_tests::strided_slice_qaunt8_11::get_test_model_all_tensors_as_inputs());
    validateEverything(model, request);
}

} // namespace android::hardware::neuralnetworks::V1_1::generated_tests::strided_slice_qaunt8_11


namespace generated_tests::strided_slice_qaunt8_11 {

const ::test_helper::TestModel& get_test_model_all_tensors_as_inputs_all_inputs_as_internal();

} // namespace generated_tests::strided_slice_qaunt8_11

namespace android::hardware::neuralnetworks::V1_1::generated_tests::strided_slice_qaunt8_11 {

TEST_F(GeneratedTest, strided_slice_qaunt8_11_all_tensors_as_inputs_all_inputs_as_internal) {
    Execute(device, ::generated_tests::strided_slice_qaunt8_11::get_test_model_all_tensors_as_inputs_all_inputs_as_internal());
}

TEST_F(ValidationTest, strided_slice_qaunt8_11_all_tensors_as_inputs_all_inputs_as_internal) {
    const Model model = createModel(::generated_tests::strided_slice_qaunt8_11::get_test_model_all_tensors_as_inputs_all_inputs_as_internal());
    const Request request = createRequest(::generated_tests::strided_slice_qaunt8_11::get_test_model_all_tensors_as_inputs_all_inputs_as_internal());
    validateEverything(model, request);
}

} // namespace android::hardware::neuralnetworks::V1_1::generated_tests::strided_slice_qaunt8_11
