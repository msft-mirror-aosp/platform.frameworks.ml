// clang-format off
// Generated file (from: resize_bilinear_v1_2.mod.py). Do not edit
void CreateModel_nhwc(Model *model) {
  OperandType type0(Type::BOOL, {});
  OperandType type1(Type::TENSOR_FLOAT32, {1, 2, 2, 1});
  OperandType type2(Type::TENSOR_FLOAT32, {1, 3, 3, 1});
  OperandType type3(Type::INT32, {});
  // Phase 1, operands
  auto op1 = model->addOperand(&type1);
  auto param = model->addOperand(&type3);
  auto param1 = model->addOperand(&type3);
  auto layout = model->addOperand(&type0);
  auto op4 = model->addOperand(&type2);
  // Phase 2, operations
  static int32_t param_init[] = {3};
  model->setOperandValue(param, param_init, sizeof(int32_t) * 1);
  static int32_t param1_init[] = {3};
  model->setOperandValue(param1, param1_init, sizeof(int32_t) * 1);
  static bool8 layout_init[] = {false};
  model->setOperandValue(layout, layout_init, sizeof(bool8) * 1);
  model->addOperation(ANEURALNETWORKS_RESIZE_BILINEAR, {op1, param, param1, layout}, {op4});
  // Phase 3, inputs and outputs
  model->identifyInputsAndOutputs(
    {op1},
    {op4});
  assert(model->isValid());
}

inline bool is_ignored_nhwc(int i) {
  static std::set<int> ignore = {};
  return ignore.find(i) != ignore.end();
}

void CreateModel_nhwc_relaxed(Model *model) {
  OperandType type0(Type::BOOL, {});
  OperandType type1(Type::TENSOR_FLOAT32, {1, 2, 2, 1});
  OperandType type2(Type::TENSOR_FLOAT32, {1, 3, 3, 1});
  OperandType type3(Type::INT32, {});
  // Phase 1, operands
  auto op1 = model->addOperand(&type1);
  auto param = model->addOperand(&type3);
  auto param1 = model->addOperand(&type3);
  auto layout = model->addOperand(&type0);
  auto op4 = model->addOperand(&type2);
  // Phase 2, operations
  static int32_t param_init[] = {3};
  model->setOperandValue(param, param_init, sizeof(int32_t) * 1);
  static int32_t param1_init[] = {3};
  model->setOperandValue(param1, param1_init, sizeof(int32_t) * 1);
  static bool8 layout_init[] = {false};
  model->setOperandValue(layout, layout_init, sizeof(bool8) * 1);
  model->addOperation(ANEURALNETWORKS_RESIZE_BILINEAR, {op1, param, param1, layout}, {op4});
  // Phase 3, inputs and outputs
  model->identifyInputsAndOutputs(
    {op1},
    {op4});
  // Phase 4: set relaxed execution
  model->relaxComputationFloat32toFloat16(true);
  assert(model->isValid());
}

inline bool is_ignored_nhwc_relaxed(int i) {
  static std::set<int> ignore = {};
  return ignore.find(i) != ignore.end();
}

void CreateModel_nhwc_float16(Model *model) {
  OperandType type0(Type::BOOL, {});
  OperandType type3(Type::INT32, {});
  OperandType type6(Type::TENSOR_FLOAT16, {1, 2, 2, 1});
  OperandType type7(Type::TENSOR_FLOAT16, {1, 3, 3, 1});
  // Phase 1, operands
  auto op1 = model->addOperand(&type6);
  auto param = model->addOperand(&type3);
  auto param1 = model->addOperand(&type3);
  auto layout = model->addOperand(&type0);
  auto op4 = model->addOperand(&type7);
  // Phase 2, operations
  static int32_t param_init[] = {3};
  model->setOperandValue(param, param_init, sizeof(int32_t) * 1);
  static int32_t param1_init[] = {3};
  model->setOperandValue(param1, param1_init, sizeof(int32_t) * 1);
  static bool8 layout_init[] = {false};
  model->setOperandValue(layout, layout_init, sizeof(bool8) * 1);
  model->addOperation(ANEURALNETWORKS_RESIZE_BILINEAR, {op1, param, param1, layout}, {op4});
  // Phase 3, inputs and outputs
  model->identifyInputsAndOutputs(
    {op1},
    {op4});
  assert(model->isValid());
}

inline bool is_ignored_nhwc_float16(int i) {
  static std::set<int> ignore = {};
  return ignore.find(i) != ignore.end();
}

