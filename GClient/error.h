/*
** error.c for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
**
** Started on  Fri Jun 05 16:42:14 2013 Marin Alcaraz
** Last update Sun Jul 14 22:35:22 2013 ivan ignatiev
*/

#ifndef ERROR_H_
# define ERROR_H_

# include	<string.h>
# include	<errno.h>

void	error_put(char *s);
int	error_log(char *loc, char *func, char *msg);
int	error_show(char *loc, char *func, char *msg);

#endif /* !ERROR_H_ */
