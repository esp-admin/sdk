#ifndef H_ESP_ADMIN_HTTP
#define H_ESP_ADMIN_HTTP

#include "Logger.h"
#include "Store.h"
#include <esp_http_client.h>

#ifndef HTTP_MAX_RESPONSE_SIZE
#define HTTP_MAX_RESPONSE_SIZE 2 * 1024
#endif

#ifndef HTTP_TIMEOUT_MS
#define HTTP_TIMEOUT_MS 8000
#endif

namespace ESPAdmin
{
    class Logger;

    class HTTP
    {
    public:
        static String get(const String &path);
        static String post(const String &path, const String &content,const String &contentType);

    private:
        static Logger _logger;
    };
}

#endif