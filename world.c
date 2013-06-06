/*
** world.c for zappy in /home/hero/zappy
** 
** Made by qiuyan liu
** Login   <liu_q@epitech.net>
** 
** Started on  Tue May 28 19:57:19 2013 qiuyan liu
** Last update Thu Jun 06 16:25:16 2013 Marin Alcaraz
*/

#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

const int	SCREEN_WIDTH = 1024;
const int	SCREEN_HEIGHT = 672;
const int	SCREEN_BPP = 32;
const int	n_column = 1024 / 32;
const int	n_row = 672 / 32;

SDL_Surface	*bush = NULL;
SDL_Surface	*background = NULL;
SDL_Surface	*screen = NULL;

SDL_Event	event;

SDL_Surface	*load_image(char *filename)
{
  SDL_Surface	*loadedImage = NULL;
  SDL_Surface	*optimizedImage = NULL;

  loadedImage = IMG_Load(filename);
  if (loadedImage != NULL)
    {
      optimizedImage = SDL_DisplayFormat(loadedImage);
      SDL_FreeSurface(loadedImage);
      if (optimizedImage != NULL)
	{
	  Uint32	colorkey = SDL_MapRGB(optimizedImage->format, 0xFF, 0xFF, 0xFF);
	  SDL_SetColorKey(optimizedImage, SDL_SRCCOLORKEY, colorkey);
	}
    }
  return (optimizedImage);
}

void		apply_surface(int x, int y, SDL_Surface *source, SDL_Surface *destination)
{
  SDL_Rect	offset;

  offset.x = x;
  offset.y = y;
  SDL_BlitSurface(source, NULL, destination, &offset);
}

int	init()
{
  if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
    return (0);
  screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
  if (screen == NULL)
    return (0);
  SDL_WM_SetCaption("Trantor", NULL);
  return (1);
}

int	load_files()
{
  background = load_image("resources/grass_background2.jpg");
  if (background == NULL)
    return (0);
  bush = load_image("resources/bush.png");
  if (bush == NULL)
    return (0);
  return (1);
}

int	apply_files()
{
  char	board[n_row][n_column];
  int	n_plants;
  int	x;
  int	y;

  memset(board, 0, sizeof(char) * n_column * n_row);
  n_plants = 0;
  apply_surface(0, 0, background, screen);
  srand((int)time(0));
  while (n_plants < n_column)
  {
    x = rand() % n_column;
    y = rand() % n_row;
    if (board[y][x] == 0)
      {
	apply_surface(x * 32, y * 32, bush, screen);
	apply_surface(0, 0, bush, screen);
	board[y][x] = 1;
	n_plants++;
      }
  }
  return (0);
}

void	clean_up()
{
  SDL_FreeSurface(background);
  SDL_FreeSurface(bush);
  SDL_Quit();
}

int	main()
{
  int	quit = 0;

  if (init() == 0)
    return (1);
  if (load_files() == 0)
    return (1);
  apply_files();
  if (SDL_Flip(screen) == -1)
    return (1);
  while (quit == 0)
    {
      while (SDL_PollEvent(&event))
	{
	  if (event.type == SDL_QUIT)
	    quit = 1;
	}
    }
  clean_up();
  return (0);
}
