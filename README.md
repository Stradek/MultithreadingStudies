# Personal multithreading studies in c++
## Description
Repository consists of multithreading project where I have sandbox for implementing multithreaded algorithms with my own JobScheduler class.

## Current projects
### Multithreaded Merge Sort [WIP]
Location: `src\mt_merge_sort`
Description: This project shows comparison between single-threaded merge sort and multi-threaded merge sort. I created job system that I queue two jobs that one calls MergeSort::topDownSplitMerge on one half of data set, and the other on second half of data set.
Finished project acceptance criteria:

#### For both implementations of merge sort:
  - [x] I have functions working
  - [ ] I have function to test duration of both implementations
  - [ ] I have function to test duration of both implementations with data set consisting of 7 test cases with entry size of: 10^1, 10^2, 10^3, ..., 10^7
  - [ ] I have unit tests that test both implementations of merge sort functions for output correctness
  
#### For multi-threaded merge sort
  - [x] I have job system working, stable for 100/100 multi-threaded merge sort tests
  - [ ] Multi-threaded merge sort can utilize job system inside all it's recursive functions
  - [ ] Multi-threaded merge sort has option for limiting job system utilization X level deep of recursive function, and is still thread-safe
  - [ ] Multi-threaded merge sort limits job system utilization X level deep of recursive function, and uses algorithm that makes X statistically proven(with testing data) best limit for test case at relatively highest efficiency
  - [ ] Multi-threaded merge sort uses most optimal thread count for my hardware, and I have data that supports chosen thread count superiority in all test scenarios mentioned above


## Prerequisities
- CMake (look for proper version in CMakeLists.txt) 

## Build
### VisualStudio 2022 on Windows
1. Run `GenerateProjectVS2022.bat`
2. Open solution using `OpenProjectVS2022.bat`

### Other
1. $ gh repo clone Stradek/multithreading_studies
2. $ cd multithreading_studies
3. $ mkdir build
4. $ cd build
5. $ cmake .. -DCMAKE_BUILD_TYPE=Release
