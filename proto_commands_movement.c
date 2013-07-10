/*
** proto_commands_movement.c for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Thu Jun 13 16:26:19 2013 Marin Alcaraz
** Last update Wed Jul 10 09:16:20 2013 Marin Alcaraz
*/

#include        "main.h"
#include        "list.h"
#include        "options.h"
#include        "trantor.h"
#include        "server.h"
#include        "users.h"
#include        "request.h"
#include        "answer.h"
#include        "item.h"
#include        "proto_commands_movement.h"

static t_steps 	g_steps[]=
{
	{0, -1},
	{1, 0},
	{0, 1},
	{-1, 0}
};

static char     *g_objects[] = {
    "food",
    "linemate",
    "deraumere",
    "sibur",
    "mendiane",
    "phiras",
    "thystame"
};

void    	cli_avance(t_request_data *rqd, t_server *t, t_world *w)
{
    char 	response[251];

    item_delete_by_content(w->surface[rqd->user->posy][rqd->user->posx].players, (void*)rqd->user);
    rqd->user->posx = _MOD(rqd->user->posx + g_steps[rqd->user->orientation].x, w->width);
    rqd->user->posy = _MOD(rqd->user->posy + g_steps[rqd->user->orientation].y, w->height);
    item_pb(w->surface[rqd->user->posy][rqd->user->posx].players, (void*)rqd->user, sizeof(t_user));
    cli_answer(rqd->user, t, "ok\n");
    sprintf(response, "ppo %d %d %d %d\n", rqd->user->number, rqd->user->posx, rqd->user->posy, rqd->user->orientation + 1);
    cli_answer_to_all_graph(t, response);
}

void        cli_droite(t_request_data *rqd, t_server *t, t_world *w)
{
    (void)  (w);
    char 	response[251];

    rqd->user->orientation = _MOD(rqd->user->orientation + 1, 4);
    cli_answer(rqd->user, t, "ok\n");
    sprintf(response, "ppo %d %d %d %d\n", rqd->user->number, rqd->user->posx, rqd->user->posy, rqd->user->orientation + 1);
    cli_answer_to_all_graph(t, response);
}

void        cli_gauche(t_request_data *rqd, t_server *t, t_world *w)
{
    (void) (w);
    char 	response[251];

    rqd->user->orientation = _MOD(rqd->user->orientation - 1, 4);
    cli_answer(rqd->user, t, "ok\n");
    sprintf(response, "ppo %d %d %d %d\n", rqd->user->number, rqd->user->posx, rqd->user->posy, rqd->user->orientation + 1);
    cli_answer_to_all_graph(t, response);
}

void        cli_broadcast(t_request_data *rqd, t_server *t, t_world *w)
{
    (void)  w;
    t_item  *current_item;
    char    response[ANSWER_SIZE];
    int     direction;

    current_item = t->client_list->head;
    while (current_item != NULL)
    {
        if ((T_PLAYER(current_item->cont)->protocol == CLI_PROTO)
            && T_PLAYER(current_item->cont) != rqd->user)
        {
            direction = broadcast_to(T_PLAYER(current_item->cont), rqd, t);
            sprintf(response, "broadcast %d, %s",
                    direction, (char *)rqd->argv[0]);
            cli_answer(rqd->user, t, response);
            response[0] = '\0';
        }
        current_item = current_item->next;
    }
    response[0] = '\0';
    sprintf(response, "pbc %d %s\n", rqd->user->number,
            (char *)rqd->argv[0]);
    cli_answer_to_all_graph(t, response);
}

void        cli_voir_players(char *answer, t_list *players)
{
    t_item  *current;

    current = players->head;
    while (current != NULL)
    {
        strcat(answer, " player");
        current = current->next;
    }
}

void        cli_voir_resources(char *answer, int *resources)
{
    int     i;
    int     j;

    i = 0;
    while (i < RES_TYPES_COUNT)
    {
        j = 0;
        while (j < resources[i])
        {
            strcat(answer, " ");
            strcat(answer, g_objects[i]);
            j = j + 1;
        }
        i = i + 1;
    }
    strcat(answer, ",");
}

void        cli_voir(t_request_data *rqd, t_server *s, t_world *w)
{
    int     level;
    int     level_count;
    int     obj_x;
    int     obj_y;
    int     x;
    int     y;
    int     i;
    char    answer[2048];

    level = 0;
    x = rqd->user->posx;
    y = rqd->user->posy;
    strcpy(answer, "{");
    level_count = 1;
    while (level < rqd->user->level)
    {
        obj_x = x;
        obj_y = y;
        i = 0;
        while (i < level_count)
        {
            cli_voir_players(answer, w->surface[obj_y][obj_x].players);
            cli_voir_resources(answer, w->surface[obj_y][obj_x].resources);
            obj_x = _MOD(obj_x + g_steps[_MOD(rqd->user->orientation - 2, 8)].x, w->width);
            obj_y = _MOD(obj_y + g_steps[_MOD(rqd->user->orientation - 2, 8)].y, w->height);
            ++i;
        }
        x = _MOD(x + g_steps[_MOD(rqd->user->orientation + 1, 8)].x, w->width);
        y = _MOD(y + g_steps[_MOD(rqd->user->orientation + 1, 8)].y, w->height);
        level_count += 2;
        ++level;
    }
    strcat(answer, "}\n");
    cli_answer(rqd->user, s, answer);
}
