#include <Arduino.h>
#include "Ethernet.h"
#include "OTA.h"
#include "Program.h"

#include <ETH.h> // Includes <WiFI>

/** TODO:
 * - Allow remote restarting of ESP using "ESP.restart()"
 * 
 */

void setup() {
  Serial.begin(115200);
  Serial.println("Booting...");

  ETH_setup(); // Setup Ethernet Connection
  OTA_setup(); // Setup OTA
  Prog_setup(); // Setup Program Sketch

  uint8_t MAC[6];
  ETH.macAddress(MAC);

  // TODO: Print device information
  // Serial.println("Hostname: " + makehostname());
  Serial.println("MAC Address: " + MAC[0] + 'x' + MAC[1] + 'x' + MAC[2] + 'x' + MAC[3] + 'x' + MAC[4] + 'x' + MAC[5] + 'x');
  Serial.println("Local IP: " + ETH.localIP());

}

void loop() {
  OTA_loop(); // Handle OTA
  Prog_loop(); // Run program
}