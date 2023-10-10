#ifndef H_ESP_ADMIN_UPDATE
#define H_ESP_ADMIN_UPDATE

#include <Arduino.h>
#include "types.h"
#include "Store.h"
#include "OTA.h"
#include "Logger.h"
#include "Report.h"

#define RESET_DELAY_MS 5000

namespace ESPAdmin
{
    class Logger;

    class Update
    {
    public:
        static void checkAndUpdate(UpdateMessage message);
        static void onChange(UpdateStatus status);

    private:
        static UpdateMessage _message;
        static Logger _logger;
        static void _onSuccess();
        static void _onFail();
        static void _onStart();
    };
}

#endif