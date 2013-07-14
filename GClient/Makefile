##
## Makefile for Zappy in /home/el/GitHub/zappy/Trantor
##
## Made by oleg kuznietsov
## Login   <kuznet_o@epitech.eu>
##
## Started on  Sun Jul  14 03:42:20 2013 oleg kuznietsov
## Last update Sun Jul 14 21:28:36 2013 Oleg Kuznietsov
##

GNAME		=	gclient

TNAME		=	Trantor

GSRC		=	GClient/error.c \
			GClient/gc_3.c \
			GClient/gclient.c \
			GClient/gclient_funcs.c \
			GClient/graph_commands.c \
			GClient/socket.c \
			GClient/gc_1.c \
			GClient/gc_4.c \
			GClient/gc_5.c \
			GClient/gclient_errors.c \
			GClient/gclient_parser.c \
			GClient/item.c \
			GClient/tools.c \
			GClient/gc_2.c \
			GClient/gclient_auth.c \
			GClient/gclient_exit.c \
			GClient/gclient_ctimeout.c \
			GClient/gclient_ping.c \
			GClient/list.c

TSRC		=	GClient/clip_ressources.c \
			GClient/commands.c \
			GClient/list.c \
			GClient/error.c \
			GClient/sdl_init.c \
			GClient/show_map.c \
			GClient/main.c

GOBJ		=	$(GSRC:.c=.o)

TOBJ		=	$(TSRC:.c=.o)

FLAGS		=	-Wall -Wextra -Werror -g3

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
