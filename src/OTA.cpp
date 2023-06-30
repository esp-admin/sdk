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

        Store::updateRunning = true;

        _onStart();

        while (Store::updateRunning)
        {
            switch (HttpsOTA.status())
            {
            case HTTPS_OTA_UPDATING:
                _logger.info("update running");
                break;

            case HTTPS_OTA_SUCCESS:
                Store::updateRunning = false;
                _onSuccess();
                break;

            case HTTPS_OTA_FAIL:
                Store::updateRunning = false;
                _onFailed();
                break;
            }

            delay(2000);
        }
    }

    void OTA::_onStart()
    {
        _logger.info("update started");
        Update::onChange(UPDATE_RUNNING);
    }

    void OTA::_onSuccess()
    {
        _logger.success("update succeeded");
        Update::onChange(UPDATE_SUCCESS);
    }

    void OTA::_onFailed()
    {
        _logger.error("update failed");
        Update::onChange(UPDATE_FAILED);
    }
}