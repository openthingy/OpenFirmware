#include <Arduino.h>
#include "Filesystem.h"
#include "Log.h"
#include "FS.h"
#include <LittleFS.h>
#include <time.h>

/* You only need to format LittleFS the first time you run a
   test or else use the LITTLEFS plugin to create a partition
   https://github.com/lorol/arduino-esp32littlefs-plugin */
   
#define FORMAT_LITTLEFS_IF_FAILED true



// void readFile(const char * path){
//     File file = LittleFS.open(path);
//     if(!file || file.isDirectory()){
//         sys_log("- failed to open file for reading");
//         return;
//     }

//     sys_log("- read from file:");
//     while(file.available()){
//         Serial.write(file.read());
//     }
//     file.close();
// }

void append_file(const char * path, const char * message){
    File file = LittleFS.open(path, FILE_APPEND);
    if(!file){
        sys_log("filesystem: failed to open file for appending", CRIT);
        return;
    }
    if(!file.print(message)){
        sys_log("filesystem: append failed");
    }
    file.close();
}

void reset_logs() {
	if (!LittleFS.remove("/entry.log"))   sys_log("filesystem: delete '/entry.log' failed", ERR);
	if (!LittleFS.remove("/sys.log"))   sys_log("filesystem: delete '/sys.log' failed", ERR);
}


void fs_setup() {
	if (!LittleFS.begin(FORMAT_LITTLEFS_IF_FAILED)) sys_log("filesystem: failed to mount littlefs", ALERT);
	// if (!LittleFS.mkdir("/log")) sys_log("filesystem: mkdir failed");
}
