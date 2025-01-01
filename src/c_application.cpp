#include "c_application.hpp"

#include "layers/c_data_layer.hpp"
#include "layers/c_logic_layer.hpp"
#include "layers/c_visual_layer.hpp"

#include <raylib/src/raylib.h>

#include <cstdint>
#include <cstdio>
#include <cstdlib>

#include <cstring> // TODO: Remove this.

namespace moirai
{
    namespace
    {
        cApplication* global_application {nullptr};
    }

    int32_t cApplication::run()
    {
        init();

        while (!WindowShouldClose())
        {
            update();
        }

        terminate();

        return EXIT_SUCCESS;
    }

    void cApplication::init()
    {
        InitWindow(800, 450, "moirai");
        SetTargetFPS(60);

        // TODO: Remove this
        // We are adding nodes manually to see if things work.
        int32_t first_node_id = _data_layer.add_node();
        sNode   first_node;
        strcpy(first_node.title, "Node number 1");
        _data_layer.set_node(first_node_id, &first_node);

        int32_t second_node_id = _data_layer.add_node();
        sNode   second_node;
        strcpy(second_node.title, "I am the secon node!\nThis is second text");
        _data_layer.set_node(second_node_id, &second_node);
    }

    void cApplication::update()
    {
        char window_title[32];
        std::sprintf(window_title, "morirai - %.3i FPS", GetFPS());
        SetWindowTitle(window_title);

        sNodePositionData node_position_data;
        node_position_data.node_array = _data_layer.get_node_array();
        node_position_data.node_count = _data_layer.get_node_count();

        _logic_layer.update_node_geometry(&node_position_data);

        sDrawData draw_data;
        draw_data.node_array = _data_layer.get_node_array();
        draw_data.node_count = _data_layer.get_node_count();

        _visual_layer.draw(&draw_data);
    }

    void cApplication::terminate()
    {
        CloseWindow();
    }

    cVisualLayer* cApplication::get_visual_layer()
    {
        return &_visual_layer;
    }

    cLogicLayer* cApplication::get_logic_layer()
    {
        return &_logic_layer;
    }

    cDataLayer* cApplication::get_data_layer()
    {
        return &_data_layer;
    }

    cApplication* get_app()
    {
        return global_application;
    }

    void set_app(cApplication* app)
    {
        global_application = app;
    }
}
