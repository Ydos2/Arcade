add_library(arcade_sdl2 SHARED
    export.cpp
    Sdl.cpp
)
SET_TARGET_PROPERTIES(arcade_sdl2 PROPERTIES PREFIX "")

target_include_directories(arcade_sdl2 PUBLIC "./" "../../../lib/")

if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_compile_options(arcade_sdl2 PRIVATE /W4)
elseif (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_compile_options(arcade_sdl2 PRIVATE -Wall -Wextra -Wpedantic -fdiagnostics-color=always
)
endif()