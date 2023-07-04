#include "Report.h"

namespace ESPAdmin
{
    Logger Report::_logger("Report");

    void Report::send(ReportMessage reportMessage)
    {
        String message;

        StaticJsonDocument<256> doc;

        doc["subject"] = reportMessage.subject;
        doc["body"] = reportMessage.body;

        switch (reportMessage.type)
        {
        case REPORT_ERROR:
            doc["type"] = "error";
            break;
        case REPORT_WARN:
            doc["type"] = "warn";
            break;
        case REPORT_SUCCESS:
            doc["type"] = "success";
            break;
        case REPORT_INFO:
            doc["type"] = "info";
            break;
        }

        serializeJson(doc, message);

        HTTP::post("/report/custom", message, "application/json");

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

    void Report::sendUpdate(UpdateMessage &updateMessage, String status)
    {
        if (status == "started")
        {
            String message;

            StaticJsonDocument<96> doc;

            doc["releaseId"] = updateMessage.releaseId;
            doc["status"] = status;

            serializeJson(doc, message);

            updateMessage.deploymentId = HTTP::post("/report/update", message, "application/json");

            String mqttMessage;

            StaticJsonDocument<96> mqttDoc;

            mqttDoc["status"] = status;
            mqttDoc["deploymentId"] = updateMessage.deploymentId;

            serializeJson(mqttDoc, mqttMessage);

            MQTT::publish("/report/update", mqttMessage, 1, false);
        }
        else
        {
            String message;

            StaticJsonDocument<96> doc;

            doc["status"] = status;
            doc["deploymentId"] = updateMessage.deploymentId;

            serializeJson(doc, message);

            HTTP::post("/report/update", message, "application/json");

            MQTT::publish("/report/update", message, 1, false);
        }
    }
}
