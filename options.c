#include "options.h"

void  usage_display(char *str)
{
  printf("Usage: %s [option] argument(s)\n", str);
  printf("Server options :\n");
  printf("-p port\n-x width of the world\n");
  printf("-y height of the world\n-n name_of_team_1 name_of_team_2 ...\n");
  printf("-c number of clients allowed at the game beginning\n");
  printf("-t time delay for executing actions.\n");
  exit(EXIT_SUCCESS);
}

void    default_error(char *argv[])
{
  int   i;
  char  *curr;

  i = 1;
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

void    options_parse(int argc, char *argv[], t_opt *g_opt)
{
  int   l_opt;

  the_parse(argc, argv);
  invalid_find(argc, argv);
  opterr = 0;
  while ((l_opt = getopt(argc, argv, ":p:x:y:n:c:t:")) != -1)
  {
    if (l_opt == 'p')
      options_get(argv, l_opt, &g_opt->port);
    if (l_opt == 'x')
      options_get(argv, l_opt, &g_opt->width);
    if (l_opt == 'y')
      options_get(argv, l_opt, &g_opt->height);
    if (l_opt == 'n')
      names_parse(argv, l_opt, argc, g_opt);     
    if (l_opt == 'c')
      options_get(argv, l_opt, &g_opt->cmax);
    if (l_opt == 't')
      options_get(argv, l_opt, &g_opt->tdelay);
    if (l_opt == '?')
      default_error(argv);
    if (l_opt == ':')
      eagle_error(argv[0]);
  }
  teams_fill(g_opt);
}