/*
** gclient_threads.c for Zappy in /home/el/Zappy/GClient
**
** Made by oleg kuznietsov
** Login   <kuznet_o@epitech.eu>
**
** Started on  Fri Jun 24 19:45:50 2013 oleg kuznietsov
** Last update Wed May 12 14:58:18 2013 oleg kuznietsov
*/

#include <pthread.h>
#include "gclient_auth.h"
#include "gclient_exit.h"
#include "gclient_funcs.h"
#include "gclient_errors.h"
#include "error.h"
#include "tools.h"

void      *auth(void *arg)
{
  t_auth  *a;
  int     i;

  a = (t_auth *)arg;
  i = 0;
  str_put("Connection accepted. Authentication ...\n");
  while (i != 3)
  {
    sleep(1);
    if (a->pm->auth == 0)
    {
      pthread_mutex_lock(&a->pm->lock);
      str_put("Authentication successful. Conncted to Zappy\n");
      a->pm->auth = 1;
      pthread_mutex_unlock(&a->pm->lock);
      pthread_exit((void *)1);
    }
    ++i;
  }
  error_show("auth", "timeout", "Authentication failed");
  pthread_mutex_lock(&a->pm->lock);
  my_exit(a->pm, 1);
  pthread_exit(NULL);
}

int   ll_auth(char *cmd, t_pm *pm)
{
  if (strcmp(cmd, "BIENVENUE\n") == 0)
  {
    cmd_send(pm, "GRAPHIC\n");
    pthread_mutex_lock(&pm->lock);
    pm->auth = 0;
    pthread_mutex_unlock(&pm->lock);
    while (pm->auth != 1);
  }
  return (1);
}

void  auth_start(t_pm *pm, t_auth *a)
{
  pm->auth = -1;
  a->pm = pm;
  if ((a->pret = pthread_create(&a->th1, NULL, auth, a)) != 0)
    ts_error("auth_start", pm, a->pret);
}
