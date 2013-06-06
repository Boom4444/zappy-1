/*
** server.h for server in /home/hero/zappy/server
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Sun May 26 18:53:05 2013 Marin Alcaraz
** Last update Wed Jun 05 21:50:43 2013 Marin Alcaraz
*/

#ifndef SERVER_H_
# define SERVER_H_

#include    <string.h>
#include    <stdio.h>
#include    "connection_utils.h"
#include    "server_functions.h"
#include    "select.h"
#include    "error.h"
#include    "list.h"
#include    "log.h"

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
}                   t_server;

typedef struct      s_word
{
  t_list            *trantor;

}                   t_word;

int         server_handshake(int *, char const *ip);
void        server_handleclient(struct sockaddr_in *s_client, int *);
int         server_start(int port);

#endif /* !SERVER_H_ */
