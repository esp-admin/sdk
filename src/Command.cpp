#include "Command.hpp"

namespace ESPAdmin
{
    Logger Command::_logger("Command");
    OnCustomCommand Command::onCustom = nullptr;
    OnConfigCommand Command::onConfig = nullptr;

    void Command::onMessage(const std::string &message, const std::string &topic)
    {
        std::string type = topic.substr(topic.find_last_of("/") + 1);

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

    void Command::_onUpdateTrigger(const std::string &message)
    {
        JsonDocument doc;

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
            _logger.warn("failed to deserialize Json");
        }
    }

    void Command::_onUpdateAbort(const std::string &message)
    {
        JsonDocument doc;

        DeserializationError error = deserializeJson(doc, message);

        if (error == DeserializationError::Ok)
        {
            std::string releaseId = doc["releaseId"];
            Update::abort(releaseId);
        }
        else
        {
            _logger.warn("failed to deserialize Json");
        }
    }

    void Command::_onConfig(const std::string &message)
    {
        Store::set(STORE_CONFIG, message.c_str());

        if (onConfig != nullptr)
        {
            onConfig(Store::get(STORE_CONFIG));
        }
    }

    void Command::_onRestart()
    {
        Report::sendStatus("disconnected");

        // Wait for MQTT publish to finish
        vTaskDelay(pdMS_TO_TICKS(Store::options.resetDelayMs));

        esp_restart();
    }

    void Command::_onLog(const std::string &message)
    {
        Store::logRemoteEnabled = message == "on" ? true : false;
    }

    void Command::_onCustom(const std::string &message)
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
