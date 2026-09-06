##
## EPITECH PROJECT, 2018
## task01 Day10
## File description:
## Makefile
##

SRC	=	step.c		\
		ger.c		\
		spa.c		\
		french.c	\
		eng.c		\
		count.c		\
		display.c	\
		check_error.c	\
		my_putnbr.c	\
		compare.c

OBJ	=	$(SRC:.c=.o)

NAME	=	rush2

all:	$(NAME) 

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ)

clean :
	rm -f $(OBJ)

fclean :	clean
	rm -f $(NAME);

re :	fclean	all
