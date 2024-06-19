#include "OTA.h"

namespace ESPAdmin
{
    Logger OTA::_logger("OTA");
    String OTA::_downloadURL;

    void OTA::start(const String &downloadURL)
    {
        _downloadURL = downloadURL;
        xTaskCreatePinnedToCore(task, "ota_start", Store::options.otaTaskStackSize, nullptr, Store::options.otaTaskPriority, nullptr, 1);
    }

    void OTA::task(void *)
    {

        esp_http_client_config_t httpConfig = {
            .url = _downloadURL.c_str(),
            .cert_pem = Store::options.httpCert,
            .timeout_ms = Store::options.httpTimeoutMs,
        };

        esp_https_ota_config_t otaConfig = {
            .http_config = &httpConfig,
        };

        Store::updateRunning = true;
        Update::onChange(UPDATE_STARTED);

        esp_https_ota_handle_t otaHandle;

        esp_err_t ret = esp_https_ota_begin(&otaConfig, &otaHandle);

        if (ret != ESP_OK)
        {
            Store::updateRunning = false;
            Update::onChange(UPDATE_FAILED);
        }

        while (Store::updateRunning)
        {
            esp_err_t ret = esp_https_ota_perform(otaHandle);

            if (ret == ESP_ERR_HTTPS_OTA_IN_PROGRESS)
            {
                continue;
            }
            else if (ret == ESP_OK)
            {
                Store::updateRunning = false;

                bool completed = esp_https_ota_is_complete_data_received(otaHandle);

                if (completed)
                {
                    Update::onChange(UPDATE_SUCCEDED);
                }
                else
                {
                    Update::onChange(UPDATE_FAILED);
                }
            }
            else
            {
                Store::updateRunning = false;
                Update::onChange(UPDATE_FAILED);
            }
        }

        esp_https_ota_finish(otaHandle);
        vTaskDelete(nullptr);
    }
}