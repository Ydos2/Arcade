add_library(arcade_sdl2 SHARED
    export.cpp
    Sdl.cpp
)
SET_TARGET_PROPERTIES(arcade_sdl2 PROPERTIES PREFIX "")

target_include_directories(arcade_sdl2 PUBLIC "./" "../../../lib/")