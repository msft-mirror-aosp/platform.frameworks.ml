// Generated from gather_higher_rank.mod.py
// DO NOT EDIT
// clang-format off
#include "TestGenerated.h"

namespace generated_tests::gather_higher_rank {

void CreateModel(Model *model);
bool is_ignored(int);
std::vector<::test_helper::MixedTypedExample>& get_examples();

TEST_F(GeneratedTests, gather_higher_rank) {
    execute(CreateModel,
            is_ignored,
            get_examples());
}

} // namespace generated_tests::gather_higher_rank
TEST_AVAILABLE_SINCE(V1_2, gather_higher_rank, generated_tests::gather_higher_rank::CreateModel)

namespace generated_tests::gather_higher_rank {

void CreateModel_relaxed(Model *model);
bool is_ignored_relaxed(int);
std::vector<::test_helper::MixedTypedExample>& get_examples_relaxed();

TEST_F(GeneratedTests, gather_higher_rank_relaxed) {
    execute(CreateModel_relaxed,
            is_ignored_relaxed,
            get_examples_relaxed());
}

} // namespace generated_tests::gather_higher_rank

namespace generated_tests::gather_higher_rank {

void CreateModel_quant8(Model *model);
bool is_ignored_quant8(int);
std::vector<::test_helper::MixedTypedExample>& get_examples_quant8();

TEST_F(GeneratedTests, gather_higher_rank_quant8) {
    execute(CreateModel_quant8,
            is_ignored_quant8,
            get_examples_quant8());
}

} // namespace generated_tests::gather_higher_rank
TEST_AVAILABLE_SINCE(V1_2, gather_higher_rank_quant8, generated_tests::gather_higher_rank::CreateModel_quant8)

namespace generated_tests::gather_higher_rank {

void CreateModel_int32(Model *model);
bool is_ignored_int32(int);
std::vector<::test_helper::MixedTypedExample>& get_examples_int32();

TEST_F(GeneratedTests, gather_higher_rank_int32) {
    execute(CreateModel_int32,
            is_ignored_int32,
            get_examples_int32());
}

} // namespace generated_tests::gather_higher_rank
TEST_AVAILABLE_SINCE(V1_2, gather_higher_rank_int32, generated_tests::gather_higher_rank::CreateModel_int32)

namespace generated_tests::gather_higher_rank {

void CreateModel_dynamic_output_shape(Model *model);
bool is_ignored_dynamic_output_shape(int);
std::vector<::test_helper::MixedTypedExample>& get_examples_dynamic_output_shape();

TEST_F(DynamicOutputShapeTest, gather_higher_rank_dynamic_output_shape) {
    execute(CreateModel_dynamic_output_shape,
            is_ignored_dynamic_output_shape,
            get_examples_dynamic_output_shape());
}

} // namespace generated_tests::gather_higher_rank

namespace generated_tests::gather_higher_rank {

void CreateModel_dynamic_output_shape_relaxed(Model *model);
bool is_ignored_dynamic_output_shape_relaxed(int);
std::vector<::test_helper::MixedTypedExample>& get_examples_dynamic_output_shape_relaxed();

TEST_F(DynamicOutputShapeTest, gather_higher_rank_dynamic_output_shape_relaxed) {
    execute(CreateModel_dynamic_output_shape_relaxed,
            is_ignored_dynamic_output_shape_relaxed,
            get_examples_dynamic_output_shape_relaxed());
}

} // namespace generated_tests::gather_higher_rank

namespace generated_tests::gather_higher_rank {

void CreateModel_dynamic_output_shape_quant8(Model *model);
bool is_ignored_dynamic_output_shape_quant8(int);
std::vector<::test_helper::MixedTypedExample>& get_examples_dynamic_output_shape_quant8();

TEST_F(DynamicOutputShapeTest, gather_higher_rank_dynamic_output_shape_quant8) {
    execute(CreateModel_dynamic_output_shape_quant8,
            is_ignored_dynamic_output_shape_quant8,
            get_examples_dynamic_output_shape_quant8());
}

} // namespace generated_tests::gather_higher_rank

namespace generated_tests::gather_higher_rank {

void CreateModel_dynamic_output_shape_int32(Model *model);
bool is_ignored_dynamic_output_shape_int32(int);
std::vector<::test_helper::MixedTypedExample>& get_examples_dynamic_output_shape_int32();

TEST_F(DynamicOutputShapeTest, gather_higher_rank_dynamic_output_shape_int32) {
    execute(CreateModel_dynamic_output_shape_int32,
            is_ignored_dynamic_output_shape_int32,
            get_examples_dynamic_output_shape_int32());
}

} // namespace generated_tests::gather_higher_rank

