add_library(pacman SHARED
    export.cpp
    PacMan.cpp
)

target_include_directories(pacman PUBLIC "./" "../../../lib/")