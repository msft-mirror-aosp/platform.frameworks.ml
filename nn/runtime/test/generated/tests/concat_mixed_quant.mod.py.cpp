// clang-format off
// Generated file (from: concat_mixed_quant.mod.py). Do not edit
#include "../../TestGenerated.h"

namespace concat_mixed_quant {
// Generated concat_mixed_quant test
#include "generated/examples/concat_mixed_quant.example.cpp"
// Generated model constructor
#include "generated/models/concat_mixed_quant.model.cpp"
} // namespace concat_mixed_quant

TEST_F(GeneratedTests, concat_mixed_quant_quant8) {
    execute(concat_mixed_quant::CreateModel_quant8,
            concat_mixed_quant::is_ignored_quant8,
            concat_mixed_quant::examples_quant8);
}

TEST_F(GeneratedTests, concat_mixed_quant_quant8_2) {
    execute(concat_mixed_quant::CreateModel_quant8_2,
            concat_mixed_quant::is_ignored_quant8_2,
            concat_mixed_quant::examples_quant8_2);
}

