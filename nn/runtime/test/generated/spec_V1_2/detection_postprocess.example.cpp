// Generated from detection_postprocess.mod.py
// DO NOT EDIT
// clang-format off
#include "TestHarness.h"

namespace generated_tests::detection_postprocess {

std::vector<::test_helper::MixedTypedExample>& get_examples_regular() {
static std::vector<::test_helper::MixedTypedExample> examples_regular = {
// Begin of an example
{
.operands = {
//Input(s)
{ // See tools/test_generator/include/TestHarness.h:MixedTyped
  // int -> Dimensions map
  .operandDimensions = {{0, {1, 6, 3}}, {1, {1, 6, 4}}, {2, {6, 4}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {0.0f, 0.9f, 0.8f, 0.0f, 0.75f, 0.72f, 0.0f, 0.6f, 0.5f, 0.0f, 0.93f, 0.95f, 0.0f, 0.5f, 0.4f, 0.0f, 0.3f, 0.2f}}, {1, {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f}}, {2, {0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 100.5f, 1.0f, 1.0f}}},
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
  .operandDimensions = {{0, {1, 3}}, {1, {1, 3, 4}}, {2, {1, 3}}, {3, {1}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {0.95f, 0.93f, 0.0f}}, {1, {0.0f, 10.0f, 1.0f, 11.0f, 0.0f, 10.0f, 1.0f, 11.0f, 0.0f, 0.0f, 0.0f, 0.0f}}},
  // int -> INT32 map
  .int32Operands = {{2, {1, 0, 0}}, {3, {2}}},
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
return examples_regular;
};

} // namespace generated_tests::detection_postprocess
namespace generated_tests::detection_postprocess {

std::vector<::test_helper::MixedTypedExample>& get_examples_regular_dynamic_output_shape() {
static std::vector<::test_helper::MixedTypedExample> examples_regular_dynamic_output_shape = {
// Begin of an example
{
.operands = {
//Input(s)
{ // See tools/test_generator/include/TestHarness.h:MixedTyped
  // int -> Dimensions map
  .operandDimensions = {{0, {1, 6, 3}}, {1, {1, 6, 4}}, {2, {6, 4}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {0.0f, 0.9f, 0.8f, 0.0f, 0.75f, 0.72f, 0.0f, 0.6f, 0.5f, 0.0f, 0.93f, 0.95f, 0.0f, 0.5f, 0.4f, 0.0f, 0.3f, 0.2f}}, {1, {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f}}, {2, {0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 100.5f, 1.0f, 1.0f}}},
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
  .operandDimensions = {{0, {1, 3}}, {1, {1, 3, 4}}, {2, {1, 3}}, {3, {1}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {0.95f, 0.93f, 0.0f}}, {1, {0.0f, 10.0f, 1.0f, 11.0f, 0.0f, 10.0f, 1.0f, 11.0f, 0.0f, 0.0f, 0.0f, 0.0f}}},
  // int -> INT32 map
  .int32Operands = {{2, {1, 0, 0}}, {3, {2}}},
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
return examples_regular_dynamic_output_shape;
};

} // namespace generated_tests::detection_postprocess
namespace generated_tests::detection_postprocess {

std::vector<::test_helper::MixedTypedExample>& get_examples_regular_all_inputs_as_internal() {
static std::vector<::test_helper::MixedTypedExample> examples_regular_all_inputs_as_internal = {
// Begin of an example
{
.operands = {
//Input(s)
{ // See tools/test_generator/include/TestHarness.h:MixedTyped
  // int -> Dimensions map
  .operandDimensions = {{0, {1, 6, 3}}, {1, {1, 6, 4}}, {2, {6, 4}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {0.0f, 0.9f, 0.8f, 0.0f, 0.75f, 0.72f, 0.0f, 0.6f, 0.5f, 0.0f, 0.93f, 0.95f, 0.0f, 0.5f, 0.4f, 0.0f, 0.3f, 0.2f}}, {1, {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f}}, {2, {0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 100.5f, 1.0f, 1.0f}}},
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
  .operandDimensions = {{0, {1, 3}}, {1, {1, 3, 4}}, {2, {1, 3}}, {3, {1}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {0.95f, 0.93f, 0.0f}}, {1, {0.0f, 10.0f, 1.0f, 11.0f, 0.0f, 10.0f, 1.0f, 11.0f, 0.0f, 0.0f, 0.0f, 0.0f}}},
  // int -> INT32 map
  .int32Operands = {{2, {1, 0, 0}}, {3, {2}}},
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
return examples_regular_all_inputs_as_internal;
};

} // namespace generated_tests::detection_postprocess
namespace generated_tests::detection_postprocess {

std::vector<::test_helper::MixedTypedExample>& get_examples_regular_all_inputs_as_internal_dynamic_output_shape() {
static std::vector<::test_helper::MixedTypedExample> examples_regular_all_inputs_as_internal_dynamic_output_shape = {
// Begin of an example
{
.operands = {
//Input(s)
{ // See tools/test_generator/include/TestHarness.h:MixedTyped
  // int -> Dimensions map
  .operandDimensions = {{0, {1, 6, 3}}, {1, {1, 6, 4}}, {2, {6, 4}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {0.0f, 0.9f, 0.8f, 0.0f, 0.75f, 0.72f, 0.0f, 0.6f, 0.5f, 0.0f, 0.93f, 0.95f, 0.0f, 0.5f, 0.4f, 0.0f, 0.3f, 0.2f}}, {1, {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f}}, {2, {0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 100.5f, 1.0f, 1.0f}}},
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
  .operandDimensions = {{0, {1, 3}}, {1, {1, 3, 4}}, {2, {1, 3}}, {3, {1}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {0.95f, 0.93f, 0.0f}}, {1, {0.0f, 10.0f, 1.0f, 11.0f, 0.0f, 10.0f, 1.0f, 11.0f, 0.0f, 0.0f, 0.0f, 0.0f}}},
  // int -> INT32 map
  .int32Operands = {{2, {1, 0, 0}}, {3, {2}}},
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
return examples_regular_all_inputs_as_internal_dynamic_output_shape;
};

} // namespace generated_tests::detection_postprocess
namespace generated_tests::detection_postprocess {

std::vector<::test_helper::MixedTypedExample>& get_examples_regular_relaxed() {
static std::vector<::test_helper::MixedTypedExample> examples_regular_relaxed = {
// Begin of an example
{
.operands = {
//Input(s)
{ // See tools/test_generator/include/TestHarness.h:MixedTyped
  // int -> Dimensions map
  .operandDimensions = {{0, {1, 6, 3}}, {1, {1, 6, 4}}, {2, {6, 4}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {0.0f, 0.9f, 0.8f, 0.0f, 0.75f, 0.72f, 0.0f, 0.6f, 0.5f, 0.0f, 0.93f, 0.95f, 0.0f, 0.5f, 0.4f, 0.0f, 0.3f, 0.2f}}, {1, {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f}}, {2, {0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 100.5f, 1.0f, 1.0f}}},
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
  .operandDimensions = {{0, {1, 3}}, {1, {1, 3, 4}}, {2, {1, 3}}, {3, {1}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {0.95f, 0.93f, 0.0f}}, {1, {0.0f, 10.0f, 1.0f, 11.0f, 0.0f, 10.0f, 1.0f, 11.0f, 0.0f, 0.0f, 0.0f, 0.0f}}},
  // int -> INT32 map
  .int32Operands = {{2, {1, 0, 0}}, {3, {2}}},
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
return examples_regular_relaxed;
};

} // namespace generated_tests::detection_postprocess
namespace generated_tests::detection_postprocess {

std::vector<::test_helper::MixedTypedExample>& get_examples_regular_relaxed_dynamic_output_shape() {
static std::vector<::test_helper::MixedTypedExample> examples_regular_relaxed_dynamic_output_shape = {
// Begin of an example
{
.operands = {
//Input(s)
{ // See tools/test_generator/include/TestHarness.h:MixedTyped
  // int -> Dimensions map
  .operandDimensions = {{0, {1, 6, 3}}, {1, {1, 6, 4}}, {2, {6, 4}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {0.0f, 0.9f, 0.8f, 0.0f, 0.75f, 0.72f, 0.0f, 0.6f, 0.5f, 0.0f, 0.93f, 0.95f, 0.0f, 0.5f, 0.4f, 0.0f, 0.3f, 0.2f}}, {1, {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f}}, {2, {0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 100.5f, 1.0f, 1.0f}}},
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
  .operandDimensions = {{0, {1, 3}}, {1, {1, 3, 4}}, {2, {1, 3}}, {3, {1}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {0.95f, 0.93f, 0.0f}}, {1, {0.0f, 10.0f, 1.0f, 11.0f, 0.0f, 10.0f, 1.0f, 11.0f, 0.0f, 0.0f, 0.0f, 0.0f}}},
  // int -> INT32 map
  .int32Operands = {{2, {1, 0, 0}}, {3, {2}}},
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
return examples_regular_relaxed_dynamic_output_shape;
};

} // namespace generated_tests::detection_postprocess
namespace generated_tests::detection_postprocess {

std::vector<::test_helper::MixedTypedExample>& get_examples_regular_relaxed_all_inputs_as_internal() {
static std::vector<::test_helper::MixedTypedExample> examples_regular_relaxed_all_inputs_as_internal = {
// Begin of an example
{
.operands = {
//Input(s)
{ // See tools/test_generator/include/TestHarness.h:MixedTyped
  // int -> Dimensions map
  .operandDimensions = {{0, {1, 6, 3}}, {1, {1, 6, 4}}, {2, {6, 4}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {0.0f, 0.9f, 0.8f, 0.0f, 0.75f, 0.72f, 0.0f, 0.6f, 0.5f, 0.0f, 0.93f, 0.95f, 0.0f, 0.5f, 0.4f, 0.0f, 0.3f, 0.2f}}, {1, {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f}}, {2, {0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 100.5f, 1.0f, 1.0f}}},
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
  .operandDimensions = {{0, {1, 3}}, {1, {1, 3, 4}}, {2, {1, 3}}, {3, {1}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {0.95f, 0.93f, 0.0f}}, {1, {0.0f, 10.0f, 1.0f, 11.0f, 0.0f, 10.0f, 1.0f, 11.0f, 0.0f, 0.0f, 0.0f, 0.0f}}},
  // int -> INT32 map
  .int32Operands = {{2, {1, 0, 0}}, {3, {2}}},
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
return examples_regular_relaxed_all_inputs_as_internal;
};

} // namespace generated_tests::detection_postprocess
namespace generated_tests::detection_postprocess {

std::vector<::test_helper::MixedTypedExample>& get_examples_regular_relaxed_all_inputs_as_internal_dynamic_output_shape() {
static std::vector<::test_helper::MixedTypedExample> examples_regular_relaxed_all_inputs_as_internal_dynamic_output_shape = {
// Begin of an example
{
.operands = {
//Input(s)
{ // See tools/test_generator/include/TestHarness.h:MixedTyped
  // int -> Dimensions map
  .operandDimensions = {{0, {1, 6, 3}}, {1, {1, 6, 4}}, {2, {6, 4}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {0.0f, 0.9f, 0.8f, 0.0f, 0.75f, 0.72f, 0.0f, 0.6f, 0.5f, 0.0f, 0.93f, 0.95f, 0.0f, 0.5f, 0.4f, 0.0f, 0.3f, 0.2f}}, {1, {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f}}, {2, {0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 100.5f, 1.0f, 1.0f}}},
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
  .operandDimensions = {{0, {1, 3}}, {1, {1, 3, 4}}, {2, {1, 3}}, {3, {1}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {0.95f, 0.93f, 0.0f}}, {1, {0.0f, 10.0f, 1.0f, 11.0f, 0.0f, 10.0f, 1.0f, 11.0f, 0.0f, 0.0f, 0.0f, 0.0f}}},
  // int -> INT32 map
  .int32Operands = {{2, {1, 0, 0}}, {3, {2}}},
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
return examples_regular_relaxed_all_inputs_as_internal_dynamic_output_shape;
};

} // namespace generated_tests::detection_postprocess
namespace generated_tests::detection_postprocess {

std::vector<::test_helper::MixedTypedExample>& get_examples_regular_float16() {
static std::vector<::test_helper::MixedTypedExample> examples_regular_float16 = {
// Begin of an example
{
.operands = {
//Input(s)
{ // See tools/test_generator/include/TestHarness.h:MixedTyped
  // int -> Dimensions map
  .operandDimensions = {{0, {1, 6, 3}}, {1, {1, 6, 4}}, {2, {6, 4}}},
  // int -> FLOAT32 map
  .float32Operands = {},
  // int -> INT32 map
  .int32Operands = {},
  // int -> QUANT8_ASYMM map
  .quant8AsymmOperands = {},
  // int -> QUANT16_SYMM map
  .quant16SymmOperands = {},
  // int -> FLOAT16 map
  .float16Operands = {{0, {0.0f, 0.8999999761581421f, 0.800000011920929f, 0.0f, 0.75f, 0.7200000286102295f, 0.0f, 0.6000000238418579f, 0.5f, 0.0f, 0.9300000071525574f, 0.949999988079071f, 0.0f, 0.5f, 0.4000000059604645f, 0.0f, 0.30000001192092896f, 0.20000000298023224f}}, {1, {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f}}, {2, {0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 100.5f, 1.0f, 1.0f}}},
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
  .operandDimensions = {{0, {1, 3}}, {1, {1, 3, 4}}, {2, {1, 3}}, {3, {1}}},
  // int -> FLOAT32 map
  .float32Operands = {},
  // int -> INT32 map
  .int32Operands = {{2, {1, 0, 0}}, {3, {2}}},
  // int -> QUANT8_ASYMM map
  .quant8AsymmOperands = {},
  // int -> QUANT16_SYMM map
  .quant16SymmOperands = {},
  // int -> FLOAT16 map
  .float16Operands = {{0, {0.949999988079071f, 0.9300000071525574f, 0.0f}}, {1, {0.0f, 10.0f, 1.0f, 11.0f, 0.0f, 10.0f, 1.0f, 11.0f, 0.0f, 0.0f, 0.0f, 0.0f}}},
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
return examples_regular_float16;
};

} // namespace generated_tests::detection_postprocess
namespace generated_tests::detection_postprocess {

std::vector<::test_helper::MixedTypedExample>& get_examples_regular_float16_dynamic_output_shape() {
static std::vector<::test_helper::MixedTypedExample> examples_regular_float16_dynamic_output_shape = {
// Begin of an example
{
.operands = {
//Input(s)
{ // See tools/test_generator/include/TestHarness.h:MixedTyped
  // int -> Dimensions map
  .operandDimensions = {{0, {1, 6, 3}}, {1, {1, 6, 4}}, {2, {6, 4}}},
  // int -> FLOAT32 map
  .float32Operands = {},
  // int -> INT32 map
  .int32Operands = {},
  // int -> QUANT8_ASYMM map
  .quant8AsymmOperands = {},
  // int -> QUANT16_SYMM map
  .quant16SymmOperands = {},
  // int -> FLOAT16 map
  .float16Operands = {{0, {0.0f, 0.8999999761581421f, 0.800000011920929f, 0.0f, 0.75f, 0.7200000286102295f, 0.0f, 0.6000000238418579f, 0.5f, 0.0f, 0.9300000071525574f, 0.949999988079071f, 0.0f, 0.5f, 0.4000000059604645f, 0.0f, 0.30000001192092896f, 0.20000000298023224f}}, {1, {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f}}, {2, {0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 100.5f, 1.0f, 1.0f}}},
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
  .operandDimensions = {{0, {1, 3}}, {1, {1, 3, 4}}, {2, {1, 3}}, {3, {1}}},
  // int -> FLOAT32 map
  .float32Operands = {},
  // int -> INT32 map
  .int32Operands = {{2, {1, 0, 0}}, {3, {2}}},
  // int -> QUANT8_ASYMM map
  .quant8AsymmOperands = {},
  // int -> QUANT16_SYMM map
  .quant16SymmOperands = {},
  // int -> FLOAT16 map
  .float16Operands = {{0, {0.949999988079071f, 0.9300000071525574f, 0.0f}}, {1, {0.0f, 10.0f, 1.0f, 11.0f, 0.0f, 10.0f, 1.0f, 11.0f, 0.0f, 0.0f, 0.0f, 0.0f}}},
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
return examples_regular_float16_dynamic_output_shape;
};

} // namespace generated_tests::detection_postprocess
namespace generated_tests::detection_postprocess {

std::vector<::test_helper::MixedTypedExample>& get_examples_regular_float16_all_inputs_as_internal() {
static std::vector<::test_helper::MixedTypedExample> examples_regular_float16_all_inputs_as_internal = {
// Begin of an example
{
.operands = {
//Input(s)
{ // See tools/test_generator/include/TestHarness.h:MixedTyped
  // int -> Dimensions map
  .operandDimensions = {{0, {1, 6, 3}}, {1, {1, 6, 4}}, {2, {6, 4}}},
  // int -> FLOAT32 map
  .float32Operands = {},
  // int -> INT32 map
  .int32Operands = {},
  // int -> QUANT8_ASYMM map
  .quant8AsymmOperands = {},
  // int -> QUANT16_SYMM map
  .quant16SymmOperands = {},
  // int -> FLOAT16 map
  .float16Operands = {{0, {0.0f, 0.8999999761581421f, 0.800000011920929f, 0.0f, 0.75f, 0.7200000286102295f, 0.0f, 0.6000000238418579f, 0.5f, 0.0f, 0.9300000071525574f, 0.949999988079071f, 0.0f, 0.5f, 0.4000000059604645f, 0.0f, 0.30000001192092896f, 0.20000000298023224f}}, {1, {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f}}, {2, {0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 100.5f, 1.0f, 1.0f}}},
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
  .operandDimensions = {{0, {1, 3}}, {1, {1, 3, 4}}, {2, {1, 3}}, {3, {1}}},
  // int -> FLOAT32 map
  .float32Operands = {},
  // int -> INT32 map
  .int32Operands = {{2, {1, 0, 0}}, {3, {2}}},
  // int -> QUANT8_ASYMM map
  .quant8AsymmOperands = {},
  // int -> QUANT16_SYMM map
  .quant16SymmOperands = {},
  // int -> FLOAT16 map
  .float16Operands = {{0, {0.949999988079071f, 0.9300000071525574f, 0.0f}}, {1, {0.0f, 10.0f, 1.0f, 11.0f, 0.0f, 10.0f, 1.0f, 11.0f, 0.0f, 0.0f, 0.0f, 0.0f}}},
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
return examples_regular_float16_all_inputs_as_internal;
};

} // namespace generated_tests::detection_postprocess
namespace generated_tests::detection_postprocess {

std::vector<::test_helper::MixedTypedExample>& get_examples_regular_float16_all_inputs_as_internal_dynamic_output_shape() {
static std::vector<::test_helper::MixedTypedExample> examples_regular_float16_all_inputs_as_internal_dynamic_output_shape = {
// Begin of an example
{
.operands = {
//Input(s)
{ // See tools/test_generator/include/TestHarness.h:MixedTyped
  // int -> Dimensions map
  .operandDimensions = {{0, {1, 6, 3}}, {1, {1, 6, 4}}, {2, {6, 4}}},
  // int -> FLOAT32 map
  .float32Operands = {},
  // int -> INT32 map
  .int32Operands = {},
  // int -> QUANT8_ASYMM map
  .quant8AsymmOperands = {},
  // int -> QUANT16_SYMM map
  .quant16SymmOperands = {},
  // int -> FLOAT16 map
  .float16Operands = {{0, {0.0f, 0.8999999761581421f, 0.800000011920929f, 0.0f, 0.75f, 0.7200000286102295f, 0.0f, 0.6000000238418579f, 0.5f, 0.0f, 0.9300000071525574f, 0.949999988079071f, 0.0f, 0.5f, 0.4000000059604645f, 0.0f, 0.30000001192092896f, 0.20000000298023224f}}, {1, {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f}}, {2, {0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 100.5f, 1.0f, 1.0f}}},
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
  .operandDimensions = {{0, {1, 3}}, {1, {1, 3, 4}}, {2, {1, 3}}, {3, {1}}},
  // int -> FLOAT32 map
  .float32Operands = {},
  // int -> INT32 map
  .int32Operands = {{2, {1, 0, 0}}, {3, {2}}},
  // int -> QUANT8_ASYMM map
  .quant8AsymmOperands = {},
  // int -> QUANT16_SYMM map
  .quant16SymmOperands = {},
  // int -> FLOAT16 map
  .float16Operands = {{0, {0.949999988079071f, 0.9300000071525574f, 0.0f}}, {1, {0.0f, 10.0f, 1.0f, 11.0f, 0.0f, 10.0f, 1.0f, 11.0f, 0.0f, 0.0f, 0.0f, 0.0f}}},
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
return examples_regular_float16_all_inputs_as_internal_dynamic_output_shape;
};

} // namespace generated_tests::detection_postprocess
namespace generated_tests::detection_postprocess {

std::vector<::test_helper::MixedTypedExample>& get_examples() {
static std::vector<::test_helper::MixedTypedExample> examples = {
// Begin of an example
{
.operands = {
//Input(s)
{ // See tools/test_generator/include/TestHarness.h:MixedTyped
  // int -> Dimensions map
  .operandDimensions = {{0, {1, 6, 3}}, {1, {1, 6, 4}}, {2, {6, 4}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {0.0f, 0.9f, 0.8f, 0.0f, 0.75f, 0.72f, 0.0f, 0.6f, 0.5f, 0.0f, 0.93f, 0.95f, 0.0f, 0.5f, 0.4f, 0.0f, 0.3f, 0.2f}}, {1, {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f}}, {2, {0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 100.5f, 1.0f, 1.0f}}},
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
  .operandDimensions = {{0, {1, 3}}, {1, {1, 3, 4}}, {2, {1, 3}}, {3, {1}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {0.95f, 0.9f, 0.3f}}, {1, {0.0f, 10.0f, 1.0f, 11.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 100.0f, 1.0f, 101.0f}}},
  // int -> INT32 map
  .int32Operands = {{2, {1, 0, 0}}, {3, {3}}},
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

} // namespace generated_tests::detection_postprocess
namespace generated_tests::detection_postprocess {

std::vector<::test_helper::MixedTypedExample>& get_examples_dynamic_output_shape() {
static std::vector<::test_helper::MixedTypedExample> examples_dynamic_output_shape = {
// Begin of an example
{
.operands = {
//Input(s)
{ // See tools/test_generator/include/TestHarness.h:MixedTyped
  // int -> Dimensions map
  .operandDimensions = {{0, {1, 6, 3}}, {1, {1, 6, 4}}, {2, {6, 4}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {0.0f, 0.9f, 0.8f, 0.0f, 0.75f, 0.72f, 0.0f, 0.6f, 0.5f, 0.0f, 0.93f, 0.95f, 0.0f, 0.5f, 0.4f, 0.0f, 0.3f, 0.2f}}, {1, {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f}}, {2, {0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 100.5f, 1.0f, 1.0f}}},
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
  .operandDimensions = {{0, {1, 3}}, {1, {1, 3, 4}}, {2, {1, 3}}, {3, {1}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {0.95f, 0.9f, 0.3f}}, {1, {0.0f, 10.0f, 1.0f, 11.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 100.0f, 1.0f, 101.0f}}},
  // int -> INT32 map
  .int32Operands = {{2, {1, 0, 0}}, {3, {3}}},
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

} // namespace generated_tests::detection_postprocess
namespace generated_tests::detection_postprocess {

std::vector<::test_helper::MixedTypedExample>& get_examples_all_inputs_as_internal() {
static std::vector<::test_helper::MixedTypedExample> examples_all_inputs_as_internal = {
// Begin of an example
{
.operands = {
//Input(s)
{ // See tools/test_generator/include/TestHarness.h:MixedTyped
  // int -> Dimensions map
  .operandDimensions = {{0, {1, 6, 3}}, {1, {1, 6, 4}}, {2, {6, 4}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {0.0f, 0.9f, 0.8f, 0.0f, 0.75f, 0.72f, 0.0f, 0.6f, 0.5f, 0.0f, 0.93f, 0.95f, 0.0f, 0.5f, 0.4f, 0.0f, 0.3f, 0.2f}}, {1, {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f}}, {2, {0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 100.5f, 1.0f, 1.0f}}},
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
  .operandDimensions = {{0, {1, 3}}, {1, {1, 3, 4}}, {2, {1, 3}}, {3, {1}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {0.95f, 0.9f, 0.3f}}, {1, {0.0f, 10.0f, 1.0f, 11.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 100.0f, 1.0f, 101.0f}}},
  // int -> INT32 map
  .int32Operands = {{2, {1, 0, 0}}, {3, {3}}},
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
return examples_all_inputs_as_internal;
};

} // namespace generated_tests::detection_postprocess
namespace generated_tests::detection_postprocess {

std::vector<::test_helper::MixedTypedExample>& get_examples_all_inputs_as_internal_dynamic_output_shape() {
static std::vector<::test_helper::MixedTypedExample> examples_all_inputs_as_internal_dynamic_output_shape = {
// Begin of an example
{
.operands = {
//Input(s)
{ // See tools/test_generator/include/TestHarness.h:MixedTyped
  // int -> Dimensions map
  .operandDimensions = {{0, {1, 6, 3}}, {1, {1, 6, 4}}, {2, {6, 4}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {0.0f, 0.9f, 0.8f, 0.0f, 0.75f, 0.72f, 0.0f, 0.6f, 0.5f, 0.0f, 0.93f, 0.95f, 0.0f, 0.5f, 0.4f, 0.0f, 0.3f, 0.2f}}, {1, {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f}}, {2, {0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 100.5f, 1.0f, 1.0f}}},
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
  .operandDimensions = {{0, {1, 3}}, {1, {1, 3, 4}}, {2, {1, 3}}, {3, {1}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {0.95f, 0.9f, 0.3f}}, {1, {0.0f, 10.0f, 1.0f, 11.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 100.0f, 1.0f, 101.0f}}},
  // int -> INT32 map
  .int32Operands = {{2, {1, 0, 0}}, {3, {3}}},
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
return examples_all_inputs_as_internal_dynamic_output_shape;
};

} // namespace generated_tests::detection_postprocess
namespace generated_tests::detection_postprocess {

std::vector<::test_helper::MixedTypedExample>& get_examples_relaxed() {
static std::vector<::test_helper::MixedTypedExample> examples_relaxed = {
// Begin of an example
{
.operands = {
//Input(s)
{ // See tools/test_generator/include/TestHarness.h:MixedTyped
  // int -> Dimensions map
  .operandDimensions = {{0, {1, 6, 3}}, {1, {1, 6, 4}}, {2, {6, 4}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {0.0f, 0.9f, 0.8f, 0.0f, 0.75f, 0.72f, 0.0f, 0.6f, 0.5f, 0.0f, 0.93f, 0.95f, 0.0f, 0.5f, 0.4f, 0.0f, 0.3f, 0.2f}}, {1, {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f}}, {2, {0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 100.5f, 1.0f, 1.0f}}},
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
  .operandDimensions = {{0, {1, 3}}, {1, {1, 3, 4}}, {2, {1, 3}}, {3, {1}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {0.95f, 0.9f, 0.3f}}, {1, {0.0f, 10.0f, 1.0f, 11.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 100.0f, 1.0f, 101.0f}}},
  // int -> INT32 map
  .int32Operands = {{2, {1, 0, 0}}, {3, {3}}},
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
return examples_relaxed;
};

} // namespace generated_tests::detection_postprocess
namespace generated_tests::detection_postprocess {

std::vector<::test_helper::MixedTypedExample>& get_examples_relaxed_dynamic_output_shape() {
static std::vector<::test_helper::MixedTypedExample> examples_relaxed_dynamic_output_shape = {
// Begin of an example
{
.operands = {
//Input(s)
{ // See tools/test_generator/include/TestHarness.h:MixedTyped
  // int -> Dimensions map
  .operandDimensions = {{0, {1, 6, 3}}, {1, {1, 6, 4}}, {2, {6, 4}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {0.0f, 0.9f, 0.8f, 0.0f, 0.75f, 0.72f, 0.0f, 0.6f, 0.5f, 0.0f, 0.93f, 0.95f, 0.0f, 0.5f, 0.4f, 0.0f, 0.3f, 0.2f}}, {1, {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f}}, {2, {0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 100.5f, 1.0f, 1.0f}}},
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
  .operandDimensions = {{0, {1, 3}}, {1, {1, 3, 4}}, {2, {1, 3}}, {3, {1}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {0.95f, 0.9f, 0.3f}}, {1, {0.0f, 10.0f, 1.0f, 11.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 100.0f, 1.0f, 101.0f}}},
  // int -> INT32 map
  .int32Operands = {{2, {1, 0, 0}}, {3, {3}}},
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
return examples_relaxed_dynamic_output_shape;
};

} // namespace generated_tests::detection_postprocess
namespace generated_tests::detection_postprocess {

std::vector<::test_helper::MixedTypedExample>& get_examples_relaxed_all_inputs_as_internal() {
static std::vector<::test_helper::MixedTypedExample> examples_relaxed_all_inputs_as_internal = {
// Begin of an example
{
.operands = {
//Input(s)
{ // See tools/test_generator/include/TestHarness.h:MixedTyped
  // int -> Dimensions map
  .operandDimensions = {{0, {1, 6, 3}}, {1, {1, 6, 4}}, {2, {6, 4}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {0.0f, 0.9f, 0.8f, 0.0f, 0.75f, 0.72f, 0.0f, 0.6f, 0.5f, 0.0f, 0.93f, 0.95f, 0.0f, 0.5f, 0.4f, 0.0f, 0.3f, 0.2f}}, {1, {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f}}, {2, {0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 100.5f, 1.0f, 1.0f}}},
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
  .operandDimensions = {{0, {1, 3}}, {1, {1, 3, 4}}, {2, {1, 3}}, {3, {1}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {0.95f, 0.9f, 0.3f}}, {1, {0.0f, 10.0f, 1.0f, 11.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 100.0f, 1.0f, 101.0f}}},
  // int -> INT32 map
  .int32Operands = {{2, {1, 0, 0}}, {3, {3}}},
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
return examples_relaxed_all_inputs_as_internal;
};

} // namespace generated_tests::detection_postprocess
namespace generated_tests::detection_postprocess {

std::vector<::test_helper::MixedTypedExample>& get_examples_relaxed_all_inputs_as_internal_dynamic_output_shape() {
static std::vector<::test_helper::MixedTypedExample> examples_relaxed_all_inputs_as_internal_dynamic_output_shape = {
// Begin of an example
{
.operands = {
//Input(s)
{ // See tools/test_generator/include/TestHarness.h:MixedTyped
  // int -> Dimensions map
  .operandDimensions = {{0, {1, 6, 3}}, {1, {1, 6, 4}}, {2, {6, 4}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {0.0f, 0.9f, 0.8f, 0.0f, 0.75f, 0.72f, 0.0f, 0.6f, 0.5f, 0.0f, 0.93f, 0.95f, 0.0f, 0.5f, 0.4f, 0.0f, 0.3f, 0.2f}}, {1, {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f}}, {2, {0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 100.5f, 1.0f, 1.0f}}},
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
  .operandDimensions = {{0, {1, 3}}, {1, {1, 3, 4}}, {2, {1, 3}}, {3, {1}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {0.95f, 0.9f, 0.3f}}, {1, {0.0f, 10.0f, 1.0f, 11.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 100.0f, 1.0f, 101.0f}}},
  // int -> INT32 map
  .int32Operands = {{2, {1, 0, 0}}, {3, {3}}},
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
return examples_relaxed_all_inputs_as_internal_dynamic_output_shape;
};

} // namespace generated_tests::detection_postprocess
namespace generated_tests::detection_postprocess {

std::vector<::test_helper::MixedTypedExample>& get_examples_float16() {
static std::vector<::test_helper::MixedTypedExample> examples_float16 = {
// Begin of an example
{
.operands = {
//Input(s)
{ // See tools/test_generator/include/TestHarness.h:MixedTyped
  // int -> Dimensions map
  .operandDimensions = {{0, {1, 6, 3}}, {1, {1, 6, 4}}, {2, {6, 4}}},
  // int -> FLOAT32 map
  .float32Operands = {},
  // int -> INT32 map
  .int32Operands = {},
  // int -> QUANT8_ASYMM map
  .quant8AsymmOperands = {},
  // int -> QUANT16_SYMM map
  .quant16SymmOperands = {},
  // int -> FLOAT16 map
  .float16Operands = {{0, {0.0f, 0.8999999761581421f, 0.800000011920929f, 0.0f, 0.75f, 0.7200000286102295f, 0.0f, 0.6000000238418579f, 0.5f, 0.0f, 0.9300000071525574f, 0.949999988079071f, 0.0f, 0.5f, 0.4000000059604645f, 0.0f, 0.30000001192092896f, 0.20000000298023224f}}, {1, {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f}}, {2, {0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 100.5f, 1.0f, 1.0f}}},
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
  .operandDimensions = {{0, {1, 3}}, {1, {1, 3, 4}}, {2, {1, 3}}, {3, {1}}},
  // int -> FLOAT32 map
  .float32Operands = {},
  // int -> INT32 map
  .int32Operands = {{2, {1, 0, 0}}, {3, {3}}},
  // int -> QUANT8_ASYMM map
  .quant8AsymmOperands = {},
  // int -> QUANT16_SYMM map
  .quant16SymmOperands = {},
  // int -> FLOAT16 map
  .float16Operands = {{0, {0.949999988079071f, 0.8999999761581421f, 0.30000001192092896f}}, {1, {0.0f, 10.0f, 1.0f, 11.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 100.0f, 1.0f, 101.0f}}},
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
return examples_float16;
};

} // namespace generated_tests::detection_postprocess
namespace generated_tests::detection_postprocess {

std::vector<::test_helper::MixedTypedExample>& get_examples_float16_dynamic_output_shape() {
static std::vector<::test_helper::MixedTypedExample> examples_float16_dynamic_output_shape = {
// Begin of an example
{
.operands = {
//Input(s)
{ // See tools/test_generator/include/TestHarness.h:MixedTyped
  // int -> Dimensions map
  .operandDimensions = {{0, {1, 6, 3}}, {1, {1, 6, 4}}, {2, {6, 4}}},
  // int -> FLOAT32 map
  .float32Operands = {},
  // int -> INT32 map
  .int32Operands = {},
  // int -> QUANT8_ASYMM map
  .quant8AsymmOperands = {},
  // int -> QUANT16_SYMM map
  .quant16SymmOperands = {},
  // int -> FLOAT16 map
  .float16Operands = {{0, {0.0f, 0.8999999761581421f, 0.800000011920929f, 0.0f, 0.75f, 0.7200000286102295f, 0.0f, 0.6000000238418579f, 0.5f, 0.0f, 0.9300000071525574f, 0.949999988079071f, 0.0f, 0.5f, 0.4000000059604645f, 0.0f, 0.30000001192092896f, 0.20000000298023224f}}, {1, {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f}}, {2, {0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 100.5f, 1.0f, 1.0f}}},
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
  .operandDimensions = {{0, {1, 3}}, {1, {1, 3, 4}}, {2, {1, 3}}, {3, {1}}},
  // int -> FLOAT32 map
  .float32Operands = {},
  // int -> INT32 map
  .int32Operands = {{2, {1, 0, 0}}, {3, {3}}},
  // int -> QUANT8_ASYMM map
  .quant8AsymmOperands = {},
  // int -> QUANT16_SYMM map
  .quant16SymmOperands = {},
  // int -> FLOAT16 map
  .float16Operands = {{0, {0.949999988079071f, 0.8999999761581421f, 0.30000001192092896f}}, {1, {0.0f, 10.0f, 1.0f, 11.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 100.0f, 1.0f, 101.0f}}},
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
return examples_float16_dynamic_output_shape;
};

} // namespace generated_tests::detection_postprocess
namespace generated_tests::detection_postprocess {

std::vector<::test_helper::MixedTypedExample>& get_examples_float16_all_inputs_as_internal() {
static std::vector<::test_helper::MixedTypedExample> examples_float16_all_inputs_as_internal = {
// Begin of an example
{
.operands = {
//Input(s)
{ // See tools/test_generator/include/TestHarness.h:MixedTyped
  // int -> Dimensions map
  .operandDimensions = {{0, {1, 6, 3}}, {1, {1, 6, 4}}, {2, {6, 4}}},
  // int -> FLOAT32 map
  .float32Operands = {},
  // int -> INT32 map
  .int32Operands = {},
  // int -> QUANT8_ASYMM map
  .quant8AsymmOperands = {},
  // int -> QUANT16_SYMM map
  .quant16SymmOperands = {},
  // int -> FLOAT16 map
  .float16Operands = {{0, {0.0f, 0.8999999761581421f, 0.800000011920929f, 0.0f, 0.75f, 0.7200000286102295f, 0.0f, 0.6000000238418579f, 0.5f, 0.0f, 0.9300000071525574f, 0.949999988079071f, 0.0f, 0.5f, 0.4000000059604645f, 0.0f, 0.30000001192092896f, 0.20000000298023224f}}, {1, {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f}}, {2, {0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 100.5f, 1.0f, 1.0f}}},
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
  .operandDimensions = {{0, {1, 3}}, {1, {1, 3, 4}}, {2, {1, 3}}, {3, {1}}},
  // int -> FLOAT32 map
  .float32Operands = {},
  // int -> INT32 map
  .int32Operands = {{2, {1, 0, 0}}, {3, {3}}},
  // int -> QUANT8_ASYMM map
  .quant8AsymmOperands = {},
  // int -> QUANT16_SYMM map
  .quant16SymmOperands = {},
  // int -> FLOAT16 map
  .float16Operands = {{0, {0.949999988079071f, 0.8999999761581421f, 0.30000001192092896f}}, {1, {0.0f, 10.0f, 1.0f, 11.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 100.0f, 1.0f, 101.0f}}},
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
return examples_float16_all_inputs_as_internal;
};

} // namespace generated_tests::detection_postprocess
namespace generated_tests::detection_postprocess {

std::vector<::test_helper::MixedTypedExample>& get_examples_float16_all_inputs_as_internal_dynamic_output_shape() {
static std::vector<::test_helper::MixedTypedExample> examples_float16_all_inputs_as_internal_dynamic_output_shape = {
// Begin of an example
{
.operands = {
//Input(s)
{ // See tools/test_generator/include/TestHarness.h:MixedTyped
  // int -> Dimensions map
  .operandDimensions = {{0, {1, 6, 3}}, {1, {1, 6, 4}}, {2, {6, 4}}},
  // int -> FLOAT32 map
  .float32Operands = {},
  // int -> INT32 map
  .int32Operands = {},
  // int -> QUANT8_ASYMM map
  .quant8AsymmOperands = {},
  // int -> QUANT16_SYMM map
  .quant16SymmOperands = {},
  // int -> FLOAT16 map
  .float16Operands = {{0, {0.0f, 0.8999999761581421f, 0.800000011920929f, 0.0f, 0.75f, 0.7200000286102295f, 0.0f, 0.6000000238418579f, 0.5f, 0.0f, 0.9300000071525574f, 0.949999988079071f, 0.0f, 0.5f, 0.4000000059604645f, 0.0f, 0.30000001192092896f, 0.20000000298023224f}}, {1, {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f}}, {2, {0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 100.5f, 1.0f, 1.0f}}},
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
  .operandDimensions = {{0, {1, 3}}, {1, {1, 3, 4}}, {2, {1, 3}}, {3, {1}}},
  // int -> FLOAT32 map
  .float32Operands = {},
  // int -> INT32 map
  .int32Operands = {{2, {1, 0, 0}}, {3, {3}}},
  // int -> QUANT8_ASYMM map
  .quant8AsymmOperands = {},
  // int -> QUANT16_SYMM map
  .quant16SymmOperands = {},
  // int -> FLOAT16 map
  .float16Operands = {{0, {0.949999988079071f, 0.8999999761581421f, 0.30000001192092896f}}, {1, {0.0f, 10.0f, 1.0f, 11.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 100.0f, 1.0f, 101.0f}}},
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
return examples_float16_all_inputs_as_internal_dynamic_output_shape;
};

} // namespace generated_tests::detection_postprocess
namespace generated_tests::detection_postprocess {

std::vector<::test_helper::MixedTypedExample>& get_examples_2() {
static std::vector<::test_helper::MixedTypedExample> examples_2 = {
// Begin of an example
{
.operands = {
//Input(s)
{ // See tools/test_generator/include/TestHarness.h:MixedTyped
  // int -> Dimensions map
  .operandDimensions = {{0, {1, 6, 3}}, {1, {1, 6, 7}}, {2, {6, 4}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {0.0f, 0.9f, 0.8f, 0.0f, 0.75f, 0.72f, 0.0f, 0.6f, 0.5f, 0.0f, 0.93f, 0.95f, 0.0f, 0.5f, 0.4f, 0.0f, 0.3f, 0.2f}}, {1, {0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f}}, {2, {0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 100.5f, 1.0f, 1.0f}}},
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
  .operandDimensions = {{0, {1, 3}}, {1, {1, 3, 4}}, {2, {1, 3}}, {3, {1}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {0.95f, 0.9f, 0.3f}}, {1, {0.0f, 10.0f, 1.0f, 11.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 100.0f, 1.0f, 101.0f}}},
  // int -> INT32 map
  .int32Operands = {{2, {1, 0, 0}}, {3, {3}}},
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
return examples_2;
};

} // namespace generated_tests::detection_postprocess
namespace generated_tests::detection_postprocess {

std::vector<::test_helper::MixedTypedExample>& get_examples_dynamic_output_shape_2() {
static std::vector<::test_helper::MixedTypedExample> examples_dynamic_output_shape_2 = {
// Begin of an example
{
.operands = {
//Input(s)
{ // See tools/test_generator/include/TestHarness.h:MixedTyped
  // int -> Dimensions map
  .operandDimensions = {{0, {1, 6, 3}}, {1, {1, 6, 7}}, {2, {6, 4}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {0.0f, 0.9f, 0.8f, 0.0f, 0.75f, 0.72f, 0.0f, 0.6f, 0.5f, 0.0f, 0.93f, 0.95f, 0.0f, 0.5f, 0.4f, 0.0f, 0.3f, 0.2f}}, {1, {0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f}}, {2, {0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 100.5f, 1.0f, 1.0f}}},
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
  .operandDimensions = {{0, {1, 3}}, {1, {1, 3, 4}}, {2, {1, 3}}, {3, {1}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {0.95f, 0.9f, 0.3f}}, {1, {0.0f, 10.0f, 1.0f, 11.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 100.0f, 1.0f, 101.0f}}},
  // int -> INT32 map
  .int32Operands = {{2, {1, 0, 0}}, {3, {3}}},
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
return examples_dynamic_output_shape_2;
};

} // namespace generated_tests::detection_postprocess
namespace generated_tests::detection_postprocess {

std::vector<::test_helper::MixedTypedExample>& get_examples_all_inputs_as_internal_2() {
static std::vector<::test_helper::MixedTypedExample> examples_all_inputs_as_internal_2 = {
// Begin of an example
{
.operands = {
//Input(s)
{ // See tools/test_generator/include/TestHarness.h:MixedTyped
  // int -> Dimensions map
  .operandDimensions = {{0, {1, 6, 3}}, {1, {1, 6, 7}}, {2, {6, 4}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {0.0f, 0.9f, 0.8f, 0.0f, 0.75f, 0.72f, 0.0f, 0.6f, 0.5f, 0.0f, 0.93f, 0.95f, 0.0f, 0.5f, 0.4f, 0.0f, 0.3f, 0.2f}}, {1, {0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f}}, {2, {0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 100.5f, 1.0f, 1.0f}}},
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
  .operandDimensions = {{0, {1, 3}}, {1, {1, 3, 4}}, {2, {1, 3}}, {3, {1}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {0.95f, 0.9f, 0.3f}}, {1, {0.0f, 10.0f, 1.0f, 11.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 100.0f, 1.0f, 101.0f}}},
  // int -> INT32 map
  .int32Operands = {{2, {1, 0, 0}}, {3, {3}}},
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
return examples_all_inputs_as_internal_2;
};

} // namespace generated_tests::detection_postprocess
namespace generated_tests::detection_postprocess {

std::vector<::test_helper::MixedTypedExample>& get_examples_all_inputs_as_internal_dynamic_output_shape_2() {
static std::vector<::test_helper::MixedTypedExample> examples_all_inputs_as_internal_dynamic_output_shape_2 = {
// Begin of an example
{
.operands = {
//Input(s)
{ // See tools/test_generator/include/TestHarness.h:MixedTyped
  // int -> Dimensions map
  .operandDimensions = {{0, {1, 6, 3}}, {1, {1, 6, 7}}, {2, {6, 4}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {0.0f, 0.9f, 0.8f, 0.0f, 0.75f, 0.72f, 0.0f, 0.6f, 0.5f, 0.0f, 0.93f, 0.95f, 0.0f, 0.5f, 0.4f, 0.0f, 0.3f, 0.2f}}, {1, {0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f}}, {2, {0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 100.5f, 1.0f, 1.0f}}},
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
  .operandDimensions = {{0, {1, 3}}, {1, {1, 3, 4}}, {2, {1, 3}}, {3, {1}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {0.95f, 0.9f, 0.3f}}, {1, {0.0f, 10.0f, 1.0f, 11.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 100.0f, 1.0f, 101.0f}}},
  // int -> INT32 map
  .int32Operands = {{2, {1, 0, 0}}, {3, {3}}},
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
return examples_all_inputs_as_internal_dynamic_output_shape_2;
};

} // namespace generated_tests::detection_postprocess
namespace generated_tests::detection_postprocess {

std::vector<::test_helper::MixedTypedExample>& get_examples_relaxed_2() {
static std::vector<::test_helper::MixedTypedExample> examples_relaxed_2 = {
// Begin of an example
{
.operands = {
//Input(s)
{ // See tools/test_generator/include/TestHarness.h:MixedTyped
  // int -> Dimensions map
  .operandDimensions = {{0, {1, 6, 3}}, {1, {1, 6, 7}}, {2, {6, 4}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {0.0f, 0.9f, 0.8f, 0.0f, 0.75f, 0.72f, 0.0f, 0.6f, 0.5f, 0.0f, 0.93f, 0.95f, 0.0f, 0.5f, 0.4f, 0.0f, 0.3f, 0.2f}}, {1, {0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f}}, {2, {0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 100.5f, 1.0f, 1.0f}}},
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
  .operandDimensions = {{0, {1, 3}}, {1, {1, 3, 4}}, {2, {1, 3}}, {3, {1}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {0.95f, 0.9f, 0.3f}}, {1, {0.0f, 10.0f, 1.0f, 11.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 100.0f, 1.0f, 101.0f}}},
  // int -> INT32 map
  .int32Operands = {{2, {1, 0, 0}}, {3, {3}}},
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
return examples_relaxed_2;
};

} // namespace generated_tests::detection_postprocess
namespace generated_tests::detection_postprocess {

std::vector<::test_helper::MixedTypedExample>& get_examples_relaxed_dynamic_output_shape_2() {
static std::vector<::test_helper::MixedTypedExample> examples_relaxed_dynamic_output_shape_2 = {
// Begin of an example
{
.operands = {
//Input(s)
{ // See tools/test_generator/include/TestHarness.h:MixedTyped
  // int -> Dimensions map
  .operandDimensions = {{0, {1, 6, 3}}, {1, {1, 6, 7}}, {2, {6, 4}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {0.0f, 0.9f, 0.8f, 0.0f, 0.75f, 0.72f, 0.0f, 0.6f, 0.5f, 0.0f, 0.93f, 0.95f, 0.0f, 0.5f, 0.4f, 0.0f, 0.3f, 0.2f}}, {1, {0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f}}, {2, {0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 100.5f, 1.0f, 1.0f}}},
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
  .operandDimensions = {{0, {1, 3}}, {1, {1, 3, 4}}, {2, {1, 3}}, {3, {1}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {0.95f, 0.9f, 0.3f}}, {1, {0.0f, 10.0f, 1.0f, 11.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 100.0f, 1.0f, 101.0f}}},
  // int -> INT32 map
  .int32Operands = {{2, {1, 0, 0}}, {3, {3}}},
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
return examples_relaxed_dynamic_output_shape_2;
};

} // namespace generated_tests::detection_postprocess
namespace generated_tests::detection_postprocess {

std::vector<::test_helper::MixedTypedExample>& get_examples_relaxed_all_inputs_as_internal_2() {
static std::vector<::test_helper::MixedTypedExample> examples_relaxed_all_inputs_as_internal_2 = {
// Begin of an example
{
.operands = {
//Input(s)
{ // See tools/test_generator/include/TestHarness.h:MixedTyped
  // int -> Dimensions map
  .operandDimensions = {{0, {1, 6, 3}}, {1, {1, 6, 7}}, {2, {6, 4}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {0.0f, 0.9f, 0.8f, 0.0f, 0.75f, 0.72f, 0.0f, 0.6f, 0.5f, 0.0f, 0.93f, 0.95f, 0.0f, 0.5f, 0.4f, 0.0f, 0.3f, 0.2f}}, {1, {0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f}}, {2, {0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 100.5f, 1.0f, 1.0f}}},
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
  .operandDimensions = {{0, {1, 3}}, {1, {1, 3, 4}}, {2, {1, 3}}, {3, {1}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {0.95f, 0.9f, 0.3f}}, {1, {0.0f, 10.0f, 1.0f, 11.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 100.0f, 1.0f, 101.0f}}},
  // int -> INT32 map
  .int32Operands = {{2, {1, 0, 0}}, {3, {3}}},
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
return examples_relaxed_all_inputs_as_internal_2;
};

} // namespace generated_tests::detection_postprocess
namespace generated_tests::detection_postprocess {

std::vector<::test_helper::MixedTypedExample>& get_examples_relaxed_all_inputs_as_internal_dynamic_output_shape_2() {
static std::vector<::test_helper::MixedTypedExample> examples_relaxed_all_inputs_as_internal_dynamic_output_shape_2 = {
// Begin of an example
{
.operands = {
//Input(s)
{ // See tools/test_generator/include/TestHarness.h:MixedTyped
  // int -> Dimensions map
  .operandDimensions = {{0, {1, 6, 3}}, {1, {1, 6, 7}}, {2, {6, 4}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {0.0f, 0.9f, 0.8f, 0.0f, 0.75f, 0.72f, 0.0f, 0.6f, 0.5f, 0.0f, 0.93f, 0.95f, 0.0f, 0.5f, 0.4f, 0.0f, 0.3f, 0.2f}}, {1, {0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f}}, {2, {0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 100.5f, 1.0f, 1.0f}}},
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
  .operandDimensions = {{0, {1, 3}}, {1, {1, 3, 4}}, {2, {1, 3}}, {3, {1}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {0.95f, 0.9f, 0.3f}}, {1, {0.0f, 10.0f, 1.0f, 11.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 100.0f, 1.0f, 101.0f}}},
  // int -> INT32 map
  .int32Operands = {{2, {1, 0, 0}}, {3, {3}}},
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
return examples_relaxed_all_inputs_as_internal_dynamic_output_shape_2;
};

} // namespace generated_tests::detection_postprocess
namespace generated_tests::detection_postprocess {

std::vector<::test_helper::MixedTypedExample>& get_examples_float16_2() {
static std::vector<::test_helper::MixedTypedExample> examples_float16_2 = {
// Begin of an example
{
.operands = {
//Input(s)
{ // See tools/test_generator/include/TestHarness.h:MixedTyped
  // int -> Dimensions map
  .operandDimensions = {{0, {1, 6, 3}}, {1, {1, 6, 7}}, {2, {6, 4}}},
  // int -> FLOAT32 map
  .float32Operands = {},
  // int -> INT32 map
  .int32Operands = {},
  // int -> QUANT8_ASYMM map
  .quant8AsymmOperands = {},
  // int -> QUANT16_SYMM map
  .quant16SymmOperands = {},
  // int -> FLOAT16 map
  .float16Operands = {{0, {0.0f, 0.8999999761581421f, 0.800000011920929f, 0.0f, 0.75f, 0.7200000286102295f, 0.0f, 0.6000000238418579f, 0.5f, 0.0f, 0.9300000071525574f, 0.949999988079071f, 0.0f, 0.5f, 0.4000000059604645f, 0.0f, 0.30000001192092896f, 0.20000000298023224f}}, {1, {0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f}}, {2, {0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 100.5f, 1.0f, 1.0f}}},
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
  .operandDimensions = {{0, {1, 3}}, {1, {1, 3, 4}}, {2, {1, 3}}, {3, {1}}},
  // int -> FLOAT32 map
  .float32Operands = {},
  // int -> INT32 map
  .int32Operands = {{2, {1, 0, 0}}, {3, {3}}},
  // int -> QUANT8_ASYMM map
  .quant8AsymmOperands = {},
  // int -> QUANT16_SYMM map
  .quant16SymmOperands = {},
  // int -> FLOAT16 map
  .float16Operands = {{0, {0.949999988079071f, 0.8999999761581421f, 0.30000001192092896f}}, {1, {0.0f, 10.0f, 1.0f, 11.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 100.0f, 1.0f, 101.0f}}},
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
return examples_float16_2;
};

} // namespace generated_tests::detection_postprocess
namespace generated_tests::detection_postprocess {

std::vector<::test_helper::MixedTypedExample>& get_examples_float16_dynamic_output_shape_2() {
static std::vector<::test_helper::MixedTypedExample> examples_float16_dynamic_output_shape_2 = {
// Begin of an example
{
.operands = {
//Input(s)
{ // See tools/test_generator/include/TestHarness.h:MixedTyped
  // int -> Dimensions map
  .operandDimensions = {{0, {1, 6, 3}}, {1, {1, 6, 7}}, {2, {6, 4}}},
  // int -> FLOAT32 map
  .float32Operands = {},
  // int -> INT32 map
  .int32Operands = {},
  // int -> QUANT8_ASYMM map
  .quant8AsymmOperands = {},
  // int -> QUANT16_SYMM map
  .quant16SymmOperands = {},
  // int -> FLOAT16 map
  .float16Operands = {{0, {0.0f, 0.8999999761581421f, 0.800000011920929f, 0.0f, 0.75f, 0.7200000286102295f, 0.0f, 0.6000000238418579f, 0.5f, 0.0f, 0.9300000071525574f, 0.949999988079071f, 0.0f, 0.5f, 0.4000000059604645f, 0.0f, 0.30000001192092896f, 0.20000000298023224f}}, {1, {0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f}}, {2, {0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 100.5f, 1.0f, 1.0f}}},
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
  .operandDimensions = {{0, {1, 3}}, {1, {1, 3, 4}}, {2, {1, 3}}, {3, {1}}},
  // int -> FLOAT32 map
  .float32Operands = {},
  // int -> INT32 map
  .int32Operands = {{2, {1, 0, 0}}, {3, {3}}},
  // int -> QUANT8_ASYMM map
  .quant8AsymmOperands = {},
  // int -> QUANT16_SYMM map
  .quant16SymmOperands = {},
  // int -> FLOAT16 map
  .float16Operands = {{0, {0.949999988079071f, 0.8999999761581421f, 0.30000001192092896f}}, {1, {0.0f, 10.0f, 1.0f, 11.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 100.0f, 1.0f, 101.0f}}},
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
return examples_float16_dynamic_output_shape_2;
};

} // namespace generated_tests::detection_postprocess
namespace generated_tests::detection_postprocess {

std::vector<::test_helper::MixedTypedExample>& get_examples_float16_all_inputs_as_internal_2() {
static std::vector<::test_helper::MixedTypedExample> examples_float16_all_inputs_as_internal_2 = {
// Begin of an example
{
.operands = {
//Input(s)
{ // See tools/test_generator/include/TestHarness.h:MixedTyped
  // int -> Dimensions map
  .operandDimensions = {{0, {1, 6, 3}}, {1, {1, 6, 7}}, {2, {6, 4}}},
  // int -> FLOAT32 map
  .float32Operands = {},
  // int -> INT32 map
  .int32Operands = {},
  // int -> QUANT8_ASYMM map
  .quant8AsymmOperands = {},
  // int -> QUANT16_SYMM map
  .quant16SymmOperands = {},
  // int -> FLOAT16 map
  .float16Operands = {{0, {0.0f, 0.8999999761581421f, 0.800000011920929f, 0.0f, 0.75f, 0.7200000286102295f, 0.0f, 0.6000000238418579f, 0.5f, 0.0f, 0.9300000071525574f, 0.949999988079071f, 0.0f, 0.5f, 0.4000000059604645f, 0.0f, 0.30000001192092896f, 0.20000000298023224f}}, {1, {0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f}}, {2, {0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 100.5f, 1.0f, 1.0f}}},
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
  .operandDimensions = {{0, {1, 3}}, {1, {1, 3, 4}}, {2, {1, 3}}, {3, {1}}},
  // int -> FLOAT32 map
  .float32Operands = {},
  // int -> INT32 map
  .int32Operands = {{2, {1, 0, 0}}, {3, {3}}},
  // int -> QUANT8_ASYMM map
  .quant8AsymmOperands = {},
  // int -> QUANT16_SYMM map
  .quant16SymmOperands = {},
  // int -> FLOAT16 map
  .float16Operands = {{0, {0.949999988079071f, 0.8999999761581421f, 0.30000001192092896f}}, {1, {0.0f, 10.0f, 1.0f, 11.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 100.0f, 1.0f, 101.0f}}},
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
return examples_float16_all_inputs_as_internal_2;
};

} // namespace generated_tests::detection_postprocess
namespace generated_tests::detection_postprocess {

std::vector<::test_helper::MixedTypedExample>& get_examples_float16_all_inputs_as_internal_dynamic_output_shape_2() {
static std::vector<::test_helper::MixedTypedExample> examples_float16_all_inputs_as_internal_dynamic_output_shape_2 = {
// Begin of an example
{
.operands = {
//Input(s)
{ // See tools/test_generator/include/TestHarness.h:MixedTyped
  // int -> Dimensions map
  .operandDimensions = {{0, {1, 6, 3}}, {1, {1, 6, 7}}, {2, {6, 4}}},
  // int -> FLOAT32 map
  .float32Operands = {},
  // int -> INT32 map
  .int32Operands = {},
  // int -> QUANT8_ASYMM map
  .quant8AsymmOperands = {},
  // int -> QUANT16_SYMM map
  .quant16SymmOperands = {},
  // int -> FLOAT16 map
  .float16Operands = {{0, {0.0f, 0.8999999761581421f, 0.800000011920929f, 0.0f, 0.75f, 0.7200000286102295f, 0.0f, 0.6000000238418579f, 0.5f, 0.0f, 0.9300000071525574f, 0.949999988079071f, 0.0f, 0.5f, 0.4000000059604645f, 0.0f, 0.30000001192092896f, 0.20000000298023224f}}, {1, {0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f}}, {2, {0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 100.5f, 1.0f, 1.0f}}},
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
  .operandDimensions = {{0, {1, 3}}, {1, {1, 3, 4}}, {2, {1, 3}}, {3, {1}}},
  // int -> FLOAT32 map
  .float32Operands = {},
  // int -> INT32 map
  .int32Operands = {{2, {1, 0, 0}}, {3, {3}}},
  // int -> QUANT8_ASYMM map
  .quant8AsymmOperands = {},
  // int -> QUANT16_SYMM map
  .quant16SymmOperands = {},
  // int -> FLOAT16 map
  .float16Operands = {{0, {0.949999988079071f, 0.8999999761581421f, 0.30000001192092896f}}, {1, {0.0f, 10.0f, 1.0f, 11.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 100.0f, 1.0f, 101.0f}}},
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
return examples_float16_all_inputs_as_internal_dynamic_output_shape_2;
};

} // namespace generated_tests::detection_postprocess
namespace generated_tests::detection_postprocess {

std::vector<::test_helper::MixedTypedExample>& get_examples_3() {
static std::vector<::test_helper::MixedTypedExample> examples_3 = {
// Begin of an example
{
.operands = {
//Input(s)
{ // See tools/test_generator/include/TestHarness.h:MixedTyped
  // int -> Dimensions map
  .operandDimensions = {{0, {1, 6, 3}}, {1, {1, 6, 7}}, {2, {6, 4}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {0.0f, 0.9f, 0.8f, 0.0f, 0.75f, 0.72f, 0.0f, 0.6f, 0.5f, 0.0f, 0.93f, 0.95f, 0.0f, 0.5f, 0.4f, 0.0f, 0.3f, 0.2f}}, {1, {0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f}}, {2, {0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 100.5f, 1.0f, 1.0f}}},
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
  .operandDimensions = {{0, {1, 3}}, {1, {1, 3, 4}}, {2, {1, 3}}, {3, {1}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {0.95f, 0.9f, 0.3f}}, {1, {0.0f, 10.0f, 1.0f, 11.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 100.0f, 1.0f, 101.0f}}},
  // int -> INT32 map
  .int32Operands = {{2, {2, 1, 1}}, {3, {3}}},
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
return examples_3;
};

} // namespace generated_tests::detection_postprocess
namespace generated_tests::detection_postprocess {

std::vector<::test_helper::MixedTypedExample>& get_examples_dynamic_output_shape_3() {
static std::vector<::test_helper::MixedTypedExample> examples_dynamic_output_shape_3 = {
// Begin of an example
{
.operands = {
//Input(s)
{ // See tools/test_generator/include/TestHarness.h:MixedTyped
  // int -> Dimensions map
  .operandDimensions = {{0, {1, 6, 3}}, {1, {1, 6, 7}}, {2, {6, 4}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {0.0f, 0.9f, 0.8f, 0.0f, 0.75f, 0.72f, 0.0f, 0.6f, 0.5f, 0.0f, 0.93f, 0.95f, 0.0f, 0.5f, 0.4f, 0.0f, 0.3f, 0.2f}}, {1, {0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f}}, {2, {0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 100.5f, 1.0f, 1.0f}}},
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
  .operandDimensions = {{0, {1, 3}}, {1, {1, 3, 4}}, {2, {1, 3}}, {3, {1}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {0.95f, 0.9f, 0.3f}}, {1, {0.0f, 10.0f, 1.0f, 11.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 100.0f, 1.0f, 101.0f}}},
  // int -> INT32 map
  .int32Operands = {{2, {2, 1, 1}}, {3, {3}}},
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
return examples_dynamic_output_shape_3;
};

} // namespace generated_tests::detection_postprocess
namespace generated_tests::detection_postprocess {

std::vector<::test_helper::MixedTypedExample>& get_examples_all_inputs_as_internal_3() {
static std::vector<::test_helper::MixedTypedExample> examples_all_inputs_as_internal_3 = {
// Begin of an example
{
.operands = {
//Input(s)
{ // See tools/test_generator/include/TestHarness.h:MixedTyped
  // int -> Dimensions map
  .operandDimensions = {{0, {1, 6, 3}}, {1, {1, 6, 7}}, {2, {6, 4}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {0.0f, 0.9f, 0.8f, 0.0f, 0.75f, 0.72f, 0.0f, 0.6f, 0.5f, 0.0f, 0.93f, 0.95f, 0.0f, 0.5f, 0.4f, 0.0f, 0.3f, 0.2f}}, {1, {0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f}}, {2, {0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 100.5f, 1.0f, 1.0f}}},
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
  .operandDimensions = {{0, {1, 3}}, {1, {1, 3, 4}}, {2, {1, 3}}, {3, {1}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {0.95f, 0.9f, 0.3f}}, {1, {0.0f, 10.0f, 1.0f, 11.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 100.0f, 1.0f, 101.0f}}},
  // int -> INT32 map
  .int32Operands = {{2, {2, 1, 1}}, {3, {3}}},
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
return examples_all_inputs_as_internal_3;
};

} // namespace generated_tests::detection_postprocess
namespace generated_tests::detection_postprocess {

std::vector<::test_helper::MixedTypedExample>& get_examples_all_inputs_as_internal_dynamic_output_shape_3() {
static std::vector<::test_helper::MixedTypedExample> examples_all_inputs_as_internal_dynamic_output_shape_3 = {
// Begin of an example
{
.operands = {
//Input(s)
{ // See tools/test_generator/include/TestHarness.h:MixedTyped
  // int -> Dimensions map
  .operandDimensions = {{0, {1, 6, 3}}, {1, {1, 6, 7}}, {2, {6, 4}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {0.0f, 0.9f, 0.8f, 0.0f, 0.75f, 0.72f, 0.0f, 0.6f, 0.5f, 0.0f, 0.93f, 0.95f, 0.0f, 0.5f, 0.4f, 0.0f, 0.3f, 0.2f}}, {1, {0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f}}, {2, {0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 100.5f, 1.0f, 1.0f}}},
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
  .operandDimensions = {{0, {1, 3}}, {1, {1, 3, 4}}, {2, {1, 3}}, {3, {1}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {0.95f, 0.9f, 0.3f}}, {1, {0.0f, 10.0f, 1.0f, 11.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 100.0f, 1.0f, 101.0f}}},
  // int -> INT32 map
  .int32Operands = {{2, {2, 1, 1}}, {3, {3}}},
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
return examples_all_inputs_as_internal_dynamic_output_shape_3;
};

} // namespace generated_tests::detection_postprocess
namespace generated_tests::detection_postprocess {

std::vector<::test_helper::MixedTypedExample>& get_examples_relaxed_3() {
static std::vector<::test_helper::MixedTypedExample> examples_relaxed_3 = {
// Begin of an example
{
.operands = {
//Input(s)
{ // See tools/test_generator/include/TestHarness.h:MixedTyped
  // int -> Dimensions map
  .operandDimensions = {{0, {1, 6, 3}}, {1, {1, 6, 7}}, {2, {6, 4}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {0.0f, 0.9f, 0.8f, 0.0f, 0.75f, 0.72f, 0.0f, 0.6f, 0.5f, 0.0f, 0.93f, 0.95f, 0.0f, 0.5f, 0.4f, 0.0f, 0.3f, 0.2f}}, {1, {0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f}}, {2, {0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 100.5f, 1.0f, 1.0f}}},
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
  .operandDimensions = {{0, {1, 3}}, {1, {1, 3, 4}}, {2, {1, 3}}, {3, {1}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {0.95f, 0.9f, 0.3f}}, {1, {0.0f, 10.0f, 1.0f, 11.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 100.0f, 1.0f, 101.0f}}},
  // int -> INT32 map
  .int32Operands = {{2, {2, 1, 1}}, {3, {3}}},
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
return examples_relaxed_3;
};

} // namespace generated_tests::detection_postprocess
namespace generated_tests::detection_postprocess {

std::vector<::test_helper::MixedTypedExample>& get_examples_relaxed_dynamic_output_shape_3() {
static std::vector<::test_helper::MixedTypedExample> examples_relaxed_dynamic_output_shape_3 = {
// Begin of an example
{
.operands = {
//Input(s)
{ // See tools/test_generator/include/TestHarness.h:MixedTyped
  // int -> Dimensions map
  .operandDimensions = {{0, {1, 6, 3}}, {1, {1, 6, 7}}, {2, {6, 4}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {0.0f, 0.9f, 0.8f, 0.0f, 0.75f, 0.72f, 0.0f, 0.6f, 0.5f, 0.0f, 0.93f, 0.95f, 0.0f, 0.5f, 0.4f, 0.0f, 0.3f, 0.2f}}, {1, {0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f}}, {2, {0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 100.5f, 1.0f, 1.0f}}},
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
  .operandDimensions = {{0, {1, 3}}, {1, {1, 3, 4}}, {2, {1, 3}}, {3, {1}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {0.95f, 0.9f, 0.3f}}, {1, {0.0f, 10.0f, 1.0f, 11.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 100.0f, 1.0f, 101.0f}}},
  // int -> INT32 map
  .int32Operands = {{2, {2, 1, 1}}, {3, {3}}},
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
return examples_relaxed_dynamic_output_shape_3;
};

} // namespace generated_tests::detection_postprocess
namespace generated_tests::detection_postprocess {

std::vector<::test_helper::MixedTypedExample>& get_examples_relaxed_all_inputs_as_internal_3() {
static std::vector<::test_helper::MixedTypedExample> examples_relaxed_all_inputs_as_internal_3 = {
// Begin of an example
{
.operands = {
//Input(s)
{ // See tools/test_generator/include/TestHarness.h:MixedTyped
  // int -> Dimensions map
  .operandDimensions = {{0, {1, 6, 3}}, {1, {1, 6, 7}}, {2, {6, 4}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {0.0f, 0.9f, 0.8f, 0.0f, 0.75f, 0.72f, 0.0f, 0.6f, 0.5f, 0.0f, 0.93f, 0.95f, 0.0f, 0.5f, 0.4f, 0.0f, 0.3f, 0.2f}}, {1, {0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f}}, {2, {0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 100.5f, 1.0f, 1.0f}}},
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
  .operandDimensions = {{0, {1, 3}}, {1, {1, 3, 4}}, {2, {1, 3}}, {3, {1}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {0.95f, 0.9f, 0.3f}}, {1, {0.0f, 10.0f, 1.0f, 11.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 100.0f, 1.0f, 101.0f}}},
  // int -> INT32 map
  .int32Operands = {{2, {2, 1, 1}}, {3, {3}}},
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
return examples_relaxed_all_inputs_as_internal_3;
};

} // namespace generated_tests::detection_postprocess
namespace generated_tests::detection_postprocess {

std::vector<::test_helper::MixedTypedExample>& get_examples_relaxed_all_inputs_as_internal_dynamic_output_shape_3() {
static std::vector<::test_helper::MixedTypedExample> examples_relaxed_all_inputs_as_internal_dynamic_output_shape_3 = {
// Begin of an example
{
.operands = {
//Input(s)
{ // See tools/test_generator/include/TestHarness.h:MixedTyped
  // int -> Dimensions map
  .operandDimensions = {{0, {1, 6, 3}}, {1, {1, 6, 7}}, {2, {6, 4}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {0.0f, 0.9f, 0.8f, 0.0f, 0.75f, 0.72f, 0.0f, 0.6f, 0.5f, 0.0f, 0.93f, 0.95f, 0.0f, 0.5f, 0.4f, 0.0f, 0.3f, 0.2f}}, {1, {0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f}}, {2, {0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 100.5f, 1.0f, 1.0f}}},
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
  .operandDimensions = {{0, {1, 3}}, {1, {1, 3, 4}}, {2, {1, 3}}, {3, {1}}},
  // int -> FLOAT32 map
  .float32Operands = {{0, {0.95f, 0.9f, 0.3f}}, {1, {0.0f, 10.0f, 1.0f, 11.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 100.0f, 1.0f, 101.0f}}},
  // int -> INT32 map
  .int32Operands = {{2, {2, 1, 1}}, {3, {3}}},
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
return examples_relaxed_all_inputs_as_internal_dynamic_output_shape_3;
};

} // namespace generated_tests::detection_postprocess
namespace generated_tests::detection_postprocess {

std::vector<::test_helper::MixedTypedExample>& get_examples_float16_3() {
static std::vector<::test_helper::MixedTypedExample> examples_float16_3 = {
// Begin of an example
{
.operands = {
//Input(s)
{ // See tools/test_generator/include/TestHarness.h:MixedTyped
  // int -> Dimensions map
  .operandDimensions = {{0, {1, 6, 3}}, {1, {1, 6, 7}}, {2, {6, 4}}},
  // int -> FLOAT32 map
  .float32Operands = {},
  // int -> INT32 map
  .int32Operands = {},
  // int -> QUANT8_ASYMM map
  .quant8AsymmOperands = {},
  // int -> QUANT16_SYMM map
  .quant16SymmOperands = {},
  // int -> FLOAT16 map
  .float16Operands = {{0, {0.0f, 0.8999999761581421f, 0.800000011920929f, 0.0f, 0.75f, 0.7200000286102295f, 0.0f, 0.6000000238418579f, 0.5f, 0.0f, 0.9300000071525574f, 0.949999988079071f, 0.0f, 0.5f, 0.4000000059604645f, 0.0f, 0.30000001192092896f, 0.20000000298023224f}}, {1, {0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f}}, {2, {0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 100.5f, 1.0f, 1.0f}}},
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
  .operandDimensions = {{0, {1, 3}}, {1, {1, 3, 4}}, {2, {1, 3}}, {3, {1}}},
  // int -> FLOAT32 map
  .float32Operands = {},
  // int -> INT32 map
  .int32Operands = {{2, {2, 1, 1}}, {3, {3}}},
  // int -> QUANT8_ASYMM map
  .quant8AsymmOperands = {},
  // int -> QUANT16_SYMM map
  .quant16SymmOperands = {},
  // int -> FLOAT16 map
  .float16Operands = {{0, {0.949999988079071f, 0.8999999761581421f, 0.30000001192092896f}}, {1, {0.0f, 10.0f, 1.0f, 11.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 100.0f, 1.0f, 101.0f}}},
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
return examples_float16_3;
};

} // namespace generated_tests::detection_postprocess
namespace generated_tests::detection_postprocess {

std::vector<::test_helper::MixedTypedExample>& get_examples_float16_dynamic_output_shape_3() {
static std::vector<::test_helper::MixedTypedExample> examples_float16_dynamic_output_shape_3 = {
// Begin of an example
{
.operands = {
//Input(s)
{ // See tools/test_generator/include/TestHarness.h:MixedTyped
  // int -> Dimensions map
  .operandDimensions = {{0, {1, 6, 3}}, {1, {1, 6, 7}}, {2, {6, 4}}},
  // int -> FLOAT32 map
  .float32Operands = {},
  // int -> INT32 map
  .int32Operands = {},
  // int -> QUANT8_ASYMM map
  .quant8AsymmOperands = {},
  // int -> QUANT16_SYMM map
  .quant16SymmOperands = {},
  // int -> FLOAT16 map
  .float16Operands = {{0, {0.0f, 0.8999999761581421f, 0.800000011920929f, 0.0f, 0.75f, 0.7200000286102295f, 0.0f, 0.6000000238418579f, 0.5f, 0.0f, 0.9300000071525574f, 0.949999988079071f, 0.0f, 0.5f, 0.4000000059604645f, 0.0f, 0.30000001192092896f, 0.20000000298023224f}}, {1, {0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f}}, {2, {0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 100.5f, 1.0f, 1.0f}}},
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
  .operandDimensions = {{0, {1, 3}}, {1, {1, 3, 4}}, {2, {1, 3}}, {3, {1}}},
  // int -> FLOAT32 map
  .float32Operands = {},
  // int -> INT32 map
  .int32Operands = {{2, {2, 1, 1}}, {3, {3}}},
  // int -> QUANT8_ASYMM map
  .quant8AsymmOperands = {},
  // int -> QUANT16_SYMM map
  .quant16SymmOperands = {},
  // int -> FLOAT16 map
  .float16Operands = {{0, {0.949999988079071f, 0.8999999761581421f, 0.30000001192092896f}}, {1, {0.0f, 10.0f, 1.0f, 11.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 100.0f, 1.0f, 101.0f}}},
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
return examples_float16_dynamic_output_shape_3;
};

} // namespace generated_tests::detection_postprocess
namespace generated_tests::detection_postprocess {

std::vector<::test_helper::MixedTypedExample>& get_examples_float16_all_inputs_as_internal_3() {
static std::vector<::test_helper::MixedTypedExample> examples_float16_all_inputs_as_internal_3 = {
// Begin of an example
{
.operands = {
//Input(s)
{ // See tools/test_generator/include/TestHarness.h:MixedTyped
  // int -> Dimensions map
  .operandDimensions = {{0, {1, 6, 3}}, {1, {1, 6, 7}}, {2, {6, 4}}},
  // int -> FLOAT32 map
  .float32Operands = {},
  // int -> INT32 map
  .int32Operands = {},
  // int -> QUANT8_ASYMM map
  .quant8AsymmOperands = {},
  // int -> QUANT16_SYMM map
  .quant16SymmOperands = {},
  // int -> FLOAT16 map
  .float16Operands = {{0, {0.0f, 0.8999999761581421f, 0.800000011920929f, 0.0f, 0.75f, 0.7200000286102295f, 0.0f, 0.6000000238418579f, 0.5f, 0.0f, 0.9300000071525574f, 0.949999988079071f, 0.0f, 0.5f, 0.4000000059604645f, 0.0f, 0.30000001192092896f, 0.20000000298023224f}}, {1, {0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f}}, {2, {0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 100.5f, 1.0f, 1.0f}}},
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
  .operandDimensions = {{0, {1, 3}}, {1, {1, 3, 4}}, {2, {1, 3}}, {3, {1}}},
  // int -> FLOAT32 map
  .float32Operands = {},
  // int -> INT32 map
  .int32Operands = {{2, {2, 1, 1}}, {3, {3}}},
  // int -> QUANT8_ASYMM map
  .quant8AsymmOperands = {},
  // int -> QUANT16_SYMM map
  .quant16SymmOperands = {},
  // int -> FLOAT16 map
  .float16Operands = {{0, {0.949999988079071f, 0.8999999761581421f, 0.30000001192092896f}}, {1, {0.0f, 10.0f, 1.0f, 11.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 100.0f, 1.0f, 101.0f}}},
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
return examples_float16_all_inputs_as_internal_3;
};

} // namespace generated_tests::detection_postprocess
namespace generated_tests::detection_postprocess {

std::vector<::test_helper::MixedTypedExample>& get_examples_float16_all_inputs_as_internal_dynamic_output_shape_3() {
static std::vector<::test_helper::MixedTypedExample> examples_float16_all_inputs_as_internal_dynamic_output_shape_3 = {
// Begin of an example
{
.operands = {
//Input(s)
{ // See tools/test_generator/include/TestHarness.h:MixedTyped
  // int -> Dimensions map
  .operandDimensions = {{0, {1, 6, 3}}, {1, {1, 6, 7}}, {2, {6, 4}}},
  // int -> FLOAT32 map
  .float32Operands = {},
  // int -> INT32 map
  .int32Operands = {},
  // int -> QUANT8_ASYMM map
  .quant8AsymmOperands = {},
  // int -> QUANT16_SYMM map
  .quant16SymmOperands = {},
  // int -> FLOAT16 map
  .float16Operands = {{0, {0.0f, 0.8999999761581421f, 0.800000011920929f, 0.0f, 0.75f, 0.7200000286102295f, 0.0f, 0.6000000238418579f, 0.5f, 0.0f, 0.9300000071525574f, 0.949999988079071f, 0.0f, 0.5f, 0.4000000059604645f, 0.0f, 0.30000001192092896f, 0.20000000298023224f}}, {1, {0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f}}, {2, {0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 10.5f, 1.0f, 1.0f, 0.5f, 100.5f, 1.0f, 1.0f}}},
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
  .operandDimensions = {{0, {1, 3}}, {1, {1, 3, 4}}, {2, {1, 3}}, {3, {1}}},
  // int -> FLOAT32 map
  .float32Operands = {},
  // int -> INT32 map
  .int32Operands = {{2, {2, 1, 1}}, {3, {3}}},
  // int -> QUANT8_ASYMM map
  .quant8AsymmOperands = {},
  // int -> QUANT16_SYMM map
  .quant16SymmOperands = {},
  // int -> FLOAT16 map
  .float16Operands = {{0, {0.949999988079071f, 0.8999999761581421f, 0.30000001192092896f}}, {1, {0.0f, 10.0f, 1.0f, 11.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 100.0f, 1.0f, 101.0f}}},
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
return examples_float16_all_inputs_as_internal_dynamic_output_shape_3;
};

} // namespace generated_tests::detection_postprocess
