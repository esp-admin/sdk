#include "Report.h"

namespace ESPAdmin
{
    Logger Report::_logger("Report");

    void Report::send(DynamicJsonDocument message)
    {
    }

    void Report::sendStatus()
    {
        String message;

        String status = Store::mqttConnected ? "connected" : "disconnected";

        StaticJsonDocument<48> doc;

        doc["status"] = status;

        serializeJson(doc, message);

        _logger.info(message);

        MQTT::publish("/report/status", message, 1, true);
    }

    void Report::sendUpdate()
    {
    }
}