void CreateModel_nchw(Model *model) {
  OperandType type0(Type::BOOL, {});
  OperandType type3(Type::INT32, {});
  OperandType type8(Type::TENSOR_FLOAT32, {1, 1, 2, 2});
  OperandType type9(Type::TENSOR_FLOAT32, {1, 1, 3, 3});
  // Phase 1, operands
  auto op1 = model->addOperand(&type8);
  auto param = model->addOperand(&type3);
  auto param1 = model->addOperand(&type3);
  auto layout = model->addOperand(&type0);
  auto op4 = model->addOperand(&type9);
  // Phase 2, operations
  static int32_t param_init[] = {3};
  model->setOperandValue(param, param_init, sizeof(int32_t) * 1);
  static int32_t param1_init[] = {3};
  model->setOperandValue(param1, param1_init, sizeof(int32_t) * 1);
  static bool8 layout_init[] = {true};
  model->setOperandValue(layout, layout_init, sizeof(bool8) * 1);
  model->addOperation(ANEURALNETWORKS_RESIZE_BILINEAR, {op1, param, param1, layout}, {op4});
  // Phase 3, inputs and outputs
  model->identifyInputsAndOutputs(
    {op1},
    {op4});
  assert(model->isValid());
}

inline bool is_ignored_nchw(int i) {
  static std::set<int> ignore = {};
  return ignore.find(i) != ignore.end();
}

void CreateModel_nchw_relaxed(Model *model) {
  OperandType type0(Type::BOOL, {});
  OperandType type3(Type::INT32, {});
  OperandType type8(Type::TENSOR_FLOAT32, {1, 1, 2, 2});
  OperandType type9(Type::TENSOR_FLOAT32, {1, 1, 3, 3});
  // Phase 1, operands
  auto op1 = model->addOperand(&type8);
  auto param = model->addOperand(&type3);
  auto param1 = model->addOperand(&type3);
  auto layout = model->addOperand(&type0);
  auto op4 = model->addOperand(&type9);
  // Phase 2, operations
  static int32_t param_init[] = {3};
  model->setOperandValue(param, param_init, sizeof(int32_t) * 1);
  static int32_t param1_init[] = {3};
  model->setOperandValue(param1, param1_init, sizeof(int32_t) * 1);
  static bool8 layout_init[] = {true};
  model->setOperandValue(layout, layout_init, sizeof(bool8) * 1);
  model->addOperation(ANEURALNETWORKS_RESIZE_BILINEAR, {op1, param, param1, layout}, {op4});
  // Phase 3, inputs and outputs
  model->identifyInputsAndOutputs(
    {op1},
    {op4});
  // Phase 4: set relaxed execution
  model->relaxComputationFloat32toFloat16(true);
  assert(model->isValid());
}

inline bool is_ignored_nchw_relaxed(int i) {
  static std::set<int> ignore = {};
  return ignore.find(i) != ignore.end();
}

void CreateModel_nchw_float16(Model *model) {
  OperandType type0(Type::BOOL, {});
  OperandType type10(Type::TENSOR_FLOAT16, {1, 1, 2, 2});
  OperandType type11(Type::TENSOR_FLOAT16, {1, 1, 3, 3});
  OperandType type3(Type::INT32, {});
  // Phase 1, operands
  auto op1 = model->addOperand(&type10);
  auto param = model->addOperand(&type3);
  auto param1 = model->addOperand(&type3);
  auto layout = model->addOperand(&type0);
  auto op4 = model->addOperand(&type11);
  // Phase 2, operations
  static int32_t param_init[] = {3};
  model->setOperandValue(param, param_init, sizeof(int32_t) * 1);
  static int32_t param1_init[] = {3};
  model->setOperandValue(param1, param1_init, sizeof(int32_t) * 1);
  static bool8 layout_init[] = {true};
  model->setOperandValue(layout, layout_init, sizeof(bool8) * 1);
  model->addOperation(ANEURALNETWORKS_RESIZE_BILINEAR, {op1, param, param1, layout}, {op4});
  // Phase 3, inputs and outputs
  model->identifyInputsAndOutputs(
    {op1},
    {op4});
  assert(model->isValid());
}

inline bool is_ignored_nchw_float16(int i) {
  static std::set<int> ignore = {};
  return ignore.find(i) != ignore.end();
}

