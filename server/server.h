/*
** server.h for server in /home/hero/zappy/server
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Sun May 26 18:53:05 2013 Marin Alcaraz
** Last update Sun May 26 19:24:20 2013 Marin Alcaraz
*/

#ifndef SERVER_H_
# define SERVER_H_

#include    <string.h>
#include    <stdio.h>
#include    "connection_utils.h"
#include    "error.h"

#define  QUEUE_LIMIT    10
#define  SERVER_RUN     1
#define  LIMIT          2
#define  SERV_FD        0
#define  CLI_FD         1

int         server_handle_client(int fd, char const *ip);
void        server_handshake(struct sockaddr_in *s_client, int c_fd);
int                         server_start(int port);

#endif /* !SERVER_H_ */
