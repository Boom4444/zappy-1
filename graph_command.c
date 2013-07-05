/*
** graph_command.c for zappy in /home/hero/zappy
** 
** Made by Ivan Ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Wed Jun 12 17:02:27 2013 Marin Alcaraz
** Last update Thu Jul 04 19:26:28 2013 Marin Alcaraz
*/

#include        <stdlib.h>
#include        <string.h>
#include        "server.h"
#include        "users.h"
#include        "graph_command.h"

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

int             graph_command_exec(t_user *u, t_server *s, t_world *w,
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
    (void) rqd;
    (void) s;
    (void) w;
    return (0);
}

int             graph_command_bct(t_graph_data *rqd, t_server *s, t_world *w)
{
    (void) rqd;
    (void) s;
    (void) w;
    return (0);
}

int             graph_command_mct(t_graph_data *rqd, t_server *s, t_world *w)
{
    (void) rqd;
    (void) s;
    (void) w;
    return (0);
}

int             graph_command_tna(t_graph_data *rqd, t_server *s, t_world *w)
{
    (void) rqd;
    (void) s;
    (void) w;
    return (0);
}

int             graph_command_ppo(t_graph_data *rqd, t_server *s, t_world *w)
{
    (void) rqd;
    (void) s;
    (void) w;
    return (0);
}

int             graph_command_piv(t_graph_data *rqd, t_server *s, t_world *w)
{
    (void) rqd;
    (void) s;
    (void) w;
    return (0);
}

int             graph_command_pin(t_graph_data *rqd, t_server *s, t_world *w)
{
    (void) rqd;
    (void) s;
    (void) w;
    return (0);
}

int             graph_command_sgt(t_graph_data *rqd, t_server *s, t_world *w)
{
    (void) rqd;
    (void) s;
    (void) w;
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
