// clang-format off
// Generated file (from: depthwise_conv_relaxed.mod.py). Do not edit
#include "../../TestGenerated.h"

namespace depthwise_conv_relaxed {
// Generated depthwise_conv_relaxed test
#include "generated/examples/depthwise_conv_relaxed.example.cpp"
// Generated model constructor
#include "generated/models/depthwise_conv_relaxed.model.cpp"
} // namespace depthwise_conv_relaxed

TEST_F(GeneratedTests, depthwise_conv_relaxed) {
    execute(depthwise_conv_relaxed::CreateModel,
            depthwise_conv_relaxed::is_ignored,
            depthwise_conv_relaxed::examples);
}

