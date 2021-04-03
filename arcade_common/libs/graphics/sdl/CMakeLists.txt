add_library(arcade_sdl2 SHARED
    export.cpp
    Sdl.cpp
)
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
target_link_libraries(arcade_sdl2 ${SDL2_LIBRARIES})
SET_TARGET_PROPERTIES(arcade_sdl2 PROPERTIES PREFIX "")

target_include_directories(arcade_sdl2 PUBLIC "./" "../../../lib/")

if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_compile_options(arcade_sdl2 PRIVATE /W4)
elseif (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_compile_options(arcade_sdl2 PRIVATE -Wall -Wextra -Wpedantic -fdiagnostics-color=always
)
endif()