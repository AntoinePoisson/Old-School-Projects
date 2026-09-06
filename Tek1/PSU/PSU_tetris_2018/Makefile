##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile of tetris project
##

CC	=	gcc

MAIN	=	main.c

SRCDIR	=	./sources/

SRC	=	$(SRCDIR)help_opt.c\
		$(SRCDIR)init_screen.c\
		$(SRCDIR)create_board.c\
		$(SRCDIR)manage_options.c\
		$(SRCDIR)loop_display.c\
		$(SRCDIR)display_tetris.c\
		$(SRCDIR)management_game.c\
		$(SRCDIR)manage_inputs.c\
		$(SRCDIR)tool_check_move_obj.c\
		$(SRCDIR)tool_move_obj.c\
		$(SRCDIR)analyze_tetriminos.c\
		$(SRCDIR)modify_term.c\
		$(SRCDIR)tool_analyze_file_tetriminos.c\
		$(SRCDIR)display_tetriminos_file_data.c\
		$(SRCDIR)control_right_file.c\
		$(SRCDIR)manage_keys.c\
		$(SRCDIR)debug_mode.c\
		$(SRCDIR)tetris.c

TEST_SRC	=	./tests/test_tetris.c

LIB	=	./lib/my/libmy.a

OBJ	=	$(SRC:.c=.o)

NAME	=	tetris

TEST	=	unit_tests

FLAG_NCURSE	=	-lncurses

CFLAGS	=	-I ./includes/ $(FLAG_NCURSE) -Wall --extra -pedantic

FLAGS_DEBUG	=	$(CFLAGS) -g -g3

FLAGS_TU	=	$(CFLAGS) --coverage -lcriterion

HEADERS_COMPLI	=	*.h.gch

VALGRIND	=	vgcore.*

BASIC_BIN	=	a.out

CRITERION	=	*.gc*

EMACS	=	\#*#

TILDE	=	*~

all:	$(NAME)

$(NAME):	$(OBJ)
	@make -C ./lib/my/
	$(CC) -o $(NAME) $(MAIN) $(OBJ) $(LIB) $(CFLAGS)
	@echo -e "\033[32mCompilation done !\033[0m"

debug:	fclean $(OBJ)
	@make -C ./lib/my/
	$(CC) -o $(NAME) $(MAIN) $(OBJ) $(LIB) $(FLAGS_DEBUG)
	@clear
	@valgrind ./$(NAME) --debug
	@echo -e "\033[32mDebug mode done !\033[0m"

tests_run:	all
	@$(CC) -o $(TEST) $(SRC) $(TEST_SRC) $(LIB) $(FLAGS_TU)
	@./$(TEST)
	gcovr

run: re
	@clear
	@./$(NAME) --debug

clean:
	@rm -frv $(OBJ)
	@make clean -C ./lib/my/

fclean:	clean
	@rm -frv $(NAME)
	@rm -frv $(TEST)
	@rm -frv $(CRITERION)
	@rm -frv $(EMACS)
	@rm -frv $(TILDE)
	@rm -frv $(BASIC_BIN)
	@rm -frv $(VALGRIND)
	@rm -frv $(SRCDIR)$(TEST)
	@rm -frv $(SRCDIR)$(OBJ)
	@rm -frv $(SRCDIR)$(CRITERION)
	@rm -frv $(SRCDIR)$(EMACS)
	@rm -frv $(SRCDIR)$(TILDE)
	@rm -frv $(SRCDIR)$(BASIC_BIN)
	@rm -frv ./includes/$(BASIC_BIN)
	@rm -frv ./includes/$(TILDE)
	@rm -frv ./includes/$(EMACS)
	@rm -frv ./includes/$(HEADERS_COMPLI)
	@rm -frv $(TESTDIR)$(BASIC_BIN)
	@rm -frv $(TESTDIR)$(TILDE)
	@rm -frv $(TESTDIR)$(EMACS)
	@rm -frv $(TESTDIR)$(HEADERS_COMPLI)
	@make fclean -C ./lib/my/
	@echo -e "\033[32mObjects cleaned !\033[0m"

re: fclean all

.PHONY: all NAME debug tests_run clean fclean re
