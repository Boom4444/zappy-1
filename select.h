/*
** select.h for server in /home/hero/zappy/server
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Sat Apr 27 20:28:03 2013 ivan ignatiev
** Last update Thu Jun 06 00:09:32 2013 Marin Alcaraz
*/

#ifndef SELECT_H_
# define SELECT_H_

# include	<sys/time.h>
# include	<sys/types.h>
# include	<unistd.h>
# include	<stdio.h>
# include	<string.h>
# include   "log.h"
# include   "error.h"
# include	"users.h"
# include   "server.h"
# include   "list.h"
# include   "log.h"

int		select_do(t_list *users, int serverfd);

#endif /* !SELECT_H_ */
