/*
** gclient_ping.c for Zappy in /home/el/Zappy/GClient
**
** Made by oleg kuznietsov
** Login   <kuznet_o@epitech.eu>
**
** Started on  Sun Jul  14 01:54:44 2013 oleg kuznietsov
** Last update  Sun Jul  14 01:54:44 2013 oleg kuznietsov
*/

#include "gclient_exit.h"
#include "tools.h"
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void  my_exit(t_pm *pm, int status)
{
  close(pm->sfd);
  str_put("GClient stop\n");
  if (status == 1)
    exit(EXIT_SUCCESS);
  else
    exit(EXIT_FAILURE);
}

void      *exit_monitor(void *arg)
{
  t_exit  *e;

  e = (t_exit *)arg;
  while (e->es == 0);
  my_exit(e->pm, 1);
}

void  exit_start(t_pm *pm, t_exit *e)
{
  e->pm = pm;
  e->es = 0;
  if ((e->pret = pthread_create(&e->th1, NULL, exit_monitor, e)) != 0)
    ts_error(pm, e->pret);
}
