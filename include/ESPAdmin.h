#ifndef H_ESP_ADMIN
#define H_ESP_ADMIN

#include "Logger.h"
#include "Report.h"
#include "Store.h"
#include "Command.h"
#include "MQTT.h"
#include "HTTP.h"
#include "Update.h"

namespace ESPAdmin
{
    void begin(const char * httpHost, const char* deviceId, const char*apiKey);
}

#endif