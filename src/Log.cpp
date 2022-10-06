#include <Arduino.h>
#include "Log.h"

#include "Filesystem.h"
// #include 

// Send log message directly to "control panel" for user action
void report_log_msg(String msg) { // TODO: rename
	// TODO: implement
}

// Send log file to "control panel"
void report_log() { // TODO: rename
	// TODO: implement
	// TODO: Call this function periodically
}

void panic(String msg) {
	// TODO: Print timestamp
	msg = "PANIC: aborting startup: " + msg;
	msg += "\r\n";
	
	// TODO: Check if each log option is setup/available before logging to it
	report_log_msg(msg);
	LOG_PORT.println(msg);
	append_file("/logs/emerg.log", msg.c_str());
	
	// Restart (enter panic mode???)
	delay(5000);
	ESP.restart();
}

void sys_log(String msg, __log_level level) {
	// TODO: Print timestamp
	msg += "\r\n";

	switch (level) {
	case EMERG:
		msg = "EMERG: " + msg;
		report_log_msg(msg);
		LOG_PORT.println(msg);
		append_file("/logs/emerg.log", msg.c_str());
		break;

	case ALERT:
		msg = "ALERT: " + msg;
		report_log_msg(msg);
		LOG_PORT.println(msg);
		append_file("/logs/alert.log", msg.c_str());
		break;

	case CRIT:
		msg = "CRIT: " + msg;
		report_log_msg(msg);
		LOG_PORT.println(msg);
		append_file("/logs/crit.log", msg.c_str());
		break;

	case ERR:
		msg = "ERR: " + msg;
		LOG_PORT.println(msg);
		append_file("/logs/err.log", msg.c_str());
		break;

	case WARNING:
		msg = "WARNING: " + msg;
		LOG_PORT.println(msg);
		append_file("/logs/warning.log", msg.c_str());
		break;

	case NOTICE:
		msg = "NOTICE: " + msg;
		LOG_PORT.println(msg);
		append_file("/logs/notice.log", msg.c_str());
		break;

	case INFO:
		msg = "INFO: " + msg;
		LOG_PORT.println(msg);
		append_file("/logs/info.log", msg.c_str());
		break;

	case DEBUG:
		msg = "DEBUG: " + msg;
		LOG_PORT.println(msg);
		append_file("/logs/debug.log", msg.c_str());
		break;
	}
}


void log_setup() {
	LOG_PORT.begin(115200);
}