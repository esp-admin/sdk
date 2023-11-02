#ifndef H_ESP_ADMIN_REPORT
#define H_ESP_ADMIN_REPORT

#include <ArduinoJson.h>
#include "Store.h"
#include "Logger.h"
#include "MQTT.h"
#include "HTTP.h"

namespace ESPAdmin
{
    class Logger;

    class Report
    {
    public:
        static void send(const ReportMessage &reportMessage);
        static void sendStatus(const String &status);
        static void sendUpdate(UpdateMessage &updateMessage, const String &status);

    private:
        static Logger _logger;
    };
}

#endif