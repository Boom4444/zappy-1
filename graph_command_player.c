/*
** graph_command_player.c for zappy in /home/hero/zappy
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Sat Jul 13 19:37:51 2013 ivan ignatiev
** Last update Fri Jul 12 22:40:20 2013 Marin Alcaraz
*/

#include	"main.h"
#include	"list.h"
#include	"options.h"
#include	"trantor.h"
#include	"server.h"
#include	"users.h"
#include	"graph_command.h"
#include	"answer.h"
#include	"error.h"

int		graph_command_ppo(t_graph_data *rqd,
				  t_server *s, t_world *w)
{
  char		response[STR_LIMIT];
  t_item	*current_player;
  int		p_number;

  (void) w;
  p_number = -1;
  sscanf(rqd->message, "ppo %d\n", &p_number);
  if (p_number < 0)
    return (cli_answer_to_graph(rqd->user, "sbp\n"));
  current_player = list_get_head(s->client_list);
  while (current_player != NULL)
    {
      if (T_PLAYER(current_player->cont)->number == p_number)
        {
	  sprintf(response, "ppo %d %d %d %d\n", p_number,
		  T_PLAYER(current_player->cont)->posx,
		  T_PLAYER(current_player->cont)->posy,
		  T_PLAYER(current_player->cont)->orientation);
	  cli_answer_to_graph(rqd->user, response);
	  return (0);
        }
      current_player = current_player->next;
    }
  return (0);
}

int		graph_command_piv(t_graph_data *rqd,
				  t_server *s, t_world *w)
{
  char		response[STR_LIMIT];
  t_item	*current_player;
  int		p_number;

  (void) w;
  p_number = -1;
  sscanf(rqd->message, "piv %d\n", &p_number);
  if (p_number < 0)
    return (cli_answer_to_graph(rqd->user, "sbp\n"));
  current_player = list_get_head(s->client_list);
    while (current_player != NULL)
    {
      if (T_PLAYER(current_player->cont)->number == p_number)
        {
	  sprintf(response, "piv %d %d\n", p_number,
		  T_PLAYER(current_player->cont)->level);
	  cli_answer_to_graph(rqd->user, response);
	  return (0);
        }
        current_player = current_player->next;
    }
    return (0);
}

int     format_response(char *response,
                        int p_number, t_user_player *player)
{
    sprintf(response, "pin %d %d %d %d %d %d %d %d %d %d\n",
            p_number, player->posx,
            player->posy,
            player->inventory[0],
            player->inventory[1],
            player->inventory[2],
            player->inventory[3],
            player->inventory[4],
            player->inventory[5],
            player->inventory[6]);
    return (0);
}

int		graph_command_pin(t_graph_data *rqd,
				  t_server *s, t_world *w)
{
  char		response[STR_LIMIT];
  t_item	*current_player;
  int		p_number;

  (void) w;
  p_number = -1;
  sscanf(rqd->message, "pin %d\n", &p_number);
  if (p_number < 0)
    return (cli_answer_to_graph(rqd->user, "sbp\n"));
  current_player = list_get_head(s->client_list);
  while (current_player != NULL)
    {
      if (T_PLAYER(current_player->cont)->number == p_number)
        {
            format_response(response,
                    p_number, T_PLAYER(current_player->cont));
            cli_answer_to_graph(rqd->user, response);
            return (0);
        }
      current_player = current_player->next;
    }
    return (0);
}
