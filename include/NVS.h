#ifndef H_ESP_ADMIN_NVS
#define H_ESP_ADMIN_NVS

#include "Logger.h"
#include <Arduino.h>
#include "nvs_flash.h"
#include "nvs.h"

namespace ESPAdmin
{
    class Logger;

    class NVS
    {
    public:
        void begin(String _namespace);
        String getString(String key);
        void setString(String key, String value);
        void clear();

    private:
        static Logger _logger;
        nvs_handle_t _handler;
    };
}

#endif