#ifndef WEBAPP_H
#define WEBAPP_H
#include <Ethernet.h>

enum HttpMethod
{
  GET,
  POST,
  OPTIONS,
  UNKNOWN
};

class Webapp
{
private:
  EthernetServer *server;

protected:
  virtual void handler(EthernetClient *client, HttpMethod method, String *path);
  HttpMethod httpMethodFromString(String methodStr);

public:
  Webapp(EthernetServer *server);
  void loop();
};

#endif