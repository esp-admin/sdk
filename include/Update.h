#ifndef H_ESP_ADMIN_UPDATE
#define H_ESP_ADMIN_UPDATE

#include <Arduino.h>
#include "types.h"
#include "Store.h"
#include "OTA.h"
#include "Logger.h"

namespace ESPAdmin
{
    class Update
    {
    public:
        static void checkAndUpdate(UpdateMessage message);
        static void onChange(UpdateStatus status);

    private:
        static UpdateMessage _message;
        static Logger _logger;
    };
}

#endif