#include <Arduino.h>
#include <WiFi.h>
#include "ESPAdmin.h"
#include "credentials.h"
#include <ArduinoJson.h>

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

  ESPAdmin::begin(httpHost, deviceId, apiKey, httpCert, mqttCert);

  ESPAdmin::Command::onCustom = &onCustomCommand;

  pinMode(2, OUTPUT);
}

void onCustomCommand(String message)
{
  logger.info("Handling command " + message);
}

void loop()
{
  digitalWrite(2, HIGH);
  delay(500);
  digitalWrite(2, LOW);
  delay(500);
}