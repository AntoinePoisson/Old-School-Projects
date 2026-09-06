##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Bistro Makefile
##

CC	=	gcc

RMF	=	rm -f

SRC	=	calculator.c			\
		is_extension_infinimul.c	\
		is_extension_two_infinimul.c	\
		is_extension_three_infinimul.c	\
		eval_expr.c			\
		infin_add.c			\
		infin_sub.c			\
		infin_div.c			\
		infin_mul.c			\
		infin_mod.c			\
		is_alpha.c			\
		is_extension_infiniadd.c	\
		is_extension_my_rpn.c		\
		is_extension_two_my_rpn.c	\
		is_operator.c			\
		is_to_pile.c			\
		my_rpn.c			\
		my_str_to_word_array.c		\
		pop.c				\
		push.c				\
		word_count.c			\
		my_itoa.c			\
		is_extension_infinisub.c	\
		rework_string.c			\
		error_checks.c

MAIN	=	main.c

LIB	=	./lib/my/libmy.a

LIBPATH	=	./lib/my/

TEST	=	unit_tests

TESTSRC	=	tests/test_my_is_operator.c		\
		tests/test_my_word_count.c		\
		tests/test_my_str_to_word_array.c	\
		tests/test_my_calculator.c		\
		tests/test_my_is_alpha.c		\
		tests/test_my_my_rpn.c			\
		tests/test_my_infin_add.c		\
		tests/test_my_infin_sub.c		\
		tests/test_my_infin_div.c		\
		tests/test_my_infin_mul.c		\
		tests/test_my_infin_mod.c		\
		tests/test_my_eval_expr.c		\
		tests/test_my_my_itoa.c

NAME	=	calc

INCLUDE	=	-I ./include/

CRIT    =       *.gc*

CRIT_FLAGS	=	--coverage -lcriterion

all:	$(NAME)

$(NAME):
	make -C $(LIBPATH)
	$(CC) -o $(NAME) $(MAIN) $(SRC) $(LIB) $(INCLUDE)

tests_run:	re
	$(CC) -o $(TEST) $(SRC) $(TESTSRC) $(LIB) $(INCLUDE) $(CRIT_FLAGS)
	./$(TEST)

clean:
	make clean -C $(LIBPATH)
	$(RMF) $(TEST)

fclean:	clean
	$(RMF) $(NAME)
	make fclean -C $(LIBPATH)
	$(RMF) $(CRIT)

re:	fclean all

.PHONY:	all tests_run clean fclean re
