##
## EPITECH PROJECT, 2018
## cat
## File description:
## Write a program called cat, which executes the same tasks as your system’s cat command.
##

SRC	=	*.c	\

NAME	=	cat

NAME_TEST	=	Unit_test

all:	$(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC)

tests_run:
	gcc -o $(NAME_TEST) cat.c ../tests/test_my_cat.c --coverage -lcriterion
	./$(NAME_TEST)

clean:
	rm -f $(OBJ)
	rm -f *~

fclean:	clean
	rm -f $(NAME)

re:	fclean all