void CreateModel_dynamic_output_shape_nhwc(Model *model) {
  OperandType type0(Type::BOOL, {});
  OperandType type1(Type::TENSOR_FLOAT32, {1, 2, 2, 1});
  OperandType type12(Type::TENSOR_FLOAT32, {0, 0, 0, 0});
  OperandType type3(Type::INT32, {});
  // Phase 1, operands
  auto op1 = model->addOperand(&type1);
  auto param = model->addOperand(&type3);
  auto param1 = model->addOperand(&type3);
  auto layout = model->addOperand(&type0);
  auto op4 = model->addOperand(&type12);
  // Phase 2, operations
  static int32_t param_init[] = {3};
  model->setOperandValue(param, param_init, sizeof(int32_t) * 1);
  static int32_t param1_init[] = {3};
  model->setOperandValue(param1, param1_init, sizeof(int32_t) * 1);
  static bool8 layout_init[] = {false};
  model->setOperandValue(layout, layout_init, sizeof(bool8) * 1);
  model->addOperation(ANEURALNETWORKS_RESIZE_BILINEAR, {op1, param, param1, layout}, {op4});
  // Phase 3, inputs and outputs
  model->identifyInputsAndOutputs(
    {op1},
    {op4});
  assert(model->isValid());
}

inline bool is_ignored_dynamic_output_shape_nhwc(int i) {
  static std::set<int> ignore = {};
  return ignore.find(i) != ignore.end();
}

void CreateModel_dynamic_output_shape_nhwc_relaxed(Model *model) {
  OperandType type0(Type::BOOL, {});
  OperandType type1(Type::TENSOR_FLOAT32, {1, 2, 2, 1});
  OperandType type12(Type::TENSOR_FLOAT32, {0, 0, 0, 0});
  OperandType type3(Type::INT32, {});
  // Phase 1, operands
  auto op1 = model->addOperand(&type1);
  auto param = model->addOperand(&type3);
  auto param1 = model->addOperand(&type3);
  auto layout = model->addOperand(&type0);
  auto op4 = model->addOperand(&type12);
  // Phase 2, operations
  static int32_t param_init[] = {3};
  model->setOperandValue(param, param_init, sizeof(int32_t) * 1);
  static int32_t param1_init[] = {3};
  model->setOperandValue(param1, param1_init, sizeof(int32_t) * 1);
  static bool8 layout_init[] = {false};
  model->setOperandValue(layout, layout_init, sizeof(bool8) * 1);
  model->addOperation(ANEURALNETWORKS_RESIZE_BILINEAR, {op1, param, param1, layout}, {op4});
  // Phase 3, inputs and outputs
  model->identifyInputsAndOutputs(
    {op1},
    {op4});
  // Phase 4: set relaxed execution
  model->relaxComputationFloat32toFloat16(true);
  assert(model->isValid());
}

inline bool is_ignored_dynamic_output_shape_nhwc_relaxed(int i) {
  static std::set<int> ignore = {};
  return ignore.find(i) != ignore.end();
}

void CreateModel_dynamic_output_shape_nhwc_float16(Model *model) {
  OperandType type0(Type::BOOL, {});
  OperandType type13(Type::TENSOR_FLOAT16, {0, 0, 0, 0});
  OperandType type3(Type::INT32, {});
  OperandType type6(Type::TENSOR_FLOAT16, {1, 2, 2, 1});
  // Phase 1, operands
  auto op1 = model->addOperand(&type6);
  auto param = model->addOperand(&type3);
  auto param1 = model->addOperand(&type3);
  auto layout = model->addOperand(&type0);
  auto op4 = model->addOperand(&type13);
  // Phase 2, operations
  static int32_t param_init[] = {3};
  model->setOperandValue(param, param_init, sizeof(int32_t) * 1);
  static int32_t param1_init[] = {3};
  model->setOperandValue(param1, param1_init, sizeof(int32_t) * 1);
  static bool8 layout_init[] = {false};
  model->setOperandValue(layout, layout_init, sizeof(bool8) * 1);
  model->addOperation(ANEURALNETWORKS_RESIZE_BILINEAR, {op1, param, param1, layout}, {op4});
  // Phase 3, inputs and outputs
  model->identifyInputsAndOutputs(
    {op1},
    {op4});
  assert(model->isValid());
}

inline bool is_ignored_dynamic_output_shape_nhwc_float16(int i) {
  static std::set<int> ignore = {};
  return ignore.find(i) != ignore.end();
}

