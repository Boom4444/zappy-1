/*
** server.h for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Sun May 26 18:53:05 2013 Marin Alcaraz
** Last update Wed Jun 12 15:27:40 2013 Marin Alcaraz
*/

#ifndef SERVER_H_
# define SERVER_H_

#include    <string.h>
#include    <stdio.h>
#include    "options.h"
#include    "connection_utils.h"
#include    "server_functions.h"
#include    "error.h"
#include    "list.h"

#define  QUEUE_LIMIT    10
#define  SERVER_RUN     1
#define  LIMIT          2
#define  SERV_FD        0
#define  CLI_FD         1

typedef  struct     s_server
{
  t_list            *client_list;
  t_list            *request_list;
  t_list            *answer_list;
  t_list            *team_list;
  t_opt             options;
  int               server_fd;
}                   t_server;

typedef struct      s_world
{
  t_list            *trantor;

}                   t_world;

int         server_handshake(int);
void        server_handleclient(struct sockaddr_in *s_client, int *);
int         server_start(t_server *s, t_world *w);

#endif /* !SERVER_H_ */
