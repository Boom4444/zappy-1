/*
** proto_commands_movement.c for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Thu Jun 13 16:26:19 2013 Marin Alcaraz
** Last update Thu Jun 13 19:07:17 2013 Marin Alcaraz
*/

#include "proto_commands_movement.h"
#include "answer.h"

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

void    		cli_avance(t_request_data *rqd, t_server *t, t_world *w)
{
	
	(void) w;
	rqd->user->posx += g_steps[rqd->user->direction].x; 
	rqd->user->posy += g_steps[rqd->user->direction].y; 
    cli_answer(rqd->user, t, "OK\n");
}

void    cli_droite(t_request_data *rqd, t_server *t, t_world *w)
{
    (void) (w);
    (void) (t);
    (void) (rqd);
    printf("droite\n");
}

void    cli_gauche(t_request_data *rqd, t_server *t, t_world *w)
{
    (void) (w);
    (void) (t);
    (void) (rqd);
    printf("gauche\n");
}

void    cli_broadcast(t_request_data *rqd, t_server *t, t_world *w)
{
    (void) (w);
    (void) (t);
    (void) (rqd);
    printf("broadcast\n");
}

void    cli_voir(t_request_data *rqd, t_server *t, t_world *w)
{
    (void) (w);
    (void) (t);
    (void) (rqd);
    printf("voir\n");
}
