cmake_minimum_required(VERSION 3.8)
project(P2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp LoopLinkList.h LinkNode.h)
add_executable(P2 ${SOURCE_FILES})