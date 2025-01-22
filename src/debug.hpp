#ifndef MOIRAR_SRC_DEBUG_HPP_
#define MOIRAR_SRC_DEBUG_HPP_

namespace moirai
{
    class cDataLayer;
    struct sNode;
}

namespace moirai::debug
{
    void print_data_layer(cDataLayer* data_layer);
    void print_node(sNode* node);
}

#endif
