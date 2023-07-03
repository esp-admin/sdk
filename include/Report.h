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
        static void send(String message);
        static void sendStatus(String status);
        static void sendUpdate(UpdateMessage updateMessage, String status);

    private:
        static Logger _logger;
        static String _deploymentId;
    };
}

#endif