##
## Makefile for server in /home/hero/zappy/server
##
## Made by Marin Alcaraz
## Login   <alcara_m@epitech.net>
##
## Started on  Fri Mar 01 09:38:17 2013 Marin Alcaraz
## Last update Thu Jun 06 00:10:38 2013 Marin Alcaraz
##

SNAME	=	server

SSRC	=	server.c 			\
			select.c 			\
			item.c 				\
			server_functions.c 	\
			list.c 				\
			error.c  			\
			connection_utils.c  \
			log.c  				\
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
