cmake_minimum_required(VERSION 3.12)

project(critters-game VERSION 1.0.0 LANGUAGES CXX)
set (CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_STANDARD_REQUIRED YES)
set (CMAKE_CXX_EXTENSIONS OFF)

if (MSVC)
  add_compile_options(/W4)
else()
  add_compile_options(-Wall -Wextra -pedantic)
endif(MSVC)

include_directories(
  ${CMAKE_SOURCE_DIR}/include
)

add_subdirectory(src)

