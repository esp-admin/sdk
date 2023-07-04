#ifndef H_ESP_ADMIN_TYPES
#define H_ESP_ADMIN_TYPES

#include <Arduino.h>

namespace ESPAdmin
{
    struct UpdateMessage
    {
        String downloadURL;
        String releaseId;
        String version;
    };

    struct ReportMessage
    {
        ReportType type;
        String subject;
        String body;
    };

    enum ReportType
    {
        REPORT_INFO,
        REPORT_ERROR,
        REPORT_WARN,
        REPORT_SUCCESS
    };

    enum StoreKey
    {
        STORE_CONFIG,
        STORE_MQTT_URI_TCP,
        STORE_MQTT_URI_WS,
        STORE_MQTT_USERNAME,
        STORE_MQTT_PASSWORD,
        STORE_UPDATE_RELEASE_ID,
        STORE_UPDATE_VERSION,
    };

    enum UpdateStatus
    {
        UPDATE_STARTED,
        UPDATE_FAILED,
        UPDATE_SUCCEDED
    };

    typedef void (*OnCustomCommand)(String);
}

#endif