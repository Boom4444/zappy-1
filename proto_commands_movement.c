/*
** proto_commands_movement.c for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Thu Jun 13 16:26:19 2013 Marin Alcaraz
** Last update Sun Jul 14 12:26:25 2013 ivan ignatiev
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

static t_point	g_steps[] =
  {
    {0, -1},
    {1, 0},
    {0, 1},
    {-1, 0}
  };

void		cli_avance(t_request_data *rqd, t_server *t, t_world *w)
{
  char		response[ANSWER_SIZE + 1];

  item_delete_by_content(w->surface[rqd->user->posy][rqd->user->posx].players,
			 (void*)rqd->user);
  rqd->user->posx = _MOD(rqd->user->posx + g_steps[rqd->user->orientation].x,
			 w->width);
  rqd->user->posy = _MOD(rqd->user->posy + g_steps[rqd->user->orientation].y,
			 w->height);
  item_pb(w->surface[rqd->user->posy][rqd->user->posx].players,
	  (void*)rqd->user, sizeof(t_user));
  cli_answer(rqd->user, t, "ok\n");
  sprintf(response, "ppo %d %d %d %d\n", rqd->user->number,
	  rqd->user->posx, rqd->user->posy, rqd->user->orientation + 1);
  cli_answer_to_all_graph(t, response);
}

void		cli_droite(t_request_data *rqd, t_server *t, t_world *w)
{
  char		response[ANSWER_SIZE + 1];

  (void) w;
  rqd->user->orientation = _MOD(rqd->user->orientation + 1, 4);
  cli_answer(rqd->user, t, "ok\n");
  sprintf(response, "ppo %d %d %d %d\n", rqd->user->number,
	  rqd->user->posx, rqd->user->posy, rqd->user->orientation + 1);
  cli_answer_to_all_graph(t, response);
}

void		cli_gauche(t_request_data *rqd, t_server *t, t_world *w)
{
  char		response[251];

  (void) w;
  rqd->user->orientation = _MOD(rqd->user->orientation - 1, 4);
  cli_answer(rqd->user, t, "ok\n");
  sprintf(response, "ppo %d %d %d %d\n", rqd->user->number,
	  rqd->user->posx, rqd->user->posy, rqd->user->orientation + 1);
  cli_answer_to_all_graph(t, response);
}

void		cli_broadcast(t_request_data *rqd, t_server *t, t_world *w)
{
  t_item	*current_item;
  char		response[ANSWER_SIZE];
  int		direction;

  (void)  w;
  current_item = list_get_head(t->client_list);
  while (current_item != NULL)
    {
      if ((T_PLAYER(current_item->cont)->protocol == CLI_PROTO)
	  && T_PLAYER(current_item->cont) != rqd->user)
        {
	  direction = broadcast_to(T_PLAYER(current_item->cont), rqd, t);
	  sprintf(response, "broadcast %d, %s\n",
		  direction, (char *)rqd->argv[0]);
	  cli_answer(T_PLAYER(current_item->cont), t, response);
        }
      current_item = current_item->next;
    }
  cli_answer(rqd->user, t, "ok\n");
  sprintf(response, "pbc %d %s\n", rqd->user->number,
            (char *)rqd->argv[0]);
  free(rqd->argv[0]);
  free(rqd->argv);
  cli_answer_to_all_graph(t, response);
}
