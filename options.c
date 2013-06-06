#include "options.h"

void  usage_display(char *str)
{
  printf("Usage: %s [option] argument(s)\n", str);
  printf("Server options :\n");
  printf("-p port\n-x width of the world\n");
  printf("-y height of the world\n-n name_of_team_1 \"name of team 2\" ...\n");
  printf("-c number of clients allowed at the game beginning\n");
  printf("-t time delay for executing actions.\n");
  exit(EXIT_SUCCESS);
}

void    default_error(char *argv[])
{
  char  *curr;

  curr = argv[optind - 1];
  if (optopt == curr[1])
  {
    printf("%s: invalid option -- \"%s\"\n", argv[0], argv[optind - 1]);
    usage_display(argv[0]);
  }
  else
  {
    printf("%s: invalid option -- \"%s\"\n", argv[0], argv[optind]);
    usage_display(argv[0]);
  }
}

void  names_parse(char *argv[], char c, int argc, t_opt *opt)
{
  if (*optarg == '-')
  {
    printf("%s: option requires an argument -- '%c'\n", argv[0], c);
    usage_display(argv[0]);
  }
  --optind;
  while ((optind < argc) && (*argv[optind] != '-'))
  {
    item_pb(opt->names, argv[optind], (strlen(argv[optind]) + 1));
    ++optind;
  }
}

void    options_get(char *argv[], char c, int *opt)
{
  char  *curr;

  if (*optarg == '-')
  {
    printf("%s: option requires an argument -- '%c'\n", argv[0], c);
    usage_display(argv[0]);
  }
  *opt = atoi(optarg);
  if (optarg[0] != '0' && *opt == 0)
  {
    curr = argv[optind - 1];
    if (curr[1] != 0)
    {
      printf("%s: invalid option -- \"%s\"\n", argv[0], curr);
      usage_display(argv[0]);
    }
    printf("%s: invalid argument -- \'%c'\n", argv[0], c);
    usage_display(argv[0]);
  }
}

void  options_parse(int argc, char *argv[], t_opt *g_opt)
{
  int i;

  i = 0;
  while (i != argc)
  {
    if (strcmp("--help", argv[i]) == 0)
      usage_display(argv[0]);
    ++i;
  }
  the_parse(argc, argv);
  invalid_find(argc, argv);
  options_getopt(argc, argv, g_opt);
  teams_fill(g_opt);
}
