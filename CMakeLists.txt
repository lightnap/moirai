cmake_minimum_required(VERSION 3.20)

project(moirai)

# Allows to configure subproject by overriding their options.
cmake_policy(SET CMP0077 NEW)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug) # We do not plan on releasing this at the moment.

set(MOIRAI_BUILD_TESTS OFF CACHE BOOL "Whether to build unit tests")

add_executable(moirai)
set_target_properties(
  moirai PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
)
target_include_directories(moirai PRIVATE src)
target_include_directories(moirai PRIVATE external)

add_subdirectory(src)

if(MOIRAI_BUILD_TESTS)
  add_executable(moirai_tests)
  set_target_properties(
    moirai_tests PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
  )
  target_include_directories(
    moirai_tests PRIVATE src external external/catch2/src
  )
  add_subdirectory(test)
endif()

add_subdirectory(external)
