##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## This Makefile compile my lib.
##

SRC	=	ex00.c\
		ex01.c\
		ex02.c\
		ex03.c\
		ex04.c\
		ex05.c\
		ex06.c\
		ex07.c\
		ex08.c\
		ex09.c\
		ex10.c\

TEST_SRC	=	./tests/test_ex01.c\
				./tests/test_ex02.c\
				./tests/test_ex03.c\
				./tests/test_ex04.c\
				./tests/test_ex05.c\
				./tests/test_ex06.c\
				./tests/test_ex07.c\

OBJ	=	$(SRC:.c=.o)

NAME	=	libstring.a

TEST	=	unit_tests

CFLAGS	=	-std=gnu11 -Wall -Wextra

FLAGS_TU	=	--coverage -lcriterion

CC	=	gcc

all:	$(NAME)

$(NAME):	$(OBJ)
	@ar rc $(NAME) $(OBJ)

tests_run:	all
	@$(CC) -o unit_tests $(SRC) $(TEST_SRC) $(FLAGS_TU)
	@./unit_tests
	@gcovr

clean:
	@rm -fr *.o

fclean:	clean
	@rm -fr $(NAME) $(TEST)
	@rm -fr a.out
	@rm -fr *.gc*

re:	fclean all

.PHONY:	all	NAME	debug	clean	fclean	re	tests_run
