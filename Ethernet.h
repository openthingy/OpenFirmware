#ifndef ETHERNET_H
#define ETHERNET_H


#include <String.h>

String Hostname; // Make user configurable
uint8_t MAC[6];

static bool eth_connected = false; // Rename

// WiFiClient client;


void ETH_setup();


#endif /** END: ETHERNET_H */