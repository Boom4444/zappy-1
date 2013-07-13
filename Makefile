##
## Makefile for zappy in /home/hero/zappy
##
## Made by Marin Alcaraz
## Login   <alcara_m@epitech.net>
##
## Started on  Fri Mar 01 09:38:17 2013 Marin Alcaraz
## Last update Sat Jul 13 13:09:16 2013 ivan ignatiev
##

SNAME	=	server

SSRC	=	server.c 				\
		select.c 				\
		options_errors.c			\
		options.c 				\
		proto.c 				\
		expulse.c 				\
		options_parsing.c 			\
		item.c 					\
		graph_command.c 			\
		cli_command_parse.c 			\
		list.c 					\
		broadcast.c 				\
		incantation.c 				\
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
		trantor.c 				\
		request.c 				\
		answer.c 				\
		str.c 					\
		main.c

SOBJ	=	$(SSRC:.c=.o)

WNAME	=   world

WSRC	=	world.c

WOBJ	=	$(WSRC:.c=.o)


CNAME 	= 	client

CSRC 	= 	client.c 	\
			error.c 	\
			socket.c

COBJ 	= 	$(CSRC:.c=.o)

CFLAGS	=	-Wall -Wextra -Werror -g3

CC		=	cc

RM		=	rm -f
ECHO	=	echo -e

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

all	: $(SNAME) $(CNAME) $(WNAME)

$(SNAME) : $(SOBJ)
	$(CC) $(SOBJ) $(CFLAGS) -o $(SNAME) -lm
	@$(ECHO) '\033[0;33m> Server Compiled\033[0m'

$(CNAME) : $(COBJ)
	$(CC) $(COBJ) $(CFLAGS) -o $(CNAME)
	@$(ECHO) '\033[0;33m> CLI Client Compiled\033[0m'

$(WNAME) : $(WOBJ)
	$(CC) $(WOBJ) $(CFLAGS) -o $(WNAME) -lSDL -lSDL_image
	@$(ECHO) '\033[0;33m> GUI Client Compiled\033[0m'

clean	:
	$(RM) $(SOBJ)
	$(RM) $(COBJ)
	$(RM) $(WOBJ)
	@$(ECHO) '\033[0;33m> Directory cleaned\033[0m'

fclean	: clean
	$(RM) $(SNAME)
	$(RM) $(CNAME)
	$(RM) $(WNAME)
	@$(ECHO) '\033[0;33m> Removed executables\033[0m'

re	: fclean all
