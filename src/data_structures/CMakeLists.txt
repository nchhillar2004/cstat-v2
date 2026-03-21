add_library(data_structures
    list.c
)

target_include_directories(data_structures PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
