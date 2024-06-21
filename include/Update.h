#ifndef H_ESP_ADMIN_UPDATE
#define H_ESP_ADMIN_UPDATE

#include <Arduino.h>
#include "types.h"
#include "Store.h"
#include "OTA.h"
#include "Logger.h"
#include "Report.h"

namespace ESPAdmin
{
    class Logger;

    class Update
    {
    public:
        static void checkAndUpdate(const UpdateMessage &message);
        static void onChange(const UpdateStatus &status);
        static void onProgress(int imageRead);
        static void abort(const String &releaseId);

    private:
        static UpdateMessage _message;
        static Logger _logger;
        static unsigned int _progress;
        static void _onSuccess();
        static void _onFail();
        static void _onStart();
    };
}

#endif