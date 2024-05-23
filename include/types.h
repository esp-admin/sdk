#ifndef H_ESP_ADMIN_TYPES
#define H_ESP_ADMIN_TYPES

#include <Arduino.h>

namespace ESPAdmin
{
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

    struct UpdateMessage
    {
        String downloadPath;
        String releaseId;
        String version;
        String deploymentId;
    };

    struct ReportMessage
    {
        ReportType type;
        String subject;
        String body;
    };

    struct InitOptions
    {
        const char *httpHost;
        const char *deviceId;
        const char *apiKey;
        const char *httpCert;
        const char *mqttCert;
        uint16_t resetDelayMs;
        uint16_t httpMaxResponseSize;
        uint16_t httpTimeoutMs;
        uint16_t logMaxMessageSize;
        uint8_t mqttTaskPriority;
        uint16_t mqttTaskStackSize;
        uint8_t mqttKeepAliveSec;
        uint16_t mqttNetworkTimeoutMs;
        uint16_t mqttReconnectTimeoutMs;
        uint8_t otaTaskPriority;
        uint16_t otaTaskStackSize;
    };

    using OnCustomCommand = void (*)(String);
    using OnConfigCommand = void (*)(String);
}

#endif