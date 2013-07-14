/*
** graph_command.c for zappy in /home/hero/zappy
** 
** Made by Ivan Ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Wed Jun 12 17:02:27 2013 Marin Alcaraz
** Last update Sun Jul 14 12:51:22 2013 ivan ignatiev
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

static t_graph_command	g_graph_cmd[] =
  {
    {"msz", graph_command_msz},
    {"bct", graph_command_bct},
    {"mct", graph_command_mct},
    {"tna", graph_command_tna},
    {"ppo", graph_command_ppo},
    {"piv", graph_command_piv},
    {"pin", graph_command_pin},
    {"sgt", graph_command_sgt},
    {"sst", graph_command_sst},
    {"show", graph_command_display},
    {NULL, NULL}
  };

int		graph_command_exec(t_user_graph *u, t_server *s,
				   t_world *w, char *message)
{
  int		i;
  t_graph_data	rqd;

  i = 0;
  while (g_graph_cmd[i].cmd)
    {
      if (strncmp(message, g_graph_cmd[i].cmd, 3) == 0)
        {
	  rqd.message = message;
	  rqd.user = u;
	  g_graph_cmd[i].func(&rqd, s, w);
	  return (0);
        }
      ++i;
    }
  cli_answer_to_graph(u, "suc\n");
  error_show("graph_command_exec", "", "GFX Command not found");
  return (-1);
}

int		graph_command_msz(t_graph_data *rqd, t_server *s, t_world *w)
{
  char		response[STR_LIMIT];

  (void) rqd;
  (void) s;
  sprintf(response, "msz %d %d\n", w->width, w->height);
  cli_answer_to_graph(rqd->user, response);
  return (0);
}

int		graph_command_bct(t_graph_data *rqd,
				  t_server *s, t_world *w)
{
  int		x;
  int		y;
  int       map_info[2];
  char		response[STR_LIMIT];

  (void) s;
  x = -1;
  y = -1;
  sscanf(rqd->message, "bct %d %d\n", &x, &y);
  if (x < 0 || y < 0)
    return (cli_answer_to_graph(rqd->user, "sbp\n"));
  x = _MOD(x, w->width);
  y = _MOD(y, w->height);
  map_info[0] = x;
  map_info[1] = y;
  sprintf(response, "bct %d %d", x, y);
  get_content(map_info, response, w);
  strcat(response, "\n");
  cli_answer_to_graph(rqd->user, response);
  return (0);
}

int		graph_command_mct(t_graph_data *rqd,
				  t_server *s, t_world *w)
{
  char		*response;

  (void) s;
  response = NULL;
  parse_and_answer(response, rqd, w);
  free(response);
  return (0);
}

int		graph_command_tna(t_graph_data *rqd,
				  t_server *s, t_world *w)
{
  char		response[STR_LIMIT];
  t_item	*current_team;

  (void) w;
  (void) rqd;
  current_team = list_get_head(s->options.names);
  while (current_team != NULL)
    {
      sprintf(response, "tna %s\n", (char *)(current_team->cont));
      cli_answer_to_graph(rqd->user, response);
      current_team = current_team->next;
      response[0] = '\0';
    }
  return (0);
}
