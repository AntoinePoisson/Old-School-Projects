##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile of project
##

MAIN	=	sources/main.c

SRC	=	sources/check_error.c			\
		sources/is_create_menu.c		\
		sources/is_create_window.c		\
		sources/is_create_game.c		\
		sources/is_extension_display.c		\
		sources/is_destroy_menu.c		\
		sources/is_destroy_game.c		\
		sources/end_game.c			\
		sources/is_extension.c			\
		sources/help_game.c			\
		sources/utile_tool.c			\
		sources/is_highscore.c			\
		sources/is_transition_game.c		\
		sources/is_menu.c			\
		sources/management_enemy.c		\
		sources/management_trap.c		\
		sources/management_how_to_play.c	\
		sources/is_defender.c			\
		sources/is_select_menu.c		\
		sources/display_menu.c			\
		sources/display.c			\
		sources/is_transition_menu.c		\
		sources/is_menu_highscore.c		\
		sources/management_event.c		\
		sources/tool_list.c			\
		sources/write_file.c			\
		sources/pause_funct.c			\
		sources/display_hp.c			\
		sources/canon_shoot.c			\
		sources/game_tool.c			\
		sources/display_range.c			\
		sources/management_clic.c		\
		sources/management_bombe.c		\
		sources/add_build.c			\
		sources/display_effet.c			\
		sources/display_h.c			\
		sources/spawn_enemy.c			\
		sources/enemy_position.c		\
		sources/enemy_attack.c			\
		sources/enemy_create.c			\
		sources/management_wave.c		\
		sources/display_text.c			\

TEST_SRC	=	./tests/test.c

LIB	=	./lib/my/libmy.a

OBJ	=	$(SRC:.c=.o)

NAME	=	my_defender

TEST	=	unit_tests

CFLAGS	=	-lm -I ./includes/ -Wall --extra -l csfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio ###-Wmissing-noreturn -Wunused-function -Wmissing-include-dirs -pedantic -pedantic-errors

FLAGS_DEBUG	=	$(CFLAGS) -g3

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
	@$(CC) -o $(TEST) $(TEST_SRC) $(OBJ) $(LIB) $(FLAGS_TU)
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
	@rm -frv ./sources/main.o
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
