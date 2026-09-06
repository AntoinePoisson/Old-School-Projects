##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Lib Makefile
##

CC	=	gcc

AR_RC	=	ar rc	

RMF     =       rm -f

SRC	=	my_compute_power_rec.c	\
	my_compute_square_root.c	\
	my_getnbr.c			\
	my_isneg.c			\
	my_is_prime.c			\
	my_putchar.c			\
	my_put_nbr.c			\
	my_putstr.c			\
	my_revstr.c			\
	my_show_word_array.c		\
	my_strcat.c			\
	my_strcmp.c			\
	my_strcpy.c			\
	my_strdup.c			\
	my_strlen.c			\
	my_strlowcase.c			\
	my_strncat.c			\
	my_strncmp.c			\
	my_strncpy.c			\
	my_strstr.c			\
	my_strupcase.c			\
	my_swap.c			\
	my_str_isnum.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -c $(SRC)
	$(AR_RC) $(NAME) $(OBJ)

clean:
	$(RMF) $(OBJ)

fclean:	clean
	$(RMF) $(NAME)

re:	fclean all
