/*
** option_parsing.c for Zappy in /home/el/Zappy/Main
**
** Made by oleg kuznietsov
** Login   <kuznet_o@epitech.net>
**
** Started on  Wed Jun  05 15:14:30 2013 oleg kuznietsov
** Last update Thu Jun  06 21:23:01 2013 oleg kuznietsov
*/

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
    if (item_pb(opt->names, tmp, size) == -1)
    {
      fprintf(stderr, "%s ERROR: %s\n", "item_pb", "teams_fill");
      exit(EXIT_FAILURE);
    }
  }
  free(tmp);
}
