/*
** gclient_ping.h for Zappy in /home/el/Zappy/GClient
**
** Made by oleg kuznietsov
** Login   <kuznet_o@epitech.eu>
**
** Started on  Sun Jul  14 01:54:50 2013 oleg kuznietsov
** Last update  Sun Jul  14 01:54:50 2013 oleg kuznietsov
*/

#ifndef GCLIENT_EXIT_H_
# define GCLIENT_EXIT_H_

#include "gclient.h"
#include <pthread.h>

typedef struct    s_exit_args
{
  t_pm            *pm;
  int             es;
  int             pret;
  pthread_t       th1;
}                 t_exit;

void  my_exit(t_pm *pm, int status);
void  *exit_monitor(void *arg);
void  exit_start(t_pm *pm, t_exit *e);

#endif /* !GCLIENT_EXIT_H_ */
