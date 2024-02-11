/*
    Copyright (c) 2023 Piotr Stradowski. All rights reserved.
    Software distributed under the permissive MIT License.
*/

#include "mergeSort.h"
#include "jobScheduler.h"

#include <stdio.h>
#include <vector>
#include <thread>
#include <functional>

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
	printf("\n\n");
}

void testMergeSort(std::function<void(std::vector<int>&, std::vector<int>&)> mergeSortFunction)
{
	std::vector<int> numbersToSortArray;
	fillArrayWithRandomNumbers(numbersToSortArray, 10000);
	
	/*
	printf("Unsorted array:\n");
	printArray(numbersToSortArray);
	*/

	std::vector<int> sortedArray;

	// start time measurement
	std::chrono::high_resolution_clock::time_point start_time = std::chrono::high_resolution_clock::now();

	mergeSortFunction(numbersToSortArray, sortedArray);
	
	// end time measurement
	std::chrono::high_resolution_clock::time_point end_time = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(end_time - start_time);
	printf("Sorting time: %f\n", time_span.count());

	// test here if array is correctly sorted

	/*
	printf("Sorted array:\n");
	printArray(numbersToSortArray);
	*/
}

int main()
{
    srand(time(NULL));

    printf("Hello mad world!\n");

	printf("Testing one threaded merge sort:\n");
	testMergeSort(MergeSort::topDownMergeSort);

	// Create JobScheduler instance now to avoid wasting time during the test
	std::shared_ptr<JobScheduler> jobSchedulerInstance = JobScheduler::createInstance(4);

	printf("Testing multithreaded merge sort:\n");
	testMergeSort(MergeSortMT::topDownMergeSortParallel);

    return 0;
}