
cmake_minimum_required(VERSION 3.22.1)

project(GTASA_Simple_ModMenu LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(
    GTASA_SimpleMenu
    SHARED
    src/main.cpp
)

target_compile_options(
    GTASA_SimpleMenu
    PRIVATE
    -Wall
    -Wextra
)

target_link_libraries(
    GTASA_SimpleMenu
    android
    log
)
