cmake_minimum_required(VERSION 3.12) 
# The 'project name' is defined here
project(critters VERSION 1.0.0 LANGUAGES CXX)

find_package(Curses REQUIRED)

add_executable(${PROJECT_NAME} 
  ${CMAKE_SOURCE_DIR}/include/add_players.h
  ${CMAKE_SOURCE_DIR}/include/color.h
  ${CMAKE_SOURCE_DIR}/include/critter.h
  ${CMAKE_SOURCE_DIR}/include/direction.h
  add_players.cpp

  # add your source files here

)

#################################################################
#
#  Don't edit anything below this line
#
#################################################################

if(NOT EXISTS "${PROJECT_BINARY_DIR}/lib${CMAKE_PROJECT_NAME}.a")
  file(DOWNLOAD http://209.129.16.61/~dparillo/cisc187/critters/libcritters-game.a
    "${PROJECT_BINARY_DIR}/lib${CMAKE_PROJECT_NAME}.a"
    STATUS DOWNLOAD_STATUS
    EXPECTED_HASH MD5=478ebbd9fc9af29aafb6e6ad86f52a67
    )
  message(STATUS " critters library download status: ${DOWNLOAD_STATUS}")
endif()

target_link_libraries(${PROJECT_NAME} PUBLIC 
  ${CURSES_LIBRARIES}
  tinfo
  "${PROJECT_BINARY_DIR}/lib${CMAKE_PROJECT_NAME}.a"
  )

target_include_directories(${PROJECT_NAME} PUBLIC
  $<BUILD_INTERFACE:${CURSES_INCLUDE_DIR}>
  )





