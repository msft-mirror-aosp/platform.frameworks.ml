// clang-format off
// Generated file (from: add_broadcast_quant8.mod.py). Do not edit
#include "../../TestGenerated.h"

namespace add_broadcast_quant8 {
// Generated add_broadcast_quant8 test
#include "generated/examples/add_broadcast_quant8.example.cpp"
// Generated model constructor
#include "generated/models/add_broadcast_quant8.model.cpp"
} // namespace add_broadcast_quant8

TEST_F(GeneratedTests, add_broadcast_quant8) {
    execute(add_broadcast_quant8::CreateModel,
            add_broadcast_quant8::is_ignored,
            add_broadcast_quant8::examples);
}

