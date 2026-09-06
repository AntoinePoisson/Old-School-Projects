##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Infinadd Makefile
##

SRC	=	check_error.c		\
		count_operator.c	\
		trans.c			\
		scaling.c		\
		rotation.c		\
		reflect.c		\
		is_operator.c

MAIN	=	main.c

LIB	=	./lib/my/libmy.a

NAME	=	102architect

INCLUDE	=	-I ./include/

TEST	=	unit_tests

TESTSRC	=	tests/

CRIT	=	*.gc*

all:
	make -C ./lib/my/
	gcc -o $(NAME) $(SRC) $(MAIN) $(LIB) $(INCLUDE) --extra -Wall -lm

tests_run:	all
	gcc -o $(TEST) $(SRC) $(TESTSRC) $(LIB) $(INCLUDE) --coverage -lcriterion
	./$(TEST)

clean:
	make clean -C ./lib/my/

fclean:	clean
	rm -f $(NAME)
	rm -f $(TEST)
	rm -f $(CRIT)
	rm -f *~
	rm -f a.out
	make fclean -C ./lib/my/

re:	fclean all

.PHONY:	all tests_run clean fclean re
