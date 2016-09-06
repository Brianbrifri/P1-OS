#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>

#include "logger.h"
#include "debugger.h"

char *fileName = NULL;

int main (int argc, char **argv)
{
  int hflag = 0;
  int index;
  int nValue = 42;
  char *filename = "logfile.txt";
  char *option = NULL;
  char *short_options = "hn:l:";
  int c;
  struct option long_options[] = {
    {"help", no_argument, 0, 'h'},
    {}
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
        else if (optopt == 'l')
          fprintf (stderr, "Option -%c requires an argument.\n", optopt);
        else if (isprint (optopt)) {
          fprintf (stderr, "Unknown option -%c.\n", optopt);
          data_t newData;
          newData.string = "Unknown option -c\n";
          if(addMsg(newData) == 0) {
            printf("success\n");
          }
          saveLog(filename);
        }
        else
          fprintf (stderr,
                   "Unknown option character `\\x%x'.\n",
                   optopt);
        return 1;
      default:
        abort ();
      }

  printf ("hflag = %d, nValue = %d, filename = %s\n",
          hflag, nValue, filename);

  for (index = optind; index < argc; index++)
    printf ("Non-option argument %s\n", argv[index]);

  if(hflag) {
    printHelpMessage();
  }
  data_t newData;
  newData.string = "Unknown option -a\n";
  char * statusMessage = addMsg(newData);
  saveLog(fileName);
  clearLog();
  return 0;
}
