/*
** proto_commands_items.h for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Thu Jun 13 16:35:59 2013 Marin Alcaraz
** Last update Sat Jul 13 20:22:50 2013 ivan ignatiev
*/

#ifndef PROTO_COMMANDS_ITEMS_H_
# define PROTO_COMMANDS_ITEMS_H_

void	cli_inventaire(t_request_data *rqd, t_server *t, t_world *w);
void	cli_prend(t_request_data *rqd, t_server *t, t_world *w);
void	cli_pose(t_request_data *rqd, t_server *t, t_world *w);
int	cli_pin(char *response, t_user_player *p);
int	cli_command_bct(char *response, int x, int y, t_world *w);

#endif /* !PROTO_COMMANDS_ITEMS_H_ */
