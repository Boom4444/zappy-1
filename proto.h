/*
** proto.h for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Wed Jun 12 17:02:27 2013 Marin Alcaraz
** Last update Wed Jun 12 17:02:55 2013 Marin Alcaraz
*/

#ifndef PROTO_H_
# define PROTO_H_

#include "server.h"
#include "select.h"

void        cli_parse(t_user *u, t_server *s, t_world *);
void        graph_parse(t_user *u, t_server *s, t_world *);
int         proto_parse(t_user *u, t_server *s, t_world *w);
int         proto_define(t_user *u, t_world *w);

#endif /* !PROTO_H_ */
