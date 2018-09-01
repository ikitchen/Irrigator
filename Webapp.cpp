#include "Webapp.h"
//TODO: implement these limitations:
#define MAXLEN_METHOD 8
#define MAXLEN_PATH 64

void Webapp::setHandler(handlerFunction handler)
{
    this->handler = handler;
}

void Webapp::loop()
{
    // listen for incoming clients
    EthernetClient client = this->server->available();
    if (client)
    {
        // Serial.println("new client");
        // an http request ends with a blank line
        bool currentLineIsBlank = true;

        String method;
        bool readingMethod = true;
        String path;
        bool readingPath = false;

        while (client.connected())
        {
            if (client.available())
            {
                char c = client.read();

                if (readingMethod)
                {
                    if (c == ' ')
                    {
                        readingMethod = false;
                        readingPath = true;
                    }
                    else
                    {
                        method += c;
                    }
                }
                else if (readingPath)
                {
                    if (c == ' ')
                    {
                        readingPath = false;
                    }
                    else
                    {
                        path += c;
                    }
                }

                // Serial.write(c);
                // if you've gotten to the end of the line (received a newline
                // character) and the line is blank, the http request has ended,
                // so you can send a reply
                if (c == '\n' && currentLineIsBlank)
                {
                    this->handler(&client, &method, &path);
                    break;
                }
                if (c == '\n')
                {
                    // you're starting a new line
                    currentLineIsBlank = true;
                }
                else if (c != '\r')
                {
                    // you've gotten a character on the current line
                    currentLineIsBlank = false;
                }
            }
        }
        // give the web browser time to receive the data
        delay(1);
        // close the connection:
        client.stop();
        // Serial.println("client disconnected");
    }
}

Webapp::Webapp(EthernetServer *server)
{
    this->server = server;
}