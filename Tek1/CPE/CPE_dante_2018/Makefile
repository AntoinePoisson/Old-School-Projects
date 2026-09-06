##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile of project
##

NAME	=	a.out

all:	$(NAME)

$(NAME):
	@make -C ./generator/
	@make -C ./solver/
	@echo -e "\033[32mCompilation done !\033[0m"

tests_run:	all
	@$(CC) -o $(TEST) $(SRC) $(TESTSRC) $(LIB) $(FLAGS_TU)
	@./$(TEST)
	gcovr

clean:
	@make clean -C ./generator/
	@make clean -C ./solver/

fclean:	clean
	@make fclean -C ./generator/
	@make fclean -C ./solver/
	@echo -e "\033[32mObjects cleaned !\033[0m"

re:	fclean all

.PHONY:	all	NAME	tests_run	clean	fclean	re
