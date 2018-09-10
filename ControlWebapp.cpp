#include "ControlWebapp.h"

#define HTML_BR "<br />"

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

    time_t lst = appState->getLastSyncTime();
    time_t lkrt = appState->getLastKnownRainTime();

    client->println(lst);
    client->println(HTML_BR);
    client->println(lkrt);
}