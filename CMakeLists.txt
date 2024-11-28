cmake_minimum_required(VERSION 3.28)
project(ds_lib C)

# generate compile_commands.json for clangd to work properly
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE sources
    "${CMAKE_SOURCE_DIR}/src/*.c"    
    )
list(FILTER sources EXCLUDE REGEX "main.c")

message(${sources})

set(CMAKE_C_STANDARD 99)

add_library(ds STATIC
    ${sources}
)
target_include_directories(ds PUBLIC "${CMAKE_SOURCE_DIR}/include")

add_executable(example src/main.c)
target_link_libraries(example ds)
