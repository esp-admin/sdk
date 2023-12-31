#include "MQTT.h"

namespace ESPAdmin
{
    Logger MQTT::_logger("MQTT");

    esp_mqtt_client_handle_t MQTT::_client;

    void MQTT::connect()
    {
        const String uriWS = Store::get(STORE_MQTT_URI_WS);
        const String uriTCP = Store::get(STORE_MQTT_URI_TCP);
        const String username = Store::get(STORE_MQTT_USERNAME);
        const String password = Store::get(STORE_MQTT_PASSWORD);

        const char lwtMessage[] = R"({"status":"disconnected"})";

        String lwtTopic = "device/" + String(Store::deviceId) + "/report/status";

        String uri = uriTCP.length() > 3 ? uriTCP : uriWS;

        _logger.info("connect to %s", uri.c_str());

        esp_mqtt_client_config_t config = {
            .uri = uri.c_str(),
            .client_id = Store::deviceId,
            .username = username.c_str(),
            .password = password.c_str(),
            .lwt_topic = lwtTopic.c_str(),
            .lwt_msg = lwtMessage,
            .lwt_qos = 1,
            .lwt_retain = true,
            .keepalive = MQTT_KEEP_ALIVE_SEC,
            .task_prio = MQTT_TASK_PRIORITY,
            .task_stack = MQTT_TASK_STACK_SIZE,
            .cert_pem = Store::mqttCert,
            .reconnect_timeout_ms = MQTT_RECONNECT_TIMEOUT_MS,
            .network_timeout_ms = MQTT_NETWORK_TIMEOUT_MS,
        };

        _client = esp_mqtt_client_init(&config);

        if (_client == nullptr)
        {
            _logger.error("unable to create client");
            return;
        }

        esp_err_t err = esp_mqtt_client_register_event(_client, MQTT_EVENT_ANY, _onEvent, _client);

        if (err != ESP_OK)
        {
            _logger.error("unable to register event handler");
            return;
        }

        err = esp_mqtt_client_start(_client);

        if (err != ESP_OK)
        {
            _logger.error("unable to start client");
            return;
        }
    }

    void MQTT::_onEvent(void *, esp_event_base_t, int32_t event_id, void *event_data)
    {
        const esp_mqtt_event_handle_t &event = *((esp_mqtt_event_handle_t *)(&event_data));

        char topic[event->topic_len + 1];
        char data[event->data_len + 1];
        strncpy(topic, event->topic, event->topic_len);
        strncpy(data, event->data, event->data_len);
        topic[event->topic_len] = '\0';
        data[event->data_len] = '\0';

        switch (event_id)
        {
        case MQTT_EVENT_CONNECTED:
            _onConnected();
            break;

        case MQTT_EVENT_DISCONNECTED:
            _onDisconnected();
            break;

        case MQTT_EVENT_DATA:
            _onDataArrived(topic, data);
            break;

        case MQTT_EVENT_SUBSCRIBED:
            _onSubscribed();
            break;
        default:
            break;
        }
    }

    void MQTT::disconnect()
    {
        esp_mqtt_client_disconnect(_client);
    }

    void MQTT::publish(const String &topic, const String &message, unsigned qos, bool retain)
    {
        if (Store::mqttConnected)
        {
            String fullTopic = "device/" + String(Store::deviceId) + topic;
            esp_mqtt_client_publish(_client, fullTopic.c_str(), message.c_str(), message.length(), qos, retain);
        }
    }

    void MQTT::subscribe(const String &topic, unsigned qos)
    {
        if (Store::mqttConnected)
        {
            esp_mqtt_client_subscribe(_client, topic.c_str(), qos);
        }
    }

    void MQTT::_onConnected()
    {
        Store::mqttConnected = true;

        _logger.info("connected");

        subscribe("device/" + String(Store::deviceId) + "/command/+", 1);

        Report::sendStatus("connected");
    }

    void MQTT::_onDisconnected()
    {
        Store::mqttConnected = false;

        _logger.info("disconnected");

        Report::sendStatus("disconnected");
    }

    void MQTT::_onDataArrived(const String &topic, const String &message)
    {
        Command::onMessage(message, topic);
    }

    void MQTT::_onSubscribed()
    {
        _logger.info("subscribed");
    }

    MQTT::~MQTT()
    {
        disconnect();
    }
}
