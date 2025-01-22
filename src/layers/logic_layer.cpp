#include "logic_layer.hpp"

#include "node/node.hpp"

#include <cstdint>

namespace moirai
{

    void cLogicLayer::update_node_geometry(sNodePositionData* node_position_data)
    {
        for (uint32_t i {0U}; i < node_position_data->node_count; i++)
        {
            sNode* node {&node_position_data->node_array[i]};
            node->pos_x = i * (NODE_SIZE_X + HORIZONTAL_NODE_SEPARATION);
            node->pos_y = 230;
        }
    }
}
