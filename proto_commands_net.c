/*
** proto_commands_net.c for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Thu Jun 13 16:31:20 2013 Marin Alcaraz
** Last update Mon Jul 08 16:16:35 2013 Marin Alcaraz
*/

#include        "main.h"
#include        "list.h"
#include        "options.h"
#include        "trantor.h"
#include        "server.h"
#include        "users.h"
#include        "request.h"
#include        "answer.h"
#include        "proto_commands_net.h"
#include        "proto_commands_movement.h"

static t_steps 	g_steps[]=
{
	{0, -1},
	{-1, -1},
	{-1, 0},
	{-1, 1},
	{0, 1},
	{1, 1},
	{1, 0},
	{1, -1}
};

void        cli_expulse(t_request_data *rqd, t_server *s, t_world *w)
{
    int     new_position_x;
    int     new_position_y;
    int     current_dir;

    current_dir = rqd->user->direction;
    new_position_x = _MOD(rqd->user->posx + g_steps[current_dir].x, w->width);
    new_position_y = _MOD(rqd->user->posy + g_steps[current_dir].y, w->height);
    expulse_square(new_position_x, new_position_y, rqd, w);
    cli_answer(rqd->user,s , "ok\n");
}

void    cli_incantation(t_request_data *rqd, t_server *s, t_world *w)
{
    (void) (w);
    printf("incantation\n");
    cli_answer(rqd->user, s, "ok\n");
}

void    cli_fork_player(t_request_data *rqd, t_server *s, t_world *w)
{
    (void) (w);
    (void) (s);
    (void) (rqd);
    printf("fork_player\n");
}

void        cli_connect_nbr(t_request_data *rqd, t_server *s, t_world *w)
{
    char    answer[256];

    (void) (w);
    sprintf(answer, "%u\n", (s->players_slots - rqd->user->team->members));
    cli_answer(rqd->user, s, answer);
}

void    cli_death(t_request_data *rqd, t_server *t, t_world *w)
{
    (void) (w);
    (void) (t);
    (void) (rqd);
    printf("death\n");
}
