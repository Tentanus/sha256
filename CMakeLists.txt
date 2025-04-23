cmake_minimum_required(VERSION 3.22)
project(Gtest
  VERSION 1.0
  DESCRIPTION "A simple factorial project to get familiar with GoogleTest"
  LANGUAGES CXX
)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable testing for this project
include(GoogleTest)
enable_testing()

add_library(sha
  src/sha256.cpp
)

target_include_directories(
  sha
  PUBLIC
  "${CMAKE_CURRENT_SOURCE_DIR}/inc"
)

# Add library and application directories
add_subdirectory(test)