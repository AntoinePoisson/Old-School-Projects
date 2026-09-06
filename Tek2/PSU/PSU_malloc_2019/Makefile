##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile of project
##

NAME		=	libmy_malloc.so

TEST		=	unit_tests

FLAGS_TU	=	--coverage -lcriterion -lm -W -Wall -Wextra

SRC		=	main_function.c	\
			realloc.c		\
			tool.c

TESTSRC	=	./tests/test.c

OBJ		=	$(SRC:.c=.o)

CFLAGS		+=	-W -Wall -Wextra -fPIC -lm

LDFLAGS		=	-shared -fPIC -lm

CC		=	gcc


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

tests_run:	all
	@$(CC) -o $(TEST) $(SRC) $(TESTSRC) $(FLAGS_TU)
	@./$(TEST)
	gcovr

clean:
	rm $(OBJ) -f

fclean: clean
	rm $(NAME) -f
	rm $(TEST) -f
	rm *.gc* -f

re: fclean all

.PHONY:	all NAME tests_run clean fclean re