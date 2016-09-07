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
  int index;
  int nValue = 42;
  char *filename = "logfile.txt";
  char *programName = argv[0];
  char *option = NULL;
  char *short_options = "hn:l:";
  int c;

  struct option long_options[] = {
    {"help", no_argument, 0, 'h'},
    {0,     0,            0,  0},
  };

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
          fprintf (stderr, "Option -%c requires an argument.\n", optopt);
        }
        else if (optopt == 'l') {
          fprintf (stderr, "Option -%c requires an argument.\n", optopt);
        }
        else if (isprint (optopt)) {
          fprintf (stderr, "Unknown option -%c.\n", optopt);
        }
        else {
          fprintf (stderr, "Unknown option character `\\x%x'.\n", optopt);
        }
        return 1;
      default:
        abort ();
      }

  for (index = optind; index < argc; index++) {
    char nonOptArg[21 + sizeof(argv[index])];
    sprintf(nonOptArg, "Non-option argument %s", argv[index]);
    puts(nonOptArg);
    buildAndAddErrorMessage(nonOptArg, programName, nValue);
    printf ("Non-option argument %s\n", argv[index]);
  }

  if(hflag) {
    printHelpMessage();
  }

  data_t newData;
  newData.string = "Unknown option -a\n";
  char * statusMessage = addMsg(newData);
  saveLog(filename);
  clearLog();
  return 0;
}
