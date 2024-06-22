#include "Command.h"

namespace ESPAdmin
{
    Logger Command::_logger("Command");
    OnCustomCommand Command::onCustom = nullptr;
    OnConfigCommand Command::onConfig = nullptr;

    void Command::onMessage(const String &message, const String &topic)
    {
        String type = topic.substring(topic.lastIndexOf("/") + 1);

        if (type == "log")
        {
            _onLog(message);
        }

        else if (type == "restart")
        {
            _onRestart();
        }

        else if (type == "update_trigger")
        {
            _onUpdateTrigger(message);
        }

        else if (type == "update_abort")
        {
            _onUpdateAbort(message);
        }

        else if (type == "config")
        {
            _onConfig(message);
        }

        else if (type == "custom")
        {
            _onCustom(message);
        }
    }

    void Command::_onUpdateTrigger(const String &message)
    {
        StaticJsonDocument<300> doc; // 192 recommended

        DeserializationError error = deserializeJson(doc, message);

        if (error == DeserializationError::Ok)
        {
            UpdateMessage updateMessage = {
                .downloadPath = doc["downloadPath"],
                .downloadSize = doc["downloadSize"],
                .releaseId = doc["releaseId"],
                .version = doc["version"],
            };

            Update::checkAndUpdate(updateMessage);
        }
        else
        {
            _logger.warn(F("failed to deserialize Json"));
        }
    }

    void Command::_onUpdateAbort(const String &message)
    {
        StaticJsonDocument<100> doc;

        DeserializationError error = deserializeJson(doc, message);

        if (error == DeserializationError::Ok)
        {
            String releaseId = doc["releaseId"];
            Update::abort(releaseId);
        }
        else
        {
            _logger.warn(F("failed to deserialize Json"));
        }
    }

    void Command::_onConfig(const String &message)
    {
        Store::set(STORE_CONFIG, message.c_str());

        if (onConfig != nullptr)
        {
            onConfig(Store::get(STORE_CONFIG));
        }
    }

    [[noreturn]] void Command::_onRestart()
    {
        Report::sendStatus("disconnected");

        // Wait for MQTT publish to finish
        delay(Store::options.resetDelayMs);

        esp_restart();
    }

    void Command::_onLog(const String &message)
    {
        Store::logRemoteEnabled = message == "on" ? true : false;
    }

    void Command::_onCustom(const String &message)
    {
        if (onCustom == nullptr)
        {
            _logger.warn(F("no handler registered for custom commands"));
        }
        else
        {
            onCustom(message);
        }
    }
}
