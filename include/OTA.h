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
        static void abort();

    private:
        static Logger _logger;
        static bool _aborted;
        static esp_https_ota_handle_t _otaHandle;
        static void _task(void *pvParameters);
    };
}

#endif