cmake_minimum_required(VERSION 3.9)
project(P9)

set(CMAKE_CXX_STANDARD 11)

if (WIN32)
    set(DEFAULT_CHARSET utf8)
endif ()

add_executable(P9 main.cpp)