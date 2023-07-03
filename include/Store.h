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
        static void set(StoreKey key, String value);
        static String get(StoreKey key);

        // CA Certificates
        static const char *ISRG_ROOT_X1;

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