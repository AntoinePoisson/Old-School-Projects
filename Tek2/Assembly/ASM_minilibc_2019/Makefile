##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile of project
##

NAME		=	libasm.so

TEST		=	unit_tests

FLAGS_TU	=	--coverage -lcriterion -lm -W -Wall -Wextra

SRC		=	./src/strlen.asm	\
			./src/strchr.asm	\
			./src/memset.asm	\
			./src/strcmp.asm	\
			./src/strncmp.asm	\
			./src/strcasecmp.asm	\
			./src/rindex.asm	\
			./src/memcpy.asm	\
			./src/strstr.asm	\
			./src/strpbrk.asm	\
			./src/strcspn.asm


OBJ	=	$(SRC:.asm=.o)

TESTSRC	=	./tests/test.c

CFLAGS		+=	-W -Wall -Wextra -fPIC

LDFLAGS		=	-shared -fPIC

CC		=	nasm -f elf64


all: $(NAME)

$(NAME): $(OBJ)
	ld -o $(NAME) $(OBJ) -shared -fPIC

%.o: %.asm
	nasm -f elf64 $< -o $@

tests_run:	all
	@$(CC) -o $(TEST) $(SRC) $(TESTSRC) $(FLAGS_TU)
	@./$(TEST)
	gcovr

ggg: fclean
	@$(CC) $(SRC)
	@ld -o $(NAME) $(OBJ)
	./$(NAME)

clean:
	@rm $(NAME) -f

fclean: clean
	@rm $(OBJ) -f
	@rm $(TEST) -f
	@rm a.out -f
	@rm *.gc* -f

re: fclean all

.PHONY:	all NAME tests_run clean fclean re