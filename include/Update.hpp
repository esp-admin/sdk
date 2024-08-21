#ifndef H_ESP_ADMIN_UPDATE
#define H_ESP_ADMIN_UPDATE

#include "types.hpp"
#include "Store.hpp"
#include "OTA.hpp"
#include "Logger.hpp"
#include "Report.hpp"

namespace ESPAdmin
{
    class Logger;

    class Update
    {
    public:
        static void checkAndUpdate(const UpdateMessage &message);
        static void onChange(const UpdateStatus &status);
        static void onProgress(int imageRead);
        static void abort(const std::string &releaseId);

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