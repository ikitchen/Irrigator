#include "ApiClient.h"
#include <SPI.h>

ApiClient::ApiClient(HttpClient *http)
{
    this->http = http;
}

String ApiClient::getData()
{
    http->get("/");
    int statusCode = http->responseStatusCode();
    return http->responseBody();
}
