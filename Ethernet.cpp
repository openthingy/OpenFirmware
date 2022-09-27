#include <Arduino.h>
#include "Ethernet.h"
#include <ETH.h> // Includes <WiFI> 


void makehostname(char* hostname, int length) {
  uint8_t MAC[6];
  ETH.macAddress(MAC);
  // Set hostname variable
  String _hostname = String("OpenThingy-") + MAC[0] + 'x' + MAC[1] + 'x' + MAC[2] + 'x' + MAC[3] + 'x' + MAC[4] + 'x' + MAC[5] + 'x';
  // Set hostname
  if (length >= _hostname.length() + 1) {
    _hostname.toCharArray(hostname, length);
  } else { /** ERROR */ }
}

void WiFiEvent(WiFiEvent_t event) {
  switch (event) {

    case ARDUINO_EVENT_ETH_START:
      Serial.println("ETH Started");
      // Set hostname
      char hostname[30];
      makehostname(hostname, 30);
      ETH.setHostname(hostname);
      // Serial.println("Hostname: " + Hostname);
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



