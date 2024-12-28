#ifndef MOIRAI_SRC_C_APPLICATION_H_
#define MOIRAI_SRC_C_APPLICATION_H_

#include "layers/c_visual_layer.hpp"

#include <cstdint>

namespace moirai
{
    class CApplication
    {
      public:
        int32_t       run();
        CVisualLayer* get_visual_layer();

      private:
        void init();
        void update();
        void terminate();

        CVisualLayer _visual_layer;
    };

    CApplication* get_app();
    void          set_app(CApplication* app);
}

#endif
