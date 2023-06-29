#ifndef H_ESP_ADMIN_TYPES
#define H_ESP_ADMIN_TYPES

#include <Arduino.h>

namespace ESPAdmin
{
    struct Meta
    {
        String deviceId;
        String mac;
    };

    struct Mqtt
    {
        bool connected;
        String uriTCP;
        String uriWS;
        String clientId;
        String username;
        String password;
        String certificate;
    };

    struct Update
    {
        enum
        {
            ACTIVE,
            FAILED,
            DONE
        } status;
        String certificate;
        String projectId;
        String releaseId;
    };

    struct Http
    {
        String baseURL;
        String username;
        String password;
        String certificate;
    };

    struct Debug
    {
        unsigned long baudrate;
        bool serial;
        bool remote;
    };

    struct UpdateMessage
    {
        String downloadURL;
        String version;
        String projectId;
    };

    enum DebugMessage
    {
        ON,
        OFF
    };
}

#endif