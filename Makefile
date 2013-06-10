##
## Makefile for zappy in /home/hero/zappy
##
## Made by Marin Alcaraz
## Login   <alcara_m@epitech.net>
##
## Started on  Fri Mar 01 09:38:17 2013 Marin Alcaraz
## Last update Thu Jun  6 22:42:07 2013 Oleg Kuznietsov
##

SNAME	=	server

SSRC	=	server.c 			\
			select.c 			\
			options_errors.c 	\
			options.c 			\
			options_parsing.c 	\
			item.c 				\
			server_functions.c 	\
			list.c 				\
			error.c  			\
			connection_utils.c  \
			log.c  				\
			server_main.c

SOBJ		=	$(SSRC:.c=.o)

PNAME	=   pdemo

PSRC	=	options_errors.c 	\
			options.c 			\
			options_parsing.c 	\
			item.c 				\
			list.c 				\
			error.c  			\
			log.c  				\
			main.c

POBJ		=	$(PSRC:.c=.o)

WNAME	=   world

WSRC	=	world.c

WOBJ		=	$(WSRC:.c=.o)


CAINAME = 	player

CAISRC 	= 	player.c

CAIOBJ 	= 	$(CAISRC:.c=.o)

CNAME 	= 	client

CSRC 	= 	client.c 	\
			error.c 	\
			log.c 		\
			socket.c

COBJ 	= 	$(CSRC:.c=.o)

CFLAGS	=	-Wall -Wextra -Werror

CC		=	cc

RM		=	rm -f
ECHO	=	echo -e

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

all	: $(SNAME) $(CAINAME) $(CNAME) $(PNAME) $(WNAME)

$(SNAME) : $(SOBJ)
	$(CC) $(SOBJ) $(CFLAGS) -o $(SNAME)
	@$(ECHO) '\033[0;33m> Server Compiled\033[0m'

$(CNAME) : $(COBJ)
	$(CC) $(COBJ) $(CFLAGS) -o $(CNAME)
	@$(ECHO) '\033[0;33m> Client Compiled\033[0m'

$(WNAME) : $(WOBJ)
	$(CC) $(WOBJ) $(CFLAGS) -o $(WNAME) -lSDL -lSDL_image
	@$(ECHO) '\033[0;33m> Word demo Compiled\033[0m'


$(PNAME) : $(POBJ)
	$(CC) $(POBJ) $(CFLAGS) -o $(PNAME)
	@$(ECHO) '\033[0;33m> Parser Demo Compiled\033[0m'

$(CAINAME) : $(CAIOBJ)
	$(CC) $(CAIOBJ) $(CFLAGS) -o $(CAINAME)
	@$(ECHO) '\033[0;33m> Client AI Compiled\033[0m'

clean	:
	$(RM) $(SOBJ)
	$(RM) $(CAIOBJ)
	@$(ECHO) '\033[0;33m> Directory cleaned\033[0m'

fclean	: clean
	$(RM) $(SNAME)
	$(RM) $(CAINAME)
	@$(ECHO) '\033[0;33m> Remove executables\033[0m'

re	: fclean all
