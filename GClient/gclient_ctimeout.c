/*
** gclient_ping.c for Zappy in /home/el/Zappy/GClient
**
** Made by oleg kuznietsov
** Login   <kuznet_o@epitech.eu>
**
** Started on  Sun Jul  14 01:54:44 2013 oleg kuznietsov
** Last update  Sun Jul  14 01:54:44 2013 oleg kuznietsov
*/

#include "gclient_ctimeout.h"
#include "tools.h"
#include <pthread.h>
#include <stdlib.h>

void      *ctimeout(void *arg)
{
  t_cto   *c;

  c = (t_cto *)arg;
  sleep(5);
  if (c->cto != 1)
  {
    error_show("ctimeout", "c->cto != 1", "Connection failed");
    str_put("GClient stop\n");
    exit(EXIT_SUCCESS);
  }
}

void  ctimeout_start(t_pm *pm, t_cto *c)
{
  c->pm = pm;
  c->cto = -1;
  if ((c->pret = pthread_create(&c->th1, NULL, ctimeout, c)) != 0)
    ts_error(pm, c->pret);
}
