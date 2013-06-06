/*
** options.c for Zappy in /home/el/Zappy/Main
**
** Made by oleg kuznietsov
** Login   <kuznet_o@epitech.net>
**
** Started on  Thu Jun  06 21:51:41 2013 oleg kuznietsov
** Last update Thu Jun  06 21:57:39 2013 oleg kuznietsov
*/

#include "options.h"

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
    if (item_pb(opt->names, argv[optind], (strlen(argv[optind]) + 1)) == -1)
    {
      fprintf(stderr, "%s ERROR: %s\n", "item_pb", "names_parse");
      exit(EXIT_FAILURE);
    }
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

void    options_getopt(int argc, char *argv[], t_opt *g_opt)
{
  int   l_opt;

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
