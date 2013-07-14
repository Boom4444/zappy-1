/*
** cli_command_parse_net.c for zappy in /home/ignati_i//zappy/zappy
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Sat Jul 13 18:20:10 2013 ivan ignatiev
** Last update Sun Jul 14 18:56:37 2013 ivan ignatiev
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
#include	"incantation.h"

t_request_data		*cli_parse_incantation(t_request_type *type,
					       t_user_player *u,
					       t_server *s, t_world *w)
{
  t_request_data	*rqd;

  (void) s;
  (void) type;
  if ((rqd = cli_request_data_init(u->request, 1)) != NULL)
    {
      rqd->user = u;
      rqd->argv[0] = list_init();
      if (init_incantation(rqd->argv[0], rqd, s, w) != 0)
        {
	  fail_incantation(rqd, s);
	  rqd->argv[0] = list_delete(rqd->argv[0]);
        }
    }
    return (rqd);
}

t_request_data		*cli_parse_fork(t_request_type *type,
					t_user_player *u,
					t_server *s, t_world *w)
{
  t_request_data	*rqd;
  char			response[ANSWER_SIZE];

  (void) s;
  (void) w;
  if ((rqd = cli_request_data_init(u->request, type->argc)) != NULL)
    {
      rqd->user = u;
      sprintf(response, "pfk %d\n", u->number);
      cli_answer_to_all_graph(s, response);
    }
  return (rqd);
}

t_request_data		*cli_parse_connect_nbr(t_request_type *type,
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
