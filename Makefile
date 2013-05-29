##
## Makefile for zappy in /home/ignatiev/Projects/zappy
##
## Made by Marin Alcaraz
## Login   <alcara_m@epitech.net>
##
## Started on  Fri Mar 01 09:38:17 2013 Marin Alcaraz
## Last update Fri May 24 19:45:14 2013 ivan ignatiev
##

SNAME	=	server

SSRC	=	server.c 			\
			error.c  			\
			connection_utils.c  \
			main.c

SOBJ		=	$(SSRC:.c=.o)

CAINAME = 	client_ai

CAISRC 	= 	client_ai.c

CAIOBJ 	= 	$(CAISRC:.c=.o)

CFLAGS	=	-Wall -Wextra -Werror

CC		=	cc

RM		=	rm -f
ECHO	=	echo -e

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

all	: $(SNAME) $(CAINAME)

$(SNAME) : $(SOBJ)
	$(CC) $(SOBJ) $(CFLAGS) -o $(SNAME)
	@$(ECHO) '\033[0;33m> Server Compiled\033[0m'

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
