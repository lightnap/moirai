cmake_minimum_required(VERSION 3.20)

project(moirai)

cmake_policy(SET CMP0077 NEW) # Allows to configure subproject by overriding
                              # their options.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug) # We do not plan on releasing this at the moment.
set(MOIRAI_BUILD_TESTS OFF CACHE BOOL "Whether to build unit tests")

# CORE APPLICATION.
add_library(moirai SHARED)
target_include_directories(moirai PUBLIC src)
target_include_directories(moirai PUBLIC external)

# MAIN EXECUTABLE.
add_executable(moirai_main)
set_target_properties(moirai_main PROPERTIES OUTPUT_NAME "moirai")
set_target_properties(
  moirai_main PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
)
target_include_directories(moirai_main PRIVATE src)
target_link_libraries(moirai_main PRIVATE moirai)

add_subdirectory(src)

# UNIT TESTS.
if(MOIRAI_BUILD_TESTS)
  add_executable(moirai_tests)
  set_target_properties(
    moirai_tests PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
  )
  target_include_directories(
    moirai_tests PRIVATE src external external/catch2/src
  )

  target_link_libraries(moirai_tests PRIVATE moirai)

  add_subdirectory(test)
endif()

add_subdirectory(external)
