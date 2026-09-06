##
## EPITECH PROJECT, 2018
## navy
## File description:
## Makefile
##

MAIN	=	main.c

SRC	=	src/file_descriptor.c\
		src/manage_errors.c\
		src/battleship.c\
		src/connection.c\
		src/fill_map.c\
		src/redirection.c\
		src/attack.c\
		src/check_hit.c\
		src/check_eog.c

LIBC	=	lib/lib.c\
		lib/lib2.c\
		lib/binary.c\
		lib/mgetline.c\
		lib/my_itoa.c\
		lib/str_to_wordarr.c

LTEST	=	tests/test_manage_error.c\
		tests/test_attack.c\
		tests/test_redirection.c

OBJ	=	$(SRC:.c=.o)

LOBJ	=	$(LIBC:.c=.o)

NAME	=	navy

TEST	=	unit_tests

LIB	=	libmy.a

FLAGS	=	-g -W -Wall -Wextra

CFLAGS	=	-I./include

CRITERION	=	*.gc*

FLAGS_TU	=	$(CFLAGS) $(FLAGS) --coverage -lcriterion

CC	=	gcc

RM	=	rm -f

all:	$(NAME)

$(NAME):	$(OBJ)	$(LOBJ)
	@ar rc $(LIB) $(LOBJ)
	@$(CC) $(OBJ) $(MAIN) $(LIB) $(CFLAGS) -o $(NAME)

debug:	$(LOBJ)
	ar rc $(LIB) $(LOBJ)
	$(CC) $(SRC) $(LIB) $(FLAGS) $(CFLAGS) -o $(NAME)

tests_run:	all
	@$(CC) -o $(TEST) $(SRC) $(LTEST) $(LIB) $(FLAGS_TU)
	@./$(TEST)
	gcovr

clean :
	@$(RM) $(CRITERION)
	@$(RM) $(TEST)
	$(RM) $(OBJ)
	$(RM) $(LOBJ)

fclean:	clean
	$(RM) $(NAME)
	$(RM) $(LIB)

re:	fclean all

.PHONY:	all	debug	clean	fclean	re
