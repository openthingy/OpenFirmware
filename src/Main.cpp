#include <Arduino.h>
#include "Log.h"
#include "Filesystem.h"
#include "Network.h"
#include "OTA.h"
#include "Program.h"

#include <ETH.h> // Includes <WiFI>

/** TODO:
 * - Allow remote restarting of ESP using "ESP.restart()"
 * 
 */

void setup() {
	log_setup();
	sys_log("system: starting up...");

	fs_setup();

	net_setup(); // Setup Ethernet Connection
	ota_setup(); // Setup OTA
	prog_setup(); // Setup Program Sketch

	// uint8_t MAC[6];
	// ETH.macAddress(MAC);

	// TODO: Print device information
	sys_log("network: hostname: " + String(ETH.getHostname()));
	sys_log("network: eth mac: " + ETH.macAddress());
	sys_log("network: ipv4: " + String(ETH.localIP()));

}

void loop() {
	ota_loop();  // Handle OTA
	prog_loop(); // Run program
}