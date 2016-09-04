#ifndef LOGGER_h
#define LOGGER_H
#include <time.h>

typedef struct data_struct {
  time_t time;
  char *string;
} data_t;

int addMsg(data_t data);
void clearLog(void);
char *getLog(void);
int saveLog(char *filename);
void printHelpMessage(void);

#endif
