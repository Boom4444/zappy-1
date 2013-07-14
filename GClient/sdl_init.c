/*
** sdl_init.c for sdl starter staff in /home/liu_q//zappy/Trantor
** 
** Made by qiuyan liu
** Login   <liu_q@epitech.net>
** 
** Started on  Tue Jul  9 19:23:05 2013 qiuyan liu
** Last update Sun Jul 14 21:56:06 2013 ivan ignatiev
*/

#include <SDL/SDL.h>
#include "clip_ressources.h"
#include "map.h"

void		apply_surface(int x, int y, SDL_Surface* source,
			      SDL_Surface* destination, SDL_Rect* clip)
{
  SDL_Rect	offset;

  offset.x = x;
  offset.y = y;
  SDL_BlitSurface(source, clip, destination, &offset);
}

SDL_Surface	*load_image(char filename[10])
{
  SDL_Surface*	loadedImage = NULL;
  SDL_Surface*	optimizedImage = NULL;

  loadedImage = IMG_Load(filename);
  if (loadedImage != NULL)
    {
      optimizedImage = SDL_DisplayFormat(loadedImage);
      SDL_FreeSurface(loadedImage);
      if (optimizedImage != NULL)
	SDL_SetColorKey(optimizedImage, SDL_SRCCOLORKEY,
			 SDL_MapRGB(optimizedImage->format, 0xFF, 0xFF, 0xFF));
    }
  return (optimizedImage);
}

int	load_files(t_graphic *g)
{
  g->ressources = load_image( "res/res.png" );
  g->foods = load_image("res/Res.bmp");
  if (g->ressources == NULL || g->foods == NULL)
    return (0);
  return (1);
}

int	init(t_graphic *g)
{
  if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
    return (0);
  g->screen = SDL_SetVideoMode(SCREEN_WIDTH * SQUARE_SIZE,
				SCREEN_HEIGHT * SQUARE_SIZE, SCREEN_BPP, SDL_SWSURFACE);
  if (g->screen == NULL)
    return (0);
  SDL_WM_SetCaption("Trantor", NULL);
  clip_ressources(g->clip);
  g->CURRENT_X = 0;
  g->CURRENT_Y = 0;
  g->xVel = 0;
  g->yVel = 0;
  if (load_files(g) == 0)
    return (0);
  else
    return (1);
}

void	clean_up(t_graphic *g)
{
  SDL_FreeSurface(g->ressources);
  SDL_FreeSurface(g->foods);
  SDL_Quit();
}
