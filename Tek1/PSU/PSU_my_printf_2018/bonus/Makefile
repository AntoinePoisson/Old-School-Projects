##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Write a Makefile that compiles your libmy.
##

SRC	=	my_printf.c			\
		my_put_address.c		\
		my_compute_power_rec.c		\
		my_strlen.c 			\
		my_putchar.c 			\
		my_put_nbr.c			\
		my_putstr.c 			\
		my_unsigned_putnbr.c		\
		my_put_nbr_base.c		\
		my_put_long.c			\
		is_extension_my_printf_two.c	\
		is_extension_my_printf.c	\
		my_putchar_color_int.c		\
		my_putchar_color_char.c		\
		my_putstr_color_int.c		\
		my_putstr_color_char.c		\
		my_rev_put_str.c

OBJ	=	$(SRC:.c=.o)

HEADER	=	my_printf.h		\
		my_put_long.h		\
		my_put_nbr_base.h	\
		my_unsigned_putnbr.h	\
		my_extension.h

TESTSRC	=	tests/test_my_put_nbr.c				\
		tests/test_my_printf.c				\
		tests/test_my_compute_power_rec.c		\
		tests/test_my_put_nbr_base.c			\
		tests/test_my_put_adress.c			\
		tests/test_my_put_long.c			\
		tests/test_my_is_extension_two_printf.c		\
		tests/test_my_is_extension_printf.c

NAME	=	libmy.a

CRIT	=	*.gc*

CRIT_FLAGS	=	--coverage -lcriterion

TEST	=	unit_tests

all:	$(NAME)

$(NAME):
	gcc -c $(SRC)
	ar rc $(NAME) $(OBJ) $(HEADER)

clean:
	rm -f $(OBJ)
	rm -f *~
	rm -f "#*#"
	rm -f *.h.gch
	rm -f a.out
	rm -f $(CRIT)

fclean:	clean
	rm -f $(NAME)
	rm -f $(TEST)

re:	fclean all

.PHONY: all clean fclean re
