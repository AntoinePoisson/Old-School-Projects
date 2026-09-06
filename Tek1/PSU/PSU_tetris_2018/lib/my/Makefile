##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## This Makefile compile my lib.
##

SRCDIR = ./sources/

SRC	=	$(SRCDIR)counter_argument.c				\
		$(SRCDIR)my_getnbr.c					\
		$(SRCDIR)mp_mput.c					\
		$(SRCDIR)mp_mputstr.c					\
		$(SRCDIR)cp_two_d.c					\
		$(SRCDIR)mp_mrevstr.c					\
		$(SRCDIR)mp_mstrlen.c					\
		$(SRCDIR)mp_mstrcmp.c					\
		$(SRCDIR)mp_mput_un.c					\
		$(SRCDIR)mp_mput_nbr.c					\
		$(SRCDIR)mp_mputhexa.c					\
		$(SRCDIR)mp_mput_long.c					\
		$(SRCDIR)mp_my_adress.c					\
		$(SRCDIR)mp_double_array.c				\
		$(SRCDIR)mp_disp_double.c				\
		$(SRCDIR)mp_disp_rev.c					\
		$(SRCDIR)mp_convert.c					\
		$(SRCDIR)mp_call_functions.c				\
		$(SRCDIR)mprintf.c					\
		$(SRCDIR)is_num.c					\
		$(SRCDIR)get_next_line.c				\
		$(SRCDIR)my_strchr.c					\
		$(SRCDIR)read_file.c					\
		$(SRCDIR)my_strerror.c					\
		$(SRCDIR)my_getnbr.c					\
		$(SRCDIR)my_compute_power_rec.c				\
		$(SRCDIR)my_malloc.c					\
		$(SRCDIR)my_malloc_two_d.c				\
		$(SRCDIR)my_putchar.c 					\
		$(SRCDIR)my_puterror.c					\
		$(SRCDIR)my_putnbr.c					\
		$(SRCDIR)my_putstr.c					\
		$(SRCDIR)my_revstr.c					\
		$(SRCDIR)my_strcat.c					\
		$(SRCDIR)my_strcmp.c					\
		$(SRCDIR)my_strcpy.c					\
		$(SRCDIR)my_strdup.c					\
		$(SRCDIR)my_strlen.c					\
		$(SRCDIR)my_strncmp.c					\
		$(SRCDIR)my_strncpy.c					\
		$(SRCDIR)my_str_to_word_array.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

CFLAGS	=	-I ./includes/ -Wall --extra

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
