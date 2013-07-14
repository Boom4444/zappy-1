/*
** resource_manager.h for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Sun Jul 14 08:07:30 2013 Marin Alcaraz
** Last update Sun Jul 14 18:19:53 2013 ivan ignatiev
*/

#ifndef RESOURCE_MANAGER_H_
# define RESOURCE_MANAGER_H_

void	resources_refresh(int resource,
			  t_server *s, t_world *w);
int	generate_resource(t_world *w, int width, int height);
int	mineral_checker(t_square_unit *sq);

#endif /* !RESOURCE_MANAGER_H_ */
