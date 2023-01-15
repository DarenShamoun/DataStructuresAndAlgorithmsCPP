cmake_minimum_required(VERSION 3.12)

project(lab1 VERSION 1.0.0 LANGUAGES CXX)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../../cmake")
include (prevent_source_builds)
include (clang_tidy)

add_library(lab1 echo.h echo.cpp)
add_executable(hello main.cpp)

target_link_libraries(hello PRIVATE lab1 project_options project_warnings)
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

target_link_libraries(${PROJECT_NAME} PRIVATE project_warnings)

