/*
** proto.h for zappy in /home/ignatiev/Projects/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Wed Jun 12 17:02:27 2013 Marin Alcaraz
** Last update Thu Jul 04 21:07:08 2013 ivan ignatiev
*/

#ifndef PROTO_H_
# define PROTO_H_

# define PROTO_BUFFER               1024

int         cli_parse(t_user_player *u, t_server *s, t_world *);
int         graph_parse(t_user_graph *u, t_server *s, t_world *);
int         proto_parse(t_user *u, t_server *s, t_world *w);
t_user*     proto_define(t_user *u, t_server *s, t_world *w);

#endif /* !PROTO_H_ */
