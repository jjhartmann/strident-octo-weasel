cmake_minimum_required(VERSION 3.3)
project(FindBeginningofLoopLinkedList)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(FindBeginningofLoopLinkedList ${SOURCE_FILES})