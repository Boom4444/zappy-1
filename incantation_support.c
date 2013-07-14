/*
** incantation_support.c for zappy in /home/hero/zappy
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Sat Jul 13 19:44:14 2013 ivan ignatiev
** Last update Sun Jul 14 21:22:35 2013 ivan ignatiev
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
#include	"resource_manager.h"

int		count_players(t_list *players, t_user_player *player)
{
  int		eq_players;
  t_item	*tmp_item;

  eq_players = 0;
  tmp_item = list_get_head(players);
  while (tmp_item != NULL)
    {
      if (T_PLAYER(tmp_item->cont)->connected == CONNECTED
	  && T_PLAYER(tmp_item->cont)->level == player->level)
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
        if (T_PLAYER(tmp_item->cont)->level == MAX_LEVEL)
	  T_PLAYER(tmp_item->cont)->team->v_flag++;
        tmp_item = tmp_item->next;
      }
    return (0);
}

int	verify_enough_resources(t_user_player *p, t_server *s,
				t_world *w)
{
  int	i;

  i = 1;
  while (i < RES_TYPES_COUNT)
    {
      if (w->surface[p->posy][p->posx].resources[i] <
	  g_level_combinations[p->level - 1][i])
	{
	  return (error_show("incantate", "",
			     "Not enough resources to begin"
			     "the incantation"));
	}
      w->surface[p->posy][p->posx].resources[i] -=
	g_level_combinations[p->level - 1][i];
      i = i + 1;
    }
  resources_refresh(RES_TYPES_COUNT, s, w);
  return (0);
}

void		check_victory(t_server *t)
{
  char		response[ANSWER_SIZE];
  t_item	*tmp_team;

  tmp_team = list_get_head(t->team_list);
  while (tmp_team != NULL)
    {
      if (T_TEAM(tmp_team)->v_flag == VICTORY)
        {
	  sprintf(response, "seg %s\n", T_TEAM(tmp_team)->name);
	  cli_answer_to_all_graph(t, response);
	  t->result = 1;
	  log_show("check_vicroty", "", "Team %s won!",
		   T_TEAM(tmp_team)->name);
	  return ;
        }
      tmp_team = tmp_team->next;
    }
  return ;
}
