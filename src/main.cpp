#include <Arduino.h>
#include <WiFi.h>
#include "ESPAdmin.h"
#include <ArduinoJson.h>

const char *ssid = "ASUR_AP";
const char *password = "pass1234";

// const char *ssid = "TTBOX-Q6HPV6";
// const char *password = "VYA9SKVLZE";

ESPAdmin::Logger logger("app");

void onCustomCommand(String message)
{
  logger.info(message);
}

void setup()
{
  Serial.begin(115200);
  Serial.printf("\n");

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    logger.info("WiFi wait");
    delay(1000);
  }

  logger.success("WiFi connected");

  ESPAdmin::begin();

  ESPAdmin::Command::onCustom = &onCustomCommand;
}

void loop()
{
  // String content;
  // StaticJsonDocument<96> doc;

  // doc["title"] = "foo";
  // doc["body"] = "bar";
  // doc["userId"] = 1;

  // serializeJson(doc, content);

  // String res = ESPAdmin::HTTP::post("/posts", content, "application/json");

  // logger.info(res);

  // delay(10000);
}
