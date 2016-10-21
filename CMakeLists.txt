cmake_minimum_required(VERSION 3.6)
project(algoAvancee)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES diamond.c)
add_executable(TP1 ${SOURCE_FILES})