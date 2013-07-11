/*
** expulse.c for zappy in /home/ignatiev/Projects/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Thu Jul 04 09:57:07 2013 Marin Alcaraz
** Last update Thu Jul 11 18:42:05 2013 ivan ignatiev
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
    char            response[ANSWER_SIZE];

    current_item =
        list_get_head((w->surface[rqd->user->posy][rqd->user->posx]).players);
    while (current_item != NULL)
    {
        tmp_play = T_PLAYER(current_item->cont);
        if (current_item->cont != rqd->user)
        {
            sprintf(response, "deplacement: %d\n", rqd->user->orientation + 1);
            tmp = current_item->next;
            cli_answer(tmp_play, s, response);
            item_delete_by_content(
                w->surface[rqd->user->posy][rqd->user->posx].players,
                tmp_play);
           tmp_play->posx = nx;
           tmp_play->posy = ny;
           sprintf(response, "ppo %d %d %d %d\n", tmp_play->number, nx, ny, tmp_play->orientation + 1);
           cli_answer_to_all_graph(s, response);
           item_pb(w->surface[ny][nx].players, tmp_play, sizeof(t_user_player));
           current_item = tmp;
        }
        else
            current_item = current_item->next;
    }
}
