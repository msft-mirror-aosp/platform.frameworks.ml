// Generated from space_to_depth_float_3_relaxed.mod.py
// DO NOT EDIT
// clang-format off
#include "TestHarness.h"

namespace generated_tests::space_to_depth_float_3_relaxed {

std::vector<::test_helper::MixedTypedExample>& get_examples() {
static std::vector<::test_helper::MixedTypedExample> examples = {
// Begin of an example
{
.operands = {
//Input(s)
{ // See tools/test_generator/include/TestHarness.h:MixedTyped
  // int -> Dimensions map
  .operandDimensions = {{0, {1, 4, 4, 2}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {10.0f, 20.0f, 11.0f, 21.0f, 12.0f, 22.0f, 13.0f, 23.0f, 14.0f, 24.0f, 15.0f, 25.0f, 16.0f, 26.0f, 17.0f, 27.0f, 18.0f, 28.0f, 19.0f, 29.0f, 110.0f, 210.0f, 111.0f, 211.0f, 112.0f, 212.0f, 113.0f, 213.0f, 114.0f, 214.0f, 115.0f, 215.0f}}},
  // int -> INT32 map
  .int32Operands = {},
  // int -> QUANT8_ASYMM map
  .quant8AsymmOperands = {},
  // int -> QUANT16_SYMM map
  .quant16SymmOperands = {},
  // int -> FLOAT16 map
  .float16Operands = {},
  // int -> BOOL8 map
  .bool8Operands = {},
  // int -> QUANT8_SYMM_PER_CHANNEL map
  .quant8ChannelOperands = {},
  // int -> QUANT16_ASYMM map
  .quant16AsymmOperands = {},
  // int -> QUANT8_SYMM map
  .quant8SymmOperands = {},
},
//Output(s)
{ // See tools/test_generator/include/TestHarness.h:MixedTyped
  // int -> Dimensions map
  .operandDimensions = {{0, {1, 2, 2, 8}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {10.0f, 20.0f, 11.0f, 21.0f, 14.0f, 24.0f, 15.0f, 25.0f, 12.0f, 22.0f, 13.0f, 23.0f, 16.0f, 26.0f, 17.0f, 27.0f, 18.0f, 28.0f, 19.0f, 29.0f, 112.0f, 212.0f, 113.0f, 213.0f, 110.0f, 210.0f, 111.0f, 211.0f, 114.0f, 214.0f, 115.0f, 215.0f}}},
  // int -> INT32 map
  .int32Operands = {},
  // int -> QUANT8_ASYMM map
  .quant8AsymmOperands = {},
  // int -> QUANT16_SYMM map
  .quant16SymmOperands = {},
  // int -> FLOAT16 map
  .float16Operands = {},
  // int -> BOOL8 map
  .bool8Operands = {},
  // int -> QUANT8_SYMM_PER_CHANNEL map
  .quant8ChannelOperands = {},
  // int -> QUANT16_ASYMM map
  .quant16AsymmOperands = {},
  // int -> QUANT8_SYMM map
  .quant8SymmOperands = {},
}
},
}, // End of an example
};
return examples;
};

} // namespace generated_tests::space_to_depth_float_3_relaxed
namespace generated_tests::space_to_depth_float_3_relaxed {

std::vector<::test_helper::MixedTypedExample>& get_examples_dynamic_output_shape() {
static std::vector<::test_helper::MixedTypedExample> examples_dynamic_output_shape = {
// Begin of an example
{
.operands = {
//Input(s)
{ // See tools/test_generator/include/TestHarness.h:MixedTyped
  // int -> Dimensions map
  .operandDimensions = {{0, {1, 4, 4, 2}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {10.0f, 20.0f, 11.0f, 21.0f, 12.0f, 22.0f, 13.0f, 23.0f, 14.0f, 24.0f, 15.0f, 25.0f, 16.0f, 26.0f, 17.0f, 27.0f, 18.0f, 28.0f, 19.0f, 29.0f, 110.0f, 210.0f, 111.0f, 211.0f, 112.0f, 212.0f, 113.0f, 213.0f, 114.0f, 214.0f, 115.0f, 215.0f}}},
  // int -> INT32 map
  .int32Operands = {},
  // int -> QUANT8_ASYMM map
  .quant8AsymmOperands = {},
  // int -> QUANT16_SYMM map
  .quant16SymmOperands = {},
  // int -> FLOAT16 map
  .float16Operands = {},
  // int -> BOOL8 map
  .bool8Operands = {},
  // int -> QUANT8_SYMM_PER_CHANNEL map
  .quant8ChannelOperands = {},
  // int -> QUANT16_ASYMM map
  .quant16AsymmOperands = {},
  // int -> QUANT8_SYMM map
  .quant8SymmOperands = {},
},
//Output(s)
{ // See tools/test_generator/include/TestHarness.h:MixedTyped
  // int -> Dimensions map
  .operandDimensions = {{0, {1, 2, 2, 8}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {10.0f, 20.0f, 11.0f, 21.0f, 14.0f, 24.0f, 15.0f, 25.0f, 12.0f, 22.0f, 13.0f, 23.0f, 16.0f, 26.0f, 17.0f, 27.0f, 18.0f, 28.0f, 19.0f, 29.0f, 112.0f, 212.0f, 113.0f, 213.0f, 110.0f, 210.0f, 111.0f, 211.0f, 114.0f, 214.0f, 115.0f, 215.0f}}},
  // int -> INT32 map
  .int32Operands = {},
  // int -> QUANT8_ASYMM map
  .quant8AsymmOperands = {},
  // int -> QUANT16_SYMM map
  .quant16SymmOperands = {},
  // int -> FLOAT16 map
  .float16Operands = {},
  // int -> BOOL8 map
  .bool8Operands = {},
  // int -> QUANT8_SYMM_PER_CHANNEL map
  .quant8ChannelOperands = {},
  // int -> QUANT16_ASYMM map
  .quant16AsymmOperands = {},
  // int -> QUANT8_SYMM map
  .quant8SymmOperands = {},
}
},
}, // End of an example
};
return examples_dynamic_output_shape;
};

} // namespace generated_tests::space_to_depth_float_3_relaxed