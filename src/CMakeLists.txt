target_sources(
  moirai
  PRIVATE main.cpp c_application.cpp c_application.hpp
)

add_subdirectory(layers)
add_subdirectory(node)
