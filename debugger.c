#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>

#include "logger.h"

int main (int argc, char **argv)
{
  int index;
  int nValue = 42;
  char *filename = "logfile.txt";
  char *option = NULL;
  char *short_options = "hn:l:";
  int c;
  struct option long_options[] = {
    {"help", no_argument, 0, 'h'},
    {0,      0,           0,  0},
    {}
  };

  opterr = 0;
  while ((c = getopt_long_only (argc, argv, short_options, long_options, NULL)) != -1)
    switch (c)
      {
      case 'h':
        printHelpMessage();
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
          //data_t newData;
          //newData.string = "Unknown option -c\n";
          //if(addMsg(newData) == 0) {
            //printf("success\n");
          //}
          //saveLog(filename);
        }
        else
          fprintf (stderr,
                   "Unknown option character `\\x%x'.\n",
                   optopt);
        return 1;
      default:
        abort ();
      }
  
  for (index = optind; index < argc; index++)
    printf ("Non-option argument %s\n", argv[index]);

  return 0;
}
