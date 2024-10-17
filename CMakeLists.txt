cmake_minimum_required(VERSION 3.28)
project(ds_practice C)

set(CMAKE_C_STANDARD 11)

include_directories(include)
add_executable(ds_practice src/main.c
        include/linked-list.h
        src/linked-list/linked-list.c)
