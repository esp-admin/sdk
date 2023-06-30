#include "OTA.h"

namespace ESPAdmin
{
    Logger OTA::_logger("OTA");

    void OTA::start(String downloadURL)
    {
        String cert = Store::get(STORE_UPDATE_CERT);

        char *_cert = new char[cert.length() + 1];
        strcpy(_cert, cert.c_str());

        HttpsOTA.onHttpEvent([](HttpEvent_t *event) {});
        HttpsOTA.begin(downloadURL.c_str(), _cert);

        bool running = true;

        _onStart();

        while (running)
        {
            switch (HttpsOTA.status())
            {
            case HTTPS_OTA_UPDATING:
                _logger.info("update running");
                break;

            case HTTPS_OTA_SUCCESS:
                running = false;
                _onSuccess();
                break;

            case HTTPS_OTA_FAIL:
                running = false;
                _onFailed();
                break;
            }

            delay(2000);
        }
    }

    void OTA::_onStart()
    {
        Store::updateRunning = true;
        _logger.info("update started");
    }

    void OTA::_onSuccess()
    {
        Store::updateRunning = false;
        _logger.success("update succeeded");
    }

    void OTA::_onFailed()
    {
        Store::updateRunning = false;
        _logger.error("update failed");
    }
}