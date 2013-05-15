/*
** error.c for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
* 
** Started on  Fri Mar 15 16:42:14 2013 Marin Alcaraz
** Last update Wed May 15 18:09:55 2013 Marin Alcaraz
**/

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
        exit(0);
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
    i = i + 1;
  }
  my_error(s);
}
