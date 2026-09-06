##
## EPITECH PROJECT, 2020
## PSU_nmobjdump_2019
## File description:
## Makefile
##

NAME	=	myftp

SRC		=	main.c	\
			tools.c	\
			message_help.c	\
			management_arg.c	\
			loop.c	\
			reply_server.c	\
			utiles.c	\
			management_client.c	\
			commands/other.c	\
			commands/login.c	\
			commands/quit.c	\
			commands/cwd.c	\
			commands/retr.c	\
			commands/stor.c	\
			commands/list.c	\
			commands/pwd.c	\
			commands/dele.c	\
			commands/pasv.c	\
			commands/port.c	\
			commands/cdup.c	\
			commands/noop.c	\
			commands/help.c	\
			commands/handle_cmd.c	\
			commands/handle_string.c	\

RM		=	rm -f

OBJ		=	$(addprefix ./src/, $(SRC:.c=.o))

CPPFLAGS	+=	-W -Wall -Wextra

CFLAGS		+=	-I ./includes

CC		=	gcc

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	@$(RM) $(NAME)

fclean:	clean
	@$(RM) $(OBJ)
	@$(RM) vgcore.*

re: fclean all

.PHONY:	all clean fclean re $(NAME)
