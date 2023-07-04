
// Note: Add <monitor_raw = true> to platformio.ini for colored logs

#include <Arduino.h>
#include <WiFi.h>
#include "ESPAdmin.h"
#include <ArduinoJson.h>

const char *httpHost = "esp-admin.bg-tech.tn";
const char *deviceId = "";
const char *apiKey = "";
const char *ssid = "";
const char *password = "";

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

    ESPAdmin::begin(httpHost, deviceId, apiKey);

    ESPAdmin::Command::onCustom = &onCustomCommand;
}

void onCustomCommand(String message)
{
    logger.info("Handling command " + message);
}

void loop()
{
}