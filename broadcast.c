/*
** broadcast.c for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Mon Jul 01 14:23:40 2013 Marin Alcaraz
** Last update Mon Jul 01 17:31:22 2013 Marin Alcaraz
*/

#include <math.h>
#include "proto_commands_movement.h"
#include "answer.h"

static double g_offsets[9][2]=
{
	{-1.0, -1.0},
	{0.0, -1.0},
	{1.0, -1.0},
	{-1.0, 0.0},
	{0.0, 0.0},
	{1.0, 1.0},
	{-1.0, 1.0},
	{0.0, 1.0},
	{1.0, 1.0}
};

double  broadcast_get_distance(t_user *u, int x, int y)
{
    return (sqrt(pow((u->posx - x), 2) + pow((u->posy - y), 2)));
}

int         generate_offsets(double offsets[9][3], t_request_data  *rqd, t_user *current, t_server *t)
{
    int     i;
    int     mini;

    i = 0;
    mini = 0;
    while (i < 9)
    {
        offsets[i][0] = (g_offsets[i][0] * t->options.width) + current->posx;
        offsets[i][1] = (g_offsets[i][1] * t->options.height) + current->posy;
        offsets[i][2] = broadcast_get_distance(rqd->user, offsets[i][0], offsets[i][1]);
        printf("%f\n", offsets[i][2]);
        if (offsets[mini][2] > offsets[i][2])
            mini = i;
        i = i + 1;
    }
    return (mini);
}

int             broadcast_to(t_user *user, t_request_data *rqd, t_server *t)
{
    int         mini;
    double      point_data[9][3];

    rqd->user->posx = 5;
    rqd->user->posy = 2;
    user->posx = 2;
    user->posy = 9;
    mini = generate_offsets(point_data, rqd, user, t);
    printf("mini: %d\n", mini);
    return (0);
}
