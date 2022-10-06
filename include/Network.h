#ifndef ETHERNET__H
#define ETHERNET__H


#include <Arduino.h>

// String Hostname; // Make user configurable

static bool eth_connected = false; // Rename

// WiFiClient client;

void makehostname(char* hostname, int length);
void net_setup();


#endif /** END: ETHERNET__H */