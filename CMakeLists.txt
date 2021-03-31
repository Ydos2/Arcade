cmake_minimum_required(VERSION 3.17)

if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    SET(CMAKE_CXX_COMPILER C:/MinGW/bin/g++.exe)
endif()

project(arcade
        VERSION 1.0.0
        DESCRIPTION "arcade"
        LANGUAGES CXX)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

add_library(pacman SHARED
    arcade_common/libs/games/pacman/export.cpp
    arcade_common/libs/games/pacman/PacMan.cpp
)

add_library(arcade_ncurses SHARED
    arcade_common/libs/graphics/ncurses/export.cpp
    arcade_common/libs/graphics/ncurses/NCurses.cpp
)
SET_TARGET_PROPERTIES(arcade_ncurses PROPERTIES PREFIX "")

add_library(arcade_sdl2 SHARED
    arcade_common/libs/graphics/sdl/export.cpp
    arcade_common/libs/graphics/sdl/Sdl.cpp
)
SET_TARGET_PROPERTIES(arcade_sdl2 PROPERTIES PREFIX "")

add_executable(arcade
    arcade_common/arcade/main.cpp
    arcade_common/arcade/Core.cpp
    arcade_common/arcade/SceneManager.cpp
    arcade_common/arcade/LibraryManager.cpp
)

target_compile_features(arcade PRIVATE cxx_std_14)

if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_compile_options(arcade PRIVATE /W4)
elseif (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_compile_options(arcade PRIVATE -Wall -Wextra -Wpedantic -fdiagnostics-color=always
)
endif()