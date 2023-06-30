#ifndef H_ESP_ADMIN_STORE
#define H_ESP_ADMIN_STORE

#include "types.h"
#include "NVS.h"
#include <Arduino.h>

namespace ESPAdmin
{
    class NVS;

    class Store
    {
    public:
        static void begin();

        // CA Certificates
        static const char *ISRG_ROOT_X1;

        // Configurations
        static String get(StoreKey key);
        static void set(StoreKey key, String value);

        // States
        static bool mqttConnected;
        static bool updateRunning;
        static bool debugSerialEnabled;
        static bool debugRemoteEnabled;
        static String deviceId;
        static String mac;

    private:
        static NVS _NVS;
        static String _namespace;
    };
}

#endif