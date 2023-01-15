cmake_minimum_required(VERSION 3.12)

project(project1 VERSION 1.0.0 LANGUAGES CXX)
include ("../common.cmake")

add_subdirectory(src)

# Remove the comment character from the front of the next line to build tests
# add_subdirectory(test)

