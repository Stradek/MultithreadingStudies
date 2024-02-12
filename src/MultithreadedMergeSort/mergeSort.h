/*
    Copyright (c) 2024 Piotr Stradowski. All rights reserved.
    Software distributed under the permissive MIT License.
*/

#pragma once

#include "mergeSortMultithreaded.h"

#include <vector>
#include <thread>

class MergeSort
{
public:
    static void topDownMergeSort(std::vector<int>& arrayToSort, std::vector<int>& outputSortedArray);

    friend MergeSortMT;
private:
    static void topDownSplitMerge(std::vector<int>& arrayB, size_t iBegin, size_t iEnd, std::vector<int>& arrayA);
    static void topDownMerge(std::vector<int>& arrayB, size_t iBegin, size_t iMiddle, size_t iEnd, std::vector<int>& arrayA);
};