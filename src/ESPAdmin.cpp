#include "ESPAdmin.h"

namespace ESPAdmin
{
    void begin()
    {
        MQTT::connect();
    }
}
