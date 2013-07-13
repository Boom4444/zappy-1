/*
** graph_command_player.c for zappy in /home/ignati_i//zappy/zappy
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Sat Jul 13 19:37:51 2013 ivan ignatiev
** Last update Sat Jul 13 19:38:09 2013 ivan ignatiev
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
	  sprintf(response, "pin %d %d %d %d %d %d %d %d %d %d\n",
		  p_number, T_PLAYER(current_player->cont)->posx,
		  T_PLAYER(current_player->cont)->posy,
		  T_PLAYER(current_player->cont)->inventory[0],
		  T_PLAYER(current_player->cont)->inventory[1],
		  T_PLAYER(current_player->cont)->inventory[2],
		  T_PLAYER(current_player->cont)->inventory[3],
		  T_PLAYER(current_player->cont)->inventory[4],
		  T_PLAYER(current_player->cont)->inventory[5],
		  T_PLAYER(current_player->cont)->inventory[6]);
	  cli_answer_to_graph(rqd->user, response);
	  return (0);
        }
      current_player = current_player->next;
    }
    return (0);
}
