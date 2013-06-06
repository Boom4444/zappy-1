/*
** server_cmd.h for server in /home/hero/zappy/server
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Sun Apr 28 03:21:17 2013 ivan ignatiev
** Last update Wed Jun 05 22:00:10 2013 Marin Alcaraz
*/

#ifndef SERVER_CMD_H_
# define SERVER_CMD_H_

# include	<stdlib.h>
# include	<stdio.h>
# include	<string.h>
# include	<sys/socket.h>
# include	<netinet/in.h>
# include	<arpa/inet.h>
# include	"list.h"
# include	"users.h"
# include	"channels.h"

typedef int	(*t_srv_cmd)(t_btree**, t_btree**,
			     t_user*, char*);

typedef struct	s_cmds
{
    char	*name;
    t_srv_cmd	cmd;
}		t_cmds;

int	server_do(t_btree **users, t_btree **channels,
		  t_user *user);
int	server_nick(t_btree **users, t_btree **channels,
		    t_user *user, char *msg);
int	server_users(t_btree **users, t_btree **channels,
		     t_user *user, char *msg);
int	server_quit(t_btree **users, t_btree **channels,
		    t_user *user, char *msg);
int	server_msg(t_btree **users, t_btree **channels,
		   t_user *user, char *msg);
int	server_sendfile(t_btree **users, t_btree **channels,
			t_user *user, char *msg);
int	server_list(t_btree **users, t_btree **channels,
		    t_user *user, char *msg);
int	server_join(t_btree **users, t_btree **channels,
		    t_user *user, char *msg);
int	server_part(t_btree **users, t_btree **channels,
		    t_user *user, char *msg);
int	server_broadcast(t_btree **users, t_btree **channels,
			 t_user *user, char *msg);

#endif /* !SERVER_CMD_H_ */
