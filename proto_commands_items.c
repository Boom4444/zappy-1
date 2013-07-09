/*
** proto_commands_items.c for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Thu Jun 13 16:28:40 2013 Marin Alcaraz
** Last update Tue Jul 09 09:43:25 2013 Marin Alcaraz
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

void        cli_prend(t_request_data *rqd, t_server *t, t_world *w)
{
    int     item;
    int     index_item;
    (void) (t);
    char    out[256];

    index_item = atoi(rqd->argv[0]);
    if (index_item < 7)
    {
        item = (w->surface[rqd->user->posy]
                [rqd->user->posx]).resources[]--;
        rqd->user->inventory[item]++;
        sprintf(out, "pgt %d %d\n", rqp->user->number, index_item);

        cli_answer(rqd->user, t, "ok\n");
    }
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
