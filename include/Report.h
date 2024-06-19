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
        static void sendUpdateStatus(UpdateMessage &updateMessage, const String &status);
        static void sendUpdateProgress(UpdateMessage &updateMessage, int progress);

    private:
        static Logger _logger;
    };
}

#endif