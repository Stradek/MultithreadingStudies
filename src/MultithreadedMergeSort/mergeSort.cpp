/*
    Copyright (c) 2023 Piotr Stradowski. All rights reserved.
    Software distributed under the permissive MIT License.
*/

#include "mergeSort.h"

#include <cassert>

// algorithms from https://en.wikipedia.org/wiki/Merge_sort

// arrayToSort[] has the items to sort; outputSortedArray[] is a output array with sorted items.
void MergeSort::topDownMergeSort(std::vector<int>& arrayToSort, std::vector<int>& outputSortedArray)
{
    std::vector<int> workArray = arrayToSort;

    topDownSplitMerge(arrayToSort, 0, arrayToSort.size(), workArray);

    // Copy sorted elements to sortedArray
    outputSortedArray = workArray;
}

// Split arrayA[] into 2 runs, sort both runs into arrayB[], merge both runs from arrayB[] to arrayA[]
// iBegin is inclusive; iEnd is exclusive (A[iEnd] is not in the set).
void MergeSort::topDownSplitMerge(std::vector<int>& arrayB, size_t iBegin, size_t iEnd, std::vector<int>& arrayA)
{
    if (iEnd - iBegin <= 1)
        return;

    size_t iMiddle = (iEnd + iBegin) / 2;

    topDownSplitMerge(arrayA, iBegin, iMiddle, arrayB);
    topDownSplitMerge(arrayA, iMiddle, iEnd, arrayB);

    // merge the resulting runs from arrayB back into arrayA
    topDownMerge(arrayB, iBegin, iMiddle, iEnd, arrayA);
}

//  Left source half is arrayA[ iBegin:iMiddle-1].
// Right source half is arrayA[iMiddle:iEnd-1   ].
// Result is            arrayB[ iBegin:iEnd-1   ].
void MergeSort::topDownMerge(std::vector<int>& arrayB, size_t iBegin, size_t iMiddle, size_t iEnd, std::vector<int>& arrayA)
{
    size_t i = iBegin, j = iMiddle;
    // Copy sorted subarrays back to the workArray
    for (size_t k = iBegin; k < iEnd; k++) {
        if (i < iMiddle && (j >= iEnd || arrayA[i] <= arrayA[j])) {
            arrayB[k] = arrayA[i];
            i++;
        }
        else {
            arrayB[k] = arrayA[j];
            j++;
        }
    }
}