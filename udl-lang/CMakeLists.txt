cmake_minimum_required(VERSION 3.24)
project(udl-lang LANGUAGES CXX)

find_package(FLEX REQUIRED)
flex_target(scanner scanner.l "${CMAKE_CURRENT_BINARY_DIR}/scanner.cc")
