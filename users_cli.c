/*
** users_cli.c for zappy in /home/ignati_i//zappy/zappy
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Sat Jul 13 12:26:14 2013 ivan ignatiev
** Last update Sun Jul 14 14:43:30 2013 ivan ignatiev
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

void		user_player_connected(t_user_player *u,
				      t_server *s, t_world *w)
{
  char		answer[ANSWER_SIZE];

  u->number = ++(s->players_count);
  log_show("user_player_init", "", "Player %d created in team '%s'",
	   u->number, u->team->name);
  ++(u->team->members);
  --(u->team->limit);
  u->life = 0;
  sprintf(answer, "%d\n", u->team->limit);
  cli_answer(u, s, answer);
  sprintf(answer, "%d %d\n", w->width, w->height);
  cli_answer(u, s, answer);
  sprintf(answer, "pnw %d %d %d %d %d %s\n", u->number,
	  u->posx, u->posy, u->orientation + 1,
	  u->level, u->team->name);
  cli_answer_to_all_graph(s, answer);
}

void		user_player_place(t_user_player *player, int x, int y,
				  int orientation)
{
  int		i;

  player->connected = CONNECTED;
  player->protocol = CLI_PROTO;
  player->posx = x;
  player->posy = y;
  player->orientation = orientation;
  player->tick = 0;
  player->level = 1;
  player->request_counter = 0;
  player->inventory[FOOD] = 10;
  i = 1;
  while (i < ARTICLES_LIMIT)
    {
      player->inventory[i] = 0;
      ++i;
    }
}

t_user_player	*user_player_init(t_user *user, t_team *team,
				  t_world *w, t_server *s)
{
  t_user_player	*player;

  (void) s;
  if ((player = T_PLAYER(realloc(user, sizeof(t_user_player)))) != NULL)
    {
      user_player_place(player,
			_MOD(rand(), w->width),
			_MOD(rand(), w->height),
			_MOD(rand(), 4));
      player->team = team;
      item_pf(w->surface[player->posy][player->posx].players,
	      (void*)player, sizeof(t_user_player));
      return (player);
    }
  error_show("user_player_init", "malloc",
	     "Unable allocate memory for players");
  return (NULL);
}

int		user_player_destroy(t_user_player *user,
				    t_server *s, t_world *w)
{
  char		response[ANSWER_SIZE];

  sprintf(response, "pdi %d\n", user->number);
  cli_answer_to_all_graph(s, response);
  ++(user->team->limit);
  item_delete_by_content(w->surface[user->posy][user->posx].players,
			 (void*)user);
  log_show("user_destroy", "", "Player %d disconnected and removed",
	   user->number);
  close(user->clientfd);
  free(user);
  return (0);
}
