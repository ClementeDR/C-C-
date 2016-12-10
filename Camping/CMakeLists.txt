cmake_minimum_required(VERSION 3.6)
project(Camping)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")

set(SOURCE_FILES main.c camping.h camping.c)
add_executable(Camping ${SOURCE_FILES})