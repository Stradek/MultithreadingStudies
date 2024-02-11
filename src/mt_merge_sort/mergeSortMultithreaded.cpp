#include "mergeSortMultithreaded.h"
#include "mergeSort.h"

#include <cassert>

void MergeSortMT::topDownSplitMergeParallel(std::vector<int>& arrayB, size_t iBegin, size_t iEnd, std::vector<int>& arrayA, std::vector<std::thread>* threadPool = nullptr)
{
    assert(threadPool != nullptr, "threadPool must not be nullptr");
    assert(threadPool->size() >= 1, "threadPool must have at least 1 thread");

    if (iEnd - iBegin <= 1)
        return;

    size_t iMiddle = (iEnd + iBegin) / 2;

    if (threadPool->size() == 1)
    {
        MergeSort::topDownSplitMerge(arrayA, iBegin, iMiddle, arrayB);
        MergeSort::topDownSplitMerge(arrayA, iMiddle, iEnd, arrayB);
    }

    unsigned int threadsPerSplit = threadPool->size() / 2;

    std::thread t1(MergeSort::topDownSplitMerge, std::ref(arrayA), iBegin, iMiddle, std::ref(arrayB));
    std::thread t2(MergeSort::topDownSplitMerge, std::ref(arrayA), iMiddle, iEnd, std::ref(arrayB));

    t1.join();
    t2.join();

    // merge the resulting runs from arrayB back into arrayA
    MergeSort::topDownMerge(arrayB, iBegin, iMiddle, iEnd, arrayA);
}

void MergeSortMT::topDownMergeSortParallel(std::vector<int>& arrayToSort, std::vector<int>& outputSortedArray, std::vector<std::thread>* threadPool = nullptr)
{
    std::vector<int> workArray = arrayToSort;

    topDownSplitMergeParallel(arrayToSort, 0, arrayToSort.size(), workArray, threadPool);

    // Copy sorted elements to sortedArray
    outputSortedArray = workArray;
}