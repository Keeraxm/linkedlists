cmake_minimum_required(VERSION 3.23.2)

project(linkedlists)

add_executable(${PROJECT_NAME}
    src/linkedlists.c
)

target_include_directories(${PROJECT_NAME}
    PUBLIC include
)

target_link_libraries(${PROJECT_NAME}
    ws2_32
    winmm
)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall)