cmake_minimum_required(VERSION 3.24)
project(udl-lang LANGUAGES CXX)

include(FetchContent)

FetchContent_Declare(
  string-span
  GIT_REPOSITORY https://github.com/jzcurious/string-span.git
  GIT_TAG v1.0.0
)

FetchContent_MakeAvailable(string-span)

file(GLOB_RECURSE SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

add_library(udl-lang STATIC ${SRC})

target_include_directories(udl-lang PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include/
)

target_link_libraries(udl-lang PRIVATE
    strspan
)
