/*
** resource_manager.c for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Sun Jul 14 07:14:41 2013 Marin Alcaraz
** Last update Sun Jul 14 07:14:43 2013 Marin Alcaraz
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

void		food_refresh(t_server *s, t_world *w,
			     int width, int height)
{
  int		amount;
  int		minx;
  int		miny;
  char		response[ANSWER_SIZE];

  amount = 0;
  srand(time(NULL));
  while (amount < RESOURCE_LIMIT / 16)
    {
      minx = _MOD(rand(), width);
      miny = _MOD(rand(), height);
      (w->surface[miny][minx]).resources[0]++;
      cli_command_bct(response, minx, miny, w);
      cli_answer_to_all_graph(s, response);
      amount = amount + 1;
    }
  log_show("generate_resource", "", "Resources ready to use");
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
      resource = _MOD(rand(), 7);
      (w->surface[miny][minx]).resources[resource]++;
      amount = amount + 1;
    }
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
