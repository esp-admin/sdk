#ifndef H_ESP_ADMIN
#define H_ESP_ADMIN

#include "Logger.hpp"
#include "Report.hpp"
#include "Store.hpp"
#include "Command.hpp"
#include "MQTT.hpp"
#include "types.hpp"

namespace ESPAdmin
{
    void begin(InitOptions options);
}

#endif