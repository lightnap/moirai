#ifndef C_APPLICATION_H_
#define C_APPLICATION_H_

#include <cstdint>

namespace moirai
{
    class CApplication
    {
      public:
        int32_t run();

      private:
        void init();
        void update();
        void terminate();
    };

    CApplication* get_app();
    void          set_app(CApplication* app);
}

#endif // C_APPLICATION_H_
