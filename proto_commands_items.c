/*
** proto_commands_items.c for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Thu Jun 13 16:28:40 2013 Marin Alcaraz
** Last update Tue Jul 09 12:42:38 2013 Marin Alcaraz
*/

#include "main.h"
#include "list.h"
#include "options.h"
#include "trantor.h"
#include "server.h"
#include "users.h"
#include "request.h"
#include "proto_commands_items.h"
#include "answer.h"
#include "error.h"
#include "graph_command.h"

void        cli_inventaire(t_request_data *rqd, t_server *t, t_world *w)
{
    (void)  (w);
    char    out[256];
    int     *inv;

    inv = (rqd->user)->inventory;
    sprintf(out, "{food %d, linemate %d, deraumere %d, sibur %d"
            ", mendiane %d, phiras %d, thystame %d}\n"
            , inv[0], inv[1], inv[2], inv[3], inv[4],
            inv[5], inv[6]);
    cli_answer(rqd->user, t, out);
}

int             cli_pin(char *response, t_user_player *player)
{
    int         p_number;

    p_number = player->number;
    sscanf(response, "pin %d\n", &(player->number));
    sprintf(response, "pin %d %d %d %d %d %d %d %d %d %d\n",
            p_number, player->posx,
            player->posy,
            player->inventory[0],
            player->inventory[1],
            player->inventory[2],
            player->inventory[3],
            player->inventory[4],
            player->inventory[5],
            player->inventory[6]);
    return (0);
}

int             cli_command_bct(char *response, int x, int y, t_world *w)
{
    int         i;
    char        out[ANSWER_SIZE];

    i = 0;
    sprintf(response, "bct %d %d", x, y);
    while (i < RES_TYPES_COUNT)
    {
        sprintf(out, " %d", w->surface[y][x].resources[i]);
        strcat(response, out);
        i = i + 1;
    }
    strcat(response, "\n");
    return (0);
}

void        cli_prend(t_request_data *rqd, t_server *t, t_world *w)
{
    int     index_item;
    (void) (t);
    char    out[256];

    index_item = atoi(rqd->argv[0]);
    if (index_item < RES_TYPES_COUNT
            && index_item >= 0
            && (w->surface[rqd->user->posy]
                [rqd->user->posx]).resources[index_item] > 0)
    {
        (w->surface[rqd->user->posy]
                [rqd->user->posx]).resources[index_item]--;
        rqd->user->inventory[index_item]++;
        sprintf(out, "pgt %d %d\n", rqd->user->number, index_item);
        cli_answer_to_all_graph(t, out);
        out[0] = '\0';
        cli_pin(out, rqd->user);
        cli_answer_to_all_graph(t, out);
        out[0] = '\0';
        cli_command_bct(out, rqd->user->posx, rqd->user->posy, w);
        cli_answer_to_all_graph(t, out);
        cli_answer(rqd->user, t, "ok\n");
        return ;
    }
    error_show("cli_prend", "", "Invalid mineral requested from player %d", rqd->user->number);
    cli_answer(rqd->user, t, "ko\n");
}

void    cli_pose(t_request_data *rqd, t_server *t, t_world *w)
{
    int     item;
    (void) (t);

    item = (rqd->user)->inventory[atoi(rqd->argv[0])]--;
    (w->surface[rqd->user->posy]
               [rqd->user->posx]).resources[item]++;
    cli_answer(rqd->user, t, "OK\n");
}
