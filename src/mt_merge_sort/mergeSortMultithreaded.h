#pragma once

#include <vector>
#include <thread>

class MergeSortMT
{
public:
    static void topDownMergeSortParallel(std::vector<int>& arrayToSort, std::vector<int>& outputSortedArray, std::vector<std::thread>* threadPool);
private:

    static void topDownSplitMergeParallel(std::vector<int>& arrayB, size_t iBegin, size_t iEnd, std::vector<int>& arrayA, std::vector<std::thread>* threadPool);
};