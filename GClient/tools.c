/*
** tools.c for Zappy in /home/el/GitHub/zappy/GClient
**
** Made by oleg kuznietsov
** Login   <kuznet_o@epitech.eu>
**
** Started on  Sun Jul  14 21:23:19 2013 oleg kuznietsov
** Last update  Sun Jul  14 21:23:19 2013 oleg kuznietsov
*/

#include "tools.h"

int   str_put(char *s)
{
  int i;

  i = 0;
  while (s[i] != 0)
  {
    if (write(1, &s[i], 1) == -1)
      return (-1);
    ++i;
  }
  return (1);
}
