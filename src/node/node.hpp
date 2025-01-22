#ifndef MOIRAI_SRC_NODE_NODEHPP_
#define MOIRAI_SRC_NODE_NODEHPP_

#include <raylib/src/raylib.h>

#include <cstdint>

namespace moirai
{
    static constexpr uint32_t MAX_NODE_TITLE_LENGTH {64U};

    static constexpr int32_t NODE_TEXT_SIZE {10}; // Size of text. We assume the font to be monospace.
    static constexpr int32_t TEXT_ROWS_IN_NODE {4};
    static constexpr int32_t TEXT_LINE_LENGTH {20};
    static constexpr int32_t LINE_SPACING {3};           // Distance between text lines.
    static constexpr int32_t NODE_HORIZONTAL_MARGIN {3}; // Distance from node border to text.
    static constexpr int32_t NODE_VERTICAL_MARGIN {3};

    static constexpr int32_t VERTICAL_NODE_SEPARATION {10}; // Separation between nodes.
    static constexpr int32_t HORIZONTAL_NODE_SEPARATION {10};

    static constexpr int32_t NODE_SIZE_X {2 * NODE_HORIZONTAL_MARGIN + NODE_TEXT_SIZE * TEXT_LINE_LENGTH};
    static constexpr int32_t NODE_SIZE_Y {2 * NODE_VERTICAL_MARGIN + NODE_TEXT_SIZE * TEXT_ROWS_IN_NODE + LINE_SPACING * (TEXT_ROWS_IN_NODE - 1)};

    struct sNode
    {
      public:
        enum class eStatus
        {
            open = 0,
            in_progress,
            done,
        };

        char    title[MAX_NODE_TITLE_LENGTH] {"/0"};
        int32_t pos_x {0};
        int32_t pos_y {0};
        int32_t size_x {NODE_SIZE_X};
        int32_t size_y {NODE_SIZE_Y};

        eStatus status {eStatus::open};

        Color get_color();
    };
}

#endif
