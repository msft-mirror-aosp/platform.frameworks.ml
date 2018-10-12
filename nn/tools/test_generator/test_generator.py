#!/usr/bin/python3

# Copyright 2017, The Android Open Source Project
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

"""NN model compiler

Contain classes definition and utilify functions for compiling models and
examples into NDK-based CTS and VTS unit tests.

Used by cts_generator.py, vts_generator.py, and slicing.py
"""

from __future__ import absolute_import
from __future__ import division
from __future__ import print_function
import argparse
import copy
from functools import reduce
import itertools
import math
import os
import re
import struct
import sys
import contextlib
import pprint
import numpy as np

def GetJointStr(l, sep=", ", method=str):
    return sep.join([method(i) for i in l])

# Print in C float literal format
def PrettyPrintAsFloat(x):
    s = str(float(x))
    if s.find(".") >= 0 or s.find("e") >= 0:
        return s + "f"
    else:
        return s + ".0f"

# Transform from original type to float32
def Dequantize(v, ty):
    v -= ty.zeroPoint
    if ty.scale != 0:
        v *= ty.scale
    return v

# Transform float32 to target data type
def Quantize(v, ty):
    if ty.scale != 0:
        v /= ty.scale
    v += ty.zeroPoint
    if not ty.IsFloat():
        v = np.round(v)
        v = int(v) if np.isscalar(v) else v.astype(int)
    if ty.type == "TENSOR_QUANT8_ASYMM":
        v = np.minimum(np.maximum(v, 0), 255)
    elif ty.type == "UINT32":
        v = np.maximum(v, 0)
    return v

@contextlib.contextmanager
def SmartOpen(filename=None, mode="w"):
    if filename and filename != '-':
        fh = open(filename, mode)
    else:
        fh = sys.stdout

    try:
        yield fh
    finally:
        if fh is not sys.stdout:
            fh.close()

# Tracking objects inside a model with a unique name
class NamedObject:
    existingNames = set()

    def __init__(self, *args, sep="_", showZero=False, startsFrom=0, skipRenaming=False):
        name = GetJointStr([i for i in args if i is not None and i != ""], sep=sep)
        if skipRenaming:
            self.name = name
            return
        # make the name unique by renaming with a suffix number
        uniqueName = name if showZero is False else name + sep + str(startsFrom)
        while uniqueName in self.__class__.existingNames:
            startsFrom += 1
            uniqueName = name + sep + str(startsFrom)
        self.__class__.existingNames.add(uniqueName)
        self.name = uniqueName

    def __str__(self):
        return self.name
    __repr__ = __str__

    # Since names are unique, objects with the same name are considered equal
    def __eq__(self, other):
        return isinstance(other, NamedObject) and self.name == other.name

    def __ne__(self, other):
        return not self.__eq__(other)

    def __hash__(self):
        return hash(self.name)

    def __lt__(self, other):
        return self.name < other.name

# Types, operands should all have a unique name since they share the same namespace
class NamedVariable(NamedObject):
    existingNames = set()
    def __init__(self, *args, sep="_", showZero=False, startsFrom=0, skipRenaming=False):
        NamedObject.__init__(self, *args, sep=sep, showZero=showZero,
            startsFrom=startsFrom, skipRenaming=skipRenaming)

# Global variables in the spec namespace such as CreateModel, is_ignored, and examples
class GlobalVariable(NamedVariable):
    def __init__(self, *args, skipRenaming=False):
        NamedObject.__init__(self, *args, startsFrom=1, skipRenaming=skipRenaming)

# Each test should have a unique name, but will not conflict with variables
class NamedTest(NamedObject):
    existingNames = set()
    def __init__(self, *args, startsFrom=0, skipRenaming=False):
        NamedObject.__init__(self, *args, startsFrom=1, skipRenaming=skipRenaming)

