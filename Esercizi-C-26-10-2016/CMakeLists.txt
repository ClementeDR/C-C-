cmake_minimum_required(VERSION 3.6)
project(Esercizi_C_26_10_2016)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c esercizic.c esercizic.h)
add_executable(Esercizi_C_26_10_2016 ${SOURCE_FILES})