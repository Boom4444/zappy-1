/*
** show_map.c for show map in /home/liu_q//zappy/Trantor
** 
** Made by qiuyan liu
** Login   <liu_q@epitech.net>
** 
** Started on  Tue Jul  9 19:28:47 2013 qiuyan liu
** Last update Thu Jul 11 16:55:50 2013 qiuyan liu
*/

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "map.h"
#include "sdl_init.h"

int	init_map(t_map *w, int width, int height)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  w->surface = (t_square_content **) malloc(sizeof(t_square_content *) * height);
  while (i < height)
    {
      if ((w->surface[i] = malloc(sizeof(t_square_content) * width)) == NULL)
        {
	  return (EXIT_FAILURE);
        }
      j = 0;
      while ( j < width )
	{
	  memset(w->surface[i][j].ressources, 0, sizeof(int) * NUM_RESSOURCES);
	  j = j + 1;
	}
      i = i + 1;
    }
  w->players = list_init();
  w->width = width;
  w->height = height;
  return (0);
}

void	handle_input(t_graphic *g)
{
  if( g->event.type == SDL_KEYDOWN )
    {
      if ( g->event.key.keysym.sym == SDLK_UP)
        g->yVel -= SPEED;
      else if ( g->event.key.keysym.sym == SDLK_DOWN)
        g->yVel += SPEED;
      else if (g->event.key.keysym.sym == SDLK_LEFT)
	g->xVel += SPEED;
      else if (g->event.key.keysym.sym == SDLK_RIGHT)
	g->xVel -= SPEED;
    }
  else if ( g->event.type == SDL_KEYUP )
    {
      if (g->event.key.keysym.sym == SDLK_UP)
        g->yVel += SPEED;
      else if (g->event.key.keysym.sym == SDLK_DOWN)
        g->yVel -= SPEED;
      else if (g->event.key.keysym.sym == SDLK_LEFT)
        g->xVel -= SPEED;
      else if (g->event.key.keysym.sym == SDLK_RIGHT)
        g->xVel += SPEED;
    }
}

void	move(t_map *map, t_graphic *g)
{
  g->CURRENT_X = _MOD(g->CURRENT_X + g->xVel, map->width);
  g->CURRENT_Y = _MOD(g->CURRENT_Y + g->yVel, map->height);
}

void	show_res_square(t_map *map, int x, int y, t_graphic *g, int j, int i)
{
  int	n;
  int	x_pos;
  int	y_pos;

  n = 0;
  while (n < NUM_RESSOURCES)
    {
      x_pos = (( n % 4) * 15) + (j * SQUARE_SIZE);
      y_pos = ((n / 4 + 2) * 15) + (i * SQUARE_SIZE);
      if (map->surface[y][x].ressources[n] > 0)
      apply_surface(x_pos, y_pos, g->foods, g->screen, &(g->clip[n + 11]));
      n++;
    }
}

void	show_ressources(t_graphic *g, t_map *map)
{
  int	x;
  int	y;
  int	i;
  int	j;

  y = g->CURRENT_Y;
  i = 0;
  while (i < SCREEN_HEIGHT)
    {
      x = g->CURRENT_X;
      j = 0;
      while (j < SCREEN_WIDTH)
        {
          apply_surface(j * SQUARE_SIZE, i * SQUARE_SIZE, g->ressources, g->screen, &g->clip[0]);
	  show_res_square(map, x, y, g, j, i);
	  x = _MOD(x + 1 , map->width);
	  j++;
        }
      y = _MOD(y + 1, map->height);
      i++;
    }
}
