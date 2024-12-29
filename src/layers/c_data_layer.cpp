#include "c_data_layer.hpp"

#include <cstring>

namespace moirai
{
    int32_t cDataLayer::add_node()
    {
        int32_t return_value {_node_count};
        _node_count++;
        return return_value;
    }

    void cDataLayer::set_node(int32_t node_index, sNode* node)
    {
        sNode* target_node {&_node_array[node_index]};
        strcpy(target_node->title, node->title);
        // TODO: If more data members are added to sNode, maybe do a copy constructor.
    }

    const sNode* cDataLayer::get_node(int32_t node_index)
    {
        return &_node_array[node_index];
    }

    int32_t cDataLayer::get_node_count()
    {
        return _node_count;
    }
    sNode* cDataLayer::get_node_array()
    {
        return _node_array;
    }
}
