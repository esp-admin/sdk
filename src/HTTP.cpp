#include "HTTP.h"

namespace ESPAdmin
{
    Logger HTTP::_logger("HTTP");

    String HTTP::get(String path)
    {
        char response[HTTP_MAX_RESPONSE_SIZE] = {0};

        String fullPath = "/api/device/" + String(Store::deviceId) + path;

        esp_http_client_config_t config = {
            .host = Store::httpHost,
            .path = fullPath.c_str(),
            .cert_pem = Store::ISRG_ROOT_X1,
            .method = HTTP_METHOD_GET,
            .timeout_ms = HTTP_TIMEOUT_MS,
            .transport_type = HTTP_TRANSPORT_OVER_SSL,
        };

        esp_http_client_handle_t client = esp_http_client_init(&config);

        esp_http_client_set_header(client, "Api-Key", Store::apiKey);

        esp_err_t err = esp_http_client_open(client, 0);

        if (err == ESP_OK)
        {
            int contentLength = esp_http_client_fetch_headers(client);

            if (contentLength <= 0)
            {
                _logger.warn("failed to read");
                return "-1";
            }
            else
            {
                esp_http_client_read_response(client, response, HTTP_MAX_RESPONSE_SIZE);
            }
        }
        else
        {
            _logger.error("failed to open connection");
            return "-1";
        }

        esp_http_client_close(client);

        esp_http_client_cleanup(client);

        return response;
    }

    String HTTP::post(String path, String content, String contentType)
    {
        char response[HTTP_MAX_RESPONSE_SIZE] = {0};

        String fullPath = "/api/device/" + String(Store::deviceId) + path;

        esp_http_client_config_t config = {
            .host = Store::httpHost,
            .path = fullPath.c_str(),
            .cert_pem = Store::ISRG_ROOT_X1,
            .method = HTTP_METHOD_POST,
            .timeout_ms = HTTP_TIMEOUT_MS,
            .transport_type = HTTP_TRANSPORT_OVER_SSL,
        };

        esp_http_client_handle_t client = esp_http_client_init(&config);

        esp_http_client_set_header(client, "Api-Key", Store::apiKey);

        esp_http_client_set_header(client, "Content-Type", contentType.c_str());

        esp_err_t err = esp_http_client_open(client, content.length());

        if (err == ESP_OK)
        {
            int wlen = esp_http_client_write(client, content.c_str(), content.length());
            if (wlen < 0)
            {
                _logger.warn("failed to write");
                return "-1";
            }
            else
            {
                esp_http_client_fetch_headers(client);
                esp_http_client_read_response(client, response, HTTP_MAX_RESPONSE_SIZE);
            }
        }
        else
        {
            _logger.error("failed to open connection");
            return "-1";
        }

        esp_http_client_close(client);

        esp_http_client_cleanup(client);

        return response;
    }
}
