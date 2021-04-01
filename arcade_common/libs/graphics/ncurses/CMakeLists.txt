add_library(arcade_ncurses SHARED
    export.cpp
    NCurses.cpp
)
SET_TARGET_PROPERTIES(arcade_ncurses PROPERTIES PREFIX "")
target_include_directories(arcade_ncurses PUBLIC "./" "../../../lib/")