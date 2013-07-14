/*
** client.c for zappy in /home/ignatiev/Projects/zappy
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Fri May 24 19:45:50 2013 ivan ignatiev
** Last update Sun Jul 14 15:15:58 2013 ivan ignatiev
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	<sys/time.h>
#include	<sys/types.h>
#include	<signal.h>
#include	<unistd.h>
#include	"client.h"
#include	"socket.h"
#include	"error.h"

static int	g_connect = 0;

static int	g_number = 0;

static char	*teams[] = {
  "1\n",
  "2\n",
  "3\n",
  "4\n"
};


static char	*cmds[] = {
  "fork\n",
  "avance\n",
  "droite\n",
  "pose 2\n",
  "gauche\n",
  "pose 3\n",
  "droite\n",
  "gauche\n",
  "WRONG COMMAND\n",
  "pose 4\n",
  "JUSTwrong\n",
  "incantation\n",
  "broadcast TEST\n",
  "pose 5\n",
  "broadcast TEST WORDS\n"
  "avance\n",
  "prend food\n",
  "pose 6\n",
  "prend deraumer\n",
  "prend linemate\n",
  "pose sibur\n",
  "prend 0\n",
  "prend 1\n",
  "pose 6\n",
  "prend -1\n",
  "pose 7\n",
  "pose 1\n",
  "prend 2n",
  "pose linemate\n",
  "avance\n",
  "avance\n",
  "pose\n",
  "prend 3\n",
  "prend\n",
  "broadcast\n",
  "expulse\n",
  "connect_nbr\n",
  "mct\n",
  "prend 4\n",
  "prend 5\n",
  "prend 6\n",
  "sgt\n",
  "msz\n"
};

int		client_process(int sfd, fd_set *fdreadset)
{
  char		buf[255];
  int		len;
  int		_num;

  if (FD_ISSET(sfd, fdreadset))
    {
      if ((len = read(sfd, buf, 255)) <= 0)
	return (-1);
      if (!g_connect)
	{
	  _num = rand() % 4;
	  write(sfd, teams[_num], strlen(teams[_num]));
	  printf("#zappy(client)<--%s", teams[_num]);
	}
      g_connect = 1;
      _num = rand() % 40;
      printf("#zappy(client-%d)<--%s", g_number, cmds[_num]);
      buf[len] = '\0';
      printf("#zappy(server-%d)-->%s", g_number, buf);
      write(sfd, cmds[_num], strlen(cmds[_num]));
    }
  return (1);
}

int		client_prompt(int sfd)
{
  int		prompt;
  int		rs;
  fd_set	fdreadset;

  prompt = 1;
  while (prompt > 0)
    {
      FD_ZERO(&fdreadset);
      FD_SET(sfd, &fdreadset);
      if ((rs = select(sfd + 1, &fdreadset, NULL, NULL, NULL)) < 0)
	prompt = -1;
      else
	prompt = client_process(sfd, &fdreadset);
      usleep((rand() % 100) * 10000);
    }
  close(sfd);
  return (prompt == 0 ? EXIT_SUCCESS : EXIT_FAILURE);
}

int		client_options(int argc, char **argv,
			       t_options *options)
{
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
      printf("%s: Too few arguments\n\t-h [host] %%s\n\t-p [port] %%s\n",
             argv[0]);
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}


int		main(int argc, char **argv)
{
  int		sfd;
  t_options	options;

  g_number = atoi(argv[1]);
  srand(time(NULL) + g_number);
  printf("Welcome to ZAPPY Smart Prompt!\n");
  if (client_options(argc, argv, &options) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  printf("Trying to connect %s : %s\n", options.host, options.port);
  if ((sfd = socket_connect(options.host, options.port)) < 0)
    return (error_show("main", "socket_connect", "Connection failed"));
  return (client_prompt(sfd));
}
