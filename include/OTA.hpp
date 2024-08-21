#ifndef H_ESP_ADMIN_OTA
#define H_ESP_ADMIN_OTA

#include <esp_http_client.h>
#include <esp_https_ota.h>
#include "Store.hpp"
#include "Logger.hpp"
#include "Update.hpp"

namespace ESPAdmin
{
    class Logger;

    class OTA
    {
    public:
        static void start(const std::string &downloadURL);
        static void abort();

    private:
        static Logger _logger;
        static bool _aborted;
        static esp_https_ota_handle_t _otaHandle;
        static void _task(void *pvParameters);
    };
}

#endif