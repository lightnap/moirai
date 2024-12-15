include(FetchContent)

set(RAYLIB_VERSION 5.5)


cmake_policy(SET CMP0077 NEW)

FetchContent_Declare(
    raylib
    DOWNLOAD_EXTRACT_TIMESTAMP OFF
    URL https://github.com/raysan5/raylib/archive/tags/${RAYLIB_VERSION}.tar.gz
)


message("[LIGHTSAYS ^. .^] STARTING FETCH CONTENT FOR RAYLIB")

FetchContent_GetProperties(raylib)
if (NOT raylib_populated)
    set(FETCHCONTENT_QUIET NO)
    set(GLFW_BUILD_WAYLAND ON CACHE BOOL "" FORCE)
    set(GLFW_BUILD_X11 OFF CACHE BOOL "" FORCE) 
    set(USE_WAYLAND ON CACHE BOOL "" FORCE)
    set(BUILD_EXAMPLES OFF CACHE BOOl "" FORCE)
    FetchContent_MakeAvailable(raylib)
endif()


message("[LIGHTSAYS ^. .^] FINISHING  FETCH CONTENT FOR RAYLIB")

target_link_libraries(moirai raylib)
