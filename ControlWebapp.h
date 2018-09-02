#ifndef CONTROL_WEBAPP_H
#define CONTROL_WEBAPP_H
#include "Webapp.h"

class ControlWebapp : public Webapp
{
  public:
    ControlWebapp(EthernetServer *server) : Webapp(server) {}

  protected:
    void handler(EthernetClient *client, HttpMethod method, String *path);
};

#endif