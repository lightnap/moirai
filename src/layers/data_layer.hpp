#ifndef MOIRAI_SRC_LAYERS_DATALAYERHPP_
#define MOIRAI_SRC_LAYERS_DATALAYERHPP_

#include "node/node.hpp"

#include <cstdint>

namespace moirai
{
    static constexpr uint32_t MAX_NODES {128U};

    class cDataLayer
    {
      public:
        cDataLayer();

        int32_t      add_node();
        void         set_node(int32_t node_index, sNode* node);
        const sNode* get_node(int32_t node_index);

        void set_parent(int32_t child_index, int32_t parent_index);

        int32_t  get_node_count();
        int32_t* get_parents_array();
        sNode*   get_node_array();

      private:
        sNode   _node_array[MAX_NODES];
        int32_t _parents_array[MAX_NODES];
        int32_t _node_count {0};
    };

}

#endif
