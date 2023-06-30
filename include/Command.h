#ifndef H_ESP_ADMIN_COMMAND
#define H_ESP_ADMIN_COMMAND

#include <ArduinoJson.h>
#include "types.h"
#include "Logger.h"

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
        static void _onUpdate(UpdateMessage message);
        static void _onConfig(DynamicJsonDocument message);
        static void _onRestart();
    };
}

#endif