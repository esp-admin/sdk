#ifndef H_ESP_ADMIN_COMMAND
#define H_ESP_ADMIN_COMMAND

#include <ArduinoJson.h>
#include "Logger.h"
#include "types.h"
#include "Update.h"
#include "Report.h"

#ifndef RESET_DELAY_MS
#define RESET_DELAY_MS 4000
#endif

namespace ESPAdmin
{
    class Logger;

    class Command
    {
    public:
        static void onMessage(const String &message, const String &topic);
        static OnCustomCommand onCustom;
        static OnConfigCommand onConfig;

    private:
        static Logger _logger;
        static void _onUpdate(const String &message);
        static void _onConfig(const String &message);
        static void _onRestart();
        static void _onLog(const String &message);
        static void _onCustom(const String &message);
    };
}

#endif