##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Write a Makefile that compiles your libmy.
##

SRC	=	my_strlen.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):
	gcc -c $(SRC) -Wall --extra
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	rm -f *~
	rm -f '#*#'
	rm -f a.out

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
