#ifndef H_ESP_ADMIN_REPORT
#define H_ESP_ADMIN_REPORT

#include <ArduinoJson.h>

namespace ESPAdmin
{
    class Report
    {
    public:
        void send(DynamicJsonDocument message);
        void sendStatus();
        void sendUpdate();
    };
}

#endif