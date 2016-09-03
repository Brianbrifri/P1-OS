#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>

#include "logger.h"

int
main (int argc, char **argv)
{
  int hflag = 0;
  int index;
  int nValue = 42;
  char *filename = "logfile.txt";
  int c;
  struct option long_options[] = {
    {"help", no_argument, 0, 'h'},
    {}
  };

  opterr = 0;
  while ((c = getopt_long_only (argc, argv, "hn:l:", long_options, NULL)) != -1)
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
        if (optopt == 'n')
          fprintf (stderr, "Option -%c requires an argument.\n", optopt);
        else if (optopt == 'l')
          fprintf (stderr, "Option -%c requires an argument.\n", optopt);
        else if (isprint (optopt))
          fprintf (stderr, "Unknown option `-%c.\n", optopt);
        else
          printf("%c\n", optopt);
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
    printf("\nThank you for using the help menu!\n");
    printf("The following is a helpful guide to enable you use this\n");
    printf("debugger program to the best of your ability!\n\n");
    printf("-h and -help: Prints this help message\n");
    printf("-n: Allows you to set the number of messages to the alien planet Krudo\n");
    printf("\tthe default value is 42\n");
    printf("-l: Allows you to set the filename for the logger so the aliens can see what you\n");
    printf("\thave been up to. The default filename is logfile.txt\n");
  }
  return 0;
}
