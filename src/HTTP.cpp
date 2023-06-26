#include "HTTP.h"

namespace ESPAdmin
{

    DynamicJsonDocument HTTP::get(String path)
    {
        DynamicJsonDocument doc(100);
        return doc;
    }

    void HTTP::patch(String path, DynamicJsonDocument body)
    {
    }

    void HTTP::post(String path, DynamicJsonDocument body)
    {
    }
}
