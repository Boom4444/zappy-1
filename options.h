/*
** options.h for zappy in /home/ignatiev/Projects/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Fri Mar 15 16:48:12 2013 Marin Alcaraz
** Last update Fri Jul 05 18:26:48 2013 ivan ignatiev
*/

#ifndef OPTIONS_H_
# define OPTIONS_H_

typedef struct  s_opt
{
  unsigned int  port;
  unsigned int  width;
  unsigned int  height;
  t_list        *names;
  unsigned int  cmax;
  unsigned int  tdelay;
}               t_opt;

int     get_nbrlen(int nbr);
void    the_parse(int argc, char *argv[]);
void    invalid_find(int argc, char *argv[]);

/* default number of teams */
void    teams_fill(t_opt *opt, int n);

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
void    options_get(char *argv[], char c, unsigned int *opt);
void    options_parse(int argc, char *argv[], t_opt *g_opt);

#endif /* OPTIONS_H_ */
