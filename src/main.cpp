#include <Arduino.h>
#include <WiFi.h>
#include "ESPAdmin.h"
#include <ArduinoJson.h>

const char *httpHost = "espadmin-app.bg.tn";       // Should be secured (over HTTPS)
const char *deviceId = "651183946659c6553efa5d31"; // Device identifier
const char *apiKey = "qsd56562";                   // Device API key
const char *ssid = "ASUS_AP";                      // WiFi station SSID
const char *password = "pass1234";

ESPAdmin::Logger logger("app");

void onCustomCommand(String message);

void setup()
{
  Serial.begin(9600);
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