#ifndef LOGGER_h
#define LOGGER_H
#include <time.h>

typedef struct data_struct {
  time_t time;
  char *string;
} data_t;

char * addMsg(data_t data);
void clearLog(void);
char *getLog(void);
char *saveLog(char *filename);
void buildErrorMessage(data_t data, char *programName);
void printHelpMessage(void);

#endif
