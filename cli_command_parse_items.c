/*
** cli_command_parse_items.c for zappy in /home/ignati_i//zappy/zappy
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Sat Jul 13 18:19:07 2013 ivan ignatiev
** Last update Sat Jul 13 18:23:34 2013 ivan ignatiev
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

t_request_data		*cli_parse_voir(t_request_type *type,
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

t_request_data		*cli_parse_inventaire(t_request_type *type,
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

t_request_data		*cli_parse_prend(t_request_type *type,
					 t_user_player *u,
					 t_server *s, t_world *w)
{
  t_request_data	*rqd;
  char			*object;

  (void) s;
  (void) w;
  if ((rqd = cli_request_data_init(u->request, type->argc)) != NULL)
    {
      rqd->user = u;
      if ((object = (char*)malloc(sizeof(char)
				  * (strlen(u->request) - 5))) != NULL)
        {
	  *object = 0;
	  sscanf(u->request, "prend %s\n", object);
	  rqd->argv[0] = (void*)object;
	  return (rqd);
        }
      free(rqd);
      rqd = NULL;
    }
  return (rqd);
}

t_request_data		*cli_parse_pose(t_request_type *type,
					t_user_player *u,
					t_server *s, t_world *w)
{
  t_request_data	*rqd;
  char			*object;

  (void) s;
  (void) w;
  if ((rqd = cli_request_data_init(u->request, type->argc)) != NULL)
    {
        rqd->user = u;
        if ((object = (char*)malloc(sizeof(char)
				    * (strlen(u->request) - 4))) != NULL)
	  {
	    *object = 0;
            sscanf(u->request, "pose %s\n", object);
            rqd->argv[0] = (void*)object;
            return (rqd);
	  }
        free(rqd);
        rqd = NULL;
    }
  return (rqd);
}
