/*
** proto_commands_movement.c for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Thu Jun 13 16:26:19 2013 Marin Alcaraz
** Last update Thu Jul 04 10:23:09 2013 Marin Alcaraz
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
    int     new_position_x;
    int     new_position_y;

    //item_delete(w->surface[rqd->user->posy][rqd->user->posx].players, rqd->user);
    new_position_x = (rqd->user->posx + g_steps[rqd->user->direction].x);
    new_position_y = (rqd->user->posy + g_steps[rqd->user->direction].y);
    if (new_position_x > w->width)
        new_position_x = new_position_x % w->width;
    if (new_position_y > w->height)
        new_position_y = new_position_y % w->height;
	rqd->user->posx = new_position_x;
	rqd->user->posy = new_position_y;
    item_pf(w->surface[rqd->user->posy][rqd->user->posx].players, rqd->user, sizeof(t_user));
    cli_answer(rqd->user, t, "OK\n");
}

void        cli_droite(t_request_data *rqd, t_server *t, t_world *w)
{
    (void)  (w);

	if (rqd->user->direction == TOP)
        rqd->user->direction = MID_RIGHT;
	else if (rqd->user->direction == MID_RIGHT)
        rqd->user->direction = BOT_MID;
	else if (rqd->user->direction == BOT_MID)
        rqd->user->direction = MID_LEFT;
	else if (rqd->user->direction == MID_LEFT)
        rqd->user->direction = TOP;
	else if (rqd->user->direction == TOP_RIGHT)
        rqd->user->direction = BOT_RIGHT;
	else if (rqd->user->direction == BOT_RIGHT)
        rqd->user->direction = BOT_LEFT;
	else if (rqd->user->direction == BOT_LEFT)
        rqd->user->direction = TOP_LEFT;
	else if (rqd->user->direction == TOP_LEFT)
        rqd->user->direction = TOP_RIGHT;
    cli_answer(rqd->user, t, "OK\n");
}

void        cli_gauche(t_request_data *rqd, t_server *t, t_world *w)
{
    (void) (w);

	if (rqd->user->direction == TOP)
        rqd->user->direction = MID_LEFT;
	else if (rqd->user->direction == MID_RIGHT)
        rqd->user->direction = TOP;
	else if (rqd->user->direction == BOT_MID)
        rqd->user->direction = MID_RIGHT;
	else if (rqd->user->direction == MID_LEFT)
        rqd->user->direction = BOT_MID;
	else if (rqd->user->direction == TOP_RIGHT)
        rqd->user->direction = TOP_LEFT;
	else if (rqd->user->direction == BOT_RIGHT)
        rqd->user->direction = TOP_RIGHT;
	else if (rqd->user->direction == BOT_LEFT)
        rqd->user->direction = BOT_RIGHT;
	else if (rqd->user->direction == TOP_LEFT)
        rqd->user->direction = BOT_LEFT;
    cli_answer(rqd->user, t, "OK\n");
}

void        cli_broadcast(t_request_data *rqd, t_server *t, t_world *w)
{
    (void)  w;
    t_item  *current_item;

    current_item = t->client_list->head;
    while (current_item != NULL)
    {
        if ((T_USER(current_item->cont)->protocol == CLI_PROTO)
            && T_USER(current_item->cont) != rqd->user)
            broadcast_to(T_USER(current_item->cont), rqd, t);
        current_item = current_item->next;
    }
    cli_answer(rqd->user, t, "OK\n");
}

void    cli_voir(t_request_data *rqd, t_server *t, t_world *w)
{
    (void) (w);
    (void) (t);
    (void) (rqd);
    printf("voir\n");
}
