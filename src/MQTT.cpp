#include "MQTT.h"

namespace ESPAdmin
{
    Logger MQTT::_logger("MQTT");

    esp_mqtt_client_handle_t MQTT::_client = {};

    void MQTT::connect()
    {
        esp_mqtt_client_config_t config = {
            .uri = Store::mqtt.uriTCP.c_str(),
            .client_id = Store::mqtt.clientId.c_str(),
            .username = Store::mqtt.username.c_str(),
            .password = Store::mqtt.password.c_str(),
            .cert_pem = Store::mqtt.certificate.c_str()};

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
        esp_mqtt_client_handle_t client = event->client;

        switch (event_id)
        {
        case MQTT_EVENT_CONNECTED:
            _onConnected();
            break;

        case MQTT_EVENT_DISCONNECTED:
            _onDisconnected();
            break;

        case MQTT_EVENT_DATA:
            _onDataArrived(event->topic, event->data);
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

    void MQTT::publish(String topic, String message)
    {
    }

    void MQTT::subscribe(String topic)
    {
        if (Store::mqtt.connected)
        {
            esp_mqtt_client_subscribe(_client, topic.c_str(), 1);
        }
        else
        {
            _logger.warn("client should be connected on subscription");
        }
    }

    void MQTT::_onConnected()
    {
        Store::mqtt.connected = true;

        _logger.info("connected");

        subscribe("/device/#");
    }

    void MQTT::_onDisconnected()
    {
        Store::mqtt.connected = false;
        _logger.info("disconnected");
    }

    void MQTT::_onDataArrived(String topic, String message)
    {
        _logger.info("received new message");
    }

    void MQTT::_onSubscribed()
    {
        _logger.info("subscribed");
    }
}
