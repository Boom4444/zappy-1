/*
** server_functions.h for server in /home/hero/zappy/server
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Wed May 29 19:31:19 2013 Marin Alcaraz
** Last update Wed May 29 19:49:14 2013 Marin Alcaraz
*/

#ifndef SERVER_FUNCTIONS_H_
# define SERVER_FUNCTIONS_H_

#include "server.h"
#include "connection_utils.h"
#include "error.h"
#include "error.h"

char    *server_getTNumber();
char    *server_getXY();
int     server_welcome_msg(int fd);

#endif /* !SERVER_FUNCTIONS_H_ */
