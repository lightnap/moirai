#include <cstdint>

#include <raylib/src/raylib.h>

#include "c_application.hpp"

int main(void)
{
    moirai::CApplication main_application {};
    moirai::set_app(&main_application);

    int32_t return_value {main_application.run()};

    moirai::set_app(nullptr);
    return return_value;
}
