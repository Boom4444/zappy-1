/*
** incantation.h for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Wed Jul 10 10:42:13 2013 Marin Alcaraz
** Last update Wed Jul 10 13:39:07 2013 Marin Alcaraz
*/

#ifndef INCANTATION_H_
# define INCANTATION_H_

int         incantate(t_user_player *p, t_server *t, t_world *w);
void        level_up(t_list *players, int level);
int         count_players(t_list *players, t_user_player *player);
int         init_incantation(t_request_data *rqd, t_server *s, t_world *w);
int         end_incantation(int stat, t_request_data *rqd, t_server *s, t_world *w);

#endif /* !INCANTATION_H_ */
