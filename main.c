/*
** main.c for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Fri Mar 15 16:48:12 2013 Marin Alcaraz
** Last update Thu Jun  06 21:43:48 2013 oleg kuznietsov
*/

#include <stdio.h>
#include "options.h"
#include "server.h"

void  server_settings_init(t_opt *opt)
{
  opt->port = 3528;
  opt->width = 600;
  opt->height = 600;
  opt->cmax = 2;
  opt->tdelay = 0;
  opt->names = list_init();
}

int     main(int argc, char *argv[])
{
  t_opt opt;

  server_settings_init(&opt);
  options_parse(argc, argv, &opt);
  server_start(&opt);
  list_delete(opt.names);
  return (1);
}