class Type(NamedVariable):
    typesMap = dict()
    typeLookup = {
        "INT32": "int32_t",
        "UINT32": "uint32_t",
        "FLOAT32": "float",
        "TENSOR_INT32": "int32_t",
        "TENSOR_FLOAT32": "float",
        "TENSOR_QUANT8_ASYMM": "uint8_t",
#     "OEM_SCALAR": this is service-defined.
        "TENSOR_OEM_BYTE": "uint8_t",
    }

    # types are named as "type0", "type1", ...
    def __init__(self, vt, dimensions, scale, zeroPoint, name="type", skipRenaming=False):
        NamedVariable.__init__(self, name, sep="", showZero=True, skipRenaming=skipRenaming)
        self.type = vt
        self.dimensions = dimensions
        self.scale = float(scale)
        self.zeroPoint = int(zeroPoint)

    # Factory for Type object, only create a new Type if requested type does
    # not have a match with all existing types
    @staticmethod
    def GetType(vt, dimensions, scale=0, zeroPoint=0):
        key = ",".join([vt, str(dimensions), str(scale), str(zeroPoint)])
        if key not in Type.typesMap:
            Type.typesMap[key] = Type(vt, dimensions, scale, zeroPoint)
        return Type.typesMap[key]

    @staticmethod
    def GetAllTypes():
        # sort to ensure a stable order when dumping the code
        return sorted(Type.typesMap.values())

    # For backward-compatibility
    @staticmethod
    def GetTypeFromString(vt, shape):
        dimensions, scale, zeroPoint = Type.GetParsedShape(shape)
        scale = float(scale)
        zeroPoint = int(zeroPoint)
        return Type.GetType(vt, dimensions, scale, zeroPoint)

    # For backward-compatibility
    @staticmethod
    def GetParsedShape(shape):
        # Parse shape
        if (shape != "" and shape != "{}"):
            left, sep, right = shape.partition('{')
            real_shape, sep, right = right.partition('}')
            shape = [int(x) for x in real_shape.split(",")]
            # left now looks like "0.0f, 127.5f, "
            scale, sep, zero_point = right.rpartition(',')
            if scale == "":
                if zero_point == "":
                    return shape, "0", "0"
                return shape, zero_point, "0"
            left, sep, scale = scale.partition(',')
            return shape, scale.replace("f", ""), zero_point
        else:
            return [], "0", "0"

    def GetNumberOfElements(self):
        return reduce(lambda x,y: x*y, self.dimensions, 1)

    def GetCppTypeString(self):
        return Type.typeLookup[self.type]

    def IsFloat(self):
        return self.GetCppTypeString() == "float"

    def GetElementByteSize(self):
        return 1 if self.GetCppTypeString() == "uint8_t" else 4

    def GetByteSize(self):
        return self.GetElementByteSize() * self.GetNumberOfElements()

    def GetDimensionsString(self):
        return "{" + GetJointStr(self.dimensions) + "}"

    def GetSignatureTuple(self):
        return (self.type, self.dimensions, self.scale, self.zeroPoint)

    # For backward-compatibility with slicing.py
    def GetRawShape(self):
        if self.scale == 0 and self.zeroPoint == 0:
            return self.GetDimensionsString()
        else:
            return GetJointStr([self.GetDimensionsString(), self.scale, self.zeroPoint])

# To track implicitly convertible parameter types
class ImplicitParameter():
    @staticmethod
    def ImplicitConvertion(value):
        if isinstance(value, Operand):
            return value
        for implicitType in ImplicitParameter.__subclasses__():
            if implicitType.IsCompatible(value):
                return implicitType("param", value)
        assert False, "%s not supported for implicit parameter"%value

# An operand that can be fed into operations. Also, an operand is always
# declared before operations.
class Operand(NamedVariable):

    def __init__(self, name, opType, value, backward=None, skipRenaming=False):
        NamedVariable.__init__(self, name, sep="", skipRenaming=skipRenaming)
        if type(opType) is str:
            self.type = Type.GetTypeFromString(opType, value)
            value = backward
        else:
            self.type = Type.GetType(*opType)
        self.SetValue(value)
        self.lifetime = "TEMPORARY_VARIABLE"
        self.ins = []
        self.outs = []

    def SetValue(self, value):
        self.value = value if type(value) is list or type(value) is tuple else [value]
        return self

    def SetValueFromNumpy(self, value):
        self.value = value.flatten().tolist()
        return self

    def GetValueAsNumpy(self):
        return np.array(self.value).reshape(self.type.dimensions)

    # Print value as cpp-style list initialization
    def GetListInitialization(self):
        assert self.value is not None, \
            "Trying to print operand %s with None value"%(str(self))
        if self.type.IsFloat():
            return "{%s}"%(GetJointStr(self.value, method=PrettyPrintAsFloat))
        else:
            return "{%s}"%(GetJointStr(self.value, method=lambda x: str(int(x))))

