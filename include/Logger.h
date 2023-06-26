#ifndef H_ESP_ADMIN_LOGGER
#define H_ESP_ADMIN_LOGGER

#include <Arduino.h>
#include "types.h"
#include "Store.h"

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
        Logger(String scope);
        static void begin();
        void info(String message);
        void error(String message);
        void warn(String message);
        void success(String message);

    private:
        void _log(String color, String type, String message);
        String _scope;
    };
}

#endif