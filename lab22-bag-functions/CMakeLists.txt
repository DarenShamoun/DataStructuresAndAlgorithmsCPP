cmake_minimum_required(VERSION 3.12)

project(lab22 VERSION 1.0.0 LANGUAGES CXX)
include ("../common.cmake")

if(MSVC)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -EHa")
endif()
add_subdirectory(src)
add_subdirectory(test)

