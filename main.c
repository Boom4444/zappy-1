/*
** main.c for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Fri Mar 15 16:48:12 2013 Marin Alcaraz
** Last update Thu Jul 04 16:23:31 2013 Marin Alcaraz
*/

#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include "options.h"
#include "server.h"
#include "proto_commands_items.h"

void  server_settings_init(t_opt *opt)
{
  opt->port = 3528;
  opt->width = 10;
  opt->height = 11;
  opt->cmax = 2;
  opt->tdelay = 0;
  opt->names = list_init();
}

void                sigint_handler(int sig)
{
    (void) sig;
}

int         main(int argc, char *argv[])
{
  t_server  s;
  t_world   w;

  signal(SIGINT, sigint_handler);
  server_settings_init(&(s.options));
  options_parse(argc, argv, &(s.options));
  init_world(&w,s.options.width, s.options.height);
  generate_resource(&w,s.options.width, s.options.height);
  display_world(&w, s.options.width, s.options.height);
  server_start(&s, &w);
  /** TODO FREE RESOURCES **/
  //list_delete(opt.names); DEPRECATED
  return (1);
}
