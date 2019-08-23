// Generated from lstm.mod.py
// DO NOT EDIT
// clang-format off
#include "GeneratedTests.h"


namespace generated_tests::lstm {

const ::test_helper::TestModel& get_test_model();

} // namespace generated_tests::lstm

namespace android::hardware::neuralnetworks::V1_0::generated_tests::lstm {

TEST_F(GeneratedTest, lstm) {
    Execute(device, ::generated_tests::lstm::get_test_model());
}

TEST_F(ValidationTest, lstm) {
    const Model model = createModel(::generated_tests::lstm::get_test_model());
    const Request request = createRequest(::generated_tests::lstm::get_test_model());
    validateEverything(model, request);
}

} // namespace android::hardware::neuralnetworks::V1_0::generated_tests::lstm


namespace generated_tests::lstm {

const ::test_helper::TestModel& get_test_model_all_inputs_as_internal();

} // namespace generated_tests::lstm

namespace android::hardware::neuralnetworks::V1_0::generated_tests::lstm {

TEST_F(GeneratedTest, lstm_all_inputs_as_internal) {
    Execute(device, ::generated_tests::lstm::get_test_model_all_inputs_as_internal());
}

TEST_F(ValidationTest, lstm_all_inputs_as_internal) {
    const Model model = createModel(::generated_tests::lstm::get_test_model_all_inputs_as_internal());
    const Request request = createRequest(::generated_tests::lstm::get_test_model_all_inputs_as_internal());
    validateEverything(model, request);
}

} // namespace android::hardware::neuralnetworks::V1_0::generated_tests::lstm
