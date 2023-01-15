cmake_minimum_required(VERSION 3.12)

project(lab27 VERSION 1.0.0 LANGUAGES CXX)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../../cmake")
include (prevent_source_builds)
include (clang_tidy)

add_executable(main bstree.h tree_node.h main.cpp)
add_executable(example search_example.cpp)