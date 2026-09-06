##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## This Makefile compile my lib.
##

SRC	=	./sources/count_arg.c					\
		./sources/is_extension_my_printf.c			\
		./sources/is_extension_my_printf_two.c			\
		./sources/my_compute_power_rec.c			\
		./sources/my_getnbr.c					\
		./sources/my_isneg.c					\
		./sources/my_itoa.c					\
		./sources/my_malloc.c					\
		./sources/get_next_line.c				\
		./sources/my_malloc_two_d.c				\
		./sources/my_printf.c					\
		./sources/my_put_address.c				\
		./sources/my_putchar.c 					\
		./sources/my_puterror.c					\
		./sources/my_put_long.c					\
		./sources/my_put_nbr.c					\
		./sources/my_put_nbr_base.c				\
		./sources/my_putstr.c					\
		./sources/my_revstr.c					\
		./sources/my_strcat.c					\
		./sources/my_strcmp.c					\
		./sources/my_strcpy.c					\
		./sources/my_strdup.c					\
		./sources/my_strlen.c					\
		./sources/my_strncat.c					\
		./sources/my_strncmp.c					\
		./sources/my_str_to_operator_array.c			\
		./sources/my_str_to_word_array.c			\
		./sources/my_str_to_selec_array.c			\
		./sources/my_unsigned_putnbr.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

CFLAGS	=	-I ./includes/ -Wall --extra -pedantic -pedantic-errors ##-Werror -Wmissing-noreturn -Wwrite-strings -Wunused-function -Wmissing-include-dirs

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
