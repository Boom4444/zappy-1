##
## Makefile for zappy in /home/ignatiev/Projects/zappy
##
## Made by Marin Alcaraz
## Login   <alcara_m@epitech.net>
##
## Started on  Fri Mar 01 09:38:17 2013 Marin Alcaraz
## Last update Wed May 29 18:21:16 2013 ivan ignatiev
##

SNAME	=	server

SSRC	=	server.c 			\
			error.c  			\
			connection_utils.c  \
			main.c

SOBJ		=	$(SSRC:.c=.o)

CAINAME = 	player

CAISRC 	= 	player.c

CAIOBJ 	= 	$(CAISRC:.c=.o)

CNAME 	= 	client

CSRC 	= 	client.c 	\
			error.c 	\
			socket.c

COBJ 	= 	$(CSRC:.c=.o)

CFLAGS	=	-Wall -Wextra -Werror

CC		=	cc

RM		=	rm -f
ECHO	=	echo -e

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

all	: $(SNAME) $(CAINAME) $(CNAME)

$(SNAME) : $(SOBJ)
	$(CC) $(SOBJ) $(CFLAGS) -o $(SNAME)
	@$(ECHO) '\033[0;33m> Server Compiled\033[0m'

$(CNAME) : $(COBJ)
	$(CC) $(COBJ) $(CFLAGS) -o $(CNAME)
	@$(ECHO) '\033[0;33m> Client Compiled\033[0m'

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
