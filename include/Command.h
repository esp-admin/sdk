#ifndef H_ESP_ADMIN_COMMAND
#define H_ESP_ADMIN_COMMAND

#include <ArduinoJson.h>
#include "types.h"
#include "Logger.h"
#include "Update.h"

namespace ESPAdmin
{
    class Logger;

    class Command
    {
    public:
        static void onMessage(String message, String topic);

    private:
        static Logger _logger;
        static void _onCustom(DynamicJsonDocument message);
        static void _onUpdate(String message);
        static void _onConfig(String message);
        static void _onRestart();
        static void _onDebug(String message);
    };
}

#endif