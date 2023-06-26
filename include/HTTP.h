#ifndef H_ESP_ADMIN_HTTP
#define H_ESP_ADMIN_HTTP

#include <ArduinoJson.h>

namespace ESPAdmin
{
    class HTTP
    {
    public:
        DynamicJsonDocument get(String path);
        void patch(String path, DynamicJsonDocument body);
        void post(String path, DynamicJsonDocument body);
    };
}

#endif