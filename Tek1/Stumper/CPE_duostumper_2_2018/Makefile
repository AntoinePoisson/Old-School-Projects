##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile of project
##

MAIN	=	sources/main.c

SRC	=	sources/check_error.c			\
		sources/is_initialization.c		\
		sources/create_two_d_tab.c		\
		sources/tool_list.c			\
		sources/convert_tab.c			\
		sources/game_loop.c			\
		sources/is_boggle.c			\
		sources/check_flags.c

TEST_SRC	=	./tests/test.c

LIB	=	./lib/my/libmy.a

OBJ	=	$(SRC:.c=.o)

NAME	=	boggle

TEST	=	unit_tests

CFLAGS	=	-I ./includes/ -Wall --extra -g3 ##-Wmissing-noreturn -Wunused-function -Wmissing-include-dirs -pedantic -pedantic-errors

FLAGS_DEBUG	=	$(CFLAGS) -g

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
	@echo -e "\033[32mCompilation done !\033[0m"

debug:	fclean $(OBJ)
	@make -C ./lib/my/
	$(CC) -o $(NAME) $(MAIN) $(OBJ) $(LIB) $(FLAGS_DEBUG)
	@valgrind ./$(NAME)
	@echo -e "\033[32mDebug mode done !\033[0m"

tests_run:	all
	@$(CC) -o $(TEST) $(SRC) $(TESTSRC) $(LIB) $(FLAGS_TU)
	@./$(TEST)
	gcovr

clean:
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
	@echo -e "\033[32mObjects cleaned !\033[0m"

re:	fclean all

.PHONY: all NAME debug tests_run clean fclean re
