cmake_minimum_required(VERSION 3.6)
project(Esercizi_23_11_2016)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c es1.c es2.c es3.c esercizi.h es4.c ex5.c es6.c fileloader.c)
add_executable(Esercizi_23_11_2016 ${SOURCE_FILES})