# Base class of user-defined input/output operand
class InOut(Operand):

    def __init__(self, name, opType, backward=None, skipRenaming=False):
        Operand.__init__(self, name, opType, backward, None, skipRenaming=skipRenaming)
        self.lifetime = "MODEL_INPUT"
        self.index = 0

    def Feed(self, value):
        self.SetValue(value[self] if type(value) is dict else value)
        return self

    def GetListInitialization(self):
        return "{%d, %s}"%(self.index, super().GetListInitialization())

# A user-declared input operand
class Input(InOut):
    def __init__(self, name, opType, backward=None, skipRenaming=False):
        InOut.__init__(self, name, opType, backward, skipRenaming=skipRenaming)
        self.lifetime = "MODEL_INPUT"

# A user-declared output operand
class Output(InOut):
    def __init__(self, name, opType, backward=None, skipRenaming=False):
        InOut.__init__(self, name, opType, backward, skipRenaming=skipRenaming)
        self.lifetime = "MODEL_OUTPUT"

# An output that we don't want to compare the results
class IgnoredOutput(Output):
    def __init__(self, name, opType, backward=None, skipRenaming=False):
        Output.__init__(self, name, opType, backward, skipRenaming=skipRenaming)
        self.lifetime = "MODEL_OUTPUT"
    def Feed(self, value):
        self.value = [0 for x in range(self.type.GetNumberOfElements())]
        return self

# An explicitly declared parameter
class Parameter(Operand):
    def __init__(self, name, opType, value, backward=None, skipRenaming=False):
        Operand.__init__(self, name, opType, value, backward, skipRenaming=skipRenaming)
        self.initializer = NamedVariable(str(self) + "_init")
        self.lifetime = "CONSTANT_REFERENCE" if Configuration.useSHM() else "CONSTANT_COPY"

# A shortcut for parameters of INT32
class Int32Scalar(Parameter, ImplicitParameter):
    def __init__(self, name, value):
        Parameter.__init__(self, name, ("INT32", []), int(value))
    @staticmethod
    def IsCompatible(value):
        return isinstance(value, int)

# A shortcut for parameters of FLOAT32
class Float32Scalar(Parameter, ImplicitParameter):
    def __init__(self, name, value):
        Parameter.__init__(self, name, ("FLOAT32", []), float(value))
    @staticmethod
    def IsCompatible(value):
        return isinstance(value, float)

# A shortcut for parameter of 1-D TENSOR_INT32
class Int32Vector(Parameter, ImplicitParameter):
    def __init__(self, name, value):
        Parameter.__init__(self, name, ("TENSOR_INT32", [len(value)]), [int(v) for v in value])
    @staticmethod
    def IsCompatible(value):
        if type(value) is not list and type(value) is not tuple:
            return False
        return all(isinstance(i, int) for i in value)

# A shortcut for parameter of 1-D TENSOR_FLOAT32
class Float32Vector(Parameter, ImplicitParameter):
    def __init__(self, name, value):
        Parameter.__init__(self, name, ("TENSOR_FLOAT32", [len(value)]), [float(v) for v in value])
    @staticmethod
    def IsCompatible(value):
        if type(value) is not list and type(value) is not tuple:
            return False
        return all(isinstance(i, float) for i in value)

# An explicitly declared intermediate result
class Internal(Operand):
    def __init__(self, name, opType, backward=None, skipRenaming=False):
        Operand.__init__(self, name, opType, backward, None, skipRenaming=skipRenaming)
        self.lifetime = "TEMPORARY_VARIABLE"

# An operation in a model, does not need a name
class Operation:

    def __init__(self, optype, ins, outs):
        self.optype = optype
        self.SetInputs(ins)
        self.SetOutputs(outs)

    # for the ease of debugging
    def __str__(self):
        insString = GetJointStr(self.ins)
        outsString = GetJointStr(self.outs)
        return "Operation %s: [%s] -> [%s]"%(self.optype, insString, outsString)
    __repr__ = __str__

    def SetInputs(self, ins):
        self.ins = [ImplicitParameter.ImplicitConvertion(i) for i in ins]
        for i in self.ins:
            i.outs.append(self)
        return self

    def SetOutputs(self, outs):
        self.outs = list(outs)
        for o in self.outs:
            o.ins.append(self)
        return self

    # For backward-compatibility with slicing.py
    # Get Python-ish dump for the op
    def PyDefinition(self):
        py_op_string = """Operation("{optype}", {inputs}).To({outputs})"""
        inputs = [str(x) for x in self.ins]
        inputs = ", ".join(inputs)
        assert len(self.outs) <= 1
        outputs = str(self.outs[0])
        ops = {"optype": self.optype, "inputs": inputs, "outputs": outputs}
        return py_op_string.format(**ops)

