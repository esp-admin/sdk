#ifndef H_CREDENTIALS
#define H_CREDENTIALS

const char *httpHost = "app.esp-admin.tn"; // Should be secured (over HTTPS)
const char *deviceId = "";                 // Device identifier (REQUIRED)
const char *apiKey = "";                   // Device API key (REQUIRED)
const char *ssid = "";                     // WiFi station SSID (REQUIRED)
const char *password = "";                 // WiFi station password (REQUIRED)
const char *httpCert =                     // https://pki.goog/repository/ GTS CA 1P5 (For app.esp-admin.tn)
    "-----BEGIN CERTIFICATE-----\n"
    "MIIFjDCCA3SgAwIBAgINAgO8UKMnU/CRgCLt8TANBgkqhkiG9w0BAQsFADBHMQsw\n"
    "CQYDVQQGEwJVUzEiMCAGA1UEChMZR29vZ2xlIFRydXN0IFNlcnZpY2VzIExMQzEU\n"
    "MBIGA1UEAxMLR1RTIFJvb3QgUjEwHhcNMjAwODEzMDAwMDQyWhcNMjcwOTMwMDAw\n"
    "MDQyWjBGMQswCQYDVQQGEwJVUzEiMCAGA1UEChMZR29vZ2xlIFRydXN0IFNlcnZp\n"
    "Y2VzIExMQzETMBEGA1UEAxMKR1RTIENBIDFQNTCCASIwDQYJKoZIhvcNAQEBBQAD\n"
    "ggEPADCCAQoCggEBALOC8CSMvy2Hr7LZp676yrpE1ls+/rL3smUW3N4Q6E8tEFha\n"
    "KIaHoe5qs6DZdU9/oVIBi1WoSlsGSMg2EiWrifnyI1+dYGX5XNq+OuhcbX2c0IQY\n"
    "hTDNTpvsPNiz4ZbU88ULZduPsHTL9h7zePGslcXdc8MxiIGvdKpv/QzjBZXwxRBP\n"
    "ZWP6oK/GGD3Fod+XedcFibMwsHSuPZIQa4wVd90LBFf7gQPd6iI01eVWsvDEjUGx\n"
    "wwLbYuyA0P921IbkBBq2tgwrYnF92a/Z8V76wB7KoBlcVfCA0SoMB4aQnzXjKCtb\n"
    "7yPIox2kozru/oPcgkwlsE3FUa2em9NbhMIaWukCAwEAAaOCAXYwggFyMA4GA1Ud\n"
    "DwEB/wQEAwIBhjAdBgNVHSUEFjAUBggrBgEFBQcDAQYIKwYBBQUHAwIwEgYDVR0T\n"
    "AQH/BAgwBgEB/wIBADAdBgNVHQ4EFgQU1fyeDd8eyt0Il5duK8VfxSv17LgwHwYD\n"
    "VR0jBBgwFoAU5K8rJnEaK0gnhS9SZizv8IkTcT4waAYIKwYBBQUHAQEEXDBaMCYG\n"
    "CCsGAQUFBzABhhpodHRwOi8vb2NzcC5wa2kuZ29vZy9ndHNyMTAwBggrBgEFBQcw\n"
    "AoYkaHR0cDovL3BraS5nb29nL3JlcG8vY2VydHMvZ3RzcjEuZGVyMDQGA1UdHwQt\n"
    "MCswKaAnoCWGI2h0dHA6Ly9jcmwucGtpLmdvb2cvZ3RzcjEvZ3RzcjEuY3JsME0G\n"
    "A1UdIARGMEQwOAYKKwYBBAHWeQIFAzAqMCgGCCsGAQUFBwIBFhxodHRwczovL3Br\n"
    "aS5nb29nL3JlcG9zaXRvcnkvMAgGBmeBDAECATANBgkqhkiG9w0BAQsFAAOCAgEA\n"
    "bGMn7iPf5VJoTYFmkYXffWXlWzcxCCayB12avrHKAbmtv5139lEd15jFC0mhe6HX\n"
    "02jlRA+LujbdQoJ30o3d9T/768gHmJPuWtC1Pd5LHC2MTex+jHv+TkD98LSzWQIQ\n"
    "UVzjwCv9twZIUX4JXj8P3Kf+l+d5xQ5EiXjFaVkpoJo6SDYpppSTVS24R7XplrWf\n"
    "B82mqz4yisCGg8XBQcifLzWODcAHeuGsyWW1y4qn3XHYYWU5hKwyPvd6NvFWn1ep\n"
    "QW1akKfbOup1gAxjC2l0bwdMFfM3KKUZpG719iDNY7J+xCsJdYna0Twuck82GqGe\n"
    "RNDNm6YjCD+XoaeeWqX3CZStXXZdKFbRGmZRUQd73j2wyO8weiQtvrizhvZL9/C1\n"
    "T//Oxvn2PyonCA8JPiNax+NCLXo25D2YlmA5mOrR22Mq63gJsU4hs463zj6S8ZVc\n"
    "pDnQwCvIUxX10i+CzQZ0Z5mQdzcKly3FHB700FvpFePqAgnIE9cTcGW/+4ibWiW+\n"
    "dwnhp2pOEXW5Hk3xABtqZnmOw27YbaIiom0F+yzy8VDloNHYnzV9/HCrWSoC8b6w\n"
    "0/H4zRK5aiWQW+OFIOb12stAHBk0IANhd7p/SA9JCynr52Fkx2PRR+sc4e6URu85\n"
    "c8zuTyuN3PtYp7NlIJmVuftVb9eWbpQ99HqSjmMd320=\n"
    "-----END CERTIFICATE-----\n";

const char *mqttCert = // The MQTT broker CA certificate (for HiveMQ Cloud)
    "-----BEGIN CERTIFICATE-----\n"
    "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\n"
    "-----END CERTIFICATE-----\n";

#endif