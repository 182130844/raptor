cmake_minimum_required(VERSION 3.10)
project(raptor)

set(CMAKE_MACOSX_RPATH 1)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY dist)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY dist)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY dist)

set(GTEST_ROOT thirdparty/gtest)
set(GTEST_INCLUDE_PATH ${GTEST_ROOT}/googletest/include)
set(GTEST_LIB_PATH ${GTEST_ROOT}/lib)

add_subdirectory(src)