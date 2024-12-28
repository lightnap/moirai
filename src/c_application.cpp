#include "c_application.hpp"

#include <raylib/src/raylib.h>

#include <cstdint>
#include <cstdlib>
#include <iostream>

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
        std::cout << "[LIGHTSAYS ^. .^] HELLO WORLD \n";

        InitWindow(800, 450, "my_first_window");
        SetTargetFPS(60);
    }

    void CApplication::update()
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("[LIGHTSAYS ^. .^] WELP, I'M A WINDOW NOW", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }

    void CApplication::terminate()
    {
        CloseWindow();
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
