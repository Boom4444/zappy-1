/*
** socket.h for Zappy in /home/el/Zappy/GClient
**
** Made by oleg kuznietsov
** Login   <kuznet_o@epitech.eu>
**
** Started on  Sun Jul  14 12:27:10 2013 oleg kuznietsov
** Last update  Sun Jul  14 12:27:10 2013 oleg kuznietsov
*/

#ifndef SOCKET_H_
# define SOCKET_H_

#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>

typedef struct        s_socket_options
{
  struct protoent     *pe;
  int                 fd;
  struct sockaddr_in  s_in;
  int                 port;
  const char          *ip;
}                     t_so;

int   socket_connect(const char *ht, const char *pr);

#endif /* !SOCKET_H_ */
