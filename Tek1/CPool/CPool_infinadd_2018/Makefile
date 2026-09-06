##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Write a Makefile that compiles your libmy and infin_add.
##

SRC	=	*.c

OBJ	=	$(SRC:.c=.o)

LIB	=	./lib/my/libmy.a

NAME	=	infin_add

all:	$(NAME)

$(NAME):
	make -C ./lib/my/
	gcc -o $(NAME) $(SRC) $(LIB)

clean:
	rm -f $(OBJ)
	rm -f *~
	rm -f '#*#'

fclean:	clean
	rm -f $(NAME)
	make fclean -C ./lib/my/

re:	fclean all

.PHONY: all clean fclean re
