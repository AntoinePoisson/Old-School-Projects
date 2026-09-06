##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Infinadd Makefile
##

SRC	=	check_error.c			\
		is_initialization.c		\
		display.c			\
		tool.c				\
		get_next_line.c			\
		is_matchstick.c			\
		is_basic_ai.c			\
		is_turn_ai.c			\
		is_extension_ai.c		\
		is_extension_ai_two.c		\
		tool_two.c

MAIN	=	main.c

LIB	=	./lib/my/libmy.a

NAME	=	matchstick

INCLUDE	=	-I ./include/

TEST	=	unit_tests

TESTSRC	=	tests/

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
