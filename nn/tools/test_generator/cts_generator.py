#!/usr/bin/python3

# Copyright 2018, The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

"""CTS testcase generator

Implements CTS test backend. Invoked by ml/nn/runtime/test/specs/generate_tests.sh;
See that script for details on how this script is used.

"""

from __future__ import absolute_import
from __future__ import division
from __future__ import print_function
import argparse
import math
import os
import re
import sys

# Stuff from test generator
import test_generator as tg
from test_generator import ActivationConverter
from test_generator import Configuration
from test_generator import DataTypeConverter
from test_generator import DataLayoutConverter
from test_generator import Example
from test_generator import Float32Scalar
from test_generator import Float32Vector
from test_generator import GetJointStr
from test_generator import IgnoredOutput
from test_generator import Input
from test_generator import Int32Scalar
from test_generator import Int32Vector
from test_generator import Internal
from test_generator import Model
from test_generator import Operand
from test_generator import Output
from test_generator import Parameter
from test_generator import ParameterAsInputConverter
from test_generator import RelaxedModeConverter
from test_generator import SmartOpen

def IndentedPrint(s, indent=2, *args, **kwargs):
    print('\n'.join([" " * indent + i for i in s.split('\n')]), *args, **kwargs)

# Take a model from command line
def ParseCmdLine():
    parser = argparse.ArgumentParser()
    parser.add_argument("spec", help="the spec file/directory")
    parser.add_argument(
        "-m", "--model", help="the output model file/directory", default="-")
    parser.add_argument(
        "-e", "--example", help="the output example file/directory", default="-")
    parser.add_argument(
        "-t", "--test", help="the output test file/directory", default="-")
    parser.add_argument(
        "-c", "--cts", help="the CTS TestGeneratedOneFile.cpp", default="-")
    parser.add_argument(
        "-f", "--force", help="force to regenerate all spec files", action="store_true")
    # for slicing tool
    parser.add_argument(
        "-l", "--log", help="the optional log file", default="")
    args = parser.parse_args()
    tg.FileNames.InitializeFileLists(
        args.spec, args.model, args.example, args.test, args.cts, args.log)
    Configuration.force_regenerate = args.force

def NeedRegenerate():
    if not all(os.path.exists(f) for f in \
        [tg.FileNames.modelFile, tg.FileNames.exampleFile, tg.FileNames.testFile]):
        return True
    specTime = os.path.getmtime(tg.FileNames.specFile) + 10
    modelTime = os.path.getmtime(tg.FileNames.modelFile)
    exampleTime = os.path.getmtime(tg.FileNames.exampleFile)
    testTime = os.path.getmtime(tg.FileNames.testFile)
    if all(t > specTime for t in [modelTime, exampleTime, testTime]):
        return False
    return True

# Write headers for generated files, which are boilerplate codes only related to filenames
def InitializeFiles(model_fd, example_fd, test_fd):
    fileHeader = "// clang-format off\n// Generated file (from: {spec_file}). Do not edit"
    testFileHeader = """\
#include "../../TestGenerated.h"\n
namespace {spec_name} {{
// Generated {spec_name} test
#include "{example_file}"
// Generated model constructor
#include "{model_file}"
}} // namespace {spec_name}\n"""
    # This regex is to remove prefix and get relative path for #include
    pathRegex = r".*frameworks/ml/nn/(runtime/test/)?"
    specFileBase = os.path.basename(tg.FileNames.specFile)
    print(fileHeader.format(spec_file=specFileBase), file=model_fd)
    print(fileHeader.format(spec_file=specFileBase), file=example_fd)
    print(fileHeader.format(spec_file=specFileBase), file=test_fd)
    print(testFileHeader.format(
        model_file=re.sub(pathRegex, "", tg.FileNames.modelFile),
        example_file=re.sub(pathRegex, "", tg.FileNames.exampleFile),
        spec_name=tg.FileNames.specName), file=test_fd)

# Dump is_ignored function for IgnoredOutput
def DumpCtsIsIgnored(model, model_fd):
    isIgnoredTemplate = """\
bool {is_ignored_name}(int i) {{
  static std::set<int> ignore = {{{ignored_index}}};
  return ignore.find(i) != ignore.end();\n}}\n"""
    print(isIgnoredTemplate.format(
        ignored_index=tg.GetJointStr(model.GetIgnoredOutputs(), method=lambda x: str(x.index)),
        is_ignored_name=str(model.isIgnoredFunctionName)), file=model_fd)

