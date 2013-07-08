/*
** graph_command.c for zappy in /home/hero/zappy
** 
** Made by Ivan Ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Wed Jun 12 17:02:27 2013 Marin Alcaraz
** Last update Mon Jul 08 13:38:53 2013 Marin Alcaraz
*/

#include        "main.h"
#include        "list.h"
#include        "options.h"
#include        "trantor.h"
#include        "server.h"
#include        "users.h"
#include        "graph_command.h"
#include        "answer.h"
#include        "error.h"

static t_graph_command  graph_cmd[] = {
    {"msz", graph_command_msz},
    {"bct X Y", graph_command_bct},
    {"mct", graph_command_mct},
    {"tna", graph_command_tna},
    {"ppo #n", graph_command_ppo},
    {"piv #n", graph_command_piv},
    {"pin #n", graph_command_pin},
    {"sgt", graph_command_sgt},
    {"sst T", graph_command_sst},
    {"show", graph_command_display},
    {NULL, NULL}
};

int             graph_command_exec(t_user_graph *u, t_server *s, t_world *w,
                                        char *message)
{
    int         i;
    t_graph_data rqd;

    i = 0;
    while (graph_cmd[i].cmd)
    {
        if (strncmp(message, graph_cmd[i].cmd, 3) == 0)
        {
            rqd.message = message;
            rqd.user = u;
            graph_cmd[i].func(&rqd, s, w);
        }
        ++i;
    }
    return (0);
}

int             graph_command_msz(t_graph_data *rqd, t_server *s, t_world *w)
{
    char        response[STR_LIMIT];
    (void)      rqd;
    (void)      s;

    sprintf(response, "msz %d %d\n", w->width, w->height);
    printf("Response: %s", response);
    cli_answer_to_graph(rqd->user, response);
    return (0);
}

int             graph_command_bct(t_graph_data *rqd, t_server *s, t_world *w)
{
    (void)      s;
    int         i;
    int         x;
    int         y;
    char        response[STR_LIMIT];

    i = 0;
    sscanf(rqd->message, "bct %d %d\n", &x, &y);
    while (i < 7)
    {
        if  ((w->surface[y][x]).resources[i] != 0)
                sprintf(response, "%s %d ", response, i);
        i = i + 1;
    }
    sprintf(response, "%s/n", response);
    printf("Response: %s", response);
    cli_answer_to_graph(rqd->user, response);
    return (0);
}

int             graph_command_mct(t_graph_data *rqd, t_server *s, t_world *w)
{
  int         i;
  int         j;
  int         min;
  char        *response;
  char        bct_line[STR_LIMIT];
  (void)      s;

  j = 0;
  if ((response  = malloc(STR_LIMIT * w->width)) == NULL)
    return (error_show("graph", "command_mct", "Unable to alloc resp"));
  while (j < w->height)
  {
    i = 0;
    while (i < w->width)
    {

      sprintf(response, "bct %d %d ", i, j);
      min = 0;
      while (min < 7)
      {
        sprintf(bct_line, "%d ", w->surface[j][i].resources[min++]);
        strcat(response, bct_line);
      }
      i = i + 1;
      strcat(response, "\n");
      cli_answer_to_graph(rqd->user, response);
    }
    j = j + 1;
    printf("Response: %s", response);
    response[0] = '\0';
  }
  free(response);
  return (0);
}

int             graph_command_tna(t_graph_data *rqd, t_server *s, t_world *w)
{
    (void)      w;
    (void)      rqd;
    char        response[STR_LIMIT];
    t_item      *current_team;

    current_team = s->options.names->head;
    while (current_team != NULL)
    {
        sprintf(response, "tna %s\n", (char *)(current_team->cont));
        printf("Response: %s", response);
        cli_answer_to_graph(rqd->user, response);
        current_team = current_team->next;
        response[0] = '\0';
    }
    return (0);
}

