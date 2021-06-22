cmake_minimum_required(VERSION 3.17)
project(1-Sort)

set(CMAKE_CXX_STANDARD 14)

# 链接时指定程序可使用堆栈大小
MATH(EXPR stack_size "100*1024*1024")
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--stack=${stack_size}")

add_executable(1-Sort main.cpp Student.h)