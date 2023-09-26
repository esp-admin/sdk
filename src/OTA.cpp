#include "OTA.h"

namespace ESPAdmin
{
    Logger OTA::_logger("OTA");

    void OTA::start(String downloadURL)
    {
        esp_http_client_config_t config = {
            .url = downloadURL.c_str(),
            .cert_pem = Store::certPem,
            .timeout_ms = HTTP_TIMEOUT_MS,
        };

        Update::onChange(UPDATE_STARTED);

        Store::updateRunning = true;

        esp_err_t ret = esp_https_ota(&config);

        if (ret == ESP_OK)
        {
            Store::updateRunning = false;
            Update::onChange(UPDATE_SUCCEDED);
        }
        else
        {
            Store::updateRunning = false;
            Update::onChange(UPDATE_FAILED);
        }
    }
}