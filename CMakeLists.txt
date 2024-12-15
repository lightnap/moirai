
cmake_minimum_required(VERSION 3.20)

project(moirai)


cmake_policy(SET CMP0077 NEW) # Allows to configure subprohject by overriding their options.

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_BUILD_TYPE Debug) # We do not plan on releasing this at the moment.

add_executable(moirai)

set_target_properties(moirai PROPERTIES  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

add_subdirectory(external)
add_subdirectory(src)

