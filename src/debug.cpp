#include "debug.hpp"

#include "layers/data_layer.hpp"
#include "node/node.hpp"

#include <cstdint>
#include <iostream>

namespace moirai::debug
{
    void print_data_layer(cDataLayer* data_layer)
    {
        std::cout << "[DEBUG]: Printing data layer\n";
        std::cout << "[DEBUG]: Number of created nodes: " << data_layer->get_node_count() << "\n";
        std::cout << "[DEBUG]: Printing all nodes\n";

        sNode* node_list {data_layer->get_node_array()};
        for (int32_t i {0}; i < data_layer->get_node_count(); i++)
        {
            std::cout << "[DEBUG]: Info on node " << i << "\n";
            print_node(&node_list[i]);
        }

        // std::cout << "[DEBUG]: Printing all links\n";
        //  print node graph, with just ids
    }

    void print_node(sNode* node)
    {
        std::cout << "Title: " << node->title << "\n";
        std::cout << "Position: (" << node->pos_x << "," << node->pos_y << ")\n";
        std::cout << "Size: (" << node->size_x << "," << node->size_y << ")\n";

        switch (node->status)
        {
            case sNode::eStatus::open:
            {
                std::cout << "Status: open\n";
                break;
            }
            case sNode::eStatus::in_progress:
            {
                std::cout << "Status: in progress\n";
                break;
            }
            case sNode::eStatus::done:
            {
                std::cout << "Status: done\n";
                break;
            }
        }
    }
}
