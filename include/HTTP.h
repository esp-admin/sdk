#ifndef H_ESP_ADMIN_HTTP
#define H_ESP_ADMIN_HTTP

#include "Logger.h"
#include "Store.h"
#include <esp_http_client.h>

#define HTTP_MAX_RESPONSE_SIZE 2 * 1024
#define HTTP_TIMEOUT_MS 8000

namespace ESPAdmin
{
    class Logger;

    class HTTP
    {
    public:
        static String get(String path);
        static String post(String path, String content, String contentType);

    private:
        static Logger _logger;
    };
}

#endif