/*
** error.h for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Fri Mar 15 16:48:12 2013 Marin Alcaraz
** Last update Thu Jun 06 15:52:11 2013 Marin Alcaraz
*/

#ifndef ERROR_H_
# define ERROR_H_

#include <stdlib.h>
#include <unistd.h>
#include "server.h"
#include "log.h"
#include "connection_utils.h"

void my_errorstr(char *);
int  error_show(const char *);
void my_error(char *);
void my_errorandclose(char *, int *);

#endif /* !ERROR_H_ */
