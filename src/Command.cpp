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
    }

    void Command::_onCustom(DynamicJsonDocument message)
    {
    }

    void Command::_onUpdate(UpdateMessage message)
    {
    }

    void Command::_onConfig(DynamicJsonDocument message)
    {
    }

    void Command::_onRestart()
    {
    }

}
