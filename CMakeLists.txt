cmake_minimum_required(VERSION 3.7)
project(ASD)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp hpp/ListM.cpp hpp/ListM.h hpp/ArrayQueue.cpp hpp/ArrayQueue.h hpp/TreeBST.cpp hpp/TreeBST.h)
add_executable(ASD ${SOURCE_FILES})