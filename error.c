/*
** error.c for zappy in /home/ignati_i/zappy/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
* 
** Started on  Fri Mar 15 16:42:14 2013 Marin Alcaraz
** Last update Sat Jul 13 20:32:29 2013 ivan ignatiev
**/

#include	"main.h"
#include	"list.h"
#include	"options.h"
#include	"trantor.h"
#include	"server.h"
#include	"users.h"
#include	"error.h"

int		error_show(char *loc, char *func, char *msg, ...)
{
  va_list	ap;
  time_t	log_time;
  char		str_time[255];

  va_start(ap, msg);
  time(&log_time);
  ctime_r(&log_time, str_time);
  str_time[strlen(str_time) - 1] = '\0';
  fprintf(stderr, "\e[1;31mERROR [%s %s in %s] : ", str_time, func, loc);
  vfprintf(stderr, msg, ap);
  fprintf(stderr, " (%d : %s) \e[m\n", errno, strerror(errno));
  errno = 0;
  va_end(ap);
  return (-1);
}

int		log_show(char *loc, char *func, char *msg, ...)
{
  va_list	ap;
  time_t	log_time;
  char		str_time[255];

  va_start(ap, msg);
  time(&log_time);
  ctime_r(&log_time, str_time);
  str_time[strlen(str_time) - 1] = '\0';
  fprintf(stdout, "\e[1;36mINFO  [%s %s in %s] : ", str_time, func, loc);
  vfprintf(stdout, msg, ap);
  fprintf(stdout, "\e[m\n");
  va_end(ap);
  return (0);
}
