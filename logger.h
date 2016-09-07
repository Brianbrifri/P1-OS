#ifndef LOGGER_h
#define LOGGER_H
#include <sys/time.h>

typedef struct data_struct {
  struct timespec time;
  char *string;
} data_t;

char *addMsg(data_t data);
void clearLog(void);
char *getLog(void);
char *saveLog(char *filename);
void buildAndAddErrorMessage(char *errorMessage, char *programName, int nValue);
void printHelpMessage(void);

#endif
