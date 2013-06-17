/*
** proto_commands_movement.h for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Thu Jun 13 16:36:15 2013 Marin Alcaraz
** Last update Thu Jun 13 19:01:57 2013 Marin Alcaraz
*/

#ifndef PROTO_COMMANDS_MOVEMENT_H_
# define PROTO_COMMANDS_MOVEMENT_H_

#include "server.h"
#include "request.h"

void    cli_avance(t_request_data *d, t_server *t, t_world *w);
void    cli_droite(t_request_data *rqd, t_server *t, t_world *w);
void    cli_gauche(t_request_data *rqd, t_server *t, t_world *w);
void    cli_broadcast(t_request_data *rqd, t_server *t, t_world *w);
void    cli_voir(t_request_data *rqd, t_server *t, t_world *w);

#endif /* !PROTO_COMMANDS_MOVEMENT_H_ */
