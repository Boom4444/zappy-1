/*
** users.c for zappy in /home/ignatiev/Projects/zappy
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Sat Apr 27 14:16:14 2013 ivan ignatiev
** Last update Sun Jul 14 14:43:37 2013 ivan ignatiev
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
#include	"request.h"

t_user		*user_create(void)
{
  t_user	*user;

  if ((user = (t_user*)malloc(sizeof(t_user))) != NULL)
    {
      user->protocol = NONE_PROTO;
      user->connected = PRE_CONNECTED;
      user->request = NULL;
      user->request_buf = NULL;
      user->addrlen = sizeof(struct sockaddr_in);
    }
  return (user);
}

void		user_destroy_anr(t_user *user, t_server *s)
{
  t_item	*current;
  t_item	*next;

  current = list_get_head(s->answer_list);
  while (current != NULL)
    {
      next = current->next;
      if (T_ANSWER(current)->user == (void*)user)
	{
	  free(current->cont);
	  item_delete(s->answer_list, current);
	}
      current = next;
    }
  current = list_get_head(s->request_list);
  while (current != NULL)
    {
      next = current->next;
      if (T_REQUEST(current)->data->user == (void*)user)
	{
	  free(current->cont);
	  item_delete(s->request_list, current);
	}
      current = next;
    }
}

int		user_destroy(t_user *user, t_server *s, t_world *w)
{
  item_delete_by_content(s->client_list, (void*)user);
  user_destroy_anr(user, s);
  if (user->protocol == CLI_PROTO)
    return (user_player_destroy(T_PLAYER(user), s, w));
  else if (user->protocol == GRAPHIC_PROTO)
    return (user_graph_destroy(T_GRAPH(user)));
  else if (user->protocol == EGG_PROTO)
    return (user_egg_destroy(T_EGG(user), s));
  if (user->clientfd >= 0)
    close(user->clientfd);
  free(user);
  return (log_show("user_destroy", "", "Client disconnected and removed"));
}

void		users_player_life(t_user_player *user, t_server *s)
{
  char		response[ANSWER_SIZE];

  --(user->life);
  if (user->life <= 0)
    {
      user->life = LIFE_UNIT * s->options.tdelay;
      --(user->inventory[FOOD]);
      if (user->inventory[FOOD] <= 0)
	{
	  server_send(user->clientfd, "mort\n");
	  sprintf(response, "pdi %d\n", user->number);
	  cli_answer_to_all_graph(s, response);
	  log_show("users_life_process", "", "PLayer %d finished his food",
		   user->number);
	  user->connected = DISCONNECTED;
	}
    }
}

void		users_life_proccess(t_server *s, t_world *w)
{
  t_item	*current;
  t_item	*next;

  (void) w;
  current = list_get_head(s->client_list);
  while (current != NULL)
    {
      next = current->next;
      if (T_USER(current->cont)->protocol == CLI_PROTO
	  && T_USER(current->cont)->connected == CONNECTED)
	users_player_life(T_PLAYER(current->cont), s);
      else if (T_USER(current->cont)->protocol == EGG_PROTO
	       && T_USER(current->cont)->protocol == PRE_CONNECTED)
        {
	  --(T_EGG(current->cont)->life);
	  if (T_EGG(current->cont)->life <= 0)
	    T_USER(current->cont)->connected = DISCONNECTED;
	}
      current = next;
    }
}
