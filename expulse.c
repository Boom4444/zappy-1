/*
** expulse.c for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Thu Jul 04 09:57:07 2013 Marin Alcaraz
** Last update Mon Jul 08 16:49:48 2013 Marin Alcaraz
*/

#include "main.h"
#include "list.h"
#include "options.h"
#include "trantor.h"
#include "server.h"
#include "users.h"
#include "request.h"
#include "answer.h"
#include "item.h"
#include "proto_commands_net.h"

void                expulse_square(int nx, int ny, t_request_data *rqd, t_world *w)
{
    t_item          *tmp;
    t_item          *current_item;
    t_user_player   *tmp_play;

    current_item =
        (w->surface[rqd->user->posy][rqd->user->posx]).players->head;
    while (current_item != NULL)
    {
        tmp_play = T_PLAYER(current_item->cont);
        printf("OUTSIDE:user %u\n", tmp_play->number);
        if (current_item->cont != rqd->user)
        {
            tmp = current_item->next;
            printf("user %u\n", tmp_play->number);
            item_delete_by_content(
                w->surface[rqd->user->posy][rqd->user->posx].players,
                tmp_play);
           tmp_play->posx = nx;
           tmp_play->posy = ny;
            item_pf(w->surface[ny][nx].players, tmp_play, sizeof(t_user));
            current_item = tmp;
        }
        else
            current_item = current_item->next;
    }
}
