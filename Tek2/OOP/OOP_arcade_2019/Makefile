##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Compile arcade program
##

CORE		=	./core/

GAMES		=	./games/

LIB			=	./lib/

RM			=	rm -f


all:		graphicals games core

core:
	@make -C $(CORE)

graphicals:
	@make -C $(LIB)

games:
	@make -C $(GAMES)

clean:
	@make clean -C $(GAMES)
	@make clean -C $(CORE)
	@make clean -C $(LIB)

fclean:		clean
	@make fclean -C $(GAMES)
	@make fclean -C $(CORE)
	@make fclean -C $(LIB)
	@$(RM) vgcore.*

re:		fclean all

.PHONY:	all core graphicals games clean fclean re