void CreateModel_dynamic_output_shape_nchw(Model *model) {
  OperandType type0(Type::BOOL, {});
  OperandType type12(Type::TENSOR_FLOAT32, {0, 0, 0, 0});
  OperandType type3(Type::INT32, {});
  OperandType type8(Type::TENSOR_FLOAT32, {1, 1, 2, 2});
  // Phase 1, operands
  auto op1 = model->addOperand(&type8);
  auto param = model->addOperand(&type3);
  auto param1 = model->addOperand(&type3);
  auto layout = model->addOperand(&type0);
  auto op4 = model->addOperand(&type12);
  // Phase 2, operations
  static int32_t param_init[] = {3};
  model->setOperandValue(param, param_init, sizeof(int32_t) * 1);
  static int32_t param1_init[] = {3};
  model->setOperandValue(param1, param1_init, sizeof(int32_t) * 1);
  static bool8 layout_init[] = {true};
  model->setOperandValue(layout, layout_init, sizeof(bool8) * 1);
  model->addOperation(ANEURALNETWORKS_RESIZE_BILINEAR, {op1, param, param1, layout}, {op4});
  // Phase 3, inputs and outputs
  model->identifyInputsAndOutputs(
    {op1},
    {op4});
  assert(model->isValid());
}

inline bool is_ignored_dynamic_output_shape_nchw(int i) {
  static std::set<int> ignore = {};
  return ignore.find(i) != ignore.end();
}

void CreateModel_dynamic_output_shape_nchw_relaxed(Model *model) {
  OperandType type0(Type::BOOL, {});
  OperandType type12(Type::TENSOR_FLOAT32, {0, 0, 0, 0});
  OperandType type3(Type::INT32, {});
  OperandType type8(Type::TENSOR_FLOAT32, {1, 1, 2, 2});
  // Phase 1, operands
  auto op1 = model->addOperand(&type8);
  auto param = model->addOperand(&type3);
  auto param1 = model->addOperand(&type3);
  auto layout = model->addOperand(&type0);
  auto op4 = model->addOperand(&type12);
  // Phase 2, operations
  static int32_t param_init[] = {3};
  model->setOperandValue(param, param_init, sizeof(int32_t) * 1);
  static int32_t param1_init[] = {3};
  model->setOperandValue(param1, param1_init, sizeof(int32_t) * 1);
  static bool8 layout_init[] = {true};
  model->setOperandValue(layout, layout_init, sizeof(bool8) * 1);
  model->addOperation(ANEURALNETWORKS_RESIZE_BILINEAR, {op1, param, param1, layout}, {op4});
  // Phase 3, inputs and outputs
  model->identifyInputsAndOutputs(
    {op1},
    {op4});
  // Phase 4: set relaxed execution
  model->relaxComputationFloat32toFloat16(true);
  assert(model->isValid());
}

inline bool is_ignored_dynamic_output_shape_nchw_relaxed(int i) {
  static std::set<int> ignore = {};
  return ignore.find(i) != ignore.end();
}

void CreateModel_dynamic_output_shape_nchw_float16(Model *model) {
  OperandType type0(Type::BOOL, {});
  OperandType type10(Type::TENSOR_FLOAT16, {1, 1, 2, 2});
  OperandType type13(Type::TENSOR_FLOAT16, {0, 0, 0, 0});
  OperandType type3(Type::INT32, {});
  // Phase 1, operands
  auto op1 = model->addOperand(&type10);
  auto param = model->addOperand(&type3);
  auto param1 = model->addOperand(&type3);
  auto layout = model->addOperand(&type0);
  auto op4 = model->addOperand(&type13);
  // Phase 2, operations
  static int32_t param_init[] = {3};
  model->setOperandValue(param, param_init, sizeof(int32_t) * 1);
  static int32_t param1_init[] = {3};
  model->setOperandValue(param1, param1_init, sizeof(int32_t) * 1);
  static bool8 layout_init[] = {true};
  model->setOperandValue(layout, layout_init, sizeof(bool8) * 1);
  model->addOperation(ANEURALNETWORKS_RESIZE_BILINEAR, {op1, param, param1, layout}, {op4});
  // Phase 3, inputs and outputs
  model->identifyInputsAndOutputs(
    {op1},
    {op4});
  assert(model->isValid());
}

inline bool is_ignored_dynamic_output_shape_nchw_float16(int i) {
  static std::set<int> ignore = {};
  return ignore.find(i) != ignore.end();
}

