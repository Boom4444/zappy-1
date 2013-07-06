/*
** proto_commands_movement.c for zappy in /home/ignatiev/Projects/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Thu Jun 13 16:26:19 2013 Marin Alcaraz
** Last update Sat Jul 06 13:15:52 2013 ivan ignatiev
*/

#include        "main.h"
#include        "list.h"
#include        "options.h"
#include        "trantor.h"
#include        "server.h"
#include        "users.h"
#include        "request.h"
#include        "answer.h"
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

void    		cli_avance(t_request_data *rqd, t_server *t, t_world *w)
{
    item_delete_by_content(w->surface[rqd->user->posy][rqd->user->posx].players, (void*)rqd->user);
    rqd->user->posx = _MOD(rqd->user->posx + g_steps[rqd->user->direction].x, w->width);
    rqd->user->posy = _MOD(rqd->user->posy + g_steps[rqd->user->direction].y, w->height);
    item_pf(w->surface[rqd->user->posy][rqd->user->posx].players, (void*)rqd->user, sizeof(t_user));
    cli_answer(rqd->user, t, "ok\n");
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
        if ((T_PLAYER(current_item->cont)->protocol == CLI_PROTO)
            && T_PLAYER(current_item->cont) != rqd->user)
            broadcast_to(T_PLAYER(current_item->cont), rqd, t);
        current_item = current_item->next;
    }
    cli_answer(rqd->user, t, rqd->argv[0]);
}

void        cli_voir(t_request_data *rqd, t_server *s, t_world *w)
{
    int     level;
    int     x;
    int     y;
    (void) w;
    (void) rqd->user->direction;

    level = 0;
    x = rqd->user->posx;
    y = rqd->user->posy;
    while (level < rqd->user->level)
    {
        x = _MOD(x + g_steps[rqd->user->direction + 1].x, w->width);
        y = _MOD(y + g_steps[rqd->user->direction + 1].y, w->height);
    }
    cli_answer(rqd->user, s, "{}\n");
}
