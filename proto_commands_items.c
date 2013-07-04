/*
** proto_commands_items.c for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Thu Jun 13 16:28:40 2013 Marin Alcaraz
** Last update Thu Jul 04 09:02:06 2013 Marin Alcaraz
*/

#include "trantor.h"
#include "proto_commands_items.h"
#include "request.h"
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
    (void) (t);

    item = (w->surface[rqd->user->posy]
               [rqd->user->posx]).resources[atoi(rqd->argv[0])]--;
    rqd->user->inventory[item]++;
    cli_answer(rqd->user, t, "OK\n");
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
