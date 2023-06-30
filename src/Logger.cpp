#include "Logger.h"

namespace ESPAdmin
{
    Logger::Logger(String scope)
    {
        _scope = scope;
    }

    void Logger::info(String message)
    {
        _log(ANSI_COLOR_BLUE, "info", message);
    }

    void Logger::error(String message)
    {
        _log(ANSI_COLOR_RED, "error", message);
    }

    void Logger::warn(String message)
    {
        _log(ANSI_COLOR_YELLOW, "warn", message);
    }

    void Logger::success(String message)
    {
        _log(ANSI_COLOR_GREEN, "success", message);
    }

    void Logger::_log(String color, String type, String message)
    {
        if (Store::debugSerialEnabled)
        {
            Serial.printf(color.c_str());
            Serial.printf(" %s ", type.c_str());
            Serial.printf(ANSI_COLOR_RESET);
            Serial.printf(" [%s] %s \n", _scope.c_str(), message.c_str());
        }
        if (Store::debugRemoteEnabled)
        {
        }
    }
}
