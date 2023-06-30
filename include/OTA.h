#ifndef H_ESP_ADMIN_OTA
#define H_ESP_ADMIN_OTA

#include <Arduino.h>
#include <HttpsOTAUpdate.h>
#include <esp_https_ota.h>
#include "Store.h"
#include "Logger.h"
#include "Update.h"

namespace ESPAdmin
{
    class OTA
    {
    public:
        static void start(String downloadURL);

    private:
        static Logger _logger;
        static void _onStart();
        static void _onSuccess();
        static void _onFailed();
    };
}

#endif