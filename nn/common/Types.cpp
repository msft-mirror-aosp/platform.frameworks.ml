/*
 * Copyright (C) 2020 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "Types.h"

#include <android-base/logging.h>

#include <algorithm>
#include <cstddef>
#include <iterator>
#include <limits>
#include <optional>
#include <utility>
#include <vector>

#include "OperandTypes.h"
#include "OperationTypes.h"
#include "Result.h"

namespace android::nn {
namespace {

constexpr size_t safeDivideRoundedUp(size_t numerator, size_t denominator) {
    CHECK_NE(denominator, 0u);
    CHECK_LE(numerator, std::numeric_limits<size_t>::max() - denominator);
    return (numerator + denominator - 1) / denominator;
}

constexpr size_t safeMultiply(size_t a, size_t b) {
    if (b == 0) {
        return 0;
    }
    CHECK_LE(a, std::numeric_limits<size_t>::max() / b);
    return a * b;
}

std::vector<AlignedData> allocateAligned(const uint8_t* data, size_t length) {
    constexpr size_t kElementSize = sizeof(AlignedData);
    const size_t numberElements = safeDivideRoundedUp(length, kElementSize);
    std::vector<AlignedData> output(numberElements);
    std::memcpy(output.data(), data, length);
    return output;
}

}  // anonymous namespace

Model::OperandValues::OperandValues() {
    constexpr size_t kNumberBytes = 4 * 1024;
    constexpr size_t kElementSize = sizeof(AlignedData);
    constexpr size_t kNumberElements = safeDivideRoundedUp(kNumberBytes, kElementSize);
    mData.reserve(kNumberElements);
}

Model::OperandValues::OperandValues(const uint8_t* data, size_t length)
    : mData(allocateAligned(data, length)) {}

DataLocation Model::OperandValues::append(const uint8_t* data, size_t length) {
    const size_t offset = size();
    auto contents = allocateAligned(data, length);
    mData.insert(mData.end(), contents.begin(), contents.end());
    CHECK_LE(offset, std::numeric_limits<uint32_t>::max());
    CHECK_LE(length, std::numeric_limits<uint32_t>::max());
    return {.offset = static_cast<uint32_t>(offset), .length = static_cast<uint32_t>(length)};
}

const uint8_t* Model::OperandValues::data() const {
    return reinterpret_cast<const uint8_t*>(mData.data());
}

size_t Model::OperandValues::size() const {
    return safeMultiply(mData.size(), sizeof(AlignedData));
}

Capabilities::OperandPerformanceTable::OperandPerformanceTable(
        std::vector<OperandPerformance> operandPerformances)
    : mSorted(std::move(operandPerformances)) {}

Result<Capabilities::OperandPerformanceTable> Capabilities::OperandPerformanceTable::create(
        std::vector<OperandPerformance> operandPerformances) {
    const auto notUnique = [](const auto& lhs, const auto& rhs) { return !(lhs.type < rhs.type); };
    const bool isUnique = std::adjacent_find(operandPerformances.begin(), operandPerformances.end(),
                                             notUnique) == operandPerformances.end();
    if (!isUnique) {
        return NN_ERROR() << "Failed to create OperandPerformanceTable: Input must be sorted by "
                             "key (in ascending order), and there must be no duplicate keys";
    }

    return Capabilities::OperandPerformanceTable(std::move(operandPerformances));
}

Capabilities::PerformanceInfo Capabilities::OperandPerformanceTable::lookup(
        OperandType operandType) const {
    // Search for operand type in the sorted collection.
    constexpr auto cmp = [](const auto& performance, auto type) { return performance.type < type; };
    const auto it = std::lower_bound(mSorted.begin(), mSorted.end(), operandType, cmp);

    // If the operand type is found, return its corresponding info.
    if (it != mSorted.end() && it->type == operandType) {
        return it->info;
    }

    // If no performance info is defined, use the default value (float's max).
    return Capabilities::PerformanceInfo{};
}

const std::vector<Capabilities::OperandPerformance>&
Capabilities::OperandPerformanceTable::asVector() const {
    return mSorted;
}

}  // namespace android::nn
