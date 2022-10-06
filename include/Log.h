#ifndef LOG__H
#define LOG__H

#define DEFAULT_LOG_LEVEL INFO
#define LOG_PORT Serial

#include <Arduino.h>

enum __log_level {
	EMERG,   // Messages about system instability or imminent crashes
	ALERT,   // Used in situations where the user attention is immediately required
	CRIT,    // Critical errors, both hardware or software related
	ERR,     // Used to notify the user about non-critical errors
	WARNING, // Warnings or messages about non imminent errors
	NOTICE,  // Message about events which may be worth noting
	INFO,    // Informational messages about the action performed
	DEBUG    // Used for debugging
};

void panic(String msg);
void sys_log(String msg, __log_level level = DEFAULT_LOG_LEVEL);

void log_setup();

#endif /** END: LOG__H */