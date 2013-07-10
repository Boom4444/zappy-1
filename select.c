/*
** select.c for zappy in /home/ignatiev/Projects/zappy
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Sat Apr 27 14:58:48 2013 ivan ignatiev
** Last update Wed Jul 10 18:24:11 2013 ivan ignatiev
*/

#include        "main.h"
#include        "list.h"
#include        "options.h"
#include        "trantor.h"
#include        "server.h"
#include        "error.h"
#include        "users.h"
#include        "proto.h"
#include        "select.h"

static int	select_create_fdset(t_server *s, fd_set *fdset, int maxfd)
{
  int		outfd;
  t_item        *current;

  current = (s->client_list)->head;
  while (current != NULL)
  {
      if (T_USER(current->cont)->clientfd >= 0)
      {
        if (maxfd < T_USER(current->cont)->clientfd)
                maxfd = T_USER(current->cont)->clientfd;
        outfd = T_USER(current->cont)->clientfd;
        FD_SET(outfd, fdset);
      }
      current = current->next;
  }
  return (maxfd);
}

static int	select_accept_connection(t_server *s)
{
    t_user	*user;

    if ((user = user_create()) == NULL)
        return (error_show("select_accept_connection", "user_create",
                    "Unable to allocate memory to new client"));
    if ((user->clientfd = accept(s->server_fd,
                    (struct sockaddr*)&user->addr,&user->addrlen)) < 0)
        error_show("select_accept_connection", "accept", "Unable to accept client");
    item_pf(s->client_list, (void*)user, sizeof(t_user));
    log_show("select_accept_connection", "accept",
            "User %s connected to the server", inet_ntoa(user->addr.sin_addr));
    server_handshake(user->clientfd);
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
              current->cont = (void*)proto_define(T_USER(current->cont), s, w);
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
  tv.tv_usec = 1;
  maxfd = select_create_fdset(s, &fdset, s->server_fd);
  if (select(maxfd + 1, &fdset, NULL, NULL, &tv) < 0)
      return (error_show("select_do", "select", "Unable select current FDSET"));
  if (FD_ISSET(s->server_fd, &fdset))
    return (select_accept_connection(s));
  return (select_check_fdset(s, w, &fdset));
}
