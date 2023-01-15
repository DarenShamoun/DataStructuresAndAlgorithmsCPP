cmake_minimum_required(VERSION 3.12)

project(lab6 VERSION 1.0.0 LANGUAGES CXX)
include ("../common.cmake")

set (CMAKE_CXX_STANDARD_REQUIRED 11)

add_subdirectory(src)
add_subdirectory(test)

