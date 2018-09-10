#include <SPI.h>
#include <Ethernet.h>
#include <ArduinoHttpClient.h>
#include <Time.h>
#include <TimeLib.h>

#include "config.h"
#include "ControlWebapp.h"
#include "ApiClient.h"
#include "ApplicationState.h"

// Initialize the Ethernet server library
// with the IP address and port you want to use
// (port 80 is default for HTTP):
ApplicationState appState;
EthernetServer server(80);
EthernetClient client;
HttpClient http = HttpClient(client, config_serverHost, 80);
ApiClient api(&http);
ControlWebapp app(&server, &api, &appState);
time_t requestSync();

void setup()
{

  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial)
  {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // start the Ethernet connection and the server:
  Ethernet.begin(config_mac, config_ip);

  // Check for Ethernet hardware present
  if (Ethernet.hardwareStatus() == EthernetNoHardware)
  {
    Serial.println("EETH");
    while (true)
    {
      delay(1); // do nothing, no point running without Ethernet hardware
    }
  }
  if (Ethernet.linkStatus() == LinkOFF)
  {
    Serial.println("ECAB");
  }

  // start the server
  server.begin();
#ifdef LOGGING
  Serial.println(Ethernet.localIP());
#endif
  setSyncProvider(requestSync);
  setSyncInterval(10);
}

void loop()
{
  app.loop();
  static unsigned long t;
  unsigned long n = millis();
  if (n - t >= 1000)
  {
    // Serial.print(now());
    t = n;
  }
}

time_t requestSync()
{
  SyncData syncData;
  if (api.getData(&syncData))
  {
    Serial.println("SYNCED");
    Serial.println(syncData.time);
    Serial.println(syncData.flags);
    appState.actionSyncDataChanged(&syncData);
    return syncData.time;
  }
  Serial.println("ERROR");
  return 0; // TODO: zero on fail?
}