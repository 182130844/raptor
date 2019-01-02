cmake_minimum_required(VERSION 3.10)

add_executable(raptor_test test_main.cc)

target_include_directories(raptor_test
    PUBLIC
    ../include
)