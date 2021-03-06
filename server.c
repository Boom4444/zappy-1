/*
** server.c for zappy in /home/ignatiev/Projects/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Tue May 21 09:42:30 2013 Marin Alcaraz
** Last update Sun Jul 14 15:39:35 2013 ivan ignatiev
*/

#include	"main.h"
#include	"list.h"
#include	"options.h"
#include	"connection_utils.h"
#include	"error.h"
#include	"trantor.h"
#include	"server.h"
#include	"users.h"
#include	"request.h"
#include	"answer.h"
#include	"select.h"

int		server_send(int clientfd, char *message)
{
  return (send(clientfd, message, strlen(message),
	       MSG_DONTWAIT | MSG_NOSIGNAL));
}

int			server_init(t_server *s)
{
  struct sockaddr_in	s_in;

  log_show("server_start", "", "Server start");
  if ((s->client_list = list_init()) == NULL
      || (s->team_list = team_list_init(s, s->options.names)) == NULL
      || (s->request_list = list_init()) == NULL
      || (s->answer_list = list_init()) == NULL
      || (s->server_fd = create_socket()) < 0)
    return (-1);
  s->tick = 0;
  s->diff = 0;
  s->players_count = 0;
  s->eggs_count = 0;
  init_sockadd(&s_in, s->options.port);
  if (bind(s->server_fd, (const struct sockaddr *)&s_in,
	   sizeof(s_in)) == -1)
    {
      close(s->server_fd);
      return (error_show("server_start", "bind",
			 "Unable to bind the server socket"));
    }
  return (listen(s->server_fd, QUEUE_LIMIT));
}

int		server_stop(t_server *s, t_world *w)
{
  t_item	*current;

  (void) w;
  current = list_get_head(s->client_list);
  while (current != NULL)
    {
      if (T_USER(current->cont)->clientfd >= 0)
	close(T_USER(current->cont)->clientfd);
      free(current->cont);
      current = current->next;
    }
  close(s->server_fd);
  list_delete(s->client_list);
  list_delete(s->team_list);
  world_destroy(w);
  log_show("server_stop", "", "Server stop");
  return (0);
}

int			server_start(t_server *s, t_world *w)
{
  struct timeval	start_loop;
  struct timeval	stop_loop;
  unsigned long long	elapsedTime;

  s->tick_size = 1000000 / s->options.tdelay;
  while (s->result == 0)
    {
      gettimeofday(&start_loop, NULL);
      users_life_proccess(s, w);
      select_do(s, w);
      cli_requests_process(s, w);
      cli_answers_process(s, &start_loop, s->tick_size);
      gettimeofday(&stop_loop, NULL);
      elapsedTime = (stop_loop.tv_sec - start_loop.tv_sec) * 1000000;
      elapsedTime = elapsedTime + (stop_loop.tv_usec - start_loop.tv_usec);
      if (s->diff)
	log_show("server_start", "", "Last command time : %lf sec. %llu tick",
		 (double) elapsedTime / 1000000.0, s->tick);
      s->diff = 0;
      ++s->tick;
    }
  return (server_stop(s, w));
}
