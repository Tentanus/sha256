## CMake commands
### Make build directory
  ``` bash
  $> cmake -B build
  ```

## Running GoogleTest with CMake
### Build and Run All Tests
  ```bash
  $> cmake -B build
  $> cmake --build build
  $> cd build/test
  $> ctest
  ```

### Run a Specific Test (by name)
  ```bash
  $> cd build/test
  $> ctest -R MessageBlock_construction
  ```
Or run the test binary directly with a GTest filter:
  ```bash
  $> ./sha256_test_messageblock --gtest_filter=sha256.MessageBlock_construction
  ```

### Run All Tests in a Specific File
  ```bash
  $> ./sha256_test_messageblock  # runs all tests in that binary
  ```
Or filter by test suite:
  ```bash
  $> ./sha256_test_messageblock --gtest_filter=sha256.*
  ```

### Update Build Directory After CMake Changes
  ```bash
  $> cmake -B build
  $> cmake --build build
  ```

### Useful CMake and GTest Features
List all available tests:
  ```bash
  $> cd build/test
  $> ctest -N
  ```
Run tests with verbose output:
  ```bash
  $> ctest -V
  ```
Run tests in parallel (faster on multicore):
  ```bash
  $> ctest -j 4
  ```
Clean build directory:
  ```bash
  $> cmake --build build --target clean
  ```
Re-run failed tests only:
  ```bash
  $> ctest --rerun-failed
  ```
Remove the entire build directory (full clean):
  ```bash
  $> rm -rf build
  ```
Force all .cpp files to be rebuilt and relinked:
  ```bash
  $> cmake --build build --target clean
  $> cmake --build build
  ```
  Or, touch all source files to update their timestamps (forces rebuild on next build):
  ```bash
  $> find src/ -name '*.cpp' | xargs touch
  $> cmake --build build
  ```

## Understanding my own code
### Understanding MessageBlock
  ``` bash
  $> clang++ -I inc infodump/understanding/MessageBlock/ && ./a.out
  ```

### show bits in Operators 
  ``` bash
  $> clang++ -I inc infodump/show_bits.c && ./a.out
  ```