#ifndef H_ESP_ADMIN_NVS
#define H_ESP_ADMIN_NVS

#include "Logger.hpp"
#include <nvs_flash.h>
#include <nvs.h>

namespace ESPAdmin
{
    class Logger;

    class NVS
    {
    public:
        void begin(const char *_namespace);
        std::string getString(const char *key) const;
        void setString(const char *key, const char *value) const;
        void clear() const;

    private:
        static Logger _logger;
        nvs_handle_t _handler;
    };
}

#endif