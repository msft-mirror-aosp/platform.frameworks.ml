// clang-format off
// Generated file (from: strided_slice_float_5.mod.py). Do not edit
#include "../../TestGenerated.h"

namespace strided_slice_float_5 {
// Generated strided_slice_float_5 test
#include "generated/examples/strided_slice_float_5.example.cpp"
// Generated model constructor
#include "generated/models/strided_slice_float_5.model.cpp"
} // namespace strided_slice_float_5

TEST_F(GeneratedTests, strided_slice_float_5) {
    execute(strided_slice_float_5::CreateModel,
            strided_slice_float_5::is_ignored,
            strided_slice_float_5::examples);
}

