cmake_minimum_required(VERSION 3.25)
project(src)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(src
        font.cpp
        font.h
        game.cpp
        game.h
        main.cpp)
