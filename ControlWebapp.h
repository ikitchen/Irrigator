#ifndef CONTROL_WEBAPP_H
#define CONTROL_WEBAPP_H
#include "Webapp.h"
#include "ApiClient.h"
#include "ApplicationState.h"

class ControlWebapp : public Webapp
{
public:
  ControlWebapp(EthernetServer *server, ApiClient *api, ApplicationState *appState) : Webapp(server)
  {
    this->api = api;
    this->appState = appState;
  }

protected:
  ApiClient *api;
  ApplicationState *appState;
  void handler(HttpMethod method, String *path);
};

#endif