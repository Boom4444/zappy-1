/*
** expulse.c for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Thu Jul 04 09:57:07 2013 Marin Alcaraz
** Last update Thu Jul 04 10:39:26 2013 Marin Alcaraz
*/

#include        "users.h"
#include        "server.h"
#include        "answer.h"
#include        "proto_commands_net.h"

void        expulse_square(int nx, int ny, t_request_data *rqd, t_world *w)
{
    t_item  *current_item;

    current_item =
        (w->surface[rqd->user->posx][rqd->user->posy]).players->head;
    while (current_item != NULL)
    {
        if (current_item->cont != rqd->user)
        {
            T_USER(current_item)->posx = nx;
            T_USER(current_item)->posy = ny;
        }
        current_item = current_item->next;
    }
}
