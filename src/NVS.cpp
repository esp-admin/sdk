#include "NVS.h"

namespace ESPAdmin
{
    Logger NVS::_logger("NVS");

    void NVS::begin(const char *_namespace)
    {
        esp_err_t err = nvs_flash_init();

        if (err == ESP_ERR_NVS_NO_FREE_PAGES || err == ESP_ERR_NVS_NEW_VERSION_FOUND)
        {
            _logger.info("partition was truncated and needs to be erased");

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

    String NVS::getString(const char *key) const
    {
        size_t required_size;
        nvs_get_str(_handler, key, nullptr, &required_size);
        char value[required_size];
        nvs_get_str(_handler, key, value, &required_size);

        return String(value);
    }

    void NVS::setString(const char *key, const char *value) const
    {
        esp_err_t err = nvs_set_str(_handler, key, value == nullptr ? "" : value);

        nvs_commit(_handler);

        if (err != ESP_OK)
        {
            _logger.warn("failed to write string %s", key);
        }
    }

    void NVS::clear() const
    {
        nvs_erase_all(_handler);
        nvs_commit(_handler);
    }
}
