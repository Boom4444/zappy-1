/*
** error.h for zappy in /home/ignatiev/Projects/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Fri Mar 15 16:48:12 2013 Marin Alcaraz
** Last update Wed May 29 18:21:39 2013 ivan ignatiev
*/

#ifndef ERROR_H_
# define ERROR_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

void my_errorstr(char *);
int		error_show(const char *str);
void my_error(char *);
void my_errorandclose(char *, int *);

#endif /* !ERROR_H_ */
