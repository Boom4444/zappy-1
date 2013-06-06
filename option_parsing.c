/*
** option_parsing.c for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Fri Mar 15 16:48:12 2013 Marin Alcaraz
** Last update Thu Jun 06 11:14:06 2013 Marin Alcaraz
*/

#include "options.h"

void    invalid_find(int argc, char *argv[])
{
  int   i;
  char  *curr;

  i = 1;
  while (i != argc)
  {
    if (*argv[i] == '-')
    {
      curr = argv[i];
      if (curr[1] != 0 && curr[1] == 'n')
      {
        while ((i + 1) != argc && *argv[i + 1] != '-')
          ++i;
      }
      else
        if ((i + 1) != argc && *argv[i + 1] != '-')
          ++i;
    }
    else
    {
      printf("%s: invalid option -- \"%s\"\n", argv[0], argv[i]);
      usage_display(argv[0]);
    }
    ++i;
  }
}

void    the_parse(int argc, char *argv[])
{
  int   i;
  int   t;
  char  *curr;

  t = 0;
  i = 1;
  while (i != argc)
  {
    curr = argv[i];
    if (curr[0] == '-' && curr[1] != 0 && isdigit(curr[1]))
      negative_error(argv[0], argv[i]);
    if (curr[t] == '-' && curr[t + 1] == 0)
      syntax_error(argv[0], argv[i]);
    while (curr[t] != 0)
    {
      if (curr[t] == 10)
        lparse_error_1(argv[0]);
      if (isalnum(curr[t]) == 0 && curr[t] != '-'
          && curr[t] != ' ' && curr[t] != '_')
        lparse_error_2(argv[0], curr[t]);
      t++;
    }
    t = 0;
    ++i;
  }
}

int   get_nbrlen(int nbr)
{
  int i;

  i = 0;
  while (nbr != 0)
  {
    nbr /= 10;
    ++i;
  }
  return (i);
}

void    teams_fill(t_opt *opt)
{
  int   i;
  char  *tmp;
  int   size;

  tmp = NULL;
  i = opt->names->len;
  while (i < opt->cmax)
  {
    ++i;
    size = get_nbrlen(i) + 6;
    if ((tmp = realloc(tmp, size)) == NULL)
    {
      fprintf(stderr, "%s ERROR: %s\n", "realloc", "teams_fill");
      exit(EXIT_FAILURE);
    }
    sprintf(tmp, "Team %d", i);
    item_pb(opt->names, tmp, size);
  }
  free(tmp);
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
