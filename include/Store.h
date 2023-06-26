#ifndef H_ESP_ADMIN_STORE
#define H_ESP_ADMIN_STORE

#include "types.h"
#include <ArduinoJson.h>

namespace ESPAdmin
{
    class Store
    {
    public:
        static Meta meta;
        static Mqtt mqtt;
        static Update update;
        static Http http;
        static Debug debug;
        static DynamicJsonDocument config;
    };
}

#endif