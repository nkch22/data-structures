cmake_minimum_required(VERSION 3.28)
project(ds_lib C)

set(CMAKE_C_STANDARD 99)

include_directories(include)

add_library(ds STATIC
        src/dynamic-array/dynamic-array.c
        src/stack/stack.c
        src/queue/queue.c
        src/linked-list/linked-list.c
)

add_executable(example src/main.c)
target_link_libraries(example ds)
