/*
** gclient_ping.c for Zappy in /home/el/Zappy/GClient
**
** Made by oleg kuznietsov
** Login   <kuznet_o@epitech.eu>
**
** Started on  Sun Jul  14 01:54:44 2013 oleg kuznietsov
** Last update Sun Jul 14 22:07:53 2013 ivan ignatiev
*/

#include	<pthread.h>
#include	"gclient_ping.h"
#include	"gclient_funcs.h"
#include	"gclient_exit.h"
#include	"gclient_errors.h"
#include	"socket.h"
#include	"error.h"
#include	"tools.h"

void		*ping_end(void *arg)
{
  t_ping	*p;

  p = (t_ping *)arg;
  while (42)
    {
      sleep(6);
      pthread_mutex_lock(&p->pm->lock);
      p->pm->auth = 0;
      pthread_mutex_unlock(&p->pm->lock);
    }
}

void		ping_save(t_pm *pm)
{
  pthread_mutex_lock(&pm->lock);
  pm->auth = 1;
  pthread_mutex_unlock(&pm->lock);
}

void		*ping(void *arg)
{
  t_ping	*p;

  p = (t_ping*)arg;
  while (p->pm->auth != 1);
  while (42)
    {
      sleep(3);
      if (p->pm->auth == 0)
	{
	  cmd_send(p->pm, "mct\n");
	  sleep(2);
	  if (p->pm->auth == 0)
	    {
	      error_show("ping", "pm->auth == 0", "Server is not responding");
	      pthread_mutex_lock(&p->pm->lock);
	      my_exit(p->pm, 1);
	    }
	}
    }
}

void		ping_start(t_pm *pm, t_ping *p)
{
  p->pm = pm;
  if ((p->pret = pthread_create(&p->th1, NULL, ping, p)) != 0)
    ts_error("ping_start", pm, p->pret);
  if ((p->pret = pthread_create(&p->th2, NULL, ping_end, p)) != 0)
    ts_error("ping_end", pm, p->pret);
}
