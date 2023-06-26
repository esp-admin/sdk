#ifndef H_ESP_ADMIN_MQTT
#define H_ESP_ADMIN_MQTT

#include <Arduino.h>

namespace ESPAdmin
{
    class MQTT
    {
    public:
        void connect();
        void disconnect();
        void publish(String topic, String message);
        void subscribe(String topic);

    private:
        void _onReceive(String topic, String message);
    };
}

#endif