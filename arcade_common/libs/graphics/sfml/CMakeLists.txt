add_library(arcade_sfml SHARED
    export.cpp
    Sfml.cpp
)
SET_TARGET_PROPERTIES(arcade_sfml PROPERTIES PREFIX "")
target_include_directories(arcade_sfml PUBLIC "./" "../../../lib/")

if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_compile_options(arcade_sfml PRIVATE /W4)
elseif (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_compile_options(arcade_sfml PRIVATE -Wall -Wextra -Wpedantic -fdiagnostics-color=always
)
endif()