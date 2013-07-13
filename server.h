/*
** server.h for zappy in /home/ignatiev/Projects/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Sun May 26 18:53:05 2013 Marin Alcaraz
** Last update Sat Jul 13 11:35:19 2013 ivan ignatiev
*/

#ifndef SERVER_H_
# define SERVER_H_

# define QUEUE_LIMIT	10
# define SERVER_RUN	1
# define LIMIT		2
# define SERV_FD	0
# define CLI_FD		1
# define LIM_X		30
# define LIM_y		30

typedef struct		s_server
{
  t_list		*client_list;
  t_list		*request_list;
  t_list		*answer_list;
  t_list		*team_list;
  t_opt			options;
  int			server_fd;
  int			diff;
  unsigned long long	tick;
  int			result;
  unsigned long long	tick_size;
  unsigned int		players_count;
  unsigned int		eggs_count;
}			t_server;

int	server_init(t_server *s);
int	server_start(t_server *s, t_world *w);
int	server_stop(t_server *s, t_world *w);
int	server_send(int clientfd, char *message);

#endif /* !SERVER_H_ */
