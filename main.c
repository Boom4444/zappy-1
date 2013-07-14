/*
** main.c for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Fri Mar 15 16:48:12 2013 Marin Alcaraz
** Last update Sun Jul 14 19:54:38 2013 ivan ignatiev
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
  opt->mode = 0;
  opt->names = list_init();
}

void		sigint_handler(int sig)
{
  (void) sig;
  *g_server_result = 1;
}

void		output_redirection()
{
  int		o_fd;
  int		e_fd;

  o_fd = open("out.log", O_WRONLY | O_APPEND | O_CREAT, 0644);
  e_fd = open("err.log", O_WRONLY | O_APPEND | O_CREAT, 0644);
  if (o_fd == -1 || e_fd == -1)
    {
      error_show("output_redirection", "open", "Unable to open log files");
      exit(EXIT_FAILURE);
    }
  close(STDIN_FILENO);
  dup2(o_fd, STDOUT_FILENO);
  dup2(e_fd, STDERR_FILENO);
}

int		daemonize()
{
    int		fd;
    int		pid;
    char	buf[20];

    if ((pid = fork()) == -1)
        return (-1);
    else if (pid != 0 && pid != 1)
    {
        fd = open ("zappy.pid", O_WRONLY | O_CREAT, 0644);
        if (fd == -1)
            return (-1);
        sprintf(buf, "PID:%d", pid);
        write(fd, buf, strlen(buf));
        exit (EXIT_SUCCESS);
    }
    output_redirection();
    if (setsid() == -1)
        return (-1);
    return (0);
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
  if (s.options.mode == 1)
      daemonize();
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
