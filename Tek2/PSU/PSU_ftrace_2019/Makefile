##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

NAME	=	ftrace

TNAME	=	unit_tests

CC		=	gcc

MAIN	=	./src/main.c

SRC		=	./src/ftrace.c				\
			./src/check_arg.c			\
			./src/check_arg_two.c		\
			./src/check_tab_sym.c		\
			./src/loop.c				\
			./src/tools.c				\
			./src/handle_function.c		\
			./src/handle_syscall.c		\
			./src/handle_signals.c		\
			./src/handle_return_funct.c	\
			./src/my_str_to_word_array.c

TSRC		=	tests/test_error.c		\
				tests/test_working.c

OBJ			=	$(SRC:.c=.o)

CFLAGS		+=	-I ./includes -lm

LDFLAGS 	=	-Wall -Wextra -W

CRIT		=	--coverage -lcriterion

all:	$(NAME)

%.o:		%.c
			@$(CC) $(CFLAGS) $(LDFLAGS) -c -o $@ $<
			@echo -e "\033[0;32m[OK]    \033[1;32m" $< "\033[0m"

$(NAME):	$(OBJ)
			@echo -e "\033[0;34m[OK]     \033[1;34mObj's files successfully compiled!\033[0m"
			@$(CC) -o $(NAME) $(OBJ) $(MAIN) $(CFLAGS) $(LDFLAGS)
			@echo -e "\033[0;34m[OK]    \033[1;34m" $(NAME) "successfully created!\033[0m"

tests_run:	re
			@$(CC) -o $(TNAME) $(SRC) $(TSRC) $(CFLAGS) $(LDFLAGS) $(CRIT)
			@./$(TNAME)

clean:
			@rm -f $(OBJ)
			@echo -e "\033[0;33m[OK]     \033[1;33mOBJs successfully cleaned!\033[0m"

fclean:		clean
			@rm -f $(shell find . -name "*~")
			@rm -f $(shell find . -name "a.out")
			@rm -f $(shell find . -name "vgcore.*")
			@rm -f $(shell find . -name "\#*#")
			@rm -f $(shell find . -name "*.gc*")
			@rm -f $(shell find . -name ".safe")
			@rm -f $(NAME)
			@rm -f $(TNAME)
			@echo -e "\033[0;33m[OK]     \033[1;33mOBJs and useless files successfully cleaned!\033[0m"

re:			fclean all

.PHONY:		all	clean fclean re tests_run
