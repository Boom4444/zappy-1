/*
** proto_commands_voir.c for zappy in /home/ignati_i//zappy/zappy
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Sat Jul 13 19:20:15 2013 ivan ignatiev
** Last update Sat Jul 13 20:17:12 2013 ivan ignatiev
*/

#include	"main.h"
#include	"list.h"
#include	"options.h"
#include	"trantor.h"
#include	"server.h"
#include	"users.h"
#include	"request.h"
#include	"answer.h"
#include	"item.h"
#include	"proto_commands_movement.h"
#include	"str.h"

static t_point	g_voir[] =
  {
    {-1, -1},
    {1, -1},
    {1, 1},
    {-1, 1}
  };

static t_point	g_steps[] =
  {
    {0, -1},
    {1, 0},
    {0, 1},
    {-1, 0}
  };

char		*cli_voir_sub_level(char *response, t_point *obj,
				    t_request_data *rqd, t_world *w)
{
  response = cli_voir_players(response,
			      w->surface[obj->y][obj->x].players);
  response = cli_voir_resources(response,
				w->surface[obj->y][obj->x].resources);
  obj->x = _MOD(obj->x
		+ g_steps[_MOD(rqd->user->orientation + 1, 4)].x, w->width);
  obj->y = _MOD(obj->y
		+ g_steps[_MOD(rqd->user->orientation + 1, 4)].y, w->height);
  return (response);
}

void		cli_voir_level_step(t_point *v, t_request_data *rqd, t_world *w)
{
  v->x = _MOD(v->x + g_voir[_MOD(rqd->user->orientation, 4)].x, w->width);
  v->y = _MOD(v->y + g_voir[_MOD(rqd->user->orientation, 4)].y, w->height);
}

char		*cli_voir_level(char *response, t_request_data *rqd,  t_world *w)
{
  int		level;
  int		level_count;
  t_point	v;
  t_point	obj;
  int		i;

  level = 0;
  v.x = rqd->user->posx;
  v.y = rqd->user->posy;
  level_count = 1;
  while (level <= rqd->user->level)
    {
      obj.x = v.x;
      obj.y = v.y;
      i = 0;
      while (i < level_count)
        {
	  response = cli_voir_sub_level(response, &obj, rqd, w);
	  ++i;
        }
      cli_voir_level_step(&v, rqd, w);
      level_count += 2;
      ++(level);
    }
  return (response);
}

void		cli_voir(t_request_data *rqd, t_server *s, t_world *w)
{
  char		*response;

  response = NULL;
  response = stralloccat(response, "{");
  response = cli_voir_level(response, rqd, w);
  response = stralloccat(response, "}\n");
  if (response != NULL)
    {
       cli_answer(rqd->user, s, response);
       free(response);
    }
  else
    cli_answer(rqd->user, s, "ko\n");
}
