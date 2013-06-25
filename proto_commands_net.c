/*
** proto_commands_net.c for zappy in /home/ignatiev/Projects/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Thu Jun 13 16:31:20 2013 Marin Alcaraz
** Last update Thu Jun 20 19:19:10 2013 ivan ignatiev
*/

#include "proto_commands_net.h"

void    cli_expulse(t_request_data *rqd, t_server *t, t_world *w)
{
    (void) (w);
    (void) (t);
    (void) (rqd);
    printf("expulse\n");
    server_send(rqd->user, "OK\n");
}

void    cli_incantation(t_request_data *rqd, t_server *t, t_world *w)
{
    (void) (w);
    (void) (t);
    (void) (rqd);
    printf("incantation\n");
    server_send(rqd->user, "OK\n");
}

void    cli_fork_player(t_request_data *rqd, t_server *s, t_world *w)
{
    (void) (w);
    (void) (s);
    (void) (rqd);
    printf("fork_player\n");
    server_send(rqd->user, "OK\n");
}

void    cli_connect_nbr(t_request_data *rqd, t_server *t, t_world *w)
{
    (void) (w);
    (void) (t);
    (void) (rqd);
    printf("connect_nbr\n");
    server_send(rqd->user, "OK\n");
}

void    cli_death(t_request_data *rqd, t_server *t, t_world *w)
{
    (void) (w);
    (void) (t);
    (void) (rqd);
    printf("death\n");
    server_send(rqd->user, "OK\n");
}
