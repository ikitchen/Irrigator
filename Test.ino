// /*
//   Web Server

//  A simple web server that shows the value of the analog input pins.
//  using an Arduino Wiznet Ethernet shield.

//  Circuit:
//  * Ethernet shield attached to pins 10, 11, 12, 13
//  * Analog inputs attached to pins A0 through A5 (optional)

//  created 18 Dec 2009
//  by David A. Mellis
//  modified 9 Apr 2012
//  by Tom Igoe
//  modified 02 Sept 2015
//  by Arturo Guadalupi
 
//  */

// #include <SPI.h>
// #include <Ethernet.h>

// #include "config.h"
// #include <ArduinoHttpClient.h>

// int statusCode = 0;
// String response;
// EthernetClient client;
// HttpClient theHttpClient = HttpClient(client, config_serverHost, 80);

// void setup()
// {

//     // Open serial communications and wait for port to open:
//     Serial.begin(9600);
//     while (!Serial)
//     {
//         ; // wait for serial port to connect. Needed for native USB port only
//     }

//     Ethernet.begin(config_mac, config_ip);
//     if (Ethernet.hardwareStatus() == EthernetNoHardware)
//     {
//         Serial.println("Ethernet shield was not found.  Sorry, can't run without hardware. :(");
//         while (true)
//         {
//             delay(1);
//         }
//     }
//     if (Ethernet.linkStatus() == LinkOFF)
//     {
//         Serial.println("Ethernet cable is not connected.");
//     }
// }

// void loop()
// {
//     Serial.println("making GET request");
//     theHttpClient.get("/");

//     // read the status code and body of the response
//     statusCode = theHttpClient.responseStatusCode();
//     response = theHttpClient.responseBody();

//     Serial.print("Status code: ");
//     Serial.println(statusCode);
//     Serial.print("Response: ");
//     Serial.println(response);
//     Serial.println("Wait five seconds");

//     delay(5000);
// }
