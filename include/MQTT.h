#ifndef H_ESP_ADMIN_MQTT
#define H_ESP_ADMIN_MQTT

#include <Arduino.h>
#include "Logger.h"
#include "Store.h"
#include <mqtt_client.h>
#include "Command.h"
#include "Report.h"

#ifndef MQTT_TASK_STACK_SIZE
#define MQTT_TASK_STACK_SIZE 6896 // StackHighWaterMark = 4848 bytes
#endif

#ifndef MQTT_KEEP_ALIVE_SEC
#define MQTT_KEEP_ALIVE_SEC 30
#endif

#ifndef MQTT_NETWORK_TIMEOUT_MS
#define MQTT_NETWORK_TIMEOUT_MS 8000
#endif

#ifndef MQTT_RECONNECT_TIMEOUT_MS
#define MQTT_RECONNECT_TIMEOUT_MS 10000
#endif

#ifndef MQTT_TASK_PRIORITY
#define MQTT_TASK_PRIORITY 5
#endif

namespace ESPAdmin
{
    class Logger;

    class MQTT
    {
    public:
        static void connect();
        static void disconnect();
        static void publish(const String &topic, const String &message, unsigned qos, bool retain);
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