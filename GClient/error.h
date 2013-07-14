/*
** error.c for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
* 
** Started on  Fri Jun 05 16:42:14 2003 Marin Alcaraz
** Last update Thu Mar 03 15:51:18 2001 oleg kuznietsov
**/

#ifndef ERROR_H_
# define ERROR_H_

#include <string.h>
#include <errno.h>

void  error_put(char *s);
int   error_log(char *loc, char *func, char *msg);
int   error_show(char *loc, char *func, char *msg);

#endif /* !ERROR_H_ */
