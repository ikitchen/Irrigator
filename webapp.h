
#ifndef WEBAPP_H
#define WEBAPP_H
#include <Ethernet.h>

class Webapp
{
  private:
    EthernetServer *server;

  public:
    Webapp(EthernetServer *server);
    void loop();
};

#endif