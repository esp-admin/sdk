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
            _logger.info("already updated with version %s", currentVersion.c_str());
        }
        else if (Store::updateRunning)
        {
            _logger.warn("already update is running");
        }
        else
        {
            _logger.info("update to version %s", _message.version.c_str());
            String downloadURL = "https://" + String(Store::options.httpHost) + message.downloadPath;
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
        default:
            break;
        }
    }

    [[noreturn]] void Update::_onSuccess()
    {
        _logger.success("succeded");
        Report::sendUpdateStatus(_message, "succeded");

        Store::set(STORE_UPDATE_RELEASE_ID, _message.releaseId.c_str());
        Store::set(STORE_UPDATE_VERSION, _message.version.c_str());

        Report::sendStatus("disconnected");

        // Wait for MQTT publish to finish
        delay(Store::options.resetDelayMs);

        esp_restart();
    }

    void Update::_onFail()
    {
        _logger.error("failed");

        Report::sendUpdateStatus(_message, "failed");
    }

    void Update::_onStart()
    {
        _logger.info("started");

        Report::sendUpdateStatus(_message, "started");
    }

    void Update::onProgress(int imageRead)
    {
        if (_message.downloadSize > 0)
        {
            int progress = (imageRead * 100) / _message.downloadSize;
            Report::sendUpdateProgress(_message, progress);
        }
    }
}
