/*
** server.h for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Wed Apr 10 22:57:25 2013 Marin Alcaraz
** Last update Wed May 15 17:20:20 2013 Marin Alcaraz
*/

#ifndef SERVER_H_
# define SERVER_H_

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include "connection_utils.h"
#define QUEUE_S 42
#define SERVER  1

int     server(int);
int     handle_client(int, char const *);
int     is_valid_fd(int);

#endif /* !SERVER_H_ */
