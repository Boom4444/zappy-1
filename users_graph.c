/*
** users_graph.c for zappy in /home/ignati_i//zappy/zappy
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Sat Jul 13 12:20:54 2013 ivan ignatiev
** Last update Sat Jul 13 12:59:16 2013 ivan ignatiev
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

t_user_graph	*user_graph_init(t_user *user)
{
  t_user_graph	*graph;

  if ((graph = realloc(user, sizeof(t_user_graph))) != NULL)
    {
      graph->protocol = GRAPHIC_PROTO;
      graph->connected = CONNECTED;
      log_show("user_graph_init", "", "Graphic client created");
      return (graph);
    }
  error_show("user_graph_init", "malloc",
	     "Unable allocate memory for GFX clients");
  return (NULL);
}


int		user_graph_destroy(t_graph_user *user)
{
  close(user->clientfd);
  free(user);
  return (log_show("user_destroy", "",
		   "GFX Client disconnected and removed"));
}
