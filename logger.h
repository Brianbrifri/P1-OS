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
void buildAndSaveErrorMessage(data_t data);
void printHelpMessage(void);

#endif
