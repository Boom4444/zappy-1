/*
** clip_ressources.c for clip ressources in /home/liu_q//zappy/Trantor
** 
** Made by qiuyan liu
** Login   <liu_q@epitech.net>
** 
** Started on  Tue Jul  9 16:37:56 2013 qiuyan liu
** Last update Wed Jul 10 18:52:11 2013 qiuyan liu
*/

#include "SDL/SDL.h"
#include "map.h"

void	clip_background(SDL_Rect clip[20])
{
  clip[0].x = 10;
  clip[0].y = 45;
  clip[0].w = SQUARE_SIZE;
  clip[0].h = SQUARE_SIZE;
}

void	clip_plants(SDL_Rect clip[20])
{
  int	i;

  clip[3].x = SQUARE_SIZE * 2;
  clip[3].y = SQUARE_SIZE * 7;
  clip[4].x = SQUARE_SIZE * 3;
  clip[4].y = SQUARE_SIZE * 7;
  clip[5].x = SQUARE_SIZE * 3;
  clip[5].y = SQUARE_SIZE * 9;
  clip[6].x = SQUARE_SIZE * 25;
  clip[6].y = SQUARE_SIZE * 15;
  clip[7].x = SQUARE_SIZE * 25;
  clip[7].y = SQUARE_SIZE * 16;
  clip[8].x = SQUARE_SIZE * 25;
  clip[8].y = SQUARE_SIZE * 17;
  clip[9].x = SQUARE_SIZE * 25;
  clip[9].y = SQUARE_SIZE * 18;
  clip[10].x = SQUARE_SIZE * 24;
  clip[10].y = SQUARE_SIZE * 133;
  i = 2;
  while (++i < 11)
    {
      clip[i].w = SQUARE_SIZE;
      clip[i].h = SQUARE_SIZE;
    }
}

void	clip_foods(SDL_Rect clip[20])
{
  int	i;

  clip[11].x = 0;
  clip[11].y = 0;
  clip[12].x = 30;
  clip[12].y = 0;
  clip[13].x = 15;
  clip[13].y = 15;
  clip[14].x = 0;
  clip[14].y = 15;
  clip[15].x = 30;
  clip[15].y = 15;
  clip[16].x = 0;
  clip[16].y = 30;
  clip[17].x = 15;
  clip[17].y = 30;
  i = 10;
  while (++i < 18)
    {
      clip[i].w = 15;
      clip[i].h = 15;
    }
}

void	clip_ressources(SDL_Rect clip[20])
{
  clip_background(clip);
  clip_plants(clip);
  clip_foods(clip);
}
