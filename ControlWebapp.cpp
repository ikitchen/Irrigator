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

    sendHeader();

    SyncData sync;
    api->getData(&sync);
}