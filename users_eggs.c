/*
** users_eggs.c for zappy in /home/ignati_i//zappy/zappy
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Sat Jul 13 12:33:06 2013 ivan ignatiev
** Last update Sat Jul 13 12:59:31 2013 ivan ignatiev
*/

#include	"main.h"
#include	"list.h"
#include	"options.h"
#include	"trantor.h"
#include	"server.h"
#include	"users.h"
#include	"error.h"
#include	"item.h"
#include	"answer.h"

t_user_player	*user_player_replace_egg(t_user *user, t_user_egg *egg)
{
  t_user_player	*player;

  if ((player = realloc(user, sizeof(t_user_player))) != NULL)
    {
      user_player_place(player,
			egg->posx,
			egg->posy,
			_MOD(rand(), 4));
      player->team = egg->team;
      item_pf(w->surface[player->posy][player->posx].players,
	      (void*)player, sizeof(t_user_player));
      log_show("user_player_egg", "", "Egg %d become a player",
	       egg->number);
      egg->connected = DISCONNECTED;
      return (player);
    }
  error_show("user_player_init", "malloc", "Unable allocate memory for players");
  return (NULL);
}

t_user_player	*user_player_egg(t_user *user, t_team *team,
				 t_world *w, t_server *s)
{
  t_user_egg	*egg;
  t_item	*current;

  current = list_get_head(s->client_list);
  while (current != NULL)
    {
      if (T_USER(current->cont)->protocol == EGG_PROTO
	  && T_USER(current->cont)->connected = PRE_CONNECTED
	  && T_EGG(current->cont)->hatched
	  && T_EGG(current->cont)->team == team)
	return (user_player_replace_egg(user, T_EGG(current->cont)));
      current = current->next;
    }
  return (NULL);
}

t_user_egg	*user_egg_init(t_user_player *parent, t_server *s)
{
  t_user_egg	*egg;

  if ((egg = malloc(sizeof(t_user_egg))) != NULL)
    {
      egg->connected = PRE_CONNECTED;
      egg->protocol = EGG_PROTO;
      egg->clientfd = -1;
      egg->hatched = 0;
      egg->life = LIFE_UNIT * 10 * s->options.tdelay;
      egg->posx = parent->posx;
      egg->posy = parent->posy;
      egg->parent_number = parent->number;
      egg->team = parent->team;
      return (egg);
    }
  error_show("user_player_init", "malloc",
	     "Unable allocate memory for eggs");
  return (NULL);
}

int		user_egg_destroy(t_user_egg *user, t_server *s)
{
  char		response[ANSWER_SIZE];

  --(user->team->limit);
  sprintf(response, "edi %d\n", user->number);
  cli_answer_to_all_graph(s, response);
  log_show("user_destroy", "", "Egg's spirit %d goes away", T_EGG(user)->number);
  free(user);
  return (0);
}
