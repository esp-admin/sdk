#include "ESPAdmin.h"

namespace ESPAdmin
{
  void begin(const char *httpHost, const char *deviceId, const char *apiKey, const char *certPem)
  {
    Store::begin(httpHost, deviceId, apiKey, certPem);

    MQTT::connect();
  }
}
