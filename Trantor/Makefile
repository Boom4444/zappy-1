##
## Makefile for make file in /home/liu_q//sdl/zappy/zappy/Trantor
## 
## Made by qiuyan liu
## Login   <liu_q@epitech.net>
## 
## Started on  Wed Jul 10 19:24:38 2013 qiuyan liu
## Last update Thu Jul 11 14:57:05 2013 Oleg Kuznietsov
##

NAME	=	Trantor

CC	=	gcc

RM	=	rm -rf

SRC	=	clip_ressources.c \
		commands.c \
		list.c \
		error.c \
		sdl_init.c \
		show_map.c \
		main.c

OBJ	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) -lSDL -lSDL_image -W -Werror -Wall
clean:
		$(RM) $(OBJ)
fclean:		clean
		$(RM) $(NAME)

re:		fclean all