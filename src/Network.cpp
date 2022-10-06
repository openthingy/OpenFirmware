#include <Arduino.h>
#include "Log.h"
#include "Network.h"
#include <ETH.h> // Includes <WiFI>


void WiFiEvent(WiFiEvent_t event) {
  switch (event) {

    case ARDUINO_EVENT_ETH_START:
      sys_log("network: ethernet started", INFO);
      // Set hostname
      if (0) { // TODO: Check for user set hostname
        // if (maxlength > _hostname.length()) {
        // 	_hostname.toCharArray(hostname, length);
        // } else { sys_log("network: provided hostname is bad", WARNING); }
      } else { ETH.setHostname(("OpenThingy-" + ETH.macAddress()).c_str()); }
      break;

    case ARDUINO_EVENT_ETH_CONNECTED:
      sys_log("network: ethernet connected", INFO);
      break;
      
    case ARDUINO_EVENT_ETH_GOT_IP:
      sys_log("network: ethernet received ip", INFO);
      eth_connected = true; // Defined in Ethernet.h
      break;

    case ARDUINO_EVENT_ETH_DISCONNECTED:
      sys_log("network: ethernet disconnected", NOTICE);
      eth_connected = false; // Defined in Ethernet.h
      break;

    case ARDUINO_EVENT_ETH_STOP:
      sys_log("network: ethernet stopped", NOTICE);
      eth_connected = false; // Defined in Ethernet.h
      break;

    default:
      break;

  }
}

void net_setup() {
  WiFi.onEvent(WiFiEvent);
  ETH.begin();
}



