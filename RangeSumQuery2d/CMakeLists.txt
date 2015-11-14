cmake_minimum_required(VERSION 3.3)
project(RangeSumQuery2d)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(RangeSumQuery2d ${SOURCE_FILES})