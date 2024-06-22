#include "Store.h"

namespace ESPAdmin
{
    Logger Store::_logger("Store");
    NVS Store::_NVS;

    const char *Store::_namespace = "esp_admin";

    bool Store::mqttConnected = false;
    bool Store::logRemoteEnabled = false;
    bool Store::logSerialEnabled = true;
    bool Store::updateRunning = false;

    InitOptions Store::options;

    /**
     * Initializes the Store with the provided initialization options.
     *
     * @param options The initialization options for the Store.
     *
     * @throws None
     */
    void Store::begin(const InitOptions &options)
    {
        _NVS.begin(_namespace);

        Store::options = options;

        _getSettings();
    }

    /**
     * Retrieves a string value from the NVS (Non-Volatile Storage) using the provided key.
     *
     * @param key The key of the string value to retrieve.
     *
     * @return The retrieved string value if it exists, an empty string otherwise.
     *
     * @throws None
     */
    String Store::get(StoreKey key)
    {
        return _NVS.getString(String(key).c_str());
    }

    /**
     * Sets a string value in the NVS (Non-Volatile Storage) with the given key.
     *
     * @param key The key of the string value to set.
     * @param value The string value to set. If nullptr, an empty string will be set.
     *
     * @return None
     *
     * @throws None.
     */
    void Store::set(StoreKey key, const char *value)
    {
        _NVS.setString(String(key).c_str(), value);
    }

    void Store::_getSettings()
    {
        String settings = HTTP::get("/settings");

        if (settings.length() == 0)
        {
            _logger.warn(F("could not fetch settings"));
            return;
        }

        StaticJsonDocument<384> doc;

        DeserializationError error = deserializeJson(doc, settings);

        if (error == DeserializationError::Ok)
        {
            const char *uriTCP = doc["uriTCP"];
            const char *uriWS = doc["uriWS"];
            const char *username = doc["username"];
            const char *password = doc["password"];

            set(STORE_MQTT_USERNAME, username);
            set(STORE_MQTT_PASSWORD, password);
            set(STORE_MQTT_URI_TCP, uriTCP);
            set(STORE_MQTT_URI_WS, uriWS);

            _logger.success(F("settings saved"));
        }
        else
        {
            _logger.warn(F("failed to deserialize Json"));
        }
    }
}
