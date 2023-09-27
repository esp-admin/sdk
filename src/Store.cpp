#include "Store.h"

namespace ESPAdmin
{
    Logger Store::_logger("Store");
    NVS Store::_NVS;

    const char *Store::_namespace = "esp_admin";

    bool Store::mqttConnected = false;
    bool Store::logRemoteEnabled = true;
    bool Store::logSerialEnabled = true;
    bool Store::updateRunning = false;

    const char *Store::deviceId;
    const char *Store::httpHost;
    const char *Store::apiKey;
    const char *Store::certPem;

    void Store::begin(const char *httpHost, const char *deviceId, const char *apiKey, const char *certPem)
    {
        _NVS.begin(_namespace);

        // _NVS.clear();

        Store::httpHost = httpHost;
        Store::deviceId = deviceId;
        Store::apiKey = apiKey;
        Store::certPem = certPem;

        _getSettings();
    }

    const char *Store::get(StoreKey key)
    {
        return _NVS.getString(String(key).c_str());
    }

    void Store::set(StoreKey key, const char *value)
    {
        _NVS.setString(String(key).c_str(), value);
    }

    void Store::_getSettings()
    {
        String settings = HTTP::get("/settings");

        if (settings.length() == 0)
        {
            _logger.warn("could not fetch settings");
            return;
        }

        StaticJsonDocument<384> doc;

        DeserializationError error = deserializeJson(doc, settings);

        const char *uriTCP = doc["uriTCP"];
        const char *uriWS = doc["uriWS"];
        const char *username = doc["username"];
        const char *password = doc["password"];

        set(STORE_MQTT_USERNAME, username);
        set(STORE_MQTT_PASSWORD, password);
        set(STORE_MQTT_URI_TCP, uriTCP);
        set(STORE_MQTT_URI_WS, uriWS);

        _logger.success("settings saved");
    }
}
