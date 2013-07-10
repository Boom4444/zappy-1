/*
** show_map.h for show map in /home/liu_q//zappy/Trantor
** 
** Made by qiuyan liu
** Login   <liu_q@epitech.net>
** 
** Started on  Tue Jul  9 20:00:54 2013 qiuyan liu
** Last update Tue Jul  9 20:21:50 2013 qiuyan liu
*/

#ifndef SHOW_MAP_H_
#define SHOW_MAP_H_

int	init_map(t_map *w, int width, int height);
void	handle_input(t_graphic *g);
void	move(t_map *map, t_graphic *g);
void	show_res_square(t_map *map, int x, int y, t_graphic *g);
void	show_ressources(t_graphic *g, t_map *map);

#endif /* SHOW_MAP_H_ */
