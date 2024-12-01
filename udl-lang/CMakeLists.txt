cmake_minimum_required(VERSION 3.24)
project(udl-lang LANGUAGES CXX)

file(GLOB_RECURSE SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

add_library(udl-lang STATIC ${SRC})

target_include_directories(udl-lang PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include/
)
