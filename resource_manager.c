/*
** resource_manager.c for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Sun Jul 14 07:14:41 2013 Marin Alcaraz
** Last update Sun Jul 14 07:14:43 2013 Marin Alcaraz
*/

#include	"main.h"
#include	"list.h"
#include	"error.h"
#include	"trantor.h"

void		random_number(int *container, int limit)
{
  *container = rand() % limit;
}

int		generate_resource(t_world *w, int width, int height)
{
  int		amount;
  int		minx;
  int		miny;
  int		resource;

  amount = 0;
  srand(time(NULL));
  while (amount < RESOURCE_LIMIT)
    {
      random_number(&minx, width);
      random_number(&miny, height);
      random_number(&resource, 7);
      (w->surface[miny][minx]).resources[resource]++;
      amount = amount + 1;
    }
  return (0);
}

int		mineral_checker(t_square_unit *sq)
{
  int		i;

  i = 0;
  while (i < RES_TYPES_COUNT)
    {
      if (sq->resources[i] != 0)
	return (1);
      i = i + 1;
    }
  return (0);
}
