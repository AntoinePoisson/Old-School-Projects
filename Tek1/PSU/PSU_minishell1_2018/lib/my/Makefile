##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Write a Makefile that compiles your libmy.
##

SRC	=	my_compute_power_rec.c		\
		my_revstr.c			\
		my_str_islower.c		\
		my_strstr.c			\
		my_compute_square_root.c	\
		my_str_isnum.c			\
		my_strupcase.c			\
		my_find_prime_sup.c		\
		my_str_isprintable.c		\
		my_swap.c			\
		my_getnbr.c			\
		my_sort_int_array.c		\
		my_str_isupper.c		\
		my_isneg.c 			\
		my_strcapitalize.c		\
		my_strlen.c 			\
		my_is_prime.c			\
		my_strcat.c			\
		my_strlowcase.c			\
		my_putchar.c 			\
		my_strcmp.c			\
		my_strncat.c			\
		my_put_nbr.c			\
		my_strcpy.c			\
		my_strncmp.c			\
		my_putstr.c 			\
		my_str_isalpha.c		\
		my_strncpy.c			\
		my_str_to_word_array.c		\
		my_printf.c			\
		my_put_address.c		\
		my_unsigned_putnbr.c		\
		my_put_nbr_base.c		\
		my_put_long.c			\
		is_extension_my_printf_two.c	\
		is_extension_my_printf.c	\
		count_arg.c			\
		my_str_to_selec_array.c		\
		my_itoa.c			\
		my_strdup.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

CFLAGS	=	-Wall --extra -Wunused-function -pedantic

FLAGS_DEBUG	=	$(CFLAGS) -g3

HEADERS_COMPLI	=	*.h.gch

VALGRIND	=	vgcore.*

BASIC_BIN	=	a.out

CRITERION	=	*.gc*

EMACS	=	\#*#

TILDE	=	*~

CC	=	gcc

all:	$(NAME)

$(NAME):	$(OBJ)
	@$(CC) -c $(SRC) $(CFLAGS)
	@ar rc $(NAME) $(OBJ)

debug:	$(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(FLAGS_DEBUG)
	@valgrind ./$(NAME)

clean:
	@rm -fr $(OBJ)
	@rm -frv $(TILDE)
	@rm -frv $(EMACS)
	@rm -frv $(BASIC_BIN)
	@rm -frv $(HEADERS_COMPLI)
	@rm -frv $(VALGRIND)

fclean:	clean
	@rm -fr $(NAME)

re:	fclean all

.PHONY: all clean fclean re debug
