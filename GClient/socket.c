/*
** socket.c for zappy in /home/ignatiev/Projects/zappy
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Sun Apr 14 03:49:32 2013 ivan ignatiev
** Last update Sat Jul 13 17:30:19 2013 ivan ignatiev
*/

#include "socket.h"
#include <stdlib.h>
#include <string.h>
#include <netdb.h>

static int		socket_hints(struct addrinfo *hints)
{
  struct protoent	*pe;

  memset(hints, 0, sizeof(struct addrinfo));
  hints->ai_family = AF_INET;
  hints->ai_socktype = SOCK_STREAM;
  hints->ai_flags = 0;
  if ((pe = getprotobyname("tcp")) == NULL)
    return (-1);
  hints->ai_protocol = pe->p_proto;
  return (0);
}

static int		socket_addr(struct sockaddr_in *addr,
				    int port)
{
  addr->sin_family = AF_INET;
  addr->sin_addr.s_addr = INADDR_ANY;
  addr->sin_port = htons(port);
  return (0);
}

int			socket_listen(int port)
{
  int			sfd;
  struct protoent	*pe;
  struct sockaddr_in	saddr;

  if ((pe = getprotobyname("tcp")) == NULL
      || (sfd = socket(AF_INET, SOCK_STREAM, pe->p_proto)) < 0
      || socket_addr(&saddr, port) < 0
      || bind(sfd, (struct sockaddr*)&saddr, sizeof(saddr)) < 0
      || listen(sfd, 20) < 0)
    return (-1);
  return (sfd);
}

int               socket_connect(const char *host, const char *port)
{
  int             sfd;
  struct addrinfo hints;
  struct addrinfo	*result;
  struct addrinfo	*rp;

  if (socket_hints(&hints) == -1)
    return (-1);
  if (getaddrinfo(host, port, &hints, &result) == -1)
    return (-1);
  rp = result;
  while (rp != NULL)
  {
    sfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
    if (sfd >= 0 && connect(sfd, rp->ai_addr, rp->ai_addrlen) != -1)
    {
      freeaddrinfo(result);
      return (sfd);
    }
    close(sfd);
    rp = rp->ai_next;
  }
  freeaddrinfo(result); 
  return (-1);
}
