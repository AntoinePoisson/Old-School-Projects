##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Infinadd Makefile
##

SRC	=	my_itoa.c		\
		create_d_o.c		\
		create_d_o_two.c	\
		create_d_t_two.c	\
		create_d_t.c		\
		create_w_o_two.c	\
		create_w_o.c		\
		create_w_t_two.c	\
		create_w_t.c		\
		create_b.c		\
		create_b_two.c		\
		is_close.c		\
		is_main_boucle.c	\
		is_rand_funct.c		\
		is_rand_funct_two.c	\
		kill_objet.c		\
		kill_objet_two.c	\
		move_perso.c		\
		move_perso_two.c	\
		move_perso_three.c	\
		random_choose.c		\
		random_choose_two.c	\
		create_sprite.c		\
		create_sprite_two.c	\
		create_sprite_three.c	\
		create_sprite_four.c	\
		create_sprite_five.c	\
		gestion.c		\
		gestion_heal_point.c	\
		is_menu.c		\
		is_menu_two.c		\
		is_window_create.c	\
		create_menu.c

MAIN	=	main.c

LIB	=	./lib/my/libmy.a

NAME	=	my_hunter

INCLUDE	=	-I ./include/

TEST	=	unit_tests

TESTSRC	=	tests/test_option_h.c	\
		tests/test_my_itoa.c

CRIT	=	*.gc*

all:
	make -C ./lib/my/
	gcc -o $(NAME) $(MAIN) $(SRC) $(LIB) $(INCLUDE) -l csfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio -Wall --extra

tests_run:	all
	gcc -o $(TEST) $(SRC) $(TESTSRC) $(LIB) $(INCLUDE) --coverage -lcriterion
	./$(TEST)

clean:
	make clean -C ./lib/my/

fclean:	clean
	rm -f $(NAME)
	rm -f $(TEST)
	rm -f $(CRIT)
	rm -f *~
	rm -f a.out
	make fclean -C ./lib/my/

re:	fclean all

.PHONY:	all tests_run clean fclean re
