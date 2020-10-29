cmake_minimum_required(VERSION 3.16)
project(linear_programming_solver)

set(CMAKE_CXX_STANDARD 20)

add_executable(linear_programming_solver src/main.cpp src/Solver.cpp src/Solver.h src/Loader.cpp src/Loader.h)