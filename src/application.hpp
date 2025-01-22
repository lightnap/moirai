#ifndef MOIRAI_SRC_APPLICATIONHPP_
#define MOIRAI_SRC_APPLICATIONHPP_

#include "layers/data_layer.hpp"
#include "layers/logic_layer.hpp"
#include "layers/visual_layer.hpp"

#include <cstdint>

namespace moirai
{
    class cApplication
    {
      public:
        int32_t       run();
        cVisualLayer* get_visual_layer();
        cLogicLayer*  get_logic_layer();
        cDataLayer*   get_data_layer();

      private:
        void init();
        void update();
        void terminate();

        cVisualLayer _visual_layer;
        cLogicLayer  _logic_layer;
        cDataLayer   _data_layer;
    };

    cApplication* get_app();
    void          set_app(cApplication* app);
}

#endif
