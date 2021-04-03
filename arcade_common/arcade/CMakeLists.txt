add_executable(arcade
    main.cpp
)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/scene)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/library)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/core)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/error)

target_compile_features(arcade PRIVATE cxx_std_14)
target_link_libraries(arcade dl)
target_include_directories(arcade PUBLIC "./" "../lib/" "include/")

if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_compile_options(arcade PRIVATE /W4)
elseif (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_compile_options(arcade PRIVATE -Wall -Wextra -Wpedantic -fdiagnostics-color=always)
endif()