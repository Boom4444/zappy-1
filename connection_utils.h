/*
** connection_utils.h for zappy in /home/hero/zappy
** 
* Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Thu Apr 11 19:11:16 2013 Marin Alcaraz
** Last update Tue May 21 09:42:14 2013 Marin Alcaraz
*/

#ifndef CONNECTION_UTILS_H_
# define CONNECTION_UTILS_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "error.h"

#define SERVER      1
#define CLIENT      2
#define MAX_PEERS   3


void    init_sockadd(struct sockaddr_in *, int);
int     create_socket(void);

#endif /* !CONNECTION_UTILS_H_ */
