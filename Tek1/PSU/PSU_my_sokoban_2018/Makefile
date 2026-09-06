##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Infinadd Makefile
##

SRC	=	check_error.c		\
		load_map.c		\
		count_rows_cols.c	\
		is_sokoban.c		\
		display_sokoban.c	\
		is_extension_sokoban.c	\
		is_control_sokoban.c	\
		my_popup.c

MAIN	=	main.c

LIB	=	./lib/my/libmy.a

NAME	=	my_sokoban

INCLUDE	=	-I ./include/

TEST	=	unit_tests

TESTSRC	=	tests/test_check_error.c	\
		tests/test_count_rows_cols.c

CRIT	=	*.gc*

all:
	make -C ./lib/my/
	gcc -o $(NAME) $(SRC) $(MAIN) $(LIB) $(INCLUDE) -Wall --extra -lncurses

tests_run:	all
	gcc -o $(TEST) $(SRC) $(TESTSRC) $(LIB) $(INCLUDE) --coverage -lcriterion -lncurses
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