# Main interface
class Model:
    models = list()

    def __init__(self, name=None):
        self.name = name
        self.createFunctionName = GlobalVariable("CreateModel", self.name)
        self.createTestFunctionName = GlobalVariable("createTestModel", self.name)
        self.isIgnoredFunctionName = GlobalVariable("is_ignored", self.name)
        self.operations = []
        self.operands = []
        self.isRelaxed = False
        self.compiled = False
        self.dumped = False
        Model.models.append(self)

    def WithSuffix(self, *args):
        if all(n is None or n == "" for n in args):
            return self
        self.createFunctionName = GlobalVariable("CreateModel", self.name, *args)
        self.createTestFunctionName = GlobalVariable("createTestModel", self.name, *args)
        self.isIgnoredFunctionName = GlobalVariable("is_ignored", self.name, *args)
        return self

    def AddOperation(self, operation):
        self.operations.append(operation)
        for i in operation.ins:
            if i not in self.operands:
                self.operands.append(i)
        for o in operation.outs:
            if o not in self.operands:
                self.operands.append(o)
        return self

    def Operation(self, op_name, *args):
        return self.AddOperation(Operation(op_name, args, []))

    def To(self, *args):
        assert len(self.operations) > 0
        if type(args[0]) is tuple or type(args[0]) is list:
            outs = args[0]
        else:
            outs = args
        self.operations[-1].SetOutputs(outs)
        for o in outs:
            if o not in self.operands:
                self.operands.append(o)
        return self

    def RelaxedExecution(self, isRelaxed):
        self.isRelaxed = isRelaxed
        return self

    def GetInputs(self):
        return [i for i in self.operands if isinstance(i, Input)]

    def GetOutputs(self):
        return [o for o in self.operands if isinstance(o, Output)]

    def GetInputsIndex(self):
        return [i for i,op in enumerate(self.operands) if isinstance(op, Input)]

    def GetOutputsIndex(self):
        return [o for o,op in enumerate(self.operands) if isinstance(op, Output)]

    def GetIndexOfOperands(self, operands):
        return [self.operands.index(i) for i in operands]

    def GetIgnoredOutputs(self):
        return [o for o in self.operands if isinstance(o, IgnoredOutput)]

    def GetParameters(self):
        return [p for p in self.operands if isinstance(p, Parameter)]

    def GetEquivalentOperands(self, targets):
        return [self.operands[self.operands.index(t)] for t in targets]

    def UpdateEquivalentOperands(self, targets):
        for t in targets:
            self.operands[self.operands.index(t)] = t
        return self

    def TopologicalSortHelper(self, op, deps, visited):
        if op in visited:
            assert op not in deps, "Cycle detected in the graph"
        else:
            visited.add(op)
            for i in deps[op]:
                self.TopologicalSortHelper(i, deps, visited)
            self.operations.append(op)
            deps.pop(op)

    # Topological sort of the operations, and detect if there is a cycle is the graph
    def TopologicalSort(self):
        deps = {op: list() for op in self.operations}
        [deps[o].append(i) for op in self.operands for o in op.outs for i in op.ins]
        operations = self.operations.copy()
        self.operations = []
        visited = set()
        for op in operations:
            self.TopologicalSortHelper(op, deps, visited)

    def Compile(self):
        if self.compiled:
            return self
        # set input/output index for MixedTypedExample mapping
        for ind, i in enumerate(self.GetInputs()):
            i.index = ind
        for ind, o in enumerate(self.GetOutputs()):
            o.index = ind
        self.TopologicalSort()
        self.compiled = True
        return self

# To track implicitly convertible variation types
class ImplicitVariation:
    @staticmethod
    def ImplicitConvertion(value):
        if isinstance(value, ModelVariation):
            return value
        for implicitType in ImplicitVariation.__subclasses__():
            value = value if type(value) is tuple or type(value) is list else [value]
            if implicitType.IsCompatible(value[0]):
                var = implicitType(value[0])
                if len(value) > 1:
                    var.Identify(*value[1:])
                return var
        assert False, "%s not supported for implicit variation"%value[0]

