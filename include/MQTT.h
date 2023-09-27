#ifndef H_ESP_ADMIN_MQTT
#define H_ESP_ADMIN_MQTT

#include <Arduino.h>
#include "Logger.h"
#include "Store.h"
#include <mqtt_client.h>
#include "Command.h"
#include "Report.h"

#define MQTT_TASK_STACK_SIZE 8 * 1024
#define MQTT_KEEP_ALIVE_SEC 30
#define MQTT_NETWORK_TIMEOUT_MS 8000
#define MQTT_RECONNECT_TIMEOUT_MS 10000

namespace ESPAdmin
{
    class Logger;

    class MQTT
    {
    public:
        static void connect();
        static void disconnect();
        static void publish(String topic, String message, unsigned qos, bool retain);
        static void subscribe(String topic, unsigned qos);

    private:
        static Logger _logger;
        static esp_mqtt_client_handle_t _client;
        static void _onEvent(void *handler_args, esp_event_base_t base, int32_t event_id, void *event_data);
        static void _onConnected();
        static void _onDisconnected();
        static void _onSubscribed();
        static void _onDataArrived(String topic, String message);
    };
}

#endif