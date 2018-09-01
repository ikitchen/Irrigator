
#ifndef WEBAPP_H
#define WEBAPP_H
#include <Ethernet.h>

typedef void (*handlerFunction)(EthernetClient *client, String *method, String *path);

class Webapp
{
private:
  EthernetServer *server;
  handlerFunction handler;

public:
  Webapp(EthernetServer *server);
  void loop();
  void setHandler(handlerFunction handler);
};

#endif