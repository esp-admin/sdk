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
        static void begin(const char *httpHost, const char *deviceId, const char *apiKey);
        static void set(StoreKey key, const char *value);
        static const char *get(StoreKey key);

        // States
        static bool mqttConnected;
        static bool updateRunning;
        static bool logSerialEnabled;
        static bool logRemoteEnabled;

        // constants
        static const char *deviceId;
        static const char *httpHost;
        static const char *apiKey;
        static const char *ISRG_ROOT_X1;

    private:
        static NVS _NVS;
        static const char *_namespace;
        static void _getSettings();
        static Logger _logger;
    };
}

#endif