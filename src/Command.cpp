#include "Command.h"

namespace ESPAdmin
{
    Logger Command::_logger("Command");

    void Command::onMessage(String message, String topic)
    {
        int beginIndex = topic.lastIndexOf("/") + 1;

        String type = topic.substring(beginIndex);

        if (type == "debug")
        {
            _onDebug(message);
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
    }

    void Command::_onCustom(DynamicJsonDocument message)
    {
    }

    void Command::_onUpdate(String message)
    {
        StaticJsonDocument<300> doc;

        DeserializationError error = deserializeJson(doc, message);

        if (error)
        {
            _logger.error("failed to parse update message");
            return;
        }

        UpdateMessage updateMessage = {
            .downloadURL = doc["downloadUrl"],
            .releaseId = doc["releaseId"],
            .version = doc["version"],
        };

        Update::checkAndUpdate(updateMessage);
    }

    void Command::_onConfig(String message)
    {
        Store::set(STORE_CONFIG, message);
    }

    void Command::_onRestart()
    {
        esp_restart();
    }

    void Command::_onDebug(String message)
    {
        Store::debugRemoteEnabled = message == "on" ? true : false;
    }
}
