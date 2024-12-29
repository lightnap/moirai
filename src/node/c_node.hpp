#ifndef C_NODE_NODEHPP_
#define C_NODE_NODEHPP_

#include <cstdint>

namespace moirai
{
    static constexpr uint32_t MAX_NODE_TITLE_LENGTH {32U};

    struct sNode
    {
      public:
        char title[MAX_NODE_TITLE_LENGTH] {"/0"};
    };
}

#endif
