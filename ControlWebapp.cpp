#include "ControlWebapp.h"

void ControlWebapp::handler(HttpMethod method, String *path)
{
    if (method != GET)
    {
        return;
    }
    if (!path->equals("/"))
    {
        return;
    }

    // send a standard http response header
    client->println("HTTP/1.1 200 OK");
    client->println("Content-Type: text/html");
    client->println("Connection: close"); // the connection will be closed after completion of the response
    client->println();

    String res = api->getData();
    client->println(res);
}