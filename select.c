/*
** select.c for zappy in /home/ignatiev/Projects/zappy
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Sat Apr 27 14:58:48 2013 ivan ignatiev
** Last update Thu Jul 04 16:31:06 2013 ivan ignatiev
*/

#include    "select.h"

static int	select_create_fdset(t_server *s, fd_set *fdset, int maxfd)
{
  int		outfd;
  t_item    *current;

  current = (s->client_list)->head;
  while (current != NULL)
  {
      if (maxfd < T_USER(current->cont)->clientfd)
          maxfd = T_USER(current->cont)->clientfd;
      outfd = T_USER(current->cont)->clientfd;
      FD_SET(outfd, fdset);
      current = current->next;
  }
  return (maxfd);
}

t_user      *user_init()
{
    t_user  *user;

    if ((user = (t_user*)malloc(sizeof(t_user))) != NULL)
    {
        strcpy(user->team, "My super team");
        user->connected = PRE_CONNECTED;
        user->request = NULL;
        user->request_counter = 0;
        user->tick = 0;
        user->addrlen = sizeof(struct sockaddr_in);
    }
    return (user);
}

static int	select_accept_connection(t_server *s, t_world *w)
{
  t_user	*user;

  if ((user = user_init()) == NULL)
      return (error_log("select_accept_connection", "user_init",
        "unable to allocate memory to new client"));
  if ((user->clientfd =
              accept(s->server_fd, (struct sockaddr*)&user->addr,&user->addrlen)) < 0)
      error_log("select_accept_connection", "accept", strerror(errno));
  item_pf(s->client_list, (void*)user, sizeof(t_user));
  printf("[%s] Connected\n", inet_ntoa(user->addr.sin_addr));
  server_handshake(user->clientfd);
  log_access(inet_ntoa(user->addr.sin_addr));
  (void) (w);
  return (0);
}

static int	select_check_fdset(t_server *s, t_world *w, fd_set *fdset)
{
  t_item    *current;

  current = (s->client_list)->head;
  while (current != NULL)
  {
      if (FD_ISSET((T_USER((current->cont))->clientfd), fdset))
      {
          if(T_USER(current->cont)->connected == PRE_CONNECTED)
              proto_define(T_USER(current->cont), w);
          else if(T_USER(current->cont)->connected == CONNECTED)
              proto_parse(T_USER(current->cont), s, w);
      }
      current = current->next;
  }
  return (0);
}

int			        select_do(t_server *s, t_world *w)
{
  int			    maxfd;
  struct timeval    tv;
  fd_set		    fdset;

  FD_ZERO(&fdset);
  FD_SET(s->server_fd, &fdset);
  tv.tv_sec = 0;
  tv.tv_usec = 10;
  maxfd = select_create_fdset(s, &fdset, s->server_fd);
  if (select(maxfd + 1, &fdset, NULL, NULL, &tv) < 0)
      return (error_log("select_do", "select", strerror(errno)));
  if (FD_ISSET(s->server_fd, &fdset))
    return (select_accept_connection(s, w));
  return (select_check_fdset(s, w, &fdset));
}