# Dump Model file for Cts tests
def DumpCtsModel(model, model_fd):
    assert model.compiled
    if model.dumped:
        return
    print("void %s(Model *model) {"%(model.createFunctionName), file=model_fd)

    # Phase 0: types
    for t in tg.Type.GetAllTypes():
        if t.scale == 0.0 and t.zeroPoint == 0:
            typeDef = "OperandType %s(Type::%s, %s);"%(t, t.type, t.GetDimensionsString())
        else:
            typeDef = "OperandType %s(Type::%s, %s, %s, %d);"%(
                t, t.type, t.GetDimensionsString(), tg.PrettyPrintAsFloat(t.scale), t.zeroPoint)
        IndentedPrint(typeDef, file=model_fd)

    # Phase 1: add operands
    print("  // Phase 1, operands", file=model_fd)
    for op in model.operands:
        IndentedPrint("auto %s = model->addOperand(&%s);"%(op, op.type), file=model_fd)

    # Phase 2: operations
    print("  // Phase 2, operations", file=model_fd)
    for p in model.GetParameters():
        paramDef = "static %s %s[] = %s;\nmodel->setOperandValue(%s, %s, sizeof(%s) * %d);"%(
            p.type.GetCppTypeString(), p.initializer, p.GetListInitialization(), p,
            p.initializer, p.type.GetCppTypeString(), p.type.GetNumberOfElements())
        IndentedPrint(paramDef, file=model_fd)
    for op in model.operations:
        IndentedPrint("model->addOperation(ANEURALNETWORKS_%s, {%s}, {%s});"%(
            op.optype, tg.GetJointStr(op.ins), tg.GetJointStr(op.outs)), file=model_fd)

    # Phase 3: add inputs and outputs
    print ("  // Phase 3, inputs and outputs", file=model_fd)
    IndentedPrint("model->identifyInputsAndOutputs(\n  {%s},\n  {%s});"%(
        tg.GetJointStr(model.GetInputs()), tg.GetJointStr(model.GetOutputs())), file=model_fd)

    # Phase 4: set relaxed execution if needed
    if (model.isRelaxed):
        print ("  // Phase 4: set relaxed execution", file=model_fd)
        print ("  model->relaxComputationFloat32toFloat16(true);", file=model_fd)

    print ("  assert(model->isValid());", file=model_fd)
    print ("}\n", file=model_fd)
    DumpCtsIsIgnored(model, model_fd)
    model.dumped = True

def DumpMixedType(operands, feedDict):
    typedMap = {}
    FeedAndGet = lambda op, d: op.Feed(d).GetListInitialization()
    # group the operands by type
    for operand in operands:
        typedMap.setdefault(operand.type.type, []).append(FeedAndGet(operand, feedDict))
    mixedTypeTemplate = """\
{{ // See tools/test_generator/include/TestHarness.h:MixedTyped
  // int -> FLOAT32 map
  {{{float32_map}}},
  // int -> INT32 map
  {{{int32_map}}},
  // int -> QUANT8_ASYMM map
  {{{uint8_map}}}\n}}"""
    return mixedTypeTemplate.format(
        float32_map=tg.GetJointStr(typedMap.get("TENSOR_FLOAT32", [])),
        int32_map=tg.GetJointStr(typedMap.get("TENSOR_INT32", [])),
        uint8_map=tg.GetJointStr(typedMap.get("TENSOR_QUANT8_ASYMM", []) +
                                 typedMap.get("TENSOR_OEM_BYTE", [])))

# Dump Example file for Cts tests
def DumpCtsExample(example, example_fd):
    print("std::vector<MixedTypedExample> %s = {"%(example.examplesName), file=example_fd)
    for inputFeedDict, outputFeedDict in example.feedDicts:
        print ('// Begin of an example', file = example_fd)
        print ('{', file = example_fd)
        inputs = DumpMixedType(example.model.GetInputs(), inputFeedDict)
        outputs = DumpMixedType(example.model.GetOutputs(), outputFeedDict)
        print ('//Input(s)\n%s,' % inputs , file = example_fd)
        print ('//Output(s)\n%s' % outputs, file = example_fd)
        print ('}, // End of an example', file = example_fd)
    print("};\n", file=example_fd)

# Dump Test file for Cts tests
def DumpCtsTest(example, test_fd):
    testTemplate = """\
TEST_F(GeneratedTests, {test_name}) {{
    execute({namespace}::{create_model_name},
            {namespace}::{is_ignored_name},
            {namespace}::{examples_name}{log_file});\n}}\n"""
    print(testTemplate.format(
        test_name=str(example.testName),
        namespace=tg.FileNames.specName,
        create_model_name=str(example.model.createFunctionName),
        is_ignored_name=str(example.model.isIgnoredFunctionName),
        examples_name=str(example.examplesName),
        log_file=tg.FileNames.logFile), file=test_fd)

if __name__ == '__main__':
    ParseCmdLine()
    while tg.FileNames.NextFile():
        if Configuration.force_regenerate or NeedRegenerate():
            exec (open(tg.FileNames.specFile, "r").read())
            print("Output CTS model: %s" % tg.FileNames.modelFile, file=sys.stderr)
            print("Output example:%s" % tg.FileNames.exampleFile, file=sys.stderr)
            print("Output CTS test: %s" % tg.FileNames.testFile, file=sys.stderr)
            with SmartOpen(tg.FileNames.modelFile) as model_fd, \
                 SmartOpen(tg.FileNames.exampleFile) as example_fd, \
                 SmartOpen(tg.FileNames.testFile) as test_fd:
                InitializeFiles(model_fd, example_fd, test_fd)
                Example.DumpAllExamples(
                    DumpModel=DumpCtsModel, model_fd=model_fd,
                    DumpExample=DumpCtsExample, example_fd=example_fd,
                    DumpTest=DumpCtsTest, test_fd=test_fd)
        else:
            print("Skip file: %s" % tg.FileNames.specFile, file=sys.stderr)
        with SmartOpen(tg.FileNames.ctsFile, mode="a") as cts_fd:
            print("#include \"../generated/tests/%s.cpp\""%os.path.basename(tg.FileNames.specFile),
                file=cts_fd)
