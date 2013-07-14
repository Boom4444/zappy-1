/*
** gclient_threads.h for Zappy in /home/el/Zappy/GClient
**
** Made by oleg kuznietsov
** Login   <kuznet_o@epitech.eu>
**
** Started on  Fri Jun 24 19:45:50 2003 oleg kuznietsov
** Last update Wed May 12 14:58:18 2001 oleg kuznietsov
*/

#ifndef GCLIENT_AUTH_H_
# define GCLIENT_AUTH_H_

# include <pthread.h>
# include "gclient.h"

typedef struct    s_tauth_args
{
  t_pm            *pm;
  int             pret;
  pthread_t       th1;
}                 t_auth;

void  *auth(void *arg);
void  auth_start(t_pm *pm, t_auth *a);
int   ll_auth(char *cmd, t_pm *pm);

#endif /* !GCLIENT_AUTH_H_ */
