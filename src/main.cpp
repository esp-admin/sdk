#include <Arduino.h>
#include <WiFi.h>
#include "ESPAdmin.h"
#include <ArduinoJson.h>

// const char *ssid = "ASUR_AP";
// const char *password = "pass1234";
const char *httpHost = "esp-admin-app.bg-tech.tn";
const char *deviceId = "648f18db246acba17f68f609";
const char *apiKey = "xcvxvDF5";

const char *ssid = "TTBOX-Q6HPV6";
const char *password = "VYA9SKVLZE";

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