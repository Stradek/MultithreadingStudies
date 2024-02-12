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
#include <random>
#include <numeric>
#include <iomanip>

void fillArrayWithRandomNumbers(std::vector<int>& array, size_t size)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(INT_MIN, INT_MAX);

	for (size_t i = 0; i < size; i++)
    {
		array.push_back(dis(gen));
	}
}

void printArray(const std::vector<int>& array)
{
    size_t size = array.size();

    for (size_t i = 0; i < size; i++)
    {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

std::chrono::duration<double> testMergeSortTime(std::function<void(std::vector<int>&, std::vector<int>&)> mergeSortFunction)
{
	std::vector<int> numbersToSortArray;
	fillArrayWithRandomNumbers(numbersToSortArray, 10000);
	
	std::vector<int> sortedArray;

	// start time measurement
	std::chrono::high_resolution_clock::time_point start_time = std::chrono::high_resolution_clock::now();

	mergeSortFunction(numbersToSortArray, sortedArray);
	
	// end time measurement
	std::chrono::high_resolution_clock::time_point end_time = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> executionTime = std::chrono::duration_cast<std::chrono::duration<double>>(end_time - start_time);
	std::cout << "Sorting time:" << executionTime.count() << std::endl;

	// test here if array is correctly sorted
	return executionTime;
}

std::chrono::duration<double> getAverageTime(std::chrono::duration<double>* timesArray, size_t entriesCount)
{
	return std::accumulate(timesArray, timesArray + entriesCount, std::chrono::duration<double>(0)) / entriesCount;
}

std::chrono::duration<double> getMaxTime(std::chrono::duration<double>* timesArray, size_t entriesCount)
{
	return *std::max_element(timesArray, timesArray + entriesCount);
}

std::chrono::duration<double> getMinTime(std::chrono::duration<double>* timesArray, size_t entriesCount)
{
	return *std::min_element(timesArray, timesArray + entriesCount);
}

void printTimeResults(std::chrono::duration<double> average, std::chrono::duration<double> max, std::chrono::duration<double> min)
{
	std::cout << "Average time: " << average.count() << "s\n"
		<< "Max time: " << max.count() << "s\n"
		<< "Min time: " << min.count() << "s\n";
}

int main()
{
    srand(time(NULL));

	const size_t testsCount = 100;

	std::cout << "Testing single-threaded merge sort:" << std::endl;
	std::chrono::duration<double> singleThreadedTestTimes[testsCount];
	for(int i = 0; i < testsCount; i++)
	{
		std::cout << "Test " << i+1 << std::endl;
		const std::chrono::duration<double> testTime = testMergeSortTime(MergeSort::topDownMergeSort);
		singleThreadedTestTimes[i] = testTime;
	}

	std::chrono::duration<double> singleThreadedAverage, singleThreadedMax, singleThreadedMin;
	singleThreadedAverage = getAverageTime(singleThreadedTestTimes, testsCount);
	singleThreadedMax = getMaxTime(singleThreadedTestTimes, testsCount);
	singleThreadedMin = getMinTime(singleThreadedTestTimes, testsCount);

	// Create JobScheduler instance now to avoid wasting time during the test
	std::shared_ptr<JobScheduler> jobSchedulerInstance = JobScheduler::createInstance(4);

	std::cout << "Testing multi-threaded merge sort:" << std::endl;
	std::chrono::duration<double> multiThreadedTestTimes[testsCount];
	for (int i = 0; i < testsCount; i++)
	{
		std::cout << "Test " << i + 1 << std::endl;
		const std::chrono::duration<double> testTime = testMergeSortTime(MergeSort::topDownMergeSort);
		multiThreadedTestTimes[i] = testTime;
	}

	std::chrono::duration<double> multiThreadedAverage, multiThreadedMax, multiThreadedMin;
	multiThreadedAverage = getAverageTime(multiThreadedTestTimes, testsCount);
	multiThreadedMax = getMaxTime(multiThreadedTestTimes, testsCount);
	multiThreadedMin = getMinTime(multiThreadedTestTimes, testsCount);

	std::cout << "\n\n" << "Single-threaded Merge Sort" << std::endl;
	printTimeResults(singleThreadedAverage, singleThreadedMax, singleThreadedMin);

	std::cout << "\n\n" << "Multi - Threaded Merge Sort" << std::endl;
	printTimeResults(multiThreadedAverage, multiThreadedMax, multiThreadedMin);

	double implementationSuperiorityRate = std::max(singleThreadedAverage, multiThreadedAverage) / min(singleThreadedAverage, multiThreadedAverage);
	if (singleThreadedAverage < multiThreadedAverage)
	{
		std::cout << "\n\n" << "Single-threaded implementation is currently ";
	}
	else
	{
		std::cout << "\n\n" << "Multi-threaded implementation is currently ";
	}

	std::cout << std::fixed << std::setprecision(1) << implementationSuperiorityRate << " times faster." << std::endl;

	std::getchar();
    return 0;
}