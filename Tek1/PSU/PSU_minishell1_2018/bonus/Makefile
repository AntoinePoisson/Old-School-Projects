##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile of project
##

SRC	=	./sources/main.c				\
		./sources/check_error.c				\
		./sources/is_minishell.c			\
		./sources/my_exec.c				\
		./sources/is_extension_my_exec.c		\
		./sources/message_signal_error.c		\
		./sources/display.c				\
		./sources/my_exit.c				\
		./sources/is_extension_my_exit.c		\
		./sources/is_extension_my_cd.c			\
		./sources/my_cd.c				\
		./sources/my_unsetenv.c				\
		./sources/my_setenv.c				\
		./sources/control_env.c				\
		./sources/is_extension_control_env.c		\
		./sources/is_extension_my_alias.c		\
		./sources/my_alias.c				\
		./sources/my_stat.c

TEST_SRC	=	./tests/test_check_error.c		\
		./tests/test_display.c			\
		./tests/test_my_stat.c			\
		./tests/test_my_unsetenv.c		\
		./tests/test_my_exit.c			\
		./tests/test_my_setenv.c		\
		./tests/test_control_env.c		\
		./tests/test_my_exec.c			\
		./tests/test_message_signal_error.c	\
		./tests/test_is_minishell.c		\
		./tests/test_is_extension_my_cd.c


LIB	=	./lib/my/libmy.a ./lib/libgnl.a

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

TEST	=	unit_tests

CFLAGS	=	-I ./includes/ -Wall --extra -Wunused-function -pedantic

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
	$(CC) -o $(NAME) $(OBJ) $(LIB) $(CFLAGS)
	@echo -e "\033[32mCompilation done !\033[0m"

debug:	$(OBJ)
	@make -C ./lib/my/
	$(CC) -o $(NAME) $(OBJ) $(LIB) $(FLAGS_DEBUG)
	@valgrind ./$(NAME)
	@echo -e "\033[32mDebug mode done !\033[0m"

tests_run:	all
	@$(CC) -o $(TEST) $(OBJ) $(LIB) $(FLAGS_TU)
	@./$(TEST)
	@gcovr

clean:
	@make clean -C ./lib/my/

fclean:
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

.PHONY: all NAME tests_run clean fclean re debug
