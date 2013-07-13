/*
** proto_cli.c for zappy in /home/ignati_i//zappy/zappy
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Sat Jul 13 19:55:19 2013 ivan ignatiev
** Last update Sat Jul 13 19:55:23 2013 ivan ignatiev
*/

#include	"main.h"
#include	"list.h"
#include	"item.h"
#include	"options.h"
#include	"trantor.h"
#include	"server.h"
#include	"users.h"
#include	"select.h"
#include	"request.h"
#include	"answer.h"
#include	"cli_command_parse.h"
#include	"graph_command.h"
#include	"proto.h"
#include	"error.h"
#include	"str.h"

int		cli_accept_request(t_user_player *u,
				   t_server *s, t_world *w)
{
  t_request	*request;

  while ((u->request = getnextline(u->request_buf)) != NULL)
    {
      if (u->request_counter > REQUESTS_LIMIT)
	{
	  free(u->request);
	  cli_answer(u, s, "ko\n");
	  error_show("cli_parse", "", "Player %d request limit", u->number);
	}
      if ((request = cli_request_parse(s, u, w)) != NULL)
	{
	  request->data->user->request_counter++;
	  item_pb(s->request_list, (void*)request, sizeof(t_request));
	}
      else
	{
	  free(request);
	  cli_answer(u, s, "ko\n");
	  error_show("cli_parse", "", "Player %d wrong request", u->number);
	}
    }
  return (0);
}

int		cli_parse(t_user_player *u, t_server *s, t_world *w)
{
  int		rb;
  char		buf[PROTO_BUFFER + 1];

  if ((rb = recv(u->clientfd, buf, PROTO_BUFFER, MSG_DONTWAIT)) > 0)
    {
      buf[rb] = '\0';
      if (proto_flud_detect(T_USER(u), buf) < 0)
	return (-1);
      u->request_buf = stralloccat(u->request_buf, buf);
      return (cli_accept_request(u, s, w));
    }
  u->connected = DISCONNECTED;
  return (-1);
}
