##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## This Makefile compile my lib.
##

SRC	=	./sources/counter_argument.c				\
		./sources/get_next_line.c				\
		./sources/is_extension_gnl.c				\
		./sources/is_extension_my_printf.c			\
		./sources/is_extension_my_printf_two.c			\
		./sources/my_compute_power_rec.c			\
		./sources/my_compute_square_root.c			\
		./sources/my_find_prime_sup.c				\
		./sources/my_getnbr.c					\
		./sources/my_isneg.c					\
		./sources/my_is_prime.c					\
		./sources/my_malloc.c					\
		./sources/my_malloc_two_d.c				\
		./sources/my_printf.c					\
		./sources/my_put_address.c				\
		./sources/my_putchar.c 					\
		./sources/my_puterror.c					\
		./sources/my_put_long.c					\
		./sources/my_putnbr.c					\
		./sources/my_put_nbr_base.c				\
		./sources/my_putstr.c					\
		./sources/my_revstr.c					\
		./sources/my_sort_int_array.c				\
		./sources/my_strcapitalize.c				\
		./sources/my_strcat.c					\
		./sources/my_strcmp.c					\
		./sources/my_strcpy.c					\
		./sources/my_strdup.c					\
		./sources/my_str_isalpha.c				\
		./sources/my_str_islower.c				\
		./sources/my_str_isnum.c				\
		./sources/my_str_isprintable.c				\
		./sources/my_str_isupper.c				\
		./sources/my_strlen.c					\
		./sources/my_strlowcase.c				\
		./sources/my_strncat.c					\
		./sources/my_strncmp.c					\
		./sources/my_strncpy.c					\
		./sources/my_strstr.c					\
		./sources/my_str_to_word_array.c			\
		./sources/my_strupcase.c				\
		./sources/my_swap.c					\
		./sources/my_unsigned_putnbr.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

CFLAGS	=	-I ./includes/ -Wall --extra -Werror -Wmissing-noreturn -Wwrite-strings -Wunused-function -Wmissing-include-dirs -pedantic -pedantic-errors

FLAGS_DEBUG	=	$(CFLAGS) -g3

HEADERS_COMPLI	=	*.h.gch

VALGRIND	=	vgcore.*

BASIC_BIN	=	a.out

FILE_O	=	*.o

EMACS	=	\#*#

TILDE	=	*~

CC	=	gcc

all:	$(NAME)

$(NAME):	$(OBJ)
	@ar rc $(NAME) $(OBJ)

debug:	fclean $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(FLAGS_DEBUG)
	@valgrind ./$(NAME)

clean:
	@rm -fr $(FILE_O)
	@rm -frv $(TILDE)
	@rm -frv $(EMACS)
	@rm -frv $(BASIC_BIN)
	@rm -frv $(HEADERS_COMPLI)
	@rm -frv $(VALGRIND)
	@rm -fr ./sources/$(FILE_O)
	@rm -frv ./sources/$(TILDE)
	@rm -frv ./sources/$(EMACS)
	@rm -frv ./sources/$(BASIC_BIN)
	@rm -frv ./sources/$(HEADERS_COMPLI)
	@rm -frv ./sources/$(VALGRIND)
	@rm -frv ./sources/$(TILDE)
	@rm -frv ./includes/$(TILDE)
	@rm -frv ./includes/$(EMACS)
	@rm -frv ./includes/$(BASIC_BIN)
	@rm -frv ./includes/$(HEADERS_COMPLI)
	@rm -frv ./includes/$(VALGRIND)

fclean:	clean
	@rm -fr $(NAME)

re:	fclean all

.PHONY:	all	NAME	debug	clean	fclean	re
