/*
** incantation.h for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Wed Jul 10 10:42:13 2013 Marin Alcaraz
** Last update Thu Jul 11 13:26:43 2013 Marin Alcaraz
*/

#ifndef INCANTATION_H_
# define INCANTATION_H_

int         incantate(t_list *pl, t_user_player *p, t_server *t, t_world *w);
int         level_up(int eq_players, t_user_player *, t_list *players, t_world *w);
int         count_players(t_list *players, t_user_player *player);
int         init_incantation(t_list *p, t_request_data *rqd, t_server *s, t_world *w);
int         end_incantation(t_list *, t_request_data *rqd, t_server *s, t_world *w);
int         match_players(t_list *ps, t_list *currents);
int         fail_incantation(t_request_data *rqd, t_server *s);

#endif /* !INCANTATION_H_ */
