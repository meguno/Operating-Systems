cmake_minimum_required(VERSION 3.10)
project(lab1_OS)

set(CMAKE_CXX_STANDARD 98)

add_executable(lab1_OS lab1_OS.cpp employee.h)
add_executable(creator creator.cpp employee.h)
add_executable(reporter reporter.cpp employee.h)