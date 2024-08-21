#include "ESPAdmin.h"

namespace ESPAdmin
{
  /**
   * Initializes the ESPAdmin library with the provided options.
   *
   * @param options The initialization options for the ESPAdmin library.
   *
   * @throws None
   */
  void begin(InitOptions options)
  {
    options.resetDelayMs = DEFAULT_INT(options.resetDelayMs, 7000);
    options.httpMaxResponseSize = DEFAULT_INT(options.httpMaxResponseSize, 300);
    options.httpTimeoutMs = DEFAULT_INT(options.httpTimeoutMs, 15000);
    options.logMaxMessageSize = DEFAULT_INT(options.logMaxMessageSize, 200);
    options.mqttTaskPriority = DEFAULT_INT(options.mqttTaskPriority, 5);
    options.mqttTaskStackSize = DEFAULT_INT(options.mqttTaskStackSize, 9640); // Stack used 4820 bytes
    options.mqttKeepAliveSec = DEFAULT_INT(options.mqttKeepAliveSec, 30);
    options.mqttNetworkTimeoutMs = DEFAULT_INT(options.mqttNetworkTimeoutMs, 8000);
    options.mqttReconnectTimeoutMs = DEFAULT_INT(options.mqttReconnectTimeoutMs, 10000);
    options.otaTaskPriority = DEFAULT_INT(options.otaTaskPriority, 5);
    options.otaTaskStackSize = DEFAULT_INT(options.otaTaskStackSize, 6928); // Stack used 3464 bytes

    Store::begin(options);
    // MQTT::connect();
  }
}