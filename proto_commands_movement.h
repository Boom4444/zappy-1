/*
** proto_commands_movement.h for zappy in /home/ignatiev/Projects/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Thu Jun 13 16:36:15 2013 Marin Alcaraz
** Last update Sat Jul 13 20:18:38 2013 ivan ignatiev
*/

#ifndef PROTO_COMMANDS_MOVEMENT_H_
# define PROTO_COMMANDS_MOVEMENT_H_

void	cli_avance(t_request_data *d, t_server *t, t_world *w);
void	cli_droite(t_request_data *rqd, t_server *t, t_world *w);
void	cli_gauche(t_request_data *rqd, t_server *t, t_world *w);
void	cli_broadcast(t_request_data *rqd, t_server *t, t_world *w);
void	cli_voir(t_request_data *rqd, t_server *t, t_world *w);
int	broadcast_to(t_user_player *user, t_request_data *rqd, t_server *t);
double	generate_offsets(double pd[9][3], t_request_data  *rqd,
			 t_user_player *, t_server *t);
double	broadcast_get_distance(t_user_player *u, int x, int y);
int	match_index(char *str);
char	*cli_voir_resources(char *response, int *resources);
char	*cli_voir_players(char *response, t_list *players);

#endif /* !PROTO_COMMANDS_MOVEMENT_H_ */
