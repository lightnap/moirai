#include "c_node.hpp"

#include <raylib/src/raylib.h>

namespace moirai
{
    Color sNode::get_color()
    {
        switch (status)
        {
            case eStatus::open:
            {
                return RED;
            }

            case eStatus::in_progress:
            {
                return YELLOW;
            }
            case eStatus::done:
            {
                return GREEN;
            }
            default:
            {
                return LIGHTGRAY;
            }
        }

        return LIGHTGRAY;
    }
}
