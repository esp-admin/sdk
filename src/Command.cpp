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
            Store::debugRemoteEnabled = message == "on" ? true : false;
        }

        else if (type == "restart")
        {
            esp_restart();
        }

        else if (type == "update")
        {
            _onUpdate(message);
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

    void Command::_onConfig(DynamicJsonDocument message)
    {
    }

    void Command::_onRestart()
    {
    }

}
