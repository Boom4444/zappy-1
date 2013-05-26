/*
** error.h for my_ftp in /home/hero/Dropbox/EPITECH/II/UNIX System/my_ftp
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Fri Mar 15 16:48:12 2013 Marin Alcaraz
** Last update Thu Apr 11 20:02:56 2013 Marin Alcaraz
*/

#ifndef ERROR_H_
# define ERROR_H_

#include <stdlib.h>
#include <unistd.h>
#include "server.h"
#include "connection_utils.h"

void my_errorstr(char *);
void my_error(char *);
void my_errorandclose(char *, int *);

#endif /* !ERROR_H_ */
