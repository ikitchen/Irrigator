#ifndef CONTROL_WEBAPP_H
#define CONTROL_WEBAPP_H
#include "Webapp.h"
#include "ApiClient.h"

class ControlWebapp : public Webapp
{
public:
  ControlWebapp(EthernetServer *server, ApiClient *api) : Webapp(server) { this->api = api; }

protected:
  ApiClient *api;
  void handler(HttpMethod method, String *path);
};

#endif