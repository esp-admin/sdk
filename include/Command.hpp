#ifndef H_ESP_ADMIN_COMMAND
#define H_ESP_ADMIN_COMMAND

#include <ArduinoJson.h>
#include "Logger.hpp"
#include "types.hpp"
#include "Update.hpp"
#include "Report.hpp"
#include "Store.hpp"

namespace ESPAdmin
{
    class Logger;

    class Command
    {
    public:
        static void onMessage(const std::string &message, const std::string &topic);
        static OnCustomCommand onCustom;
        static OnConfigCommand onConfig;

    private:
        static Logger _logger;
        static void _onUpdateTrigger(const std::string &message);
        static void _onUpdateAbort(const std::string &message);
        static void _onConfig(const std::string &message);
        static void _onRestart();
        static void _onLog(const std::string &message);
        static void _onCustom(const std::string &message);
    };
}

#endif