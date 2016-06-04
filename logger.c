// logger.c

#include <stdlib.h>
#include <stdio.h>
#include "logger.h"

bool logCreated = false;

void logThis(char *msg_)
{
    FILE *file;
    
    if (!logCreated)
    {
        file = fopen(LOGFILE, "w");
        logCreated = true;
    }
    else
    {
        file = fopen(LOGFILE, "a");
    }
    
    
    if (file == NULL)
    {
        if (logCreated)
        {
            logCreated = false;
        }
        return;
    }
    else
    {
        fputs(msg_, file);
        fclose(file);
    }
    if (file)
        fclose(file);
    
}

void logError(char *msg_)
{
    logThis(msg_);
    logThis("\n");
}