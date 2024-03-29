# Personal multithreading studies in c++
## Description
Repository consists of multithreading project where I have sandbox for implementing multithreaded algorithms with my own JobScheduler class.

## Current projects
### Multithreaded Merge Sort [WIP]
#### Location: 
`src\MultithreadedMergeSort`
#### Description: 
This project shows comparison between single-threaded and multi-threaded merge sort implementations.
#### To-Do List:
For both implementations of merge sort:
  - [x] I have both single-threaded and multi-threaded implementations of merge sort working
  - [x] I have function to test duration of both implementations
  - [ ] I have function to test duration of both implementations with data set consisting of 7 test cases with entry size of: 10^1, 10^2, 10^3, ..., 10^7
  - [ ] I have unit tests that test both implementations of merge sort functions for output correctness
  
For multi-threaded merge sort
  - [x] I have job system working, stable for 100/100 multi-threaded merge sort tests
  - [ ] Multi-threaded merge sort can utilize job system inside all it's recursive functions
  - [ ] Multi-threaded merge sort has option for limiting job system utilization X level deep of recursive function
  - [ ] Multi-threaded merge sort limits job system utilization X level deep of recursive function, and uses algorithm that makes X statistically proven(with testing data) best limit for test case at relatively highest efficiency
  - [ ] Multi-threaded merge sort uses most optimal thread count for my hardware, and I have data that supports chosen thread count superiority in all test scenarios mentioned above


## Prerequisities
- CMake (look for proper version in CMakeLists.txt) 

## Build
### VisualStudio 2022 on Windows
1. Run `GenerateProjectVS2022.bat`
2. Open solution using `OpenProjectVS2022.bat`

### Other
1. $ gh repo clone Stradek/MultithreadingStudies
2. $ cd MultithreadingStudies
3. $ mkdir build
4. $ cd build
5. $ cmake .. -DCMAKE_BUILD_TYPE=Release
