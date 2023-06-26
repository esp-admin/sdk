#include "Store.h"

namespace ESPAdmin
{
    Debug Store::debug = {
        baudrate : 9600,
        serial : true,
        remote : false,
    };

    Mqtt Store::mqtt = {
        connected : false,
        uriTCP : "",
        uriWS : "",
        clientId : "",
        username : "",
        password : "",
        certificate : ""
    };
}
