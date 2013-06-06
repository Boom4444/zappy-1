/*
** options.h for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Fri Mar 15 16:48:12 2013 Marin Alcaraz
** Last update Thu Jun 06 11:12:32 2013 Marin Alcaraz
*/

#ifndef MAIN_H_
# define MAIN_H_

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include "list.h"

typedef struct  s_options
{
  int           port;
  int           width;
  int           height;
  t_list        *names;
  int           cmax;
  int           tdelay;
}               t_opt;

int     get_nbrlen(int nbr);
void    the_parse(int argc, char *argv[]);
void    invalid_find(int argc, char *argv[]);
void    teams_fill(t_opt *opt);
int     get_nbrlen(int nbr);
void    options_getopt(int argc, char *argv[], t_opt *g_opt);
void    negative_error(char *str, char *ptr);
void    eagle_error(char *str);
void    lparse_error_1(char *str);
void    lparse_error_2(char *str, char c);
void    syntax_error(char *str, char *ptr);
void    usage_display(char *);
void    default_error(char *argv[]);
void    names_parse(char *argv[], char c, int argc, t_opt *opt);
void    options_get(char *argv[], char c, int *opt);
void    options_parse(int argc, char *argv[], t_opt *g_opt);

#endif /* MAIN_H_ */