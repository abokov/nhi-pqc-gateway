cmake_minimum_required(VERSION 3.14)
project(nhi-pqc-gateway VERSION 1.0 LANGUAGES CXX)

# Require modern C++20 for advanced timing and memory features
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Create the src directory structure
file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Define the executable
add_executable(nhi-pqc-benchmark src/main.cpp)

# Enable maximum compiler warnings (A "Senior C++" best practice)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(nhi-pqc-benchmark PRIVATE -Wall -Wextra -Wpedantic -O3)
endif()

message(STATUS "Configured NHI PQC Gateway for C++20 High-Performance Build.")

