#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "logger.h"

typedef struct list_struct {
  data_t item;
  struct list_struct *next;
} log_t;

static log_t *headptr = NULL;
static log_t *tailptr = NULL;

int addMsg(data_t data) {
  log_t *newEntry;
  int entrySize;

  entrySize = sizeof(log_t) + strlen(data.string) + 1;
  //Couldn't add newEntry
  if((newEntry = (log_t *) (malloc(entrySize))) == NULL) {
    return -1;
  }
  newEntry->item.time = data.time;
  newEntry->item.string = (char *)newEntry + sizeof(log_t);
  strcpy(newEntry->item.string, data.string);
  newEntry->next = NULL;
  if(headptr == NULL) {
    headptr = newEntry;
  }
  else {
    tailptr->next = newEntry;
  }
  tailptr = newEntry;
  return 0;
}

void clearLog(void) {

}

char *getLog(void) {
  return NULL;
}

int saveLog(char *filename) {
  FILE * file = fopen(filename, "wb");
  if(file != NULL) {
    fwrite(headptr, sizeof(struct list_struct), 1, file);
    fclose(file);
  }
  return 0;
}

void printHelpMessage(void) {
    printf("\nThank you for using the help menu!\n");
    printf("The following is a helpful guide to enable you to use this\n");
    printf("debugger program to the best of your ability!\n\n");
    printf("-h, -help: Prints this help message.\n");
    printf("-n: Allows you to set the number of messages to the alien planet Krudo.\n");
    printf("\tThe default value is 42.\n");
    printf("-l: Allows you to set the filename for the logger so the aliens can see how bad you mess up.\n");
}
