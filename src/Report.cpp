#include "Report.h"

namespace ESPAdmin
{
    Logger Report::_logger("Report");

    String Report::_deploymentId;

    void Report::send(String message)
    {
        HTTP::post("/device/report", message, "application/json");

        MQTT::publish("/report/custom", message, 1, false);
    }

    void Report::sendStatus(String status)
    {
        String message;

        StaticJsonDocument<48> doc;

        doc["status"] = status;

        serializeJson(doc, message);

        MQTT::publish("/report/status", message, 1, true);
    }

    void Report::sendUpdate(UpdateMessage updateMessage, String status)
    {
        if (status == "started")
        {
            String message;

            StaticJsonDocument<100> doc;

            doc["releaseId"] = updateMessage.releaseId;

            serializeJson(doc, message);

            _deploymentId = HTTP::post("/report/update", message, "application/json");

            String mqttMessage;

            StaticJsonDocument<100> mqttDoc;

            mqttDoc["status"] = status;
            mqttDoc["deploymentId"] = _deploymentId;

            serializeJson(mqttDoc, mqttMessage);

            MQTT::publish("/report/update", mqttMessage, 1, false);
        }
        else
        {
            String message;

            StaticJsonDocument<100> doc;

            doc["status"] = status;
            doc["deploymentId"] = _deploymentId;

            serializeJson(doc, message);

            HTTP::patch("/report/update", message, "application/json");

            MQTT::publish("/report/update", message, 1, false);
        }
    }
}
