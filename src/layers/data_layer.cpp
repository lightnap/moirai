#include "data_layer.hpp"

#include <cstring>

namespace moirai
{
    cDataLayer::cDataLayer()
    {
        for (int32_t i {0}; i < MAX_NODES; i++)
        {
            _parents_array[i] = -1;
        }
    }

    int32_t cDataLayer::add_node()
    {
        int32_t return_value {_node_count};
        _node_count++;
        return return_value;
    }

    void cDataLayer::set_node(int32_t node_index, sNode* node)
    {
        _node_array[node_index] = *node;
    }

    const sNode* cDataLayer::get_node(int32_t node_index)
    {
        return &_node_array[node_index];
    }

    void cDataLayer::set_parent(int32_t child_index, int32_t parent_index)
    {
        _parents_array[child_index] = parent_index;
    }

    int32_t cDataLayer::get_node_count()
    {
        return _node_count;
    }
    sNode* cDataLayer::get_node_array()
    {
        return _node_array;
    }

    int32_t* cDataLayer::get_parents_array()
    {
        return _parents_array;
    }
}
