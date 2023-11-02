#include "Logger.h"

namespace ESPAdmin
{
    Logger::Logger(const char *scope) : _scope{scope}
    {
    }

    void Logger::info(const char *format, ...) const
    {
        va_list args;
        va_start(args, format);

        char buffer[MAX_LOG_MESSAGE_SIZE];
        vsnprintf(buffer, sizeof(buffer), format, args);

        va_end(args);
        _log(ANSI_COLOR_BLUE, "info", buffer);
    }

    void Logger::error(const char *format, ...) const
    {
        va_list args;
        va_start(args, format);

        char buffer[MAX_LOG_MESSAGE_SIZE];
        vsnprintf(buffer, sizeof(buffer), format, args);

        va_end(args);
        _log(ANSI_COLOR_RED, "error", buffer);
    }

    void Logger::warn(const char *format, ...) const
    {
        va_list args;
        va_start(args, format);

        char buffer[MAX_LOG_MESSAGE_SIZE];
        vsnprintf(buffer, sizeof(buffer), format, args);

        va_end(args);
        _log(ANSI_COLOR_YELLOW, "warn", buffer);
    }

    void Logger::success(const char *format, ...) const
    {
        va_list args;
        va_start(args, format);

        char buffer[MAX_LOG_MESSAGE_SIZE];
        vsnprintf(buffer, sizeof(buffer), format, args);

        va_end(args);
        _log(ANSI_COLOR_GREEN, "success", buffer);
    }

    void Logger::_log(const char *color, const char *type, const char *message) const
    {
        if (Store::logSerialEnabled)
        {
            Serial.printf("%s %s ", color, type);
            Serial.printf(ANSI_COLOR_RESET);
            Serial.printf(" [%s] %s \n", _scope.c_str(), message);
        }
        if (Store::logRemoteEnabled)
        {
            MQTT::publish("/logs/" + String(type), message, 0, false);
        }
    }
}
