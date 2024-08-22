/*
This example demonstrate basic counter increment/decrement via ESP Admin with TFT display.

Instructions:
- Setup TFT_eSPI https://github.com/Bodmer/TFT_eSPI
- Setup LVGL https://docs.lvgl.io/latest/en/html/get-started/arduino.html
- Setup TFT_SCREEN_WIDTH and TFT_SCREEN_HEIGHT in <TFT.h>
- Setup <config.h>
- Create counter_step project variable
- Create counter_inc and counter_dec project commands
*/

#include <Arduino.h>
#include <UI.h>
#include <ESPAdmin.h>
#include <config.h>
#include <WiFi.h>

using namespace ESPAdmin;

UI ui;
Logger logger("app");

struct
{
  int value = 0;
  int step = 1;
} counter;

void onCommand(std::string message);
void onConfig(std::string message);

void setup()
{
  ui.setup();

  WiFi.begin(ssid, password);

  logger.info("WiFi wait");

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
  }

  logger.success("WiFi connected");

  ESPAdmin::begin({
      .httpHost = httpHost,
      .deviceId = deviceId,
      .apiKey = apiKey,
      .httpCert = httpCert,
      .mqttCert = mqttCert,
  });

  Command::onCustom = &onCommand;
  Command::onConfig = &onConfig;

  lv_scr_load_anim(ui.screen2, LV_SCR_LOAD_ANIM_FADE_ON, 1000, 0, true);

  lv_label_set_text(ui.label2, Store::get(STORE_UPDATE_VERSION).c_str());
}

void loop()
{
  if (Store::updateRunning)
  {
    lv_obj_set_style_border_color(ui.screen2, lv_color_hex(COLOR_BLUE_700), _LV_STYLE_STATE_CMP_SAME);
  }
  else if (Store::mqttConnected)
  {
    lv_obj_set_style_border_color(ui.screen2, lv_color_hex(COLOR_GREEN_700), _LV_STYLE_STATE_CMP_SAME);
  }
  else
  {
    lv_obj_set_style_border_color(ui.screen2, lv_color_hex(COLOR_RED_700), _LV_STYLE_STATE_CMP_SAME);
  }

  delay(500);
}

void onCommand(std::string msg)
{
  StaticJsonDocument<100> doc;

  DeserializationError error = deserializeJson(doc, msg);

  if (error != DeserializationError::Ok)
  {
    logger.error("deserializeJson() failed\n");
    return;
  }

  const char *key = doc["key"];

  if (strcmp(key, "counter_inc") == 0)
  {
    counter.value += counter.step;
  }
  else if (strcmp(key, "counter_dec") == 0)
  {
    counter.value -= counter.step;
  }

  lv_label_set_text_fmt(ui.label1, "%d", counter.value);
  logger.info("counter %d", counter);
}

void onConfig(std::string msg)
{
  StaticJsonDocument<100> doc;

  DeserializationError error = deserializeJson(doc, msg);

  if (error != DeserializationError::Ok)
  {
    logger.error("deserializeJson() failed\n");
    return;
  }

  sscanf(doc["counter_step"], "%d", &counter.step);
}