#include "ESPAdmin.h"

namespace ESPAdmin
{
    void begin()
    {
        Logger::begin();

        Logger logger("init");

        logger.success("ESP Admin ready");
        logger.error("ESP Admin ready");
        logger.warn("ESP Admin ready");
        logger.info("ESP Admin ready");
    }
}
