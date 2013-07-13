/*
** options.c for zappy in /home/hero/zappy
**
** Made by oleg kuznietsov
** Login   <kuznet_o@epitech.net>
**
** Started on  Fri Jun  07 00:47:46 2013 oleg kuznietsov
** Last update Fri Jul 12 21:47:33 2013 Marin Alcaraz
*/

#include	"main.h"
#include	"list.h"
#include	"item.h"
#include	"error.h"
#include	"options.h"

void		default_error(char *argv[])
{
  char		*curr;

  curr = argv[optind - 1];
  if (optopt == curr[1])
  {
    printf("%s: invalid option -- '%c'\n", argv[0], optopt);
    printf("Use \"%s --help\" to get more information.\n", argv[0]);
    exit(EXIT_SUCCESS);
  }
  curr = argv[optind];
  printf("%s: invalid option -- '%c'\n", argv[0], curr[1]);
  printf("Use \"%s --help\" to get more information.\n", argv[0]);
  exit(EXIT_SUCCESS);
}

void		names_parse(char *argv[], char c, int argc, t_opt *opt)
{
  if (*optarg == '-')
    {
      printf("%s: option requires an argument -- '%c'\n", argv[0], c);
      printf("Use \"%s --help\" to get more information.\n", argv[0]);
      exit(EXIT_SUCCESS);
    }
  else if (*argv[optind - 1] == '-'
	   && item_pb(opt->names, optarg, (strlen(optarg) + 1)) == -1)
    {
      fprintf(stderr, "%s ERROR: %s\n", "item_pb", "names_parse");
      exit(EXIT_FAILURE);
    }
  else
    --optind;
  while ((optind < argc) && (*argv[optind] != '-'))
    {
      if (item_pb(opt->names, argv[optind],
		  (strlen(argv[optind]) + 1)) == -1)
	{
	  fprintf(stderr, "%s ERROR: %s\n", "item_pb", "names_parse");
	  exit(EXIT_FAILURE);
	}
      ++optind;
    }
}

void		options_get(char *argv[], char c, unsigned int *opt)
{
  if (*optarg == '-')
    {
      printf("%s: option requires an argument -- '%c'\n", argv[0], c);
      printf("Use \"%s --help\" to get more information.\n", argv[0]);
      exit(EXIT_SUCCESS);
    }
  *opt = atoi(optarg);
  if (optarg[0] != '0' && *opt == 0)
    {
      printf("%s: invalid argument -- \"%s\"\n", argv[0], optarg);
      printf("Use \"%s --help\" to get more information.\n", argv[0]);
      exit(EXIT_SUCCESS);
    }
}

void    options_getopt(int argc, char *argv[], t_opt *g_opt)
{
  int   l_opt;

  opterr = 0;
  while ((l_opt = getopt(argc, argv, ":p:x:y:n:c:t:d")) != -1)
  {
    if (l_opt == 'p')
      options_get(argv, l_opt, &g_opt->port);
    if (l_opt == 'd')
        g_opt->mode = 1;
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
  teams_fill(g_opt, 2);

  log_show("options_parse", "", "Options accepted : "
	   "PORT = %d, WIDTH = %d, HEIGHT = %d, CMAX = %d, T = %d",
	   g_opt->port, g_opt->width,
	   g_opt->height, g_opt->cmax, g_opt->tdelay);
}
