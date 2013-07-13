/*
** graph_command_server.c for zappy in /home/ignati_i//zappy/zappy
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Sat Jul 13 19:39:34 2013 ivan ignatiev
** Last update Sat Jul 13 19:40:00 2013 ivan ignatiev
*/

#include	"main.h"
#include	"list.h"
#include	"options.h"
#include	"trantor.h"
#include	"server.h"
#include	"users.h"
#include	"graph_command.h"
#include	"answer.h"
#include	"error.h"

int		graph_command_sgt(t_graph_data *rqd,
				  t_server *s, t_world *w)
{
  char		response[STR_LIMIT];

  (void) rqd;
  (void) w;
  sprintf(response, "sgt %u\n", s->options.tdelay);
  cli_answer_to_graph(rqd->user, response);
  return (0);
}

int		graph_command_sst(t_graph_data *rqd,
				  t_server *s, t_world *w)
{
  unsigned int	tmp_time;
  char		response[STR_LIMIT];

  (void) w;
  sscanf(rqd->message, "sst %u\n", &tmp_time);
  if (tmp_time <= 100 && tmp_time >= 1)
    s->options.tdelay = tmp_time;
  else
    return (cli_answer_to_graph(rqd->user, "sbp\n"));
  s->tick_size = 1000000 / s->options.tdelay;
  sprintf(response, "sgt %u\n", s->options.tdelay);
  cli_answer_to_graph(rqd->user, response);
  return (0);
}

int		graph_command_display(t_graph_data *rqd,
				      t_server *s, t_world *w)
{
  (void) rqd;
  (void) s;
  display_world(w, w->width, w->height);
  return (0);
}
