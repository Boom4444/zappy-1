/*
** broadcast.h for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Tue Jul 09 07:20:02 2013 Marin Alcaraz
** Last update Tue Jul 09 07:46:09 2013 Marin Alcaraz
*/

#ifndef BROADCAST_H_
# define BROADCAST_H_

int         determine_direction(int alpha);
double      broadcast_get_distance(t_user_player *u, int x, int y);
int         or_to_dir(int orientation);
double      generate_offsets(double offsets[9][3], t_request_data  *rqd, t_user_player *current, t_server *t);
int         broadcast_to(t_user_player *user, t_request_data *rqd, t_server *t);

#endif /* !BROADCAST_H_ */
