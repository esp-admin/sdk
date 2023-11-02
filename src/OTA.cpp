#include "OTA.h"

namespace ESPAdmin
{
    Logger OTA::_logger("OTA");
    String OTA::_downloadURL;

    void OTA::start(const String &downloadURL)
    {
        _downloadURL = downloadURL;
        xTaskCreatePinnedToCore(task, "ota_start", OTA_TASK_STACK_SIZE, nullptr, OTA_TASK_PRIORITY, nullptr, 1);
    }

    void OTA::task(void *)
    {
        esp_http_client_config_t config = {
            .url = _downloadURL.c_str(),
            .cert_pem = Store::httpCert,
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

         vTaskDelete(nullptr);
    }
}