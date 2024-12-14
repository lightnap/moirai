
cmake_minimum_required(VERSION 3.14)

project(moirai)

add_executable(moirai)

set_target_properties(moirai PROPERTIES  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

add_subdirectory(src)

