/*
** users.h for zappy in /home/ignatiev/Projects/zappy
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Sat Apr 27 17:03:35 2013 ivan ignatiev
** Last update Thu Jun 13 18:48:01 2013 ivan ignatiev
*/

#ifndef USERS_H_
# define USERS_H_

# include	<stdlib.h>
# include	<stdio.h>
# include	<string.h>
# include	<sys/socket.h>
# include	<netinet/in.h>
# include	<arpa/inet.h>
# include	<unistd.h>
# include   "list.h"

# define PRE_CONNECTED	2
# define CONNECTED		1
# define DISCONNECTED	0
# define NAME_LIMIT     256
# define ARTICLES_LIMIT 21
# define GRAPHIC_PROTO  100
# define CLI_PROTO      200

typedef struct		    s_user
{
  int			        clientfd;
  int			        connected;
  int                   protocol;
  struct sockaddr_in	addr;
  socklen_t		        addrlen;
  char                  *request;

  char			        team[NAME_LIMIT];
  int                   inventory[ARTICLES_LIMIT];
  int                   request_counter;
}			            t_user;

/* TODO : struct for each type of client */

t_user		*user_create(void);
t_list		*user_add(t_list *users, t_user *user);
t_list		*user_remove(t_list *users, t_user *user);
t_user		*user_find(t_list *users, char *nick);
t_list		*user_remove_all(t_list *users);

#endif /* !USERS_H_ */
