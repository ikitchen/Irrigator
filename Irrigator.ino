/*
  Web Server

 A simple web server that shows the value of the analog input pins.
 using an Arduino Wiznet Ethernet shield.

 Circuit:
 * Ethernet shield attached to pins 10, 11, 12, 13
 * Analog inputs attached to pins A0 through A5 (optional)

 created 18 Dec 2009
 by David A. Mellis
 modified 9 Apr 2012
 by Tom Igoe
 modified 02 Sept 2015
 by Arturo Guadalupi
 
 */

#include <SPI.h>
#include <Ethernet.h>

#include "config.h"
#include "Webapp.h"

// Initialize the Ethernet server library
// with the IP address and port you want to use
// (port 80 is default for HTTP):
EthernetServer server(80);
Webapp app(&server);

void onHttpRequest(EthernetClient *client, String *method, String *path)
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
  client->println(*method);
  client->println("<br />");
  client->print("Path = ");
  client->println(*path);
  client->println("<br />");
}

void setup()
{

  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial)
  {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("Ethernet WebServer Example");

  // start the Ethernet connection and the server:
  Ethernet.begin(config_mac, config_ip);

  // Check for Ethernet hardware present
  if (Ethernet.hardwareStatus() == EthernetNoHardware)
  {
    Serial.println("Ethernet shield was not found.  Sorry, can't run without hardware. :(");
    while (true)
    {
      delay(1); // do nothing, no point running without Ethernet hardware
    }
  }
  if (Ethernet.linkStatus() == LinkOFF)
  {
    Serial.println("Ethernet cable is not connected.");
  }

  // start the server
  server.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());
  app.setHandler(onHttpRequest);
}

void loop()
{
  app.loop();
}
