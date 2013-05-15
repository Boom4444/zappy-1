/*
** connection_utils.c for my_ftp in /home/hero/Dropbox/EPITECH/II/UNIX System/my_ftp
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Thu Apr 11 19:09:26 2013 Marin Alcaraz
** Last update Thu Apr 11 19:42:14 2013 Marin Alcaraz
*/

#include "connection_utils.h"

void    init_sockadd(struct sockaddr_in *sa, int port, int mode, char *ip)
{
    sa->sin_family = AF_INET;
    sa->sin_port = htons(port);
    if (mode == CLIENT)
      (sa->sin_addr).s_addr = inet_addr(ip);
    else
    {
      (sa->sin_addr).s_addr = INADDR_ANY;
      (void) ip;
    }
}

int         create_socket(void)
{
  int       fd;
  struct    protoent    *pe;

  pe = getprotobyname("TCP");
  if (pe == (void *)-1)
    my_error("Error obtaining protocol, unable to create socket\n");
  fd = socket(AF_INET, SOCK_STREAM, pe->p_proto);
  if (fd == -1)
    my_error("Error creating socket\n");
  return (fd);
}
