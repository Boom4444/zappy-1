/*
** server_cmd.c for server in /home/hero/zappy/server
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Sun Apr 28 03:10:34 2013 ivan ignatiev
** Last update Thu Jun 06 10:22:07 2013 Marin Alcaraz
*/

#include "server_cmd.h"

static t_cmds	g_cmds[] =
  {
    {
      "/nick",
      server_nick
    },
    {
      "/users",
      server_users
    },
    {
      "/quit",
      server_quit
    },
    {
      "/msg",
      server_msg
    },
    {
      "/sendfile",
      server_sendfile
    },
    {
      "/list",
      server_list
    },
    {
      "/join",
      server_join
    },
    {
      "/part",
      server_part
    },
    {
      NULL,
      NULL
    }
  };

int	server_quit(t_list **users, t_list **channels,
		    t_user *user, char *msg)
{
  (void) users;
  (void) channels;
  (void) msg;
  user->connected = IRC_DISCONNECTED;
  fprintf(user->iow, "SUCCESS\n");
  return (1);
}

static char	*server_select_io(t_user *user)
{
  size_t	len;
  char		*line;

  line = NULL;
  if (getline(&line, &len, user->ior) < 0)
    return (NULL);
  return (line);
}

static int	server_exec(t_list **users,
			    t_user *user, char *msg)
{
  char		cmd[32];
  int		i;
  int		found;

  sscanf(msg, "%s", cmd);
  i = 0;
  found = 0;
  while (g_cmds[i].name != NULL)
    {
      if (strcmp(cmd, g_cmds[i].name) == 0)
        {
	  (g_cmds[i].cmd)(users, user, msg + strlen(g_cmds[i].name));
            found = 1;
        }
      ++i;
    }
  if (!found)
    server_broadcast(users, channels, user, msg);
  return (0);
}

int		server_do(t_list **users, t_user *user)
{
  char		*line;

  printf("[%s] Try to read command from client\n", user->name);
  if ((line = server_select_io(user)) == NULL)
    return (-1);
  printf("[%s] %s\n", user->name, line);
  fflush(stdout);
  server_exec(users,º user, line);
  fflush(user->iow);
  free(line);
  return (0);
}
