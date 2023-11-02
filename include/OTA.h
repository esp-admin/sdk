#ifndef H_ESP_ADMIN_OTA
#define H_ESP_ADMIN_OTA

#ifndef HTTP_TIMEOUT_MS
#define HTTP_TIMEOUT_MS 8000
#endif

#ifndef OTA_TASK_STACK_SIZE
#define OTA_TASK_STACK_SIZE 6 * 1024
#endif

#ifndef OTA_TASK_PRIORITY
#define OTA_TASK_PRIORITY 5
#endif

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