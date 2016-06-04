// logger.h

#define LOGFILE "sdLog.log" 
#include <stdbool.h>


extern bool logCreated;

void logThis (char *msg_);
void logError (char *msg_);

