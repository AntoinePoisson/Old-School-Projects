##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Write a Makefile that compiles your libmy.
##

SRC	=	my_compute_power_rec.c	\
		my_revstr.c		\
		my_str_islower.c	\
		my_strstr.c		\
		my_compute_square_root.c\
		my_showmen.c		\
		my_str_isnum.c		\
		my_strupcase.c		\
		my_find_prime_sup.c	\
		my_showstr.c		\
		my_str_isprintable.c	\
		my_swap.c		\
		my_getnbr.c		\
		my_sort_int_array.c	\
		my_str_isupper.c	\
		my_isneg.c 		\
		my_strcapitalize.c	\
		my_strlen.c 		\
		my_is_prime.c		\
		my_strcat.c		\
		my_strlowcase.c		\
		my_putchar.c 		\
		my_strcmp.c		\
		my_strncat.c		\
		my_put_nbr.c		\
		my_strcpy.c		\
		my_strncmp.c		\
		my_putstr.c 		\
		my_str_isalpha.c	\
		my_strncpy.c 		

OBJ	=	$(SRC: .c =.o)

LIB	=	libmy.a 

NAME	=	compilation

all:	$(NAME)

$(NAME):
	gcc -c $(SRC)
	ar rc $(LIB) $(OBJ)

clean:
	rm -f *.o
	rm -f *~

fclean:	clean
	rm -f $(LIB)

re: fclean all
