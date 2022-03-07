cmake_minimum_required(VERSION 3.21)
project(conway)

set(CMAKE_CXX_STANDARD 14)

add_executable(conway main.cpp Conway.cpp Conway.h)