void CreateModel_nhwc_2(Model *model) {
  OperandType type0(Type::BOOL, {});
  OperandType type3(Type::INT32, {});
  OperandType type4(Type::TENSOR_FLOAT32, {1, 2, 2, 2});
  OperandType type5(Type::TENSOR_FLOAT32, {1, 3, 3, 2});
  // Phase 1, operands
  auto op11 = model->addOperand(&type4);
  auto param2 = model->addOperand(&type3);
  auto param3 = model->addOperand(&type3);
  auto layout = model->addOperand(&type0);
  auto op41 = model->addOperand(&type5);
  // Phase 2, operations
  static int32_t param2_init[] = {3};
  model->setOperandValue(param2, param2_init, sizeof(int32_t) * 1);
  static int32_t param3_init[] = {3};
  model->setOperandValue(param3, param3_init, sizeof(int32_t) * 1);
  static bool8 layout_init[] = {false};
  model->setOperandValue(layout, layout_init, sizeof(bool8) * 1);
  model->addOperation(ANEURALNETWORKS_RESIZE_BILINEAR, {op11, param2, param3, layout}, {op41});
  // Phase 3, inputs and outputs
  model->identifyInputsAndOutputs(
    {op11},
    {op41});
  assert(model->isValid());
}

inline bool is_ignored_nhwc_2(int i) {
  static std::set<int> ignore = {};
  return ignore.find(i) != ignore.end();
}

void CreateModel_nhwc_relaxed_2(Model *model) {
  OperandType type0(Type::BOOL, {});
  OperandType type3(Type::INT32, {});
  OperandType type4(Type::TENSOR_FLOAT32, {1, 2, 2, 2});
  OperandType type5(Type::TENSOR_FLOAT32, {1, 3, 3, 2});
  // Phase 1, operands
  auto op11 = model->addOperand(&type4);
  auto param2 = model->addOperand(&type3);
  auto param3 = model->addOperand(&type3);
  auto layout = model->addOperand(&type0);
  auto op41 = model->addOperand(&type5);
  // Phase 2, operations
  static int32_t param2_init[] = {3};
  model->setOperandValue(param2, param2_init, sizeof(int32_t) * 1);
  static int32_t param3_init[] = {3};
  model->setOperandValue(param3, param3_init, sizeof(int32_t) * 1);
  static bool8 layout_init[] = {false};
  model->setOperandValue(layout, layout_init, sizeof(bool8) * 1);
  model->addOperation(ANEURALNETWORKS_RESIZE_BILINEAR, {op11, param2, param3, layout}, {op41});
  // Phase 3, inputs and outputs
  model->identifyInputsAndOutputs(
    {op11},
    {op41});
  // Phase 4: set relaxed execution
  model->relaxComputationFloat32toFloat16(true);
  assert(model->isValid());
}

inline bool is_ignored_nhwc_relaxed_2(int i) {
  static std::set<int> ignore = {};
  return ignore.find(i) != ignore.end();
}

void CreateModel_nhwc_float16_2(Model *model) {
  OperandType type0(Type::BOOL, {});
  OperandType type14(Type::TENSOR_FLOAT16, {1, 2, 2, 2});
  OperandType type15(Type::TENSOR_FLOAT16, {1, 3, 3, 2});
  OperandType type3(Type::INT32, {});
  // Phase 1, operands
  auto op11 = model->addOperand(&type14);
  auto param2 = model->addOperand(&type3);
  auto param3 = model->addOperand(&type3);
  auto layout = model->addOperand(&type0);
  auto op41 = model->addOperand(&type15);
  // Phase 2, operations
  static int32_t param2_init[] = {3};
  model->setOperandValue(param2, param2_init, sizeof(int32_t) * 1);
  static int32_t param3_init[] = {3};
  model->setOperandValue(param3, param3_init, sizeof(int32_t) * 1);
  static bool8 layout_init[] = {false};
  model->setOperandValue(layout, layout_init, sizeof(bool8) * 1);
  model->addOperation(ANEURALNETWORKS_RESIZE_BILINEAR, {op11, param2, param3, layout}, {op41});
  // Phase 3, inputs and outputs
  model->identifyInputsAndOutputs(
    {op11},
    {op41});
  assert(model->isValid());
}

inline bool is_ignored_nhwc_float16_2(int i) {
  static std::set<int> ignore = {};
  return ignore.find(i) != ignore.end();
}

void CreateModel_nchw_2(Model *model) {
  OperandType type0(Type::BOOL, {});
  OperandType type16(Type::TENSOR_FLOAT32, {1, 2, 3, 3});
  OperandType type3(Type::INT32, {});
  OperandType type4(Type::TENSOR_FLOAT32, {1, 2, 2, 2});
  // Phase 1, operands
  auto op11 = model->addOperand(&type4);
  auto param2 = model->addOperand(&type3);
  auto param3 = model->addOperand(&type3);
  auto layout = model->addOperand(&type0);
  auto op41 = model->addOperand(&type16);
  // Phase 2, operations
  static int32_t param2_init[] = {3};
  model->setOperandValue(param2, param2_init, sizeof(int32_t) * 1);
  static int32_t param3_init[] = {3};
  model->setOperandValue(param3, param3_init, sizeof(int32_t) * 1);
  static bool8 layout_init[] = {true};
  model->setOperandValue(layout, layout_init, sizeof(bool8) * 1);
  model->addOperation(ANEURALNETWORKS_RESIZE_BILINEAR, {op11, param2, param3, layout}, {op41});
  // Phase 3, inputs and outputs
  model->identifyInputsAndOutputs(
    {op11},
    {op41});
  assert(model->isValid());
}

inline bool is_ignored_nchw_2(int i) {
  static std::set<int> ignore = {};
  return ignore.find(i) != ignore.end();
}

void CreateModel_nchw_relaxed_2(Model *model) {
  OperandType type0(Type::BOOL, {});
  OperandType type16(Type::TENSOR_FLOAT32, {1, 2, 3, 3});
  OperandType type3(Type::INT32, {});
  OperandType type4(Type::TENSOR_FLOAT32, {1, 2, 2, 2});
  // Phase 1, operands
  auto op11 = model->addOperand(&type4);
  auto param2 = model->addOperand(&type3);
  auto param3 = model->addOperand(&type3);
  auto layout = model->addOperand(&type0);
  auto op41 = model->addOperand(&type16);
  // Phase 2, operations
  static int32_t param2_init[] = {3};
  model->setOperandValue(param2, param2_init, sizeof(int32_t) * 1);
  static int32_t param3_init[] = {3};
  model->setOperandValue(param3, param3_init, sizeof(int32_t) * 1);
  static bool8 layout_init[] = {true};
  model->setOperandValue(layout, layout_init, sizeof(bool8) * 1);
  model->addOperation(ANEURALNETWORKS_RESIZE_BILINEAR, {op11, param2, param3, layout}, {op41});
  // Phase 3, inputs and outputs
  model->identifyInputsAndOutputs(
    {op11},
    {op41});
  // Phase 4: set relaxed execution
  model->relaxComputationFloat32toFloat16(true);
  assert(model->isValid());
}

inline bool is_ignored_nchw_relaxed_2(int i) {
  static std::set<int> ignore = {};
  return ignore.find(i) != ignore.end();
}

void CreateModel_nchw_float16_2(Model *model) {
  OperandType type0(Type::BOOL, {});
  OperandType type14(Type::TENSOR_FLOAT16, {1, 2, 2, 2});
  OperandType type17(Type::TENSOR_FLOAT16, {1, 2, 3, 3});
  OperandType type3(Type::INT32, {});
  // Phase 1, operands
  auto op11 = model->addOperand(&type14);
  auto param2 = model->addOperand(&type3);
  auto param3 = model->addOperand(&type3);
  auto layout = model->addOperand(&type0);
  auto op41 = model->addOperand(&type17);
  // Phase 2, operations
  static int32_t param2_init[] = {3};
  model->setOperandValue(param2, param2_init, sizeof(int32_t) * 1);
  static int32_t param3_init[] = {3};
  model->setOperandValue(param3, param3_init, sizeof(int32_t) * 1);
  static bool8 layout_init[] = {true};
  model->setOperandValue(layout, layout_init, sizeof(bool8) * 1);
  model->addOperation(ANEURALNETWORKS_RESIZE_BILINEAR, {op11, param2, param3, layout}, {op41});
  // Phase 3, inputs and outputs
  model->identifyInputsAndOutputs(
    {op11},
    {op41});
  assert(model->isValid());
}

inline bool is_ignored_nchw_float16_2(int i) {
  static std::set<int> ignore = {};
  return ignore.find(i) != ignore.end();
}

