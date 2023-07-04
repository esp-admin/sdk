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
        static void send(ReportMessage reportMessage);
        static void sendStatus(String status);
        static void sendUpdate(UpdateMessage& updateMessage, String status);

    private:
        static Logger _logger;
    };
}

#endif