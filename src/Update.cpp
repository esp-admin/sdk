#include "Update.h"

namespace ESPAdmin
{
    UpdateMessage Update::_message;
    Logger Update::_logger("Update");

    void Update::checkAndUpdate(UpdateMessage message)
    {
        _message = message;

        String currentReleaseId = Store::get(STORE_UPDATE_RELEASE_ID);

        if (currentReleaseId != _message.releaseId)
        {
            OTA::start(message.downloadURL);
        }
        else
        {
            _logger.info("already updated");
        }
    }

    void Update::onChange(UpdateStatus status)
    {
        switch (status)
        {
        case UPDATE_SUCCESS:
            Store::set(STORE_UPDATE_RELEASE_ID, _message.releaseId);
            break;
        }
    }
}
