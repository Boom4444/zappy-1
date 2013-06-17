/*
** connection_utils.c for server in /home/hero/zappy/server
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Thu Apr 11 19:09:26 2013 Marin Alcaraz
** Last update Fri May 24 19:18:18 2013 Marin Alcaraz
*/

#include "connection_utils.h"

void    init_sockadd(struct sockaddr_in *sa, int port)
{
    sa->sin_family = AF_INET;
    sa->sin_port = htons(port);
    (sa->sin_addr).s_addr = INADDR_ANY;
}

int         create_socket(void)
{
  int       fd;
  struct    protoent    *pe;

  pe = getprotobyname("TCP");
  if (pe == (void *)-1)
    error_log("create_socket", "getprotobyname", 
      "Error obtaining protocol, unable to create socket\n");
  fd = socket(AF_INET, SOCK_STREAM, pe->p_proto);
  if (fd == -1)
    error_log("create_socket", "getprotobyname", strerror(errno));
  return (fd);
}