# The base class for model variations
class ModelVariation:

    def __init__(self, name=None):
        self.targetOperands = {}
        self.targetParameters = []
        self.name = name

    def ApplyToHelper(self, model, args, feedDicts, transform):
        opVarList = []
        for op in model.GetEquivalentOperands(sorted(args.keys())):
            opVar = op
            feedDictsVar = []
            if isinstance(op, Input) or isinstance(op, Output):
                for feedDict in feedDicts:
                    op_tmp = copy.deepcopy(op)
                    if op_tmp in feedDict[0]:
                        opVar = transform(op_tmp.Feed(feedDict[0]), args[op_tmp])
                    elif op_tmp in feedDict[1]:
                        opVar = transform(op_tmp.Feed(feedDict[1]), args[op_tmp])
                    else:
                        assert False
                    feedDictsVar.append(opVar.value)
                assert type(op) == type(opVar), "Can not handle %s -> %s"%(type(op), type(opVar))
            else:
                opVar = transform(op, args[op])
                # handle Parameter -> Input
                if isinstance(opVar, Input) or isinstance(opVar, Output):
                    feedDictsVar = [opVar.value] * len(feedDicts)
            if isinstance(opVar, Input) or isinstance(opVar, Output):
                for feedDict, feedDictVar in zip(feedDicts, feedDictsVar):
                    if opVar in feedDict[1]:
                        feedDict[1][opVar] = feedDictVar
                    else:
                        feedDict[0][opVar] = feedDictVar
            opVarList.append(opVar)
        return opVarList

    # Make a deepcopy of the model and feedDicts, and apply the change
    def ApplyTo(self, modelOrigin, feedDictsOrigin):
        model, feedDicts = copy.deepcopy((modelOrigin, feedDictsOrigin))
        model.compiled = False
        model.dumped = False

        # get transformed operands and update feedDicts
        operandsVar = self.ApplyToHelper(
            model, self.targetOperands, feedDicts, self.TransformOperand)
        parametersVar = self.TransformParameters(
            model.GetEquivalentOperands(self.targetParameters))

        model = self.TransformModel(model)
        model.UpdateEquivalentOperands(operandsVar)
        model.UpdateEquivalentOperands(parametersVar)
        return model, feedDicts

    def IdentifyOperands(self, args=None):
        if args is None:
            return self
        self.targetOperands = args if type(args) is dict else {i: None for i in args}
        return self

    def IdentifyParameters(self, args=None):
        if args is None:
            return self
        self.targetParameters = args
        return self

    def Identify(self, operandArgs=None, paramArgs=None):
        self.IdentifyOperands(operandArgs).IdentifyParameters(paramArgs)
        return self

    # Set variation to its default name
    def SetToDefaultName(self):
        self.name = ""
        return self

    # Transform operands that are marked by IdentifyOperands()
    def TransformOperand(self, op, arg=None):
        return op

    # Transform operands that are marked as parameters by IdentifyParameters()
    def TransformParameters(self, parameters):
        return parameters

    # Transform the model
    def TransformModel(self, model):
        return model

# Default variation that does nothing
class DefaultVariation(ModelVariation):

    def __init__(self, name=None):
        ModelVariation.__init__(self, name=name)

    # For faster execution
    def ApplyTo(self, model, feedDicts):
        return model, feedDicts

# Convert operand data type
class DataTypeConverter(ModelVariation):

    def __init__(self, name=None):
        ModelVariation.__init__(self, name=name)

    def SetToDefaultName(self):
        # get all target types
        targetTypes = list(zip(*self.targetOperands.values()))[0]
        if "TENSOR_QUANT8_ASYMM" in targetTypes:
            self.name = "quant8"
        elif "TENSOR_INT32" in targetTypes:
            self.name = "int32"
        else:
            self.name = "float"
        return self

    def TransformOperand(self, op, arg=None):
        if len(arg) == 1:
            typeTuple = (arg[0], op.type.dimensions)
        else:
            typeTuple = (arg[0], op.type.dimensions, *arg[1:])
        # To handle Internal operands
        if op.value is None:
            op.type = Type.GetType(*typeTuple)
        else:
            v = Dequantize(op.GetValueAsNumpy().astype(np.float32), op.type)
            op.type = Type.GetType(*typeTuple)
            v = Quantize(v, op.type)
            op.SetValueFromNumpy(v)
        return op

