#include <Arduino.h>
#include <WiFi.h>
#include <ESPAdmin.h>
#include <credentials.h>

ESPAdmin::Logger logger("app");

void onCustomCommand(std::string message);

void setup()
{
    WiFi.begin(ssid, password);

    logger.info("WiFi wait");

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(1000);
    }

    logger.success("WiFi connected");

    ESPAdmin::begin({
        .httpHost = httpHost,
        .deviceId = deviceId,
        .apiKey = apiKey,
        .httpCert = httpCert,
        .mqttCert = mqttCert,
    });

    ESPAdmin::Command::onCustom = &onCustomCommand;
}

void onCustomCommand(std::string message)
{
    logger.info("Handling command %s", message.c_str());
}

void loop()
{
}