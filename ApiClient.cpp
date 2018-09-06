#include <Time.h>
#include <TimeLib.h>
#include <SPI.h>

#include "ApiClient.h"

struct SyncData
{
    time_t time;
    bool isRaining;
};

SyncData parseSyncData(String serverResponse) {

}

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
