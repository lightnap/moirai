#ifndef MORIAI_SRC_LAYERS_CVISUALLAYERHPP_
#define MORIAI_SRC_LAYERS_CVISUALLAYERHPP_

#include <cstdint>

namespace moirai
{
    struct sNode;

    struct sDrawData
    {
      public:
        sNode*  node_array {nullptr};
        int32_t node_count {0};
    };

    class cVisualLayer
    {
      public:
        void draw(sDrawData* draw_data);
    };
}

#endif
