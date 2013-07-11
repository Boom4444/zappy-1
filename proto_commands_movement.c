/*
** proto_commands_movement.c for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Thu Jun 13 16:26:19 2013 Marin Alcaraz
** Last update Thu Jul 11 14:11:38 2013 Marin Alcaraz
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
#include        "str.h"

static t_point 	g_steps[]=
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

static t_point 	g_voir[]=
{
	{-1, -1},
	{1, -1},
	{1, 1},
	{-1, 1}
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

    current_item = list_get_head(t->client_list);
    while (current_item != NULL)
    {
        if ((T_PLAYER(current_item->cont)->protocol == CLI_PROTO)
            && T_PLAYER(current_item->cont) != rqd->user)
        {
            direction = broadcast_to(T_PLAYER(current_item->cont), rqd, t);
            sprintf(response, "broadcast %d, %s\n",
                    direction, (char *)rqd->argv[0]);
            cli_answer(T_PLAYER(current_item->cont), t, response);
            response[0] = '\0';
        }
        current_item = current_item->next;
    }
    response[0] = '\0';
    cli_answer(rqd->user, t, "ok\n");
    sprintf(response, "pbc %d %s\n", rqd->user->number,
            (char *)rqd->argv[0]);
    free(rqd->argv[0]);
    free(rqd->argv);
    cli_answer_to_all_graph(t, response);
}

char        *cli_voir_players(char *response, t_list *players)
{
    t_item  *current;

    current = list_get_head(players);
    while (current != NULL)
    {
        response = stralloccat(response, " player");
        current = current->next;
    }
    return (response);
}

char        *cli_voir_resources(char *response, int *resources)
{
    int     i;
    int     j;

    i = 0;
    while (i < RES_TYPES_COUNT)
    {
        j = 0;
        while (j < resources[i])
        {
            response = stralloccat(response, " ");
            response = stralloccat(response, g_objects[i]);
            j++;
        }
        i = i + 1;
    }
    response = stralloccat(response, ",");
    return (response);
}

char        *cli_voir_level(char *response, t_request_data *rqd,  t_world *w)
{
    int     level;
    int     level_count;
    t_point v;
    t_point obj;
    int     i;

    level = 0;
    v.x = rqd->user->posx;
    v.y = rqd->user->posy;
    level_count = 1;
    while (level <= rqd->user->level)
    {
        obj.x = v.x;
        obj.y = v.y;
        i = 0;
        while (i < level_count)
        {
            response = cli_voir_players(response, w->surface[obj.y][obj.x].players);
            response = cli_voir_resources(response, w->surface[obj.y][obj.x].resources);
            obj.x = _MOD(obj.x + g_steps[_MOD(rqd->user->orientation + 1, 4)].x, w->width);
            obj.y = _MOD(obj.y + g_steps[_MOD(rqd->user->orientation + 1, 4)].y, w->height);
            ++i;
        }
        v.x = _MOD(v.x + g_voir[_MOD(rqd->user->orientation, 4)].x, w->width);
        v.y = _MOD(v.y + g_voir[_MOD(rqd->user->orientation, 4)].y, w->height);
        level_count += 2;
        ++(level);
    }
    return (response);
}

void        cli_voir(t_request_data *rqd, t_server *s, t_world *w)
{
   char    *response;

   response = NULL;
   response = stralloccat(response, "{");
   response = cli_voir_level(response, rqd, w);
   response = stralloccat(response, "}\n");
   if (response != NULL)
   {
       cli_answer(rqd->user, s, response);
       free(response);
   }
   else
       cli_answer(rqd->user, s, "ko\n");
}
