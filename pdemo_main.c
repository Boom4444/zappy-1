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

static void dump_string(void *content, int size)
{
  (void) size;
  printf(" %s\n", (char*)content);
}

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

  printf("\n-p=%d, -x=%d, -y=%d, -c=%d, -t=%d\n",
    opt.port, opt.width, opt.height, opt.cmax, opt.tdelay);
  printf("Teams (%zu):\n", opt.names->len);
  list_iter(opt.names, &dump_string);
  printf("\n");

  list_delete(opt.names);
  return (1);
}