#include "NVS.hpp"

namespace ESPAdmin
{
    Logger NVS::_logger("NVS");

    /**
     * Initializes the NVS module and opens a namespace for reading and writing.
     *
     * @param _namespace The name of the namespace to open.
     *
     * @throws None.
     */
    void NVS::begin(const char *_namespace)
    {
        esp_err_t err = nvs_flash_init();

        if (err == ESP_ERR_NVS_NO_FREE_PAGES || err == ESP_ERR_NVS_NEW_VERSION_FOUND)
        {
            _logger.info("partition needs to be erased");

            ESP_ERROR_CHECK(nvs_flash_erase());

            err = nvs_flash_init();
        }

        ESP_ERROR_CHECK(err);

        err = nvs_open(_namespace, NVS_READWRITE, &_handler);

        if (err != ESP_OK)
        {
            _logger.error("failed to open namespace");
        }
        else
        {
            _logger.success("ready");
        }
    }

    /**
     * Retrieves a string value from the NVS (Non-Volatile Storage) with the given key.
     *
     * @param key The key of the string value to retrieve.
     *
     * @return The retrieved string value if it exists, an empty string otherwise.
     *
     * @throws None
     */
    std::string NVS::getString(const char *key) const
    {
        size_t required_size;
        esp_err_t err = nvs_get_str(_handler, key, nullptr, &required_size);

        if (err != ESP_OK || required_size == 0)
        {
            return "";
        }

        char value[required_size];
        err = nvs_get_str(_handler, key, value, &required_size);

        if (err != ESP_OK)
        {
            return "";
        }

        return std::string(value);
    }

    /**
     * Sets a string value in the NVS (Non-Volatile Storage) with the given key.
     *
     * @param key The key of the string value to set.
     * @param value The string value to set. If nullptr, an empty string will be set.
     *
     * @throws None.
     */
    void NVS::setString(const char *key, const char *value) const
    {
        const char *valueToSet = (value == nullptr) ? "" : value;

        esp_err_t err = nvs_set_str(_handler, key, valueToSet);
        if (err != ESP_OK)
        {
            _logger.warn("failed to write value of %s", key);
            return;
        }

        err = nvs_commit(_handler);
        if (err != ESP_OK)
        {
            _logger.warn("failed to commit value of %s", key);
        }
    }

    /**
     * Clears all the data stored in the NVS (Non-Volatile Storage) by erasing all the keys and committing the changes.
     *
     * @throws None
     */
    void NVS::clear() const
    {
        nvs_erase_all(_handler);
        nvs_commit(_handler);
    }
}
