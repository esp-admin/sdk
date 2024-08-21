#ifndef H_ESP_ADMIN_MQTT
#define H_ESP_ADMIN_MQTT

#include "Logger.hpp"
#include "Store.hpp"
#include <mqtt_client.h>
#include "Command.hpp"
#include "Report.hpp"
#include <esp_idf_version.h>

namespace ESPAdmin
{
    class Logger;

    class MQTT
    {
    public:
        static void connect();
        static void disconnect();
        static void publish(const std::string &topic, const std::string &message, unsigned qos, bool retain);
        static void publish(const std::string &topic, const char *message, int len, unsigned qos, bool retain);
        static void subscribe(const std::string &topic, unsigned qos);
        ~MQTT();

    private:
        static Logger _logger;
        static esp_mqtt_client_handle_t _client;
        static void _onEvent(void *handler_args, esp_event_base_t base, int32_t event_id, void *event_data);
        static void _onConnected();
        static void _onDisconnected();
        static void _onSubscribed();
        static void _onDataArrived(const std::string &topic, const std::string &message);
    };
}

#endif