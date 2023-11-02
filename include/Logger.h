#ifndef H_ESP_ADMIN_LOGGER
#define H_ESP_ADMIN_LOGGER

#include <Arduino.h>
#include "Store.h"
#include "MQTT.h"

#ifndef MAX_LOG_MESSAGE_SIZE
#define MAX_LOG_MESSAGE_SIZE 100
#endif

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
        Logger(const char *scope);
        void info(const char *format, ...);
        void error(const char *format, ...);
        void warn(const char *format, ...);
        void success(const char *format, ...);

    private:
        void _log(const char *color, const char *type, const char *message);
        String _scope;
    };
}

#endif