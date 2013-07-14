/*
** client.c for zappy in /home/hero/zappy
**
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
**
** Started on  Fri Jun 24 19:45:50 2003 ivan ignatiev
** Last update Wed May 12 14:58:18 2001 oleg kuznietsov
*/

#include "gclient.h"
#include "error.h"
#include "tools.h"
#include "gclient_auth.h"
#include "gclient_ping.h"
#include "gclient_exit.h"
#include "socket.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

static int  *g_exit;

int   client_options(int argc, char **argv, t_options *options)
{
  opterr = 0;
  options->host = NULL;
  options->port = NULL;
  while (-1 != (options->current = getopt(argc, argv, "h:" "p:" )))
  {
    if (options->current == 'h')
        options->host = optarg;
    else if (options->current == 'p')
            options->port = optarg;
  }
  if (!options->host || !options->port)
  {
    error_show("client_options", "!host !port",
              "Too few arguments\n\t-h [host] %s\n\t-p [port] %s");
    return (-1);
  }
  return (1);
}

int   screen_update(t_ppo *po, t_pm *pm)
{
  po->i = 0;
  po->t = 0;
  if (pbuf_process(po, pm) == -1)
    return (0);
  while (po->i < po->tlen)
  {
    while (po->i != po->tlen && po->tbuf[po->i] != '\n')
      ++po->i;
    if (po->i != po->tlen)
    {
      if (bp_guide(1, po, pm) == -1)
        return (0);
      if (cmd_process(po->rbuf, pm) == -1)
        return (0);
      ++po->i;
      po->t = po->i;
    }
    else if (bp_guide(2, po, pm) == -1)
      return (0);
  }
  return (1);
}

void      client_prompt(t_pm *pm)
{
  t_ppo   po;
  fd_set  fd_rs;
  t_auth  a;
  t_ping  p;

  po.plen = 0;
  FD_ZERO(&fd_rs);
  FD_SET(pm->sfd, &fd_rs);
  pthread_mutex_init(&pm->lock, NULL);
  auth_start(pm, &a);
  ping_start(pm, &p);
  while (42)
  {
    select_monitor(&fd_rs, &po, pm);
    screen_update(&po, pm);
  }
}

void                sigint_handler(int sig)
{
  (void) sig;
  write(1, "\n", 1);
  *g_exit = 1;
}

int         main(int argc, char **argv)
{
  t_pm      pm;
  t_options options;
  t_exit    e;

  signal(SIGINT, sigint_handler);
  g_exit = &e.es;
  exit_start(&pm, &e);
  if (client_options(argc, argv, &options) == -1)
    return (EXIT_SUCCESS);
  str_put("Welcome to Zappy GClient !\n");
  printf("Trying to connect %s:%s\n", options.host, options.port);
  if ((pm.sfd = socket_connect(options.host, options.port)) == -1)
  {
    error_show("main", "socket_connect", "Connection failed");
    str_put("GClient stop\n");
    return (EXIT_SUCCESS);
  }
  client_prompt(&pm);
  return (EXIT_FAILURE);
}
