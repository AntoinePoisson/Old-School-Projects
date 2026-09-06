##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Infinadd Makefile
##

SRC	=	is_my_ls.c				\
		check_error.c				\
		check_flag.c				\
		check_arg.c				\
		my_stat.c				\
		my_put_long.c				\
		my_itoa.c				\
		is_ls_big_r.c				\
		control_list.c				\
		is_extension_my_stat_two.c		\
		is_extension_my_stat_three.c		\
		is_extension_my_stat.c			\
		is_extension_is_my_ls_big_r.c		\
		is_extension_my_ls_big_two.c		\
		is_extension_my_ls_big_three.c		\
		is_extension_my_ls_big_four.c		\
		is_extension_my_ls_big_five.c		\
		is_extension_my_ls_big_six.c		\
		is_extension_is_my_ls_two.c		\
		is_extension_is_my_ls_three.c		\
		is_extension_is_my_ls_four.c		\
		is_extension_is_my_ls_five.c		\
		is_extension_is_my_ls.c

MAIN	=	main.c

LIB	=	./lib/my/libmy.a

NAME	=	my_ls

INCLUDE	=	-I ./include/

TEST	=	unit_tests

TESTSRC	=	tests/test.c

CRIT	=	*.gc*

OPTION	=	-Wall --extra -lm

BASIC_BIN	=	a.out

TILDE	=	*~

OPTION_DEBUG	=	-Wall --extra -g3

OPTION_TU	=	--coverage -lcriterion

HEADER_COMPLI	=	*.h.gch

VALGRIND	=	vgcore.*

EMACS	=	\#*#

all: NAME

NAME:
	make -C ./lib/my/
	gcc -o $(NAME) $(SRC) $(MAIN) $(LIB) $(INCLUDE) $(OPTION)

debug:
	make -C ./lib/my/
	gcc -o $(NAME) $(SRC) $(MAIN) $(LIB) $(INCLUDE) $(OPTION_DEBUG)

tests_run:	all
	gcc -o $(TEST) $(SRC) $(TESTSRC) $(LIB) $(INCLUDE) $(OPTION_TU)
	./$(TEST)

clean:
	make clean -C ./lib/my/

fclean:	clean
	rm -f $(NAME)
	rm -f $(TEST)
	rm -f $(CRIT)
	rm -f $(EMACS)
	rm -f $(TILDE)
	rm -f $(BASIC_BIN)
	rm -f include/$(BASIC_BIN)
	rm -f tests/$(BASIC_BIN)
	rm -f include/$(TILDE)
	rm -f tests/$(TILDE)
	rm -f include/$(EMACS)
	rm -f tests/$(EMACS)
	rm -f include/$(HEADER_COMPLI)
	rm -f tests/$(HEADER_COMPLI)
	rm -f $(VALGRIND)
	make fclean -C ./lib/my/

re:	fclean all

.PHONY:	all NAME tests_run clean fclean re
