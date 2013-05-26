/*
** error.c for server in /home/hero/zappy/server
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
* 
** Started on  Fri Mar 15 16:42:14 2013 Marin Alcaraz
** Last update Sun May 26 19:30:49 2013 Marin Alcaraz
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
