/*
** select.c for server in /home/hero/zappy/server
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Sat Apr 27 14:58:48 2013 ivan ignatiev
** Last update Thu Jun 06 00:41:54 2013 Marin Alcaraz
*/

#include    "select.h"


static int	select_create_fdset(t_list *users, fd_set *fdset,
				    int maxfd)
{
  int		outfd;
  t_item    *current;

  current = users->head;
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

static int	select_accept_connection(t_list *users, int serverfd)
{
  t_user	*user;

  user = malloc(sizeof(t_user));
  if (user == NULL)
      log_error("Error: unable to allocate memory to new client", -1);
  user->addrlen = sizeof(struct sockaddr_in);
  if ((user->clientfd = accept(serverfd, (struct sockaddr*)&user->addr,
                  &user->addrlen)) < 0)
      log_error("Error: unable to accept new connection", -1);
  strcpy(user->team, "My super team");
  user->connected = PRE_CONNECTED;
  item_pf(users, user, sizeof(t_user));
  printf("[%s] Connected\n", inet_ntoa(user->addr.sin_addr));
  log_access(inet_ntoa(user->addr.sin_addr));
  return (0);
}

static int	select_check_fdset(t_list *users, fd_set *fdset, int sfd)
{
  t_item    *current;

  (void) sfd;
  current = users->head;
  while (current != NULL)
  {
      if (FD_ISSET((((t_user *)(current->cont))->clientfd), fdset))
       {
          perror("");
          log_error("Error: unable to check fdset", -1);
        }
      current = current->next;
  }
  return (0);
}

int			        select_do(t_list *users, int serverfd)
{
  int			    maxfd;
  struct timeval    tv;
  fd_set		    fdset;

  FD_ZERO(&fdset);
  FD_SET(serverfd, &fdset);
  tv.tv_sec = 0;
  tv.tv_usec = 10000;
  maxfd = select_create_fdset(users, &fdset, serverfd);
  if (select(maxfd + 1, &fdset, NULL, NULL, &tv) < 0)
      log_error("Error: can't perform select", -1);
  if (FD_ISSET(serverfd, &fdset))
    return (select_accept_connection(users, serverfd));
  return (select_check_fdset(users, &fdset, serverfd));
}
