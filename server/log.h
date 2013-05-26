/*
** log.h for server in /home/hero/zappy/server
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Sun May 26 19:36:20 2013 Marin Alcaraz
** Last update Sun May 26 20:06:47 2013 Marin Alcaraz
*/

#ifndef LOG_H_
# define LOG_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

int     log_error(const char *, int);

#endif /* !LOG_H_ */
