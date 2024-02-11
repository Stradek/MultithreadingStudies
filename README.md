# Personal multithreading studies in c++
## Description
Repository consists of multithreading project where I have sandbox for implementing multithreaded algorithms with my own JobScheduler class.

## Current projects
* Multithreaded Merge Sort: `src\mt_merge_sort`


## Prerequisities
* CMake (look for proper version in CMakeLists.txt) 

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
