##
## Makefile for zappy in /home/hero/zappy
##
## Made by Marin Alcaraz
## Login   <alcara_m@epitech.net>
##
## Started on  Fri Mar 01 09:38:17 2013 Marin Alcaraz
## Last update Wed May 15 17:45:31 2013 Marin Alcaraz
##

SNAME	=	server

SSRC	=	server.c 			\
			error.c  			\
			connection_utils.c  \
			main.c

SOBJ		=	$(SSRC:.c=.o)

CFLAGS	=	-Wall -Wextra -Werror

CC		=	cc

RM		=	rm -f
ECHO	=	echo -e

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

all	: $(SNAME)

$(SNAME) : $(SOBJ)
	$(CC) $(SOBJ) $(CFLAGS) -o $(SNAME)
	@$(ECHO) '\033[0;33m> Server Compiled\033[0m'

clean	:
	$(RM) $(SOBJ)
	@$(ECHO) '\033[0;33m> Directory cleaned\033[0m'

fclean	: clean
	$(RM) $(SNAME)
	@$(ECHO) '\033[0;33m> Remove executables\033[0m'

re	: fclean all
