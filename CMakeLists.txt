
cmake_minimum_required(VERSION 3.22.1)

project(GTASA_Simple_ModMenu LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(
    GTASA_SimpleMenu
    SHARED

    src/main.cpp
    src/menu.cpp
)

target_compile_options(
    GTASA_SimpleMenu
    PRIVATE
    -Wall
    -Wextra
    -Wpedantic
)

target_link_libraries(
    GTASA_SimpleMenu
    PRIVATE
    android
    log
)