void CreateModel_dynamic_output_shape_nhwc_2(Model *model) {
  OperandType type0(Type::BOOL, {});
  OperandType type12(Type::TENSOR_FLOAT32, {0, 0, 0, 0});
  OperandType type3(Type::INT32, {});
  OperandType type4(Type::TENSOR_FLOAT32, {1, 2, 2, 2});
  // Phase 1, operands
  auto op11 = model->addOperand(&type4);
  auto param2 = model->addOperand(&type3);
  auto param3 = model->addOperand(&type3);
  auto layout = model->addOperand(&type0);
  auto op41 = model->addOperand(&type12);
  // Phase 2, operations
  static int32_t param2_init[] = {3};
  model->setOperandValue(param2, param2_init, sizeof(int32_t) * 1);
  static int32_t param3_init[] = {3};
  model->setOperandValue(param3, param3_init, sizeof(int32_t) * 1);
  static bool8 layout_init[] = {false};
  model->setOperandValue(layout, layout_init, sizeof(bool8) * 1);
  model->addOperation(ANEURALNETWORKS_RESIZE_BILINEAR, {op11, param2, param3, layout}, {op41});
  // Phase 3, inputs and outputs
  model->identifyInputsAndOutputs(
    {op11},
    {op41});
  assert(model->isValid());
}

inline bool is_ignored_dynamic_output_shape_nhwc_2(int i) {
  static std::set<int> ignore = {};
  return ignore.find(i) != ignore.end();
}

void CreateModel_dynamic_output_shape_nhwc_relaxed_2(Model *model) {
  OperandType type0(Type::BOOL, {});
  OperandType type12(Type::TENSOR_FLOAT32, {0, 0, 0, 0});
  OperandType type3(Type::INT32, {});
  OperandType type4(Type::TENSOR_FLOAT32, {1, 2, 2, 2});
  // Phase 1, operands
  auto op11 = model->addOperand(&type4);
  auto param2 = model->addOperand(&type3);
  auto param3 = model->addOperand(&type3);
  auto layout = model->addOperand(&type0);
  auto op41 = model->addOperand(&type12);
  // Phase 2, operations
  static int32_t param2_init[] = {3};
  model->setOperandValue(param2, param2_init, sizeof(int32_t) * 1);
  static int32_t param3_init[] = {3};
  model->setOperandValue(param3, param3_init, sizeof(int32_t) * 1);
  static bool8 layout_init[] = {false};
  model->setOperandValue(layout, layout_init, sizeof(bool8) * 1);
  model->addOperation(ANEURALNETWORKS_RESIZE_BILINEAR, {op11, param2, param3, layout}, {op41});
  // Phase 3, inputs and outputs
  model->identifyInputsAndOutputs(
    {op11},
    {op41});
  // Phase 4: set relaxed execution
  model->relaxComputationFloat32toFloat16(true);
  assert(model->isValid());
}

inline bool is_ignored_dynamic_output_shape_nhwc_relaxed_2(int i) {
  static std::set<int> ignore = {};
  return ignore.find(i) != ignore.end();
}

void CreateModel_dynamic_output_shape_nhwc_float16_2(Model *model) {
  OperandType type0(Type::BOOL, {});
  OperandType type13(Type::TENSOR_FLOAT16, {0, 0, 0, 0});
  OperandType type14(Type::TENSOR_FLOAT16, {1, 2, 2, 2});
  OperandType type3(Type::INT32, {});
  // Phase 1, operands
  auto op11 = model->addOperand(&type14);
  auto param2 = model->addOperand(&type3);
  auto param3 = model->addOperand(&type3);
  auto layout = model->addOperand(&type0);
  auto op41 = model->addOperand(&type13);
  // Phase 2, operations
  static int32_t param2_init[] = {3};
  model->setOperandValue(param2, param2_init, sizeof(int32_t) * 1);
  static int32_t param3_init[] = {3};
  model->setOperandValue(param3, param3_init, sizeof(int32_t) * 1);
  static bool8 layout_init[] = {false};
  model->setOperandValue(layout, layout_init, sizeof(bool8) * 1);
  model->addOperation(ANEURALNETWORKS_RESIZE_BILINEAR, {op11, param2, param3, layout}, {op41});
  // Phase 3, inputs and outputs
  model->identifyInputsAndOutputs(
    {op11},
    {op41});
  assert(model->isValid());
}

inline bool is_ignored_dynamic_output_shape_nhwc_float16_2(int i) {
  static std::set<int> ignore = {};
  return ignore.find(i) != ignore.end();
}

