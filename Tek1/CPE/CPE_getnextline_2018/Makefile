##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Infinadd Makefile
##

SRC	=	get_next_line.c

MAIN	=	main.c

NAME	=	bin

INCLUDE	=	-I ./include/

TEST	=	unit_tests

TESTSRC	=	tests/test_get_next_line.c

CRIT	=	*.gc*

OPTION	=	-Wall --extra -lm

BASIC_BIN	=	a.out

TILDE	=	*~

OPTION_DEBUG	=	-Wall --extra -g3

OPTION_TU	=	--coverage -lcriterion

HEADER_COMPLI	=	*.h.gch

VALGRIND	=	vgcore.*

EMACS	=	\#*#

all: fclean

tests_run:	all
	gcc -o $(TEST) $(SRC) $(TESTSRC) $(INCLUDE) $(OPTION_TU)
	./$(TEST)

fclean:
	rm -f $(NAME)
	rm -f $(TEST)
	rm -f $(CRIT)
	rm -f $(EMACS)
	rm -f $(TILDE)
	rm -f $(BASIC_BIN)
	rm -f include/$(BASIC_BIN)
	rm -f include/$(TILDE)
	rm -f include/$(EMACS)
	rm -f include/$(HEADER_COMPLI)
	rm -f $(VALGRIND)

re:	fclean all

.PHONY:	all tests_run clean fclean re
