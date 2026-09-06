##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

NAME	=	strace

CC		=	gcc

SRC		=	./src/exists_in_path.c		\
			./src/pid_exists.c			\
			./src/main.c				\
			./src/fork_strace.c			\
			./src/display.c				\
			./src/tool.c				\

OBJ		=	$(SRC:.c=.o)

CFLAGS		+=	-I ./includes -lm

LDFLAGS 	=	-Wall -Wextra -W

all:	$(NAME)

%.o:	%.c
			@$(CC) $(CFLAGS) $(LDFLAGS) -c -o $@ $<
			@echo -e "\033[0;32m[OK]    \033[1;32m" $< "\033[0m"

$(NAME):	$(OBJ)
			@echo -e "\033[0;34m[OK]     \033[1;34mObj's files successfully compiled!\033[0m"
			@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)
			@echo -e "\033[0;34m[OK]    \033[1;34m" $(NAME) "successfully created!\033[1;33m"

clean:
			@rm -f $(OBJ)
			@echo -e "\033[0;33m[OK]     \033[1;33mOBJs successfully cleaned!\033[0m"

fclean:	clean
			@rm -f $(shell find . -name "*~")
			@rm -f $(shell find . -name "a.out")
			@rm -f $(shell find . -name "vgcore.*")
			@rm -f $(shell find . -name "\#*#")
			@rm -f $(shell find . -name "*.gc*")
			@rm -f $(shell find . -name ".safe")
			@rm -f $(NAME)
			@echo -e "\033[0;33m[OK]     \033[1;33mOBJs and useless files successfully cleaned!\033[0m"

re:	fclean all

.PHONY:	all	clean fclean re