int             graph_command_ppo(t_graph_data *rqd, t_server *s, t_world *w)
{
    (void)      w;
    char        response[STR_LIMIT];
    t_item      *current_player;
    int         p_number;

    sscanf(rqd->message, "ppo %d\n", &p_number);
    current_player = s->client_list->head;
    while (current_player != NULL)
    {
        if (T_PLAYER(current_player->cont)->number == p_number)
        {
            sprintf(response, "ppo %d %d %d %d\n", p_number,
                    T_PLAYER(current_player->cont)->posx, T_PLAYER(current_player->cont)->posy,
                    T_PLAYER(current_player->cont)->direction);
            printf("Response: %s", response);
            cli_answer_to_graph(rqd->user, response);
            return (0);
        }
        current_player = current_player->next;
    }
    return (0);
}

int             graph_command_piv(t_graph_data *rqd, t_server *s, t_world *w)
{
    (void)      w;
    char        response[STR_LIMIT];
    t_item      *current_player;
    int         p_number;

    sscanf(rqd->message, "piv %d\n", &p_number);
    current_player = s->client_list->head;
    while (current_player != NULL)
    {
        if (T_PLAYER(current_player->cont)->number == p_number)
        {
            sprintf(response, "piv %d %d\n", p_number,
                    T_PLAYER(current_player->cont)->level);
            printf("Response: %s", response);
            cli_answer_to_graph(rqd->user, response);
            return (0);
        }
        current_player = current_player->next;
    }
    return (0);
}

int             graph_command_pin(t_graph_data *rqd, t_server *s, t_world *w)
{
    (void)      w;
    char        response[STR_LIMIT];
    t_item      *current_player;
    int         p_number;

    sscanf(rqd->message, "piv %d\n", &p_number);
    current_player = s->client_list->head;
    while (current_player != NULL)
    {
        if (T_PLAYER(current_player->cont)->number == p_number)
        {
            sprintf(response, "ppo %d %d %d %d %d %d %d %d %d %d\n",
            p_number, T_PLAYER(current_player->cont)->posx,
            T_PLAYER(current_player->cont)->posy,
            T_PLAYER(current_player->cont)->inventory[0],
            T_PLAYER(current_player->cont)->inventory[1],
            T_PLAYER(current_player->cont)->inventory[2],
            T_PLAYER(current_player->cont)->inventory[3],
            T_PLAYER(current_player->cont)->inventory[4],
            T_PLAYER(current_player->cont)->inventory[5],
            T_PLAYER(current_player->cont)->inventory[6]);
            printf("Response: %s", response);
            cli_answer_to_graph(rqd->user, response);
            return (0);
        }
        current_player = current_player->next;
    }
    return (0);
}

int             graph_command_sgt(t_graph_data *rqd, t_server *s, t_world *w)
{
    (void) 		rqd;
    (void) 		w;
	char 		response[STR_LIMIT];

	sprintf(response, "sgt %u\n", s->options.tdelay);
	cli_answer_to_graph(rqd->user, response);
    return (0);
}

int             graph_command_sst(t_graph_data *rqd, t_server *s, t_world *w)
{
    (void) rqd;
    (void) s;
    (void) w;
    return (0);
}

int             graph_command_display(t_graph_data *rqd, t_server *s, t_world *w)
{
    (void) rqd;
    (void) s;
    display_world(w, w->width, w->height);
    return (0);
}

int 			graph_display_users(t_server *s, t_graph_data *rqd)
{
	t_item 	*current;
	char 	response[STR_LIMIT];

	current = s->client_list->head;
	while (current != NULL)
	{
		if (T_USER(current->cont)->protocol == CLI_PROTO)
		{
		sprintf(response, "pnw %d %d %d %d %d %s\n",
				T_PLAYER(current->cont)->number,
				T_PLAYER(current->cont)->posx,
				T_PLAYER(current->cont)->posy,
				T_PLAYER(current->cont)->direction,
				T_PLAYER(current->cont)->level,
				T_PLAYER(current->cont)->team->name);
		cli_answer_to_graph(rqd->user, response);
		}
		current = current->next;
	}
	return (0);
}

int 		graph_client_init(t_user_graph *u, t_server *s, t_world *w)
{
	t_graph_data rqd;

	rqd.user = u;
	graph_command_msz(&rqd, s, w);
	graph_command_sgt(&rqd, s, w);
	graph_command_mct(&rqd, s, w);
	graph_command_tna(&rqd, s, w);
	graph_display_users(s, &rqd);
	/** SEND ENW **/
	return (0);
}
