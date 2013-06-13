/*
** proto_commands_items.c for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Thu Jun 13 16:28:40 2013 Marin Alcaraz
** Last update Thu Jun 13 19:11:13 2013 Marin Alcaraz
*/

#include "proto_commands_items.h"

void    cli_inventaire(t_request_data *rqd, t_server *t, t_world *w)
{
    (void) (w);
    (void) (t);
    (void) (rqd);
    printf("inventaire\n");
}

void    cli_prend(t_request_data *rqd, t_server *t, t_world *w)
{
    (void) (w);
    (void) (t);
    (void) (rqd);
    printf("prend\n");
}

void    cli_pose(t_request_data *rqd, t_server *t, t_world *w)
{
    (void) (w);
    (void) (t);
    (void) (rqd);
    printf("pose\n");
}
