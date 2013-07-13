/*
** connection_utils.c for zappy in /home/ignatiev/Projects/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Thu Apr 11 19:09:26 2013 Marin Alcaraz
** Last update Sat Jul 13 17:46:59 2013 ivan ignatiev
*/

#include		"main.h"
#include		"error.h"
#include		"connection_utils.h"

void			init_sockadd(struct sockaddr_in *sa, int port)
{
  sa->sin_family = AF_INET;
  sa->sin_port = htons(port);
  (sa->sin_addr).s_addr = INADDR_ANY;
}

int			create_socket(void)
{
  int			fd;
  struct protoent	*pe;

  pe = getprotobyname("TCP");
  if (pe == (void *)-1)
    return (error_show("create_socket", "getprotobyname",
		       "Error obtaining protocol, unable to create socket\n"));
  if ((fd = socket(AF_INET, SOCK_STREAM, pe->p_proto)) < 0)
    return (error_show("create_socket", "getprotobyname",
		       "Unable create a socket"));
  return (fd);
}
