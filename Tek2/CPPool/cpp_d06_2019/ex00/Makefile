##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## This Makefile compile my lib.
##

SRC	=	ex00.cpp\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_cat

TEST	=	unit_tests

CFLAGS	=	-Wall -Wextra

CC	=	g++

all:	$(NAME)

$(NAME):	$(OBJ)
	@$(CC) -o $(NAME) $(SRC) $(CFLAGS)

clean:
	@rm -fr *.o

fclean:	clean
	@rm -fr $(NAME)
	@rm -fr a.out

re:	fclean all

.PHONY:	all	NAME	debug	clean	fclean	re	tests_run
