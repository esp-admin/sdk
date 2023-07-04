#include <Arduino.h>
#include <WiFi.h>
#include "ESPAdmin.h"
#include <ArduinoJson.h>

const char *ssid = "ASUR_AP";
const char *password = "pass1234";

// const char *ssid = "TTBOX-Q6HPV6";
// const char *password = "VYA9SKVLZE";

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

  ESPAdmin::begin("esp-admin.bg-tech.tn", "648f18db246acba17f68f609", "xcvxvDF5");

  ESPAdmin::Command::onCustom = &onCustomCommand;
}

void onCustomCommand(String message)
{
  logger.info("Handling command " + message);
}

void loop()
{
}