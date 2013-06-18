/*
** error.c for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
* 
** Started on  Fri Mar 15 16:42:14 2013 Marin Alcaraz
** Last update Thu Jun 06 15:51:18 2013 oleg kuznietsov
**/

#include "error.h"

void  error_put(char *s)
{
  int i;

  i = 0;
  write(STDERR_FILENO, "Error: ", 7);
  while (s[i] != 0)
  {
    write(STDERR_FILENO, &s[i], 1);
    i = i + 1;
  }
}

int       error_log(char *loc, char *func, char *msg)
{
  FILE    *log_stream;
  char    *slog_time;
  time_t  log_time;

  log_stream = fopen("error.log", "a");
  if (log_stream == NULL)
  {
    error_put("'error_log' fails to store error [ ");
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

int   error_show(char *loc, char *func, char *msg)
{
  error_put(msg);
  if (error_log(loc, func, msg) != -1)
    return 1;
  else
    return -1;
}

int       log_access(const char *ip)
{
  FILE    *log_stream;
  char    *slog_time;
  time_t  log_time;

  log_stream = fopen("access.log", "a");
  if (log_stream == NULL)
  {
    error_log("log_access", "fopen", strerror(errno));
    return (-1);
  }
  time(&log_time);
  slog_time = ctime(&log_time);
  slog_time[strlen(slog_time) - 1] = 0;
  fprintf(log_stream, "%s Connection accepted from %s\n",  slog_time, ip);
  fclose(log_stream);
  return (1);
}

int       log_command(char *user_name, char *cmd, int dir)
{
  FILE    *log_stream;
  char    *slog_time;
  time_t  log_time;

  log_stream = fopen("command.log", "a");
  if (log_stream == NULL)
  {
    error_log("log_command", "fopen", strerror(errno));
    return (-1);
  }
  time(&log_time);
  slog_time = ctime(&log_time);
  slog_time[strlen(slog_time) - 1] = 0;
  if (dir == 0)
    fprintf(log_stream, 
      "%s Sending [%s] from server to \"%s\"\n", 
      slog_time, cmd, user_name);
  if (dir == 1)
    fprintf(log_stream, 
      "%s Sending [%s] from \"%s\" to server\n", 
      slog_time, cmd, user_name);
  else
    return (-1);
  fclose(log_stream);
  return (1);
}
