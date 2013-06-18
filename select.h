/*
** select.h for zappy in /home/hero/zappy
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Sat Apr 27 20:28:03 2013 ivan ignatiev
** Last update Wed Jun 12 17:03:14 2013 Marin Alcaraz
*/

#ifndef SELECT_H_
# define SELECT_H_

# include	<sys/time.h>
# include	<sys/types.h>
# include	<unistd.h>
# include	<stdio.h>
# include	<string.h>
# include   "server.h"
# include   "error.h"
# include	"users.h"
# include   "list.h"
# include   "proto.h"

# define    T_USER(user) ((t_user *)(user))

int		select_do(t_server *s, t_world *w);

#endif /* !SELECT_H_ */