# Convert model to turn on/off relaxed computation
class RelaxedModeConverter(ModelVariation, ImplicitVariation):

    def __init__(self, isRelaxed=True, name=None):
        ModelVariation.__init__(self, name=name)
        if isinstance(isRelaxed, bool):
            self.isRelaxed = isRelaxed
        else:
            assert RelaxedModeConverter.IsCompatible(isRelaxed.lower())
            self.isRelaxed = True

    @staticmethod
    def IsCompatible(value):
        return value.lower() in ["relaxed"]

    def SetToDefaultName(self):
        self.name = "relaxed" if self.isRelaxed else "float"
        return self

    def TransformModel(self, model):
        model.RelaxedExecution(self.isRelaxed)
        return model

# Convert data layout between "NHWC" amd "NCHW"
class DataLayoutConverter(ModelVariation, ImplicitVariation):

    def __init__(self, targetLayout="nchw", name=None):
        ModelVariation.__init__(self, name=name)
        self.targetLayout = targetLayout.lower()
        assert DataLayoutConverter.IsCompatible(self.targetLayout)
        self.perm = (0, 3, 1, 2) if self.targetLayout == "nchw" else (0, 2, 3, 1)
        self.enum = 1 if self.targetLayout == "nchw" else 0

    @staticmethod
    def IsCompatible(value):
        return value.lower() in ["nhwc", "nchw"]

    def SetToDefaultName(self):
        self.name = self.targetLayout
        return self

    def TransformOperand(self, op, arg=None):
        assert len(op.type.dimensions) == 4, \
            "Error converting layout of %s, can only apply transformation to 4-D tensor"%op
        # To handle Internal operands
        if op.value is not None:
            op.SetValueFromNumpy(op.GetValueAsNumpy().transpose(self.perm))
        newDim = [op.type.dimensions[i] for i in self.perm]
        op.type = Type.GetType(op.type.type, newDim, op.type.scale, op.type.zeroPoint)
        return op

    def TransformParameters(self, parameters):
        for p in parameters:
            p.SetValue(self.enum)
        return parameters

# Convert a Parameter to Input
class ParameterAsInputConverter(ModelVariation, ImplicitVariation):

    def __init__(self, arg="as_input", prefix="weight", name=None):
        ModelVariation.__init__(self, name=name)
        assert ParameterAsInputConverter.IsCompatible(arg.lower())
        self.prefix = prefix

    @staticmethod
    def IsCompatible(value):
        return value.lower() in ["as_input"]

    def SetToDefaultName(self):
        self.name = self.prefix + "_as_input"
        return self

    def TransformOperand(self, op, arg=None):
        assert isinstance(op, Parameter), "%s cannot be converted to Input."%type(op)
        newop = Input(op.name, op.type.GetSignatureTuple(), skipRenaming=True)
        newop.SetValue(op.value)
        return newop

# Convert Output based on activation
class ActivationConverter(ModelVariation, ImplicitVariation):
    # (Enum, low, high)
    actMap = {
        "none": (0, None, None),
        "relu": (1, 0.0, None),
        "relu1": (2, -1.0, 1.0),
        "relu6": (3, 0.0, 6.0),
    }
    def __init__(self, act="relu", name=None):
        ModelVariation.__init__(self, name=name)
        self.act = act.lower()
        assert ActivationConverter.IsCompatible(self.act)
        self.enum = ActivationConverter.actMap[self.act][0]
        self.low = ActivationConverter.actMap[self.act][1]
        self.high = ActivationConverter.actMap[self.act][2]

    @staticmethod
    def IsCompatible(value):
        return value.lower() in ActivationConverter.actMap.keys()

    def SetToDefaultName(self):
        self.name = self.act
        return self

    def TransformOperand(self, op, arg=None):
        assert isinstance(op, Output)
        v = op.GetValueAsNumpy()
        if self.low is not None:
            low = Quantize(self.low, op.type)
            v = np.maximum(v, low)
        if self.high is not None:
            high = Quantize(self.high, op.type)
            v = np.minimum(v, high)
        return op.SetValueFromNumpy(v)

    def TransformParameters(self, parameters):
        for p in parameters:
            p.SetValue(self.enum)
        return parameters

