/*
** incantation_support.c for zappy in /home/ignati_i//zappy/zappy
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Sat Jul 13 19:44:14 2013 ivan ignatiev
** Last update Sat Jul 13 19:44:15 2013 ivan ignatiev
*/

#include	"main.h"
#include	"list.h"
#include	"options.h"
#include	"trantor.h"
#include	"server.h"
#include	"users.h"
#include	"request.h"
#include	"answer.h"
#include	"proto_commands_net.h"
#include	"proto_commands_items.h"
#include	"item.h"
#include	"error.h"
#include	"incantation.h"

int		count_players(t_list *players, t_user_player *player)
{
  int		eq_players;
  t_item	*tmp_item;

  eq_players = 0;
  tmp_item = list_get_head(players);
  while (tmp_item != NULL)
    {
      if (T_PLAYER(tmp_item->cont)->level == player->level)
            eq_players = eq_players + 1;
      tmp_item = tmp_item->next;
    }
  return (eq_players);
}

int		match_players(t_list *ps, t_list *currents)
{
  int		flag;
  t_item	*tmp_item;
  t_item	*ps_current;

  flag = 0;
  tmp_item = list_get_head(currents);
  ps_current = list_get_head(ps);
  while (tmp_item != NULL && ps_current != NULL)
    {
      if (T_PLAYER(ps_current->cont)->number ==
	  T_PLAYER(tmp_item->cont)->number)
	flag = flag  + 1;
      ps_current = ps_current->next;
      tmp_item = tmp_item->next;
    }
  return (flag);
}

int		level_up(int eq_players, t_user_player *p,
			 t_list *players, t_world *w)
{
  t_item	*tmp_item;

  tmp_item = list_get_head(players);
  if (eq_players != match_players(players,
				  w->surface[p->posy][p->posx].players))
    return (error_show("level_up", "",
		       "One or many players left the square"));
    while (tmp_item != NULL)
      {
        T_PLAYER(tmp_item->cont)->level++;
        if (T_PLAYER(tmp_item->cont)->level == 8)
	  T_PLAYER(tmp_item->cont)->team->v_flag++;
        tmp_item = tmp_item->next;
      }
    return (0);
}
