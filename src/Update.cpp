#include "Update.h"

namespace ESPAdmin
{
    UpdateMessage Update::_message;
    Logger Update::_logger("Update");

    void Update::checkAndUpdate(const UpdateMessage &message)
    {
        _message = message;

        String currentReleaseId = Store::get(STORE_UPDATE_RELEASE_ID);
        String currentVersion = Store::get(STORE_UPDATE_VERSION);

        if (currentReleaseId == _message.releaseId)
        {
            _logger.info("Already updated with release %s version %s", currentReleaseId.c_str(), currentVersion.c_str());
        }
        else
        {
            _logger.info("Update to release %s version %s", _message.releaseId.c_str(), _message.version.c_str());
            String downloadURL = "https://" + String(Store::httpHost) + message.downloadPath;
            OTA::start(downloadURL);
        }
    }

    void Update::onChange(const UpdateStatus &status)
    {
        switch (status)
        {
        case UPDATE_STARTED:
            _onStart();
            break;
        case UPDATE_SUCCEDED:
            _onSuccess();
            break;
        case UPDATE_FAILED:
            _onFail();
            break;
        }
    }

    void Update::_onSuccess()
    {
        _logger.success("succeded");
        Report::sendUpdate(_message, "succeded");

        Store::set(STORE_UPDATE_RELEASE_ID, _message.releaseId.c_str());
        Store::set(STORE_UPDATE_VERSION, _message.version.c_str());

        // Wait for MQTT publish to finish
        delay(UPDATE_RESET_DELAY_MS);

        esp_restart();
    }

    void Update::_onFail()
    {
        _logger.error("failed");

        Report::sendUpdate(_message, "failed");
    }

    void Update::_onStart()
    {
        _logger.info("started");

        Report::sendUpdate(_message, "started");
    }
}
