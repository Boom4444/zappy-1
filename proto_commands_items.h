/*
** proto_commands_items.h for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Thu Jun 13 16:35:59 2013 Marin Alcaraz
** Last update Thu Jun 13 19:01:48 2013 Marin Alcaraz
*/

#ifndef PROTO_COMMANDS_ITEMS_H_
# define PROTO_COMMANDS_ITEMS_H_

#include "server.h"
#include "request.h"

void    cli_inventaire(t_request_data *rqd, t_server *t, t_world *w);
void    cli_prend(t_request_data *rqd, t_server *t, t_world *w);
void    cli_pose(t_request_data *rqd, t_server *t, t_world *w);

#endif /* !PROTO_COMMANDS_ITEMS_H_ */
