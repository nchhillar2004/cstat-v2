cmake_minimum_required(VERSION 3.20)

project(cstat C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(
    src/data_structures
)

add_executable(cstat
    src/main.c
)

target_link_libraries(cstat
    data_structures
)
