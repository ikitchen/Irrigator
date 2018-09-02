#include "ControlWebapp.h"

void ControlWebapp::handler(EthernetClient *client, HttpMethod method, String *path)
{
    // send a standard http response header
    client->println("HTTP/1.1 200 OK");
    client->println("Content-Type: text/html");
    client->println("Connection: close"); // the connection will be closed after completion of the response
    client->println();
    // output the value of each analog input pin
    for (int analogChannel = 0; analogChannel < 6; analogChannel++)
    {
        int sensorReading = analogRead(analogChannel);
        client->print("AI ");
        client->print(analogChannel);
        client->print(" = ");
        client->print(sensorReading);
        client->println("<br />");
    }
    client->print("HTTP method = ");

    switch (method)
    {
    case GET:
        client->println("G");
        break;
    case POST:
        client->println("P");
        break;
    case OPTIONS:
        client->println("O");
        break;
    case UNKNOWN:
        client->println("U");
        break;
    }

    client->println("<br />");
    client->print("Path = ");
    client->println(*path);
    client->println("<br />");
}