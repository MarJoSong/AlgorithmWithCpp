cmake_minimum_required(VERSION 3.10)

project(2-Search)

# 链接时指定程序可使用堆栈大小
MATH(EXPR stack_size "100*1024*1024")

if (WIN32)
    set(CMAKE_EXE_LINKER_FLAGS "-Wl,--stack=${stack_size}")
endif()

add_executable(${PROJECT_NAME} main.cpp)