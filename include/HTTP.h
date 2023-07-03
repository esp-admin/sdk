#ifndef H_ESP_ADMIN_HTTP
#define H_ESP_ADMIN_HTTP

#include "Logger.h"
#include "Store.h"
#include <esp_http_client.h>

namespace ESPAdmin
{
    class Logger;

    class HTTP
    {
    public:
        static String get(String path);
        static String patch(String path, String content, String contentType);
        static String post(String path, String content, String contentType);

    private:
        static Logger _logger;
        static unsigned int _maxResponseSize;
        static int _timeoutMs;
    };
}

#endif