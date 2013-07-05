/*
** expulse.c for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Thu Jul 04 09:57:07 2013 Marin Alcaraz
** Last update Fri Jul 05 11:50:09 2013 Marin Alcaraz
*/

#include "main.h"
#include "list.h"
#include "options.h"
#include "trantor.h"
#include "server.h"
#include "users.h"
#include "request.h"
#include "answer.h"
#include "proto_commands_net.h"

void        expulse_square(int nx, int ny, t_request_data *rqd, t_world *w)
{
    t_item  *current_item;

    current_item =
        (w->surface[rqd->user->posx][rqd->user->posy]).players->head;
    while (current_item != NULL)
    {
        if (current_item->cont != rqd->user)
        {
            T_PLAYER(current_item)->posx = nx;
            T_PLAYER(current_item)->posy = ny;
        }
        current_item = current_item->next;
    }
}
