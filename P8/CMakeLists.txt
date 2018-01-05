cmake_minimum_required(VERSION 3.9)
project(P8)

set(CMAKE_CXX_STANDARD 11)

if (WIN32)
    set(DEFAULT_CHARSET utf8)
endif ()

add_executable(P8 main.cpp)