#ifndef H_ESP_ADMIN
#define H_ESP_ADMIN

#include "Logger.h"
#include "Report.h"
#include "Store.h"
#include "Command.h"
#include "MQTT.h"
#include "types.h"

namespace ESPAdmin
{
    void begin(InitOptions options);
}

#endif