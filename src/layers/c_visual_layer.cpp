#include "c_visual_layer.hpp"

#include <raylib/src/raylib.h>

namespace moirai
{
    void CVisualLayer::draw()
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("[LIGHTSAYS ^. .^] WELP, I'M A WINDOW NOW", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }
}
