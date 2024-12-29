#include "c_application.hpp"

#include <raylib/src/raylib.h>

#include <cstdint>

int main(void)
{
    moirai::cApplication main_application {};
    moirai::set_app(&main_application);

    int32_t return_value {main_application.run()};

    moirai::set_app(nullptr);
    return return_value;
}
