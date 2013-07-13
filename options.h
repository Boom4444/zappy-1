/*
** options.h for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Fri Mar 15 16:48:12 2013 Marin Alcaraz
** Last update Fri Jul 12 21:47:45 2013 Marin Alcaraz
*/

#ifndef OPTIONS_H_
# define OPTIONS_H_

typedef struct	s_opt
{
  unsigned int	port;
  unsigned int	width;
  unsigned int	height;
  t_list	*names;
  unsigned int	cmax;
  unsigned int  mode;
  unsigned int	tdelay;
}		t_opt;

void	the_parse(int argc, char *argv[]);
void	invalid_find(int argc, char *argv[]);
void	teams_fill(t_opt *opt, int n);
void	options_getopt(int argc, char *argv[], t_opt *g_opt);
void	negative_error(char *str, char *ptr);
void	eagle_error(char *str);
void	lparse_error_1(char *str);
void	lparse_error_2(char *str, char c);
void	syntax_error(char *str, char *ptr);
void	usage_display(char *);
void	default_error(char *argv[]);
void	names_parse(char *argv[], char c, int argc, t_opt *opt);
void	options_get(char *argv[], char c, unsigned int *opt);
void	options_parse(int argc, char *argv[], t_opt *g_opt);

#endif /* OPTIONS_H_ */
