#include "OTA.h"

namespace ESPAdmin
{
    Logger OTA::_logger("OTA");

    void OTA::start(String downloadURL)
    {
        Update::onChange(UPDATE_STARTED);

        _logger.info("@ " + downloadURL);

        HttpsOTA.onHttpEvent([](HttpEvent_t *event) {});
        HttpsOTA.begin(downloadURL.c_str(), Store::ISRG_ROOT_X1);

        Store::updateRunning = true;

        while (Store::updateRunning)
        {
            switch (HttpsOTA.status())
            {
            case HTTPS_OTA_SUCCESS:
                Store::updateRunning = false;
                Update::onChange(UPDATE_SUCCEDED);
                break;

            case HTTPS_OTA_FAIL:
                Store::updateRunning = false;
                Update::onChange(UPDATE_FAILED);
                break;
            }

            delay(1000);
        }
    }
}