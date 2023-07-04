#include "ESPAdmin.h"

namespace ESPAdmin
{
  void begin(const char *httpHost, const char *deviceId, const char *apiKey)
  {
    Store::begin(httpHost, deviceId, apiKey);

    MQTT::connect();
  }
}
