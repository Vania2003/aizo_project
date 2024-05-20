cmake_minimum_required(VERSION 3.24)
project(AiZO)

set(CMAKE_CXX_STANDARD 20)

add_executable(AiZO main.cpp Time.cpp Time.h Sorter.cpp Sorter.h
        generatorRandom.h)
