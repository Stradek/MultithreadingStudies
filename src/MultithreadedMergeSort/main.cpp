/*
	Copyright (c) 2024 Piotr Stradowski. All rights reserved.
	Software distributed under the permissive MIT License.
*/

#include "mergeSort.h"
#include "jobScheduler.h"

#include <iostream>
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
		std::cout << array[i] << " ";
	}
	std::cout << "\n" << std::endl;
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
	std::cout << "Sorting time:" << time_span.count() << std::endl;

	// test here if array is correctly sorted

	/*
	printf("Sorted array:\n");
	printArray(numbersToSortArray);
	*/
}

int main()
{
    srand(time(NULL));

	std::cout << "Testing sigle-threaded merge sort:" << std::endl;
	testMergeSort(MergeSort::topDownMergeSort);

	// Create JobScheduler instance now to avoid wasting time during the test
	std::shared_ptr<JobScheduler> jobSchedulerInstance = JobScheduler::createInstance(4);

	std::cout << "Testing multithreaded merge sort:" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		std::cout << "Test " << i+1 << std::endl;
		testMergeSort(MergeSortMT::topDownMergeSortParallel);
	}

	std::getchar();

    return 0;
}