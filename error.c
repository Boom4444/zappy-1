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

   log_stream = fopen("error_log.txt", "a");
   if (log_stream == NULL)
   {
      error_put("'error_log' fails to 'fopen'");
      printf("error info: %s fails in %s\n", func, loc); // ?
      return (-1);
   }
   time(&log_time);
   slog_time = ctime(&log_time);
   slog_time[strlen(slog_time) - 1] = 0;
   fprintf(log_stream, "%s %s: %s: %s\n", slog_time, loc, func, msg);
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
  int     log_fd;
  char    log_msg[256];
  char    *slog_time;
  time_t  log_time;

  log_fd = open("access_log.txt", O_CREAT | O_WRONLY | O_APPEND, 0666);
  if (log_fd == -1)
  {
    error_log("log_access", "open", strerror(errno));
    return (-1);
  }
  time(&log_time);
  slog_time = ctime(&log_time);
  slog_time[strlen(slog_time) - 1] = '\0';
  sprintf(log_msg, "%s Connection accepted from %s\n",  slog_time, ip);
  write(log_fd, log_msg, strlen(log_msg));
  close(log_fd);
  return(1);
}

/*
** TODO: to be updated
*/ 
int       log_command(t_user *user, char *cmd)
{
  FILE    *log_stream;
  char    *slog_time;
  time_t  log_time;

  log_stream = fopen("command_log.txt", "a");
  if (log_stream == NULL)
  {
    error_log("log_command", "fopen", strerror(errno));
    return (-1);
  }
  time(&log_time);
  slog_time = ctime(&log_time);
  slog_time[strlen(slog_time) - 1] = 0;
  fprintf(log_stream, "%s %s (%s): %s\n", 
  slog_time, 
  inet_ntoa(user->addr.sin_addr), 
  user->team, cmd);
  fclose(log_stream);
  return (1);
}

// void    my_errorandclose(char *s, int *descriptors)
// {
//   int   i;

//   i = 0;
//   while (descriptors[i] != LIMIT)
//   {
//     if (close(descriptors[i]) == -1)
//     {
//       perror("");
//       my_error("Error: Unable to close socket, socket corrupted\n");
//     }
//     log_error("Closed FD on ", i);
//     i = i + 1;
//   }
//   my_error(s);
// }
