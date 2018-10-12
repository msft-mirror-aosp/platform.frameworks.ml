# Using the NN-API Test Generator

## Prerequisites

- Python3
- Numpy

## Writing a Test Specification

You should create new test specs in `nn/runtime/test/specs/<version>/` and name it with `.mod.py` suffix, so that other tools can automatically update the unit tests.

### Specifying Operands

#### Syntax

```
OperandType(name, (type, shape, <optional scale, zero point>), <optional initializer>)
```

For example,

```Python
# p1 is a 2-by-2 fp matrix parameter, with value [1, 2; 3, 4]
p1 = Parameter("param", ("TENSOR_FLOAT32", [2, 2]), [1, 2, 3, 4])

# i1 is a quantized input of shape (2, 256, 256, 3), with scale = 0.5, zero point = 128
i1 = Input("input", ("TENSOR_QUANT8_ASYMM", [2, 256, 256, 3], 0.5, 128))

# p2 is an Int32 scalar with value 1
p2 = Int32Scalar("act", 1)
```

#### OperandType

There are currently 10 operand types supported by the test generator.

- Input
- Output
    * IgnoredOutput, will not compare results in the test
- Parameter
    * Int32Scalar, shorthand for parameter with type INT32
    * Float32Scalar, shorthand for parameter with type FLOAT32
    * Int32Vector, shorthand for 1-D TENSOR_INT32 parameter
    * Float32Vector, shorthand for 1-D TENSOR_FLOAT32 parameter
- Internal, for model with multiple operations

### Specifying Models

#### Instantiate a model

```Python
# Instantiate a model
model = Model()

# Instantiate a model with a name
model2 = Model("model_name")
```

#### Add an operation

```
model.Operation(optype, i1, i2, ...).To(o1, o2, ...)
```

For example,

```Python
model.Operation("ADD", i1, i2, act).To(o1)
```

#### Use implicit operands

Simple scalar and 1-D vector parameters can now be directly passed to Operation constructor, and test generator will deduce the operand type from the value provided.

```Python
model.Operation("MEAN", i1, [1], 0) # axis = [1], keep_dims = 0
```

Note that, for fp values, the initializer should all be Python fp numbers, e.g. use `1.0` or `1.` instead of `1` for implicit fp operands.

### Specifying Inputs and Expected Outputs

The combination of inputs and expected outputs is called an example for a given model. An example is defined like

```Python
# Example 1, separate dictionary for inputs and outputs
input1 = {
    i1: [1, 2],
    i2: [3, 4]
}
output1 = {o1: [4, 6]}

# Example 2, combined dictionary
example2_values = {
    i1: [5, 6],
    i2: [7, 8],
    o1: [12, 14]
}

# Instantiate an example
Example((input1, output1), example2_values)
```

By default, examples will be attached to the most recent instantiated model. You can explicitly specify the target model, and optionally, the example name by

```Python
Example((input1, output1), example2_values, model=model, name="example_name")
```

### Specifying Variations

You can add variations to the example so that the test generator can automatically create multiple tests. Currently, 6 types of variation are supported:

- DefaultVariation, i.e. no variation
- DataTypeConverter
- DataLayoutConverter
- RelaxedModeConverter
- ParameterAsInputConverter
- ActivationConverter

#### DataTypeConverter

Convert input/parameter/output to the specified type, e.g. float32 -> quant8. The target data type for each operand to transform has to be explicitly specified. It is the spec writer's responsibility to ensure such conversion is valid.

```Python
converter = DataTypeConverter(name="variation_name").Identify({
    op1: (target_type, target_scale, target_zero_point),
    op2: (target_type, target_scale, target_zero_point),
    ...
})
```

#### DataLayoutConverter

Convert input/parameter/output between NHWC and NCHW. The caller need to provide a list of target operands to transform, and also the data layout parameter to set.

```Python
converter = DataLayoutConverter(target_data_layout, name="variation_name").Identify(
    [op1, op2, ...], [layout_parameter]
)
```

#### RelaxedModeConverter

Convert the model to enable/disable relaxed computation.

```Python
converter = RelaxedModeConverter(is_relaxed, name="variation_name")
```

#### ParameterAsInputConverter

Convert a certain parameter to model input, e.g. weight in CONV_2D. The caller need to provide a list of target operands to convert.

```Python
converter = ParameterAsInputConverter(name="variation_name").Identify(
    [op1, op2, ...]
)
```

#### ActivationConverter

Convert the output by certain activation, the original activation is assumed to be NONE. The caller need to provide a list of target operands to transform,  and also the activation parameter to set.

```Python
converter = ActivationConverter(name="variation_name").Identify(
    [op1, op2, ...], [act_parameter]
)
```

#### Add variation to example

