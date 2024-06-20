#include "Update.h"

namespace ESPAdmin
{
    UpdateMessage Update::_message;
    Logger Update::_logger("Update");

    /**
     * Checks if an update is available and initiates the update process if necessary.
     *
     * @param message the update message containing information about the update
     *
     * @throws None
     */
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

    /**
     * Handles the change of the update status.
     *
     * @param status the current update status
     *
     * @throws None
     */
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

    /**
     * A method to handle the progress of an update process.
     *
     * @param imageRead The number of bytes read for the update.
     *
     * @return None
     *
     * @throws None
     */
    void Update::onProgress(int imageRead)
    {
        if (_message.downloadSize > 0)
        {
            int progress = (imageRead * 100) / _message.downloadSize;
            Report::sendUpdateProgress(_message, progress);
        }
    }

    /**
     * Abort Update process.
     *
     * @param releaseId The release id of the update.
     *
     * @return None.
     *
     * @throws None.
     */
    void Update::abort(const String &releaseId)
    {
        if (_message.releaseId == releaseId)
        {
            OTA::abort();
        }
    }
}
