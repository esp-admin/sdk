#include "ESPAdmin.h"

namespace ESPAdmin
{
  void begin(String httpHost, String deviceId, String apiKey)
  {
    Store::begin(httpHost, deviceId, apiKey);

    MQTT::connect();
  }
}
