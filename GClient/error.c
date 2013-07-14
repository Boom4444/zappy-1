/*
** error.c for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Fri Jun 05 16:42:14 2013 Marin Alcaraz
** Last update Sun Jul 14 21:59:56 2013 ivan ignatiev
*/

#include	<time.h>
#include	<unistd.h>
#include	<stdio.h>
#include	"error.h"

void	error_put(char *s)
{
  int	i;

  i = 0;
  while (s[i] != 0)
  {
    write(STDERR_FILENO, &s[i], 1);
    i = i + 1;
  }
}

int		error_log(char *loc, char *func, char *msg)
{
  FILE		*log_stream;
  char		*slog_time;
  time_t	log_time;

  log_stream = fopen("error.log", "a");
  if (log_stream == NULL)
  {
    error_put("Error: 'error_log' fails to store error [");
    fprintf(stderr, "%s fails in %s]\n", func, loc);
    return (-1);
  }
  time(&log_time);
  slog_time = ctime(&log_time);
  slog_time[strlen(slog_time) - 1] = 0;
  fprintf(log_stream, "%s %s [%s]: %s\n", slog_time, loc, func, msg);
  fclose(log_stream);
  return (1);
}

int	error_show(char *loc, char *func, char *msg)
{
  write(STDERR_FILENO, "Error: ", 7);
  error_put(msg);
  write(STDERR_FILENO, "\n", 1);
  if (error_log(loc, func, msg) == -1)
    return (-1);
  return (1);
}
