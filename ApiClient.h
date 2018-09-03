#ifndef API_CLIENT_H
#define API_CLIENT_H
#include <Ethernet.h>
#include <ArduinoHttpClient.h>

class ApiClient
{
protected:
  HttpClient *http;

public:
  ApiClient(HttpClient *http);
  String getData();
};

#endif