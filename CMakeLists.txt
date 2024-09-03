cmake_minimum_required(VERSION 3.6.0)
project(reversi_xt_2 VERSION 0.1.0 LANGUAGES C CXX)

add_executable(client main.cpp)

include(CTest)
enable_testing()