##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## makefile of libmy
##

NAME	=	libmy.a

SRC	=	my_strcmp.c	\
		my_puterror.c	\
		my_strlen.c

CFLAGS	+=	-Wall -Wextra -I./../../include

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

debug:
	gcc -c $(SRC) $(CFLAGS) -g3
	ar rc $(NAME) ./*.o

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all debug clean fclean re
