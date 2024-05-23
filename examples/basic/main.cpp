#include <Arduino.h>
#include <WiFi.h>
#include <ESPAdmin.h>
#include <ArduinoJson.h>
#include "credentials.h"

ESPAdmin::Logger logger("app");

void onCustomCommand(String message);

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

    ESPAdmin::begin({
        .httpHost = httpHost,
        .deviceId = deviceId,
        .apiKey = apiKey,
        .httpCert = httpCert,
        .mqttCert = mqttCert,
    });

    ESPAdmin::Command::onCustom = &onCustomCommand;
}

void onCustomCommand(String message)
{
    logger.info("Handling command " + message);
}

void loop()
{
}