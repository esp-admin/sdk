#ifndef H_ESP_ADMIN_MQTT
#define H_ESP_ADMIN_MQTT

#include <Arduino.h>
#include "Logger.h"
#include "Store.h"
#include <mqtt_client.h>
#include "Command.h"
#include "Report.h"

namespace ESPAdmin
{
    class Logger;

    class MQTT
    {
    public:
        static void connect();
        static void disconnect();
        static void publish(const String &topic, const String &message, unsigned qos, bool retain);
        static void publish(const String &topic, const char *message, int len, unsigned qos, bool retain);
        static void subscribe(const String &topic, unsigned qos);
        ~MQTT();

    private:
        static Logger _logger;
        static esp_mqtt_client_handle_t _client;
        static void _onEvent(void *handler_args, esp_event_base_t base, int32_t event_id, void *event_data);
        static void _onConnected();
        static void _onDisconnected();
        static void _onSubscribed();
        static void _onDataArrived(const String &topic, const String &message);
    };
}

#endif