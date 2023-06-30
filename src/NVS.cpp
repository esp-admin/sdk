#include "NVS.h"

namespace ESPAdmin
{
    Logger NVS::_logger("NVS");

    void NVS::begin(String _namespace)
    {
        esp_err_t err = nvs_flash_init();

        if (err == ESP_ERR_NVS_NO_FREE_PAGES || err == ESP_ERR_NVS_NEW_VERSION_FOUND)
        {
            _logger.info("NVS partition was truncated and needs to be erased");
            ESP_ERROR_CHECK(nvs_flash_erase());
            err = nvs_flash_init();
        }
        ESP_ERROR_CHECK(err);

        err = nvs_open(_namespace.c_str(), NVS_READWRITE, &_handler);

        if (err != ESP_OK)
        {
            _logger.error("failed to open namespace");
        }
        else
        {
            _logger.success("ready");
        }
    }

    String NVS::getString(String key)
    {
        size_t required_size;
        nvs_get_str(_handler, key.c_str(), NULL, &required_size);
        char *value = (char *)malloc(required_size);
        nvs_get_str(_handler, key.c_str(), value, &required_size);

        return String(value);
    }

    void NVS::setString(String key, String value)
    {
        esp_err_t err = nvs_set_str(_handler, key.c_str(), value.c_str());

        nvs_commit(_handler);

        if (err != ESP_OK)
        {
            _logger.warn("failed to write string " + key);
        }
    }

    void NVS::clear()
    {
        nvs_erase_all(_handler);
        nvs_commit(_handler);
    }
}
