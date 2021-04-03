add_library(arcade_ncurses SHARED
    export.cpp
    NCurses.cpp
)
SET_TARGET_PROPERTIES(arcade_ncurses PROPERTIES PREFIX "")
target_include_directories(arcade_ncurses PUBLIC "./" "../../../lib/")

if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_compile_options(arcade_ncurses PRIVATE /W4)
elseif (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_compile_options(arcade_ncurses PRIVATE -Wall -Wextra -Wpedantic -fdiagnostics-color=always
)
endif()