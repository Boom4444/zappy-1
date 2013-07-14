/*
** gclient_funcs.c for Zappy in /home/el/Zappy/GClient
**
** Made by oleg kuznietsov
** Login   <kuznet_o@epitech.eu>
**
** Started on  Fri Jun 24 19:45:50 2013 oleg kuznietsov
** Last update Wed May 12 14:58:18 2013 oleg kuznietsov
*/

#include <stdio.h>
#include <time.h>
#include "gclient_funcs.h"
#include "gclient_exit.h"
#include "gclient_errors.h"
#include "socket.h"
#include "error.h"
#include "tools.h"

void  cmd_send(t_pm *pm, char *cmd)
{
  if (send(pm->sfd, cmd, strlen(cmd), MSG_DONTWAIT) == -1)
  {
    if (errno == 9)
    {
      error_show("cmd_send", "errno == 9", "Connection has been aborted");
      my_exit(pm, 1);
    }
    else
    {
      error_show("cmd_send", "errno != 9", strerror(errno));
      my_exit(pm, -1);
    }
  }
}

int   nsp_get(char *str)
{
  int i;
  int c;

  c = 0;
  i = 0;
  while (str[i] != 0)
  {
    if (str[i] == ' ')
      ++c;
    ++i;
  }
  return (c);
}

void        cmd_put(int i, char *cmd)
{
  time_t    t;
  struct tm s;

  t = time(NULL);
  s = *localtime(&t);
  if (i == 1)
    printf("\e[1;36mprocessed\e[m [%d:%d:%d]: \e[1;36mm%s\e[m",
          s.tm_hour, s.tm_min, s.tm_sec, cmd);
  else
    printf("\e[1;31m failed\e[m   [%d:%d:%d]: \e[1;31m%s\e[m",
          s.tm_hour, s.tm_min, s.tm_sec, cmd);
}

void  select_monitor(fd_set *fd_rs, t_ppo *p, t_pm *pm)
{
  if (select(pm->sfd + 1, fd_rs, NULL, NULL, NULL) == -1)
    cp_error(pm, "select", strerror(errno));
  else if ((p->tlen = read(pm->sfd, p->tbuf, 1000)) == -1)
    cp_error(pm, "read", strerror(errno));
  else if (p->tlen == 0)
    cp_error(pm, "r == 0", "Connection has been aborted");
}
