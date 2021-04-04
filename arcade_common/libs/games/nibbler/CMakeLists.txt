add_library(arcade_nibbler SHARED
    export.cpp
    Nibbler.cpp
)

SET_TARGET_PROPERTIES(arcade_nibbler PROPERTIES PREFIX "")
target_include_directories(arcade_nibbler PUBLIC "./" "../../../lib/")

if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_compile_options(arcade_nibbler PRIVATE /W4)
elseif (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_compile_options(arcade_nibbler PRIVATE -Wall -Wextra -Wpedantic -fdiagnostics-color=always
)
endif()