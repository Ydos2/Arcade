cmake_minimum_required(VERSION 3.17)

if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    SET(CMAKE_CXX_COMPILER C:/MinGW/bin/g++.exe)
endif()

project(arcade
        VERSION 1.0.0
        DESCRIPTION "arcade"
        LANGUAGES CXX
)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# set Verbose
#set(CMAKE_VERBOSE_MAKEFILE ON)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/arcade_common/libs)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/arcade_common/arcade)