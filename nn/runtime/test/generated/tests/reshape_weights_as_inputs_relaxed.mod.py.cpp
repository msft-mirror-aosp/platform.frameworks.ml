// clang-format off
// Generated file (from: reshape_weights_as_inputs_relaxed.mod.py). Do not edit
#include "../../TestGenerated.h"

namespace reshape_weights_as_inputs_relaxed {
// Generated reshape_weights_as_inputs_relaxed test
#include "generated/examples/reshape_weights_as_inputs_relaxed.example.cpp"
// Generated model constructor
#include "generated/models/reshape_weights_as_inputs_relaxed.model.cpp"
} // namespace reshape_weights_as_inputs_relaxed

TEST_F(GeneratedTests, reshape_weights_as_inputs_relaxed) {
    execute(reshape_weights_as_inputs_relaxed::CreateModel,
            reshape_weights_as_inputs_relaxed::is_ignored,
            reshape_weights_as_inputs_relaxed::examples);
}

