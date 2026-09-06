##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Infinadd Makefile
##

SRC	=	is_pong.c		\
		calcul_vector.c		\
		is_extension_101pong.c

MAIN	=	main.c

LIB	=	./lib/my/libmy.a

NAME	=	101pong

INCLUDE	=	-I ./include/

TEST	=	unit_tests

TESTSRC	=	tests/test_101pong.c

CRIT	=	*.gc*

all:
	make -C ./lib/my/
	gcc -o $(NAME) $(MAIN) $(SRC) $(LIB) $(INCLUDE) -lm

tests_run:	all
	gcc -o $(TEST) $(SRC) $(TESTSRC) $(LIB) $(INCLUDE) --coverage -lcriterion -lm
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
