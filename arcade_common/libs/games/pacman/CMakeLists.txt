add_library(arcade_pacman SHARED
    export.cpp
    PacMan.cpp
)

SET_TARGET_PROPERTIES(arcade_pacman PROPERTIES PREFIX "")
target_include_directories(arcade_pacman PUBLIC "./" "../../../lib/")

if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_compile_options(arcade_pacman PRIVATE /W4)
elseif (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_compile_options(arcade_pacman PRIVATE -Wall -Wextra -Wpedantic -fdiagnostics-color=always
)
endif()