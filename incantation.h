/*
** incantation.h for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Wed Jul 10 10:42:13 2013 Marin Alcaraz
** Last update Sun Jul 14 18:19:05 2013 ivan ignatiev
*/

#ifndef INCANTATION_H_
# define INCANTATION_H_

# define VICTORY	6

extern int	g_level_combinations[7][7];

int	incantate(t_list *pl, t_user_player *p,
		  t_server *t, t_world *w);
int	level_up(int eq_players, t_user_player *,
		 t_list *players, t_world *w);
int	count_players(t_list *players, t_user_player *player);
int	init_incantation(t_list *p, t_request_data *rqd,
			 t_server *s, t_world *w);
int	end_incantation(t_list *, t_request_data *rqd,
			t_server *s, t_world *w);
int	match_players(t_list *ps, t_list *currents);
int	fail_incantation(t_request_data *rqd, t_server *s);
void	check_victory(t_server *t);
int     verify_enough_resources(t_user_player *p, t_server *s,
				t_world *w);

#endif /* !INCANTATION_H_ */
