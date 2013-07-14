/*
** gclient_ping.h for Zappy in /home/el/Zappy/GClient
**
** Made by oleg kuznietsov
** Login   <kuznet_o@epitech.eu>
**
** Started on  Sun Jul  14 01:54:50 2013 oleg kuznietsov
** Last update  Sun Jul  14 01:54:50 2013 oleg kuznietsov
*/

#ifndef GCLIENT_CTIMEOUT_H_
# define GCLIENT_CTIMEOUT_H_

#include "gclient.h"
#include <pthread.h>

typedef struct    s_ctimeout_args
{
  int             cto;
  int             pret;
  t_pm            *pm;
  pthread_t       th1;
}                 t_cto;

void  *ctimeout(void *arg);
void  ctimeout_start(t_pm *pm, t_cto *c);

#endif /* !GCLIENT_CTIMEOUT_H_ */
