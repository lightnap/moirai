#ifndef MOIRAI_SRC_CAPPLICATIONHPP_
#define MOIRAI_SRC_CAPPLICATIONHPP_

#include "layers/c_data_layer.hpp"
#include "layers/c_visual_layer.hpp"

#include <cstdint>

namespace moirai
{
    class cApplication
    {
      public:
        int32_t       run();
        cVisualLayer* get_visual_layer();
        cDataLayer*   get_data_layer();

      private:
        void init();
        void update();
        void terminate();

        cVisualLayer _visual_layer;
        cDataLayer   _data_layer;
    };

    cApplication* get_app();
    void          set_app(cApplication* app);
}

#endif
