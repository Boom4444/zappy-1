/*
** error.c for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
* 
** Started on  Fri Mar 15 16:42:14 2013 Marin Alcaraz
** Last update Thu Jun 06 15:51:18 2013 Marin Alcaraz
**/

#include "server.h"
#include "error.h"


void        my_errorstr(char *s)
{
    int     i;

    i = 0;
    while (s[i] != '\0')
    {
        write(STDERR_FILENO, &s[i], 1);
        i = i + 1;
    }
}

int     error_show(const char *str)
{
    fprintf(stderr, "Zappy: %s (%d:%s)\n", str, errno, strerror(errno));
    return (EXIT_FAILURE);
}

void    my_error(char *s)
{
        my_errorstr(s);
}

void    my_errorandclose(char *s, int *descriptors)
{
  int   i;

  i = 0;
  while (descriptors[i] != LIMIT)
  {
    if (close(descriptors[i]) == -1)
    {
      perror("");
      my_error("Error: Unable to close socket, socket corrupted\n");
    }
    log_error("Closed FD on ", i);
    i = i + 1;
  }
  my_error(s);
}
