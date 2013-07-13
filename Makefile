##
## Makefile for zappy in /home/ignati_i/zappy/zappy
##
## Made by Marin Alcaraz
## Login   <alcara_m@epitech.net>
##
## Started on  Fri Mar 01 09:38:17 2013 Marin Alcaraz
## Last update Sat Jul 13 20:40:07 2013 marin alcarazcordova
##

SNAME	=	server

SSRC	=	server.c 				\
		select.c 				\
		options_errors.c			\
		options.c 				\
		proto.c 				\
		proto_cli.c 				\
		expulse.c 				\
		options_parsing.c 			\
		item.c 					\
		graph_command.c 			\
		graph_command_player.c 			\
		graph_command_server.c 			\
		cli_command_parse.c 			\
		cli_command_parse_items.c		\
		cli_command_parse_net.c 		\
		list.c 					\
		broadcast.c 				\
		incantation.c 				\
		incantation_support.c			\
		error.c  				\
		users.c 				\
		users_cli.c 				\
		users_eggs.c 				\
		users_graph.c 				\
		team.c					\
		connection_utils.c  			\
		proto_commands_items.c 			\
		proto_commands_net.c 			\
		proto_commands_movement.c 		\
		proto_commands_voir.c 			\
		proto_commands_res.c 			\
		trantor.c 				\
		request.c 				\
		request_data.c 				\
		answer.c 				\
		str.c 					\
		main.c

SOBJ	=	$(SSRC:.c=.o)

CNAME 	= 	client

CSRC 	= 	client.c 	\
		error.c 	\
		socket.c

COBJ 	= 	$(CSRC:.c=.o)

CFLAGS	=	-Wall -Wextra -Werror -g3

CC	=	cc

RM	=	rm -f
ECHO	=	echo -e

%.o: 	%.c
	$(CC) -c -o $@ $< $(CFLAGS)

all	: $(SNAME) $(CNAME) $(WNAME)

$(SNAME) : $(SOBJ)
	$(CC) $(SOBJ) $(CFLAGS) -o $(SNAME) -lm
	@$(ECHO) '\033[0;33m> Server Compiled\033[0m'

$(CNAME) : $(COBJ)
	$(CC) $(COBJ) $(CFLAGS) -o $(CNAME)
	@$(ECHO) '\033[0;33m> CLI Client Compiled\033[0m'

clean	:
	$(RM) $(SOBJ)
	$(RM) $(DOBJ)
	$(RM) $(COBJ)
	@$(ECHO) '\033[0;33m> Directory cleaned\033[0m'

fclean	: clean
	$(RM) $(SNAME)
	$(RM) $(DNAME)
	$(RM) $(CNAME)
	@$(ECHO) '\033[0;33m> Removed executables\033[0m'

re	: fclean clean re all
