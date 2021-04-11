add_library(arcade_sfml SHARED
    export.cpp
    Sfml.cpp
)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML COMPONENTS network audio graphics window system REQUIRED)
if(SFML_FOUND)
  target_include_directories(arcade_sfml PUBLIC ${SFML_INCLUDE_DIR})
  target_link_libraries(arcade_sfml PUBLIC sfml-window sfml-graphics sfml-network sfml-system sfml-audio)
endif()

SET_TARGET_PROPERTIES(arcade_sfml PROPERTIES PREFIX "")
target_include_directories(arcade_sfml PUBLIC "./" "../../../lib/")

if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_compile_options(arcade_sfml PRIVATE /W4)
elseif (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_compile_options(arcade_sfml PRIVATE -Wall -Wextra -Wpedantic -fdiagnostics-color=always
)
endif()