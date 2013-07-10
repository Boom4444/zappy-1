/*
** map.h for map info in /home/liu_q//zappy/Trantor
** 
** Made by qiuyan liu
** Login   <liu_q@epitech.net>
** 
** Started on  Tue Jul  9 16:26:20 2013 qiuyan liu
** Last update Wed Jul 10 19:05:16 2013 qiuyan liu
*/

#ifndef MAP_H_
# define MAP_H_

# include "SDL/SDL.h"
# include "SDL/SDL_image.h"
# include "list.h"

# define SCREEN_WIDTH	7
# define SCREEN_HEIGHT	5
# define SCREEN_BPP	32
# define SQUARE_SIZE	60
# define FOOD_WIDTH	30
# define FOOD_HEIGHT	30
# define SPEED 1
# define _MOD(x,d)  (((x) < 0) ? (((d) - ( (-(x)) % (d))) % (d)) : (x) % (d))
# define FOOD		11
# define LINEMATE	12
# define DERAUMERE	13
# define SIBUR		14
# define MENDIANE	15
# define PHIRAS		16
# define THYSTAME	17
# define NUM_RESSOURCES	7

typedef struct	s_square_info
{
  int		x;
  int		y;
  int		res[NUM_RESSOURCES];
}		t_square_info;

typedef struct	s_square_content
{ 
    int		ressources[NUM_RESSOURCES];
}		t_square_content;

typedef struct		s_map
{
  t_square_content	**surface;
  int			width;
  int			height;
  t_list		*players;
}			t_map;

typedef struct	s_graphic
{
  int		quit;
  int		yVel;
  int		xVel;
  int		CURRENT_X;
  int		CURRENT_Y;
  SDL_Surface	*ressources;
  SDL_Surface	*screen;
  SDL_Surface	*foods;
  SDL_Event	event;
  SDL_Rect	clip[20];
}		t_graphic;

int        init_map(t_map *w, int width, int height);

#endif /* !MAP_H_ */
