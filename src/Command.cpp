#include "Command.h"

namespace ESPAdmin
{
    Logger Command::_logger("Command");
    OnCustomCommand Command::onCustom;

    void Command::onMessage(String message, String topic)
    {
        String type = topic.substring(topic.lastIndexOf("/") + 1);

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

        else if (type == "custom")
        {
            onCustom(message);
        }
    }

    void Command::_onUpdate(String message)
    {
        StaticJsonDocument<256> doc;

        DeserializationError error = deserializeJson(doc, message);

        UpdateMessage updateMessage = {
            .downloadURL = doc["downloadUrl"],
            .releaseId = doc["releaseId"],
            .version = doc["version"],
        };

        Update::checkAndUpdate(updateMessage);
    }

    void Command::_onConfig(String message)
    {
        Store::set(STORE_CONFIG, message.c_str());
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