void CreateModel_dynamic_output_shape_nchw_2(Model *model) {
  OperandType type0(Type::BOOL, {});
  OperandType type12(Type::TENSOR_FLOAT32, {0, 0, 0, 0});
  OperandType type3(Type::INT32, {});
  OperandType type4(Type::TENSOR_FLOAT32, {1, 2, 2, 2});
  // Phase 1, operands
  auto op11 = model->addOperand(&type4);
  auto param2 = model->addOperand(&type3);
  auto param3 = model->addOperand(&type3);
  auto layout = model->addOperand(&type0);
  auto op41 = model->addOperand(&type12);
  // Phase 2, operations
  static int32_t param2_init[] = {3};
  model->setOperandValue(param2, param2_init, sizeof(int32_t) * 1);
  static int32_t param3_init[] = {3};
  model->setOperandValue(param3, param3_init, sizeof(int32_t) * 1);
  static bool8 layout_init[] = {true};
  model->setOperandValue(layout, layout_init, sizeof(bool8) * 1);
  model->addOperation(ANEURALNETWORKS_RESIZE_BILINEAR, {op11, param2, param3, layout}, {op41});
  // Phase 3, inputs and outputs
  model->identifyInputsAndOutputs(
    {op11},
    {op41});
  assert(model->isValid());
}

inline bool is_ignored_dynamic_output_shape_nchw_2(int i) {
  static std::set<int> ignore = {};
  return ignore.find(i) != ignore.end();
}

void CreateModel_dynamic_output_shape_nchw_relaxed_2(Model *model) {
  OperandType type0(Type::BOOL, {});
  OperandType type12(Type::TENSOR_FLOAT32, {0, 0, 0, 0});
  OperandType type3(Type::INT32, {});
  OperandType type4(Type::TENSOR_FLOAT32, {1, 2, 2, 2});
  // Phase 1, operands
  auto op11 = model->addOperand(&type4);
  auto param2 = model->addOperand(&type3);
  auto param3 = model->addOperand(&type3);
  auto layout = model->addOperand(&type0);
  auto op41 = model->addOperand(&type12);
  // Phase 2, operations
  static int32_t param2_init[] = {3};
  model->setOperandValue(param2, param2_init, sizeof(int32_t) * 1);
  static int32_t param3_init[] = {3};
  model->setOperandValue(param3, param3_init, sizeof(int32_t) * 1);
  static bool8 layout_init[] = {true};
  model->setOperandValue(layout, layout_init, sizeof(bool8) * 1);
  model->addOperation(ANEURALNETWORKS_RESIZE_BILINEAR, {op11, param2, param3, layout}, {op41});
  // Phase 3, inputs and outputs
  model->identifyInputsAndOutputs(
    {op11},
    {op41});
  // Phase 4: set relaxed execution
  model->relaxComputationFloat32toFloat16(true);
  assert(model->isValid());
}

inline bool is_ignored_dynamic_output_shape_nchw_relaxed_2(int i) {
  static std::set<int> ignore = {};
  return ignore.find(i) != ignore.end();
}

void CreateModel_dynamic_output_shape_nchw_float16_2(Model *model) {
  OperandType type0(Type::BOOL, {});
  OperandType type13(Type::TENSOR_FLOAT16, {0, 0, 0, 0});
  OperandType type14(Type::TENSOR_FLOAT16, {1, 2, 2, 2});
  OperandType type3(Type::INT32, {});
  // Phase 1, operands
  auto op11 = model->addOperand(&type14);
  auto param2 = model->addOperand(&type3);
  auto param3 = model->addOperand(&type3);
  auto layout = model->addOperand(&type0);
  auto op41 = model->addOperand(&type13);
  // Phase 2, operations
  static int32_t param2_init[] = {3};
  model->setOperandValue(param2, param2_init, sizeof(int32_t) * 1);
  static int32_t param3_init[] = {3};
  model->setOperandValue(param3, param3_init, sizeof(int32_t) * 1);
  static bool8 layout_init[] = {true};
  model->setOperandValue(layout, layout_init, sizeof(bool8) * 1);
  model->addOperation(ANEURALNETWORKS_RESIZE_BILINEAR, {op11, param2, param3, layout}, {op41});
  // Phase 3, inputs and outputs
  model->identifyInputsAndOutputs(
    {op11},
    {op41});
  assert(model->isValid());
}

inline bool is_ignored_dynamic_output_shape_nchw_float16_2(int i) {
  static std::set<int> ignore = {};
  return ignore.find(i) != ignore.end();
}

