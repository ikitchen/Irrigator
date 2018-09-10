#ifndef API_CLIENT_H
#define API_CLIENT_H
#include <Ethernet.h>
#include <ArduinoHttpClient.h>
#include <Time.h>
#include <TimeLib.h>
#include <SPI.h>
#include "msgpck.h"
#include "SyncData.h"

class ApiClient
{
protected:
  HttpClient *http;

public:
  ApiClient(HttpClient *http);
  bool getData(SyncData *data);
};

#endif