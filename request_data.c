/*
** request_data.c for zappy in /home/ignati_i//zappy/zappy
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Sat Jul 13 20:04:36 2013 ivan ignatiev
** Last update Sat Jul 13 20:07:09 2013 ivan ignatiev
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

t_request_data		*cli_request_data_init(char *message,
					       unsigned int argc)
{
  t_request_data	*rqd;

  if ((rqd = (t_request_data*)malloc(sizeof(t_request_data))) != NULL)
    {
      rqd->message = message;
      rqd->argv = NULL;
      if (argc > 0
	  && (rqd->argv = (void**) malloc(sizeof(void*) * argc)) == NULL)
        {
	  free(rqd);
	  return (NULL);
        }
      return (rqd);
    }
  error_show("cli_request_data_init", "malloc",
	     "Unable allocate memory for requesti data");
  return (rqd);
}

t_request_type		*cli_request_type_init(void)
{
  t_request_type	*type;

  if ((type = (t_request_type*)malloc(sizeof(t_request_type))) != NULL)
    return (type);
  error_show("cli_request_type_init", "malloc",
	     "Unable allocate memory for requesti type");
  return (NULL);
}

t_request		*cli_request_init(void)
{
  t_request		*request;

  if ((request = (t_request*)malloc(sizeof(t_request))) != NULL)
    return (request);
  error_show("cli_request_init", "malloc",
	     "Unable allocate memory for request");
  return (NULL);
}

t_request		*cli_request_fill(t_request *request, t_user_player *user,
					  t_server *s, t_world *w)
{
  request->tick = (user->tick > s->tick ? user->tick : s->tick)
    + request->type->delay;
  if (request->type->parse != NULL
      && (request->data = request->type->parse(request->type,
					       user, s, w)) != NULL)
    log_show("cli_parse", "", "Request '%s' for player %d accepted "
	     "on the %lluth tick, plan : %llu",
	     request->data->message, user->number,
	     s->tick, request->tick);
  else
    request->data = NULL;
  user->tick = request->tick;
  return (request);
}
