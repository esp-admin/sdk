/*
This example shows how to use ESPAdmin library with a GPRS modem (no WiFi)
Requirements:
 - `espidf` framework version 4 (platform = espressif32 @ 5.4.0)
 - `SIM800` modem (RST -> IO5, TX -> IO16, RX -> IO17)
*/

#include <ESPAdmin.h>
#include <credentials.h>
#include <esp_netif.h>
#include <esp_netif_ppp.h>
#include <cxx_include/esp_modem_api.hpp>
#include <esp_modem_config.h>
#include <driver/gpio.h>

using namespace ESPAdmin;

Logger logger("app");
esp_netif_t *netif;
std::shared_ptr<esp_modem::DTE> dte;
std::unique_ptr<esp_modem::DCE> dce;
const char *apn = "SIM_APN";

void setup_modem();
void onCustomCommand(std::string message);
void onConfigCommand(std::string message);

extern "C" void app_main()
{
    logger.info("started");

    setup_modem();

    ESPAdmin::begin({
        .httpHost = httpHost,
        .deviceId = deviceId,
        .apiKey = apiKey,
        .httpCert = httpCert,
        .mqttCert = mqttCert,
    });

    Command::onCustom = &onCustomCommand;
    Command::onConfig = &onConfigCommand;

    gpio_set_direction(GPIO_NUM_2, GPIO_MODE_OUTPUT);

    while (true)
    {
        gpio_set_level(GPIO_NUM_2, 1);
        vTaskDelay(pdMS_TO_TICKS(500));
        gpio_set_level(GPIO_NUM_2, 0);
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}

void onCustomCommand(std::string message)
{
    logger.info("Handling custom command %s", message.c_str());
}

void onConfigCommand(std::string message)
{
    logger.info("Handling config command %s", message.c_str());
}

void setup_modem(void)
{
    // Reset modem
    gpio_set_direction(GPIO_NUM_5, GPIO_MODE_OUTPUT);
    gpio_set_level(GPIO_NUM_5, 0);
    vTaskDelay(pdMS_TO_TICKS(1000));
    gpio_set_level(GPIO_NUM_5, 1);
    vTaskDelay(pdMS_TO_TICKS(6000));

    esp_netif_config_t netif_ppp_config = ESP_NETIF_DEFAULT_PPP();

    ESP_ERROR_CHECK(esp_netif_init());
    ESP_ERROR_CHECK(esp_event_loop_create_default());

    netif = esp_netif_new(&netif_ppp_config);
    assert(netif);

    esp_modem_dte_config_t dte_config = ESP_MODEM_DTE_DEFAULT_CONFIG();
    dte_config.uart_config.baud_rate = 115200;
    dte_config.uart_config.port_num = UART_NUM_2;
    dte_config.uart_config.tx_io_num = GPIO_NUM_17;
    dte_config.uart_config.rx_io_num = GPIO_NUM_16;
    dte_config.uart_config.flow_control = ESP_MODEM_FLOW_CONTROL_NONE;

    dte = esp_modem::create_uart_dte(&dte_config);
    assert(dte);

    esp_modem_dce_config_t dce_config = ESP_MODEM_DCE_DEFAULT_CONFIG(apn);

    dce = esp_modem::create_SIM800_dce(&dce_config, dte, netif);
    assert(dce);

    // Wait for Network registration
    int rssi = 0;
    int ber = 0;
    while (rssi == 0)
    {
        dce->get_signal_quality(rssi, ber);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }

    // Wait for GPRS registration
    int gprs_ready = 0;
    while (gprs_ready == 0)
    {
        dce->get_network_attachment_state(gprs_ready);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }

    // Enable data mode
    dce->set_mode(esp_modem::modem_mode::DATA_MODE);
    vTaskDelay(pdMS_TO_TICKS(5000));

    logger.success("Modem ready");
}