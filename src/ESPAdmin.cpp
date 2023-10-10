#include "ESPAdmin.h"

namespace ESPAdmin
{
  void begin(const char *httpHost, const char *deviceId, const char *apiKey, const char *httpCert, const char *mqttCert)
  {
    Store::begin(httpHost, deviceId, apiKey, httpCert, mqttCert);

    MQTT::connect();
  }
}
