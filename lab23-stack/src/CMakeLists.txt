cmake_minimum_required(VERSION 3.12)

project(lab23 VERSION 1.0.0 LANGUAGES CXX)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../../cmake")
include (prevent_source_builds)
include (clang_tidy)

add_executable(main bag.h stack.h main.cpp)
set_target_properties(main PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
	CXX_EXTENSIONS OFF
)
target_compile_options(main PRIVATE -Wall -Wextra -Werror -pedantic-errors)
