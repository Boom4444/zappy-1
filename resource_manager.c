/*
** resource_manager.c for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Sun Jul 14 07:14:41 2013 Marin Alcaraz
** Last update Sun Jul 14 18:21:55 2013 ivan ignatiev
*/

#include	"main.h"
#include	"list.h"
#include	"error.h"
#include	"options.h"
#include	"trantor.h"
#include	"server.h"
#include	"users.h"
#include	"request.h"
#include	"answer.h"
#include	"proto_commands_items.h"
#include	"resource_manager.h"

void		resources_refresh(int resource,
				  t_server *s, t_world *w)
{
  int		amount;
  int		minx;
  int		miny;
  char		response[ANSWER_SIZE];
  int		res;

  amount = 0;
  while (amount < RESOURCE_LIMIT / 16)
    {
      minx = _MOD(rand(), w->width);
      miny = _MOD(rand(), w->height);
      res = resource == FOOD ? FOOD : _MOD(rand(), RESOURCE_LIMIT);
      (w->surface[miny][minx]).resources[res]++;
      cli_command_bct(response, minx, miny, w);
      cli_answer_to_all_graph(s, response);
      amount = amount + 1;
    }
}

int		generate_resource(t_world *w, int width, int height)
{
  int		amount;
  int		minx;
  int		miny;
  int		resource;

  amount = 0;
  srand(time(NULL));
  while (amount < RESOURCE_LIMIT)
    {
      minx = _MOD(rand(), width);
      miny = _MOD(rand(), height);
      resource = _MOD(rand(), RES_TYPES_COUNT);
      (w->surface[miny][minx]).resources[resource]++;
      amount = amount + 1;
    }
  log_show("generate_resource", "", "Resources ready to use");
  return (0);
}

int		mineral_checker(t_square_unit *sq)
{
  int		i;

  i = 0;
  while (i < RES_TYPES_COUNT)
    {
      if (sq->resources[i] != 0)
	return (1);
      i = i + 1;
    }
  return (0);
}
