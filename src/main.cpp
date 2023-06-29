#include <Arduino.h>
#include <WiFi.h>
#include "ESPAdmin.h"
#include <ArduinoJson.h>

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
  String content;
  StaticJsonDocument<96> doc;

  doc["title"] = "foo";
  doc["body"] = "bar";
  doc["userId"] = 1;

  serializeJson(doc, content);

  logger.info("sending " + content);

  String res = ESPAdmin::HTTP::post("/posts", content, "application/json");

  logger.info(res);

  delay(5000);
}
