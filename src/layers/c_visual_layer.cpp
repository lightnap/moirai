#include "c_visual_layer.hpp"

#include "c_application.hpp"
#include "layers/c_data_layer.hpp"
#include "node/c_node.hpp"

#include <raylib/src/raylib.h>

namespace moirai
{
    void cVisualLayer::draw()
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("[LIGHTSAYS ^. .^] WELP, I'M A WINDOW NOW", 190, 200, 20, LIGHTGRAY);

        sNode*  node_array {get_app()->get_data_layer()->get_node_array()};
        int32_t node_count {get_app()->get_data_layer()->get_node_count()};

        for (int32_t i {0}; i < node_count; i++)
        {
            char* node_title {node_array[i].title};
            DrawText(node_title, 190, 230 + 15 * i, 10, BLACK);
        }

        EndDrawing();
    }
}
