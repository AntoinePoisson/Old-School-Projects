##
## EPITECH PROJECT, 2018
## navy
## File description:
## Makefile
##

SRC	=	menger.c\
		main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	menger

CFLAGS	=	-std=gnu11 -Wall -Wextra

CC	=	gcc

RM	=	rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean :
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all	debug	clean	fclean	re
