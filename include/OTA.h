#ifndef H_ESP_ADMIN_OTA
#define H_ESP_ADMIN_OTA

#include <Arduino.h>
#include <esp_http_client.h>
#include <esp_https_ota.h>
#include "Store.h"
#include "Logger.h"
#include "Update.h"

namespace ESPAdmin
{
    class Logger;

    class OTA
    {
    public:
        static void start(const String &downloadURL);

    private:
        static Logger _logger;
        static String _downloadURL;
        static void task(void *pvParameters);
    };
}

#endif