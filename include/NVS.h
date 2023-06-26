#ifndef H_ESP_ADMIN_NVS
#define H_ESP_ADMIN_NVS

#include <Arduino.h>

namespace ESPAdmin
{
    class NVS
    {
    public:
        void init(String _namespace);
        void get(String _namespace, String key);
        void set(String _namespace, String key);
        void clear(String _namespace);
    };
}

#endif