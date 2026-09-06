##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Infinadd Makefile
##

SRC	=	is_runner.c				\
		check_argument.c			\
		is_menu.c				\
		is_create_window.c			\
		is_create_bg.c				\
		is_create_bg_two.c			\
		is_gestion_dino.c			\
		is_extension_gestion_dino.c		\
		is_extension_create_obstacle.c		\
		control_move_dino.c			\
		is_create_obstacle.c			\
		get_next_line.c				\
		my_itoa.c				\
		bird.c					\
		is_highscore.c				\
		control_score.c				\
		write_file.c				\
		is_extension_control_move_dino.c	\
		is_create_menu.c			\
		is_destroy_menu.c			\
		is_menu_highscore.c			\
		display_menu.c				\
		is_transition_menu.c			\
		is_select_menu.c			\
		is_end_level_runner.c			\
		is_hitbox_dino.c			\
		is_highscore_two.c			\
		is_transition_runner.c			\
		display_runner.c			\
		display_runner_two.c			\
		display_runner_three.c			\
		is_create_runner.c			\
		is_create_runner_two.c

MAIN	=	main.c

LIB	=	./lib/my/libmy.a

NAME	=	my_runner

INCLUDE	=	-I ./include/

TEST	=	unit_tests

TESTSRC	=	tests/

CRIT	=	*.gc*

OPTION	=	-Wall --extra

BASE_BIN	=	a.out

TILDE	=	*~

OPTION_DEBUG	=	-Wall --extra -g3

OPTION_TU	=	--coverage -lcriterion

HEADER_COMPLI	=	*.h.gch

VALGRIND	=	vgcore.*

EMACS	=	\#*#

all: NAME

NAME:
	make -C ./lib/my/
	gcc -o $(NAME) $(SRC) $(MAIN) $(LIB) $(INCLUDE) $(OPTION) -l csfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio

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
	rm -f include/$(EMACS)
	rm -f $(TILDE)
	rm -f include/$(TILDE)
	rm -f $(BASE_BIN)
	rm -f include/$(HEADER_COMPLI)
	rm -f $(VALGRIND)
	make fclean -C ./lib/my/

re:	fclean all

.PHONY:	all NAME tests_run clean fclean re
