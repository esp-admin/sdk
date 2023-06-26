#ifndef H_ESP_ADMIN_OTA
#define H_ESP_ADMIN_OTA

#include <Arduino.h>

namespace ESPAdmin
{
    class OTA
    {
    public:
        void start(String downloadURL);
    };
}

#endif