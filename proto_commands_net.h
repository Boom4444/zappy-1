/*
** proto_commands_net.h for zappy in /home/ignatiev/Projects/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Thu Jun 13 16:35:15 2013 Marin Alcaraz
** Last update Thu Jul 04 20:26:42 2013 ivan ignatiev
*/

#ifndef PROTO_COMMANDS_NET_H_
# define PROTO_COMMANDS_NET_H_

void    cli_expulse(t_request_data *rqd, t_server *t, t_world *w);
void    cli_incantation(t_request_data *rqd, t_server *t, t_world *w);
void    cli_fork_player(t_request_data *rqd, t_server *t, t_world *w);
void    cli_connect_nbr(t_request_data *rqd, t_server *t, t_world *w);
/* void    cli_death(t_server *t, t_world *w); */

#endif /* !PROTO_COMMANDS_NET_H_ */
