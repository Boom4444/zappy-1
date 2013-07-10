##
## Makefile for zappy in /home/ignatiev/Projects/zappy
##
## Made by Marin Alcaraz
## Login   <alcara_m@epitech.net>
##
## Started on  Fri Mar 01 09:38:17 2013 Marin Alcaraz
## Last update Wed Jul 10 18:18:00 2013 ivan ignatiev
##

SNAME	=	server

SSRC	=	server.c 						\
			select.c 						\
			options_errors.c 				\
			options.c 						\
			proto.c 						\
			expulse.c 						\
			options_parsing.c 				\
			item.c 							\
			graph_command.c 				\
			cli_command_parse.c 			\
			list.c 							\
			broadcast.c 				    \
			error.c  						\
			users.c 						\
			connection_utils.c  			\
			proto_commands_items.c 			\
			proto_commands_net.c 			\
			proto_commands_movement.c 		\
			trantor.c 						\
			request.c 						\
			answer.c 						\
			str.c 							\
			main.c

SOBJ	=	$(SSRC:.c=.o)

WNAME	=   world

WSRC	=	world.c

WOBJ	=	$(WSRC:.c=.o)


CAINAME = 	player

CAISRC 	= 	player.c

CAIOBJ 	= 	$(CAISRC:.c=.o)

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

all	: $(SNAME) $(CAINAME) $(CNAME) $(WNAME)

$(SNAME) : $(SOBJ)
	$(CC) $(SOBJ) $(CFLAGS) -o $(SNAME) -lm
	@$(ECHO) '\033[0;33m> Server Compiled\033[0m'

$(CNAME) : $(COBJ)
	$(CC) $(COBJ) $(CFLAGS) -o $(CNAME)
	@$(ECHO) '\033[0;33m> Client Compiled\033[0m'

$(WNAME) : $(WOBJ)
	$(CC) $(WOBJ) $(CFLAGS) -o $(WNAME) -lSDL -lSDL_image
	@$(ECHO) '\033[0;33m> Word demo Compiled\033[0m'

$(CAINAME) : $(CAIOBJ)
	$(CC) $(CAIOBJ) $(CFLAGS) -o $(CAINAME)
	@$(ECHO) '\033[0;33m> Client AI Compiled\033[0m'

clean	:
	$(RM) $(SOBJ)
	$(RM) $(CAIOBJ)
	$(RM) $(COBJ)
	$(RM) $(WOBJ)
	@$(ECHO) '\033[0;33m> Directory cleaned\033[0m'

fclean	: clean
	$(RM) $(SNAME)
	$(RM) $(CAINAME)
	$(RM) $(CNAME)
	$(RM) $(WNAME)
	@$(ECHO) '\033[0;33m> Remove executables\033[0m'

re	: fclean all
