##
## EPITECH PROJECT, 2020
## PSU_nmobjdump_2019
## File description:
## Makefile
##

NAME_NM	=	my_nm

NAME_OBJDUMP	=	my_objdump

TEST		=	unit_tests

FLAGS_TU	=	--coverage -lcriterion -lm -W -Wall -Wextra -I ./includes

SRC_NM	=	main.c	\
			parse.c	\
			display_file.c	\
			control_list.c	\
			control_list_extension.c	\

SRC_OBJDUMP	=	main.c	\
				display_header.c	\
				display_file.c	\
				parse.c	\

SRC_T	=	./src/nm/parse.c	\
			./src/nm/display_file.c	\
			./src/nm/control_list.c	\
			./src/nm/control_list_extension.c

TESTSRC	=	./tests/test.c

RM	=	rm -f

OBJ_NM     =       $(addprefix ./src/nm/, $(SRC_NM:.c=.o))

OBJ_OBJDUMP     =       $(addprefix ./src/objdump/, $(SRC_OBJDUMP:.c=.o))

CFLAGS	+=	-W -Wall -Wextra -I ./includes

CC	=	gcc

all:	nm objdump

nm: $(OBJ_NM)
	$(CC) -o $(NAME_NM) $(OBJ_NM) $(CFLAGS)

objdump: $(OBJ_OBJDUMP)
	$(CC) -o $(NAME_OBJDUMP) $(OBJ_OBJDUMP) $(CFLAGS)

tests_run:	all
	@$(CC) -o $(TEST) $(SRC_T) $(TESTSRC) $(FLAGS_TU)
	@./$(TEST)
	gcovr

clean:
	@$(RM) $(NAME_NM)
	@$(RM) $(NAME_OBJDUMP)

fclean:	clean
	@$(RM) $(OBJ_NM)
	@$(RM) $(OBJ_OBJDUMP)
	@$(RM) $(TEST)
	@$(RM) vgcore.*
	@$(RM) *.gc*

re: fclean all

.PHONY:	all clean fclean re nm objdump