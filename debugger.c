#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>

int
main (int argc, char **argv)
{
  int hflag = 0;
  int index;
  int nValue = 42;
  char *filename = "logfile.txt";
  int c;
  struct option long_options[] = {
    {"help", no_argument, 0, 'h'}
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
          fprintf (stderr, "Option -n requires an argument.\n", optopt);
        else if (optopt == 'l')
          fprintf (stderr, "Option -l requires an argument.\n", optopt);
        else if (isprint (optopt))
          fprintf (stderr, "Unknown option `-%c'.\n", optopt);
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
  return 0;
}
