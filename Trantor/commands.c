/*
** commands.c for commands in /home/liu_q//zappy/Trantor
** 
** Made by qiuyan liu
** Login   <liu_q@epitech.net>
** 
** Started on  Tue Jul  9 14:47:14 2013 qiuyan liu
** Last update Sat Jul 13 12:46:16 2013 qiuyan liu
*/

#include "map.h"
#include "list.h"

int	taille_carte(t_map *w, int x, int y)
{
  return (init_map(w, x, y));
}

int	contenu_une_carte(t_square_info *info, t_map *map)
{
  int	n;

  n = 0;
  while (n < NUM_RESSOURCES)
    {
      map->surface[info->y][info->x].ressources[n] = info->res[n];
      n++;
    }
  return (1);
}

void	contenu_carte(t_square_info *res_info, t_map *map)
{
  int	i;

  i = 0;
  while (i <  map->height * map->width)
    {
      contenu_une_carte(&res_info[i], map);
      i++;
    }
}
