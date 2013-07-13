/*
** main.c for zappy in /home/ignati_i/zappy/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Fri Mar 15 16:48:12 2013 Marin Alcaraz
** Last update Sat Jul 13 18:41:25 2013 ivan ignatiev
*/

#include	"main.h"
#include	"list.h"
#include	"options.h"
#include	"trantor.h"
#include	"server.h"
#include	"users.h"
#include	"request.h"
#include	"proto_commands_items.h"
#include	"error.h"

static int	*g_server_result;

void		server_settings_init(t_opt *opt)
{
  opt->port = 3528;
  opt->width = 10;
  opt->height = 11;
  opt->cmax = 10;
  opt->tdelay = 100;
  opt->names = list_init();
}

void		sigint_handler(int sig)
{
  (void) sig;
  *g_server_result = 1;
}

int		main(int argc, char *argv[])
{
  t_server	s;
  t_world	w;

  s.result = 0;
  g_server_result = &s.result;
  signal(SIGINT, sigint_handler);
  server_settings_init(&(s.options));
  options_parse(argc, argv, &(s.options));
  init_world(&w, s.options.width, s.options.height);
  generate_resource(&w, s.options.width, s.options.height);
  if (server_init(&s) != 0)
    {
      error_show("server_start", "server_init",
		 "Server's init failed");
      return (EXIT_FAILURE);
    }
  if (server_start(&s, &w) == 0)
    return (EXIT_SUCCESS);
  return (EXIT_FAILURE);
}
