cmake_minimum_required(VERSION 3.8)
project(P7)

set(CMAKE_CXX_STANDARD 11)

if (WIN32)
    set(DEFAULT_CHARSET utf8)
endif ()

set(SOURCE_FILES main.cpp)
add_executable(P7 ${SOURCE_FILES})