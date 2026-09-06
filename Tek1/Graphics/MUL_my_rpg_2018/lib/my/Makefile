##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile of libmy
##

NAME	=	libmy.a

CC	=	gcc

SRC	=	src/my_atoi.c		\
		src/my_itoa.c		\
		src/my_malloc.c		\
		src/my_strcat.c		\
		src/get_next_line.c	\
		src/my_getnbr.c		\
		src/my_itoa.c		\
		src/my_revstr.c		\
		src/my_compute_power_rec.c\
		src/my_revstr.c		\
		src/my_strcat_charac.c	\
		src/my_putchar.c	\
		src/my_putstr.c		\
		src/my_puterror.c	\
		src/my_strcmp.c		\
		src/my_strdup.c		\
		src/my_strlen.c

CFLAGS	+=	-Wall -Wextra -I./../../include

TILTE	=	src/*~

OBJ	=	$(SRC:.c=.o)


all:	$(NAME)

%.o:	%.c
	@$(CC) $(CFLAGS) -c -o $@ $<
	@echo -e "\033[0;32m[OK]    \033[1;32m" $< "\033[0m"

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo -e "\033[0;34m[OK]    \033[1;34m" $(NAME) "successfully compiled!\033[0m"

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f src/$(NAME)
	@rm -f $(TILTE)

re:	fclean all

.PHONY: all debug clean fclean re
