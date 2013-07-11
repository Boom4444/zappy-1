/*
** incantation.c for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Wed Jul 10 09:57:57 2013 Marin Alcaraz
** Last update Wed Jul 10 13:37:14 2013 Marin Alcaraz
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
#include        "item.h"
#include        "error.h"

int         g_level_combinations[7][7] =
{
    {1, 1, 0, 0, 0, 0, 0},
    {2, 1, 1, 1, 0, 0, 0},
    {2, 2, 0, 1, 0, 2, 0},
    {4, 1, 1, 2, 0, 1, 0},
    {4, 1, 2, 1, 3, 0, 0},
    {6, 1, 2, 3, 0, 1, 0},
    {6, 2, 2, 2, 2, 2, 1}
};

int         count_players(t_list *players, t_user_player *player)
{
    int     eq_players;
    t_item  *tmp_item;

    eq_players = 0;
    tmp_item = players->head;
    while (tmp_item != NULL)
    {
        if (T_PLAYER(tmp_item->cont)->level == player->level)
            eq_players = eq_players + 1;
        tmp_item = tmp_item->next;
    }
    return (eq_players);
}

void        level_up(t_list *players, int level)
{
    t_item  *tmp_item;

    tmp_item = players->head;
    while (tmp_item != NULL)
    {
        if (T_PLAYER(tmp_item->cont)->level == level)
            T_PLAYER(tmp_item->cont)->level++;
        tmp_item = tmp_item->next;
    }
}

int         init_incantation(t_request_data *rqd, t_server *s, t_world *w)
{
    int     i;

    i = 0;
    t_item  *tmp_item;
    char    response[ANSWER_SIZE];
    char    aux_level[ANSWER_SIZE];

    tmp_item = w->surface[rqd->user->posy][rqd->user->posx].players->head;
    sprintf(response, "pic %d %d %d %d", rqd->user->posx, rqd->user->posy,
            rqd->user->level, rqd->user->number);
    while (tmp_item != NULL)
    {
        if (T_PLAYER(tmp_item->cont)->level == rqd->user->level)
        {
            sprintf(aux_level, " %d", T_PLAYER(tmp_item->cont)->number);
            sprintf(rqd->argv[0], " %d", T_PLAYER(tmp_item->cont)->number);
            sprintf(rqd->argv[i], "plv %d %d\n",
                        T_PLAYER(tmp_item->cont)->number,
                        T_PLAYER(tmp_item->cont)->level);
            strcat(response, aux_level);
            i = i + 1;
        }
        tmp_item = tmp_item->next;
    }
    strcat(response, " \n");
    cli_answer_to_all_graph(s, response);
    return (0);
}

int         end_incantation(int stat, t_request_data *rqd,
                t_server *s, t_world *w)
{
    char    response[ANSWER_SIZE];
    int     i;

    i = 1;
    sprintf(response, "pie %d %d %d\n", rqd->user->posx,
                rqd->user->posy, stat);
    cli_answer_to_all_graph(s, response);
    while (rqd->argv[i] != NULL)
    {
        cli_answer_to_all_graph(s, rqd->argv[i]);
        i = i + 1;
    }
    response[0] = '\0';
    cli_command_bct(response, rqd->user->posx, rqd->user->posy, w);
    cli_answer_to_all_graph(s, response);

}

int         incantate(t_user_player *p, t_server *t, t_world *w)
{
    int     i;
    int     eq_players;

    i = 1;
    eq_players = count_players(w->surface[p->posy][p->posx].players, p);
    if (eq_players >= g_level_combinations[p->level - 1][0])
        {
            while (i < RES_TYPES_COUNT)
            {
                if (w->surface[p->posy][p->posx].resources[i] <
                        g_level_combinations[p->level - 1][i])
                {
                    return (error_show("incantate", "",
                                "Not enough resources to begin the incantation"));
                }
                w->surface[p->posy][p->posx].resources[i]--;
                i = i + 1;
            }
            level_up(w->surface[p->posy][p->posx].players, p->level);
        }
    else
        return (error_show("incantate", "",
                    "Not enough players to begin the incantation"));
    cli_answer(p, t, "ok\n");
    return (0);
}
