/*
    Copyright (c) 2024 Piotr Stradowski. All rights reserved.
    Software distributed under the permissive MIT License.
*/

#include "jobScheduler.h"

#include "mergeSort.h"
#include "mergeSortMultithreaded.h"


#include <cassert>

void MergeSortMT::topDownSplitMergeParallel(std::vector<int>& arrayB, size_t iBegin, size_t iEnd, std::vector<int>& arrayA)
{
    if (iEnd - iBegin <= 1)
        return;

    size_t iMiddle = (iEnd + iBegin) / 2;

    auto func = &MergeSort::topDownSplitMerge;

    auto jobSchedulerInstance = JobScheduler::getInstance();
    auto jobResult1 = jobSchedulerInstance->enqueueJob([=, &arrayA, &arrayB]() { func(arrayA, iBegin, iMiddle, arrayB); });
    auto jobResult2 = jobSchedulerInstance->enqueueJob([=, &arrayA, &arrayB]() { func(arrayA, iMiddle, iEnd, arrayB); });

    jobResult1.get();
    jobResult2.get();

    // merge the resulting runs from arrayB back into arrayA
    MergeSort::topDownMerge(arrayB, iBegin, iMiddle, iEnd, arrayA);
}

void MergeSortMT::topDownMergeSortParallel(std::vector<int>& arrayToSort, std::vector<int>& outputSortedArray)
{
    std::vector<int> workArray = arrayToSort;

    topDownSplitMergeParallel(arrayToSort, 0, arrayToSort.size(), workArray);

    // Copy sorted elements to sortedArray
    outputSortedArray = workArray;
}