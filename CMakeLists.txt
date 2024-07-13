cmake_minimum_required(VERSION 3.28)
project(GameOfLife)

set(CMAKE_CXX_STANDARD 17)

add_library(GameOfLife STATIC GameOfLife.cpp)
