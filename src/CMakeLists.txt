target_sources(
  moirai_main
  PRIVATE main.cpp
)

target_sources(
  moirai
  PRIVATE application.cpp
          application.hpp
          debug.cpp
          debug.hpp
)

add_subdirectory(layers)
add_subdirectory(node)
