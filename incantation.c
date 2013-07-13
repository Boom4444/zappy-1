/*
** incantation.c for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Wed Jul 10 09:57:57 2013 Marin Alcaraz
** Last update Fri Jul 12 22:52:26 2013 Marin Alcaraz
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

int	g_level_combinations[7][7] =
  {
    {1, 1, 0, 0, 0, 0, 0},
    {2, 1, 1, 1, 0, 0, 0},
    {2, 2, 0, 1, 0, 2, 0},
    {4, 1, 1, 2, 0, 1, 0},
    {4, 1, 2, 1, 3, 0, 0},
    {6, 1, 2, 3, 0, 1, 0},
    {6, 2, 2, 2, 2, 2, 1}
  };

int		init_incantation(t_list *piv, t_request_data *rqd,
				 t_server *s, t_world *w)
{
  t_item	*tmp_item;
  char		response[ANSWER_SIZE];
  char		aux_level[ANSWER_SIZE];

  tmp_item = list_get_head(w->surface[rqd->user->posy]
			   [rqd->user->posx].players);
  sprintf(response, "pic %d %d %d", rqd->user->posx, rqd->user->posy,
	  rqd->user->level);
  if (g_level_combinations[rqd->user->level - 1][0] !=
      count_players(w->surface[rqd->user->posy][rqd->user->posx].players,
		    rqd->user))
    return (error_show("init_incantation", "cli",
		       "Incantation failed, invalid number of players"));
  while (tmp_item != NULL)
    {
      if (T_PLAYER(tmp_item->cont)->level == rqd->user->level)
        {
	  sprintf(aux_level, " %d", T_PLAYER(tmp_item->cont)->number);
	  item_pb(piv, tmp_item->cont, sizeof(t_user_player));
	  strcat(response, aux_level);
        }
      tmp_item = tmp_item->next;
    }
  strcat(response, "\n");
  return (cli_answer_to_all_graph(s, response));
}

int		incantate(t_list *players, t_user_player *p,
			  t_server *t, t_world *w)
{
  int		eq_players;

  eq_players = count_players(w->surface[p->posy]
			     [p->posx].players, p);
  if (eq_players >= g_level_combinations[p->level - 1][0])
    {
        if (verify_enough_resources(p, w) == -1)
            return (-1);
        if (level_up(eq_players, p, players, w) != 0)
            return (-1);
    }
  else
    return (error_show("incantate", "",
                "Not enough players to begin the incantation"));
  cli_answer(p, t, "ok\n");
  return (0);
}

int		end_incantation(t_list *plv_list, t_request_data *rqd,
				t_server *s, t_world *w)
{
  char		response[ANSWER_SIZE];
  char		plv_str[ANSWER_SIZE];
  t_item	*tmp_item;

  sprintf(response, "pie %d %d ok\n", rqd->user->posx,
	  rqd->user->posy);
  cli_answer_to_all_graph(s, response);
  tmp_item = list_get_head(plv_list);
  while (tmp_item != NULL)
    {
      sprintf(plv_str, "plv %d %d\n",
	      T_PLAYER(tmp_item->cont)->number,
	      T_PLAYER(tmp_item->cont)->level);
      cli_answer_to_all_graph(s, plv_str);
      plv_str[0] = '\0';
      tmp_item = tmp_item->next;
    }
  response[0] = '\0';
  cli_command_bct(response, rqd->user->posx, rqd->user->posy, w);
  cli_answer_to_all_graph(s, response);
  return (0);
}

int		fail_incantation(t_request_data *rqd, t_server *s)
{
  char		response[ANSWER_SIZE];

  sprintf(response, "pie %d %d ko\n", rqd->user->posx,
	  rqd->user->posy);
  cli_answer_to_all_graph(s, response);
  return (error_show("fail_incantate", "",
		     "incantation failed"));
}