# An example is always attached to a model, and could have multiple variations
class Example:
    examples = []

    def __init__(self, *args, model=None, name=None):
        self.model = Model.models[-1] if model is None else model
        self.name = name
        self.feedDicts = []
        for feedDict in args:
            if type(feedDict) is tuple or type(feedDict) is list:
                self.feedDicts.append(feedDict)
            elif type(feedDict) is dict:
                self.feedDicts.append((
                    {i: feedDict[i] for i in self.model.GetInputs()},
                    {o: feedDict[o] for o in self.model.GetOutputs()}
                ))
            else:
                assert False
        self.variations = []
        Example.examples.append(self)

    # Main entrance of test generator
    @staticmethod
    def DumpAllExamples(DumpModel=None, model_fd=None,
                        DumpExample=None, example_fd=None,
                        DumpTest=None, test_fd=None):
        Example.CombineAllExamples()
        for example in Example.examples:
            example.Dump(DumpModel, model_fd, DumpExample, example_fd, DumpTest, test_fd)

    # Combine examples with the same model, same name, and same set of variations
    @staticmethod
    def CombineAllExamples():
        modelMap = {}
        newExamples = []
        for example in Example.examples:
            key = (example.model, example.name, tuple(tuple(e) for e in example.variations))
            if key in modelMap:
                modelMap[key].Combine(example)
            else:
                modelMap[key] = example
                newExamples.append(example)
        Example.examples = newExamples

    def AddVariations(self, *args, includeDefault=True, defaultName=None):
        self.variations.append([DefaultVariation(defaultName)] if includeDefault else [])
        self.variations[-1].extend(ImplicitVariation.ImplicitConvertion(i) for i in args)
        return self

    def AddNchw(self, ops, params, includeDefault=True, defaultName=None):
        var = DataLayoutConverter("nchw").Identify(ops, params)
        self.AddVariations(var, includeDefault=includeDefault, defaultName=defaultName)
        return self

    def AddRelaxed(self, isRelaxed=True, includeDefault=True, defaultName=None):
        var = RelaxedModeConverter(isRelaxed)
        self.AddVariations(var, includeDefault=includeDefault, defaultName=defaultName)
        return self

    def AddInput(self, ops, includeDefault=True, defaultName=None):
        var = ParameterAsInputConverter().Identify(ops)
        self.AddVariations(var, includeDefault=includeDefault, defaultName=defaultName)
        return self

    def AddRelu(self, ops, params, includeDefault=True, defaultName=None):
        var = ActivationConverter("relu").Identify(ops, params)
        self.AddVariations(var, includeDefault=includeDefault, defaultName=defaultName)
        return self

    def AddAllActivations(self, ops, params):
        var = [ActivationConverter(i).Identify(ops, params)
            for i in sorted(ActivationConverter.actMap.keys())]
        self.AddVariations(*var, includeDefault=False)
        return self

    def Combine(self, other):
        assert self.model is other.model, "Only examples targetting the same model can be combined"
        assert tuple(self.variations) == tuple(other.variations), \
            "Only examples with the same set of variations can be combined"
        assert self.name == other.name, "Only examples with the same name can be combined"
        self.feedDicts.extend(other.feedDicts)
        return self

    def Dump(self, DumpModel, model_fd, DumpExample, example_fd, DumpTest, test_fd):
        [v.SetToDefaultName() for vs in self.variations for v in vs if v.name is None]
        for variationList in itertools.product(*self.variations):
            # Apply variations
            modelOrigin, feedDictsOrigin = self.model, self.feedDicts
            for variation in variationList:
                self.model, self.feedDicts = variation.ApplyTo(self.model, self.feedDicts)
            # Concat names for test and examples
            varNames = [v.name for v in variationList]
            self.testName = NamedTest(FileNames.specName, self.model.name, self.name, *varNames)
            self.examplesName = GlobalVariable("examples", self.model.name, self.name, *varNames)
            self.model.WithSuffix(*varNames).Compile()
            # Dump files
            if DumpModel is not None and model_fd is not None:
                DumpModel(self.model, model_fd)
            if DumpExample is not None and example_fd is not None:
                DumpExample(self, example_fd)
            if DumpTest is not None and test_fd is not None:
                DumpTest(self, test_fd)
            # Restore model and feedDicts before variation
            self.model = modelOrigin
            self.feedDicts = feedDictsOrigin
        return self

    # For backward-compatibility with slicing.py
    # Similar to dump_dict, but in python. Used by the slicing tool
    # if referenced is not None, only print operands that are present there
    @staticmethod
    def py_dump_dict(d, referenced):
        ret = []
        for k, v in d.items():
            if referenced != None and k not in referenced:
                continue
            key = str(k)
            init = pprint.pformat(v)
            ret.append("%s: %s" % (key, init))
        return ", ".join(ret)

    # For backward-compatibility with slicing.py
    # similar to dump, but in python. Used by the slicing tool
    # if referenced is not None, only print operands that are present there
    @staticmethod
    def py_dump(example_file, override, referenced):
        Example.CombineAllExamples()
        if len(Example.examples[0].feedDicts) > 0:
            example_no = 0
            example_template = """\
input{no} = {{{inputs}}}
# Only executed during data collection phase
if collecting_data is True:
  Example((input{no}, {{{outputs}}}))
"""
        for i, o in Example.examples[0].feedDicts:
            print ('# Begin of an example', file = example_file)
            inputs = Example.py_dump_dict(i, referenced)
            output_list = []
            for k, v in override.items():
                output_list.append("%s: [0] * %d" % (k, v))
            outputs = ",".join(output_list)

            # TODO: handle >1 outputs
            for k, v in o.items():
                assert k.index == 0
            example_contents = {
                'no': example_no,
                'inputs': inputs,
                'outputs': outputs
            }
            print (example_template.format(**example_contents), file = example_file)

