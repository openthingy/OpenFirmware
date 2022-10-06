#ifndef FILESYSTEM__H
#define FILESYSTEM__H

void fs_setup();

// void readFile(const char * path);
void append_file(const char * path, const char * message);
void reset_logs();

#endif /** END: FILESYSTEM__H */