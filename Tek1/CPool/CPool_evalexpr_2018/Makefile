##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Infinadd Makefile
##

SRC	=	eval_expr.c		\
		is_operator.c		\
		my_str_to_word_array.c	\
		word_count.c		\
		calculator.c		\
		my_rpn.c		\
		pop.c			\
		push.c			\
		is_to_pile.c		\
		my_itoa.c		\
		is_case_zero.c		\
		is_extension_my_rpn.c	\
		is_extension_two_my_rpn.c

MAIN	=	main.c

LIB	=	./lib/my/libmy.a

NAME	=	eval_expr

INCLUDE	=	-I ./include/

TEST	=	unit_tests

TESTSRC	=	tests/test_my_is_operator.c		\
		tests/test_my_word_count.c		\
		tests/test_my_str_to_word_array.c	\
		tests/test_my_calculator.c

CRIT	=	*.gc*

all:
	make -C ./lib/my/
	gcc -o $(NAME) $(SRC) $(MAIN) $(LIB) $(INCLUDE)

tests_run:	all
	gcc -o $(TEST) $(SRC) $(TESTSRC) $(LIB) $(INCLUDE) --coverage -lcriterion
	./$(TEST)

clean:
	make clean -C ./lib/my/

fclean:	clean
	rm -f $(NAME)
	rm -f $(TEST)
	rm -f $(CRIT)
	make fclean -C ./lib/my/

re:	fclean all

.PHONY:	all tests_run clean fclean re
