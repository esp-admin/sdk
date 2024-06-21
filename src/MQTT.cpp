#include "MQTT.h"

namespace ESPAdmin
{
    Logger MQTT::_logger("MQTT");

    esp_mqtt_client_handle_t MQTT::_client;

    /**
     * Connects to an MQTT broker using the provided configuration.
     *
     * @throws None
     */
    void MQTT::connect()
    {
        const String uriWS = Store::get(STORE_MQTT_URI_WS);
        const String uriTCP = Store::get(STORE_MQTT_URI_TCP);
        const String username = Store::get(STORE_MQTT_USERNAME);
        const String password = Store::get(STORE_MQTT_PASSWORD);

        if (uriWS.length() == 0 || username.length() == 0 || password.length() == 0)
        {
            _logger.error(F("invalid MQTT configuration"));
            return;
        }

        const char lwtMessage[] = R"({"status":"disconnected"})";

        String lwtTopic = "device/" + String(Store::options.deviceId) + "/report/status";

        String uri = uriTCP.length() > 3 ? uriTCP : uriWS;

        _logger.info("connect to %s", uri.c_str());

        esp_mqtt_client_config_t config = {
            .uri = uri.c_str(),
            .client_id = Store::options.deviceId,
            .username = username.c_str(),
            .password = password.c_str(),
            .lwt_topic = lwtTopic.c_str(),
            .lwt_msg = lwtMessage,
            .lwt_qos = 1,
            .lwt_retain = true,
            .keepalive = Store::options.mqttKeepAliveSec,
            .task_prio = Store::options.mqttTaskPriority,
            .task_stack = Store::options.mqttTaskStackSize,
            .cert_pem = Store::options.mqttCert,
            .reconnect_timeout_ms = Store::options.mqttReconnectTimeoutMs,
            .network_timeout_ms = Store::options.mqttNetworkTimeoutMs,
        };

        _client = esp_mqtt_client_init(&config);

        if (_client == nullptr)
        {
            _logger.error(F("unable to create client"));
            return;
        }

        esp_err_t err = esp_mqtt_client_register_event(_client, MQTT_EVENT_ANY, _onEvent, _client);

        if (err != ESP_OK)
        {
            _logger.error(F("unable to register event handler"));
            return;
        }

        err = esp_mqtt_client_start(_client);

        if (err != ESP_OK)
        {
            _logger.error(F("unable to start client"));
            return;
        }
    }

    void MQTT::_onEvent(void *, esp_event_base_t, int32_t event_id, void *event_data)
    {
        const esp_mqtt_event_handle_t &event = *((esp_mqtt_event_handle_t *)(&event_data));

        switch (event_id)
        {
        case MQTT_EVENT_CONNECTED:
            _onConnected();
            break;

        case MQTT_EVENT_DISCONNECTED:
            _onDisconnected();
            break;

        case MQTT_EVENT_DATA:
        {
            char topic[event->topic_len + 1];
            char data[event->data_len + 1];
            strncpy(topic, event->topic, event->topic_len);
            strncpy(data, event->data, event->data_len);
            topic[event->topic_len] = '\0';
            data[event->data_len] = '\0';
            _onDataArrived(topic, data);
            break;
        }

        case MQTT_EVENT_SUBSCRIBED:
            _onSubscribed();
            break;

        default:
            break;
        }
    }

    /**
     * Disconnects the MQTT client from the broker.
     *
     * @throws None
     */
    void MQTT::disconnect()
    {
        esp_mqtt_client_disconnect(_client);
    }

    /**
     * Publishes a message to a specified MQTT topic.
     *
     * @param topic The topic to publish the message to.
     * @param message The message to publish.
     * @param qos The quality of service level for the message.
     * @param retain Whether the message should be retained by the broker.
     *
     * @throws None
     */
    void MQTT::publish(const String &topic, const String &message, unsigned qos, bool retain)
    {
        if (Store::mqttConnected)
        {
            String fullTopic = "device/" + String(Store::options.deviceId) + topic;
            esp_mqtt_client_publish(_client, fullTopic.c_str(), message.c_str(), message.length(), qos, retain);
        }
    }

    /**
     * Publishes a message to a specified MQTT topic.
     *
     * @param topic The topic to publish the message to.
     * @param message The message to publish.
     * @param len The length of the message.
     * @param qos The quality of service level for the message.
     * @param retain Whether the message should be retained by the broker.
     *
     * @throws None
     */
    void MQTT::publish(const String &topic, const char *message, int len, unsigned qos, bool retain)
    {
        if (Store::mqttConnected)
        {
            String fullTopic = "device/" + String(Store::options.deviceId) + topic;
            esp_mqtt_client_publish(_client, fullTopic.c_str(), message, len, qos, retain);
        }
    }

    /**
     * Subscribes to a specified MQTT topic with the given quality of service level.
     *
     * @param topic The topic to subscribe to.
     * @param qos The quality of service level for the subscription.
     *
     * @throws None
     */
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

        _logger.info(F("connected"));

        subscribe("device/" + String(Store::options.deviceId) + "/command/+", 1);

        Report::sendStatus("connected");
    }

    void MQTT::_onDisconnected()
    {
        Store::mqttConnected = false;

        _logger.info(F("disconnected"));

        Report::sendStatus("disconnected");
    }

    void MQTT::_onDataArrived(const String &topic, const String &message)
    {
        Command::onMessage(message, topic);
    }

    void MQTT::_onSubscribed()
    {
        _logger.info(F("subscribed"));
    }

    MQTT::~MQTT()
    {
        disconnect();
    }
}
