#include <Arduino.h>
#include <WiFi.h>
#include <ESPAdmin.h>
#include "credentials.h"

ESPAdmin::Logger logger("app");

void setup()
{
    Serial.begin(115200);
    Serial.printf("\n");

    WiFi.begin(ssid, password);

    logger.info("WiFi wait");

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(1000);
    }

    logger.success("WiFi connected");

    ESPAdmin::begin(httpHost, deviceId, httpCert, mqttCert);
}

void loop()
{
}