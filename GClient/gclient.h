/*
** client.h for zappy in /home/hero/zappy
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Wed Jun 29 18:02:30 2003 ivan ignatiev
** Last update Thu May 06 11:09:30 2001 oleg kuznietsov
*/

#ifndef CLIENT_H_
# define CLIENT_H_

#include <pthread.h>

typedef struct  s_options
{
  int           current;
  char          *host;
  char          *port;
}               t_options;

typedef struct  s_pre_parse_options
{
  int           i;
  int           t;
  char          rbuf[256];
  char          tbuf[1001];
  char          pbuf[256];
  int           tlen;
  int           plen;
}               t_ppo;

typedef struct    s_program_memory
{
  int             auth;
  pthread_mutex_t lock;
  int             sfd;
}                 t_pm;

#endif /* !CLIENT_H_ */
