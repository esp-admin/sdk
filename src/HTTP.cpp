#include "HTTP.hpp"

namespace ESPAdmin
{
    Logger HTTP::_logger("HTTP");

    /**
     * Retrieves data from the server using an HTTP GET request.
     *
     * @param path The path to append to the base URL for the GET request.
     *
     * @return The response data obtained from the server.
     *
     * @throws ErrorType If there are errors during the HTTP GET request.
     */
    std::string HTTP::get(const std::string &path)
    {
        char response[Store::options.httpMaxResponseSize + 1] = {0};

        std::string fullPath = "/api/device/" + std::string(Store::options.deviceId) + path;

        esp_http_client_config_t config = {
            .host = Store::options.httpHost,
            .path = fullPath.c_str(),
            .cert_pem = Store::options.httpCert,
            .method = HTTP_METHOD_GET,
            .timeout_ms = Store::options.httpTimeoutMs,
            .transport_type = HTTP_TRANSPORT_OVER_SSL,
        };

        esp_http_client_handle_t client = esp_http_client_init(&config);
        if (client == nullptr)
        {
            _logger.error("failed to init http client");
            return "";
        }

        ESP_ERROR_CHECK(esp_http_client_set_header(client, "Api-Key", Store::options.apiKey));

        esp_err_t err = esp_http_client_open(client, 0);
        if (err != ESP_OK)
        {
            _logger.error("failed to open connection %s", esp_err_to_name(err));
            esp_http_client_cleanup(client);
            return "";
        }

        int contentLength = esp_http_client_fetch_headers(client);
        if (contentLength == -1)
        {
            _logger.error("failed to read");
            esp_http_client_cleanup(client);
            return "";
        }

        int statusCode = esp_http_client_get_status_code(client);
        if (statusCode < 200 || statusCode >= 300)
        {
            _logger.error("failed with %d", statusCode);
            esp_http_client_cleanup(client);
            return "";
        }

        esp_http_client_read_response(client, response, Store::options.httpMaxResponseSize);

        esp_http_client_close(client);
        esp_http_client_cleanup(client);

        return std::string(response);
    }

    /**
     * Sends an HTTP POST request to the specified path with the given content and content type.
     *
     * @param path The path to append to the base URL for the POST request.
     * @param content The content to send in the request body.
     * @param contentType The content type of the request body.
     *
     * @return The response data obtained from the server.
     *
     * @throws ErrorType If there are errors during the HTTP POST request.
     */
    std::string HTTP::post(const std::string &path, const std::string &content, const std::string &contentType)
    {
        char response[Store::options.httpMaxResponseSize + 1] = {0};

        std::string fullPath = "/api/device/" + std::string(Store::options.deviceId) + path;

        esp_http_client_config_t config = {
            .host = Store::options.httpHost,
            .path = fullPath.c_str(),
            .cert_pem = Store::options.httpCert,
            .method = HTTP_METHOD_POST,
            .timeout_ms = Store::options.httpTimeoutMs,
            .transport_type = HTTP_TRANSPORT_OVER_SSL,
        };

        esp_http_client_handle_t client = esp_http_client_init(&config);
        if (client == nullptr)
        {
            _logger.error("failed to init http client");
            return "";
        }

        esp_http_client_set_header(client, "Api-Key", Store::options.apiKey);
        esp_http_client_set_header(client, "Content-Type", contentType.c_str());

        esp_err_t err = esp_http_client_open(client, content.length());
        if (err != ESP_OK)
        {
            _logger.error("failed to open connection %s", esp_err_to_name(err));
            esp_http_client_cleanup(client);
            return "";
        }

        int wlen = esp_http_client_write(client, content.c_str(), content.length());
        if (wlen == -1)
        {
            _logger.error("failed to write");
            esp_http_client_close(client);
            esp_http_client_cleanup(client);
            return "";
        }

        int contentLength = esp_http_client_fetch_headers(client);
        if (contentLength == -1)
        {
            _logger.error("failed to read");
            esp_http_client_close(client);
            esp_http_client_cleanup(client);
            return "";
        }

        int statusCode = esp_http_client_get_status_code(client);
        if (statusCode < 200 || statusCode >= 300)
        {
            _logger.error("failed with %d", statusCode);
            esp_http_client_close(client);
            esp_http_client_cleanup(client);
            return "";
        }

        esp_http_client_read_response(client, response, Store::options.httpMaxResponseSize);

        esp_http_client_close(client);
        esp_http_client_cleanup(client);

        return std::string(response);
    }
}
