/*
** proto.h for zappy in /home/ignatiev/Projects/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Wed Jun 12 17:02:27 2013 Marin Alcaraz
** Last update Sat Jul 13 20:22:02 2013 ivan ignatiev
*/

#ifndef PROTO_H_
# define PROTO_H_

# define PROTO_BUFFER	2048

int	cli_parse(t_user_player *u, t_server *s, t_world *);
int	graph_parse(t_user_graph *u, t_server *s, t_world *);
int	proto_parse(t_user *u, t_server *s, t_world *w);
t_user*	proto_define(t_user *u, t_server *s, t_world *w);
int	proto_flud_detect(t_user *u, char *buf);

#endif /* !PROTO_H_ */
