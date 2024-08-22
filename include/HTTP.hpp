#ifndef H_ESP_ADMIN_HTTP
#define H_ESP_ADMIN_HTTP

#include "Logger.hpp"
#include "Store.hpp"
#include <esp_http_client.h>

namespace ESPAdmin
{
    class Logger;

    class HTTP
    {
    public:
        static std::string get(const std::string &path);
        static std::string post(const std::string &path, const std::string &content, const std::string &contentType);

    private:
        static Logger _logger;
    };
}

#endif