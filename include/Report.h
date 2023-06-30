#ifndef H_ESP_ADMIN_REPORT
#define H_ESP_ADMIN_REPORT

#include <ArduinoJson.h>
#include "Store.h"
#include "Logger.h"
#include "MQTT.h"

namespace ESPAdmin
{
    class Report
    {
    public:
        static void send(DynamicJsonDocument message);
        static void sendStatus();
        static void sendUpdate();

    private:
        static Logger _logger;
    };
}

#endif