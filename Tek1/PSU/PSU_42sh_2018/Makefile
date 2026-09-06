##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile of project
##

MAIN	=	main.c

SRC	=	check_error/check_error.c				\
		is_shell.c						\
		alias/my_alias.c					\
		alias/is_extension_my_alias.c				\
		backticks/backticks.c					\
		backticks/backticks2.c					\
		backticks/clean_str.c					\
		backticks/exec_backticks.c				\
		backticks/file_to_str.c					\
		backticks/free_array.c					\
		backticks/my_arrlen.c					\
		backticks/my_realloc_array.c				\
		backticks/my_strcat_with_char.c				\
		backticks/my_strcmp.c					\
		backticks/my_strcpy.c					\
		backticks/my_strdup.c					\
		backticks/my_strlen.c					\
		built_in/my_history.c					\
		built_in/my_alias.c					\
		display/display_history.c				\
		check_error/check_parentheses.c				\
		execution/my_exec.c					\
		execution/is_extension_my_exec.c			\
		signal/message_signal_error.c				\
		display/display.c					\
		check_error/check_right_operator.c			\
		parser_ll/create_tree.c					\
		built_in/my_exit.c					\
		built_in/my_echo.c					\
		built_in/is_extension_my_exit.c				\
		operator/control_semicolon.c				\
		operator/control_double_right_chevron.c			\
		tool/tool_operator.c					\
		tool/tool_operator_bis.c				\
		operator/control_right_chevron.c			\
		operator/control_left_chevron.c				\
		operator/control_double_left_chevron.c			\
		operator/control_double_pipe.c				\
		operator/control_double_ampersand.c			\
		operator/control_parentheses.c				\
		operator/control_pipe.c					\
		operator/is_operator.c					\
		parser_ll/is_exec_tree.c				\
		built_in/is_extension_my_cd.c				\
		built_in/my_cd.c					\
		built_in/my_unsetenv.c					\
		built_in/my_setenv.c					\
		built_in/control_env.c					\
		built_in/is_extension_control_env.c			\
		built_in/my_stat.c					\
		globbing/inhibitors.c					\
		globbing/globbing.c					\
		globbing/edit_tab.c					\
		globbing/globbing_funct.c				\
		line_editing/get_cmd.c					\
		line_editing/setup_term.c				\
		line_editing/actions.c					\
		built_in/my_print_echo.c				\

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

LIB	=	./lib/my/libmy.a

OBJ	=	$(addprefix ./sources/, $(SRC:.c=.o))

NAME	=	42sh

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

%.o:	%.c
	$(CC) $(CFLAGS) $(LDFLAGS) $(LFLAGS) -c -o $@ $<

all:	$(NAME)

$(NAME):	$(OBJ)
	@make -sC ./lib/my/
	$(CC) -o $(NAME) $(OBJ) $(MAIN) $(LIB) $(CFLAGS) -lncurses
	@echo -e "\033[32mCompilation done !\033[0m"

debug:	fclean $(OBJ)
	@make -sC ./lib/my/
	$(CC) -o $(NAME) $(MAIN) $(addprefix ./sources/, $(SRC)) $(LIB) $(FLAGS_DEBUG) -lncurses
	@echo -e "\033[32mDebug mode done !\033[0m"
	@valgrind ./$(NAME)

tests_run:	all
	@$(CC) -o $(TEST) $(addprefix ./sources/, $(SRC)) $(addprefix ./tests/, $(TEST_SRC)) $(LIB) $(FLAGS_TU) -lncurses
	@./$(TEST)
	@gcovr

run:	re
	@echo -e "\033[32mMode Run !\033[0m"
	@clear
	@clear
	@./$(NAME)

clean:
	@make clean -sC ./lib/my/

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
	@make fclean -sC ./lib/my/
	@echo -e "\033[32mObjects cleaned !\033[0m"

re:	fclean all

.PHONY:	all NAME tests_run clean fclean re debug run
