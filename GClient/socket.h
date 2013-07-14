/*
** socket.h for my_ftp in /home/ignati_i//projects/my_ftp/common
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Sun Apr 14 04:01:11 2013 ivan ignatiev
** Last update Sun Apr 14 11:36:21 2013 ivan ignatiev
*/

#ifndef SOCKET_H_
# define SOCKET_H_

#include <sys/types.h>
#include <sys/socket.h>

int	socket_listen(int port);
int	socket_connect(const char *host, const char *port);

#endif /* !SOCKET_H_ */
