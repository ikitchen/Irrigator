#include "ApiClient.h"

ApiClient::ApiClient(HttpClient *http)
{
    this->http = http;
}

bool ApiClient::getData(SyncData *data)
{
    http->get("/");
    int statusCode = http->responseStatusCode();

    int a = 0;
    http->contentLength();

    bool res = true;
    unsigned long int timestamp = 0;
    byte flags = 0;
    uint32_t arraySize = 0;

#ifdef LOGGING
    Serial.println("Unpacking");
#endif

    res &= msgpck_array_next(http);
    if (!res)
    {
#ifdef LOGGING
        Serial.println("Not array");
#endif
        return false;
    }

    res &= msgpck_read_array_size(http, &arraySize);
    if (!res)
    {
#ifdef LOGGING
        Serial.println("Could not read array size");
#endif
        return false;
    }
#ifdef LOGGING
    Serial.print("Array size=");
    Serial.println(arraySize);
#endif
    if (arraySize != 2)
    {
        return false;
    }

    res &= msgpck_read_integer(http, (byte *)&flags, sizeof(flags));
    if (!res)
    {
#ifdef LOGGING
        Serial.println("Not int 1");
#endif
        return false;
    }
#ifdef LOGGING
    Serial.print("FL=");
    Serial.println(flags);
#endif

    res &= msgpck_read_integer(http, (byte *)&timestamp, sizeof(timestamp));
    if (!res)
    {
#ifdef LOGGING
        Serial.println("Not int 2");
#endif
        return false;
    }
#ifdef LOGGING
    Serial.print("TS=");
    Serial.println(timestamp);
#endif

    data->flags = flags;
    data->time = timestamp;

    Serial.print("T=");
    Serial.println(data->time);
    Serial.print("F=");
    Serial.println(data->flags);
    return true;
}
