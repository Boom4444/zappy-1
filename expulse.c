/*
** expulse.c for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Thu Jul 04 09:57:07 2013 Marin Alcaraz
** Last update Tue Jul 09 13:28:53 2013 Marin Alcaraz
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

void                expulse_square(int nx, int ny, t_request_data *rqd, t_world *w, t_server *s)
{
    t_item          *tmp;
    t_item          *current_item;
    t_user_player   *tmp_play;
    char            out[ANSWER_SIZE];

    current_item =
        (w->surface[rqd->user->posy][rqd->user->posx]).players->head;
    while (current_item != NULL)
    {
        tmp_play = T_PLAYER(current_item->cont);
        if (current_item->cont != rqd->user)
        {
            sprintf(out, "deplacement: %d\n", rqd->user->orientation + 1);
            tmp = current_item->next;
            cli_answer(tmp_play, s, out);
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
