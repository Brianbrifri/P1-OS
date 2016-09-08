#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <time.h>

#include "logger.h"

int main (int argc, char **argv)
{
  int hflag = 0;
  int nonOptArgFlag = 0;
  int index;
  int nValue = 42;
  char *filename = "logfile.txt";
  char *defaultFileName = "logfile.txt";
  char *programName = argv[0];
  char *option = NULL;
  char *short_options = "hn:l:";
  int c;

  struct option long_options[] = {
    {"help", no_argument, 0, 'h'},
    {0,     0,            0,  0},
    {}
  };

  buildAndAddErrorMessage("Test Log", programName, nValue);
  
  opterr = 0;
  while ((c = getopt_long (argc, argv, short_options, long_options, NULL)) != -1)
    switch (c)
      {
      case 'h':
        hflag = 1;
        break;
      case 'n':
        nValue = atoi(optarg);
        break;
      case 'l':
        filename = optarg;
        break;
      case '?':
        if (optopt == 'n') {
          char message[50];
          sprintf(message, "Option -%c requires an argument. Using default value.", optopt);
          puts(message);
          buildAndAddErrorMessage(message, programName, nValue);
          nValue = 42;
        }
        else if (optopt == 'l') {
          char message[50];
          sprintf(message, "Option -%c requires an argument. Using default value.", optopt);
          puts(message);
          buildAndAddErrorMessage(message, programName, nValue);
          filename = defaultFileName;
        }
        else if (isprint (optopt)) {
          char message[50];
          sprintf(message, "Unknown option -%c. Terminating.", optopt);
          puts(message);
          printShortHelpMessage();
          buildAndAddErrorMessage(message, programName, nValue);
          if(!saveLog(filename)) {
            printf("Unable to save to specified file. Saving to default file.\n");
            saveLog(defaultFileName);
          }
          clearLog();
          return 1;
        }
        else {
          printShortHelpMessage();
          char message[50];
          sprintf(message, "Unknown option character `\\x%x'. Terminating.", optopt);
          buildAndAddErrorMessage(message, programName, nValue);
          if(!saveLog(filename)) {
            printf("Unable to save to specified file. Saving to default file.\n");
            saveLog(defaultFileName);
          }
          clearLog();
          return 1; 
        }
      }

  if(!saveLog(filename)) {
      printf("Unable to save to specified file. Saving to default file.\n");
      saveLog(defaultFileName);
    }
  clearLog();

  for (index = optind; index < argc; index++) {
    char message[21 + sizeof(argv[index])];
    sprintf(message, "Non-option argument %s", argv[index]);
    buildAndAddErrorMessage(message, programName, nValue);
    nonOptArgFlag = 1;
  }

  if(nonOptArgFlag) {
    printShortHelpMessage();
    if(!saveLog(filename)) {
      printf("Unable to save to specified file. Saving to default file.\n");
      saveLog(defaultFileName);
    }
    clearLog();
    return 1;
  }

  if(hflag) {
    printHelpMessage();
  }

  if(!hflag) {
    buildAndAddErrorMessage("Whaaaat? No aliens??", programName, nValue); 
    buildAndAddErrorMessage("Their leader has come!!", programName, nValue); 
    buildAndAddErrorMessage("Running low on health....", programName, nValue); 
  }
  if(!saveLog(filename)) {
      printf("Unable to save to specified file. Saving to default file.\n");
      saveLog(defaultFileName);
  }
  clearLog();

  return 0;
}
