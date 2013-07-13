/*
** users_graph.c for zappy in /home/hero/zappy
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Sat Jul 13 12:20:54 2013 ivan ignatiev
** Last update Fri Jul 12 22:30:12 2013 Marin Alcaraz
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
#include	"graph_command.h"
#include	"users_graph.h"

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

int		user_graph_destroy(t_user_graph *user)
{
  close(user->clientfd);
  free(user);
  return (log_show("user_destroy", "",
		   "GFX Client disconnected and removed"));
}

int 			graph_display_users(t_server *s, t_graph_data *rqd)
{
  t_item 	*current;
  char 	response[STR_LIMIT];

  current = list_get_head(s->client_list);
  while (current != NULL)
    {
      if (T_USER(current->cont)->protocol == CLI_PROTO)
	{
	  sprintf(response, "pnw %d %d %d %d %d %s\n",
		  T_PLAYER(current->cont)->number,
		  T_PLAYER(current->cont)->posx,
		  T_PLAYER(current->cont)->posy,
		  T_PLAYER(current->cont)->orientation + 1,
		  T_PLAYER(current->cont)->level,
		  T_PLAYER(current->cont)->team->name);
	  cli_answer_to_graph(rqd->user, response);
	}
      current = current->next;
    }
  return (0);
}

int             graph_display_eggs(t_server *s, t_graph_data *rqd)
{
  t_item      *current;
  char        response[STR_LIMIT];

  current = list_get_head(s->client_list);
  while (current != NULL)
    {
      if (T_USER(current->cont)->protocol == EGG_PROTO)
        {
	  sprintf(response, "enw %d %d %d %d\n",
		  T_EGG(current->cont)->number,
		  T_EGG(current->cont)->parent_number,
		  T_EGG(current->cont)->posx,
		  T_EGG(current->cont)->posy);
            cli_answer_to_graph(rqd->user, response);
        }
      current = current->next;
    }
  return (0);
}

int 		graph_client_init(t_user_graph *u, t_server *s, t_world *w)
{
  t_graph_data rqd;
  char		response[ANSWER_SIZE];

  rqd.user = u;
  graph_command_msz(&rqd, s, w);
  graph_command_sgt(&rqd, s, w);
  graph_command_mct(&rqd, s, w);
  graph_command_tna(&rqd, s, w);
  graph_display_users(s, &rqd);
  graph_display_eggs(s, &rqd);
  sprintf(response, "smg WELCOME TO TECH3SI ZAPPY SERVER!\n");
  cli_answer_to_graph(u, response);
  return (0);
}
