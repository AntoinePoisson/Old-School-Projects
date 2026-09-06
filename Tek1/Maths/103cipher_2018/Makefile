##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile of my_printf
##

NAME	=	103cipher

SRC	=	main.c			\
		matrix.c		\
		check_error.c		\
		encrypted.c		\
		is_extension_encrypted.c\
		cipher.c

INCLD	+=	-I./include/

LIB	=	-L./lib/my/ -lmy

OBJ	=	$(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	make -C lib/my
	gcc $(OBJ) -o $(NAME) $(INCLD) $(LIB) -Wall --extra

debug : $(OBJ)
	make -C lib/my
	gcc $(OBJ) -o $(NAME) $(INCLD) $(LIB) -g3 -Wall --extra

clean :
	rm -f $(OBJ) *~ *.gc*
	make -C lib/my/ fclean

fclean : clean
	rm -f $(NAME) $(TNAME)

re : fclean all

.PHONY : all debug clean fclean re
