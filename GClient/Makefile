##
## Makefile for Zappy in /home/el/GitHub/zappy/Trantor
##
## Made by oleg kuznietsov
## Login   <kuznet_o@epitech.eu>
##
## Started on  Sun Jul  14 03:42:20 2013 oleg kuznietsov
## Last update Sun Jul 14 09:31:26 2013 Oleg Kuznietsov
##

GNAME		=	gclient

TNAME		=	Trantor

GSRC		=	error.c \
			gc_3.c \
			gclient.c \
			gclient_funcs.c \
			graph_commands.c \
			socket.c \
			gc_1.c \
			gc_4.c \
			gclient_errors.c \
			gclient_parser.c \
			item.c \
			tools.c \
			gc_2.c \
			gclient_auth.c \
			gclient_exit.c \
			gclient_ctimeout.c \
			gclient_ping.c \
			list.c

TSRC		=	clip_ressources.c \
			commands.c \
			list.c \
			error.c \
			sdl_init.c \
			show_map.c \
			main.c

GOBJ		=	$(GSRC:.c=.o)

TOBJ		=	$(TSRC:.c=.o)

# FLAGS		=	-Wall -Wextra -Werror -g3

CC		=	cc

RM		=	rm -f

ECHO		=	echo -e

%.o:			%.c
			$(CC) -c -o $@ $< $(FLAGS)

all		:	$(GNAME) $(TNAME)

$(GNAME)	:	$(GOBJ)
			$(CC) $(GOBJ) $(FLAGS) -o $(GNAME) -pthread
			@$(ECHO) '\033[0;33m> GClient Compiled\033[0m'

$(TNAME):		$(TOBJ)
			$(CC) $(TOBJ) $(FLAGS) -o $(TNAME) -lSDL -lSDL_image -W -Werror -Wall
			@$(ECHO) '\033[0;33m> Trantor Compiled\033[0m'

clean		:
			$(RM) $(GOBJ) $(TOBJ)
			@$(ECHO) '\033[0;33m> Directory cleaned\033[0m'

fclean		:	clean
			$(RM) $(GNAME) $(TNAME)
			@$(ECHO) '\033[0;33m> Removed executables\033[0m'

re		:	fclean all
