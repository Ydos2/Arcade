add_library(pacman SHARED
    export.cpp
    PacMan.cpp
)

target_include_directories(pacman PUBLIC "./" "../../../lib/")

if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_compile_options(pacman PRIVATE /W4)
elseif (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_compile_options(pacman PRIVATE -Wall -Wextra -Wpedantic -fdiagnostics-color=always
)
endif()