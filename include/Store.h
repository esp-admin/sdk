#ifndef H_ESP_ADMIN_STORE
#define H_ESP_ADMIN_STORE

#include "types.h"
#include "NVS.h"
#include <Arduino.h>
#include "HTTP.h"
#include "Logger.h"
#include "Store.h"

#define DEFAULT_INT(x, y) (x == 0 ? y : x)

namespace ESPAdmin
{
    class NVS;

    class Store
    {
    public:
        static void begin(const InitOptions &options);
        static void set(StoreKey key, const char *value);
        static String get(StoreKey key);

        // States
        static bool mqttConnected;
        static bool updateRunning;
        static bool logSerialEnabled;
        static bool logRemoteEnabled;

        // constants
        static InitOptions options;

    private:
        static NVS _NVS;
        static const char *_namespace;
        static void _getSettings();
        static Logger _logger;
    };
}

#endif