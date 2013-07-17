/*
** gclient_errors.c for Zappy in /home/el/Zappy/GClient
**
** Made by oleg kuznietsov
** Login   <kuznet_o@epitech.eu>
**
** Started on  Fri Jun 24 19:45:50 2003 oleg kuznietsov
** Last update Sun Jul 14 22:11:47 2013 ivan ignatiev
*/

#include	"gclient_errors.h"
#include	"gclient_funcs.h"
#include	"gclient_exit.h"
#include	"error.h"

void		cp_error(t_pm *pm, char *loc, char *msg)
{
  error_show("client_prompt", loc, msg);
  if (strcmp("r == 0", loc) == 0)
    my_exit(pm, 1);
  else
    my_exit(pm, -1);
}

void		ts_error(char *loc, t_pm *pm, int ret)
{
  error_show(loc, "pthread_create", strerror(ret));
  my_exit(pm, -1);
}

int		bp_error(t_pm *pm)
{
  cmd_send(pm, "mct\n");
  return (-1);
}
