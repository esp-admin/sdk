#ifndef H_ESP_ADMIN_REPORT
#define H_ESP_ADMIN_REPORT

#include <ArduinoJson.h>
#include "Store.hpp"
#include "Logger.hpp"
#include "MQTT.hpp"
#include "HTTP.hpp"

namespace ESPAdmin
{
    class Logger;

    class Report
    {
    public:
        static void send(const ReportMessage &reportMessage);
        static void sendStatus(const std::string &status);
        static void sendUpdateStatus(UpdateMessage &updateMessage, const std::string &status);
        static void sendUpdateProgress(UpdateMessage &updateMessage, unsigned int progress);

    private:
        static Logger _logger;
    };
}

#endif