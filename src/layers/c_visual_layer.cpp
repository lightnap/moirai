#include "c_visual_layer.hpp"

#include "node/c_node.hpp"

#include <raylib/src/raylib.h>

namespace moirai
{
    void cVisualLayer::draw(sDrawData* draw_data)
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("[LIGHTSAYS ^. .^] WELP, I'M A WINDOW NOW", 190, 200, 20, LIGHTGRAY);

        for (int32_t i {0}; i < draw_data->node_count; i++)
        {
            sNode* node {&draw_data->node_array[i]};
            DrawText(node->title, node->pos_x, node->pos_y, 10, BLACK);
        }

        EndDrawing();
    }
}
