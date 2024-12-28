#include <iostream>

#include <raylib/src/raylib.h>

int main(void)
{
    std::cout << "[LIGHTSAYS ^. .^] HELLO WORLD \n";

    InitWindow(800, 450, "my_first_window");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("[LIGHTSAYS ^. .^] WELP, I'M A WINDOW NOW", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
