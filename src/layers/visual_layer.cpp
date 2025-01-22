#include "visual_layer.hpp"

#include "node/node.hpp"

#include <raylib/src/raylib.h>

namespace moirai
{
    namespace
    {
        constexpr int32_t CAMERA_SPEED {5};
        constexpr float   ZOOM_SPEED {0.05F};
    }

    cVisualLayer::cVisualLayer()
    {
        _camera.target = (Vector2) {0.0f, 0.0f};
        _camera.offset = (Vector2) {0.0f, 0.0f};
        _camera.rotation = 0.0f;
        _camera.zoom = 1.0f;
    }

    void cVisualLayer::draw(sDrawData* draw_data)
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("[LIGHTSAYS ^. .^] THIS IS THE BACKGROUND", 190, 200, 20, LIGHTGRAY);

        SetTextLineSpacing(LINE_SPACING);

        update_camera();

        BeginMode2D(_camera);
        for (int32_t i {0}; i < draw_data->node_count; i++)
        {
            sNode* node {&draw_data->node_array[i]};
            DrawRectangle(node->pos_x, node->pos_y, node->size_x, node->size_y, node->get_color());
            DrawText(node->title, node->pos_x + NODE_HORIZONTAL_MARGIN, node->pos_y + NODE_VERTICAL_MARGIN, NODE_TEXT_SIZE, BLACK);

            int32_t parent_index {draw_data->parents_array[i]};
            if (parent_index != -1)
            {
                sNode* parent_node {&draw_data->node_array[parent_index]};
                DrawLine(node->pos_x + node->size_x / 2, node->pos_y, parent_node->pos_x + parent_node->size_x / 2, parent_node->pos_y + parent_node->size_y, BLACK);
            }
        }
        EndMode2D();
        EndDrawing();
    }

    void cVisualLayer::update_camera()
    {
        if (IsKeyDown(KEY_D))
            _camera.target.x += CAMERA_SPEED;
        else if (IsKeyDown(KEY_A))
            _camera.target.x -= CAMERA_SPEED;

        if (IsKeyDown(KEY_W))
            _camera.target.y -= CAMERA_SPEED;
        else if (IsKeyDown(KEY_S))
            _camera.target.y += CAMERA_SPEED;

        _camera.zoom += ((float)GetMouseWheelMove() * ZOOM_SPEED);
        if (_camera.zoom > 3.0f)
            _camera.zoom = 3.0f;
        else if (_camera.zoom < 0.1f)
            _camera.zoom = 0.1f;
    }
}
