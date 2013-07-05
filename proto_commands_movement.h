/*
** proto_commands_movement.h for zappy in /home/ignatiev/Projects/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Thu Jun 13 16:36:15 2013 Marin Alcaraz
** Last update Thu Jul 04 21:24:07 2013 ivan ignatiev
*/

#ifndef PROTO_COMMANDS_MOVEMENT_H_
# define PROTO_COMMANDS_MOVEMENT_H_

typedef struct 		s_steps
{
    int 			x;
    int 			y;
} 					t_steps;

void    cli_avance(t_request_data *d, t_server *t, t_world *w);
void    cli_droite(t_request_data *rqd, t_server *t, t_world *w);
void    cli_gauche(t_request_data *rqd, t_server *t, t_world *w);
void    cli_broadcast(t_request_data *rqd, t_server *t, t_world *w);
void    cli_voir(t_request_data *rqd, t_server *t, t_world *w);
int     broadcast_to(t_user_player *user, t_request_data *rqd, t_server *t);
double     generate_offsets(double pd[9][3], t_request_data  *rqd, t_user_player *, t_server *t);
double  broadcast_get_distance(t_user_player *u, int x, int y);

#endif /* !PROTO_COMMANDS_MOVEMENT_H_ */
