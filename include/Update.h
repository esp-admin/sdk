#ifndef H_ESP_ADMIN_UPDATE
#define H_ESP_ADMIN_UPDATE

#include <Arduino.h>

namespace ESPAdmin
{
    class Update
    {
    public:
        void check();
        void start(String downloadURL);
    };
}

#endif