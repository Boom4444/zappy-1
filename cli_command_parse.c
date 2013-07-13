/*
** cli_command_parse.c for zappy in /home/hero/zappy
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Thu Jun 13 17:27:55 2013 ivan ignatiev
** Last update Sat Jul 13 18:22:49 2013 ivan ignatiev
*/

#include	"main.h"
#include	"list.h"
#include	"options.h"
#include	"trantor.h"
#include	"server.h"
#include	"users.h"
#include	"proto.h"
#include	"request.h"
#include	"cli_command_parse.h"
#include	"answer.h"

t_request_data		*cli_parse_avance(t_request_type *type,
					  t_user_player *u,
					  t_server *s, t_world *w)
{
  t_request_data	*rqd;

  (void) s;
  (void) w;
  if ((rqd = cli_request_data_init(u->request, type->argc)) != NULL)
    {
      rqd->user = u;
    }
  return (rqd);
}

t_request_data		*cli_parse_droite(t_request_type *type,
					  t_user_player *u,
					  t_server *s, t_world *w)
{
  t_request_data	*rqd;

  (void) s;
  (void) w;
  if ((rqd = cli_request_data_init(u->request, type->argc)) != NULL)
    {
      rqd->user = u;
    }
  return (rqd);
}

t_request_data		*cli_parse_gauche(t_request_type *type,
					  t_user_player *u,
					  t_server *s, t_world *w)
{
  t_request_data	*rqd;

  (void) s;
  (void) w;
  if ((rqd = cli_request_data_init(u->request, type->argc)) != NULL)
    {
        rqd->user = u;
    }
  return (rqd);
}

t_request_data		*cli_parse_expulse(t_request_type *type,
					   t_user_player *u,
					   t_server *s, t_world *w)
{
  t_request_data	*rqd;

  (void) s;
  (void) w;
  if ((rqd = cli_request_data_init(u->request, type->argc)) != NULL)
    {
      rqd->user = u;
    }
  return (rqd);
}

t_request_data		*cli_parse_broadcast(t_request_type *type,
					     t_user_player *u,
					     t_server *s, t_world *w)
{
  t_request_data	*rqd;
  char			*text;

  (void) s;
  (void) w;
  if ((rqd = cli_request_data_init(u->request, type->argc)) != NULL)
    {
      rqd->user = u;
      if ((text = (char*)malloc(sizeof(char)
				* (strlen(u->request) - 9))) != NULL)
        {
	  *text = 0;
	  sscanf(u->request, "broadcast %s\n", text);
	  rqd->argv[0] = (void*)text;
	  return (rqd);
        }
      free(rqd);
      rqd = NULL;
    }
  return (rqd);
}
