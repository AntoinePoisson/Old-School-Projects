##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile of project
##

MAIN	=	main.c

SRC	=	sources/check_error.c				\
		sources/is_parsing.c				\
		sources/display.c				\
		sources/is_create_list.c			\
		sources/check_end_start_link.c			\
		sources/tool_of_algo.c				\
		sources/tool_of_algo_two.c			\
		sources/select_data.c				\
		sources/tool.c					\
		sources/check_element_parse.c			\
		sources/is_algo.c				\
		sources/tools.c					\
		sources/convert_list.c				\
		sources/sort_array.c				\
		sources/move_ants.c				\
		sources/disp_movement.c				\
		second_main.c

TEST_SRC	=	./tests/test.c\
			./tests/unit.c

LIB	=	./lib/my/libmy.a

OBJ	=	$(SRC:.c=.o)

NAME	=	lem_in

TEST	=	unit_tests

CFLAGS	=	-I ./includes/ -Wall --extra -g3 ##-Wmissing-noreturn -Wmissing-include-dirs -pedantic -pedantic-errors

FLAGS_DEBUG	=	$(CFLAGS) -g -g3

FLAGS_TU	=	$(CFLAGS) --coverage -lcriterion

HEADERS_COMPLI	=	*.h.gch

VALGRIND	=	vgcore.*

BASIC_BIN	=	a.out

CRITERION	=	*.gc*

EMACS	=	\#*#

TILDE	=	*~

CC	=	gcc

all:	$(NAME)

$(NAME):	$(OBJ)
	@make -C ./lib/my/
	$(CC) -o $(NAME) $(OBJ) $(MAIN) $(LIB) $(CFLAGS)
	@echo -e "\033[32mCompilation done !\033[0m"

debug:	fclean $(OBJ)
	@make -C ./lib/my/
	$(CC) -o $(NAME) $(OBJ) $(MAIN) $(LIB) $(FLAGS_DEBUG)
	@valgrind ./$(NAME)
	@echo -e "\033[32mDebug mode done !\033[0m"

tests_run: re
	@$(CC) -o $(TEST) $(TEST_SRC) $(SRC) $(LIB) $(FLAGS_TU)
	@./$(TEST)
	gcovr

clean:
	@rm -frv main.o
	@make clean -C ./lib/my/

fclean:	clean
	@rm -frv $(NAME)
	@rm -frv $(TEST)
	@rm -frv $(OBJ)
	@rm -frv $(CRITERION)
	@rm -frv $(EMACS)
	@rm -frv $(TILDE)
	@rm -frv $(BASIC_BIN)
	@rm -frv $(VALGRIND)
	@rm -frv ./sources/main.o
	@rm -frv ./sources/$(TEST)
	@rm -frv ./sources/$(OBJ)
	@rm -frv ./sources/$(CRITERION)
	@rm -frv ./sources/$(EMACS)
	@rm -frv ./sources/$(TILDE)
	@rm -frv ./sources/$(BASIC_BIN)
	@rm -frv ./includes/$(BASIC_BIN)
	@rm -frv ./includes/$(HEADERS_COMPLI)
	@rm -frv ./includes/$(EMACS)
	@rm -frv ./includes/$(TILDE)
	@rm -frv ./tests/$(BASIC_BIN)
	@rm -frv ./tests/$(TILDE)
	@rm -frv ./tests/$(EMACS)
	@rm -frv ./tests/$(HEADERS_COMPLI)
	@make fclean -C ./lib/my/
	@echo -e "\033[32mObjects cleaned !\033[0m"

re:	fclean all

.PHONY:	all	NAME	debug	tests_run	clean	fclean	re
