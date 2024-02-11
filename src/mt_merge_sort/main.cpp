/*
    Copyright (c) 2023 Piotr Stradowski. All rights reserved.
    Software distributed under the permissive MIT License.
*/

#include "mergeSort.h"

#include <stdio.h>
#include <vector>
#include <thread>


void fillArrayWithRandomNumbers(std::vector<int>& array, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
		array.push_back(rand() % 100);
	}
}

void printArray(const std::vector<int>& array)
{
    size_t size = array.size();

    for (size_t i = 0; i < size; i++)
    {
		printf("%d ", array[i]);
	}
	printf("\n");
}

int main()
{
    srand(time(NULL));

    printf("Hello mad world!\n");

    std::vector<int> numbersToSortArray;
    fillArrayWithRandomNumbers(numbersToSortArray, 100);
    
    printf("Unsorted array:\n");
    printArray(numbersToSortArray);
    printf("\n");

    std::vector<int> sortedArray;
    MergeSort::topDownMergeSort(numbersToSortArray, sortedArray);
    printf("Sorted array:\n");
    printArray(numbersToSortArray);

    return 0;
}