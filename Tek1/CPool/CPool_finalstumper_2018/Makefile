##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## finalstumper Makefile
##

SRC	=	my_strlen.c	\
		rush3.c		\
		my_put_nbr.c	\
		my_putstr.c	\
		my_display_rush.c

MAIN	=	main.c

NAME	=	./rush3

INCLUDE	=	-I ./include/ 

all:
	gcc -o $(NAME) $(SRC) $(MAIN) $(INCLUDE)

clean:
	rm -f *~

fclean:	clean
	rm -f $(NAME)
	rm -f a.out

re:	fclean all

.PHONY:	all clean fclean re
