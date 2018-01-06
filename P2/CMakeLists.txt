cmake_minimum_required(VERSION 3.8)
project(P2)

set(CMAKE_CXX_STANDARD 11)

if (WIN32)
    set(CMAKE_CXX_FLAGS -fexec-charset=gbk)
endif ()

set(SOURCE_FILES main.cpp LoopLinkList.h LinkNode.h)
add_executable(P2 ${SOURCE_FILES})