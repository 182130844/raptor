cmake_minimum_required(VERSION 3.10)

aux_source_directory(. RAPTOR_SRCS)

add_library(raptor STATIC ${RAPTOR_SRCS})

target_include_directories(raptor
    PUBLIC
    ../include
)