class FileNames:
    specFiles = []
    specNames = []
    modelFiles = []
    exampleFiles = []
    testFiles = []
    specFile = ""
    specName = ""
    modelFile = ""
    exampleFile = ""
    testFile = ""
    ctsFile = ""
    logFile = ""
    fileIndex = 0

    @staticmethod
    def InitializeFileLists(spec, model, example, test, cts="-", log=""):
        # get all spec files and target files
        if os.path.isfile(spec):
            FileNames.specFiles = [os.path.abspath(spec)]
        elif os.path.isdir(spec):
            FileNames.specFiles = sorted([os.path.abspath(os.path.join(spec, f))
                for f in os.listdir(spec) if f.endswith(".mod.py")])
        else:
            assert False, "%s is neither a file or a directory"%spec
        FileNames.specNames = [re.sub(r"\..*", "", os.path.basename(f))
            for f in FileNames.specFiles]
        FileNames.modelFiles = FileNames.ParseTargetFiles(model, ".model.cpp")
        FileNames.exampleFiles = FileNames.ParseTargetFiles(example, ".example.cpp")
        FileNames.testFiles = FileNames.ParseTargetFiles(test, ".mod.py.cpp")
        FileNames.ctsFile = os.path.abspath(cts) if cts != "-" else "-"
        FileNames.logFile = ", \"%s\""%log if log != "" else ""

    @staticmethod
    def ParseTargetFiles(arg, ext):
        numFiles = len(FileNames.specFiles)
        absPath = os.path.abspath(arg)
        if os.path.isfile(arg):
            assert numFiles == 1
            target = [absPath]
        elif os.path.isdir(arg):
            target = [os.path.join(absPath, f + ext) for f in FileNames.specNames]
        elif arg == "-":
            target = ["-"] * numFiles
        else:
            assert False, "%s is neither a file or a directory"%arg
        return target

    @staticmethod
    def NextFile():
        if FileNames.fileIndex >= len(FileNames.specFiles):
            return False
        FileNames.specFile = FileNames.specFiles[FileNames.fileIndex]
        FileNames.specName = FileNames.specNames[FileNames.fileIndex]
        FileNames.modelFile = FileNames.modelFiles[FileNames.fileIndex]
        FileNames.exampleFile = FileNames.exampleFiles[FileNames.fileIndex]
        FileNames.testFile = FileNames.testFiles[FileNames.fileIndex]
        FileNames.fileIndex += 1
        NamedObject.existingNames = set()
        NamedVariable.existingNames = set()
        NamedTest.existingNames = set()
        Type.typesMap = dict()
        Model.models = list()
        Example.examples = list()
        Configuration.use_shm_for_weights = False
        return True

class Configuration:
    use_shm_for_weights = False
    force_regenerate = False

    @staticmethod
    def useSHM():
        return Configuration.use_shm_for_weights
