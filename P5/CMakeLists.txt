cmake_minimum_required(VERSION 3.8)
project(P5)

set(CMAKE_CXX_STANDARD 11)

if (WIN32)
    set(DEFAULT_CHARSET utf8)
endif ()

set(SOURCE_FILES main.cpp test.txt)
add_executable(P5 ${SOURCE_FILES})