
#include <String.h>

String Hostname; // Make user configurable
uint8_t MAC[6];


static bool eth_connected = false;

WiFiClient client;


void ETH_setup();
