/*
** proto_commands_movement.h for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Thu Jun 13 16:36:15 2013 Marin Alcaraz
** Last update Thu Jun 13 16:47:43 2013 Marin Alcaraz
*/

#ifndef PROTO_COMMANDS_MOVEMENT_H_
# define PROTO_COMMANDS_MOVEMENT_H_

#include "server.h"

void    cli_avance(t_request_data *d, t_server *t, t_world *w);
void    cli_droite(t_server *t, t_world *w);
void    cli_gauche(t_server *t, t_world *w);
void    cli_broadcast(t_server *t, t_world *w);
void    cli_voir(t_server *t, t_world *w);

#endif /* !PROTO_COMMANDS_MOVEMENT_H_ */
