#include "MQTT.h"

namespace ESPAdmin
{
    Logger MQTT::_logger("MQTT");

    esp_mqtt_client_handle_t MQTT::_client = {};

    void MQTT::connect()
    {
        String uriTCP = Store::get(STORE_MQTT_URI_TCP);
        String clientID = Store::deviceId;
        String username = Store::get(STORE_MQTT_USERNAME);
        String password = Store::get(STORE_MQTT_PASSWORD);

        String lwtMessage = "{'status':'disconnected'}";
        String lwtTopic = "device/" + Store::deviceId + "/report/status";

        esp_mqtt_client_config_t config = {
            .uri = uriTCP.c_str(),
            .client_id = clientID.c_str(),
            .username = username.c_str(),
            .password = password.c_str(),
            .lwt_topic = lwtTopic.c_str(),
            .lwt_msg = lwtMessage.c_str(),
            .lwt_qos = 1,
            .lwt_retain = true,
            .cert_pem = Store::ISRG_ROOT_X1,
        };

        _client = esp_mqtt_client_init(&config);

        if (_client == NULL)
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

    void MQTT::_onEvent(void *handler_args, esp_event_base_t base, int32_t event_id, void *event_data)
    {
        esp_mqtt_event_handle_t event = *((esp_mqtt_event_handle_t *)(&event_data));

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
        }
    }

    void MQTT::disconnect()
    {
        esp_mqtt_client_disconnect(_client);
    }

    void MQTT::publish(String topic, String message, unsigned qos, bool retain)
    {
        if (Store::mqttConnected)
        {
            String fullTopic = "device/" + Store::deviceId + topic;
            esp_mqtt_client_publish(_client, fullTopic.c_str(), message.c_str(), message.length(), qos, retain);
        }
    }

    void MQTT::_subscribe(String topic, unsigned qos)
    {
        if (Store::mqttConnected)
        {
            esp_mqtt_client_subscribe(_client, topic.c_str(), qos);
        }
        else
        {
            _logger.warn("client should be connected on subscription");
        }
    }

    void MQTT::_onConnected()
    {
        Store::mqttConnected = true;

        _logger.info("connected");

        _subscribe("device/" + Store::deviceId + "/command/+", 1);

        Report::sendStatus();
    }

    void MQTT::_onDisconnected()
    {
        Store::mqttConnected = false;

        _logger.info("disconnected");

        Report::sendStatus();
    }

    void MQTT::_onDataArrived(String topic, String message)
    {
        Command::onMessage(message, topic);
    }

    void MQTT::_onSubscribed()
    {
        _logger.info("subscribed");
    }
}
