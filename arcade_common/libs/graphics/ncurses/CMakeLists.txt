add_library(arcade_ncurses SHARED
    export.cpp
    NCurses.cpp
)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
target_link_libraries(arcade_ncurses ${CURSES_LIBRARIES})
SET_TARGET_PROPERTIES(arcade_ncurses PROPERTIES PREFIX "")
target_include_directories(arcade_ncurses PUBLIC "./" "../../../lib/")

if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_compile_options(arcade_ncurses PRIVATE /W4)
elseif (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_compile_options(arcade_ncurses PRIVATE -Wall -Wextra -Wpedantic -fdiagnostics-color=always
)
endif()