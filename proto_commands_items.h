/*
** proto_commands_items.h for zappy in /home/ignatiev/Projects/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Thu Jun 13 16:35:59 2013 Marin Alcaraz
** Last update Thu Jul 04 20:24:46 2013 ivan ignatiev
*/

#ifndef PROTO_COMMANDS_ITEMS_H_
# define PROTO_COMMANDS_ITEMS_H_

void    cli_inventaire(t_request_data *rqd, t_server *t, t_world *w);
void    cli_prend(t_request_data *rqd, t_server *t, t_world *w);
void    cli_pose(t_request_data *rqd, t_server *t, t_world *w);

#endif /* !PROTO_COMMANDS_ITEMS_H_ */
