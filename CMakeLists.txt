cmake_minimum_required(VERSION 3.7)
project(ASD)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp datatypes/list/LinkedList.cpp datatypes/list/LinkedList.h datatypes/list/ArrayList.cpp datatypes/list/ArrayList.h datatypes/queue/ArrayQueue.cpp datatypes/queue/ArrayQueue.h datatypes/tree/TreeBST.cpp datatypes/tree/TreeBST.h datatypes/tree/TreeD.cpp datatypes/tree/TreeD.h)
add_executable(ASD ${SOURCE_FILES})