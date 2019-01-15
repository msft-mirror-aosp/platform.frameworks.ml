// clang-format off
// Generated file (from: quantized_lstm.mod.py). Do not edit
std::vector<MixedTypedExample>& get_examples() {
static std::vector<MixedTypedExample> examples = {
// Begin of an example
{
.operands = {
//Input(s)
{ // See tools/test_generator/include/TestHarness.h:MixedTyped
  // int -> FLOAT32 map
  {},
  // int -> INT32 map
  {{3, {-7876, 13488, -726, 32839, 39481, 48624, 48976, -21419, 9206, -46884, -11693, -38724, -58999, -17050, -41852, -40538}}},
  // int -> QUANT8_ASYMM map
  {{0, {166, 179, 50, 150}}, {1, {136, 150, 140, 115, 135, 152, 138, 112}}, {2, {254, 206, 77, 168, 146, 250, 71, 20, 215, 6, 235, 171, 223, 7, 118, 225, 10, 218, 59, 130, 174, 26, 171, 108, 172, 60, 205, 65, 133, 34, 14, 0, 140, 168, 29, 49, 240, 223, 133, 56, 206, 109, 142, 64, 246, 216, 54, 183, 137, 240, 103, 52, 24, 50, 68, 51, 237, 112, 132, 179, 0, 220, 89, 23, 158, 110, 69, 4, 207, 253, 3, 169, 106, 214, 67, 23, 195, 187, 59, 158, 45, 3, 11, 99, 119, 132, 49, 205, 109, 10, 129, 218, 11, 98, 218, 48}}},
  // int -> QUANT16_SYMM map
  {{4, {876, 1034, 955, -909, 761, 1029, 796, -1036}}},
  // int -> FLOAT16 map
  {},
  // int -> BOOL8 map
  {},
  // int -> QUANT8_SYMM_PER_CHANNEL map
  {},
},
//Output(s)
{ // See tools/test_generator/include/TestHarness.h:MixedTyped
  // int -> FLOAT32 map
  {},
  // int -> INT32 map
  {},
  // int -> QUANT8_ASYMM map
  {{0, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, {2, {140, 151, 146, 112, 136, 156, 142, 112}}, {4, {140, 151, 146, 112, 136, 156, 142, 112}}},
  // int -> QUANT16_SYMM map
  {{1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, {3, {1485, 1177, 1373, -1023, 1019, 1355, 1097, -1235}}},
  // int -> FLOAT16 map
  {},
  // int -> BOOL8 map
  {},
  // int -> QUANT8_SYMM_PER_CHANNEL map
  {},
}
},
}, // End of an example
};
return examples;
};

