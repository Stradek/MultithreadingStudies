/*
    Copyright (c) 2024 Piotr Stradowski. All rights reserved.
    Software distributed under the permissive MIT License.
*/

#pragma once

#include <vector>
#include <thread>

class MergeSortMT
{
public:
    static void topDownMergeSortParallel(std::vector<int>& arrayToSort, std::vector<int>& outputSortedArray);
private:
    static void topDownSplitMergeParallel(std::vector<int>& arrayB, size_t iBegin, size_t iEnd, std::vector<int>& arrayA);
};