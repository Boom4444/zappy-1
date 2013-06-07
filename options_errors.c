/*
** options_errors.c for Zappy in /home/el/Zappy/Main
**
** Made by oleg kuznietsov
** Login   <kuznet_o@epitech.net>
**
** Started on  Thu Jun  06 22:43:10 2013 oleg kuznietsov
** Last update Fri Jun  07 00:24:15 2013 oleg kuznietsov
*/

#include "options.h"

void  negative_error(char *str, char *ptr)
{
  printf("%s: syntax error -- \"%s\"\n", str, ptr);
  printf("Argument values can only be positive.\n");
  exit(EXIT_SUCCESS);
}

void  eagle_error(char *str)
{
  printf("%s: option requires an argument -- '%c'\n", str, optopt);
  printf("Use \"%s --help\" to get more information.\n", str);
  exit(EXIT_SUCCESS);
}

void  lparse_error_1(char *str)
{
  printf("%s: illegal characters -- \'\\n\'\n", str);
  printf("Server options should contain only '-' combined with a letter.\n");
  printf("Server argumens can contain only letters");
  printf(" and numbers (+ ' ' '_' characters).\n");
  exit(EXIT_SUCCESS);
  
}

void  lparse_error_2(char *str, char c)
{
  printf("%s: illegal characters -- '%c'\n", str, c);
  printf("Server options should contain only '-' combined with a letter.\n");
  printf("Server argumens can contain only letters");
  printf(" and numbers (+ ' ' '_' characters).\n");
  exit(EXIT_SUCCESS);
}

void  syntax_error(char *str, char *ptr)
{
  printf("%s: syntax error -- '%s'\n", str, ptr);
  printf("Use \"%s --help\" to get more information.\n", str);
  exit(EXIT_SUCCESS);
}
