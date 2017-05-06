cmake_minimum_required(VERSION 3.7)
project(EightQueens)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp solver.cpp solver.h)
add_executable(EightQueens ${SOURCE_FILES})