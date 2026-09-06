##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile of project
##

MAIN	=	main.c

SRC	=	check_error/check_error.c				\
		is_minishell.c						\
		execution/my_exec.c					\
		execution/is_extension_my_exec.c			\
		signal/message_signal_error.c				\
		display/display.c					\
		check_error/check_right_operator.c			\
		parser_ll/create_tree.c					\
		built_in/my_exit.c					\
		built_in/is_extension_my_exit.c				\
		operator/control_semicolon.c				\
		operator/control_double_right_chevron.c			\
		tool/tool_operator.c					\
		operator/control_right_chevron.c			\
		operator/control_left_chevron.c				\
		operator/control_double_left_chevron.c			\
		operator/control_pipe.c					\
		operator/is_operator.c					\
		parser_ll/is_exec_tree.c				\
		built_in/is_extension_my_cd.c				\
		built_in/my_cd.c					\
		built_in/my_unsetenv.c					\
		built_in/my_setenv.c					\
		built_in/control_env.c					\
		built_in/is_extension_control_env.c			\
		built_in/my_stat.c

TEST_SRC	=	test_check_error.c			\
			test_display.c				\
			test_my_stat.c				\
			test_my_unsetenv.c			\
			test_my_exit.c				\
			test_exec_tree.c			\
			test_is_extension_my_exec.c		\
			test_cd.c				\
			test_my_setenv.c			\
			test_tool_operator.c			\
			test_control_env.c			\
			test_my_exec.c				\
			test_message_signal_error.c		\
			test_is_minishell.c			\
			test_is_extension_my_cd.c

LIB	=	./lib/my/libmy.a ./lib/libgnl.a

OBJ	=	$(addprefix ./sources/, $(SRC:.c=.o))

NAME	=	mysh

TEST	=	unit_tests

CFLAGS	=	-I ./includes/ -Wall --extra -pedantic

FLAGS_DEBUG	=	$(CFLAGS) -g3

FILE_TU	=	./toto.c

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
	$(CC) -o $(NAME) $(OBJ) $(MAIN) $(LIB) $(CFLAGS)
	@echo -e "\033[32mCompilation done !\033[0m"

debug:	fclean $(OBJ)
	@make -C ./lib/my/
	$(CC) -o $(NAME) $(OBJ) $(LIB) $(FLAGS_DEBUG)
	@echo -e "\033[32mDebug mode done !\033[0m"
	@valgrind ./$(NAME)

tests_run:	all
	@$(CC) -o $(TEST) $(addprefix ./sources/, $(SRC)) $(addprefix ./tests/, $(TEST_SRC)) $(LIB) $(FLAGS_TU)
	@./$(TEST)
	@gcovr

run:	re
	@echo -e "\033[32mMode Run !\033[0m"
	@./$(NAME)

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
	@rm -f $(FILE_TU);
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

.PHONY:	all NAME tests_run clean fclean re debug run
