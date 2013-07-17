##
## Makefile for zappy in /home/hero/zappy
##
## Made by Marin Alcaraz
## Login   <alcara_m@epitech.net>
##
## Started on  Fri Mar 01 09:38:17 2013 Marin Alcaraz
## Last update Fri Jul 12 22:51:51 2013 Marin Alcaraz
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
		resource_manager.c 			\
		request.c 				\
		request_data.c 				\
		graph_utils.c 				\
		answer.c 				\
		str.c 					\
		main.c

SOBJ	=	$(SSRC:.c=.o)

CNAME 	= 	client

CSRC 	= 	client.c 	\
		error.c 	\
		socket.c

COBJ 	= 	$(CSRC:.c=.o)

GNAME	=	gclient

TNAME	=	Trantor

GSRC	=	GClient/error.c 		\
		GClient/gc_3.c 			\
		GClient/gclient.c 		\
		GClient/gclient_funcs.c 	\
		GClient/graph_commands.c	\
		GClient/socket.c 		\
		GClient/gc_1.c 			\
		GClient/gc_4.c 			\
		GClient/gc_5.c 			\
		GClient/gclient_errors.c 	\
		GClient/gclient_parser.c 	\
		GClient/item.c 			\
		GClient/tools.c 		\
		GClient/gc_2.c 			\
		GClient/gclient_auth.c 		\
		GClient/gclient_exit.c 		\
		GClient/gclient_ctimeout.c 	\
		GClient/gclient_ping.c 		\
		GClient/list.c

TSRC	=	GClient/clip_ressources.c 	\
		GClient/commands.c 		\
		GClient/list.c 			\
		GClient/error.c 		\
		GClient/sdl_init.c 		\
		GClient/show_map.c 		\
		GClient/main.c

GOBJ	=	$(GSRC:.c=.o)

TOBJ	=	$(TSRC:.c=.o)

CFLAGS	=	-Wall -Wextra -Werror -g3

CC	=	cc

RM	=	rm -f
ECHO	=	echo -e

%.o: 	%.c
	$(CC) -c -o $@ $< $(CFLAGS)

all	: $(SNAME) $(CNAME) $(WNAME) $(GNAME) $(TNAME)

$(SNAME) : $(SOBJ)
	$(CC) $(SOBJ) $(CFLAGS) -o $(SNAME) -lm
	@$(ECHO) '\033[0;33m> Server Compiled\033[0m'

$(CNAME) : $(COBJ)
	$(CC) $(COBJ) $(CFLAGS) -o $(CNAME)
	@$(ECHO) '\033[0;33m> CLI Client Compiled\033[0m'

$(GNAME) : $(GOBJ)
	$(CC) $(GOBJ) $(FLAGS) -o $(GNAME) -pthread
	@$(ECHO) '\033[0;33m> GClient Compiled\033[0m'

$(TNAME) : $(TOBJ)
	$(CC) $(TOBJ) $(FLAGS) -o $(TNAME) -lSDL -lSDL_image
	@$(ECHO) '\033[0;33m> Trantor Compiled\033[0m'

clean	:
	$(RM) $(SOBJ)
	$(RM) $(COBJ)
	$(RM) $(GOBJ) 
	$(RM) $(TOBJ)
	@$(ECHO) '\033[0;33m> Directory cleaned\033[0m'

fclean	: clean
	$(RM) $(SNAME)
	$(RM) $(CNAME)
	$(RM) $(GNAME) 
	$(RM) $(TNAME)
	@$(ECHO) '\033[0;33m> Removed executables\033[0m'

re	: fclean all

.PHONY: all clean fclean re
