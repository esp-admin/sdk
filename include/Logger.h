#ifndef H_ESP_ADMIN_LOGGER
#define H_ESP_ADMIN_LOGGER

#include <Arduino.h>
#include "Store.h"
#include "MQTT.h"

// ANSI escape codes for text color
#define ANSI_COLOR_RED "\x1b[41m"
#define ANSI_COLOR_GREEN "\x1b[42m"
#define ANSI_COLOR_YELLOW "\x1b[43m"
#define ANSI_COLOR_BLUE "\x1b[44m"
#define ANSI_COLOR_RESET "\x1b[49m"

namespace ESPAdmin
{
    class Logger
    {
    public:
        explicit Logger(const char *scope);
        void info(const char *format, ...) const;
        void error(const char *format, ...) const;
        void warn(const char *format, ...) const;
        void success(const char *format, ...) const;

    private:
        void _log(const char *color, const char *type, const char *message) const;
        const String _scope;
    };
}

#endif