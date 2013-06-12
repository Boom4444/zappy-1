/*
** select.c for zappy in /home/hero/zappy
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Sat Apr 27 14:58:48 2013 ivan ignatiev
** Last update Wed Jun 12 15:36:15 2013 Marin Alcaraz
*/

#include    "select.h"


static int	select_create_fdset(t_server *s, fd_set *fdset, int maxfd)
{
  int		outfd;
  t_item    *current;

  current = (s->client_list)->head;
  while (current != NULL)
  {
      if (maxfd < ((t_user *)(current->cont))->clientfd)
          maxfd = ((t_user *)(current->cont))->clientfd;
      outfd = ((t_user *)(current->cont))->clientfd;
      FD_SET(outfd, fdset);
      current = current->next;
  }
  return (maxfd);
}

static int	select_accept_connection(t_server *s, t_world *w)
{
  t_user	*user;

  user = malloc(sizeof(t_user));
  if (user == NULL)
      return (log_error("Error: unable to allocate memory to new client", -1));
  user->addrlen = sizeof(struct sockaddr_in);
  if ((user->clientfd =
              accept(s->server_fd, (struct sockaddr*)&user->addr,&user->addrlen)) < 0)
      log_error("Error: unable to accept new connection", -1);
  strcpy(user->team, "My super team");
  user->connected = PRE_CONNECTED;
  item_pf(s->client_list, user, sizeof(t_user));
  printf("[%s] Connected\n", inet_ntoa(user->addr.sin_addr));
  server_handshake(user->clientfd);
  log_access(inet_ntoa(user->addr.sin_addr));
  (void) (w);
  return (0);
}

static int	select_check_fdset(t_server *s, t_world *w, fd_set *fdset)
{
  t_item    *current;
  int       len;
  char      buf[255];

  current = (s->client_list)->head;
  while (current != NULL)
  {
      if (FD_ISSET((((t_user *)(current->cont))->clientfd), fdset))
           len = read((((t_user *)(current->cont))->clientfd), buf, 255);
      current = current->next;
  }
  (void) (len); /** READ FULL MESSAGE ?? **/
  (void) (w);
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
  tv.tv_usec = 10000;
  maxfd = select_create_fdset(s, &fdset, s->server_fd);
  if (select(maxfd + 1, &fdset, NULL, NULL, &tv) < 0)
      return (log_error("Error: can't perform select", -1));
  if (FD_ISSET(s->server_fd, &fdset))
    return (select_accept_connection(s, w));
  return (select_check_fdset(s, w, &fdset));
}
