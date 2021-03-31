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

# set Verbose
#set(CMAKE_VERBOSE_MAKEFILE ON)

add_library(pacman SHARED
    arcade_common/libs/games/pacman/export.cpp
    arcade_common/libs/games/pacman/PacMan.cpp
)

target_include_directories(pacman PUBLIC "arcade_common/lib/" "arcade_common/libs/pacman")

add_library(ncurses SHARED
    arcade_common/libs/graphics/ncurses/export.cpp
    arcade_common/libs/graphics/ncurses/NCurses.cpp
)

target_include_directories(ncurses PUBLIC "arcade_common/lib/" "arcade_common/libs/ncurses")

add_library(sdl SHARED
    arcade_common/libs/graphics/sdl/export.cpp
    arcade_common/libs/graphics/sdl/Sdl.cpp
)

target_include_directories(sdl PUBLIC "arcade_common/lib/" "arcade_common/libs/sdl")

add_executable(arcade
    arcade_common/arcade/main.cpp
    arcade_common/arcade/Core.cpp
    arcade_common/arcade/SceneManager.cpp
    arcade_common/arcade/library/LibraryManager.cpp
    arcade_common/arcade/library/Library.cpp
    arcade_common/arcade/library/LibraryLoader.cpp
    arcade_common/arcade/library/LibrarySet.cpp
    arcade_common/arcade/Bios.cpp
    arcade_common/arcade/Scene.cpp
)

target_compile_features(arcade PRIVATE cxx_std_14)
target_link_libraries(arcade dl)
target_include_directories(arcade PUBLIC "arcade_common/lib/" "arcade_common/arcade")

if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_compile_options(arcade PRIVATE /W4)
elseif (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_compile_options(arcade PRIVATE -Wall -Wextra -Wpedantic -fdiagnostics-color=always
)
endif()