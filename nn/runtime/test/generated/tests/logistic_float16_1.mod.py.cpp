// clang-format off
// Generated file (from: logistic_float16_1.mod.py). Do not edit
#include "../../TestGenerated.h"

namespace logistic_float16_1 {
// Generated logistic_float16_1 test
#include "generated/examples/logistic_float16_1.example.cpp"
// Generated model constructor
#include "generated/models/logistic_float16_1.model.cpp"
} // namespace logistic_float16_1

TEST_F(GeneratedTests, logistic_float16_1) {
    execute(logistic_float16_1::CreateModel,
            logistic_float16_1::is_ignored,
            logistic_float16_1::get_examples());
}

