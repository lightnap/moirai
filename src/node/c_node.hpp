#ifndef C_NODE_NODEHPP_
#define C_NODE_NODEHPP_

#include <cstdint>

namespace moirai
{
    static constexpr uint32_t MAX_NODE_TITLE_LENGTH {64U};

    struct sNode
    {
      public:
        char    title[MAX_NODE_TITLE_LENGTH] {"/0"};
        int32_t pos_x {0};
        int32_t pos_y {0};
        int32_t size_x {20};
        int32_t size_y {20};
    };
}

#endif
