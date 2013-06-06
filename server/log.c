/*
** log.c for server in /home/hero/zappy/server
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Sun May 26 19:31:09 2013 Marin Alcaraz
** Last update Wed May 29 19:31:46 2013 Marin Alcaraz
*/

#include "log.h"
#include "server.h"


int         log_error(const char *msg, int info)
{
   int      log_fd;
   char     log_msg[256];
   char     *slog_time;
   char     *error_msg;
   time_t   log_time;

   log_fd = open("error_log.txt", O_CREAT | O_WRONLY | O_APPEND, 0666);
   if (log_fd == -1)
   {
       error_msg = strdup("can't open error_log.txt\n");
       write(STDIN_FILENO, error_msg, strlen(error_msg));
       return (-1);
   }
   time(&log_time);
   slog_time = ctime(&log_time);
   slog_time[strlen(slog_time) - 1] = '\0';
   sprintf(log_msg, "%s %s %d]\n",  slog_time, msg, info);
   write(log_fd, log_msg, strlen(log_msg));
   close(log_fd);
   return(1);
}

int         log_access(const char *ip)
    {
   int      log_fd;
   char     log_msg[256];
   char     *slog_time;
   char     *error_msg;
   time_t   log_time;

   log_fd = open("access_log.txt", O_CREAT | O_WRONLY | O_APPEND, 0666);
   if (log_fd == -1)
   {
       error_msg = strdup("can't open access_log.txt\n");
       write(STDIN_FILENO, error_msg, strlen(error_msg));
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
