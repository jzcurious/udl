cmake_minimum_required(VERSION 3.24)
project(udl-lang LANGUAGES CXX)

include(FetchContent)

FetchContent_Declare(
  string-span
  GIT_REPOSITORY https://github.com/jzcurious/string-span.git
  GIT_TAG v1.0.0
)
FetchContent_MakeAvailable(string-span)

FetchContent_Declare(
  poly
  GIT_REPOSITORY https://github.com/jzcurious/poly.git
  GIT_TAG v1.0.0
)
FetchContent_MakeAvailable(poly)

FetchContent_Declare(
  cleverptr
  GIT_REPOSITORY https://github.com/jzcurious/cleverptr.git
  GIT_TAG v1.0.0
)
FetchContent_MakeAvailable(cleverptr)

file(GLOB_RECURSE SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

add_library(udl STATIC ${SRC})

target_include_directories(udl PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include/
)

target_link_libraries(udl PUBLIC
    strspan
    poly
    cleverptr
)
