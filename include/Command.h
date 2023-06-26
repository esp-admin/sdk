#ifndef H_ESP_ADMIN_COMMAND
#define H_ESP_ADMIN_COMMAND

#include <ArduinoJson.h>
#include "types.h"

namespace ESPAdmin
{
    class Command
    {
    public:
        static void onMessage(String message);
        static void onCustom(DynamicJsonDocument message);
        static void onUpdate(UpdateMessage message);
        static void onConfig(DynamicJsonDocument message);
        static void onDebug(DebugMessage message);
        static void onRestart();
    };
}

#endif