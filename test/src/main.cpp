#include <Arduino.h>
#include <WiFi.h>
#include "ESPAdmin.h"

const char *httpHost = "esp-admin-app.bg.tn";      // Should be secured (over HTTPS)
const char *deviceId = "65043be911b195e46ae16a12"; // Device identifier
const char *apiKey = "tester123";                  // Device API key
const char *ssid = "ASUS_AP";                      // WiFi station SSID
const char *password = "pass1234";                 // WiFi station password

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

  pinMode(2, OUTPUT);
}

void loop()
{
  digitalWrite(2, HIGH);
  delay(500);
  digitalWrite(2, LOW);
  delay(1000);
}