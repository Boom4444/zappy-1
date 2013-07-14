/*
** socket.c for Zappy in /home/el/Zappy/GClient
**
** Made by oleg kuznietsov
** Login   <kuznet_o@epitech.eu>
**
** Started on  Sun Jul  14 12:27:00 2013 oleg kuznietsov
** Last update  Sun Jul  14 12:27:00 2013 oleg kuznietsov
*/

#include "socket.h"
#include "error.h"

int     socket_connect(const char *ht, const char *pr)
{
  t_so  s;

  s.ip = ht;
  s.port = atoi(pr);
  s.s_in.sin_family = AF_INET;
  s.s_in.sin_port = htons(s.port);
  s.s_in.sin_addr.s_addr = inet_addr(s.ip);
  if (!(s.pe = getprotobyname("TCP")))
  {
    error_show("socket_connect", "getprotobyname", strerror(errno));
    return -1;
  }
  if ((s.fd = socket(AF_INET, SOCK_STREAM, s.pe->p_proto)) == -1)
  {
    error_show("socket_connect", "socket", strerror(errno));
    return -1;
  }
  if (connect(s.fd, (struct sockaddr*)&s.s_in, sizeof(s.s_in)) == -1)
  {
    error_show("socket_connect", "connect", strerror(errno));
    close(s.fd);
    return -1;
  }
  endprotoent();
  return (s.fd);
}
