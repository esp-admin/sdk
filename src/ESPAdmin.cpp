#include "ESPAdmin.h"

namespace ESPAdmin
{
  void begin()
  {
    Store::begin();

    MQTT::connect();
  }
}
