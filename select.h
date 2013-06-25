/*
** select.h for zappy in /home/ignatiev/Projects/zappy
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Sat Apr 27 20:28:03 2013 ivan ignatiev
** Last update Tue Jun 25 18:09:06 2013 ivan ignatiev
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


int		select_do(t_server *s, t_world *w);

#endif /* !SELECT_H_ */
