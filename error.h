/*
** error.h for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Fri Mar 15 16:48:12 2013 Marin Alcaraz
** Last update Thu Jun  06 22:28:48 2013 oleg kuznietsov
*/

#ifndef ERROR_H_
# define ERROR_H_

#include "users.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

/* Use this only in special cases */
void  error_put(char *s);

/* Example: error_log("main", "open", strerror(errno)); */
int   error_log(char *loc, char *func, char *msg);

/* For displaying and loging at the same time */
int   error_show(char *loc, char *func, char *msg);

/* dir is direction to 1 (server) or 0 (client) */
int   log_command(char *user_name, char *cmd, int dir);

int   log_access(const char *ip);

#endif /* !ERROR_H_ */
