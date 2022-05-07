cmake_minimum_required(VERSION 3.17)
project(ex2)

set(CMAKE_CXX_STANDARD 11)
include_directories(.)

add_executable(ex2 Player.cpp Card.cpp Mtmchkin.cpp test.cpp utilities.cpp)
