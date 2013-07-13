/*
** users_graph.h for zappy in /home/ignati_i//zappy/zappy
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Sat Jul 13 14:17:42 2013 ivan ignatiev
** Last update Sat Jul 13 14:18:15 2013 ivan ignatiev
*/

#ifndef USERS_GRAPH_H_
# define USERS_GRAPH_H_

int		graph_display_users(t_server *s, t_graph_data *);
int		graph_client_init(t_user_graph *, t_server *s,
				  t_world *w);
int		graph_command_display(t_graph_data *, t_server *s,
				      t_world *w);

#endif /* !USERS_GRAPH_H_ */
