target_sources(
  moirai_main
  PRIVATE main.cpp
)

target_sources(
  moirai
  PRIVATE c_application.cpp c_application.hpp
)

add_subdirectory(layers)
add_subdirectory(node)
