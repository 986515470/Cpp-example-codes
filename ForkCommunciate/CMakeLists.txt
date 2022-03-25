cmake_minimum_required(VERSION 3.17)
project(ForkCommunciate)

set(CMAKE_CXX_STANDARD 20)

add_executable(ForkCommunciate main.cpp communciate.cpp second.c two.cpp two.c third.c third.cpp)
add_executable(second second.c)
add_executable(third third.cpp)
add_executable(one one.cpp)
