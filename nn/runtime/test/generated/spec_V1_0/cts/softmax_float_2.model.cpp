// Generated from softmax_float_2.mod.py
// DO NOT EDIT
// clang-format off
#include "TestGenerated.h"

namespace generated_tests::softmax_float_2 {

void CreateModel(Model *model) {
  OperandType type0(Type::TENSOR_FLOAT32, {2, 5});
  OperandType type1(Type::FLOAT32, {});
  // Phase 1, operands
  auto input = model->addOperand(&type0);
  auto beta = model->addOperand(&type1);
  auto output = model->addOperand(&type0);
  // Phase 2, operations
  static float beta_init[] = {1.0f};
  model->setOperandValue(beta, beta_init, sizeof(float) * 1);
  model->addOperation(ANEURALNETWORKS_SOFTMAX, {input, beta}, {output});
  // Phase 3, inputs and outputs
  model->identifyInputsAndOutputs(
    {input},
    {output});
  assert(model->isValid());
}

bool is_ignored(int i) {
  static std::set<int> ignore = {};
  return ignore.find(i) != ignore.end();
}

} // namespace generated_tests::softmax_float_2
namespace generated_tests::softmax_float_2 {

void CreateModel_dynamic_output_shape(Model *model) {
  OperandType type0(Type::TENSOR_FLOAT32, {2, 5});
  OperandType type1(Type::FLOAT32, {});
  OperandType type2(Type::TENSOR_FLOAT32, {0, 0});
  // Phase 1, operands
  auto input = model->addOperand(&type0);
  auto beta = model->addOperand(&type1);
  auto output = model->addOperand(&type2);
  // Phase 2, operations
  static float beta_init[] = {1.0f};
  model->setOperandValue(beta, beta_init, sizeof(float) * 1);
  model->addOperation(ANEURALNETWORKS_SOFTMAX, {input, beta}, {output});
  // Phase 3, inputs and outputs
  model->identifyInputsAndOutputs(
    {input},
    {output});
  assert(model->isValid());
}

bool is_ignored_dynamic_output_shape(int i) {
  static std::set<int> ignore = {};
  return ignore.find(i) != ignore.end();
}

} // namespace generated_tests::softmax_float_2
namespace generated_tests::softmax_float_2 {

void CreateModel_all_inputs_as_internal(Model *model) {
  OperandType type0(Type::TENSOR_FLOAT32, {2, 5});
  OperandType type1(Type::FLOAT32, {});
  OperandType type3(Type::TENSOR_FLOAT32, {1});
  OperandType type4(Type::INT32, {});
  // Phase 1, operands
  auto input = model->addOperand(&type0);
  auto beta = model->addOperand(&type1);
  auto output = model->addOperand(&type0);
  auto input_tmp = model->addOperand(&type0);
  auto dummy = model->addOperand(&type3);
  auto param = model->addOperand(&type4);
  // Phase 2, operations
  static float beta_init[] = {1.0f};
  model->setOperandValue(beta, beta_init, sizeof(float) * 1);
  static float dummy_init[] = {0.0f};
  model->setOperandValue(dummy, dummy_init, sizeof(float) * 1);
  static int32_t param_init[] = {0};
  model->setOperandValue(param, param_init, sizeof(int32_t) * 1);
  model->addOperation(ANEURALNETWORKS_ADD, {input_tmp, dummy, param}, {input});
  model->addOperation(ANEURALNETWORKS_SOFTMAX, {input, beta}, {output});
  // Phase 3, inputs and outputs
  model->identifyInputsAndOutputs(
    {input_tmp},
    {output});
  assert(model->isValid());
}

bool is_ignored_all_inputs_as_internal(int i) {
  static std::set<int> ignore = {};
  return ignore.find(i) != ignore.end();
}

} // namespace generated_tests::softmax_float_2
namespace generated_tests::softmax_float_2 {

void CreateModel_all_inputs_as_internal_dynamic_output_shape(Model *model) {
  OperandType type0(Type::TENSOR_FLOAT32, {2, 5});
  OperandType type1(Type::FLOAT32, {});
  OperandType type2(Type::TENSOR_FLOAT32, {0, 0});
  OperandType type3(Type::TENSOR_FLOAT32, {1});
  OperandType type4(Type::INT32, {});
  // Phase 1, operands
  auto input = model->addOperand(&type0);
  auto beta = model->addOperand(&type1);
  auto output = model->addOperand(&type2);
  auto input_tmp = model->addOperand(&type0);
  auto dummy1 = model->addOperand(&type3);
  auto param1 = model->addOperand(&type4);
  // Phase 2, operations
  static float beta_init[] = {1.0f};
  model->setOperandValue(beta, beta_init, sizeof(float) * 1);
  static float dummy1_init[] = {0.0f};
  model->setOperandValue(dummy1, dummy1_init, sizeof(float) * 1);
  static int32_t param1_init[] = {0};
  model->setOperandValue(param1, param1_init, sizeof(int32_t) * 1);
  model->addOperation(ANEURALNETWORKS_ADD, {input_tmp, dummy1, param1}, {input});
  model->addOperation(ANEURALNETWORKS_SOFTMAX, {input, beta}, {output});
  // Phase 3, inputs and outputs
  model->identifyInputsAndOutputs(
    {input_tmp},
    {output});
  assert(model->isValid());
}

bool is_ignored_all_inputs_as_internal_dynamic_output_shape(int i) {
  static std::set<int> ignore = {};
  return ignore.find(i) != ignore.end();
}

} // namespace generated_tests::softmax_float_2
