#ifndef H_ESP_ADMIN_STORE
#define H_ESP_ADMIN_STORE

#include "types.h"
#include "NVS.h"
#include <Arduino.h>
#include "HTTP.h"
#include "Logger.h"

namespace ESPAdmin
{
    class NVS;

    class Store
    {
    public:
        static void begin(String httpHost, String deviceId, String apiKey);
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
        static String httpHost;
        static String apiKey;

    private:
        static NVS _NVS;
        static String _namespace;
        static void _getSettings();
        static Logger _logger;
    };
}

#endif