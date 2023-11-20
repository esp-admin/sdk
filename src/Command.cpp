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

        else if (type == "update")
        {
            _onUpdate(message);
        }

        else if (type == "config")
        {
            _onConfig(message);
        }

        else if (type == "custom")
        {
            if (onCustom == nullptr)
            {
                _logger.warn("no handler registered for custom commands");
            }
            else
            {
                onCustom(message);
            }
        }
    }

    void Command::_onUpdate(const String &message)
    {
        StaticJsonDocument<222> doc; // 192 recommended

        DeserializationError error = deserializeJson(doc, message);

        if (error == DeserializationError::Ok)
        {
            UpdateMessage updateMessage = {
                .downloadPath = doc["downloadPath"],
                .releaseId = doc["releaseId"],
                .version = doc["version"],
            };

            Update::checkAndUpdate(updateMessage);
        }
    }

    void Command::_onConfig(const String &message)
    {
        Store::set(STORE_CONFIG, message.c_str());

        if (onConfig == nullptr)
        {
            _logger.warn("no handler registered for config command");
        }
        else
        {
            onConfig(Store::get(STORE_CONFIG));
        }
    }

    [[noreturn]] void Command::_onRestart()
    {
        Report::sendStatus("disconnected");

        // Wait for MQTT publish to finish
        delay(RESET_DELAY_MS);

        esp_restart();
    }

    void Command::_onLog(const String &message)
    {
        Store::logRemoteEnabled = message == "on" ? true : false;
    }
}
