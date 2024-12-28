#include "c_application.hpp"

#include "layers/c_visual_layer.hpp"

#include <raylib/src/raylib.h>

#include <cstdint>
#include <cstdio>
#include <cstdlib>

namespace moirai
{
    namespace
    {
        CApplication* global_application {nullptr};
    }

    int32_t CApplication::run()
    {
        init();

        while (!WindowShouldClose())
        {
            update();
        }

        terminate();

        return EXIT_SUCCESS;
    }

    void CApplication::init()
    {
        InitWindow(800, 450, "moirai");
        SetTargetFPS(60);
    }

    void CApplication::update()
    {
        char window_title[32];
        std::sprintf(window_title, "morirai - %.3i FPS", GetFPS());
        SetWindowTitle(window_title);

        _visual_layer.draw();
    }

    void CApplication::terminate()
    {
        CloseWindow();
    }

    CVisualLayer* CApplication::get_visual_layer()
    {
        return &_visual_layer;
    }

    CApplication* get_app()
    {
        return global_application;
    }

    void set_app(CApplication* app)
    {
        global_application = app;
    }
}
