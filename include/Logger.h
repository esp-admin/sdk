#ifndef H_ESP_ADMIN_LOGGER
#define H_ESP_ADMIN_LOGGER

#include <Arduino.h>
#include "types.h"

namespace ESPAdmin
{
    class Logger
    {
    public:
        void info(String message, String scope);
        void error(String message, String scope);
        void warn(String message, String scope);
        void success(String message, String scope);

    private:
        void _log(LoggerType type, String message, String scope);
    };
}

#endif