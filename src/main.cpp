#include <Arduino.h>
#include <WiFi.h>
#include "ESPAdmin.h"

const char *ssid = "ASUR_AP";
const char *password = "pass1234";

ESPAdmin::Logger logger("app");

void setup()
{
  Serial.begin(ESPAdmin::Store::debug.baudrate);
  Serial.printf("\n");

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    logger.info("WiFi wait");
    delay(1000);
  }

  logger.success("WiFi connected");

  ESPAdmin::begin();
}

void loop()
{
}
