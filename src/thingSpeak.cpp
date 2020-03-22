#include "ThingSpeak.h"
#include <WiFi.h>
#include "../src/headerfiles/secrets.h"
#include "../src/headerfiles/json.h"

char ssid[] = SECRET_SSID;   // your network SSID (name) 
char pass[] = SECRET_PASS;   // your network password
size_t len;

WiFiClient  client;
char server[] = "api.thingspeak.com"; 


void connectWiFi(){
if(WiFi.status() != WL_CONNECTED){
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(SECRET_SSID);
    while(WiFi.status() != WL_CONNECTED){
      WiFi.begin(ssid, pass);  // Connect to WPA/WPA2 network. Change this line if using open or WEP network
      Serial.print(".");
      delay(5000);     
    } 
    Serial.println("\nConnected");
  }
}

void httpRequest(const JsonDocument& _doc) {
  len = measureJson(_doc);
  String data_length = String(len);
  
  // Close any connection before sending a new request
  client.stop();
  // String data_length = String(strlen(data)+1); //Compute the data buffer length
  // POST data to ThingSpeak
  if (client.connect(server, 80)) {
    client.println("POST /channels/1024049/bulk_update.json HTTP/1.1"); // Replace YOUR-CHANNEL-ID with your ThingSpeak channel ID
    client.println("Host: api.thingspeak.com");
    client.println("Content-Type: application/json");
    client.println("Content-Length: " +len);
    client.println();
    serializeJson(doc, client);
  }
  else {
    Serial.println("Failure: Failed to connect to ThingSpeak");
  }
  delay(50); //Wait to receive the response
  client.parseFloat();
  String resp = String(client.parseInt());
  Serial.println("Response code:"+resp); // Print the response code. 202 indicates that the server has accepted the response
}

