/*
** request.c for zappy in /home/hero/zappy
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Thu Jun 20 20:00:46 2013 ivan ignatiev
** Last update Sun Jul 14 14:11:34 2013 ivan ignatiev
*/

#include	"main.h"
#include	"list.h"
#include	"item.h"
#include	"options.h"
#include	"trantor.h"
#include	"server.h"
#include	"users.h"
#include	"error.h"
#include	"request.h"
#include	"proto.h"
#include	"cli_command_parse.h"
#include	"proto_commands_net.h"
#include	"proto_commands_movement.h"
#include	"proto_commands_items.h"

static t_request_type	g_cli_commands[] =
  {
    {"avance", 7, 0, cli_parse_avance, cli_avance },
    {"droite", 7, 0, cli_parse_droite, cli_droite },
    {"gauche", 7, 0, cli_parse_gauche, cli_gauche  },
    {"voir", 7, 0, cli_parse_voir, cli_voir },
    {"inventaire", 7, 0, cli_parse_inventaire, cli_inventaire },
    {"prend", 7, 1, cli_parse_prend, cli_prend },
    {"pose", 7, 1, cli_parse_pose, cli_pose },
    {"expulse", 7, 0, cli_parse_expulse, cli_expulse },
    {"broadcast", 7, 1, cli_parse_broadcast, cli_broadcast  },
    {"incantation", 300, 0, cli_parse_incantation, cli_incantation },
    {"fork", 42, 0, cli_parse_fork, cli_fork_player },
    {"connect_nbr", 0, 0, cli_parse_connect_nbr, cli_connect_nbr },
    {NULL, 0, 0, NULL, NULL }
  };

t_request		*cli_request_parse(t_server *s, t_user_player *user,
					   t_world *w)
{
  t_request		*request;
  int			i;

  if ((request = cli_request_init()) != NULL)
    {
      i = 0;
      while (g_cli_commands[i].cmd)
        {
	  if (strncmp(g_cli_commands[i].cmd, user->request,
		      strlen(g_cli_commands[i].cmd)) == 0)
	    {
	      request->type = &g_cli_commands[i];
	      return (cli_request_fill(request, user, s, w));
	    }
	  ++i;
        }
      free(request);
    }
  return (NULL);
}

void			cli_requests_process(t_server *s, t_world *w)
{
  t_item		*current;
  t_item		*next;

  current = list_get_head(s->request_list);
  while (current != NULL)
    {
      next = current->next;
      if (T_REQUEST(current)->type->func != NULL
	  && T_REQUEST(current)->data != NULL
	  && s->tick >= T_REQUEST(current)->tick)
        {
	  T_REQUEST(current)->type->func(T_REQUEST(current)->data, s, w);
	  log_show("cli_requests_process", "",
		   "Request '%s' implemented on %dth tick",
		   T_REQUEST(current)->data->message, s->tick);
	  --(T_REQUEST(current)->data->user->request_counter);
	  free(T_REQUEST(current)->data->message);
	  s->diff = 1;
	  item_delete(s->request_list, current);
        }
      current = next;
    }
}
