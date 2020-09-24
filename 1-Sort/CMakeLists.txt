cmake_minimum_required(VERSION 3.17)
project(1-Sort)

set(CMAKE_CXX_STANDARD 14)

add_executable(1-Sort main.cpp Student.cpp Student.h SortTestHelper.h SelectionSort.h InsertionSort.h stdafx.h MergeSort.h)