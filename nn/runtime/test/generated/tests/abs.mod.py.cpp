// clang-format off
// Generated file (from: abs.mod.py). Do not edit
#include "../../TestGenerated.h"

namespace abs {
// Generated abs test
#include "generated/examples/abs.example.cpp"
// Generated model constructor
#include "generated/models/abs.model.cpp"
} // namespace abs

TEST_F(GeneratedTests, abs) {
    execute(abs::CreateModel,
            abs::is_ignored,
            abs::get_examples());
}

TEST_F(GeneratedTests, abs_relaxed) {
    execute(abs::CreateModel_relaxed,
            abs::is_ignored_relaxed,
            abs::get_examples_relaxed());
}

TEST_F(GeneratedTests, abs_float16) {
    execute(abs::CreateModel_float16,
            abs::is_ignored_float16,
            abs::get_examples_float16());
}

