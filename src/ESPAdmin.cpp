#include "ESPAdmin.h"

namespace ESPAdmin
{
  void begin(InitOptions options)
  {
    options.resetDelayMs = DEFAULT_INT(options.resetDelayMs, 7000);
    options.httpMaxResponseSize = DEFAULT_INT(options.httpMaxResponseSize, 300);
    options.httpTimeoutMs = DEFAULT_INT(options.httpTimeoutMs, 8000);
    options.logMaxMessageSize = DEFAULT_INT(options.logMaxMessageSize, 100);
    options.mqttTaskPriority = DEFAULT_INT(options.mqttTaskPriority, 5);
    options.mqttTaskStackSize = DEFAULT_INT(options.mqttTaskStackSize, 6896); // StackHighWaterMark = 4848 bytes
    options.mqttKeepAliveSec = DEFAULT_INT(options.mqttKeepAliveSec, 30);
    options.mqttNetworkTimeoutMs = DEFAULT_INT(options.mqttNetworkTimeoutMs, 8000);
    options.mqttReconnectTimeoutMs = DEFAULT_INT(options.mqttReconnectTimeoutMs, 10000);
    options.otaTaskPriority = DEFAULT_INT(options.otaTaskPriority, 5);
    options.otaTaskStackSize = DEFAULT_INT(options.otaTaskStackSize, 6896); // StackHighWaterMark = 3384 bytes

    Store::begin(options);

    MQTT::connect();
  }
}