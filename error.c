/*
** error.c for zappy in /home/ignatiev/Projects/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
* 
** Started on  Fri Mar 15 16:42:14 2013 Marin Alcaraz
** Last update Wed May 29 18:30:31 2013 ivan ignatiev
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
/*
 * TODO : Clear management unit
 *
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
*/

int		error_show(const char *str)
{
  fprintf(stderr, "zappy: %s (%d:%s)\n", str, errno, strerror(errno));
  return (EXIT_FAILURE);
}
