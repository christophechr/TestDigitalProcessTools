# Generate a cmake to compile test.cpp

cmake_minimum_required(VERSION 3.0)
project(test_digital_process_tools)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(TEST_BINARY escalator)

set(SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/src/test.cpp
           ${CMAKE_CURRENT_SOURCE_DIR}/src/test.hpp
           ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

add_executable(${TEST_BINARY} ${SOURCE})