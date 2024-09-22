# Set the minimum version of CMake required to build the project
cmake_minimum_required(VERSION 3.22)

# Name of the project and specify the language as C
project(MyCProject C)

# Set the C standard (optional)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# Manually specify the paths to the CUnit library and headers
set(CUNIT_INCLUDE_DIR /usr/include/CUnit)
set(CUNIT_LIBRARY /usr/lib/x86_64-linux-gnu/libcunit.so)

include_directories(${CUNIT_INCLUDE_DIR})
link_libraries(${CUNIT_LIBRARY})

# Include the "include" directory
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add the test executable (test cases and implementation file)
add_executable(test_math_operations tests/test_math_operations.c src/math_operations.c)

# Link the CUnit library to the test executable
target_link_libraries(test_math_operations ${CUNIT_LIBRARY})

