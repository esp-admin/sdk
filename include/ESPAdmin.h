#ifndef H_ESP_ADMIN
#define H_ESP_ADMIN

#include "Logger.h"
#include "Report.h"
#include "Store.h"
#include "Command.h"
#include "MQTT.h"

namespace ESPAdmin
{
    void begin(const char *httpHost, const char *deviceId, const char *apiKey, const char *certPem);
}

#endif