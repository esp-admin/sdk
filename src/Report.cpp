#include "Report.h"

namespace ESPAdmin
{
    Logger Report::_logger("Report");

    void Report::send(const ReportMessage &reportMessage)
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
        default:
            break;
        }

        serializeJson(doc, message);

        HTTP::post("/report/custom", message, "application/json");

        MQTT::publish("/report/custom", message, 1, false);
    }

    void Report::sendStatus(const String &status)
    {
        String message;

        StaticJsonDocument<48> doc;

        doc["status"] = status;

        serializeJson(doc, message);

        MQTT::publish("/report/status", message, 1, true);
    }

    void Report::sendUpdateStatus(UpdateMessage &updateMessage, const String &status)
    {
        if (status == "started")
        {
            String message;

            StaticJsonDocument<126> doc; // 96 recommended

            doc["releaseId"] = updateMessage.releaseId;
            doc["status"] = status;

            serializeJson(doc, message);

            updateMessage.deploymentId = HTTP::post("/report/update", message, "application/json");

            String mqttMessage;

            StaticJsonDocument<126> mqttDoc; // 96 recommended

            mqttDoc["status"] = status;
            mqttDoc["deploymentId"] = updateMessage.deploymentId;

            serializeJson(mqttDoc, mqttMessage);

            MQTT::publish("/report/update_status", mqttMessage, 1, false);
        }
        else
        {
            StaticJsonDocument<126> doc; // 96 recommended

            doc["status"] = status;
            doc["deploymentId"] = updateMessage.deploymentId;

            String message;

            const size_t size = serializeJson(doc, message);

            if (size > 0)
            {
                HTTP::post("/report/update", message, "application/json");

                MQTT::publish("/report/update_status", message, 1, false);
            }
        }
    }

    void Report::sendUpdateProgress(UpdateMessage &updateMessage, int progress)
    {
        String mqttMessage;

        StaticJsonDocument<150> mqttDoc;

        mqttDoc["releaseId"] = updateMessage.releaseId;
        mqttDoc["deploymentId"] = updateMessage.deploymentId;
        mqttDoc["progress"] = progress;

        serializeJson(mqttDoc, mqttMessage);

        MQTT::publish("/report/update_progress", mqttMessage, 0, false);
    }
}