Each example can have multiple groups of variations, and if so, will take the cartesian product of the groups. For example, suppose we declare a model with two groups, and each group has two variations: `[[default, nchw], [default, relaxed, quant8]]`. This will result in 6 examples: `[default, default], [default, relaxed], [default, quant8], [nchw, default], [nchw, relaxed], [nchw, quant8]`.

Use `AddVariations` to add a group of variations to the example

```Python
# Add two groups of variations [default, nchw] and [default, relaxed, quant8]
example.AddVariations(nchw).AddVariations(relaxed, quant8)
```

By default, when you add a group of variation, a unnamed default variation will be automatically included in the list. You can name the default variation by

```Python
example.AddVariations(nchw, defaultName="nhwc").AddVariations(relaxed, quant8)
```

Also, you can choose not to include default by

```Python
# Add two groups of variations [nchw] and [default, relaxed, quant8]
example.AddVariations(nchw, includeDefault=False).AddVariations(relaxed, quant8)
```

The example above will result in 3 examples: `[nchw, default], [nchw, relaxed], [nchw, quant8]`.

#### Some helper functions

The test generator provides several helper functions or shorthands to add commonly used group of variations.

```Python
# Each following group of statements are equivalent

example.AddVariations(DataLayoutConverter("nchw").Identify(op_list, parameters))
example.AddVariations(("nchw", op_list, parameters))
example.AddNchw(op_list, parameters)

example.AddVariations(ParameterAsInputConverter().Identify(op_list))
example.AddVariations(("as_input", op_list))
example.AddInput(op_list)

example.Addvariations(RelaxedModeConverter(True))
example.AddVariations("relaxed")
example.AddRelaxed()

example.AddVariations(ActivationConverter("relu").Identify(op_list, parameters))
example.AddVariations(("relu", op_list, parameters))
example.AddRelu(op_list, parameters)

example.AddVariations(
    ActivationConverter("relu").Identify(op_list, parameters),
    ActivationConverter("relu1").Identify(op_list, parameters),
    ActivationConverter("relu6").Identify(op_list, parameters))
example.AddVariations(
    ("relu", op_list, parameters),
    ("relu1", op_list, parameters),
    ("relu6", op_list, parameters))
example.AddAllActivations()
```

### A Complete Example

```Python
# Declare input, output, and parameters
i1 = Input("op1", "TENSOR_FLOAT32", "{1, 3, 4, 1}")
f1 = Parameter("op2", "TENSOR_FLOAT32", "{1, 3, 3, 1}", [1, 4, 7, 2, 5, 8, 3, 6, 9])
b1 = Parameter("op3", "TENSOR_FLOAT32", "{1}", [-200])
o1 = Output("op4", "TENSOR_FLOAT32", "{1, 3, 4, 1}")

# Instantiate a model and add CONV_2D operation
# Use implicit parameter for padding, stride, and activation
Model().Operation("CONV_2D", i1, f1, b1, 1, 1, 1, 1, layout).To(o1)

# Additional data type
quant8 = DataTypeConverter().Identify({
    i1: ("TENSOR_QUANT8_ASYMM", 0.5, 127),
    f1: ("TENSOR_QUANT8_ASYMM", 0.5, 127),
    b1: ("TENSOR_INT32", 0.25, 0),
    o1: ("TENSOR_QUANT8_ASYMM", 1.0, 50)
})

# Instantiate an example
example = Example({
    i1: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12],
    o1: [0, 0, 0, 0, 35, 112, 157, 0, 0, 34, 61, 0]
})

# Only use NCHW data layout
example.AddNchw([i1, f1, o1], [layout], includeDefault=False)

# Add two more groups of variations
example.AddInput([f1, b1]).AddVariations("relaxed", quant8)
```

The spec above will result in 6 tests.

## Generate Tests

Once you have your model ready, run

```
$ANDROID_BUILD_TOP/frameworks/ml/nn/runtime/test/specs/generate_test.sh
$ANDROID_BUILD_TOP/frameworks/ml/nn/runtime/test/specs/generate_vts_test.sh
```

It will read and generate all CTS/VTS unit tests based on spec files in `nn/runtime/test/specs/V1_*/*` if needed. CTS test generator is able to identify which spec files are modified since last generation and only regenerate those files to reduce compilation time. To force a regeneration, use `-f` flag.

```
$ANDROID_BUILD_TOP/frameworks/ml/nn/runtime/test/specs/generate_test.sh -f
```

If you only want to regenerate a certain set of files, simply append the file names to the end of the command, and optionally, use `-f` flag.

```
$ANDROID_BUILD_TOP/frameworks/ml/nn/runtime/test/specs/generate_test.sh -f file1.mod.py file2.mod.py ...
```

Rebuild with mm afterwards.
