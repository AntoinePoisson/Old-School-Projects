##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile of project
##

MAIN	=	main.c

SRC	=	sources/check_error.c\
		sources/backtracker.c\
		sources/imperfect_maze.c\
		sources/split_map.c\
		sources/tool_list.c\
		sources/move_direction.c\
		sources/find_midle.c\
		sources/handle_imperfect.c

TEST_SRC	=	./tests/test.c

LIB	=	./lib/my/libmy.a

OBJ	=	$(SRC:.c=.o)

NAME	=	generator

TEST	=	unit_tests

CFLAGS	=	-I ./includes/ -Wall --extra ##-Wmissing-noreturn -Wunused-function -Wmissing-include-dirs -pedantic -pedantic-errors

FLAGS_DEBUG	=	$(CFLAGS) -g -g3

FLAGS_TU	=	$(CFLAGS) --coverage -lcriterion

HEADERS_COMPLI	=	*.h.gch

VALGRIND	=	vgcore.*

BASIC_BIN	=	a.out

CRITERION	=	*.gc*

EMACS	=	\#*#

TILDE	=	*~

CC	=	gcc

all:	$(NAME)

$(NAME):	$(OBJ)
	@make -C ./lib/my/
	$(CC) -o $(NAME) $(MAIN) $(OBJ) $(LIB) $(CFLAGS)

debug:	fclean $(OBJ)
	@make -C ./lib/my/
	$(CC) -o $(NAME) $(MAIN) $(OBJ) $(LIB) $(FLAGS_DEBUG)
	@valgrind ./$(NAME)

tests_run:	all
	@$(CC) -o $(TEST) $(SRC) $(TESTSRC) $(LIB) $(FLAGS_TU)
	@./$(TEST)
	gcovr

clean:
	@rm -frv main.o
	@make clean -C ./lib/my/

fclean:	clean
	@rm -frv $(NAME)
	@rm -frv $(TEST)
	@rm -frv $(OBJ)
	@rm -frv $(CRITERION)
	@rm -frv $(EMACS)
	@rm -frv $(TILDE)
	@rm -frv $(BASIC_BIN)
	@rm -frv $(VALGRIND)
	@rm -frv ./sources/$(TEST)
	@rm -frv ./sources/$(OBJ)
	@rm -frv ./sources/$(CRITERION)
	@rm -frv ./sources/$(EMACS)
	@rm -frv ./sources/$(TILDE)
	@rm -frv ./sources/$(BASIC_BIN)
	@rm -frv ./includes/$(BASIC_BIN)
	@rm -frv ./includes/$(HEADERS_COMPLI)
	@rm -frv ./includes/$(EMACS)
	@rm -frv ./includes/$(TILDE)
	@rm -frv ./tests/$(BASIC_BIN)
	@rm -frv ./tests/$(TILDE)
	@rm -frv ./tests/$(EMACS)
	@rm -frv ./tests/$(HEADERS_COMPLI)
	@make fclean -C ./lib/my/

re:	fclean all

.PHONY:	all	NAME	debug	tests_run	clean	fclean	re
