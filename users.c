/*
** users.c for zappy in /home/ignatiev/Projects/zappy
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Sat Apr 27 14:16:14 2013 ivan ignatiev
** Last update Sat Jul 13 13:33:59 2013 ivan ignatiev
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

int		user_destroy(t_user *user, t_server *s, t_world *w)
{
  item_delete_by_content(s->client_list, (void*)user);
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

void		users_life_proccess(t_server *s, t_world *w)
{
  t_item	*current;
  t_item	*next;

  (void) w;
  //SEGFLT
  current = list_get_head(s->client_list);
  while (current != NULL)
    {
      next = current->next;
      if (T_USER(current->cont)->protocol == CLI_PROTO
	  && T_USER(current->cont)->connected == CONNECTED)
	{
	  --(T_PLAYER(current->cont)->life);
	  if (T_PLAYER(current->cont)->life <= 0)
            {
	      T_PLAYER(current->cont)->life = LIFE_UNIT * s->options.tdelay;
	      --(T_PLAYER(current->cont)->inventory[FOOD]);
	      if (T_PLAYER(current->cont)->inventory[FOOD] <= 0)
                {
		  server_send(T_PLAYER(current->cont)->clientfd, "mort\n");
		  log_show("users_life_process", "", "PLayer %d finished his food",
			   T_PLAYER(current->cont)->number);
		  T_USER(current->cont)->connected = DISCONNECTED;
                }
            }
        }
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
