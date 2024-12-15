include(FetchContent)
set(RAYLIB_VERSION 5.5)

FetchContent_Declare(
    raylib
    DOWNLOAD_EXTRACT_TIMESTAMP OFF
    URL https://github.com/raysan5/raylib/archive/tags/${RAYLIB_VERSION}.tar.gz
    SOURCE_DIR ${PROJECT_SOURCE_DIR}/external/raylib
)

FetchContent_GetProperties(raylib)
if (NOT raylib_populated)
    set(FETCHCONTENT_QUIET NO)
    set(GLFW_BUILD_WAYLAND ON CACHE BOOL "" FORCE)
    set(GLFW_BUILD_X11 OFF CACHE BOOL "" FORCE) 
    set(USE_WAYLAND ON CACHE BOOL "" FORCE)
    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(raylib)
endif()

target_link_libraries(moirai raylib)
