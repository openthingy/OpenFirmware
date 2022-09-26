#include "Ethernet.h"
#include <ETH.h> // Includes <WiFI> 
#include <String.h>


void WiFiEvent(WiFiEvent_t event) {
  switch (event) {

    case ARDUINO_EVENT_ETH_START:
      Serial.println("ETH Started");
      ETH.macAddress(MAC);
      String _hostname = "OpenThingy-" + MAC[0] + 'x' + MAC[1] + 'x' + MAC[2] + 'x' + MAC[3] + 'x' + MAC[4] + 'x' + MAC[5] + 'x';
      if (Hostname.length() == 0) { Hostname = _hostname; }
      ETH.setHostname(Hostname); // Defined in Ethernet.h
      Serial.println("Hostname: "+_hostname);
      break;

    case ARDUINO_EVENT_ETH_CONNECTED:
      Serial.println("ETH Connected");
      break;
      
    case ARDUINO_EVENT_ETH_GOT_IP:
      Serial.print("ETH MAC: ");
      Serial.print(ETH.macAddress());
      Serial.print(", IPv4: ");
      Serial.print(ETH.localIP());
      if (ETH.fullDuplex()) {
        Serial.print(", FULL_DUPLEX");
      }
      Serial.print(", ");
      Serial.print(ETH.linkSpeed());
      Serial.println("Mbps");
      eth_connected = true; // Defined in Ethernet.h
      break;

    case ARDUINO_EVENT_ETH_DISCONNECTED:
      Serial.println("ETH Disconnected");
      eth_connected = false; // Defined in Ethernet.h
      break;

    case ARDUINO_EVENT_ETH_STOP:
      Serial.println("ETH Stopped");
      eth_connected = false; // Defined in Ethernet.h
      break;

    default:
      break;

  }
}

void ETH_setup() {
  WiFi.onEvent(WiFiEvent);
  ETH.begin();
}


