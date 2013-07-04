/*
** proto_commands_net.c for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Thu Jun 13 16:31:20 2013 Marin Alcaraz
** Last update Thu Jul 04 10:41:09 2013 Marin Alcaraz
*/

#include        "users.h"
#include        "server.h"
#include        "answer.h"
#include        "proto_commands_net.h"
#include        "proto_commands_movement.h"

static t_steps 	g_steps[]=
{
	{0, 1},
	{-1, 1},
	{-1, 0},
	{-1, -1},
	{0, -1},
	{1, -1},
	{1, 0},
	{1, 1}
};

void        cli_expulse(t_request_data *rqd, t_server *s, t_world *w)
{
    int     new_position_x;
    int     new_position_y;
    int     current_dir;

    current_dir = rqd->user->direction;
    new_position_x = rqd->user->posx + g_steps[current_dir].x;
    new_position_y = rqd->user->posy + g_steps[current_dir].y;
    if (new_position_x > w->width)
        new_position_x = new_position_x % w->width;
    if (new_position_y > w->height)
        new_position_y = new_position_y % w->height;
    expulse_square(new_position_x, new_position_y, rqd, w);
    cli_answer(rqd->user,s , "OK\n");
}

void    cli_incantation(t_request_data *rqd, t_server *s, t_world *w)
{
    (void) (w);
    printf("incantation\n");
    cli_answer(rqd->user, s, "OK\n");
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
