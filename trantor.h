/*
** trantor.h for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Thu Jun 20 17:38:38 2013 Marin Alcaraz
** Last update Sun Jul 14 08:09:16 2013 Marin Alcaraz
*/

#ifndef TRANTOR_H_
# define TRANTOR_H_

# define FOOD			0
# define LINEMATE		1
# define DERAUMERE		2
# define SIBUR			3
# define MENDIANE		4
# define PHIRAS			5
# define THYSTAME		6
# define RES_TYPES_COUNT	7
# define RESOURCE_LIMIT		256
# define _MOD(x, d)		(((x) < 0) ? ((d) - ((-(x)) % (d))) : ((x) % (d)))

typedef struct	s_point
{
  int		x;
  int		y;
}		t_point;

typedef struct	s_square_unit
{
  t_list	*players;
  int		resources[RES_TYPES_COUNT + 1];
}		t_square_unit;

typedef struct	s_world
{
  t_square_unit	**surface;
  int		width;
  int		height;
}		t_world;

int	init_world(t_world *w, int width, int height);
int	display_world(t_world *w, int width, int height);
int	generate_resource(t_world *w, int width, int height);
int	mineral_checker(t_square_unit *sq);
void	random_number(int *container, int limit);
void	world_destroy(t_world *w);

#endif /* !TRANTOR_H_ */
