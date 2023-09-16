
// Note: Add <monitor_raw = true> to platformio.ini for colored logs

#include <Arduino.h>
#include <WiFi.h>
#include "ESPAdmin.h"

const char *httpHost = "esp-admin-app.bg.tn"; // Should be secured (over HTTPS)
const char *deviceId = "";                         // Device identifier
const char *apiKey = "";                           // Device API key
const char *ssid = "";                             // WiFi station SSID
const char *password = "";                         // WiFi station password

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

    ESPAdmin::begin(httpHost, deviceId, apiKey);
}

void loop()
{
}