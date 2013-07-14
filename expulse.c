/*
** expulse.c for zappy in /home/ignatiev/Projects/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Thu Jul 04 09:57:07 2013 Marin Alcaraz
** Last update Sun Jul 14 16:52:38 2013 ivan ignatiev
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
#include	"proto_commands_net.h"

void		move_player(t_user_player *player,
			    t_request_data *rqd, t_server *s, t_world *w)
{
  char		response[ANSWER_SIZE];

  sprintf(response, "deplacement: %d\n", rqd->user->orientation + 1);
  cli_answer(player, s, response);
  item_delete_by_content(w->surface[rqd->user->posy][rqd->user->posx].players,
			 player);
  sprintf(response, "ppo %d %d %d %d\n", player->number,
	  player->posx, player->posy, player->orientation + 1);
  cli_answer_to_all_graph(s, response);
  item_pf(w->surface[player->posy][player->posy].players,
	  player, sizeof(t_user_player));
}

void		expulse_square(t_point *n, t_request_data *rqd,
			       t_world *w, t_server *s)
{
  t_item	*next;
  t_item	*current_item;

  current_item =
    list_get_head((w->surface[rqd->user->posy]
		   [rqd->user->posx]).players);
  while (current_item != NULL)
    {
      next = current_item->next;
      if (T_PLAYER(current_item->cont)->connected == CONNECTED
	  && current_item->cont != rqd->user)
	{
	  T_PLAYER(current_item->cont)->posx = n->x;
	  T_PLAYER(current_item->cont)->posy = n->y;
	  move_player(T_PLAYER(current_item->cont), rqd, s, w);
	}
      current_item = next;
    }
}
