/*
** users.h for zappy in /home/hero/zappy
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Sat Apr 27 17:03:35 2013 ivan ignatiev
** Last update Wed Jun 26 16:03:01 2013 Marin Alcaraz
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

#define PRE_CONNECTED	2
#define CONNECTED		1
#define DISCONNECTED	0
#define NAME_LIMIT     256
#define ARTICLES_LIMIT 7
#define GRAPHIC_PROTO  100
#define CLI_PROTO      200

#define TOP         0
#define TOP_LEFT    1
#define MID_LEFT    2
#define BOT_LEFT    3
#define BOT_MID     4
#define BOT_RIGHT   5
#define MID_RIGHT   6
#define TOP_RIGHT   7

#define    T_USER(user) ((t_user *)(user))

typedef struct		s_user
{
  int			clientfd;
  int			connected;
  int                   protocol;
  struct sockaddr_in	addr;
  socklen_t		addrlen;
  char                  *request;

  int                   posx;
  int                   posy;
  int                   direction;

  char			team[NAME_LIMIT];
  int                   inventory[ARTICLES_LIMIT];
  int                   request_counter;
}			            t_user;

typedef struct          s_user_player
{

}                       t_user_player;

typedef struct          s_user_graph
{

}                       t_user_graph;

#endif /* !USERS_H_ */
