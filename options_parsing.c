/*
** options_parsing.c for zappy in /home/hero/zappy
**
** Made by oleg kuznietsov
** Login   <kuznet_o@epitech.eu>
**
** Started on  Fri Jun  07 00:49:53 2013 oleg kuznietsov
** Last update Sat Jul 13 16:12:20 2013 ivan ignatiev
*/

#include	"main.h"
#include	"list.h"
#include	"item.h"
#include	"options.h"

void		usage_display(char *str)
{
  printf("Usage: %s [option] argument(s)\n", str);
  printf("Server options :\n");
  printf("-p port\n-x width of the world\n");
  printf("-y height of the world\n-n name_of_team_1 \"name of team 2\" ...\n");
  printf("-c number of clients allowed at the game beginning\n");
  printf("-t time delay for executing actions\n");
  printf("-d run in daemon mode {PORT}\n");
  exit(EXIT_SUCCESS);
}

void		invalid_find(int argc, char *argv[])
{
  int		i;
  char		*curr;

  i = 1;
  while (i != argc)
  {
    if (*argv[i] == '-')
      {
	curr = argv[i];
	if (curr[1] != 0 && curr[1] == 'n')
	  while ((i + 1) != argc && *argv[i + 1] != '-')
	    ++i;
	else
	  if ((i + 1) != argc && *argv[i + 1] != '-' && curr[2] == 0)
	    ++i;
      }
    else
      {
	printf("%s: syntax error -- \"%s\"\n", argv[0], argv[i]);
	printf("Use \"%s --help\" to get more information.\n", argv[0]);
	exit(EXIT_SUCCESS);
      }
    ++i;
  }
}

void		the_parse(int argc, char *argv[])
{
  int		i;
  int		t;
  char		*curr;

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

void		teams_fill(t_opt *opt, int n)
{
  int		i;
  char		tmp[255];

  i = 1;
  while (i <= n)
    {
      sprintf(tmp, "Team%d", i);
      if (item_pb(opt->names, (void*)strdup(tmp), strlen(tmp)) == -1)
        {
            fprintf(stderr, "%s ERROR: %s\n", "item_pb", "teams_fill");
            return ;
        }
      i++;
    }
}
