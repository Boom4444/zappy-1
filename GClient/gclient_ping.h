/*
** gclient_ping.h for Zappy in /home/el/Zappy/GClient
**
** Made by oleg kuznietsov
** Login   <kuznet_o@epitech.eu>
**
** Started on  Sun Jul  14 01:54:50 2013 oleg kuznietsov
** Last update  Sun Jul  14 01:54:50 2013 oleg kuznietsov
*/

#ifndef GCLIENT_PING_H_
# define GCLIENT_PING_H_

#include "gclient.h"
#include <pthread.h>

typedef struct    s_ping_args
{
  t_pm            *pm;
  int             pret;
  pthread_t       th1;
  pthread_t       th2;
}                 t_ping;

void  *ping_end(void *arg);
void  ping_save(t_pm *pm);
void  *ping(void *arg);
void  ping_start(t_pm *pm, t_ping *p);

#endif /* !GCLIENT_PING_H_ */
