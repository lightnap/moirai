#ifndef MOIRAI_SRC_LAYERS_CDATALAYERHPP_
#define MOIRAI_SRC_LAYERS_CDATALAYERHPP_

#include "node/c_node.hpp"

#include <cstdint>

namespace moirai
{
    static constexpr uint32_t MAX_NODES {128U};

    class cDataLayer
    {
      public:
        int32_t      add_node();
        void         set_node(int32_t node_index, sNode* node);
        const sNode* get_node(int32_t node_index);

        int32_t get_node_count();
        sNode*  get_node_array();

      private:
        sNode   _node_array[MAX_NODES];
        int32_t _node_count {0};
    };
}

#endif
